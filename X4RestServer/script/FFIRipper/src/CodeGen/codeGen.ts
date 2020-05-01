import { getFuncName, getArgs } from './../util/util';

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

export const funcsToUsing = (funcs: string[]): string[] => funcs.map(
    (func) =>
        `using ${(/\S+?(?=\()/g).exec(func)} = ${(/(\S|const \S)+?(?=\s\S+?\()/g).exec(func)?.[0]} (*)${(/\(.*\)/g).exec(func)};`
);


// eslint-disable-next-line @typescript-eslint/no-unused-vars
const genJsonFunc = (func: string): string => {
    const funcName = getFuncName(func);
    const args = getArgs(func);
    const lines = [
        `json ${funcName}(PARAMS(${args}))`,
        '{',
        `    const auto res = invoke(${funcName}${ args ? `, ${args}` : '' });`,
        '    return json',
        '    {',
        // TODO: fill json body
        '    }',
        '}',
        ''
    ];
    return lines.join('n');
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

