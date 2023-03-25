/*
Copyright 2021-2023 Peter Repukat - FlatspotSoftware

Use of this source code is governed by the MIT
license that can be found in the LICENSE file or at
https://opensource.org/licenses/MIT.
*/

#pragma once

#include "../httpserver/HttpServer.h"
#include "../ffi/FFIInvoke.h"

#include "../_lua_.h"
#include "../lua_scripts/dump_lua.h"



inline void RegisterCommonFunctions(INIT_PARAMS()) {
    HttpServer::AddEndpoint(SIMPLE_GET_HANDLER(GetGameStartName));
    HttpServer::AddEndpoint(SIMPLE_GET_HANDLER(GetCurrentGameTime));
    HttpServer::AddEndpoint(SIMPLE_GET_HANDLER(GetCurrentUTCDataTime));

    HttpServer::AddEndpoint({"/Pause", HttpServer::Method::POST,
        [ & ](const httplib::Request& req, httplib::Response& res) {
            if (ui_lua_state != nullptr) {
                const auto result = executeLua("Pause()", false);
                SET_CONTENT(({true}));
                return;
            }
            SET_CONTENT(({false}));
        },
        {"[boolean]"}});

    HttpServer::AddEndpoint({"/Unpause", HttpServer::Method::POST,
        [ & ](const httplib::Request& req, httplib::Response& res) {
            if (ui_lua_state != nullptr) {
                const auto result = executeLua("Unpause()", false);
                SET_CONTENT(({true}));
                return;
            }
            SET_CONTENT(({false}));
        },
        {"[boolean]"}});


    HttpServer::AddEndpoint({"/DumpLua", HttpServer::Method::GET,
        [ & ](const httplib::Request& req, httplib::Response& res) {
            if (ui_lua_state != nullptr) {

                const auto result = executeLua(dump_lua, true, false);

                res.set_content(result, "application/json");
                return;
            }
            SET_CONTENT(({false}));
        },
        "JSON", "experimental; don't rely on it"});

#ifdef _DEBUG
    HttpServer::AddEndpoint({"/ExecuteLuaScript", HttpServer::Method::POST,
        [ & ](const httplib::Request& req, httplib::Response& res) {
            if (ui_lua_state != nullptr) {

                const auto result = executeLua(req.body, false, false);

                res.set_content(result, "application/json");
                return;
            }
            SET_CONTENT(({false}));
        },
        "", "executes arbitrary lua. used only for debugging"});
#endif
}
