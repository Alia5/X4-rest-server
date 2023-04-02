#pragma once
#include <subhook.h>

#include "lua_scripts/json.h"

#define LUA_OK 0
#define LUA_YIELD 1
#define LUA_ERRRUN 2
#define LUA_ERRSYNTAX 3
#define LUA_ERRMEM 4
#define LUA_ERRERR 5

std::timed_mutex lua_state_mtx;

typedef void* lua_State;

lua_State* ui_lua_state = nullptr;

using _lua_setfield = void (*)(lua_State* L, int idx, const char* k);
_lua_setfield lua_setfield;

using _lua_getfield = void (*)(lua_State* L, int idx, const char* k);
_lua_getfield lua_getfield;

using _lua_close = void (*)(lua_State* L);
_lua_close lua_close;


using _luaL_loadfilex = int (*)(lua_State* L, const char* filename, const char* mode);
_luaL_loadfilex luaL_loadfilex;

using _lua_pcall = int (*)(lua_State* L, int nargs, int nresults, int errfunc);
_lua_pcall lua_pcall;

using _lua_tolstring = const char* (*)(lua_State* L, int idx, size_t* len);
_lua_tolstring lua_tolstring;

using _lua_settop = void (*)(lua_State* L, int idx);
_lua_settop lua_settop;

using _luaL_loadstring = int (*)(lua_State* L, const char* s);
_luaL_loadstring luaL_loadstring;

using _lua_getmetatable = int (*)(lua_State* L, int idx);
_lua_getmetatable lua_getmetatable;


using _lua_newthread = lua_State* (*)(lua_State* L);
_lua_newthread lua_newthread;

using _lua_gettop = int (*)(lua_State* L);
_lua_gettop lua_gettop;


std::atomic<const char*> toExecuteLuaString{};
std::atomic<const char*> lua_result{};


subhook::Hook LuaSetFieldHook;
subhook::Hook LuaCloseHook;

subhook::Hook LuaGetFieldHook;

void lua_setfield_hook(lua_State* L, int idx, const char* k) {
    // OutputDebugStringA((std::string("lua_setfield_hook: ") + k + "  idx: " +
    // std::to_string(idx) + "\n").c_str());
    subhook::ScopedHookRemove remove(&LuaSetFieldHook);
    lua_setfield(L, idx, k);

    // correct lua state has functions from the UI.
    // UpdateFrame seems to be the last one that's called when loading
    // -10002 is magic number defined in lua_setglobal macro
    // see: lua src
    if (idx == -10002 && std::string(k) == "UpdateFrame") {
        const std::lock_guard<std::timed_mutex> lock(lua_state_mtx);
        // OutputDebugStringA("lua_setfield_hook; found_lua_state\n");
        ui_lua_state = L;
    }
}

void lua_close_hook(lua_State* L) {
    const std::lock_guard<std::timed_mutex> lock(lua_state_mtx);
    if (L == ui_lua_state) {
        // OutputDebugStringA("Lua_close_hook; ui_lua_state_closed\n");
        ui_lua_state = nullptr;
    }
    subhook::ScopedHookRemove remove(&LuaCloseHook);
    lua_close(L);
}

void lua_getfield_hook(lua_State* L, int idx, const char* k) {
    subhook::ScopedHookRemove remove(&LuaGetFieldHook);
    lua_getfield(L, idx, k);
    // "onUpdate" is called every frame; this makes sure we're in the correct game-thread
    if (L == ui_lua_state && std::string(k) == "onUpdate") {
        // OutputDebugStringA(
        //     (std::string("lua_getfield_hook: ") + k + "  idx: " + std::to_string(idx) + "\n")
        //         .c_str());

        const auto lua_str = toExecuteLuaString.load();
        if (lua_str != nullptr) {
            const auto top = lua_gettop(L);
            if (luaL_loadstring(L, lua_str) == LUA_OK) {
                // OutputDebugStringA("Calling lua_string from http: calling lua\n");
                if (lua_pcall(L, 0, -1, 0) == LUA_OK) {
                    const char* result = lua_tolstring(L, -1, nullptr);

                    if (result == nullptr) {
                        // OutputDebugStringA("Calling lua_string from http: storing
                        // res 1\n");
                        lua_result.store("true");
                    }
                    else {
                        // OutputDebugStringA("Calling lua_string from http: storing
                        // res 2\n");
                        lua_result.store(result);
                    }
                }
                else {
                    // OutputDebugStringA("Calling lua_string from http: storing res
                    // 3\n");
                    lua_result.store("error executing lua");
                }
                auto newTop = lua_gettop(L);
                while (newTop != top) {
                    lua_settop(L, -(1) - 1);
                    newTop = lua_gettop(L);
                }
            }
            else {
                // OutputDebugStringA("Calling lua_string from http: storing res
                // 4\n");
                lua_result.store("error loading lua");
            }
            // OutputDebugStringA("Calling lua_string from http: resetting
            // lua_string\n");
            toExecuteLuaString.store(nullptr);
        }
    }
}

inline void loadLuaLib() {
    if (const auto lua_module = GetModuleHandle(L"lua51_64.dll")) {
        lua_setfield = (_lua_setfield)(GetProcAddress(lua_module, "lua_setfield"));
        lua_getfield = (_lua_getfield)(GetProcAddress(lua_module, "lua_getfield"));
        lua_close = (_lua_close)(GetProcAddress(lua_module, "lua_close"));

        luaL_loadfilex = (_luaL_loadfilex)GetProcAddress(lua_module, "luaL_loadfilex");
        lua_pcall = (_lua_pcall)GetProcAddress(lua_module, "lua_pcall");
        lua_tolstring = (_lua_tolstring)GetProcAddress(lua_module, "lua_tolstring");
        lua_settop = (_lua_settop)GetProcAddress(lua_module, "lua_settop");
        luaL_loadstring = (_luaL_loadstring)GetProcAddress(lua_module, "luaL_loadstring");

        lua_getmetatable = (_lua_getmetatable)GetProcAddress(lua_module, "lua_getmetatable");

        lua_newthread = (_lua_newthread)GetProcAddress(lua_module, "lua_newthread");

        lua_gettop = (_lua_gettop)GetProcAddress(lua_module, "lua_gettop");

        LuaSetFieldHook.Install(GetProcAddress(lua_module, "lua_setfield"), &lua_setfield_hook,
            subhook::HookFlags::HookFlag64BitOffset);
        LuaCloseHook.Install(GetProcAddress(lua_module, "lua_close"), &lua_close_hook,
            subhook::HookFlags::HookFlag64BitOffset);

        LuaGetFieldHook.Install(GetProcAddress(lua_module, "lua_getfield"), &lua_getfield_hook,
            subhook::HookFlags::HookFlag64BitOffset);
    }
}

inline std::string executeLua(
    const std::string& lua_code, bool include_json = true, bool encode_userdata = false) {

    std::stringstream threadIdStrStr;
    threadIdStrStr << std::this_thread::get_id();

    const auto start = std::chrono::high_resolution_clock::now();
    // OutputDebugStringA(
    (std::string("queuing lua execution: locking lua_state_mtx; threadId: ") +
        threadIdStrStr.str() + "\n")
        .c_str();
    if (!lua_state_mtx.try_lock_for(std::chrono::seconds(3))) {
        throw std::exception("Error: Timeout acquiring lua execution lock");
    }
    const std::lock_guard<std::timed_mutex> lock(lua_state_mtx, std::adopt_lock);
    if (ui_lua_state != nullptr) {
        // OutputDebugStringA("queuing lua execution: resetting lua result\n");
        lua_result.store(nullptr);
        std::string lua_str =
            include_json ? (GetJsonLua(encode_userdata) + "\n" + lua_code) : lua_code;
        // OutputDebugStringA("queuing lua execution: storing lua string\n");
        toExecuteLuaString.store(lua_str.c_str());
        // OutputDebugStringA("queuing lua execution: loading lua string\n");
        auto res = lua_result.load();
        while (res == nullptr) {
            Sleep(10);
            if (std::chrono::duration_cast<std::chrono::milliseconds>(
                    std::chrono::high_resolution_clock::now() - start)
                    .count() > 3000) {
                throw std::exception("Lua error: Timeout executing lua");
            }
            // // OutputDebugStringA("queuing lua execution: loading lua string in loop\n");
            res = lua_result.load();
        }
        // OutputDebugStringA("queuing lua execution: returning\n");
        return res;
    }
    throw std::exception("Lua error: Lua_State not loaded");
}