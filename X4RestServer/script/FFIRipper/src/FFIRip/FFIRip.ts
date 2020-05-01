import config from 'config';
import { listFiles } from '../util/util';
import { readFile as readFileCallbacks } from 'fs';
import { promisify } from 'util';

const readFile = promisify(readFileCallbacks);

const uiPath: string = config.get('uiPath');
const LUA_FILE_EXT = '.lua';

const FFI_CDEF_START = 'ffi.cdef[[';
const FFI_CDEF_END = ']]';

const OSX_WORKAROUND = [
    'typedef struct {\n    int unknown;\n} mach_header;',
    'typedef struct {\n    int unknown;\n} mach_header_64;',
    'typedef struct {\n    int unknown;\n} mach_fat_header;',
    'typedef struct {\n    int unknown;\n} mach_fat_arch;'
];


export const getLuaFiles = (dir: string): string[] => listFiles(dir).filter((f) => f.endsWith(LUA_FILE_EXT));

const includesFfi = async (file: string): Promise<boolean> => (await readFile(file)).includes(FFI_CDEF_START);

export const getFfiLuaFiles = async (): Promise<string[]> => {
    const luaFiles = getLuaFiles(uiPath);
    const filterProms = await Promise.all(luaFiles.map((file) => includesFfi(file)));
    return luaFiles.filter((file, index) => filterProms[index]);
};

export const readFFiStrings = async (files: string[]): Promise<string[]> => (
    // read all files "at once"
    (await Promise.all(files.map((file) => readFile(file))))
    // extract ffi.cdef array
        .map((content) => content.toString().split(FFI_CDEF_START).pop().split(FFI_CDEF_END)?.[0] )
    // remove blank lines
        .map((ffiString) => ffiString.replace(/^\s*/g, ''))
);

export const filterTypedefs = (ffiFiles: string[]): string[] => ffiFiles.flatMap((ffiStrings) => ffiStrings.split(/(?<=;)/g))
// remove blank lines
    .map((ffiString) => ffiString.replace(/^\s*/g, ''))
    .filter((ffiString) => ffiString.startsWith('typedef') && !ffiString.startsWith('typedef struct'))
    .sort()
// remove duplicates
    .filter((v,i,arr) => arr.indexOf(v) === i);

export const filterStructs = (ffiFiles: string[]): string[] => ffiFiles.join('\n')
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

export const filterFuns = (ffiFiles: string[]): string[] => ffiFiles.flatMap((ffiStrings) => ffiStrings.split(/(?<=\);)/g))
// remove blank lines
    .map((ffiString) => ffiString.replace(/^\s*/g, ''))
    .filter((ffiString) =>  ffiString !== '')
    .filter((ffiString) => !ffiString.startsWith('typedef'))
    .sort()
// remove duplicates
    .filter((v,i,arr) => arr.indexOf(v) === i)
// remove dupes with different parameter names (and potential overloads, but meh);
    .filter((v, i, arr) => arr[i+1]?.split('(')?.[0] !== v?.split('(')?.[0]);

export const sortStructArray = (structs: string[]): string[] => {
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
    const res = structs.sort((structA, structB) =>
        requiredTypes.includes(structA.match(/\S+?(?=;(?!\s))/g)?.[0])
            ? -1 : requiredTypes.includes(structB.match(/\S+?(?=;(?!\s))/g)?.[0])
                ? 1 : structA > structB ? -1 : 1);
    res.unshift(...OSX_WORKAROUND);
    return res;
};
