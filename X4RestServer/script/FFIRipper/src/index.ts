import { PathLike, lstatSync } from 'fs';
/* eslint-disable no-console */
import config from 'config';
import { join } from 'path';
import { readdirSync, readFile as readFileCallbacks } from 'fs';
import { promisify } from 'util';

const readFile = promisify(readFileCallbacks);

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
            .map((content) => content.toString().split(ffiCdefStart).pop().split(ffiCdefEnd)[0] )
            // remove blank lines
            .map((ffiString) => ffiString.replace(/^\s*/g, ''))
    );

    export const main = async (): Promise<void> => {
        const luaFiles = await getFfiLuaFiles();
        const ffiStrings = await readFFiStrings(luaFiles);


        console.log(ffiStrings);
    };
}

FFIRipper.main();
