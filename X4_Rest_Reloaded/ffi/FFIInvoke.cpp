#include "FFIInvoke.h"
#ifdef _WIN32
FFIInvoke::FFIInvoke(const HMODULE x4_module) { x4_module_ = x4_module; }
#else
#include <dlfcn.h>
#endif

void FFIInvoke::loadFunction(const char* name)
{
#ifdef _WIN32
    const auto addr = GetProcAddress(x4_module_, name);
#else
    const auto addr = dlsym(RTLD_DEFAULT, name);
#endif
    if (!addr) {
#ifdef _WIN32
        throw std::exception(std::string(std::string(name) + " not found").c_str());
#else
        throw std::exception(); // exception with message ctor is M$ extension
#endif
    }
    funcs_[name] = addr;
}
