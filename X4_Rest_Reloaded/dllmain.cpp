#define WIN32_LEAN_AND_MEAN

#include "InitHelper.h"


#include <windows.h>
#include <string>

#define FUNCTION_COUNT 203

extern "C" uintptr_t functions[ FUNCTION_COUNT ] = {0};
std::string functionNames[] = {"DbgHelpCreateUserDump", "DbgHelpCreateUserDumpW", "EnumDirTree", "EnumDirTreeW",
    "EnumerateLoadedModules", "EnumerateLoadedModules64", "EnumerateLoadedModulesEx", "EnumerateLoadedModulesExW",
    "EnumerateLoadedModulesW64", "ExtensionApiVersion", "FindDebugInfoFile", "FindDebugInfoFileEx",
    "FindDebugInfoFileExW", "FindExecutableImage", "FindExecutableImageEx", "FindExecutableImageExW", "FindFileInPath",
    "FindFileInSearchPath", "GetTimestampForLoadedLibrary", "ImageDirectoryEntryToData", "ImageDirectoryEntryToDataEx",
    "ImageNtHeader", "ImageRvaToSection", "ImageRvaToVa", "ImagehlpApiVersion", "ImagehlpApiVersionEx",
    "MakeSureDirectoryPathExists", "MiniDumpReadDumpStream", "MiniDumpWriteDump", "SearchTreeForFile",
    "SearchTreeForFileW", "StackWalk", "StackWalk64", "SymAddSourceStream", "SymAddSourceStreamA",
    "SymAddSourceStreamW", "SymAddSymbol", "SymAddSymbolW", "SymCleanup", "SymDeleteSymbol", "SymDeleteSymbolW",
    "SymEnumLines", "SymEnumLinesW", "SymEnumProcesses", "SymEnumSourceFileTokens", "SymEnumSourceFiles",
    "SymEnumSourceFilesW", "SymEnumSourceLines", "SymEnumSourceLinesW", "SymEnumSym", "SymEnumSymbols",
    "SymEnumSymbolsForAddr", "SymEnumSymbolsForAddrW", "SymEnumSymbolsW", "SymEnumTypes", "SymEnumTypesByName",
    "SymEnumTypesByNameW", "SymEnumTypesW", "SymEnumerateModules", "SymEnumerateModules64", "SymEnumerateModulesW64",
    "SymEnumerateSymbols", "SymEnumerateSymbols64", "SymEnumerateSymbolsW", "SymEnumerateSymbolsW64",
    "SymFindDebugInfoFile", "SymFindDebugInfoFileW", "SymFindExecutableImage", "SymFindExecutableImageW",
    "SymFindFileInPath", "SymFindFileInPathW", "SymFromAddr", "SymFromAddrW", "SymFromIndex", "SymFromIndexW",
    "SymFromName", "SymFromNameW", "SymFromToken", "SymFromTokenW", "SymFunctionTableAccess",
    "SymFunctionTableAccess64", "SymGetFileLineOffsets64", "SymGetHomeDirectory", "SymGetHomeDirectoryW",
    "SymGetLineFromAddr", "SymGetLineFromAddr64", "SymGetLineFromAddrW64", "SymGetLineFromName", "SymGetLineFromName64",
    "SymGetLineFromNameW64", "SymGetLineNext", "SymGetLineNext64", "SymGetLineNextW64", "SymGetLinePrev",
    "SymGetLinePrev64", "SymGetLinePrevW64", "SymGetModuleBase", "SymGetModuleBase64", "SymGetModuleInfo",
    "SymGetModuleInfo64", "SymGetModuleInfoW", "SymGetModuleInfoW64", "SymGetOmapBlockBase", "SymGetOmaps",
    "SymGetOptions", "SymGetScope", "SymGetScopeW", "SymGetSearchPath", "SymGetSearchPathW", "SymGetSourceFile",
    "SymGetSourceFileFromToken", "SymGetSourceFileFromTokenW", "SymGetSourceFileToken", "SymGetSourceFileTokenW",
    "SymGetSourceFileW", "SymGetSourceVarFromToken", "SymGetSourceVarFromTokenW", "SymGetSymFromAddr",
    "SymGetSymFromAddr64", "SymGetSymFromName", "SymGetSymFromName64", "SymGetSymNext", "SymGetSymNext64",
    "SymGetSymPrev", "SymGetSymPrev64", "SymGetSymbolFile", "SymGetSymbolFileW", "SymGetTypeFromName",
    "SymGetTypeFromNameW", "SymGetTypeInfo", "SymGetTypeInfoEx", "SymGetUnwindInfo", "SymInitialize", "SymInitializeW",
    "SymLoadModule", "SymLoadModule64", "SymLoadModuleEx", "SymLoadModuleExW", "SymMatchFileName", "SymMatchFileNameW",
    "SymMatchString", "SymMatchStringA", "SymMatchStringW", "SymNext", "SymNextW", "SymPrev", "SymPrevW",
    "SymRefreshModuleList", "SymRegisterCallback", "SymRegisterCallback64", "SymRegisterCallbackW64",
    "SymRegisterFunctionEntryCallback", "SymRegisterFunctionEntryCallback64", "SymSearch", "SymSearchW",
    "SymSetContext", "SymSetHomeDirectory", "SymSetHomeDirectoryW", "SymSetOptions", "SymSetParentWindow",
    "SymSetScopeFromAddr", "SymSetScopeFromIndex", "SymSetSearchPath", "SymSetSearchPathW", "SymSrvDeltaName",
    "SymSrvDeltaNameW", "SymSrvGetFileIndexInfo", "SymSrvGetFileIndexInfoW", "SymSrvGetFileIndexString",
    "SymSrvGetFileIndexStringW", "SymSrvGetFileIndexes", "SymSrvGetFileIndexesW", "SymSrvGetSupplement",
    "SymSrvGetSupplementW", "SymSrvIsStore", "SymSrvIsStoreW", "SymSrvStoreFile", "SymSrvStoreFileW",
    "SymSrvStoreSupplement", "SymSrvStoreSupplementW", "SymUnDName", "SymUnDName64", "SymUnloadModule",
    "SymUnloadModule64", "UnDecorateSymbolName", "UnDecorateSymbolNameW", "WinDbgExtensionDllInit", "block", "chksym",
    "dbghelp", "dh", "fptr", "homedir", "itoldyouso", "lmi", "lminfo", "omap", "srcfiles", "stack_force_ebp",
    "stackdbg", "sym", "symsrv", "vc7fpo"};

// [index: 000] [ordinal: 001] DbgHelpCreateUserDump
#pragma comment(linker, "/EXPORT:DbgHelpCreateUserDump=func_120d4bcc12264f01a49264ce4e5d6600,@1")
extern "C" void func_120d4bcc12264f01a49264ce4e5d6600();

// [index: 001] [ordinal: 002] DbgHelpCreateUserDumpW
#pragma comment(linker, "/EXPORT:DbgHelpCreateUserDumpW=func_5a497ce26860415ab42f4f459876f50a,@2")
extern "C" void func_5a497ce26860415ab42f4f459876f50a();

// [index: 002] [ordinal: 003] EnumDirTree
#pragma comment(linker, "/EXPORT:EnumDirTree=func_09032d9487a04160b52bcd5c69d4d225,@3")
extern "C" void func_09032d9487a04160b52bcd5c69d4d225();

// [index: 003] [ordinal: 004] EnumDirTreeW
#pragma comment(linker, "/EXPORT:EnumDirTreeW=func_1193994b75124806925a32e2e7b3224e,@4")
extern "C" void func_1193994b75124806925a32e2e7b3224e();

// [index: 004] [ordinal: 005] EnumerateLoadedModules
#pragma comment(linker, "/EXPORT:EnumerateLoadedModules=func_1b8edab639384bf38c970734c669991b,@5")
extern "C" void func_1b8edab639384bf38c970734c669991b();

// [index: 005] [ordinal: 006] EnumerateLoadedModules64
#pragma comment(linker, "/EXPORT:EnumerateLoadedModules64=func_3eeb0856fb1442d29b3827b5ff3c56ea,@6")
extern "C" void func_3eeb0856fb1442d29b3827b5ff3c56ea();

// [index: 006] [ordinal: 007] EnumerateLoadedModulesEx
#pragma comment(linker, "/EXPORT:EnumerateLoadedModulesEx=func_2614d9b92afc497e96e6dc6b2c31da7a,@7")
extern "C" void func_2614d9b92afc497e96e6dc6b2c31da7a();

// [index: 007] [ordinal: 008] EnumerateLoadedModulesExW
#pragma comment(linker, "/EXPORT:EnumerateLoadedModulesExW=func_41812600d28e435d8d07b04859da4f19,@8")
extern "C" void func_41812600d28e435d8d07b04859da4f19();

// [index: 008] [ordinal: 009] EnumerateLoadedModulesW64
#pragma comment(linker, "/EXPORT:EnumerateLoadedModulesW64=func_466feb2fc7a04fe59cb6fdf1bc760e59,@9")
extern "C" void func_466feb2fc7a04fe59cb6fdf1bc760e59();

// [index: 009] [ordinal: 010] ExtensionApiVersion
#pragma comment(linker, "/EXPORT:ExtensionApiVersion=func_7f0922f210fb4009b045ae6aeaacb605,@10")
extern "C" void func_7f0922f210fb4009b045ae6aeaacb605();

// [index: 010] [ordinal: 011] FindDebugInfoFile
#pragma comment(linker, "/EXPORT:FindDebugInfoFile=func_f2febe9572d24fec927ba8143bcc31fc,@11")
extern "C" void func_f2febe9572d24fec927ba8143bcc31fc();

// [index: 011] [ordinal: 012] FindDebugInfoFileEx
#pragma comment(linker, "/EXPORT:FindDebugInfoFileEx=func_af26c2bbdb894a6a9e054e83aff46558,@12")
extern "C" void func_af26c2bbdb894a6a9e054e83aff46558();

// [index: 012] [ordinal: 013] FindDebugInfoFileExW
#pragma comment(linker, "/EXPORT:FindDebugInfoFileExW=func_b87a769cf3f74c039af9134860db53ef,@13")
extern "C" void func_b87a769cf3f74c039af9134860db53ef();

// [index: 013] [ordinal: 014] FindExecutableImage
#pragma comment(linker, "/EXPORT:FindExecutableImage=func_dd8db33634954900abe53de8f2e938fb,@14")
extern "C" void func_dd8db33634954900abe53de8f2e938fb();

// [index: 014] [ordinal: 015] FindExecutableImageEx
#pragma comment(linker, "/EXPORT:FindExecutableImageEx=func_e6c78f032eab43ae808e0e71b0cad112,@15")
extern "C" void func_e6c78f032eab43ae808e0e71b0cad112();

// [index: 015] [ordinal: 016] FindExecutableImageExW
#pragma comment(linker, "/EXPORT:FindExecutableImageExW=func_89ec93494815484c989c80645c9c0d3e,@16")
extern "C" void func_89ec93494815484c989c80645c9c0d3e();

// [index: 016] [ordinal: 017] FindFileInPath
#pragma comment(linker, "/EXPORT:FindFileInPath=func_f7ec0ce3270949d4abd17601d65a16eb,@17")
extern "C" void func_f7ec0ce3270949d4abd17601d65a16eb();

// [index: 017] [ordinal: 018] FindFileInSearchPath
#pragma comment(linker, "/EXPORT:FindFileInSearchPath=func_54ed153c41d2477f85c75c6ce7f2e8bf,@18")
extern "C" void func_54ed153c41d2477f85c75c6ce7f2e8bf();

// [index: 018] [ordinal: 019] GetTimestampForLoadedLibrary
#pragma comment(linker, "/EXPORT:GetTimestampForLoadedLibrary=func_628e418bc5ae47e7a634c3e2a0ba8e53,@19")
extern "C" void func_628e418bc5ae47e7a634c3e2a0ba8e53();

// [index: 019] [ordinal: 020] ImageDirectoryEntryToData
#pragma comment(linker, "/EXPORT:ImageDirectoryEntryToData=func_abfb253e31724ecb890696e7a302aee2,@20")
extern "C" void func_abfb253e31724ecb890696e7a302aee2();

// [index: 020] [ordinal: 021] ImageDirectoryEntryToDataEx
#pragma comment(linker, "/EXPORT:ImageDirectoryEntryToDataEx=func_5014c0bbfc9243b09d7a513d0859599e,@21")
extern "C" void func_5014c0bbfc9243b09d7a513d0859599e();

// [index: 021] [ordinal: 022] ImageNtHeader
#pragma comment(linker, "/EXPORT:ImageNtHeader=func_d7e8b7c88a074ec288e5ce183556f975,@22")
extern "C" void func_d7e8b7c88a074ec288e5ce183556f975();

// [index: 022] [ordinal: 023] ImageRvaToSection
#pragma comment(linker, "/EXPORT:ImageRvaToSection=func_c3814d0ad92e4cee82985eccca4cd677,@23")
extern "C" void func_c3814d0ad92e4cee82985eccca4cd677();

// [index: 023] [ordinal: 024] ImageRvaToVa
#pragma comment(linker, "/EXPORT:ImageRvaToVa=func_e4a98242d7664f3e9917207817fb2e39,@24")
extern "C" void func_e4a98242d7664f3e9917207817fb2e39();

// [index: 024] [ordinal: 025] ImagehlpApiVersion
#pragma comment(linker, "/EXPORT:ImagehlpApiVersion=func_5f15d681e5d248fe89737c551a5bddb9,@25")
extern "C" void func_5f15d681e5d248fe89737c551a5bddb9();

// [index: 025] [ordinal: 026] ImagehlpApiVersionEx
#pragma comment(linker, "/EXPORT:ImagehlpApiVersionEx=func_2e17b1f39b32459288179d47c8b777d3,@26")
extern "C" void func_2e17b1f39b32459288179d47c8b777d3();

// [index: 026] [ordinal: 027] MakeSureDirectoryPathExists
#pragma comment(linker, "/EXPORT:MakeSureDirectoryPathExists=func_38d9a17105524d86abe70f719a7301d4,@27")
extern "C" void func_38d9a17105524d86abe70f719a7301d4();

// [index: 027] [ordinal: 028] MiniDumpReadDumpStream
#pragma comment(linker, "/EXPORT:MiniDumpReadDumpStream=func_3159e20812b24a879e6402ab51f56539,@28")
extern "C" void func_3159e20812b24a879e6402ab51f56539();

// [index: 028] [ordinal: 029] MiniDumpWriteDump
#pragma comment(linker, "/EXPORT:MiniDumpWriteDump=func_a7085fd75dbc48b78d3d35d2c7311377,@29")
extern "C" void func_a7085fd75dbc48b78d3d35d2c7311377();

// [index: 029] [ordinal: 030] SearchTreeForFile
#pragma comment(linker, "/EXPORT:SearchTreeForFile=func_5d4a8feb4fca4aae876b69106d5fc355,@30")
extern "C" void func_5d4a8feb4fca4aae876b69106d5fc355();

// [index: 030] [ordinal: 031] SearchTreeForFileW
#pragma comment(linker, "/EXPORT:SearchTreeForFileW=func_fb3605d9102e489e834a1ba6e578bd66,@31")
extern "C" void func_fb3605d9102e489e834a1ba6e578bd66();

// [index: 031] [ordinal: 032] StackWalk
#pragma comment(linker, "/EXPORT:StackWalk=func_960ff22e918143ea85530407c93df6dc,@32")
extern "C" void func_960ff22e918143ea85530407c93df6dc();

// [index: 032] [ordinal: 033] StackWalk64
#pragma comment(linker, "/EXPORT:StackWalk64=func_2b25ec7428e948d7885011ad1a2cb0df,@33")
extern "C" void func_2b25ec7428e948d7885011ad1a2cb0df();

// [index: 033] [ordinal: 034] SymAddSourceStream
#pragma comment(linker, "/EXPORT:SymAddSourceStream=func_0e76c185cbf1446bbed074aaa6069bf2,@34")
extern "C" void func_0e76c185cbf1446bbed074aaa6069bf2();

// [index: 034] [ordinal: 035] SymAddSourceStreamA
#pragma comment(linker, "/EXPORT:SymAddSourceStreamA=func_de254f13bd4b4138be6459d66e0cae90,@35")
extern "C" void func_de254f13bd4b4138be6459d66e0cae90();

// [index: 035] [ordinal: 036] SymAddSourceStreamW
#pragma comment(linker, "/EXPORT:SymAddSourceStreamW=func_a740cdd88dd3421a87b20c1e0076f665,@36")
extern "C" void func_a740cdd88dd3421a87b20c1e0076f665();

// [index: 036] [ordinal: 037] SymAddSymbol
#pragma comment(linker, "/EXPORT:SymAddSymbol=func_8c836cc17ee14566af9e0944bfc74b06,@37")
extern "C" void func_8c836cc17ee14566af9e0944bfc74b06();

// [index: 037] [ordinal: 038] SymAddSymbolW
#pragma comment(linker, "/EXPORT:SymAddSymbolW=func_7f951e75a4a84e848a4c3b960e0a087d,@38")
extern "C" void func_7f951e75a4a84e848a4c3b960e0a087d();

// [index: 038] [ordinal: 039] SymCleanup
#pragma comment(linker, "/EXPORT:SymCleanup=func_a86135f51fec4830afe97ef714546fda,@39")
extern "C" void func_a86135f51fec4830afe97ef714546fda();

// [index: 039] [ordinal: 040] SymDeleteSymbol
#pragma comment(linker, "/EXPORT:SymDeleteSymbol=func_4b0c3a0fb8084a61a55521f0409f15eb,@40")
extern "C" void func_4b0c3a0fb8084a61a55521f0409f15eb();

// [index: 040] [ordinal: 041] SymDeleteSymbolW
#pragma comment(linker, "/EXPORT:SymDeleteSymbolW=func_70e5d2c0a41c4810bf8b3209d50c2eac,@41")
extern "C" void func_70e5d2c0a41c4810bf8b3209d50c2eac();

// [index: 041] [ordinal: 042] SymEnumLines
#pragma comment(linker, "/EXPORT:SymEnumLines=func_8d7a2ace41484fd9833988ff8e19cb25,@42")
extern "C" void func_8d7a2ace41484fd9833988ff8e19cb25();

// [index: 042] [ordinal: 043] SymEnumLinesW
#pragma comment(linker, "/EXPORT:SymEnumLinesW=func_f8c07b6f1c2c4f9cadd87e2fa1a148b3,@43")
extern "C" void func_f8c07b6f1c2c4f9cadd87e2fa1a148b3();

// [index: 043] [ordinal: 044] SymEnumProcesses
#pragma comment(linker, "/EXPORT:SymEnumProcesses=func_d4b0b901987d48b08e4ad7273d26a856,@44")
extern "C" void func_d4b0b901987d48b08e4ad7273d26a856();

// [index: 044] [ordinal: 045] SymEnumSourceFileTokens
#pragma comment(linker, "/EXPORT:SymEnumSourceFileTokens=func_d5799c579c5240fc8bfac1bbd9ae4649,@45")
extern "C" void func_d5799c579c5240fc8bfac1bbd9ae4649();

// [index: 045] [ordinal: 046] SymEnumSourceFiles
#pragma comment(linker, "/EXPORT:SymEnumSourceFiles=func_722ebc764f0b4aa59f3e99c7ff0f532a,@46")
extern "C" void func_722ebc764f0b4aa59f3e99c7ff0f532a();

// [index: 046] [ordinal: 047] SymEnumSourceFilesW
#pragma comment(linker, "/EXPORT:SymEnumSourceFilesW=func_9a305c0fbb9d431694b624f2b5447fed,@47")
extern "C" void func_9a305c0fbb9d431694b624f2b5447fed();

// [index: 047] [ordinal: 048] SymEnumSourceLines
#pragma comment(linker, "/EXPORT:SymEnumSourceLines=func_fdc9fbac0d994c62bc3f2f5635628cc9,@48")
extern "C" void func_fdc9fbac0d994c62bc3f2f5635628cc9();

// [index: 048] [ordinal: 049] SymEnumSourceLinesW
#pragma comment(linker, "/EXPORT:SymEnumSourceLinesW=func_00e40ac92bcd4c0b9a48310cda4fa80d,@49")
extern "C" void func_00e40ac92bcd4c0b9a48310cda4fa80d();

// [index: 049] [ordinal: 050] SymEnumSym
#pragma comment(linker, "/EXPORT:SymEnumSym=func_646b2baef49f4de98451b729e195e025,@50")
extern "C" void func_646b2baef49f4de98451b729e195e025();

// [index: 050] [ordinal: 051] SymEnumSymbols
#pragma comment(linker, "/EXPORT:SymEnumSymbols=func_b0dd177ba32a4a6f86b3f7bb3f44e61c,@51")
extern "C" void func_b0dd177ba32a4a6f86b3f7bb3f44e61c();

// [index: 051] [ordinal: 052] SymEnumSymbolsForAddr
#pragma comment(linker, "/EXPORT:SymEnumSymbolsForAddr=func_eb26d336a8bd4cf4b9d866d36cdebeb4,@52")
extern "C" void func_eb26d336a8bd4cf4b9d866d36cdebeb4();

// [index: 052] [ordinal: 053] SymEnumSymbolsForAddrW
#pragma comment(linker, "/EXPORT:SymEnumSymbolsForAddrW=func_9f051ed805b44911825043937af76a03,@53")
extern "C" void func_9f051ed805b44911825043937af76a03();

// [index: 053] [ordinal: 054] SymEnumSymbolsW
#pragma comment(linker, "/EXPORT:SymEnumSymbolsW=func_8cbcc99a34664cc781a340f9c037c8c7,@54")
extern "C" void func_8cbcc99a34664cc781a340f9c037c8c7();

// [index: 054] [ordinal: 055] SymEnumTypes
#pragma comment(linker, "/EXPORT:SymEnumTypes=func_145aadd283804790a87a37f9d2cba57c,@55")
extern "C" void func_145aadd283804790a87a37f9d2cba57c();

// [index: 055] [ordinal: 056] SymEnumTypesByName
#pragma comment(linker, "/EXPORT:SymEnumTypesByName=func_aa0f7b045a4f463cb67e254f91549a09,@56")
extern "C" void func_aa0f7b045a4f463cb67e254f91549a09();

// [index: 056] [ordinal: 057] SymEnumTypesByNameW
#pragma comment(linker, "/EXPORT:SymEnumTypesByNameW=func_d6cc2c83f3f94b65a97bcc36f1118e3a,@57")
extern "C" void func_d6cc2c83f3f94b65a97bcc36f1118e3a();

// [index: 057] [ordinal: 058] SymEnumTypesW
#pragma comment(linker, "/EXPORT:SymEnumTypesW=func_8207fe8372bf4fd29147728f7e4f96f5,@58")
extern "C" void func_8207fe8372bf4fd29147728f7e4f96f5();

// [index: 058] [ordinal: 059] SymEnumerateModules
#pragma comment(linker, "/EXPORT:SymEnumerateModules=func_c4c876a265e142e4a5d9cf1de138c9e1,@59")
extern "C" void func_c4c876a265e142e4a5d9cf1de138c9e1();

// [index: 059] [ordinal: 060] SymEnumerateModules64
#pragma comment(linker, "/EXPORT:SymEnumerateModules64=func_98e192b898014789bc6f1c05681c907c,@60")
extern "C" void func_98e192b898014789bc6f1c05681c907c();

// [index: 060] [ordinal: 061] SymEnumerateModulesW64
#pragma comment(linker, "/EXPORT:SymEnumerateModulesW64=func_40a3487452b24844a11862d6e43d7ac9,@61")
extern "C" void func_40a3487452b24844a11862d6e43d7ac9();

// [index: 061] [ordinal: 062] SymEnumerateSymbols
#pragma comment(linker, "/EXPORT:SymEnumerateSymbols=func_455f30bb765b4d47a0fc33997a41e82c,@62")
extern "C" void func_455f30bb765b4d47a0fc33997a41e82c();

// [index: 062] [ordinal: 063] SymEnumerateSymbols64
#pragma comment(linker, "/EXPORT:SymEnumerateSymbols64=func_aae6ef28a2d24cbd881939afb65ae9f1,@63")
extern "C" void func_aae6ef28a2d24cbd881939afb65ae9f1();

// [index: 063] [ordinal: 064] SymEnumerateSymbolsW
#pragma comment(linker, "/EXPORT:SymEnumerateSymbolsW=func_791b356f9bb64636b73854d75eb95b70,@64")
extern "C" void func_791b356f9bb64636b73854d75eb95b70();

// [index: 064] [ordinal: 065] SymEnumerateSymbolsW64
#pragma comment(linker, "/EXPORT:SymEnumerateSymbolsW64=func_a827e2f1f7a5433e91cf06febbc8edad,@65")
extern "C" void func_a827e2f1f7a5433e91cf06febbc8edad();

// [index: 065] [ordinal: 066] SymFindDebugInfoFile
#pragma comment(linker, "/EXPORT:SymFindDebugInfoFile=func_3d0575058c3b4ad588fa5cc31f3aec04,@66")
extern "C" void func_3d0575058c3b4ad588fa5cc31f3aec04();

// [index: 066] [ordinal: 067] SymFindDebugInfoFileW
#pragma comment(linker, "/EXPORT:SymFindDebugInfoFileW=func_448e0c3500eb42e993a4028cefa01302,@67")
extern "C" void func_448e0c3500eb42e993a4028cefa01302();

// [index: 067] [ordinal: 068] SymFindExecutableImage
#pragma comment(linker, "/EXPORT:SymFindExecutableImage=func_9905fb79efb246afafa67d36de3f46d8,@68")
extern "C" void func_9905fb79efb246afafa67d36de3f46d8();

// [index: 068] [ordinal: 069] SymFindExecutableImageW
#pragma comment(linker, "/EXPORT:SymFindExecutableImageW=func_0472d45552d34d308b36ca2202222f15,@69")
extern "C" void func_0472d45552d34d308b36ca2202222f15();

// [index: 069] [ordinal: 070] SymFindFileInPath
#pragma comment(linker, "/EXPORT:SymFindFileInPath=func_6398187f61b84534a2385053efe8950c,@70")
extern "C" void func_6398187f61b84534a2385053efe8950c();

// [index: 070] [ordinal: 071] SymFindFileInPathW
#pragma comment(linker, "/EXPORT:SymFindFileInPathW=func_23043282d8c64216951295c880cb7da0,@71")
extern "C" void func_23043282d8c64216951295c880cb7da0();

// [index: 071] [ordinal: 072] SymFromAddr
#pragma comment(linker, "/EXPORT:SymFromAddr=func_52ce42d41d404aa0b5235efdbbb6e817,@72")
extern "C" void func_52ce42d41d404aa0b5235efdbbb6e817();

// [index: 072] [ordinal: 073] SymFromAddrW
#pragma comment(linker, "/EXPORT:SymFromAddrW=func_a6731ba4b38f41dea6ddf2b52e84dcb9,@73")
extern "C" void func_a6731ba4b38f41dea6ddf2b52e84dcb9();

// [index: 073] [ordinal: 074] SymFromIndex
#pragma comment(linker, "/EXPORT:SymFromIndex=func_687d171a3b8c4602874f8b3f5cc673e3,@74")
extern "C" void func_687d171a3b8c4602874f8b3f5cc673e3();

// [index: 074] [ordinal: 075] SymFromIndexW
#pragma comment(linker, "/EXPORT:SymFromIndexW=func_2df01a5a2266489e848d4409f98de010,@75")
extern "C" void func_2df01a5a2266489e848d4409f98de010();

// [index: 075] [ordinal: 076] SymFromName
#pragma comment(linker, "/EXPORT:SymFromName=func_1104eaf18fe04128a03ed34750bc534b,@76")
extern "C" void func_1104eaf18fe04128a03ed34750bc534b();

// [index: 076] [ordinal: 077] SymFromNameW
#pragma comment(linker, "/EXPORT:SymFromNameW=func_4f88921bb09945138322a73b780fa936,@77")
extern "C" void func_4f88921bb09945138322a73b780fa936();

// [index: 077] [ordinal: 078] SymFromToken
#pragma comment(linker, "/EXPORT:SymFromToken=func_a6963f71dad0411195cdc60bf12a58b6,@78")
extern "C" void func_a6963f71dad0411195cdc60bf12a58b6();

// [index: 078] [ordinal: 079] SymFromTokenW
#pragma comment(linker, "/EXPORT:SymFromTokenW=func_2e2ac702406a40359779ee92f3124df9,@79")
extern "C" void func_2e2ac702406a40359779ee92f3124df9();

// [index: 079] [ordinal: 080] SymFunctionTableAccess
#pragma comment(linker, "/EXPORT:SymFunctionTableAccess=func_525c710710b74849985e248e90a6b7a9,@80")
extern "C" void func_525c710710b74849985e248e90a6b7a9();

// [index: 080] [ordinal: 081] SymFunctionTableAccess64
#pragma comment(linker, "/EXPORT:SymFunctionTableAccess64=func_f8432a5bde234aa7b091a0190692821e,@81")
extern "C" void func_f8432a5bde234aa7b091a0190692821e();

// [index: 081] [ordinal: 082] SymGetFileLineOffsets64
#pragma comment(linker, "/EXPORT:SymGetFileLineOffsets64=func_5ce186fe326348c080e04634555c4c40,@82")
extern "C" void func_5ce186fe326348c080e04634555c4c40();

// [index: 082] [ordinal: 083] SymGetHomeDirectory
#pragma comment(linker, "/EXPORT:SymGetHomeDirectory=func_b7bf49f769dd4f188626ea3e93ed228d,@83")
extern "C" void func_b7bf49f769dd4f188626ea3e93ed228d();

// [index: 083] [ordinal: 084] SymGetHomeDirectoryW
#pragma comment(linker, "/EXPORT:SymGetHomeDirectoryW=func_d61208f4506149ee99fe708cfc50276d,@84")
extern "C" void func_d61208f4506149ee99fe708cfc50276d();

// [index: 084] [ordinal: 085] SymGetLineFromAddr
#pragma comment(linker, "/EXPORT:SymGetLineFromAddr=func_cea06f13c17e4640bf33aff62e1d237c,@85")
extern "C" void func_cea06f13c17e4640bf33aff62e1d237c();

// [index: 085] [ordinal: 086] SymGetLineFromAddr64
#pragma comment(linker, "/EXPORT:SymGetLineFromAddr64=func_1e68542de6274511b826c3f25de44fed,@86")
extern "C" void func_1e68542de6274511b826c3f25de44fed();

// [index: 086] [ordinal: 087] SymGetLineFromAddrW64
#pragma comment(linker, "/EXPORT:SymGetLineFromAddrW64=func_2ce9dc8f6a394be9b7d4e883e5c90be3,@87")
extern "C" void func_2ce9dc8f6a394be9b7d4e883e5c90be3();

// [index: 087] [ordinal: 088] SymGetLineFromName
#pragma comment(linker, "/EXPORT:SymGetLineFromName=func_78644265a3cd46f4aa7dfdae1b5a47f7,@88")
extern "C" void func_78644265a3cd46f4aa7dfdae1b5a47f7();

// [index: 088] [ordinal: 089] SymGetLineFromName64
#pragma comment(linker, "/EXPORT:SymGetLineFromName64=func_5a94a69a463e4fd6ad748a5ca5b7e768,@89")
extern "C" void func_5a94a69a463e4fd6ad748a5ca5b7e768();

// [index: 089] [ordinal: 090] SymGetLineFromNameW64
#pragma comment(linker, "/EXPORT:SymGetLineFromNameW64=func_0a8d3143fbc149888df42da24aea9d41,@90")
extern "C" void func_0a8d3143fbc149888df42da24aea9d41();

// [index: 090] [ordinal: 091] SymGetLineNext
#pragma comment(linker, "/EXPORT:SymGetLineNext=func_066cce76939044c4832e64bc7386a7c7,@91")
extern "C" void func_066cce76939044c4832e64bc7386a7c7();

// [index: 091] [ordinal: 092] SymGetLineNext64
#pragma comment(linker, "/EXPORT:SymGetLineNext64=func_0bc368d8d7984aaa852faa7f3dcf8b63,@92")
extern "C" void func_0bc368d8d7984aaa852faa7f3dcf8b63();

// [index: 092] [ordinal: 093] SymGetLineNextW64
#pragma comment(linker, "/EXPORT:SymGetLineNextW64=func_cea60d6bd942402599685d84c4fc7bb6,@93")
extern "C" void func_cea60d6bd942402599685d84c4fc7bb6();

// [index: 093] [ordinal: 094] SymGetLinePrev
#pragma comment(linker, "/EXPORT:SymGetLinePrev=func_c6715e6b39e04b0e96364e368b56bc67,@94")
extern "C" void func_c6715e6b39e04b0e96364e368b56bc67();

// [index: 094] [ordinal: 095] SymGetLinePrev64
#pragma comment(linker, "/EXPORT:SymGetLinePrev64=func_3d37ff9b3a574909a3766f920622532e,@95")
extern "C" void func_3d37ff9b3a574909a3766f920622532e();

// [index: 095] [ordinal: 096] SymGetLinePrevW64
#pragma comment(linker, "/EXPORT:SymGetLinePrevW64=func_0817f91aa11c478abd68a9e87ded2109,@96")
extern "C" void func_0817f91aa11c478abd68a9e87ded2109();

// [index: 096] [ordinal: 097] SymGetModuleBase
#pragma comment(linker, "/EXPORT:SymGetModuleBase=func_1a0d0baacecf46bea01f2fc4b39e2ab8,@97")
extern "C" void func_1a0d0baacecf46bea01f2fc4b39e2ab8();

// [index: 097] [ordinal: 098] SymGetModuleBase64
#pragma comment(linker, "/EXPORT:SymGetModuleBase64=func_1d7b98493ef54968bf8098a58c778205,@98")
extern "C" void func_1d7b98493ef54968bf8098a58c778205();

// [index: 098] [ordinal: 099] SymGetModuleInfo
#pragma comment(linker, "/EXPORT:SymGetModuleInfo=func_683519a66d6c4e3fab94abf5a5cdfb1e,@99")
extern "C" void func_683519a66d6c4e3fab94abf5a5cdfb1e();

// [index: 099] [ordinal: 100] SymGetModuleInfo64
#pragma comment(linker, "/EXPORT:SymGetModuleInfo64=func_40cb2c5223504d0cacc7f445b191a07c,@100")
extern "C" void func_40cb2c5223504d0cacc7f445b191a07c();

// [index: 100] [ordinal: 101] SymGetModuleInfoW
#pragma comment(linker, "/EXPORT:SymGetModuleInfoW=func_fced6dea3d6d4eeab466e36dd9c601dd,@101")
extern "C" void func_fced6dea3d6d4eeab466e36dd9c601dd();

// [index: 101] [ordinal: 102] SymGetModuleInfoW64
#pragma comment(linker, "/EXPORT:SymGetModuleInfoW64=func_57c9111d75b04a22a4419cc2f3ee42e1,@102")
extern "C" void func_57c9111d75b04a22a4419cc2f3ee42e1();

// [index: 102] [ordinal: 103] SymGetOmapBlockBase
#pragma comment(linker, "/EXPORT:SymGetOmapBlockBase=func_c184d00e42c546ecbdf28a73c3d0860c,@103")
extern "C" void func_c184d00e42c546ecbdf28a73c3d0860c();

// [index: 103] [ordinal: 104] SymGetOmaps
#pragma comment(linker, "/EXPORT:SymGetOmaps=func_edcfca8dcb4143a4b5939aa44c911529,@104")
extern "C" void func_edcfca8dcb4143a4b5939aa44c911529();

// [index: 104] [ordinal: 105] SymGetOptions
#pragma comment(linker, "/EXPORT:SymGetOptions=func_3b37a9a5169c4fc189570cf39cda7e8a,@105")
extern "C" void func_3b37a9a5169c4fc189570cf39cda7e8a();

// [index: 105] [ordinal: 106] SymGetScope
#pragma comment(linker, "/EXPORT:SymGetScope=func_2ad339d96ee84a8cbd396a60a1777c11,@106")
extern "C" void func_2ad339d96ee84a8cbd396a60a1777c11();

// [index: 106] [ordinal: 107] SymGetScopeW
#pragma comment(linker, "/EXPORT:SymGetScopeW=func_894e37c16a2647d28212b6703d8878f7,@107")
extern "C" void func_894e37c16a2647d28212b6703d8878f7();

// [index: 107] [ordinal: 108] SymGetSearchPath
#pragma comment(linker, "/EXPORT:SymGetSearchPath=func_2dbf49fa4ae24e6a809d1b2b16dba0e2,@108")
extern "C" void func_2dbf49fa4ae24e6a809d1b2b16dba0e2();

// [index: 108] [ordinal: 109] SymGetSearchPathW
#pragma comment(linker, "/EXPORT:SymGetSearchPathW=func_e9400fca96b8475281335e6c372c0b24,@109")
extern "C" void func_e9400fca96b8475281335e6c372c0b24();

// [index: 109] [ordinal: 110] SymGetSourceFile
#pragma comment(linker, "/EXPORT:SymGetSourceFile=func_d2f648a8edad4f1a9ebe2a68fcbbc483,@110")
extern "C" void func_d2f648a8edad4f1a9ebe2a68fcbbc483();

// [index: 110] [ordinal: 111] SymGetSourceFileFromToken
#pragma comment(linker, "/EXPORT:SymGetSourceFileFromToken=func_620bde3040d44c599eed447e352225f8,@111")
extern "C" void func_620bde3040d44c599eed447e352225f8();

// [index: 111] [ordinal: 112] SymGetSourceFileFromTokenW
#pragma comment(linker, "/EXPORT:SymGetSourceFileFromTokenW=func_1905cc6d08f641ec975cef2911d458af,@112")
extern "C" void func_1905cc6d08f641ec975cef2911d458af();

// [index: 112] [ordinal: 113] SymGetSourceFileToken
#pragma comment(linker, "/EXPORT:SymGetSourceFileToken=func_fcf8508608f145a28f0181d9b2d29924,@113")
extern "C" void func_fcf8508608f145a28f0181d9b2d29924();

// [index: 113] [ordinal: 114] SymGetSourceFileTokenW
#pragma comment(linker, "/EXPORT:SymGetSourceFileTokenW=func_471b532f8e4742acb3159c237694d824,@114")
extern "C" void func_471b532f8e4742acb3159c237694d824();

// [index: 114] [ordinal: 115] SymGetSourceFileW
#pragma comment(linker, "/EXPORT:SymGetSourceFileW=func_9a8ecc62ddc64d278c8c6f9428d9aa83,@115")
extern "C" void func_9a8ecc62ddc64d278c8c6f9428d9aa83();

// [index: 115] [ordinal: 116] SymGetSourceVarFromToken
#pragma comment(linker, "/EXPORT:SymGetSourceVarFromToken=func_b465689dea434304b4115a98213e622b,@116")
extern "C" void func_b465689dea434304b4115a98213e622b();

// [index: 116] [ordinal: 117] SymGetSourceVarFromTokenW
#pragma comment(linker, "/EXPORT:SymGetSourceVarFromTokenW=func_2489d534a2f0417a92217160ced2cef0,@117")
extern "C" void func_2489d534a2f0417a92217160ced2cef0();

// [index: 117] [ordinal: 118] SymGetSymFromAddr
#pragma comment(linker, "/EXPORT:SymGetSymFromAddr=func_32f4d89c30ba4f5a87e3ac4837523bd4,@118")
extern "C" void func_32f4d89c30ba4f5a87e3ac4837523bd4();

// [index: 118] [ordinal: 119] SymGetSymFromAddr64
#pragma comment(linker, "/EXPORT:SymGetSymFromAddr64=func_b55eb589335f4ba4ae78b74cdcfa0390,@119")
extern "C" void func_b55eb589335f4ba4ae78b74cdcfa0390();

// [index: 119] [ordinal: 120] SymGetSymFromName
#pragma comment(linker, "/EXPORT:SymGetSymFromName=func_5bfa3f0cd59640afbf9809ac04fdf739,@120")
extern "C" void func_5bfa3f0cd59640afbf9809ac04fdf739();

// [index: 120] [ordinal: 121] SymGetSymFromName64
#pragma comment(linker, "/EXPORT:SymGetSymFromName64=func_782776b4332941778dd354455ab2d6cf,@121")
extern "C" void func_782776b4332941778dd354455ab2d6cf();

// [index: 121] [ordinal: 122] SymGetSymNext
#pragma comment(linker, "/EXPORT:SymGetSymNext=func_0c91f5d0767d4ed89ad8d47a9267a29f,@122")
extern "C" void func_0c91f5d0767d4ed89ad8d47a9267a29f();

// [index: 122] [ordinal: 123] SymGetSymNext64
#pragma comment(linker, "/EXPORT:SymGetSymNext64=func_d2600d742c684a13a7789e5fba421ef2,@123")
extern "C" void func_d2600d742c684a13a7789e5fba421ef2();

// [index: 123] [ordinal: 124] SymGetSymPrev
#pragma comment(linker, "/EXPORT:SymGetSymPrev=func_182399f1efaa448198a6b22edaa9a48a,@124")
extern "C" void func_182399f1efaa448198a6b22edaa9a48a();

// [index: 124] [ordinal: 125] SymGetSymPrev64
#pragma comment(linker, "/EXPORT:SymGetSymPrev64=func_570ef0385bd64edd8c4276b9216deb5b,@125")
extern "C" void func_570ef0385bd64edd8c4276b9216deb5b();

// [index: 125] [ordinal: 126] SymGetSymbolFile
#pragma comment(linker, "/EXPORT:SymGetSymbolFile=func_fcacc47e5035486aa15a0496049d8cd0,@126")
extern "C" void func_fcacc47e5035486aa15a0496049d8cd0();

// [index: 126] [ordinal: 127] SymGetSymbolFileW
#pragma comment(linker, "/EXPORT:SymGetSymbolFileW=func_1a44d0aaab1b4e6d9c83e8517f223c7a,@127")
extern "C" void func_1a44d0aaab1b4e6d9c83e8517f223c7a();

// [index: 127] [ordinal: 128] SymGetTypeFromName
#pragma comment(linker, "/EXPORT:SymGetTypeFromName=func_ce687ef4e98546e0972a5077f9ee574a,@128")
extern "C" void func_ce687ef4e98546e0972a5077f9ee574a();

// [index: 128] [ordinal: 129] SymGetTypeFromNameW
#pragma comment(linker, "/EXPORT:SymGetTypeFromNameW=func_6fc85559dcea47779831cfec37c60c79,@129")
extern "C" void func_6fc85559dcea47779831cfec37c60c79();

// [index: 129] [ordinal: 130] SymGetTypeInfo
#pragma comment(linker, "/EXPORT:SymGetTypeInfo=func_81b2a3adb3e145e7904566c0a9a26674,@130")
extern "C" void func_81b2a3adb3e145e7904566c0a9a26674();

// [index: 130] [ordinal: 131] SymGetTypeInfoEx
#pragma comment(linker, "/EXPORT:SymGetTypeInfoEx=func_8e2b4a7c44db45f19b209f6abe5c583a,@131")
extern "C" void func_8e2b4a7c44db45f19b209f6abe5c583a();

// [index: 131] [ordinal: 132] SymGetUnwindInfo
#pragma comment(linker, "/EXPORT:SymGetUnwindInfo=func_865275462e5f4ea893ddd2511003590a,@132")
extern "C" void func_865275462e5f4ea893ddd2511003590a();

// [index: 132] [ordinal: 133] SymInitialize
#pragma comment(linker, "/EXPORT:SymInitialize=func_d3a0b69f5985412ab83e7be62def9100,@133")
extern "C" void func_d3a0b69f5985412ab83e7be62def9100();

// [index: 133] [ordinal: 134] SymInitializeW
#pragma comment(linker, "/EXPORT:SymInitializeW=func_193068edf91e47abada775d2a6d20fb4,@134")
extern "C" void func_193068edf91e47abada775d2a6d20fb4();

// [index: 134] [ordinal: 135] SymLoadModule
#pragma comment(linker, "/EXPORT:SymLoadModule=func_e0978ce2ae91486d9bb1012066224f84,@135")
extern "C" void func_e0978ce2ae91486d9bb1012066224f84();

// [index: 135] [ordinal: 136] SymLoadModule64
#pragma comment(linker, "/EXPORT:SymLoadModule64=func_abbd939191f04bfdbd558016481be009,@136")
extern "C" void func_abbd939191f04bfdbd558016481be009();

// [index: 136] [ordinal: 137] SymLoadModuleEx
#pragma comment(linker, "/EXPORT:SymLoadModuleEx=func_bd69cbfeaf77402d8384c33292dab4c4,@137")
extern "C" void func_bd69cbfeaf77402d8384c33292dab4c4();

// [index: 137] [ordinal: 138] SymLoadModuleExW
#pragma comment(linker, "/EXPORT:SymLoadModuleExW=func_197fe9c27e85468a902d00595b4c88e8,@138")
extern "C" void func_197fe9c27e85468a902d00595b4c88e8();

// [index: 138] [ordinal: 139] SymMatchFileName
#pragma comment(linker, "/EXPORT:SymMatchFileName=func_0224b297621a45bbaf81d37926ae7843,@139")
extern "C" void func_0224b297621a45bbaf81d37926ae7843();

// [index: 139] [ordinal: 140] SymMatchFileNameW
#pragma comment(linker, "/EXPORT:SymMatchFileNameW=func_6d4997e986d347c99db25cc24fd89769,@140")
extern "C" void func_6d4997e986d347c99db25cc24fd89769();

// [index: 140] [ordinal: 141] SymMatchString
#pragma comment(linker, "/EXPORT:SymMatchString=func_8c5817cae33a46c4bd74b608d469a288,@141")
extern "C" void func_8c5817cae33a46c4bd74b608d469a288();

// [index: 141] [ordinal: 142] SymMatchStringA
#pragma comment(linker, "/EXPORT:SymMatchStringA=func_3e9148a80a964577ae2aaac1c94b2903,@142")
extern "C" void func_3e9148a80a964577ae2aaac1c94b2903();

// [index: 142] [ordinal: 143] SymMatchStringW
#pragma comment(linker, "/EXPORT:SymMatchStringW=func_44a1ecb7444a48d084415826ab4b74a6,@143")
extern "C" void func_44a1ecb7444a48d084415826ab4b74a6();

// [index: 143] [ordinal: 144] SymNext
#pragma comment(linker, "/EXPORT:SymNext=func_3786b412b7424191a8f92863a2995210,@144")
extern "C" void func_3786b412b7424191a8f92863a2995210();

// [index: 144] [ordinal: 145] SymNextW
#pragma comment(linker, "/EXPORT:SymNextW=func_324bf5f45ffd47798af156cc14e54be0,@145")
extern "C" void func_324bf5f45ffd47798af156cc14e54be0();

// [index: 145] [ordinal: 146] SymPrev
#pragma comment(linker, "/EXPORT:SymPrev=func_c13e1510288842af89f4e496146e1bf7,@146")
extern "C" void func_c13e1510288842af89f4e496146e1bf7();

// [index: 146] [ordinal: 147] SymPrevW
#pragma comment(linker, "/EXPORT:SymPrevW=func_88bbd0071d354028b3369a50a85ca00a,@147")
extern "C" void func_88bbd0071d354028b3369a50a85ca00a();

// [index: 147] [ordinal: 148] SymRefreshModuleList
#pragma comment(linker, "/EXPORT:SymRefreshModuleList=func_804a2084a6b4424ba28e1eb11b5f8033,@148")
extern "C" void func_804a2084a6b4424ba28e1eb11b5f8033();

// [index: 148] [ordinal: 149] SymRegisterCallback
#pragma comment(linker, "/EXPORT:SymRegisterCallback=func_ab01306cad744492a985ce3b95b5960c,@149")
extern "C" void func_ab01306cad744492a985ce3b95b5960c();

// [index: 149] [ordinal: 150] SymRegisterCallback64
#pragma comment(linker, "/EXPORT:SymRegisterCallback64=func_8080c183e2b046bc86678755f34eb924,@150")
extern "C" void func_8080c183e2b046bc86678755f34eb924();

// [index: 150] [ordinal: 151] SymRegisterCallbackW64
#pragma comment(linker, "/EXPORT:SymRegisterCallbackW64=func_c5fc4017fa724f14952456e291337c19,@151")
extern "C" void func_c5fc4017fa724f14952456e291337c19();

// [index: 151] [ordinal: 152] SymRegisterFunctionEntryCallback
#pragma comment(linker, "/EXPORT:SymRegisterFunctionEntryCallback=func_57ac55e2fdd84ec99bd1cf697b38724a,@152")
extern "C" void func_57ac55e2fdd84ec99bd1cf697b38724a();

// [index: 152] [ordinal: 153] SymRegisterFunctionEntryCallback64
#pragma comment(linker, "/EXPORT:SymRegisterFunctionEntryCallback64=func_4d7f6fcf84134956b99ca85165e3eda7,@153")
extern "C" void func_4d7f6fcf84134956b99ca85165e3eda7();

// [index: 153] [ordinal: 154] SymSearch
#pragma comment(linker, "/EXPORT:SymSearch=func_b581abf14f2b44d4a4aa6508dc7c98aa,@154")
extern "C" void func_b581abf14f2b44d4a4aa6508dc7c98aa();

// [index: 154] [ordinal: 155] SymSearchW
#pragma comment(linker, "/EXPORT:SymSearchW=func_dae8a0938d6a4ea28ee27c8ad296fb68,@155")
extern "C" void func_dae8a0938d6a4ea28ee27c8ad296fb68();

// [index: 155] [ordinal: 156] SymSetContext
#pragma comment(linker, "/EXPORT:SymSetContext=func_0dd96a1b03594209bcecc77fa4d3ae77,@156")
extern "C" void func_0dd96a1b03594209bcecc77fa4d3ae77();

// [index: 156] [ordinal: 157] SymSetHomeDirectory
#pragma comment(linker, "/EXPORT:SymSetHomeDirectory=func_746274b5a3e24932ab15ddf6497f6975,@157")
extern "C" void func_746274b5a3e24932ab15ddf6497f6975();

// [index: 157] [ordinal: 158] SymSetHomeDirectoryW
#pragma comment(linker, "/EXPORT:SymSetHomeDirectoryW=func_141be2aa490d4155ab9bcb065ad25496,@158")
extern "C" void func_141be2aa490d4155ab9bcb065ad25496();

// [index: 158] [ordinal: 159] SymSetOptions
#pragma comment(linker, "/EXPORT:SymSetOptions=func_bb8e0848bb654cbaaf585dce364b82c7,@159")
extern "C" void func_bb8e0848bb654cbaaf585dce364b82c7();

// [index: 159] [ordinal: 160] SymSetParentWindow
#pragma comment(linker, "/EXPORT:SymSetParentWindow=func_087e38567ed94e3c922b95f90f297d28,@160")
extern "C" void func_087e38567ed94e3c922b95f90f297d28();

// [index: 160] [ordinal: 161] SymSetScopeFromAddr
#pragma comment(linker, "/EXPORT:SymSetScopeFromAddr=func_cfbb7c03c7ab440588c2460829842e68,@161")
extern "C" void func_cfbb7c03c7ab440588c2460829842e68();

// [index: 161] [ordinal: 162] SymSetScopeFromIndex
#pragma comment(linker, "/EXPORT:SymSetScopeFromIndex=func_f0fe26bbce8843429df3f4dfd62abd0f,@162")
extern "C" void func_f0fe26bbce8843429df3f4dfd62abd0f();

// [index: 162] [ordinal: 163] SymSetSearchPath
#pragma comment(linker, "/EXPORT:SymSetSearchPath=func_e83f581931b342ccb0257e576fe9472f,@163")
extern "C" void func_e83f581931b342ccb0257e576fe9472f();

// [index: 163] [ordinal: 164] SymSetSearchPathW
#pragma comment(linker, "/EXPORT:SymSetSearchPathW=func_23101f60bfbc43eabb4bd00f1f8fd433,@164")
extern "C" void func_23101f60bfbc43eabb4bd00f1f8fd433();

// [index: 164] [ordinal: 165] SymSrvDeltaName
#pragma comment(linker, "/EXPORT:SymSrvDeltaName=func_0e8629d277e148dabe58195bbd1bc19f,@165")
extern "C" void func_0e8629d277e148dabe58195bbd1bc19f();

// [index: 165] [ordinal: 166] SymSrvDeltaNameW
#pragma comment(linker, "/EXPORT:SymSrvDeltaNameW=func_32c75c9ffff64c8c96ef07dbdec9876a,@166")
extern "C" void func_32c75c9ffff64c8c96ef07dbdec9876a();

// [index: 166] [ordinal: 167] SymSrvGetFileIndexInfo
#pragma comment(linker, "/EXPORT:SymSrvGetFileIndexInfo=func_a20c633cb6c74cda86290059e5346038,@167")
extern "C" void func_a20c633cb6c74cda86290059e5346038();

// [index: 167] [ordinal: 168] SymSrvGetFileIndexInfoW
#pragma comment(linker, "/EXPORT:SymSrvGetFileIndexInfoW=func_44e8bb14d6864d2daf68692969e5bb7f,@168")
extern "C" void func_44e8bb14d6864d2daf68692969e5bb7f();

// [index: 168] [ordinal: 169] SymSrvGetFileIndexString
#pragma comment(linker, "/EXPORT:SymSrvGetFileIndexString=func_a4be3fb2023a493da75af93dff4d760c,@169")
extern "C" void func_a4be3fb2023a493da75af93dff4d760c();

// [index: 169] [ordinal: 170] SymSrvGetFileIndexStringW
#pragma comment(linker, "/EXPORT:SymSrvGetFileIndexStringW=func_9c5b914d48b743e0b6bd5353ee3a4399,@170")
extern "C" void func_9c5b914d48b743e0b6bd5353ee3a4399();

// [index: 170] [ordinal: 171] SymSrvGetFileIndexes
#pragma comment(linker, "/EXPORT:SymSrvGetFileIndexes=func_bb3dd46db1f049f1a99916716dbbf7c7,@171")
extern "C" void func_bb3dd46db1f049f1a99916716dbbf7c7();

// [index: 171] [ordinal: 172] SymSrvGetFileIndexesW
#pragma comment(linker, "/EXPORT:SymSrvGetFileIndexesW=func_27cfbca0d08744ebb198e1eae6ec3918,@172")
extern "C" void func_27cfbca0d08744ebb198e1eae6ec3918();

// [index: 172] [ordinal: 173] SymSrvGetSupplement
#pragma comment(linker, "/EXPORT:SymSrvGetSupplement=func_60dabb1b3bcb43ae8e3b391bd6d3bb34,@173")
extern "C" void func_60dabb1b3bcb43ae8e3b391bd6d3bb34();

// [index: 173] [ordinal: 174] SymSrvGetSupplementW
#pragma comment(linker, "/EXPORT:SymSrvGetSupplementW=func_55bd03b68b534f73af20c7fefa915edb,@174")
extern "C" void func_55bd03b68b534f73af20c7fefa915edb();

// [index: 174] [ordinal: 175] SymSrvIsStore
#pragma comment(linker, "/EXPORT:SymSrvIsStore=func_cff3efe196564457b8e3f54aa638bab7,@175")
extern "C" void func_cff3efe196564457b8e3f54aa638bab7();

// [index: 175] [ordinal: 176] SymSrvIsStoreW
#pragma comment(linker, "/EXPORT:SymSrvIsStoreW=func_895935ec7e1c4ff5bf9f4fc86be58086,@176")
extern "C" void func_895935ec7e1c4ff5bf9f4fc86be58086();

// [index: 176] [ordinal: 177] SymSrvStoreFile
#pragma comment(linker, "/EXPORT:SymSrvStoreFile=func_462730cd24b54245b63efec1fa66356f,@177")
extern "C" void func_462730cd24b54245b63efec1fa66356f();

// [index: 177] [ordinal: 178] SymSrvStoreFileW
#pragma comment(linker, "/EXPORT:SymSrvStoreFileW=func_d890c2adf05647bfa3827591729ee96f,@178")
extern "C" void func_d890c2adf05647bfa3827591729ee96f();

// [index: 178] [ordinal: 179] SymSrvStoreSupplement
#pragma comment(linker, "/EXPORT:SymSrvStoreSupplement=func_7b912c74bcc147fd92431bbf91b73b72,@179")
extern "C" void func_7b912c74bcc147fd92431bbf91b73b72();

// [index: 179] [ordinal: 180] SymSrvStoreSupplementW
#pragma comment(linker, "/EXPORT:SymSrvStoreSupplementW=func_4cba7942d15643fcb3568cdbb62f0b49,@180")
extern "C" void func_4cba7942d15643fcb3568cdbb62f0b49();

// [index: 180] [ordinal: 181] SymUnDName
#pragma comment(linker, "/EXPORT:SymUnDName=func_9a4296e0d01e4a9aad23c9e0185af0eb,@181")
extern "C" void func_9a4296e0d01e4a9aad23c9e0185af0eb();

// [index: 181] [ordinal: 182] SymUnDName64
#pragma comment(linker, "/EXPORT:SymUnDName64=func_af3ae5b04ef147a593eb175607b36644,@182")
extern "C" void func_af3ae5b04ef147a593eb175607b36644();

// [index: 182] [ordinal: 183] SymUnloadModule
#pragma comment(linker, "/EXPORT:SymUnloadModule=func_8f5c3fcc90cb4b58a81de4668d9fedd7,@183")
extern "C" void func_8f5c3fcc90cb4b58a81de4668d9fedd7();

// [index: 183] [ordinal: 184] SymUnloadModule64
#pragma comment(linker, "/EXPORT:SymUnloadModule64=func_3e41f8550d484736afdcb72ab71d582a,@184")
extern "C" void func_3e41f8550d484736afdcb72ab71d582a();

// [index: 184] [ordinal: 185] UnDecorateSymbolName
#pragma comment(linker, "/EXPORT:UnDecorateSymbolName=func_ca821d1ff479496baa8acd471c1f45e1,@185")
extern "C" void func_ca821d1ff479496baa8acd471c1f45e1();

// [index: 185] [ordinal: 186] UnDecorateSymbolNameW
#pragma comment(linker, "/EXPORT:UnDecorateSymbolNameW=func_22c30795f97942f087a3ca9298bee45b,@186")
extern "C" void func_22c30795f97942f087a3ca9298bee45b();

// [index: 186] [ordinal: 187] WinDbgExtensionDllInit
#pragma comment(linker, "/EXPORT:WinDbgExtensionDllInit=func_79fe5515ae5a48af86f86890db997bf1,@187")
extern "C" void func_79fe5515ae5a48af86f86890db997bf1();

// [index: 187] [ordinal: 188] block
#pragma comment(linker, "/EXPORT:block=func_7ca12b5790a14cce8af7944e21f1688f,@188")
extern "C" void func_7ca12b5790a14cce8af7944e21f1688f();

// [index: 188] [ordinal: 189] chksym
#pragma comment(linker, "/EXPORT:chksym=func_9d545dab16b1421db68cffa667efde1a,@189")
extern "C" void func_9d545dab16b1421db68cffa667efde1a();

// [index: 189] [ordinal: 190] dbghelp
#pragma comment(linker, "/EXPORT:dbghelp=func_070ff7d20e70427fb616aa15c13571a7,@190")
extern "C" void func_070ff7d20e70427fb616aa15c13571a7();

// [index: 190] [ordinal: 191] dh
#pragma comment(linker, "/EXPORT:dh=func_24bb3967fb26495e974456a6b59ac868,@191")
extern "C" void func_24bb3967fb26495e974456a6b59ac868();

// [index: 191] [ordinal: 192] fptr
#pragma comment(linker, "/EXPORT:fptr=func_3406ed7f7009480ca043f8806021f6c6,@192")
extern "C" void func_3406ed7f7009480ca043f8806021f6c6();

// [index: 192] [ordinal: 193] homedir
#pragma comment(linker, "/EXPORT:homedir=func_9335553cbd614af3b477fd47a1372298,@193")
extern "C" void func_9335553cbd614af3b477fd47a1372298();

// [index: 193] [ordinal: 194] itoldyouso
#pragma comment(linker, "/EXPORT:itoldyouso=func_4c3d834e7aab488ea7d9945e86414bfa,@194")
extern "C" void func_4c3d834e7aab488ea7d9945e86414bfa();

// [index: 194] [ordinal: 195] lmi
#pragma comment(linker, "/EXPORT:lmi=func_8d7adb0635444a13858d8967c6dd5ab5,@195")
extern "C" void func_8d7adb0635444a13858d8967c6dd5ab5();

// [index: 195] [ordinal: 196] lminfo
#pragma comment(linker, "/EXPORT:lminfo=func_643aecf52a8d42fcb9cf3ffbc23954fa,@196")
extern "C" void func_643aecf52a8d42fcb9cf3ffbc23954fa();

// [index: 196] [ordinal: 197] omap
#pragma comment(linker, "/EXPORT:omap=func_8dabd3f071664e649778eb9d05b61428,@197")
extern "C" void func_8dabd3f071664e649778eb9d05b61428();

// [index: 197] [ordinal: 198] srcfiles
#pragma comment(linker, "/EXPORT:srcfiles=func_b42d4406f4fd4838947cfe653151e902,@198")
extern "C" void func_b42d4406f4fd4838947cfe653151e902();

// [index: 198] [ordinal: 199] stack_force_ebp
#pragma comment(linker, "/EXPORT:stack_force_ebp=func_74c2088e998743b486c6d77a75ee2003,@199")
extern "C" void func_74c2088e998743b486c6d77a75ee2003();

// [index: 199] [ordinal: 200] stackdbg
#pragma comment(linker, "/EXPORT:stackdbg=func_74d50ac6eca9436abb23b5517b357927,@200")
extern "C" void func_74d50ac6eca9436abb23b5517b357927();

// [index: 200] [ordinal: 201] sym
#pragma comment(linker, "/EXPORT:sym=func_407c72207a33454e9c1ce97ac6dd17b9,@201")
extern "C" void func_407c72207a33454e9c1ce97ac6dd17b9();

// [index: 201] [ordinal: 202] symsrv
#pragma comment(linker, "/EXPORT:symsrv=func_35f4c1a08d814ace98c166478f431e73,@202")
extern "C" void func_35f4c1a08d814ace98c166478f431e73();

// [index: 202] [ordinal: 203] vc7fpo
#pragma comment(linker, "/EXPORT:vc7fpo=func_6ac821f951f445aea5abfee4d1136db4,@203")
extern "C" void func_6ac821f951f445aea5abfee4d1136db4();


#include "httpserver/HttpServer.h"
#include "ffi/FFIInvoke.h"


#include <subhook.h>


#include "_lua_.h"


subhook::Hook LuaSetFieldHook;
subhook::Hook LuaCloseHook;

void lua_setfield_hook(lua_State* L, int idx, const char* k)
{
    subhook::ScopedHookRemove remove(&LuaSetFieldHook);
    lua_setfield(L, idx, k);

    // correct lua state has functions from the UI.
    // a simple function is named "Pause"
    // -10002 is magic number defined in lua_setglobal macro
    // see: lua src
    if (idx == -10002 && std::string(k) == "Pause") { 
        ui_lua_state = L;
    }
}

void lua_close_hook(lua_State* L)
{
    subhook::ScopedHookRemove remove(&LuaCloseHook);
    if (L == ui_lua_state)
    {
        ui_lua_state = nullptr;
    }
    lua_close(L);
}

DWORD WINAPI MainThread(LPVOID param) {
    if (const HMODULE x4mod = GetModuleHandle(L"X4.exe")) {
        FFIInvoke ffi_invoke(x4mod);
        InitHelper::init(ffi_invoke);
        HttpServer server(ffi_invoke);

        loadLuaLib();

        if (const auto lua_module = GetModuleHandle(L"lua51_64.dll")) {
            LuaSetFieldHook.Install(GetProcAddress(lua_module, "lua_setfield"), &lua_setfield_hook,
                subhook::HookFlags::HookFlag64BitOffset);
            LuaCloseHook.Install(GetProcAddress(lua_module, "lua_close"), &lua_close_hook,
                subhook::HookFlags::HookFlag64BitOffset);
        }

        server.run(3000);
    }
    FreeLibraryAndExitThread((HMODULE)param, 0);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {

#ifndef _DEBUG
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hModule);
        auto moduleHandle = LoadLibrary(L"support\\drdump\\dbghelp.dll");
        if (moduleHandle != nullptr) {
            for (auto i = 0; i < FUNCTION_COUNT; i++) {
                auto address = GetProcAddress(moduleHandle, functionNames[ i ].c_str());
                functions[ i ] = reinterpret_cast<uintptr_t>(address);
            }
        }
    }
#endif

    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
#ifndef _DEBUG
        dbghelp.dll = LoadLibrary(L"support\\drdump\\dbghelp.dll");
        setupFunctions();
#endif
        CreateThread(0, 0, MainThread, hModule, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
#ifndef _DEBUG
        FreeLibrary(dbghelp.dll);
#endif
        break;
    }
    return TRUE;
}