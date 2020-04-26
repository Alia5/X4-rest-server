#pragma once

#include <nlohmann/json.hpp>
#include "../ffi/ffirip/ffirip.h"
#include "../ffi/FFIInvoke.h"

using json = nlohmann::json;

#define Q(x) #x
#define QUOTE(x) Q(x)

#define invoke(FuncName, ...) \
  ffi_invoke.invokeFn<X4FFI::FuncName>(QUOTE(FuncName), __VA_ARGS__);

#define PARAMS(...) \
	FFIInvoke& ffi_invoke, __VA_ARGS__

// ---

namespace GEN
{
	using namespace X4FFI;

	/**
	 * Returns player name
	 */
	json GetPlayerName(PARAMS())
	{
		const auto res = invoke(GetPlayerName);
		return json
		{
			{"player_name", res}
		};
	}
	/**
	 * Returns universeId (componentId) and uiConnectionName from currently targeted object
	 */
	json GetSofttarget(PARAMS())
	{
		const SofttargetDetails softTarget = invoke(GetSofttarget);
		return json
		{
			{"universeId", softTarget.softtargetID},
			{"softtargetConnectionName", softTarget.softtargetConnectionName},
		};
	}
	/**
	 * Returns details of universeObject
	 *
	 * @param componentId universeId
	 * @param connectionName uiConnectionName (seemingly any gibberish)
	 */
	json GetComponentDetails(PARAMS(const UniverseID componentid, const char* const connectionname))
	{
		const ComponentDetails compDetails = invoke(GetComponentDetails, componentid, connectionname);
		return json
		{
			{"name", compDetails.name},
			{"hull", compDetails.hull},
			{"shield", compDetails.shield},
			{"speed", compDetails.speed},
			{"hasShield", compDetails.hasShield},
		};
	}
}