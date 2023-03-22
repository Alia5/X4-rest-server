#pragma once
#include "lua_scripts/json.h"

typedef void* lua_State;

lua_State* ui_lua_state = nullptr;

using _lua_setfield = void (*)(lua_State* L, int idx, const char* k);
_lua_setfield lua_setfield;

using _lua_close = void (*)(lua_State* L);
_lua_close lua_close;


using _luaL_loadfilex = int (*)(lua_State* L, const char* filename, const char* mode);
_luaL_loadfilex luaL_loadfilex;

using _lua_pcall = int (*)(lua_State* L, int nargs, int nresults, int errfunc);
_lua_pcall lua_pcall;

using _lua_tolstring = const char* (*)(lua_State*L,int idx,size_t*len);
_lua_tolstring lua_tolstring;

using _lua_settop = void (*)(lua_State*L,int idx);
_lua_settop lua_settop;

using _luaL_loadstring = int (*)(lua_State* L, const char* s);
_luaL_loadstring luaL_loadstring;

inline void loadLuaLib()
{
    if (const auto lua_module = GetModuleHandle(L"lua51_64.dll")) {
        lua_setfield = (_lua_setfield)(GetProcAddress(lua_module, "lua_setfield"));
        lua_close = (_lua_close)(GetProcAddress(lua_module, "lua_close"));

        luaL_loadfilex = (_luaL_loadfilex)GetProcAddress(lua_module, "luaL_loadfilex");
        lua_pcall = (_lua_pcall)GetProcAddress(lua_module, "lua_pcall");
        lua_tolstring = (_lua_tolstring)GetProcAddress(lua_module, "lua_tolstring");
        lua_settop = (_lua_settop)GetProcAddress(lua_module, "lua_settop");
        luaL_loadstring = (_luaL_loadstring)GetProcAddress(lua_module, "luaL_loadstring");
    }
}

inline std::string executeLua(const std::string& lua_code, bool include_json = true, bool encode_userdata = false)
{
    if (ui_lua_state != nullptr)
    {
        const auto L = ui_lua_state;
        std::string lua_str = include_json ? (
            GetJsonLua(encode_userdata) + "\n"
            + lua_code) 
            : lua_code;
        luaL_loadstring(L, lua_str.c_str()) || lua_pcall(L, 0, -1, 0);

        const char* result = lua_tolstring(L, -1, nullptr);
        lua_settop(L, 0); // clear stack

        if (result == nullptr) {
            return "true";
        }
        return result;
    }
    return "false";
}