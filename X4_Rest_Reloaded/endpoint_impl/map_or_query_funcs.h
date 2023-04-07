/*
Copyright 2021-2023 Peter Repukat - FlatspotSoftware

Use of this source code is governed by the MIT
license that can be found in the LICENSE file or at
https://opensource.org/licenses/MIT.
*/

#include "../httpserver/HttpServer.h"
#include "../ffi/FFIInvoke.h"

#include "../ffi/ffi_enum_helper.h"

#include "../ffi/json_converters.h"


inline void RegisterMapOrQueryFunctions(INIT_PARAMS()) {
    HttpServer::AddEndpoint(SIMPLE_GET_HANDLER(GetNumAllRaces));

    HttpServer::AddEndpoint({"/GetNumAllFactions", HttpServer::Method::GET,
        [ & ](const httplib::Request& req, httplib::Response& res) {
            bool include_hidden = false;

            try {
                const auto hidden_param = req.get_param_value("hidden");
                include_hidden = hidden_param == "true" || hidden_param == "1";
            }
            catch (...) {
                // ignore
            }

            const auto numFactions = invoke(GetNumAllFactions, include_hidden);
            SET_CONTENT((numFactions));
        }});

    HttpServer::AddEndpoint({"/GetAllRaces", HttpServer::Method::GET,
        [ & ](const httplib::Request& req, httplib::Response& res) {
            const auto numRaces = invoke(GetNumAllRaces);
            std::vector<X4FFI::RaceInfo> result;
            result.resize(numRaces);
            const auto callResult = invoke(GetAllRaces, result.data(), result.size());
            SET_CONTENT((result));
        }});

    HttpServer::AddEndpoint({"/GetAllFactions", HttpServer::Method::GET,
        [ & ](const httplib::Request& req, httplib::Response& res) {
            bool include_hidden = false;

            try {
                const auto hidden_param = req.get_param_value("hidden");
                include_hidden = hidden_param == "true" || hidden_param == "1";
            }
            catch (...) {
                // ignore
            }

            const auto numFactions = invoke(GetNumAllFactions, include_hidden);
            std::vector<char*> result;
            result.resize(numFactions);
            const auto callResult = invoke(
                GetAllFactions, (const char**)result.data(), result.size(), include_hidden);
            SET_CONTENT((result));
        }});

    HttpServer::AddEndpoint({"/GetAllFactionShips", HttpServer::Method::GET,
        [ & ](const httplib::Request& req, httplib::Response& res) {
            std::string factionId = "";
            try {
                factionId = req.get_param_value("factionId");
            }
            catch (...) {
                // ignore
            }
            const auto numFactions = invoke(GetNumAllFactions, true);
            std::vector<char*> factions;
            factions.resize(numFactions);
            invoke(GetAllFactions, (const char**)factions.data(), factions.size(), true);

            if (std::ranges::find_if(factions, [ & ](const auto f) {
                    return f == factionId;
                }) == std::ranges::end(factions)) {
                return BadRequest(res, "factionId is invalid");
            }

            const auto numShips = invoke(GetNumAllFactionShips, factionId.c_str());
            std::vector<X4FFI::UniverseID> result;
            result.resize(numShips);

            invoke(GetAllFactionShips, result.data(), result.size(), factionId.c_str());
            SET_CONTENT((result));
        }});

    HttpServer::AddEndpoint({"/GetAllFactionStations", HttpServer::Method::GET,
        [ & ](const httplib::Request& req, httplib::Response& res) {
            std::string factionId = "";
            try {
                factionId = req.get_param_value("factionId");
            }
            catch (...) {
                // ignore
            }
            const auto numFactions = invoke(GetNumAllFactions, true);
            std::vector<char*> factions;
            factions.resize(numFactions);
            invoke(GetAllFactions, (const char**)factions.data(), factions.size(), true);

            if (std::ranges::find_if(factions, [ & ](const auto f) {
                    return f == factionId;
                }) == std::ranges::end(factions)) {
                return BadRequest(res, "factionId is invalid");
            }

            const auto numShips = invoke(GetNumAllFactionStations, factionId.c_str());
            std::vector<X4FFI::UniverseID> result;
            result.resize(numShips);

            invoke(GetAllFactionStations, result.data(), result.size(), factionId.c_str());
            SET_CONTENT((result));
        }});


    HttpServer::AddEndpoint({"/GetSectorShips", HttpServer::Method::GET,
        [ & ](const httplib::Request& req, httplib::Response& res) {
            const X4FFI::UniverseID sectorId = HttpServer::ParseQueryParam(req, "sectorId", 0);
            if (sectorId == 0) {
                return BadRequest(res, "sectorId is invalid");
            }
            const bool includeHidden = HttpServer::ParseQueryParam(req, "hidden", false);
            const auto numFactions = invoke(GetNumAllFactions, includeHidden);
            std::vector<char*> allFactions;
            allFactions.resize(numFactions);
            invoke(GetAllFactions, (const char**)allFactions.data(), allFactions.size(),
                includeHidden);
            std::string shipIdsString = "";
            for (const auto& faction : allFactions) {
                const auto numShips = invoke(GetNumAllFactionShips, faction);
                std::vector<X4FFI::UniverseID> factionShipIds;
                factionShipIds.resize(numShips);
                invoke(
                    GetAllFactionShips, factionShipIds.data(), factionShipIds.size(), faction);
                for (const auto& ship : factionShipIds) {
                    shipIdsString += std::to_string(ship) + ",";
                }
            }
            shipIdsString.pop_back();

            const auto lua_str = std::string(R"(
local resultTable = {}
local sectorId = "ID: )") + std::to_string(sectorId) + R"("
local shipIds = {)" + shipIdsString +
                                 R"(}

for i, ship in ipairs(shipIds) do
	local data = {GetComponentData(ship, "name","sectorid","owner","shiptype")}
	if tostring(data[2]) == sectorId then 
        table.insert(resultTable, {
   		    ["id"] = ship,
   		    ["name"] = data[1],
      	    ["sectorid"] = data[2],
      	    ["owner"] = data[3],
      	    ["shiptype"] = data[4]
       })
    end
end


return json.encode(resultTable)
            )";
            const auto callResult = executeLua(lua_str, true, true);
            res.set_content(callResult, "application/json");
        }});
}