#pragma once
#include <windows.h>
#include <unordered_map>
#include <array>
#include <cstddef>

#include <nlohmann/json.hpp>
#include "ffirip.h"

using json = nlohmann::json;

/**
 * Loads and invokes FFI functions from the game
 * Always returns dumpable json
 *
 * proooobably needs some refactoring.
 */
class FFIInvoke
{
public:
	explicit FFIInvoke(const HMODULE x4_module);

	/**
	 * Returns player name
	 */
	json GetPlayerName();
	/**
	 * Returns universeId (componentId) and uiConnectionName from currently targeted object
	 */
	json GetSofttarget();
	/**
	 * Returns details of universeObject
	 *
	 * @param componentId universeId
	 * @param connectionName uiConnectionName (seemingly any gibberish)
	 */
	json GetComponentDetails(const X4FFI::UniverseID componentid, const char* const connectionname);
	
private:
	HMODULE x4_module_;
	std::unordered_map<LPCSTR, FARPROC> funcs_; // map holding funcs by name
	/**
	 * Actually loads a given FFI-function by name
	 */
	void loadFunction(LPCSTR name);

	template<typename Func, typename ...Args>
	decltype(auto) invokeFn(const char* funcname, Args... args)
	{
		if (funcs_.count(funcname) == 0)
		{
			loadFunction(funcname);
		}
		return reinterpret_cast<Func>(funcs_[funcname])(args...);
	};
	
};