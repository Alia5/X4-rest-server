import { getTypedefsFile, getStructsFile, getFuncsFile } from './CodeGen/codeGen';
import { writeFileSync } from 'fs';
import { join, resolve } from 'path';
import {
    getFfiLuaFiles,
    readFFiStrings,
    filterTypedefs,
    filterStructs,
    sortStructArray,
    filterFuns
} from './FFIRip/FFIRip';

namespace FFIRipper {

    export const main = async (): Promise<void> => {

        const ffiStrings = await readFFiStrings(await getFfiLuaFiles());

        const typedefs = filterTypedefs(ffiStrings);
        const structs = sortStructArray(filterStructs(ffiStrings));
        const funcs = filterFuns(ffiStrings);

        writeFileSync(
            resolve(join(
                __dirname,
                '../../../X4RestServer/src/__generated__/ffi_typedef.h'
            )),
            getTypedefsFile(typedefs)
        );
        writeFileSync(
            resolve(join(
                __dirname,
                '../../../X4RestServer/src/__generated__/ffi_typedef_struct.h'
            )),
            getStructsFile(structs)
        );
        writeFileSync(
            resolve(join(
                __dirname,
                '../../../X4RestServer/src/__generated__/ffi_funcs.h'
            )),
            getFuncsFile(funcs)
        );
    };
}

FFIRipper.main();
