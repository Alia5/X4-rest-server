/*
Copyright 2021-2023 Peter Repukat - FlatspotSoftware

Use of this source code is governed by the MIT
license that can be found in the LICENSE file or at
https://opensource.org/licenses/MIT.
*/

#pragma once
#include "endpoint_impl/common_funcs.h"
#include "endpoint_impl/logbook_funcs.h"
#include "endpoint_impl/map_or_query_funcs.h"
#include "endpoint_impl/message_funcs.h"
#include "endpoint_impl/object_and_component_funcs.h"
#include "endpoint_impl/player_funcs.h"

class FFIInvoke;

class InitHelper {
public:
    static inline void init(FFIInvoke& ffi_invoke) {
        RegisterCommonFunctions(ffi_invoke);
        RegisterPlayerFunctions(ffi_invoke);
        RegisterMessageFunctions(ffi_invoke);
        RegisterLogbookFunctions(ffi_invoke);
        RegisterObjectAndComponentFunctions(ffi_invoke);
        RegisterMapOrQueryFunctions(ffi_invoke);
    }
};

;
