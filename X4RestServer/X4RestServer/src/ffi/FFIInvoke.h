#pragma once
#include <windows.h>
#include <unordered_map>
#include <nlohmann/json.hpp>
#include "ffi_typedef.h"

using json = nlohmann::json;

class FFIInvoke
{
public:
	explicit FFIInvoke(const HMODULE x4_module);
	json GetPlayerName();
	json GetSofttarget();
	json GetComponentDetails(const X4FFI::UniverseID componentid, const char* const connectionname);
private:
	HMODULE x4_module_;
	std::unordered_map<LPCSTR, FARPROC> funcs_;
	void loadFunction(LPCSTR name);
};

