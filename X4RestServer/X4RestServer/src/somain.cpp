#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <stdlib.h>     /* getenv */

#include "httpserver/HttpServer.h"
#include "ffi/FFIInvoke.h"

bool endsWith(std::string const &fullString, std::string const &ending) {
        if (fullString.length() >= ending.length()) {
                return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
        } else {
                return false;
        }
}

using namespace std::chrono_literals;

int onLoadX4RestServer() {

        std::thread([&]() {
                        const std::string env = getenv("_");
                        if (endsWith(env, "X4")) {
                            std::cout << "Loaded into X4 Binary:  " << getenv("_") << "\n";
                            FFIInvoke ffi_invoke;
                            HttpServer server(ffi_invoke);
                            server.run(3000);
                        }
                        }).detach();
        return 1337;
}

int static_initX4RestServer = onLoadX4RestServer();