#include <string>
#include "FFIInvoke.h"

#define Q(x) #x
#define QUOTE(x) Q(x)

#define invoke(FuncName, ...) \
   invokeFn<X4FFI::FuncName>(QUOTE(FuncName), __VA_ARGS__);

FFIInvoke::FFIInvoke(const HMODULE x4_module) : x4_module_(x4_module) {}

json FFIInvoke::GetPlayerName()
{
	const auto res = invoke(GetPlayerName);
		return json
        {
			{"player_name", res}
		};
}

json FFIInvoke::GetSofttarget()
{
	const X4FFI::SofttargetDetails softTarget = invoke(GetSofttarget);
	return json
	{
		{"universeId", softTarget.softtargetID},
		{"softtargetConnectionName", softTarget.softtargetConnectionName},
	};
}

json FFIInvoke::GetComponentDetails(const X4FFI::UniverseID componentid, const char* const connectionname)
{
	const X4FFI::ComponentDetails compDetails = invoke(GetComponentDetails, componentid, connectionname);
	return json
	{
		{"name", compDetails.name},
		{"hull", compDetails.hull},
		{"shield", compDetails.shield},
		{"speed", compDetails.speed},
		{"hasShield", compDetails.hasShield},
	};
}


void FFIInvoke::loadFunction(LPCSTR name)
{
	const auto addr = GetProcAddress(x4_module_, name);
	if (!addr) {
		throw std::exception(std::string(std::string(name) + "not found").c_str());
	}
	funcs_[name] = addr;
}