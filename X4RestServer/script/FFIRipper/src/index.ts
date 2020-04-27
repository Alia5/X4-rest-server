import { PathLike, lstatSync, mkdirSync, writeFileSync } from 'fs';
/* eslint-disable no-console */
import config from 'config';
import { join, resolve } from 'path';
import { readdirSync, readFile as readFileCallbacks } from 'fs';
import { promisify } from 'util';

const readFile = promisify(readFileCallbacks);


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
#include "fii_typedef_struct.h"

namespace X4FFI
` as const;

const OSX_WORKAROUND = [
    'typedef struct {\n    int unknown;\n} mach_header;',
    'typedef struct {\n    int unknown;\n} mach_header_64;',
    'typedef struct {\n    int unknown;\n} mach_fat_header;',
    'typedef struct {\n    int unknown;\n} mach_fat_arch;'
];


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

    const filterStructs = (ffiFiles: string[]): string[] => ffiFiles.join('\n')
        // as ecmascript doesn't have recursive regexes, here a massive monster for parsing structs
        .match(/typedef struct(\s|\n)(\{(?:[^}{]*((\{(?:[^}{]*((\{(?:[^}{]*((\{(?:[^}{]*()?)*\}))?)*\}))?)*\}))?)*\}).*?;/gm)
        // remove blank lines
        .map((ffiString) => ffiString.replace(/^(\s|\n)*/g, ''))
        .map((ffiString) => ffiString.replace(/^typedef struct\s*?\n/g, 'typedef struct '))
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

    const sortStructArray = (structs: string[]): string[] => {
        // This bloody hell of a mess needs to be fixed.
        let requiredTypes: string[] = [];
        structs.forEach((struct) => {
            const reqTypes = struct.split(/(?<=;)/g)
                .filter((line) => !line.includes('{') && !line.includes('}') && !line.includes('const'))
                .flatMap((line) => line.match(/\S+?(?=\s\S)/gm))
                .map((type) => type.replace(/\*/g, ''))
                .sort()
                .filter((v,i,arr) => arr.indexOf(v) === i) // remove dupes
                .filter((type) => !type.match(/(int(32|64)|float|bool|char|double|long)/g))
                // just hardcode normal typedefs. i doubt they need to get updated all the time...
                .filter((type) => !type.match(/(BlacklistID|BuildTaskID|MissionID|NPCSeed|TradeID|MessageID|UniverseID)/g));
            if (reqTypes.length > 0) {
                requiredTypes.splice(Number.MAX_VALUE, 0, ...reqTypes);
            }
        });
        requiredTypes = requiredTypes.sort().filter((v,i,arr) => arr.indexOf(v) === i);
        console.log(requiredTypes);
        const res = structs.sort((structA, structB) =>
            requiredTypes.includes(structA.match(/\S+?(?=;(?!\s))/g)?.[0])
                ? -1 : requiredTypes.includes(structB.match(/\S+?(?=;(?!\s))/g)?.[0])
                    ? 1 : structA > structB ? -1 : 1);
        res.unshift(...OSX_WORKAROUND);
        return res;
    };


    export const main = async (): Promise<void> => {

        const luaFiles = await getFfiLuaFiles();
        const ffiStrings = await readFFiStrings(luaFiles);

        const typedefs = filterTypedefs(ffiStrings);
        const structs = sortStructArray(filterStructs(ffiStrings));
        const funcs = filterFuns(ffiStrings);

        // TODO: transform function decls to types

        writeFileSync(
            resolve(join(__dirname, '../../../X4RestServer/src/__generated__/ffi_typedef.h')),
            `${FFI_TYPEDEF_H}{\n    ${typedefs.join('\n    ')}\n}`
        );
        writeFileSync(
            resolve(join(__dirname, '../../../X4RestServer/src/__generated__/ffi_typedef_struct.h')),
            `${FFI_TYPEDEF_STRUCT_H}{\n    ${structs.join('\n').replace(/\n/g, '\n    ')}\n}`
        );
        // writeFileSync('../../../X4RestServer/src/__generated__/ffi_typedef.h', `${ffi_typedef_h}{    ${typedefs.join('\n    ')}}`);


        // // mkdirSync('DEBUG');
        // writeFileSync('DEBUG/typedefs.h', typedefs.join('\n'));
        // writeFileSync('DEBUG/structs.h', structs.join('\n'));
        // writeFileSync('DEBUG/funcs.h', funcs.join('\n'));
    };
}

FFIRipper.main();
