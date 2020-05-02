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
        if (type.startsWith(type[0].toUpperCase())) {
            const subStruct = structFromName(type, structs);
            if (subStruct) {
                return `{"${name}", ${structToCppJsonVals(subStruct, `${valueName}.${name}`, structs)}}`;
            }
        }

        return `{"${name}", ${valueName}.${name}}`;
    });
};

// eslint-disable-next-line @typescript-eslint/no-unused-vars
export const genJsonFunc = (usingFunc: string, structs: string[]): string => {
    const funcName = getFuncName(usingFunc);
    const args = getArgs(usingFunc);
    const resName = 'res';

    const resultStruct = structFromName(getReturnType(usingFunc), structs);

    const innerJson = structToCppJsonVals(resultStruct, resName, structs);

    const lines = [
        `json ${funcName}(PARAMS(${args}))`,
        '    {',
        `        const auto ${resName} = invoke(${funcName}${ args ? `, ${(`${args},`).match(/\S+?(?=,)/g).join(', ')}` : '' });`,
        '        return json',
        '        {',
        innerJson.map((line) => `            ${line}`).join(',\n'),
        '        };',
        '    }',
        ''
    ];
    return lines.join('\n');
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
