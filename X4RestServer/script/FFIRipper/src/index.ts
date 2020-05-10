/* eslint-disable no-console */
import { getTypedefsFile, getStructsFile, getFuncsFile, getCppJsonFile, getHttpFuncsCppFile } from './CodeGen/codeGen';
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
import { CFunction } from './CodeGen/function';

const EXCLUDE_LIST: readonly string[] = [
    // TODO: Support input translation of structs:
    'CreateBlacklist',
    'GetCompSlotScreenPos',
    'GetLoadoutStatistics2',
    'GetMapPositionOnEcliptic2',
    'GetRoomForTransporter',
    'GetSlotComponent',
    'GetTransporterLocationComponent',
    'ReserveBuildPlot',
    'ExtendBuildPlot',
    'IsControlPanelHacked',
    'PerformCompSlotPlayerAction',
    'GetControlPanelName',
    'GetTransporterLocationName',
    'GetBuildDuration',
    'GetControlPanelHackExpireTime',
    'GetBuildPlotPrice',
    'GetCompSlotPlayerActions',
    'GetControlPanelNumRequiredWares',
    'GetControlPanelRequiredWares',
    'GetMineablesAtSectorPos',
    'GetNumCompSlotPlayerActions',
    'GetNumMineablesAtSectorPos',
    'MovePlayerToSectorPos',
    'PayBuildPlotSize',
    'SaveLoadout',
    'SetBoxTextBoxColor',
    'SetBoxTextColor',
    'SetButtonHighlightColor',
    'SetButtonText2Color',
    'SetButtonTextColor',
    'SetCheckBoxColor',
    'SetCustomGameStartPosRotProperty',
    'SetCustomGameStartShipAndLoadoutProperty',
    'SetFlowChartEdgeColor',
    'SetFlowChartNodeCaptionTextColor',
    'SetFlowChartNodeOutlineColor',
    'SetFlowChartNodeStatusColor',
    'SetGuidance',
    'SetIconColor',
    'SetMacroMapPlayerSectorOffset',
    'SetMapState',
    'SetPlayerLogo',
    'ShowObjectConfigurationMap',
    'SpawnObjectAtPos',
    'ShowUniverseMacroMap',
    'ShowUniverseMap2',
    'StartControlPanelHack',
    'TransportPlayerToTarget',
    'UpdateBlacklist',
    'UpdateConstructionMapItemLoadout',
    'UpdateObjectConfigurationMap',
    'UpdatePlayerAlert',
    // TODO: impl. manually. :
    'FilterComponentByText',
    'SetMapFilterString',
    'GetBlacklistInfo'
] as const;

namespace FFIRipper {

    export const main = async (): Promise<void> => {

        console.log('reading ui files...');
        const ffiStrings = await readFFiStrings(await getFfiLuaFiles());

        console.log('extracting typedefs...');
        const typedefs = filterTypedefs(ffiStrings);
        console.log('extracting structs...');
        const structs = sortStructArray(filterStructs(ffiStrings));
        console.log('extracting funcs...');
        const funcs = filterFuns(ffiStrings).map((f) => new CFunction(f));


        console.log('generating typedef file...');
        writeFileSync(
            resolve(join(
                __dirname,
                '../../../X4RestServer/src/__generated__/ffi_typedef.h'
            )),
            getTypedefsFile(typedefs)
        );
        console.log('generating structs file...');
        writeFileSync(
            resolve(join(
                __dirname,
                '../../../X4RestServer/src/__generated__/ffi_typedef_struct.h'
            )),
            getStructsFile(structs)
        );
        console.log('generating funcs file...');
        writeFileSync(
            resolve(join(
                __dirname,
                '../../../X4RestServer/src/__generated__/ffi_funcs.h'
            )),
            getFuncsFile(funcs)
        );

        const funcsToGenImpl = funcs.filter((f) => !EXCLUDE_LIST.includes(f.name));
        console.log('generating funcsToJson file...');
        const cppJsonImpl = getCppJsonFile(funcsToGenImpl, structs);
        writeFileSync(
            resolve(join(
                __dirname,
                '../../../X4RestServer/src/__generated__/gen_ffi_json.h'
            )),
            cppJsonImpl
        );

        console.log('generating endpointsImpl. file...');
        const jsonImplFuncs = cppJsonImpl.match(/json.*?\)\)/g);
        const httpCppImpl = getHttpFuncsCppFile(jsonImplFuncs);
        writeFileSync(
            resolve(join(
                __dirname,
                '../../../X4RestServer/src/__generated__/gen_http_funs.h'
            )),
            httpCppImpl
        );
        console.log('done');

    };
}

FFIRipper.main();
