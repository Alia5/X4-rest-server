/*
Copyright 2021-2023 Peter Repukat - FlatspotSoftware

Use of this source code is governed by the MIT
license that can be found in the LICENSE file or at
https://opensource.org/licenses/MIT.
*/

#pragma once

#include "../httpserver/HttpServer.h"
#include "../ffi/FFIInvoke.h"

#include "../ffi/ffi_enum_helper.h"

#include "../ffi/json_converters.h"

inline void RegisterMessageFunctions(INIT_PARAMS()) {

    HttpServer::AddEndpoint(
        {"/GetNumMessages", HttpServer::Method::GET, [ & ](const httplib::Request& req, httplib::Response& res) {
             const auto category = req.get_param_value("category");

             if (category.empty()) {
                 return BadRequest(res, "category is required");
             }

             if (!MessageCategory::is_valid(category)) {
                 return BadRequest(res, "category is invalid; Valid categories: 'all', 'highprio', 'lowprio'");
             }

             bool unread = false;
             const auto lastParam = req.get_param_value("unread");
             if (lastParam == "1" || lastParam == "true") {
                 unread = true;
             }


             const auto callResult = invoke(GetNumMessages, category.c_str(), unread);
             SET_CONTENT((callResult));
         }});

    //   using GetMessages = uint32_t (*)(
    //    MessageInfo* result, uint32_t resultlen, size_t start, size_t count, const char* categoryname);

    HttpServer::AddEndpoint(
        {"/GetMessages", HttpServer::Method::GET, [ & ](const httplib::Request& req, httplib::Response& res) {
             const auto category = req.get_param_value("category");

             if (category.empty()) {
                 return BadRequest(res, "category is required");
             }

             if (!MessageCategory::is_valid(category)) {
                 return BadRequest(res, "category is invalid; Valid categories: 'all', 'highprio', 'lowprio'");
             }

             size_t from = 0;
             size_t count = 0;

             try {
                 from = std::stoul(req.get_param_value("from"));
             }
             catch (...) {
                 // ignore
             }
             try {
                 count = std::stoul(req.get_param_value("count"));
             }
             catch (...) {
                 // ignore
             }


             std::vector<X4FFI::MessageInfo> messages;

             const auto numMessages = invoke(GetNumMessages, category.c_str(), false);
             if (from > numMessages) {
                 from = numMessages;
             }
             if (count == 0) {
                 count = numMessages;
             }
             count = std::clamp(count, static_cast<size_t>(0),
                 std::max(static_cast<size_t>(0), (numMessages + (from == 0 ? 0 : 1)) - from));

             messages.resize(count);

             const auto length = invoke(GetMessages, messages.data(), messages.size(), from, count, category.c_str());
             SET_CONTENT(({{"length", length}, {"messages", messages}}));
         }});
}
