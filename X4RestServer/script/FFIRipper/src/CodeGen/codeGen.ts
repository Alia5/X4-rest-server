import { getFuncName, getArgs, getReturnType, structFromName, funcsToUsing } from './../util/util';

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

const structToCppJsonVals = (struct: string|undefined, valueName: string, structs: string[]): string[] => {
    // currently no structs with arrays
    // or inner structs that are not separately defined
    // available via ffi funcs
    // so we ignore that, here
    if (!struct) {
        return [`{"value", ${valueName}}`];
    }
    const valuesArr = struct.split('\n').slice(1, -1).join('').split(';').filter((str) => !(/^\s*$/g).exec(str));

    return valuesArr.flatMap((val) => {
        const valInfo = (/(.+?)(?=\S.+$)((\S|\S+,\s|(\S|\S+,\s|(\S|\S+,\s|(\S|\S+,\s|(\S|\S+,\s|(\S|\S+,\s))))))+$)/g).exec(val);
        const type = valInfo?.[1].replace(/\s|\*/g, '');
        const name = valInfo?.[2];
        // const keyName = type.toLowerCase() === 'universeid'
        //     ? 'universeId'
        //     : name;
        const keyName = name;
        if (type.startsWith(type[0].toUpperCase())) {
            const subStruct = structFromName(type, structs);
            if (subStruct) {
                return `{"${keyName}", ${structToCppJsonVals(subStruct, `${valueName}.${name}`, structs)}}`;
            }
        }

        return `{"${keyName}", ${valueName}.${name}}`;
    });
};

export const genJsonFunc = (usingFunc: string, structs: string[]): string => {
    const resName = 'func_res_1';
    const funcName = getFuncName(usingFunc);
    const args = getArgs(usingFunc)?.split(',');

    const jsonFuncArgs = args.filter((arg) => !arg.includes('*') || arg.match(/const char\*[^*]/g)).join(',');
    const ptrArgs = args.filter((arg) => arg.includes('*') && !arg.match(/const char\*[^*]/g));

    const resultStruct = structFromName(getReturnType(usingFunc), structs);

    const lines = [
        `json ${funcName}(PARAMS(${jsonFuncArgs}))`,
        '    {'
    ];
    if (ptrArgs.length) {
        lines.push(ptrArgs?.map((arg) => {
            const regexRes = (/(^[A-z]+).*?(\S+)$/g).exec(arg);
            return `        ${regexRes[1]} ${regexRes[2]};`;
        })?.join('\n'));

    }
    lines.push(...[
        `        const auto ${resName} = invoke(${funcName}${
            args && args[0] !== ''
                ? `, ${args.map((arg) => {
                    const res = arg.includes('*') && !arg.match(/const char\*[^*]/g) ? '&' : '';
                    return res + (/\S+$/).exec(arg)[0];
                }).join(', ')}`
                : ''
        });`
    ]);
    if(ptrArgs.length) {
        lines.push(...[
            `        if (${resName}) {`,
            '            return json',
            '            {',
            structToCppJsonVals(resultStruct, resName, structs)
                .map((line) => `                ${line}`)
                .join(',\n') + ','
        ]);
        lines.push(...[
            ptrArgs.map((arg) => {
                const variableName = (/\S+$/).exec(arg)[0];
                const argStruct = structFromName((/(^[A-z]+)/g).exec(arg)[1], structs);
                return [
                    `                {"${variableName}", {`,
                    structToCppJsonVals(argStruct, variableName, structs)
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
    lines.push(...[
        '        return json',
        '        {',
        structToCppJsonVals(resultStruct, resName, structs)
            .map((line) => `            ${line}`)
            .join(',\n'),
        '        };',
        '    }',
        ' '
    ]);
    return lines.filter((line) => !!line).join('\n');
};

export const getTypedefsFile = (typefStrings: string[]): string => (
    `${FFI_TYPEDEF_H}{\n    ${typefStrings.join('\n    ')}\n}`
);
export const getStructsFile = (structStrings: string[]): string => (
    `${FFI_TYPEDEF_STRUCT_H}{\n    ${structStrings.join('\n').replace(/\n/g, '\n    ')}\n}`
);
export const getFuncsFile = (funcStrings: string[]): string => (
    `${FFI_FUNCS_H}{\n    ${(funcsToUsing(funcStrings)).join('\n    ')}\n}`
);

export const getCppJsonFile = (usingFuncStrings: string[], structStrings: string[]): string => (
    `${FFI_JSON_H}\n    ${
        usingFuncStrings.map((func) => genJsonFunc(func, structStrings)).join('\n    ')
    }\n}`
);
