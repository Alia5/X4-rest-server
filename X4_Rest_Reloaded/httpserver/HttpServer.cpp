/*
Copyright 2021-2023 Peter Repukat - FlatspotSoftware

Use of this source code is governed by the MIT
license that can be found in the LICENSE file or at
https://opensource.org/licenses/MIT.
*/

#include "HttpServer.h"
HttpServer::HttpServer(FFIInvoke& ffi_invoke) : ffi_invoke_(ffi_invoke) {}

std::string HttpServer::ToString(Method m) {
    switch (m) {
    case POST:
        return "POST";
    case PATCH:
        return "PATCH";
    case PUT:
        return "PUT";
    default:
        return "GET";
    }
}

void HttpServer::AddEndpoint(const Endpoint&& e) { endpoints_.push_back(e); }

void HttpServer::run(int port) {

    server_.set_default_headers(httplib::Headers{{"Access-Control-Allow-Origin", "*"}});

    server_.Get("/", [ this ](const httplib::Request& req, httplib::Response& res) {
        auto content_json = nlohmann::json{{"endpoints", nlohmann::json::array()}};

        for (const auto& e : endpoints_) {
            content_json[ "endpoints" ].push_back(nlohmann::json{
                {"path", e.path},
                {"method", ToString(e.method)},
                {"response", e.response_hint},
                {"payload", e.payload_hint},
            });
        }

        content_json[ "endpoints" ].push_back(
            nlohmann::json{{"path", "/stop"}, {"method", "POST"}});

        res.set_content(content_json.dump(4), "application/json");
        res.status = 200;
    });

    for (const auto& e : endpoints_) {
        const auto fn =
            ([ this, &e ]() -> httplib::Server& (httplib::Server::*)(const std::string&,
                                httplib::Server::Handler) {
                switch (e.method) {
                case POST:
                    return &httplib::Server::Post;
                case PUT:
                    return &httplib::Server::Put;
                case PATCH:
                    return &httplib::Server::Patch;
                default:
                    return &httplib::Server::Get;
                }
            })();

        (server_.*fn)(
            e.path, [ this, &e ](const httplib::Request& req, httplib::Response& res) {
                res.status = 0;
                res.content_length_ = 0;
                try {
                    e.handler(req, res);
                }
                catch (std::exception& err) {
                    // spdlog::error("Exception in http handler: {}", err.what());
                    res.status = res.status == 0 ? 500 : res.status;
                    if (res.content_length_ == 0) {
                        res.set_content(
                            nlohmann::json{
                                {"code", res.status},
                                {"name", "HandlerError"},
                                {"message", err.what()},
                            }
                                .dump(),
                            "application/json");
                    }
                }
                catch (...) {
                    res.status = 500;
                    res.set_content(
                        nlohmann::json{
                            {"code", res.status},
                            {"name", "Internal Server Error"},
                            {"message", "Unknown Error"},
                        }
                            .dump(),
                        "application/json");
                }
                if (res.status == 0) {
                    res.status = e.method == Method::POST ? 201 : 200;
                }
            });
    }

    // --
#ifdef _DEBUG
    server_.Post("/stop", [ & ](const httplib::Request& req, httplib::Response& res) {
        std::thread([ & ]() { server_.stop(); }).detach();
        res.set_content(nlohmann::json{{"ejected", true}}.dump(), "application/json");
    });
#endif
    // somehow got bad request every other request without an extra thread o.O
    // (The server_ already runs in it's own separate thread by default...
    std::thread([ & ]() { server_.listen("0.0.0.0", port); }).join();
}