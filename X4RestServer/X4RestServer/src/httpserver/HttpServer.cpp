#include "HttpServer.h"
#include "../ffi/FFIInvoke.h"

HttpServer::HttpServer(FFIInvoke& ffi_invoke) : ffi_invoke_(ffi_invoke)
{
}

void HttpServer::run(int port)
{
	server.Get("/player-name", [&](const httplib::Request& req, httplib::Response& res) {
		res.set_content(
			ffi_invoke_.GetPlayerName().dump(), "text/json");
		});
	server.Get("/soft-target", [&](const httplib::Request& req, httplib::Response& res) {
		res.set_content(
			ffi_invoke_.GetSofttarget().dump(), "text/json");
		});



	
	server.Get("/stop", [&](const httplib::Request& req, httplib::Response& res) {
		std::thread([&]() {
			server.stop();
			}).detach();
		// produces empty response
		});
	// somehow got bad request every other request without this o.O
	std::thread([&]()
	{
			server.listen("0.0.0.0", port);
	}).join();
}
