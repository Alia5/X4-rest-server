#pragma once
#include <httplib.h>
class FFIInvoke;

/**
 * Class containing the actual http-endpoints
 */
class HttpServer {
  public:
    explicit HttpServer(FFIInvoke& ffi_invoke);
    /**
     * creating the endpoints and defining them with some lambdas.
     */
    void run(int port);

  private:
    httplib::Server server;
    FFIInvoke& ffi_invoke_;
};
