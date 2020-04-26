import { PathLike, lstatSync, mkdirSync, writeFileSync } from 'fs';
/* eslint-disable no-console */
import config from 'config';
import { join, resolve } from 'path';
import { readdirSync, readFile as readFileCallbacks } from 'fs';
import { promisify } from 'util';

const readFile = promisify(readFileCallbacks);


const ffi_typedef_h =
`#pragma once
#include <cstdint>

namespace X4FFI
`;

const ffi_typedef_struct_h =
`#pragma once
#include "ffi_typedef.h"

namespace X4FFI
`;

const ffi_funcs_h =
`#pragma once
#include "fii_typedef_struct.h"

namespace X4FFI
`;


namespace FFIRipper {

    const uiPath: string = config.get('uiPath');
    const luaFileExt = '.lua';

    const ffiCdefStart = 'ffi.cdef[[';
    const ffiCdefEnd = ']]';

    const isDir = (path: PathLike): boolean => lstatSync(path).isDirectory();

    const listFiles = (dir: string): string[] =>
        isDir(dir)
            ? [].concat(...readdirSync(dir).map((f) => listFiles(join(dir, f))))
            : [dir];

    const getLuaFiles = (dir: string): string[] => listFiles(dir).filter((f) => f.endsWith(luaFileExt));

    const includesFfi = async (file: string): Promise<boolean> => (await readFile(file)).includes(ffiCdefStart);

    const getFfiLuaFiles = async (): Promise<string[]> => {
        const luaFiles = getLuaFiles(uiPath);
        const filterProms = await Promise.all(luaFiles.map((file) => includesFfi(file)));
        return luaFiles.filter((file, index) => filterProms[index]);
    };

    const readFFiStrings = async (files: string[]): Promise<string[]> => (
        // read all files "at once"
        (await Promise.all(files.map((file) => readFile(file))))
            // extract ffi.cdef array
            .map((content) => content.toString().split(ffiCdefStart).pop().split(ffiCdefEnd)?.[0] )
            // remove blank lines
            .map((ffiString) => ffiString.replace(/^\s*/g, ''))
    );

    const filterTypedefs = (ffiFiles: string[]): string[] => ffiFiles.flatMap((ffiStrings) => ffiStrings.split(/(?<=;)/g))
        // remove blank lines
        .map((ffiString) => ffiString.replace(/^\s*/g, ''))
        .filter((ffiString) => ffiString.startsWith('typedef') && !ffiString.startsWith('typedef struct'))
        .sort()
        // remove duplicates
        .filter((v,i,arr) => arr.indexOf(v) === i);

    const filterStructs = (ffiFiles: string[]): string[] => ffiFiles.flatMap((ffiStrings) => ffiStrings.split(/(?<=\}(.*?);)/g))
        // remove blank lines
        .map((ffiString) => ffiString.replace(/^\s*/g, ''))
        .filter((ffiString) => ffiString.startsWith('typedef struct'))
        // remove const variants
        .filter((v, i, arr) =>
            v.includes('const') && !v.includes('const char')
                ? (arr.find((arrv) => arrv.replace(/const /g, '') === v.replace(/const /g, ''))) ? false : true
                : true)
        .sort()
        // remove duplicates
        .filter((v,i,arr) => arr.indexOf(v) === i)
        ;

    const filterFuns = (ffiFiles: string[]): string[] => ffiFiles.flatMap((ffiStrings) => ffiStrings.split(/(?<=\);)/g))
        // remove blank lines
        .map((ffiString) => ffiString.replace(/^\s*/g, ''))
        .filter((ffiString) =>  ffiString !== '')
        .filter((ffiString) => !ffiString.startsWith('typedef'))
        .sort()
        // remove duplicates
        .filter((v,i,arr) => arr.indexOf(v) === i)
        // remove dupes with different parameter names (and potential overloads, but meh);
        .filter((v, i, arr) => arr[i+1]?.split('(')?.[0] !== v?.split('(')?.[0]);

    export const main = async (): Promise<void> => {

        const luaFiles = await getFfiLuaFiles();
        const ffiStrings = await readFFiStrings(luaFiles);

        const typedefs = filterTypedefs(ffiStrings);
        const structs = filterStructs(ffiStrings);
        const funcs = filterFuns(ffiStrings);

        // TODO: sort structs by usage;
        // TODO: transform function decls to types


        writeFileSync(
            resolve(join(__dirname, '../../../X4RestServer/src/__generated__/ffi_typedef.h')),
            `${ffi_typedef_h}{\n    ${typedefs.join('\n    ')}\n}`
        );
        writeFileSync(
            resolve(join(__dirname, '../../../X4RestServer/src/__generated__/ffi_typedef_struct.h')),
            `${ffi_typedef_struct_h}{\n    ${structs.join('\n').replace(/\n/g, '\n    ')}\n}`
        );
        // writeFileSync('../../../X4RestServer/src/__generated__/ffi_typedef.h', `${ffi_typedef_h}{    ${typedefs.join('\n    ')}}`);


        // // mkdirSync('DEBUG');
        // writeFileSync('DEBUG/typedefs.h', typedefs.join('\n'));
        // writeFileSync('DEBUG/structs.h', structs.join('\n'));
        // writeFileSync('DEBUG/funcs.h', funcs.join('\n'));
    };
}

FFIRipper.main();

