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

#include "../lua_scripts/ComponentDataHelper.h"


inline void RegisterObjectAndComponentFunctions(INIT_PARAMS()) {
    HttpServer::AddEndpoint(UINT64_PARAM_GET_HANDLER(GetObjectIDCode, "objectId"));
    HttpServer::AddEndpoint(UINT64_PARAM_GET_HANDLER(GetObjectPositionInSector, "objectId"));

    HttpServer::AddEndpoint(UINT64_PARAM_GET_HANDLER(GetComponentClass, "componentId"));
    HttpServer::AddEndpoint(UINT64_PARAM_GET_HANDLER(GetComponentName, "componentId"));

    HttpServer::AddEndpoint(UINT64_PARAM_GET_HANDLER(IsObjectKnown, "componentId"));

    HttpServer::AddEndpoint({"/IsComponentClass", HttpServer::Method::GET,
        [&](const httplib::Request& req, httplib::Response& res)
        {
            uint64_t componentId;
            try {
                componentId = std::stoull(req.get_param_value("componentId"));
            }
            catch (...) {
                return BadRequest(res, "componentId is invalid");
            }
            if (componentId == 0) {
                return BadRequest(res, "componentId is required");
            }

            std::string component_class;
            try {
                component_class = req.get_param_value("componentClass");
            }
            catch (...) {
                return BadRequest(res, "componentClass is required");
            }
            if (component_class.empty())
            {
                return BadRequest(res, "componentClass is required");
            }

            const auto callResult = invoke(IsComponentClass, componentId, component_class.c_str());
            SET_CONTENT((callResult));

        }
    });

    HttpServer::AddEndpoint({"/GetComponentData", HttpServer::Method::GET,
        [](const httplib::Request& req, httplib::Response& res) {
            uint64_t componentId;
            try {
                componentId = std::stoull(req.get_param_value("componentId"));
            }
            catch (...) {
                return BadRequest(res, "componentId is invalid");
            }
            if (componentId == 0)
            {
                return BadRequest(res, "componentId is required");
            }

            std::string attribs;

            try {
                attribs = req.get_param_value("attribs");
            }
            catch (...) {
                return BadRequest(res, "attribs are required");
            }

            if (attribs.empty()) {
                return BadRequest(res, "attribs are required");
            }

            std::string lua_attribs = "";

            for (auto attr : std::views::split(attribs, ',')) {
                const auto attr_str = std::string(attr.begin(), attr.end());
                if (!is_valid_component_data(attr_str)) {
                    res.status = 401;
                    SET_CONTENT(({{"code", 401}, {"name", "Bad Request"},
                        {"message", "attrib \"" + attr_str + "\" is invalid"}, {"valid_attributes", valid_component_data_attribs}}));
                    return;
                }
                lua_attribs += "\"" + attr_str + "\",";
            }

            lua_attribs.pop_back();

            if (ui_lua_state != nullptr) {
                const auto lua_str =
                    std::string("local querieddata = {GetComponentData(" + std::to_string(componentId) + ",") +
                    lua_attribs +
                    " )}\n" + "return json.encode(querieddata)";
                const auto callResult = executeLua(lua_str, true, true);
                res.set_content(callResult, "application/json");
                return;
            }
            SET_CONTENT(({}));
        },
        "array"});
}