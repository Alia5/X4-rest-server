#pragma once
#ifdef _WIN32
#include <windows.h>
#endif
#include <cstdint>
#include <string>
#include <unordered_map>

#include "x4ffi/ffi_funcs.h"

#define Q(x) #x
#define QUOTE(x) Q(x)

#define INIT_PARAMS(...) FFIInvoke &ffi_invoke, ##__VA_ARGS__

#define invoke(FuncName, ...) ffi_invoke.invokeFn<X4FFI::FuncName>(QUOTE(FuncName), ##__VA_ARGS__)

/**
 * Loads and invokes FFI functions from the game
 */
class FFIInvoke {
  public:
#ifdef _WIN32
    explicit FFIInvoke(const HMODULE x4_module);
#else
    FFIInvoke() = default;
#endif

    template <typename Func, typename... Args> decltype(auto) invokeFn(const char* funcname, Args... args)
    {
        if (!funcs_.contains(funcname)) {
            loadFunction(funcname);
        }
        return reinterpret_cast<Func>(funcs_[funcname])(args...);
    };

  private:
#ifdef _WIN32
    HMODULE x4_module_;
#endif
    std::unordered_map<std::string, void*> funcs_; // map holding funcs by name
    /**
     * Actually loads a given FFI-function by name
     */
    void loadFunction(const char* name);
};