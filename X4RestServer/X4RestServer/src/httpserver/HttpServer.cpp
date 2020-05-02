#include "HttpServer.h"
#include "../ffi/FFIInvoke.h"
#include "../ffi/ffi_json.h"
#include "../__generated__/gen_ffi_json.h"

#define SET_CONTENT(Call) \
	res.set_content( \
			Call.dump(), "text/json")

#define PARAMS(...) \
	ffi_invoke_, __VA_ARGS__

HttpServer::HttpServer(FFIInvoke& ffi_invoke) : ffi_invoke_(ffi_invoke)
{
}

void HttpServer::run(int port)
{
	server.Get("/player-name", [&](const httplib::Request& req, httplib::Response& res) {
		SET_CONTENT(ffijson::GetPlayerName(PARAMS()));
	});
	server.Get("/soft-target", [&](const httplib::Request& req, httplib::Response& res) {
		SET_CONTENT(ffijson::GetSofttarget(PARAMS()));
	});

	server.Get("/component-details", [&](const httplib::Request& req, httplib::Response& res) {
		std::string compId = req.get_param_value("componentId");
		std::string connectionName = req.get_param_value("connectionName");
		if (compId.empty())
		{
			return BadRequest(res, "componentId must be set");
		}
		if (connectionName.empty())
		{
			connectionName = "X4RestServer";
			//return BadRequest(res, "connectionName must be set");
		}
		try {
			X4FFI::UniverseID uniId = std::stoll(compId);
			SET_CONTENT(ffijson::GetComponentDetails(PARAMS(uniId, connectionName.c_str())));
		} catch (std::exception&) {
			return BadRequest(res, "componentId malformed");
		}
	});

	// --
	
	server.Get("/default-order", [&](const httplib::Request& req, httplib::Response& res) {
		std::string controllableId = req.get_param_value("controllableId");
		if (controllableId.empty())
		{
			return BadRequest(res, "controllableId must be set");
		}
		try {
			X4FFI::UniverseID uniId = std::stoll(controllableId);
			SET_CONTENT(JSONIMPL::GetDefaultOrder(PARAMS(uniId)));
		}
		catch (std::exception&) {
			return BadRequest(res, "controllableId malformed");
		}
	});

	// --
	
	server.Get("/stop", [&](const httplib::Request& req, httplib::Response& res) {
		std::thread([&]() {
			server.stop();
			}).detach();
			res.set_content(json{{"ejected", true}}.dump(), "text/json");
		});
	// somehow got bad request every other request without this o.O
	std::thread([&]()
	{
			server.listen("0.0.0.0", port);
	}).join();
}

void HttpServer::BadRequest(httplib::Response& res, std::string const& message)
{
	res.status = 401;
	res.set_content(json{
		{"code", 401},
		{"name", "Bad Request"},
		{"message", message},
	}.dump(), "text/json");
}
