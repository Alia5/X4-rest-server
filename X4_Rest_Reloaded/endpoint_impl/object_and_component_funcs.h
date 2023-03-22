#pragma once

#include "../httpserver/HttpServer.h"
#include "../ffi/FFIInvoke.h"


inline void RegisterObjectAndComponentFunctions(INIT_PARAMS()) {
    HttpServer::AddEndpoint(UINT64_PARAM_GET_HANDLER(GetObjectIDCode, "objectId"));

    HttpServer::AddEndpoint(UINT64_PARAM_GET_HANDLER(GetComponentClass, "componentId"));
    HttpServer::AddEndpoint(UINT64_PARAM_GET_HANDLER(GetComponentName, "componentId"));
}