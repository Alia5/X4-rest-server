import { PathLike, lstatSync, readdirSync } from 'fs';
import { join } from 'path';

export const isDir = (path: PathLike): boolean => lstatSync(path).isDirectory();

export const listFiles = (dir: string): string[] =>
    isDir(dir)
        ? [].concat(...readdirSync(dir)
            .map((f) => listFiles(join(dir, f))))
        : [dir];

export const getFuncName = (funcType: string): string => (/\s*using\s*(.+?)\s/g)
    .exec(funcType)?.[1];

export const getReturnType = (funcType: string): string => (/=\s*(.+?)\s/g)
    .exec(funcType)?.[1];

// it's not required, but i guess I like pointing out that ecmascript still doesn't have recursive regex
export const getArgs = (funcType: string): string => (
(/\(\*\)\(((?:[^()]|\(((?:[^()]|(\(((?:[^()]|\(((?:[^()]|)*)\))*)\)))*)\))*)\)/g)
    .exec(funcType)?.[1]
    || ''
);
