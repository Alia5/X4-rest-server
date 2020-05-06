#pragma once
#ifdef _WIN32
#include <windows.h>
#endif
#include <string>
#include <unordered_map>
#include <cstdint>

/**
 * Loads and invokes FFI functions from the game
 */
class FFIInvoke
{
public:
#ifdef _WIN32
	explicit FFIInvoke(const HMODULE x4_module);
#else
	FFIInvoke() = default;
#endif

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
#ifdef _WIN32
	HMODULE x4_module_;
	std::unordered_map<LPCSTR, FARPROC> funcs_; // map holding funcs by name
	/**
	 * Actually loads a given FFI-function by name
	 */
	void loadFunction(LPCSTR name);
#else
	std::unordered_map<std::string, void*> funcs_; // map holding funcs by name
	/**
	 * Actually loads a given FFI-function by name
	 */
	void loadFunction(const char* name);
#endif
	
};