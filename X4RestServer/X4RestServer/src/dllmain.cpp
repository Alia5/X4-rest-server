#include <windows.h>

typedef const char* (__cdecl* _GetPlayerName)(void);
_GetPlayerName GetPlayerName;

DWORD WINAPI MainThread(LPVOID param)
{
	uintptr_t modBase = (uintptr_t)GetModuleHandle(NULL);


	HMODULE x4mod = GetModuleHandle(L"X4.exe");
	
	GetPlayerName = (_GetPlayerName)GetProcAddress(x4mod, "GetPlayerName");

	while (!GetAsyncKeyState(VK_END))
	{
		if (GetAsyncKeyState(VK_NUMPAD2) & 1)
		{
			const char* playername = GetPlayerName();
			MessageBoxA(NULL, playername, playername, MB_OK);
		}
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