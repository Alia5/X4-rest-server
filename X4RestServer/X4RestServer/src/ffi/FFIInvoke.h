#pragma once
#include <windows.h>
#include <unordered_map>
#include <cstdint>

/**
 * Loads and invokes FFI functions from the game
 */
class FFIInvoke
{
public:
	explicit FFIInvoke(const HMODULE x4_module);


	template<typename Func, typename ...Args>
	decltype(auto) invokeFn(const char* funcname, Args... args)
	{
		if (funcs_.count(funcname) == 0)
		{
			loadFunction(funcname);
		}
		return reinterpret_cast<Func>(funcs_[funcname])(args...);
	};

	
private:
	HMODULE x4_module_;
	std::unordered_map<LPCSTR, FARPROC> funcs_; // map holding funcs by name
	/**
	 * Actually loads a given FFI-function by name
	 */
	void loadFunction(LPCSTR name);
	
};