#pragma once
#include "endpoint_impl/common_funcs.h"
#include "endpoint_impl/logbook_funcs.h"
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
    }
};

;
