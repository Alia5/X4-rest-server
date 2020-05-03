import { getFuncName, getArgs, getReturnType, structFromName, funcsToUsing } from './../util/util';
import { getHttpFuncsCpp } from './httpFuncGen';

// TODO: Cleanup Codegen
// ! Note to self: OOP would probably be simpler.
// ! Note to self: You have extensively used templating-engines in the past, haven't you?

const FFI_TYPEDEF_H =
`#pragma once
#include <cstdint>

namespace X4FFI
` as const;

const FFI_TYPEDEF_STRUCT_H =
`#pragma once
#include "ffi_typedef.h"

namespace X4FFI
` as const;

const FFI_FUNCS_H =
`#pragma once
#include "ffi_typedef_struct.h"

namespace X4FFI
` as const;

const FFI_JSON_H =
`
#pragma once

#include <nlohmann/json.hpp>
#include "ffi_funcs.h"
#include "../ffi/FFIInvoke.h"

using json = nlohmann::json;
using uint = unsigned int;

#define Q(x) #x
#define QUOTE(x) Q(x)

#define invoke(FuncName, ...) \
  ffi_invoke.invokeFn<X4FFI::FuncName>(QUOTE(FuncName), __VA_ARGS__);

#define PARAMS(...) \
    FFIInvoke& ffi_invoke, __VA_ARGS__

// ---

namespace ffijson
{
    using namespace X4FFI;

` as const;

const HTTP_SERVER_FUNS =
`
#pragma once
#include <httplib.h>
#include <string>

#include "../ffi/FFIInvoke.h"
#include "../ffi/ffi_json.h"
#include "gen_ffi_json.h"

#define SET_CONTENT(Call) \
	res.set_content( \
			Call.dump(), "text/json")

#define PARAMS(...) \
	ffi_invoke, __VA_ARGS__

#define HAN_FN \
	[&](const httplib::Request& req, httplib::Response& res)

void BadRequest(httplib::Response& res, std::string const& message)
{
	res.status = 401;
	res.set_content(json{
		{"code", 401},
		{"name", "Bad Request"},
		{"message", message},
		}.dump(), "text/json");
}

void initGenFuns(httplib::Server& server, FFIInvoke& ffi_invoke)
{
` as const;

const structToCppJsonVals = (struct: string|undefined, valueName: string, structs: string[], returnType?: string, lastWasPtr?: boolean): string[] => {
    // currently no structs with arrays
    // or inner structs that are not separately defined
    // available via ffi funcs
    // so we ignore that, here
    if (!struct) {
        if (returnType.includes('void')) {
            return ['{"func_res", true}'];
        }
        return [`{"${valueName.includes('func') || valueName.endsWith('res') ? 'func_res' : valueName}", ${valueName}}`];
    }
    const valuesArr = struct.split('\n').slice(1, -1).join('').split(';').filter((str) => !(/^\s*$/g).exec(str));

    return valuesArr.flatMap((val) => {
        const valInfo = (/(.+?)(?=(\S.|\S)+$)((\S|\S+,\s|(\S|\S+,\s))+$)/g).exec(val.trim());
        const type = valInfo?.[1].replace(/\s|\*/g, '');
        const name = valInfo?.[3];
        const isPtrType = valInfo?.[1]?.includes('*') && !valInfo?.[1]?.includes('const char');
        // const keyName = type.toLowerCase() === 'universeid'
        //     ? 'universeId'
        //     : name;
        const keyName = name;
        if (type.trim().startsWith(type.trim()[0].toUpperCase())) {
            const subStruct = structFromName(type, structs);
            if (subStruct) {
                return `{"${keyName}", ${structToCppJsonVals(
                    subStruct,
                    `${valueName}${lastWasPtr && valueName.includes('.') ? '->' : '.'}${name}`,
                    structs,
                    undefined,
                    isPtrType
                )}}`;
            }
        }

        return `{"${keyName}", ${valueName}${lastWasPtr && valueName.includes('.') ? '->' : '.'}${name}}`;
    });
};

export const genJsonFunc = (usingFunc: string, structs: string[]): string => {
    const resName = 'func_res_1';
    const arraySize = 32767; // ^= SHRT_MAX should be enough, right? technically possible: 4294967295 (UINT32_MAX)
    // TODO: make arraySize user controllable
    const funcName = getFuncName(usingFunc);
    // eslint-disable-next-line no-console
    console.log(`generating Function: ${funcName}...`);
    const args = getArgs(usingFunc)?.split(',');

    const jsonFuncArgs = args.filter((arg) =>
        (!arg.includes('*') || arg.match(/const char\*[^*]/g)) && (/\S+$/).exec(arg)?.[0] !== 'resultlen'
    ).join(',');
    const ptrArgs = args.filter((arg, i, arr) =>
        arg.includes('*') && !arg.match(/const char\*[^*]/g) && (/\S+$/).exec(arr[i+1])?.[0] !== 'resultlen'
    );
    const arrayArgs = args.filter((arg, i, arr) =>
        arg.includes('*') && !arg.match(/const char\*[^*]/g) && (/\S+$/).exec(arr[i+1])?.[0] === 'resultlen'
    );

    const returnType = getReturnType(usingFunc);
    const resultStruct = structFromName(returnType, structs);

    const lines = [
        `json ${funcName}(PARAMS(${jsonFuncArgs}))`,
        '    {'
    ];
    if (ptrArgs.length) {
        lines.push(ptrArgs?.map((arg) => {
            const regexRes = (/(^[A-z]+).*?(\S+)$/g).exec(arg.trim());
            return `        ${regexRes[1]} ${regexRes[2]};`;
        })?.join('\n'));
    }
    if (arrayArgs.length) {
        lines.push(
            `        uint32_t resultlen = ${arraySize};`,
            arrayArgs?.map((arg) => {
                const regexRes = (/(^[A-z]+).*?(\S+)$/g).exec(arg.trim());
                return `        ${
                    // TODO: fix horrible check for str arrays...
                    regexRes[1] === 'const' ? 'std::vector<const char*>' : `std::vector<${regexRes[1]}>`
                } ${regexRes[2]};\n`
                + `        ${regexRes[2]}.resize(resultlen);`;
            })?.join('\n'));
    }
    lines.push(...[
        `        ${ returnType.includes('void') ? '' : `const auto ${resName} = `}invoke(${funcName}${
            args && args[0] !== ''
                ? `, ${args.map((arg) => {
                    const pname = (/\S+$/).exec(arg.trim())[0];
                    return ptrArgs.includes(arg)
                        ? `&${pname}`
                        : arrayArgs.includes(arg)
                            ? `${pname}.data()`
                            : pname;
                }).join(', ')}`
                : ''
        });`
    ]);
    if(ptrArgs.length) {
        lines.push(...[
            `        if (${resName}) {`,
            '            return json',
            '            {',
            structToCppJsonVals(resultStruct, resName, structs, returnType)
                .map((line) => `                ${line}`)
                .join(',\n') + ','
        ]);
        lines.push(...[
            ptrArgs.map((arg) => {
                const variableName = (/\S+$/).exec(arg)[0];
                const argStruct = structFromName((/(^[A-z]+)/g).exec(arg.trim())[1], structs);
                return [
                    `                {"${variableName}", {`,
                    structToCppJsonVals(argStruct, variableName, structs, returnType)
                        .map((line) => `                    ${line}`)
                        .join(',\n'),
                    '                }}'
                ].join('\n');
            }).join(',\n')
        ]);
        lines.push(...[
            '            };',
            '        }',
            ' '
        ]);
    }
    if(arrayArgs.length) {
        lines.push(...[
            `        if (${resName}) {`,
            arrayArgs?.map((arg) => {
                const regexRes = (/(^[A-z]+).*?(\S+)$/g).exec(arg.trim());
                return `            ${regexRes[2]}.resize(${resName});`;
            })?.join('\n')
        ]);
        lines.push( ...arrayArgs.map((arg) => {
            // TODO: move "return" statement out of map...
            const regexRes = (/(^[A-z]+).*?(\S+)$/g).exec(arg.trim());
            const argType = regexRes[1] === 'const' ? 'const char*' : regexRes[1];
            const argStruct = structFromName(argType, structs);
            if (!argStruct) {
                return [
                    '            return json',
                    '            {',
                    structToCppJsonVals(resultStruct, resName, structs, returnType)
                        .map((line) => `                ${line}`)
                        .join(',\n') + ',',
                    `                {"${regexRes[2]}", ${regexRes[2]}}`,
                    '            };'
                ].join('\n');
            }
            return [
                `            std::vector<json> json_${regexRes[2]};`,
                `            json_${regexRes[2]}.reserve(${resName});`,
                `        	for (const auto& v : ${regexRes[2]})`,
                '            {',
                `                json_${regexRes[2]}.push_back({`,
                structToCppJsonVals(argStruct, 'v', structs, returnType)
                    .map((line) => `                    ${line}`)
                    .join(',\n'),
                '                });',
                '            }',
                '            return json',
                '            {',
                structToCppJsonVals(resultStruct, resName, structs, returnType)
                    .map((line) => `                ${line}`)
                    .join(',\n') + ',',
                `                {"${regexRes[2]}", json_${regexRes[2]}}`,
                '            };'
            ].join('\n');
        }));
        lines.push(...[
            '        }',
            ' '
        ]);
    }
    lines.push(...[
        '        return json',
        '        {',
        structToCppJsonVals(resultStruct, resName, structs, returnType)
            .map((line) => `            ${line}`)
            .join(',\n'),
        '        };',
        '    }',
        ' '
    ]);
    return lines.filter((line) => !!line).join('\n');
};

export const getTypedefsFile = (typefStrings: string[]): string => (
    `${FFI_TYPEDEF_H}{\n    ${typefStrings.join('\n    ')}\n}\n`
);
export const getStructsFile = (structStrings: string[]): string => (
    `${FFI_TYPEDEF_STRUCT_H}{\n    ${structStrings.join('\n').replace(/\n/g, '\n    ')}\n}\n`
);
export const getFuncsFile = (funcStrings: string[]): string => (
    `${FFI_FUNCS_H}{\n    ${(funcsToUsing(funcStrings)).join('\n    ')}\n}\n`
);

export const getCppJsonFile = (usingFuncStrings: string[], structStrings: string[]): string => (
    `${FFI_JSON_H}\n    ${
        usingFuncStrings.map((func) => genJsonFunc(func, structStrings)).join('\n    ')
    }\n}\n`
);

export const getHttpFuncsCppFile = (jsonFuncStrings: string[]): string => (
    `${HTTP_SERVER_FUNS}\n${getHttpFuncsCpp(jsonFuncStrings)}\n}\n`
);
