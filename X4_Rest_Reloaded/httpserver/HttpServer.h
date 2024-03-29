/*
Copyright 2021-2023 Peter Repukat - FlatspotSoftware

Use of this source code is governed by the MIT
license that can be found in the LICENSE file or at
https://opensource.org/licenses/MIT.
*/

#pragma once
#include <httplib.h>
#include <nlohmann/json.hpp>
#include <string>

#define SET_CONTENT(content) res.set_content(nlohmann::json content.dump(), "application/json")

#define HAN_FN [ & ](const httplib::Request& req, httplib::Response& res)

#define SIMPLE_GET_HANDLER(FuncName)                                                           \
    {                                                                                          \
        std::string("/") + QUOTE(FuncName), HttpServer::Method::GET, HAN_FN {                  \
            const auto callResult = invoke(FuncName);                                          \
            SET_CONTENT((callResult));                                                         \
        }                                                                                      \
    }

#define INT_PARAM_GET_HANDLER(FuncName, paramName)                                             \
    {                                                                                          \
        std::string("/") + QUOTE(FuncName), HttpServer::Method::GET, HAN_FN {                  \
            try {                                                                              \
                const auto param = std::stoi(req.get_param_value(paramName));                  \
                const auto callResult = invoke(FuncName, param);                               \
                SET_CONTENT((callResult));                                                     \
            }                                                                                  \
            catch (...) {                                                                      \
                return BadRequest(res, std::string(paramName) + " is invalid");                \
            }                                                                                  \
        }                                                                                      \
    }

#define UINT64_PARAM_GET_HANDLER(FuncName, paramName)                                          \
    {                                                                                          \
        std::string("/") + QUOTE(FuncName), HttpServer::Method::GET, HAN_FN {                  \
            try {                                                                              \
                const uint64_t param = std::stoull(req.get_param_value(paramName));            \
                const auto callResult = invoke(FuncName, param);                               \
                SET_CONTENT((callResult));                                                     \
            }                                                                                  \
            catch (...) {                                                                      \
                return BadRequest(res, std::string(paramName) + " is invalid");                \
            }                                                                                  \
        }                                                                                      \
    }


inline void BadRequest(httplib::Response& res, std::string const& message) {
    res.status = 400;
    SET_CONTENT(({{"code", 400}, {"name", "Bad Request"}, {"message", message}}));
}

class FFIInvoke;


class HttpServer {
public:
    explicit HttpServer(FFIInvoke& ffi_invoke);

    // C++ enums suck.
    enum Method {
        GET,
        POST,
        PUT,
        PATCH,
    };
    // but im not in the mood of adding yet another dependency for just that shit here.
    static std::string ToString(Method m);

    struct Endpoint {
        std::string path;
        Method method;
        std::function<void(const httplib::Request& req, httplib::Response& res)> handler;
        nlohmann::json response_hint = nullptr;
        nlohmann::json payload_hint = nullptr;
    };

    static void AddEndpoint(const Endpoint&& e);
    template <typename T>
    static inline auto ParseQueryParam(const httplib::Request& req, const std::string& name, T defaultValue) -> T
    {
        T value = defaultValue;
        try {
            value = req.get_param_value(name);
        }
        catch (...) {
            // ignore
        }
        return value;
    }
    template <>
    static inline auto ParseQueryParam(
        const httplib::Request& req, const std::string& name, bool defaultValue) -> bool {
        auto value = defaultValue;
        try {
            const auto value_str = req.get_param_value(name);
            value = value_str == "true" || value_str == "1";
        }
        catch (...) {
            // ignore
        }
        return value;
    }
    template <>
    static inline auto ParseQueryParam(
        const httplib::Request& req, const std::string& name, int defaultValue) -> int {
        auto value = defaultValue;
        try {
            const auto value_str = req.get_param_value(name);
            value = std::stoi(value_str);
        }
        catch (...) {
            // ignore
        }
        return value;
    }

    template <>
    static inline auto ParseQueryParam(const httplib::Request& req, const std::string& name,
        unsigned long long defaultValue) -> unsigned long long {
        auto value = defaultValue;
        try {
            const auto value_str = req.get_param_value(name);
            value = std::stoll(value_str);
        }
        catch (...) {
            // ignore
        }
        return value;
    }


    /**
     * creating the endpoints and defining them with some lambdas.
     */
    void run(int port);

private:
    httplib::Server server_;
    FFIInvoke& ffi_invoke_;

    static inline std::vector<Endpoint> endpoints_;
};
