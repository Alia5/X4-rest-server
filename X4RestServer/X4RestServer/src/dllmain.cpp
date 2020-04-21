#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <httplib.h>
#include <string>
#include <thread>

typedef const char* (__cdecl* _GetPlayerName)(void);
_GetPlayerName GetPlayerName;

DWORD WINAPI MainThread(LPVOID param)
{
	uintptr_t modBase = (uintptr_t)GetModuleHandle(NULL);


	HMODULE x4mod = GetModuleHandle(L"X4.exe");
	if (x4mod) {
		_GetPlayerName GetPlayerName = (_GetPlayerName)GetProcAddress(x4mod, "GetPlayerName");

		httplib::Server server;

		server.Get("/player-name", [GetPlayerName](const httplib::Request& req, httplib::Response& res) {
			res.set_content(
				"{\n    \"player_name\": \"" + std::string(GetPlayerName()) + "\"\n}", "text/json");
			});
		server.Get("/stop", [&](const httplib::Request& req, httplib::Response& res) {
			std::thread([&]() {
				server.stop();
			}).detach();
		});
		server.listen("0.0.0.0", 3000);
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