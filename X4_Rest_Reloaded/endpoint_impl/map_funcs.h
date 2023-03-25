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

#include <subhook.h>

static std::vector<X4FFI::UniverseID> holomap_ids;

subhook::Hook AddHoloMapHook;
subhook::Hook RemoveHoloMapHook;

X4FFI::AddHoloMap add_holo_map;
X4FFI::RemoveHoloMap remove_holo_map;

X4FFI::UniverseID add_holo_map_hook(const char* texturename, float x0, float x1, float y0,
    float y1, float aspectx, float aspecty) {
    subhook::ScopedHookRemove remove(&AddHoloMapHook);
    const auto retval = add_holo_map(texturename, x0, x1, y0, y1, aspectx, aspecty);
    holomap_ids.push_back(retval);
    return retval;
}




void remove_holo_map_hook() {
    subhook::ScopedHookRemove remove(&RemoveHoloMapHook);
    remove_holo_map();
    if (!holomap_ids.empty()) {
        holomap_ids.pop_back();
    }
}

inline void RegisterMapFunctions(INIT_PARAMS()) {
    if (const HMODULE x4mod = GetModuleHandle(L"X4.exe")) {
        add_holo_map = (X4FFI::AddHoloMap)GetProcAddress(x4mod, "AddHoloMap");
        remove_holo_map = (X4FFI::RemoveHoloMap)GetProcAddress(x4mod, "RemoveHoloMap");

        //AddHoloMapHook.Install(GetProcAddress(x4mod, "AddHoloMap"), &add_holo_map,
        //    subhook::HookFlags::HookFlagTrampoline | subhook::HookFlag64BitOffset);
        //RemoveHoloMapHook.Install(GetProcAddress(x4mod, "RemoveHoloMap"), &remove_holo_map,
        //    subhook::HookFlags::HookFlagTrampoline | subhook::HookFlags::HookFlag64BitOffset);
    }

    HttpServer::AddEndpoint({"/GetHoloMapIds", HttpServer::Method::GET,
        [](const httplib::Request& req, httplib::Response& res) {
            SET_CONTENT((holomap_ids));
        },
        "experimental; don't use!"
        "experimental; don't use!"
    });
}