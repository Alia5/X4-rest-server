#pragma once
#include <httplib.h>
class FFIInvoke;

class HttpServer
{
public:
	explicit HttpServer(FFIInvoke& ffi_invoke);
	void run(int port);

private:
	httplib::Server server;
	FFIInvoke& ffi_invoke_;

	static void BadRequest(httplib::Response& res, std::string const& message);
	
};

