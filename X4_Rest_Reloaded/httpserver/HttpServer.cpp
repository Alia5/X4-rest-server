#include "HttpServer.h"
//#include "../__generated__/gen_ffi_json.h"
//#include "../__generated__/gen_http_funs.h"
//#include "../ffi/FFIInvoke.h"
//#include "../ffi/ffi_json.h"

//#define SET_CONTENT(Call) res.set_content(Call.dump(), "text/json")
//
//#define PARAMS(...) ffi_invoke_, ##__VA_ARGS__
//
//HttpServer::HttpServer(FFIInvoke& ffi_invoke) : ffi_invoke_(ffi_invoke) {}
//
//void HttpServer::run(int port)
//{
//
//    initGenFuns(server, ffi_invoke_);
//
//    // --
//#ifdef _DEBUG
//    server.Get("/stop", [&](const httplib::Request& req, httplib::Response& res) {
//        std::thread([&]() { server.stop(); }).detach();
//        res.set_content(json{{"ejected", true}}.dump(), "text/json");
//    });
//#endif
//    // somehow got bad request every other request without this o.O
//    std::thread([&]() { server.listen("0.0.0.0", port); }).join();
//}