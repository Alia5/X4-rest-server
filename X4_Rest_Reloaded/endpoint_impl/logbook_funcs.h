/*
Copyright 2021-2023 Peter Repukat - FlatspotSoftware

Use of this source code is governed by the MIT
license that can be found in the LICENSE file or at
https://opensource.org/licenses/MIT.
*/

#pragma once

#include "../httpserver/HttpServer.h"
#include "../ffi/FFIInvoke.h"

#include "../ffi/ffi_enum_helper.h"

#include "../_lua_.h"

inline void RegisterLogbookFunctions(INIT_PARAMS()) {


    HttpServer::AddEndpoint({"/GetNumLogbook", HttpServer::Method::GET,
        [ & ](const httplib::Request& req, httplib::Response& res) {
            const auto category = req.get_param_value("category");

            if (category.empty()) {
                return BadRequest(res, "category is required");
            }

            if (!LogbookCategory::is_valid(category)) {
                return BadRequest(res, "category is invalid; Valid categories: 'all', 'general', 'missions', 'news', "
                                       "'alerts', 'upkeep', 'tips'");
            }

            if (ui_lua_state != nullptr) {
                const auto result = executeLua("return GetNumLogbook(\"" + category + "\")", false, false);
                res.set_content(result, "application/json");
                return;
            }
            SET_CONTENT((nullptr));
        },
        "number"});


    HttpServer::AddEndpoint({"/GetLogbook", HttpServer::Method::GET,
        [ & ](const httplib::Request& req, httplib::Response& res) {
            const auto category = req.get_param_value("category");

            if (category.empty()) {
                return BadRequest(res, "category is required");
            }

            if (!LogbookCategory::is_valid(category)) {
                return BadRequest(res, "category is invalid; Valid categories: 'all', 'general', 'missions', 'news', "
                                       "'alerts', 'upkeep', 'tips'");
            }

            size_t page = 1;

            try {
                page = std::stoul(req.get_param_value("page"));
            }
            catch (...) {
                // ignore
            }
            if (page <= 0) {
                page = 1;
            }

            if (ui_lua_state != nullptr) {
                // "inspiration" from gamefiles /ui/addons/ego_detailmonitor/menu_playerinfo.lua
                std::string lua = R"(
                    local numEntries = GetNumLogbook( ")" +
                                  category + R"(" )
                    local logbook = {}
                    local startIndex = 1
                    local numQuery = math.min(100, numEntries)
                    local curPage = )" +
                                  std::to_string(page) + R"(
                    if numEntries <= 100 then
                        curPage = 1
                    else
                        startIndex = numEntries - 100 * curPage + 1
                        if startIndex < 1 then
                            numQuery = 100 + startIndex - 1
                            startIndex = 1
                        end
                    end
                    logbook = GetLogbook(startIndex, numQuery, ")" +
                                  category + R"(")
                    return json.encode(logbook)
                )";

                const auto result = executeLua(lua, true, true);
                res.set_content(result, "application/json");
                return;
            }
            SET_CONTENT(({}));
        },
        "number"});
}