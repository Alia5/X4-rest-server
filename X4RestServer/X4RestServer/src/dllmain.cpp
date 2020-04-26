#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "httpserver/HttpServer.h"
#include "ffi/FFIInvoke.h"


DWORD WINAPI MainThread(LPVOID param)
{
	HMODULE x4mod = GetModuleHandle(L"X4.exe");
	if (x4mod) {
		FFIInvoke ffi_invoke(x4mod);
		HttpServer server(ffi_invoke);
		server.run(3000);
	}
	FreeLibraryAndExitThread((HMODULE)param, 0);
	return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		CreateThread(0, 0, MainThread, hModule, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}