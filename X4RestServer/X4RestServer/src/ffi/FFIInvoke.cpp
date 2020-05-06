#include "FFIInvoke.h"
#ifdef _WIN32
FFIInvoke::FFIInvoke(const HMODULE x4_module)
{
	x4_module_ = x4_module;
}

void FFIInvoke::loadFunction(LPCSTR name)
{
	const auto addr = GetProcAddress(x4_module_, name);
	if (!addr) {
		throw std::exception(std::string(std::string(name) + " not found").c_str());
	}
	funcs_[name] = addr;
}
#else
#include <dlfcn.h>

void FFIInvoke::loadFunction(const char* name)
{
	const auto addr = dlsym(RTLD_DEFAULT, name);

	if (!addr) {
		throw std::exception(); // exception with message ctor is M$ extension
	}
	funcs_[name] = addr;
}
#endif
