import { PathLike, lstatSync, readdirSync } from 'fs';
import { join } from 'path';

export const isDir = (path: PathLike): boolean => lstatSync(path).isDirectory();

export const listFiles = (dir: string): string[] =>
    isDir(dir)
        ? [].concat(...readdirSync(dir)
            .map((f) => listFiles(join(dir, f))))
        : [dir];


export const structFromName = (structName: string, structs: string[]): string => (
    structs.find((struct) => struct.endsWith(` ${structName};`))
);
