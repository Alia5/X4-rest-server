#pragma once
#include <windows.h>
#include <unordered_map>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class FFIInvoke
{
public:
	explicit FFIInvoke(const HMODULE x4_module);
	json GetPlayerName();
	json GetSofttarget();
private:
	HMODULE x4_module_;
	std::unordered_map<LPCSTR, FARPROC> funcs_;
	void loadFunction(LPCSTR name);
};

