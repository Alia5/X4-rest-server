#include <string>
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
		throw std::exception(std::string(std::string(name) + "not found").c_str());
	}
	funcs_[name] = addr;
}
#endif
