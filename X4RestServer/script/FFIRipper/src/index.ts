import { getTypedefsFile, getStructsFile, getFuncsFile, genJsonFunc, getCppJsonFile, getHttpFuncsCppFile } from './CodeGen/codeGen';
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
import { funcsToUsing } from './util/util';

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

        const funcsToGenImpl = funcsToUsing(funcs)
            .filter((func) =>
                (/GetComponentDetails|GetPlayerName|GetSofttarget|GetDefaultOrder|GetAllFactions|GetFormationShapes/g)
                    .exec(func));
        const cppJsonImpl = getCppJsonFile(funcsToGenImpl, structs);
        writeFileSync(
            resolve(join(
                __dirname,
                '../../../X4RestServer/src/__generated__/gen_ffi_json.h'
            )),
            cppJsonImpl
        );

        const jsonImplFuncs = cppJsonImpl.match(/json.*?\)\)/g); 
        const httpCppImpl = getHttpFuncsCppFile(jsonImplFuncs);
        writeFileSync(
            resolve(join(
                __dirname,
                '../../../X4RestServer/src/__generated__/gen_http_funs.h'
            )),
            httpCppImpl
        );

    };
}

FFIRipper.main();
