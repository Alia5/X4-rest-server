
#pragma once
#include <httplib.h>
#include <string>

#include "../ffi/FFIInvoke.h"
#include "../ffi/ffi_json.h"
#include "gen_ffi_json.h"

#define SET_CONTENT(Call) 	res.set_content( 			Call.dump(), "text/json")

#define PARAMS(...) 	ffi_invoke, __VA_ARGS__

#define HAN_FN 	[&](const httplib::Request& req, httplib::Response& res)

void BadRequest(httplib::Response& res, std::string const& message)
{
	res.status = 401;
	res.set_content(json{
		{"code", 401},
		{"name", "Bad Request"},
		{"message", message},
		}.dump(), "text/json");
}

void initGenFuns(httplib::Server& server, FFIInvoke& ffi_invoke)
{

    server.Get("/GetCrosshairArrowDetails", HAN_FN {
        std::string posid = req.get_param_value("posid");
        std::string radius = req.get_param_value("radius");
        if (posid.empty())
        {
            return BadRequest(res, "posid must be set");
        }
        if (radius.empty())
        {
            return BadRequest(res, "radius must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCrosshairArrowDetails(PARAMS(std::stoi(posid), std::stof(radius))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAutosaveIntervalOption", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetAutosaveIntervalOption(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetBlacklistInfoCounts", HAN_FN {
        std::string id = req.get_param_value("id");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        try {
            SET_CONTENT(ffijson::GetBlacklistInfoCounts(PARAMS(std::stoll(id))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetControllableBlacklistID", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string listtype = req.get_param_value("listtype");
        std::string defaultgroup = req.get_param_value("defaultgroup");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (listtype.empty())
        {
            return BadRequest(res, "listtype must be set");
        }
        if (defaultgroup.empty())
        {
            return BadRequest(res, "defaultgroup must be set");
        }
        try {
            SET_CONTENT(ffijson::GetControllableBlacklistID(PARAMS(std::stoll(controllableid), listtype.c_str(), defaultgroup.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetBoardingRiskThresholds", HAN_FN {
        std::string defensibletargetid = req.get_param_value("defensibletargetid");
        std::string boarderfactionid = req.get_param_value("boarderfactionid");
        if (defensibletargetid.empty())
        {
            return BadRequest(res, "defensibletargetid must be set");
        }
        if (boarderfactionid.empty())
        {
            return BadRequest(res, "boarderfactionid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetBoardingRiskThresholds(PARAMS(std::stoll(defensibletargetid), boarderfactionid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetBuildTaskInfo", HAN_FN {
        std::string id = req.get_param_value("id");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        try {
            SET_CONTENT(ffijson::GetBuildTaskInfo(PARAMS(std::stoll(id))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetComponentDetails", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        std::string connectionname = req.get_param_value("connectionname");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetComponentDetails(PARAMS(std::stoll(componentid), connectionname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCenteredMousePos", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetCenteredMousePos(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetWidgetSystemSizeOverride", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetWidgetSystemSizeOverride(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetBuildPlotCenterOffset", HAN_FN {
        std::string stationid = req.get_param_value("stationid");
        if (stationid.empty())
        {
            return BadRequest(res, "stationid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetBuildPlotCenterOffset(PARAMS(std::stoll(stationid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetBuildPlotSize", HAN_FN {
        std::string stationid = req.get_param_value("stationid");
        if (stationid.empty())
        {
            return BadRequest(res, "stationid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetBuildPlotSize(PARAMS(std::stoll(stationid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetMinimumBuildPlotCenterOffset", HAN_FN {
        std::string stationid = req.get_param_value("stationid");
        if (stationid.empty())
        {
            return BadRequest(res, "stationid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetMinimumBuildPlotCenterOffset(PARAMS(std::stoll(stationid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetMinimumBuildPlotSize", HAN_FN {
        std::string stationid = req.get_param_value("stationid");
        if (stationid.empty())
        {
            return BadRequest(res, "stationid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetMinimumBuildPlotSize(PARAMS(std::stoll(stationid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPaidBuildPlotCenterOffset", HAN_FN {
        std::string stationid = req.get_param_value("stationid");
        if (stationid.empty())
        {
            return BadRequest(res, "stationid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetPaidBuildPlotCenterOffset(PARAMS(std::stoll(stationid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPaidBuildPlotSize", HAN_FN {
        std::string stationid = req.get_param_value("stationid");
        if (stationid.empty())
        {
            return BadRequest(res, "stationid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetPaidBuildPlotSize(PARAMS(std::stoll(stationid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumBuildTaskCrewTransferInfo", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string id = req.get_param_value("id");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumBuildTaskCrewTransferInfo(PARAMS(std::stoll(containerid), std::stoll(id))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCurrentCrosshairMessage", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetCurrentCrosshairMessage(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCurrentCursorInfo", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetCurrentCursorInfo(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCustomGameStartBlueprintPropertyState", HAN_FN {
        std::string id = req.get_param_value("id");
        std::string propertyid = req.get_param_value("propertyid");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (propertyid.empty())
        {
            return BadRequest(res, "propertyid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCustomGameStartBlueprintPropertyState(PARAMS(id.c_str(), propertyid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCustomGameStartEncyclopediaPropertyState", HAN_FN {
        std::string id = req.get_param_value("id");
        std::string propertyid = req.get_param_value("propertyid");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (propertyid.empty())
        {
            return BadRequest(res, "propertyid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCustomGameStartEncyclopediaPropertyState(PARAMS(id.c_str(), propertyid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCustomGameStartInventoryPropertyState", HAN_FN {
        std::string id = req.get_param_value("id");
        std::string propertyid = req.get_param_value("propertyid");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (propertyid.empty())
        {
            return BadRequest(res, "propertyid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCustomGameStartInventoryPropertyState(PARAMS(id.c_str(), propertyid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCustomGameStartLoadoutPropertyState", HAN_FN {
        std::string id = req.get_param_value("id");
        std::string propertyid = req.get_param_value("propertyid");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (propertyid.empty())
        {
            return BadRequest(res, "propertyid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCustomGameStartLoadoutPropertyState(PARAMS(id.c_str(), propertyid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCustomGameStartRelationsPropertyState", HAN_FN {
        std::string id = req.get_param_value("id");
        std::string propertyid = req.get_param_value("propertyid");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (propertyid.empty())
        {
            return BadRequest(res, "propertyid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCustomGameStartRelationsPropertyState(PARAMS(id.c_str(), propertyid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCustomGameStartResearchPropertyState", HAN_FN {
        std::string id = req.get_param_value("id");
        std::string propertyid = req.get_param_value("propertyid");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (propertyid.empty())
        {
            return BadRequest(res, "propertyid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCustomGameStartResearchPropertyState(PARAMS(id.c_str(), propertyid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetDroneDetails", HAN_FN {
        std::string dronetype = req.get_param_value("dronetype");
        if (dronetype.empty())
        {
            return BadRequest(res, "dronetype must be set");
        }
        try {
            SET_CONTENT(ffijson::GetDroneDetails(PARAMS(std::stoll(dronetype))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetEquipmentModInfo", HAN_FN {
        std::string wareid = req.get_param_value("wareid");
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetEquipmentModInfo(PARAMS(wareid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetFPS", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetFPS(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetFactionDetails", HAN_FN {
        std::string factionid = req.get_param_value("factionid");
        if (factionid.empty())
        {
            return BadRequest(res, "factionid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetFactionDetails(PARAMS(factionid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetOwnerDetails", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetOwnerDetails(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetGameVersion", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetGameVersion(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetMissionOfferIcons", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetMissionOfferIcons(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetLastAttackInfo", HAN_FN {
        std::string destructibleid = req.get_param_value("destructibleid");
        if (destructibleid.empty())
        {
            return BadRequest(res, "destructibleid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetLastAttackInfo(PARAMS(std::stoll(destructibleid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetMessageDetails2", HAN_FN {
        std::string messageid = req.get_param_value("messageid");
        if (messageid.empty())
        {
            return BadRequest(res, "messageid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetMessageDetails2(PARAMS(std::stoll(messageid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetMissionBriefingIcon", HAN_FN {
        std::string missionid = req.get_param_value("missionid");
        if (missionid.empty())
        {
            return BadRequest(res, "missionid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetMissionBriefingIcon(PARAMS(std::stoll(missionid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetMissionIDDetails", HAN_FN {
        std::string missionid = req.get_param_value("missionid");
        if (missionid.empty())
        {
            return BadRequest(res, "missionid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetMissionIDDetails(PARAMS(std::stoll(missionid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetMissionGroupDetails", HAN_FN {
        std::string missionid = req.get_param_value("missionid");
        if (missionid.empty())
        {
            return BadRequest(res, "missionid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetMissionGroupDetails(PARAMS(std::stoll(missionid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPickedMapMission", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetPickedMapMission(PARAMS(std::stoll(holomapid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetMissionInfo2", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetMissionInfo2(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetMissionIDObjective", HAN_FN {
        std::string missionid = req.get_param_value("missionid");
        if (missionid.empty())
        {
            return BadRequest(res, "missionid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetMissionIDObjective(PARAMS(std::stoll(missionid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetMissionObjectiveStep2", HAN_FN {
        std::string missionid = req.get_param_value("missionid");
        std::string objectiveIndex = req.get_param_value("objectiveIndex");
        if (missionid.empty())
        {
            return BadRequest(res, "missionid must be set");
        }
        if (objectiveIndex.empty())
        {
            return BadRequest(res, "objectiveIndex must be set");
        }
        try {
            SET_CONTENT(ffijson::GetMissionObjectiveStep2(PARAMS(std::stoll(missionid), std::stoll(objectiveIndex))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPOIDetails", HAN_FN {
        std::string poiid = req.get_param_value("poiid");
        if (poiid.empty())
        {
            return BadRequest(res, "poiid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetPOIDetails(PARAMS(std::stoll(poiid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetRelativeAimOffset", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetRelativeAimOffset(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetTargetElementOffset", HAN_FN {
        std::string posid = req.get_param_value("posid");
        if (posid.empty())
        {
            return BadRequest(res, "posid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetTargetElementOffset(PARAMS(std::stoi(posid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetRelativeAimScreenPosition", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        std::string iconsizeonscreen = req.get_param_value("iconsizeonscreen");
        std::string iconsizeoffscreen = req.get_param_value("iconsizeoffscreen");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        if (iconsizeonscreen.empty())
        {
            return BadRequest(res, "iconsizeonscreen must be set");
        }
        if (iconsizeoffscreen.empty())
        {
            return BadRequest(res, "iconsizeoffscreen must be set");
        }
        try {
            SET_CONTENT(ffijson::GetRelativeAimScreenPosition(PARAMS(std::stoll(componentid), std::stoll(iconsizeonscreen), std::stoll(iconsizeoffscreen))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetFactionRelationStatus", HAN_FN {
        std::string factionid = req.get_param_value("factionid");
        if (factionid.empty())
        {
            return BadRequest(res, "factionid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetFactionRelationStatus(PARAMS(factionid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetRelationStatus2", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        std::string connectionname = req.get_param_value("connectionname");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetRelationStatus2(PARAMS(std::stoll(componentid), connectionname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetGameResolution", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetGameResolution(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetRenderResolutionOption", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetRenderResolutionOption(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCameraRotation", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetCameraRotation(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetComponentScreenPosition", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        std::string iconsizeonscreen = req.get_param_value("iconsizeonscreen");
        std::string iconsizeoffscreen = req.get_param_value("iconsizeoffscreen");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        if (iconsizeonscreen.empty())
        {
            return BadRequest(res, "iconsizeonscreen must be set");
        }
        if (iconsizeoffscreen.empty())
        {
            return BadRequest(res, "iconsizeoffscreen must be set");
        }
        try {
            SET_CONTENT(ffijson::GetComponentScreenPosition(PARAMS(std::stoll(componentid), std::stoll(iconsizeonscreen), std::stoll(iconsizeoffscreen))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetSofttarget", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetSofttarget(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetSpecialNPCs", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetSpecialNPCs(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetTableInitialSelectionInfo", HAN_FN {
        std::string tableid = req.get_param_value("tableid");
        if (tableid.empty())
        {
            return BadRequest(res, "tableid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetTableInitialSelectionInfo(PARAMS(std::stoi(tableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPickedMapTradeOffer", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetPickedMapTradeOffer(PARAMS(std::stoll(holomapid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetTurret", HAN_FN {
        std::string turretnum = req.get_param_value("turretnum");
        if (turretnum.empty())
        {
            return BadRequest(res, "turretnum must be set");
        }
        try {
            SET_CONTENT(ffijson::GetTurret(PARAMS(std::stoll(turretnum))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetFormationShape", HAN_FN {
        std::string objectid = req.get_param_value("objectid");
        std::string formationshape = req.get_param_value("formationshape");
        if (objectid.empty())
        {
            return BadRequest(res, "objectid must be set");
        }
        if (formationshape.empty())
        {
            return BadRequest(res, "formationshape must be set");
        }
        try {
            SET_CONTENT(ffijson::SetFormationShape(PARAMS(std::stoll(objectid), formationshape.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetFrameBackground2Info", HAN_FN {
        std::string frameid = req.get_param_value("frameid");
        if (frameid.empty())
        {
            return BadRequest(res, "frameid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetFrameBackground2Info(PARAMS(std::stoi(frameid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetFrameBackgroundInfo", HAN_FN {
        std::string frameid = req.get_param_value("frameid");
        if (frameid.empty())
        {
            return BadRequest(res, "frameid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetFrameBackgroundInfo(PARAMS(std::stoi(frameid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetFrameOverlayInfo", HAN_FN {
        std::string frameid = req.get_param_value("frameid");
        if (frameid.empty())
        {
            return BadRequest(res, "frameid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetFrameOverlayInfo(PARAMS(std::stoi(frameid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCurrentLoadoutStatistics2", HAN_FN {
        std::string shipid = req.get_param_value("shipid");
        if (shipid.empty())
        {
            return BadRequest(res, "shipid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCurrentLoadoutStatistics2(PARAMS(std::stoll(shipid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetMaxLoadoutStatistics2", HAN_FN {
        std::string shipid = req.get_param_value("shipid");
        std::string macroname = req.get_param_value("macroname");
        if (shipid.empty())
        {
            return BadRequest(res, "shipid must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        try {
            SET_CONTENT(ffijson::GetMaxLoadoutStatistics2(PARAMS(std::stoll(shipid), macroname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCurrentPlayerLogo", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetCurrentPlayerLogo(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetMapTradeVolumeParameter", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetMapTradeVolumeParameter(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetHelpOverlayInfo", HAN_FN {
        std::string widgetid = req.get_param_value("widgetid");
        if (widgetid.empty())
        {
            return BadRequest(res, "widgetid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetHelpOverlayInfo(PARAMS(std::stoi(widgetid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetStandardButtonHelpOverlayInfo", HAN_FN {
        std::string frameid = req.get_param_value("frameid");
        std::string button = req.get_param_value("button");
        if (frameid.empty())
        {
            return BadRequest(res, "frameid must be set");
        }
        if (button.empty())
        {
            return BadRequest(res, "button must be set");
        }
        try {
            SET_CONTENT(ffijson::GetStandardButtonHelpOverlayInfo(PARAMS(std::stoi(frameid), button.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCustomGameStartPosRotProperty", HAN_FN {
        std::string id = req.get_param_value("id");
        std::string propertyid = req.get_param_value("propertyid");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (propertyid.empty())
        {
            return BadRequest(res, "propertyid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCustomGameStartPosRotProperty(PARAMS(id.c_str(), propertyid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetObjectPositionInSector", HAN_FN {
        std::string objectid = req.get_param_value("objectid");
        if (objectid.empty())
        {
            return BadRequest(res, "objectid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetObjectPositionInSector(PARAMS(std::stoll(objectid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPlayerTargetOffset", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetPlayerTargetOffset(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetLastSaveInfo", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetLastSaveInfo(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumUISystemInfo", HAN_FN {
        std::string clusterid = req.get_param_value("clusterid");
        if (clusterid.empty())
        {
            return BadRequest(res, "clusterid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumUISystemInfo(PARAMS(std::stoll(clusterid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCurrentVentureMissionInfo", HAN_FN {
        std::string ventureplatformid = req.get_param_value("ventureplatformid");
        if (ventureplatformid.empty())
        {
            return BadRequest(res, "ventureplatformid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCurrentVentureMissionInfo(PARAMS(std::stoll(ventureplatformid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/AddHoloMap", HAN_FN {
        std::string texturename = req.get_param_value("texturename");
        std::string x0 = req.get_param_value("x0");
        std::string x1 = req.get_param_value("x1");
        std::string y0 = req.get_param_value("y0");
        std::string y1 = req.get_param_value("y1");
        std::string aspectx = req.get_param_value("aspectx");
        std::string aspecty = req.get_param_value("aspecty");
        if (texturename.empty())
        {
            return BadRequest(res, "texturename must be set");
        }
        if (x0.empty())
        {
            return BadRequest(res, "x0 must be set");
        }
        if (x1.empty())
        {
            return BadRequest(res, "x1 must be set");
        }
        if (y0.empty())
        {
            return BadRequest(res, "y0 must be set");
        }
        if (y1.empty())
        {
            return BadRequest(res, "y1 must be set");
        }
        if (aspectx.empty())
        {
            return BadRequest(res, "aspectx must be set");
        }
        if (aspecty.empty())
        {
            return BadRequest(res, "aspecty must be set");
        }
        try {
            SET_CONTENT(ffijson::AddHoloMap(PARAMS(texturename.c_str(), std::stof(x0), std::stof(x1), std::stof(y0), std::stof(y1), std::stof(aspectx), std::stof(aspecty))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/CreateNPCFromPerson", HAN_FN {
        std::string person = req.get_param_value("person");
        std::string controllableid = req.get_param_value("controllableid");
        if (person.empty())
        {
            return BadRequest(res, "person must be set");
        }
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        try {
            SET_CONTENT(ffijson::CreateNPCFromPerson(PARAMS(std::stoll(person), std::stoll(controllableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCommonContext", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        std::string othercomponentid = req.get_param_value("othercomponentid");
        std::string includeself = req.get_param_value("includeself");
        std::string includeother = req.get_param_value("includeother");
        std::string limitid = req.get_param_value("limitid");
        std::string includelimit = req.get_param_value("includelimit");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        if (othercomponentid.empty())
        {
            return BadRequest(res, "othercomponentid must be set");
        }
        if (includeself.empty())
        {
            return BadRequest(res, "includeself must be set");
        }
        if (includeother.empty())
        {
            return BadRequest(res, "includeother must be set");
        }
        if (limitid.empty())
        {
            return BadRequest(res, "limitid must be set");
        }
        if (includelimit.empty())
        {
            return BadRequest(res, "includelimit must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCommonContext(PARAMS(std::stoll(componentid), std::stoll(othercomponentid), std::stoi(includeself), std::stoi(includeother), std::stoll(limitid), std::stoi(includelimit))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetContextByClass", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        std::string classname = req.get_param_value("classname");
        std::string includeself = req.get_param_value("includeself");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        if (classname.empty())
        {
            return BadRequest(res, "classname must be set");
        }
        if (includeself.empty())
        {
            return BadRequest(res, "includeself must be set");
        }
        try {
            SET_CONTENT(ffijson::GetContextByClass(PARAMS(std::stoll(componentid), classname.c_str(), std::stoi(includeself))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetContextForTransporterCheck", HAN_FN {
        std::string positionalid = req.get_param_value("positionalid");
        if (positionalid.empty())
        {
            return BadRequest(res, "positionalid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetContextForTransporterCheck(PARAMS(std::stoll(positionalid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetEnvironmentObject", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetEnvironmentObject(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetExternalTargetViewComponent", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetExternalTargetViewComponent(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetFactionRepresentative", HAN_FN {
        std::string factionid = req.get_param_value("factionid");
        if (factionid.empty())
        {
            return BadRequest(res, "factionid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetFactionRepresentative(PARAMS(factionid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetInstantiatedPerson", HAN_FN {
        std::string person = req.get_param_value("person");
        std::string controllableid = req.get_param_value("controllableid");
        if (person.empty())
        {
            return BadRequest(res, "person must be set");
        }
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetInstantiatedPerson(PARAMS(std::stoll(person), std::stoll(controllableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetLastPlayerControlledShipID", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetLastPlayerControlledShipID(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetMissionIDObjectiveTarget", HAN_FN {
        std::string missionid = req.get_param_value("missionid");
        std::string targetIndex = req.get_param_value("targetIndex");
        if (missionid.empty())
        {
            return BadRequest(res, "missionid must be set");
        }
        if (targetIndex.empty())
        {
            return BadRequest(res, "targetIndex must be set");
        }
        try {
            SET_CONTENT(ffijson::GetMissionIDObjectiveTarget(PARAMS(std::stoll(missionid), std::stoll(targetIndex))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetParentComponent", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetParentComponent(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPickedMapComponent", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetPickedMapComponent(PARAMS(std::stoll(holomapid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPickedMapMissionOffer", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetPickedMapMissionOffer(PARAMS(std::stoll(holomapid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPickedMapOrder", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetPickedMapOrder(PARAMS(std::stoll(holomapid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPlayerComputerID", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetPlayerComputerID(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPlayerContainerID", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetPlayerContainerID(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPlayerControlledShipID", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetPlayerControlledShipID(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPlayerID", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetPlayerID(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPlayerObjectID", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetPlayerObjectID(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPlayerOccupiedShipID", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetPlayerOccupiedShipID(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPlayerShipID", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetPlayerShipID(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPlayerZoneID", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetPlayerZoneID(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetSectorControlStation", HAN_FN {
        std::string sectorid = req.get_param_value("sectorid");
        if (sectorid.empty())
        {
            return BadRequest(res, "sectorid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetSectorControlStation(PARAMS(std::stoll(sectorid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetTopLevelContainer", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetTopLevelContainer(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetUpgradeSlotCurrentComponent", HAN_FN {
        std::string destructibleid = req.get_param_value("destructibleid");
        std::string upgradetypename = req.get_param_value("upgradetypename");
        std::string slot = req.get_param_value("slot");
        if (destructibleid.empty())
        {
            return BadRequest(res, "destructibleid must be set");
        }
        if (upgradetypename.empty())
        {
            return BadRequest(res, "upgradetypename must be set");
        }
        if (slot.empty())
        {
            return BadRequest(res, "slot must be set");
        }
        try {
            SET_CONTENT(ffijson::GetUpgradeSlotCurrentComponent(PARAMS(std::stoll(destructibleid), upgradetypename.c_str(), std::stoll(slot))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetZoneAt", HAN_FN {
        std::string sectorid = req.get_param_value("sectorid");
        if (sectorid.empty())
        {
            return BadRequest(res, "sectorid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetZoneAt(PARAMS(std::stoll(sectorid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetUpgradeSlotGroup", HAN_FN {
        std::string destructibleid = req.get_param_value("destructibleid");
        std::string macroname = req.get_param_value("macroname");
        std::string upgradetypename = req.get_param_value("upgradetypename");
        std::string slot = req.get_param_value("slot");
        if (destructibleid.empty())
        {
            return BadRequest(res, "destructibleid must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        if (upgradetypename.empty())
        {
            return BadRequest(res, "upgradetypename must be set");
        }
        if (slot.empty())
        {
            return BadRequest(res, "slot must be set");
        }
        try {
            SET_CONTENT(ffijson::GetUpgradeSlotGroup(PARAMS(std::stoll(destructibleid), macroname.c_str(), upgradetypename.c_str(), std::stoll(slot))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetUpgradeGroupInfo", HAN_FN {
        std::string destructibleid = req.get_param_value("destructibleid");
        std::string macroname = req.get_param_value("macroname");
        std::string path = req.get_param_value("path");
        std::string group = req.get_param_value("group");
        std::string upgradetypename = req.get_param_value("upgradetypename");
        if (destructibleid.empty())
        {
            return BadRequest(res, "destructibleid must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        if (path.empty())
        {
            return BadRequest(res, "path must be set");
        }
        if (group.empty())
        {
            return BadRequest(res, "group must be set");
        }
        if (upgradetypename.empty())
        {
            return BadRequest(res, "upgradetypename must be set");
        }
        try {
            SET_CONTENT(ffijson::GetUpgradeGroupInfo(PARAMS(std::stoll(destructibleid), macroname.c_str(), path.c_str(), group.c_str(), upgradetypename.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetUpgradeGroupInfo2", HAN_FN {
        std::string destructibleid = req.get_param_value("destructibleid");
        std::string macroname = req.get_param_value("macroname");
        std::string contextid = req.get_param_value("contextid");
        std::string path = req.get_param_value("path");
        std::string group = req.get_param_value("group");
        std::string upgradetypename = req.get_param_value("upgradetypename");
        if (destructibleid.empty())
        {
            return BadRequest(res, "destructibleid must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        if (contextid.empty())
        {
            return BadRequest(res, "contextid must be set");
        }
        if (path.empty())
        {
            return BadRequest(res, "path must be set");
        }
        if (group.empty())
        {
            return BadRequest(res, "group must be set");
        }
        if (upgradetypename.empty())
        {
            return BadRequest(res, "upgradetypename must be set");
        }
        try {
            SET_CONTENT(ffijson::GetUpgradeGroupInfo2(PARAMS(std::stoll(destructibleid), macroname.c_str(), std::stoll(contextid), path.c_str(), group.c_str(), upgradetypename.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPrimaryWeapon", HAN_FN {
        std::string weaponnum = req.get_param_value("weaponnum");
        if (weaponnum.empty())
        {
            return BadRequest(res, "weaponnum must be set");
        }
        try {
            SET_CONTENT(ffijson::GetPrimaryWeapon(PARAMS(std::stoll(weaponnum))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetSecondaryWeapon", HAN_FN {
        std::string weaponnum = req.get_param_value("weaponnum");
        if (weaponnum.empty())
        {
            return BadRequest(res, "weaponnum must be set");
        }
        try {
            SET_CONTENT(ffijson::GetSecondaryWeapon(PARAMS(std::stoll(weaponnum))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetWorkForceInfo", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string raceid = req.get_param_value("raceid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (raceid.empty())
        {
            return BadRequest(res, "raceid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetWorkForceInfo(PARAMS(std::stoll(containerid), raceid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/AddAttackerToBoardingOperation", HAN_FN {
        std::string defensibletargetid = req.get_param_value("defensibletargetid");
        std::string defensibleboarderid = req.get_param_value("defensibleboarderid");
        std::string boarderfactionid = req.get_param_value("boarderfactionid");
        std::string actionid = req.get_param_value("actionid");
        std::string nummarinetiers = req.get_param_value("nummarinetiers");
        if (defensibletargetid.empty())
        {
            return BadRequest(res, "defensibletargetid must be set");
        }
        if (defensibleboarderid.empty())
        {
            return BadRequest(res, "defensibleboarderid must be set");
        }
        if (boarderfactionid.empty())
        {
            return BadRequest(res, "boarderfactionid must be set");
        }
        if (actionid.empty())
        {
            return BadRequest(res, "actionid must be set");
        }
        if (nummarinetiers.empty())
        {
            return BadRequest(res, "nummarinetiers must be set");
        }
        try {
            SET_CONTENT(ffijson::AddAttackerToBoardingOperation(PARAMS(std::stoll(defensibletargetid), std::stoll(defensibleboarderid), boarderfactionid.c_str(), actionid.c_str(), std::stoll(nummarinetiers))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/AdjustOrder", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string idx = req.get_param_value("idx");
        std::string newidx = req.get_param_value("newidx");
        std::string enabled = req.get_param_value("enabled");
        std::string forcestates = req.get_param_value("forcestates");
        std::string checkonly = req.get_param_value("checkonly");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (idx.empty())
        {
            return BadRequest(res, "idx must be set");
        }
        if (newidx.empty())
        {
            return BadRequest(res, "newidx must be set");
        }
        if (enabled.empty())
        {
            return BadRequest(res, "enabled must be set");
        }
        if (forcestates.empty())
        {
            return BadRequest(res, "forcestates must be set");
        }
        if (checkonly.empty())
        {
            return BadRequest(res, "checkonly must be set");
        }
        try {
            SET_CONTENT(ffijson::AdjustOrder(PARAMS(std::stoll(controllableid), std::stoll(idx), std::stoll(newidx), std::stoi(enabled), std::stoi(forcestates), std::stoi(checkonly))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/AreGfxSettingsTooHigh", HAN_FN {
        try {
            SET_CONTENT(ffijson::AreGfxSettingsTooHigh(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/AreMandatoryAssertsEnabled", HAN_FN {
        try {
            SET_CONTENT(ffijson::AreMandatoryAssertsEnabled(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/AreOptionalAssertEnabled", HAN_FN {
        try {
            SET_CONTENT(ffijson::AreOptionalAssertEnabled(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/CanAcceptSubordinate", HAN_FN {
        std::string commanderid = req.get_param_value("commanderid");
        std::string potentialsubordinateid = req.get_param_value("potentialsubordinateid");
        if (commanderid.empty())
        {
            return BadRequest(res, "commanderid must be set");
        }
        if (potentialsubordinateid.empty())
        {
            return BadRequest(res, "potentialsubordinateid must be set");
        }
        try {
            SET_CONTENT(ffijson::CanAcceptSubordinate(PARAMS(std::stoll(commanderid), std::stoll(potentialsubordinateid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/CanApplyKnownLoadout", HAN_FN {
        std::string macroname = req.get_param_value("macroname");
        std::string loadoutid = req.get_param_value("loadoutid");
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        if (loadoutid.empty())
        {
            return BadRequest(res, "loadoutid must be set");
        }
        try {
            SET_CONTENT(ffijson::CanApplyKnownLoadout(PARAMS(macroname.c_str(), loadoutid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/CanBuildLoadout", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string macroname = req.get_param_value("macroname");
        std::string loadoutid = req.get_param_value("loadoutid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        if (loadoutid.empty())
        {
            return BadRequest(res, "loadoutid must be set");
        }
        try {
            SET_CONTENT(ffijson::CanBuildLoadout(PARAMS(std::stoll(containerid), std::stoll(defensibleid), macroname.c_str(), loadoutid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/CanCancelConstruction", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string id = req.get_param_value("id");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        try {
            SET_CONTENT(ffijson::CanCancelConstruction(PARAMS(std::stoll(containerid), std::stoll(id))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/CanContainerEquipShip", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string shipid = req.get_param_value("shipid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (shipid.empty())
        {
            return BadRequest(res, "shipid must be set");
        }
        try {
            SET_CONTENT(ffijson::CanContainerEquipShip(PARAMS(std::stoll(containerid), std::stoll(shipid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/CanContainerMineTransport", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string transportname = req.get_param_value("transportname");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (transportname.empty())
        {
            return BadRequest(res, "transportname must be set");
        }
        try {
            SET_CONTENT(ffijson::CanContainerMineTransport(PARAMS(std::stoll(containerid), transportname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/CanContainerSupplyShip", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string shipid = req.get_param_value("shipid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (shipid.empty())
        {
            return BadRequest(res, "shipid must be set");
        }
        try {
            SET_CONTENT(ffijson::CanContainerSupplyShip(PARAMS(std::stoll(containerid), std::stoll(shipid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/CanContainerTransport", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string transportname = req.get_param_value("transportname");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (transportname.empty())
        {
            return BadRequest(res, "transportname must be set");
        }
        try {
            SET_CONTENT(ffijson::CanContainerTransport(PARAMS(std::stoll(containerid), transportname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/CanControllableHaveControlEntity", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string postid = req.get_param_value("postid");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (postid.empty())
        {
            return BadRequest(res, "postid must be set");
        }
        try {
            SET_CONTENT(ffijson::CanControllableHaveControlEntity(PARAMS(std::stoll(controllableid), postid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/CanGenerateValidKnownLoadout", HAN_FN {
        std::string macroname = req.get_param_value("macroname");
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        try {
            SET_CONTENT(ffijson::CanGenerateValidKnownLoadout(PARAMS(macroname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/CanGenerateValidLoadout", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string macroname = req.get_param_value("macroname");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        try {
            SET_CONTENT(ffijson::CanGenerateValidLoadout(PARAMS(std::stoll(containerid), macroname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/CanHaveCountermeasures", HAN_FN {
        try {
            SET_CONTENT(ffijson::CanHaveCountermeasures(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/CanOpenWebBrowser", HAN_FN {
        try {
            SET_CONTENT(ffijson::CanOpenWebBrowser(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/CanPlayerCommTarget", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::CanPlayerCommTarget(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/CanPlayerStandUp", HAN_FN {
        try {
            SET_CONTENT(ffijson::CanPlayerStandUp(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/CanRedoConstructionMapChange", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        try {
            SET_CONTENT(ffijson::CanRedoConstructionMapChange(PARAMS(std::stoll(holomapid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/CanStartTravelMode", HAN_FN {
        std::string objectid = req.get_param_value("objectid");
        if (objectid.empty())
        {
            return BadRequest(res, "objectid must be set");
        }
        try {
            SET_CONTENT(ffijson::CanStartTravelMode(PARAMS(std::stoll(objectid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/CanUndoConstructionMapChange", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        try {
            SET_CONTENT(ffijson::CanUndoConstructionMapChange(PARAMS(std::stoll(holomapid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/CancelConstruction", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string id = req.get_param_value("id");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        try {
            SET_CONTENT(ffijson::CancelConstruction(PARAMS(std::stoll(containerid), std::stoll(id))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/CheckWeaponModCompatibility", HAN_FN {
        std::string weaponid = req.get_param_value("weaponid");
        std::string wareid = req.get_param_value("wareid");
        if (weaponid.empty())
        {
            return BadRequest(res, "weaponid must be set");
        }
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        try {
            SET_CONTENT(ffijson::CheckWeaponModCompatibility(PARAMS(std::stoll(weaponid), wareid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/CompareMapConstructionSequenceWithPlanned", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string usestoredplan = req.get_param_value("usestoredplan");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (usestoredplan.empty())
        {
            return BadRequest(res, "usestoredplan must be set");
        }
        try {
            SET_CONTENT(ffijson::CompareMapConstructionSequenceWithPlanned(PARAMS(std::stoll(holomapid), std::stoll(defensibleid), std::stoi(usestoredplan))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/CopyToClipboard", HAN_FN {
        std::string text = req.get_param_value("text");
        if (text.empty())
        {
            return BadRequest(res, "text must be set");
        }
        try {
            SET_CONTENT(ffijson::CopyToClipboard(PARAMS(text.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/CreateBoardingOperation", HAN_FN {
        std::string defensibletargetid = req.get_param_value("defensibletargetid");
        std::string boarderfactionid = req.get_param_value("boarderfactionid");
        std::string approachthreshold = req.get_param_value("approachthreshold");
        std::string insertionthreshold = req.get_param_value("insertionthreshold");
        if (defensibletargetid.empty())
        {
            return BadRequest(res, "defensibletargetid must be set");
        }
        if (boarderfactionid.empty())
        {
            return BadRequest(res, "boarderfactionid must be set");
        }
        if (approachthreshold.empty())
        {
            return BadRequest(res, "approachthreshold must be set");
        }
        if (insertionthreshold.empty())
        {
            return BadRequest(res, "insertionthreshold must be set");
        }
        try {
            SET_CONTENT(ffijson::CreateBoardingOperation(PARAMS(std::stoll(defensibletargetid), boarderfactionid.c_str(), std::stoll(approachthreshold), std::stoll(insertionthreshold))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/DeleteSavegame", HAN_FN {
        std::string filename = req.get_param_value("filename");
        if (filename.empty())
        {
            return BadRequest(res, "filename must be set");
        }
        try {
            SET_CONTENT(ffijson::DeleteSavegame(PARAMS(filename.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/DoesMapConstructionSequenceRequireBuilder", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string usestoredplan = req.get_param_value("usestoredplan");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (usestoredplan.empty())
        {
            return BadRequest(res, "usestoredplan must be set");
        }
        try {
            SET_CONTENT(ffijson::DoesMapConstructionSequenceRequireBuilder(PARAMS(std::stoll(holomapid), std::stoll(defensibleid), std::stoi(usestoredplan))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/DropCargo", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string wareid = req.get_param_value("wareid");
        std::string amount = req.get_param_value("amount");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        if (amount.empty())
        {
            return BadRequest(res, "amount must be set");
        }
        try {
            SET_CONTENT(ffijson::DropCargo(PARAMS(std::stoll(containerid), wareid.c_str(), std::stoll(amount))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/DropInventory", HAN_FN {
        std::string entityid = req.get_param_value("entityid");
        std::string lockboxid = req.get_param_value("lockboxid");
        std::string numwares = req.get_param_value("numwares");
        if (entityid.empty())
        {
            return BadRequest(res, "entityid must be set");
        }
        if (lockboxid.empty())
        {
            return BadRequest(res, "lockboxid must be set");
        }
        if (numwares.empty())
        {
            return BadRequest(res, "numwares must be set");
        }
        try {
            SET_CONTENT(ffijson::DropInventory(PARAMS(std::stoll(entityid), lockboxid.c_str(), std::stoll(numwares))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/EnableOrder", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string idx = req.get_param_value("idx");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (idx.empty())
        {
            return BadRequest(res, "idx must be set");
        }
        try {
            SET_CONTENT(ffijson::EnableOrder(PARAMS(std::stoll(controllableid), std::stoll(idx))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/EnablePlannedDefaultOrder", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string checkonly = req.get_param_value("checkonly");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (checkonly.empty())
        {
            return BadRequest(res, "checkonly must be set");
        }
        try {
            SET_CONTENT(ffijson::EnablePlannedDefaultOrder(PARAMS(std::stoll(controllableid), std::stoi(checkonly))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAskToSignalForControllable", HAN_FN {
        std::string signalid = req.get_param_value("signalid");
        std::string controllableid = req.get_param_value("controllableid");
        if (signalid.empty())
        {
            return BadRequest(res, "signalid must be set");
        }
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetAskToSignalForControllable(PARAMS(signalid.c_str(), std::stoll(controllableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAskToSignalForFaction", HAN_FN {
        std::string signalid = req.get_param_value("signalid");
        std::string factionid = req.get_param_value("factionid");
        if (signalid.empty())
        {
            return BadRequest(res, "signalid must be set");
        }
        if (factionid.empty())
        {
            return BadRequest(res, "factionid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetAskToSignalForFaction(PARAMS(signalid.c_str(), factionid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetBoardingMarineTierAmountsFromAttacker", HAN_FN {
        std::string inputnummarinetiers = req.get_param_value("inputnummarinetiers");
        std::string defensibletargetid = req.get_param_value("defensibletargetid");
        std::string defensibleboarderid = req.get_param_value("defensibleboarderid");
        std::string boarderfactionid = req.get_param_value("boarderfactionid");
        if (inputnummarinetiers.empty())
        {
            return BadRequest(res, "inputnummarinetiers must be set");
        }
        if (defensibletargetid.empty())
        {
            return BadRequest(res, "defensibletargetid must be set");
        }
        if (defensibleboarderid.empty())
        {
            return BadRequest(res, "defensibleboarderid must be set");
        }
        if (boarderfactionid.empty())
        {
            return BadRequest(res, "boarderfactionid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetBoardingMarineTierAmountsFromAttacker(PARAMS(std::stoll(inputnummarinetiers), std::stoll(defensibletargetid), std::stoll(defensibleboarderid), boarderfactionid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetBoxTextBoxColor", HAN_FN {
        std::string boxtextid = req.get_param_value("boxtextid");
        if (boxtextid.empty())
        {
            return BadRequest(res, "boxtextid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetBoxTextBoxColor(PARAMS(std::stoi(boxtextid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetBoxTextInfo", HAN_FN {
        std::string boxtextid = req.get_param_value("boxtextid");
        if (boxtextid.empty())
        {
            return BadRequest(res, "boxtextid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetBoxTextInfo(PARAMS(std::stoi(boxtextid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetBuildMapStationLocation", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetBuildMapStationLocation(PARAMS(std::stoll(holomapid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetButtonHighlightColor", HAN_FN {
        std::string buttonid = req.get_param_value("buttonid");
        if (buttonid.empty())
        {
            return BadRequest(res, "buttonid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetButtonHighlightColor(PARAMS(std::stoi(buttonid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetButtonText2Details", HAN_FN {
        std::string buttonid = req.get_param_value("buttonid");
        if (buttonid.empty())
        {
            return BadRequest(res, "buttonid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetButtonText2Details(PARAMS(std::stoi(buttonid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCheckBoxColor", HAN_FN {
        std::string checkboxid = req.get_param_value("checkboxid");
        if (checkboxid.empty())
        {
            return BadRequest(res, "checkboxid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCheckBoxColor(PARAMS(std::stoi(checkboxid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetChromaticAberrationOption", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetChromaticAberrationOption(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetContainerWareIsBuyable", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string wareid = req.get_param_value("wareid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetContainerWareIsBuyable(PARAMS(std::stoll(containerid), wareid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetContainerWareIsSellable", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string wareid = req.get_param_value("wareid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetContainerWareIsSellable(PARAMS(std::stoll(containerid), wareid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCustomGameStartBoolProperty", HAN_FN {
        std::string id = req.get_param_value("id");
        std::string propertyid = req.get_param_value("propertyid");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (propertyid.empty())
        {
            return BadRequest(res, "propertyid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCustomGameStartBoolProperty(PARAMS(id.c_str(), propertyid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetDefaultOrder", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetDefaultOrder(PARAMS(std::stoll(controllableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetDropDownColor", HAN_FN {
        std::string dropdownid = req.get_param_value("dropdownid");
        if (dropdownid.empty())
        {
            return BadRequest(res, "dropdownid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetDropDownColor(PARAMS(std::stoi(dropdownid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetDropDownHighlightColor", HAN_FN {
        std::string dropdownid = req.get_param_value("dropdownid");
        if (dropdownid.empty())
        {
            return BadRequest(res, "dropdownid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetDropDownHighlightColor(PARAMS(std::stoi(dropdownid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetDropDownHotkeyDetails", HAN_FN {
        std::string dropdownid = req.get_param_value("dropdownid");
        if (dropdownid.empty())
        {
            return BadRequest(res, "dropdownid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetDropDownHotkeyDetails(PARAMS(std::stoi(dropdownid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetDropDownIconDetails", HAN_FN {
        std::string dropdownid = req.get_param_value("dropdownid");
        if (dropdownid.empty())
        {
            return BadRequest(res, "dropdownid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetDropDownIconDetails(PARAMS(std::stoi(dropdownid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetDropDownOptionColor", HAN_FN {
        std::string dropdownid = req.get_param_value("dropdownid");
        if (dropdownid.empty())
        {
            return BadRequest(res, "dropdownid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetDropDownOptionColor(PARAMS(std::stoi(dropdownid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetDropDownText2Details", HAN_FN {
        std::string dropdownid = req.get_param_value("dropdownid");
        if (dropdownid.empty())
        {
            return BadRequest(res, "dropdownid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetDropDownText2Details(PARAMS(std::stoi(dropdownid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetDropDownTextDetails", HAN_FN {
        std::string dropdownid = req.get_param_value("dropdownid");
        if (dropdownid.empty())
        {
            return BadRequest(res, "dropdownid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetDropDownTextDetails(PARAMS(std::stoi(dropdownid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetFontStringTitleColor", HAN_FN {
        std::string fontstringid = req.get_param_value("fontstringid");
        if (fontstringid.empty())
        {
            return BadRequest(res, "fontstringid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetFontStringTitleColor(PARAMS(std::stoi(fontstringid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetForceShootingAtCursorOption", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetForceShootingAtCursorOption(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetGraphBackgroundColor", HAN_FN {
        std::string graphid = req.get_param_value("graphid");
        if (graphid.empty())
        {
            return BadRequest(res, "graphid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetGraphBackgroundColor(PARAMS(std::stoi(graphid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetGraphTitle", HAN_FN {
        std::string graphid = req.get_param_value("graphid");
        if (graphid.empty())
        {
            return BadRequest(res, "graphid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetGraphTitle(PARAMS(std::stoi(graphid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetGraphXAxis", HAN_FN {
        std::string graphid = req.get_param_value("graphid");
        if (graphid.empty())
        {
            return BadRequest(res, "graphid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetGraphXAxis(PARAMS(std::stoi(graphid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetGraphYAxis", HAN_FN {
        std::string graphid = req.get_param_value("graphid");
        if (graphid.empty())
        {
            return BadRequest(res, "graphid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetGraphYAxis(PARAMS(std::stoi(graphid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetHUDSeparateRadar", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetHUDSeparateRadar(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetIconText2Details", HAN_FN {
        std::string iconid = req.get_param_value("iconid");
        if (iconid.empty())
        {
            return BadRequest(res, "iconid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetIconText2Details(PARAMS(std::stoi(iconid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetIconTextDetails", HAN_FN {
        std::string iconid = req.get_param_value("iconid");
        if (iconid.empty())
        {
            return BadRequest(res, "iconid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetIconTextDetails(PARAMS(std::stoi(iconid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetInstalledEngineMod", HAN_FN {
        std::string objectid = req.get_param_value("objectid");
        if (objectid.empty())
        {
            return BadRequest(res, "objectid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetInstalledEngineMod(PARAMS(std::stoll(objectid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetInstalledGroupedWeaponMod", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string contextid = req.get_param_value("contextid");
        std::string group = req.get_param_value("group");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (contextid.empty())
        {
            return BadRequest(res, "contextid must be set");
        }
        if (group.empty())
        {
            return BadRequest(res, "group must be set");
        }
        try {
            SET_CONTENT(ffijson::GetInstalledGroupedWeaponMod(PARAMS(std::stoll(defensibleid), std::stoll(contextid), group.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetInstalledPaintMod", HAN_FN {
        std::string objectid = req.get_param_value("objectid");
        if (objectid.empty())
        {
            return BadRequest(res, "objectid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetInstalledPaintMod(PARAMS(std::stoll(objectid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetInstalledShieldMod", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string contextid = req.get_param_value("contextid");
        std::string group = req.get_param_value("group");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (contextid.empty())
        {
            return BadRequest(res, "contextid must be set");
        }
        if (group.empty())
        {
            return BadRequest(res, "group must be set");
        }
        try {
            SET_CONTENT(ffijson::GetInstalledShieldMod(PARAMS(std::stoll(defensibleid), std::stoll(contextid), group.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetInstalledShipMod", HAN_FN {
        std::string shipid = req.get_param_value("shipid");
        if (shipid.empty())
        {
            return BadRequest(res, "shipid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetInstalledShipMod(PARAMS(std::stoll(shipid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetInstalledWeaponMod", HAN_FN {
        std::string weaponid = req.get_param_value("weaponid");
        if (weaponid.empty())
        {
            return BadRequest(res, "weaponid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetInstalledWeaponMod(PARAMS(std::stoll(weaponid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetLicenceInfo", HAN_FN {
        std::string factionid = req.get_param_value("factionid");
        std::string licenceid = req.get_param_value("licenceid");
        if (factionid.empty())
        {
            return BadRequest(res, "factionid must be set");
        }
        if (licenceid.empty())
        {
            return BadRequest(res, "licenceid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetLicenceInfo(PARAMS(factionid.c_str(), licenceid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetMouseOverTextOption", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetMouseOverTextOption(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetMouseSteeringInvertedOption", HAN_FN {
        std::string paramname = req.get_param_value("paramname");
        if (paramname.empty())
        {
            return BadRequest(res, "paramname must be set");
        }
        try {
            SET_CONTENT(ffijson::GetMouseSteeringInvertedOption(PARAMS(paramname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetOrderDefinition", HAN_FN {
        std::string orderdef = req.get_param_value("orderdef");
        if (orderdef.empty())
        {
            return BadRequest(res, "orderdef must be set");
        }
        try {
            SET_CONTENT(ffijson::GetOrderDefinition(PARAMS(orderdef.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPickedBuildMapEntry", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string defensibleid = req.get_param_value("defensibleid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetPickedBuildMapEntry(PARAMS(std::stoll(holomapid), std::stoll(defensibleid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPickedMapMacroSlot", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string moduleid = req.get_param_value("moduleid");
        std::string macroname = req.get_param_value("macroname");
        std::string ismodule = req.get_param_value("ismodule");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (moduleid.empty())
        {
            return BadRequest(res, "moduleid must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        if (ismodule.empty())
        {
            return BadRequest(res, "ismodule must be set");
        }
        try {
            SET_CONTENT(ffijson::GetPickedMapMacroSlot(PARAMS(std::stoll(holomapid), std::stoll(defensibleid), std::stoll(moduleid), macroname.c_str(), std::stoi(ismodule))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPlannedDefaultOrder", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetPlannedDefaultOrder(PARAMS(std::stoll(controllableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPlayerPaintThemeMod", HAN_FN {
        std::string objectid = req.get_param_value("objectid");
        std::string macroname = req.get_param_value("macroname");
        if (objectid.empty())
        {
            return BadRequest(res, "objectid must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        try {
            SET_CONTENT(ffijson::GetPlayerPaintThemeMod(PARAMS(std::stoll(objectid), macroname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetSavesCompressedOption", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetSavesCompressedOption(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetScreenDisplayOption", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetScreenDisplayOption(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetShieldGroup", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string destructibleid = req.get_param_value("destructibleid");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (destructibleid.empty())
        {
            return BadRequest(res, "destructibleid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetShieldGroup(PARAMS(std::stoll(defensibleid), std::stoll(destructibleid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetSliderCellBackgroundColor", HAN_FN {
        std::string slidercellid = req.get_param_value("slidercellid");
        if (slidercellid.empty())
        {
            return BadRequest(res, "slidercellid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetSliderCellBackgroundColor(PARAMS(std::stoi(slidercellid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetSliderCellFont", HAN_FN {
        std::string slidercellid = req.get_param_value("slidercellid");
        if (slidercellid.empty())
        {
            return BadRequest(res, "slidercellid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetSliderCellFont(PARAMS(std::stoi(slidercellid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetSliderCellInactiveBackgroundColor", HAN_FN {
        std::string slidercellid = req.get_param_value("slidercellid");
        if (slidercellid.empty())
        {
            return BadRequest(res, "slidercellid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetSliderCellInactiveBackgroundColor(PARAMS(std::stoi(slidercellid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetSliderCellNegativeValueColor", HAN_FN {
        std::string slidercellid = req.get_param_value("slidercellid");
        if (slidercellid.empty())
        {
            return BadRequest(res, "slidercellid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetSliderCellNegativeValueColor(PARAMS(std::stoi(slidercellid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetSliderCellTextColor", HAN_FN {
        std::string slidercellid = req.get_param_value("slidercellid");
        if (slidercellid.empty())
        {
            return BadRequest(res, "slidercellid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetSliderCellTextColor(PARAMS(std::stoi(slidercellid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetSliderCellValueColor", HAN_FN {
        std::string slidercellid = req.get_param_value("slidercellid");
        if (slidercellid.empty())
        {
            return BadRequest(res, "slidercellid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetSliderCellValueColor(PARAMS(std::stoi(slidercellid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetSliderCellValues", HAN_FN {
        std::string slidercellid = req.get_param_value("slidercellid");
        if (slidercellid.empty())
        {
            return BadRequest(res, "slidercellid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetSliderCellValues(PARAMS(std::stoi(slidercellid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetSpeakTargetNameOption", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetSpeakTargetNameOption(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetStatusBarMarkerColor", HAN_FN {
        std::string statusbarid = req.get_param_value("statusbarid");
        if (statusbarid.empty())
        {
            return BadRequest(res, "statusbarid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetStatusBarMarkerColor(PARAMS(std::stoi(statusbarid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetStatusBarNegChangeColor", HAN_FN {
        std::string statusbarid = req.get_param_value("statusbarid");
        if (statusbarid.empty())
        {
            return BadRequest(res, "statusbarid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetStatusBarNegChangeColor(PARAMS(std::stoi(statusbarid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetStatusBarPosChangeColor", HAN_FN {
        std::string statusbarid = req.get_param_value("statusbarid");
        if (statusbarid.empty())
        {
            return BadRequest(res, "statusbarid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetStatusBarPosChangeColor(PARAMS(std::stoi(statusbarid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetStatusBarValueColor", HAN_FN {
        std::string statusbarid = req.get_param_value("statusbarid");
        if (statusbarid.empty())
        {
            return BadRequest(res, "statusbarid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetStatusBarValueColor(PARAMS(std::stoi(statusbarid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetSyncPointInfo", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string orderidx = req.get_param_value("orderidx");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (orderidx.empty())
        {
            return BadRequest(res, "orderidx must be set");
        }
        try {
            SET_CONTENT(ffijson::GetSyncPointInfo(PARAMS(std::stoll(controllableid), std::stoll(orderidx))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetTableBackgroundColor", HAN_FN {
        std::string tableid = req.get_param_value("tableid");
        if (tableid.empty())
        {
            return BadRequest(res, "tableid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetTableBackgroundColor(PARAMS(std::stoi(tableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetUISystemInfo", HAN_FN {
        std::string clusterid = req.get_param_value("clusterid");
        if (clusterid.empty())
        {
            return BadRequest(res, "clusterid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetUISystemInfo(PARAMS(std::stoll(clusterid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetUp", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetUp(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetVentureOption", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetVentureOption(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetVisitorNamesShownOption", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetVisitorNamesShownOption(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/HasContainerBuyLimitOverride", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string wareid = req.get_param_value("wareid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        try {
            SET_CONTENT(ffijson::HasContainerBuyLimitOverride(PARAMS(std::stoll(containerid), wareid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/HasContainerSellLimitOverride", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string wareid = req.get_param_value("wareid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        try {
            SET_CONTENT(ffijson::HasContainerSellLimitOverride(PARAMS(std::stoll(containerid), wareid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/HasControllableOwnBlacklist", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string listtype = req.get_param_value("listtype");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (listtype.empty())
        {
            return BadRequest(res, "listtype must be set");
        }
        try {
            SET_CONTENT(ffijson::HasControllableOwnBlacklist(PARAMS(std::stoll(controllableid), listtype.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/HasControllableOwnResponse", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string signalid = req.get_param_value("signalid");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (signalid.empty())
        {
            return BadRequest(res, "signalid must be set");
        }
        try {
            SET_CONTENT(ffijson::HasControllableOwnResponse(PARAMS(std::stoll(controllableid), signalid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/HasDefaultLoadout", HAN_FN {
        std::string macroname = req.get_param_value("macroname");
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        try {
            SET_CONTENT(ffijson::HasDefaultLoadout(PARAMS(macroname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/HasEntityMoneyLogEntries", HAN_FN {
        std::string entityid = req.get_param_value("entityid");
        if (entityid.empty())
        {
            return BadRequest(res, "entityid must be set");
        }
        try {
            SET_CONTENT(ffijson::HasEntityMoneyLogEntries(PARAMS(std::stoll(entityid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/HasExtension", HAN_FN {
        std::string extensionid = req.get_param_value("extensionid");
        std::string personal = req.get_param_value("personal");
        if (extensionid.empty())
        {
            return BadRequest(res, "extensionid must be set");
        }
        if (personal.empty())
        {
            return BadRequest(res, "personal must be set");
        }
        try {
            SET_CONTENT(ffijson::HasExtension(PARAMS(extensionid.c_str(), std::stoi(personal))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/HasFrameBrackets", HAN_FN {
        std::string frameid = req.get_param_value("frameid");
        if (frameid.empty())
        {
            return BadRequest(res, "frameid must be set");
        }
        try {
            SET_CONTENT(ffijson::HasFrameBrackets(PARAMS(std::stoi(frameid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/HasLimitedOxygenSupply", HAN_FN {
        try {
            SET_CONTENT(ffijson::HasLimitedOxygenSupply(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/HasResearched", HAN_FN {
        std::string wareid = req.get_param_value("wareid");
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        try {
            SET_CONTENT(ffijson::HasResearched(PARAMS(wareid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/HasSavegame", HAN_FN {
        try {
            SET_CONTENT(ffijson::HasSavegame(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/HasSeta", HAN_FN {
        try {
            SET_CONTENT(ffijson::HasSeta(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/HasShipFlightAssist", HAN_FN {
        std::string shipid = req.get_param_value("shipid");
        if (shipid.empty())
        {
            return BadRequest(res, "shipid must be set");
        }
        try {
            SET_CONTENT(ffijson::HasShipFlightAssist(PARAMS(std::stoll(shipid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/HasStartAnimation", HAN_FN {
        try {
            SET_CONTENT(ffijson::HasStartAnimation(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/HasVenturerDock", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string shipid = req.get_param_value("shipid");
        std::string ventureplatformid = req.get_param_value("ventureplatformid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (shipid.empty())
        {
            return BadRequest(res, "shipid must be set");
        }
        if (ventureplatformid.empty())
        {
            return BadRequest(res, "ventureplatformid must be set");
        }
        try {
            SET_CONTENT(ffijson::HasVenturerDock(PARAMS(std::stoll(containerid), std::stoll(shipid), std::stoll(ventureplatformid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/InstallEngineMod", HAN_FN {
        std::string objectid = req.get_param_value("objectid");
        std::string wareid = req.get_param_value("wareid");
        if (objectid.empty())
        {
            return BadRequest(res, "objectid must be set");
        }
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        try {
            SET_CONTENT(ffijson::InstallEngineMod(PARAMS(std::stoll(objectid), wareid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/InstallGroupedWeaponMod", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string contextid = req.get_param_value("contextid");
        std::string group = req.get_param_value("group");
        std::string wareid = req.get_param_value("wareid");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (contextid.empty())
        {
            return BadRequest(res, "contextid must be set");
        }
        if (group.empty())
        {
            return BadRequest(res, "group must be set");
        }
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        try {
            SET_CONTENT(ffijson::InstallGroupedWeaponMod(PARAMS(std::stoll(defensibleid), std::stoll(contextid), group.c_str(), wareid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/InstallPaintMod", HAN_FN {
        std::string objectid = req.get_param_value("objectid");
        std::string wareid = req.get_param_value("wareid");
        std::string useinventory = req.get_param_value("useinventory");
        if (objectid.empty())
        {
            return BadRequest(res, "objectid must be set");
        }
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        if (useinventory.empty())
        {
            return BadRequest(res, "useinventory must be set");
        }
        try {
            SET_CONTENT(ffijson::InstallPaintMod(PARAMS(std::stoll(objectid), wareid.c_str(), std::stoi(useinventory))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/InstallShieldMod", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string contextid = req.get_param_value("contextid");
        std::string group = req.get_param_value("group");
        std::string wareid = req.get_param_value("wareid");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (contextid.empty())
        {
            return BadRequest(res, "contextid must be set");
        }
        if (group.empty())
        {
            return BadRequest(res, "group must be set");
        }
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        try {
            SET_CONTENT(ffijson::InstallShieldMod(PARAMS(std::stoll(defensibleid), std::stoll(contextid), group.c_str(), wareid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/InstallShipMod", HAN_FN {
        std::string shipid = req.get_param_value("shipid");
        std::string wareid = req.get_param_value("wareid");
        if (shipid.empty())
        {
            return BadRequest(res, "shipid must be set");
        }
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        try {
            SET_CONTENT(ffijson::InstallShipMod(PARAMS(std::stoll(shipid), wareid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/InstallWeaponMod", HAN_FN {
        std::string weaponid = req.get_param_value("weaponid");
        std::string wareid = req.get_param_value("wareid");
        if (weaponid.empty())
        {
            return BadRequest(res, "weaponid must be set");
        }
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        try {
            SET_CONTENT(ffijson::InstallWeaponMod(PARAMS(std::stoll(weaponid), wareid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsAAOptionSupported", HAN_FN {
        std::string mode = req.get_param_value("mode");
        if (mode.empty())
        {
            return BadRequest(res, "mode must be set");
        }
        try {
            SET_CONTENT(ffijson::IsAAOptionSupported(PARAMS(mode.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsAdvancedSatellite", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsAdvancedSatellite(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsAmmoMacroCompatible", HAN_FN {
        std::string weaponmacroname = req.get_param_value("weaponmacroname");
        std::string ammomacroname = req.get_param_value("ammomacroname");
        if (weaponmacroname.empty())
        {
            return BadRequest(res, "weaponmacroname must be set");
        }
        if (ammomacroname.empty())
        {
            return BadRequest(res, "ammomacroname must be set");
        }
        try {
            SET_CONTENT(ffijson::IsAmmoMacroCompatible(PARAMS(weaponmacroname.c_str(), ammomacroname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsAppStoreVersion", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsAppStoreVersion(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsAsteroid", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsAsteroid(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsAutotargetingActive", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsAutotargetingActive(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsBomb", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsBomb(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsBoxTextWordWrap", HAN_FN {
        std::string boxtextid = req.get_param_value("boxtextid");
        if (boxtextid.empty())
        {
            return BadRequest(res, "boxtextid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsBoxTextWordWrap(PARAMS(std::stoi(boxtextid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsBuilderBusy", HAN_FN {
        std::string shipid = req.get_param_value("shipid");
        if (shipid.empty())
        {
            return BadRequest(res, "shipid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsBuilderBusy(PARAMS(std::stoll(shipid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsCheckBoxActive", HAN_FN {
        std::string checkboxid = req.get_param_value("checkboxid");
        if (checkboxid.empty())
        {
            return BadRequest(res, "checkboxid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsCheckBoxActive(PARAMS(std::stoi(checkboxid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsCheckBoxChecked", HAN_FN {
        std::string checkboxid = req.get_param_value("checkboxid");
        if (checkboxid.empty())
        {
            return BadRequest(res, "checkboxid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsCheckBoxChecked(PARAMS(std::stoi(checkboxid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsCollectable", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsCollectable(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsCommander", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsCommander(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsComponentClass", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        std::string classname = req.get_param_value("classname");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        if (classname.empty())
        {
            return BadRequest(res, "classname must be set");
        }
        try {
            SET_CONTENT(ffijson::IsComponentClass(PARAMS(std::stoll(componentid), classname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsComponentOperational", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsComponentOperational(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsComponentWrecked", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsComponentWrecked(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsConstructionPlanValid", HAN_FN {
        std::string constructionplanid = req.get_param_value("constructionplanid");
        if (constructionplanid.empty())
        {
            return BadRequest(res, "constructionplanid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsConstructionPlanValid(PARAMS(constructionplanid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsContainerAmmoMacroCompatible", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string ammomacroname = req.get_param_value("ammomacroname");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (ammomacroname.empty())
        {
            return BadRequest(res, "ammomacroname must be set");
        }
        try {
            SET_CONTENT(ffijson::IsContainerAmmoMacroCompatible(PARAMS(std::stoll(containerid), ammomacroname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsContainerFactionBuildRescricted", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsContainerFactionBuildRescricted(PARAMS(std::stoll(containerid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsContainerFactionTradeRescricted", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string wareid = req.get_param_value("wareid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsContainerFactionTradeRescricted(PARAMS(std::stoll(containerid), wareid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsContestedSector", HAN_FN {
        std::string sectorid = req.get_param_value("sectorid");
        if (sectorid.empty())
        {
            return BadRequest(res, "sectorid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsContestedSector(PARAMS(std::stoll(sectorid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsControlPressed", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsControlPressed(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsConversationActive", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsConversationActive(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsCrate", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsCrate(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsCrystal", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsCrystal(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsCurrentGPUDiscrete", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsCurrentGPUDiscrete(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsCurrentOrderCritical", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsCurrentOrderCritical(PARAMS(std::stoll(controllableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsCurrentlyScanning", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsCurrentlyScanning(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsCustomGameStartPropertyChanged", HAN_FN {
        std::string id = req.get_param_value("id");
        std::string propertyid = req.get_param_value("propertyid");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (propertyid.empty())
        {
            return BadRequest(res, "propertyid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsCustomGameStartPropertyChanged(PARAMS(id.c_str(), propertyid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsDefensibleBeingBoardedBy", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string factionid = req.get_param_value("factionid");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (factionid.empty())
        {
            return BadRequest(res, "factionid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsDefensibleBeingBoardedBy(PARAMS(std::stoll(defensibleid), factionid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsDemoVersion", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsDemoVersion(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsDeployableMacroCompatible", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string macroname = req.get_param_value("macroname");
        std::string deployablemacroname = req.get_param_value("deployablemacroname");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        if (deployablemacroname.empty())
        {
            return BadRequest(res, "deployablemacroname must be set");
        }
        try {
            SET_CONTENT(ffijson::IsDeployableMacroCompatible(PARAMS(std::stoll(containerid), macroname.c_str(), deployablemacroname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsDestructible2", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        std::string connectionname = req.get_param_value("connectionname");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsDestructible2(PARAMS(std::stoll(componentid), connectionname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsDetailUIElement", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        std::string connectionname = req.get_param_value("connectionname");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsDetailUIElement(PARAMS(std::stoll(componentid), connectionname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsDroneTypeArmed", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string dronetype = req.get_param_value("dronetype");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (dronetype.empty())
        {
            return BadRequest(res, "dronetype must be set");
        }
        try {
            SET_CONTENT(ffijson::IsDroneTypeArmed(PARAMS(std::stoll(defensibleid), dronetype.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsDroneTypeBlocked", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string dronetype = req.get_param_value("dronetype");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (dronetype.empty())
        {
            return BadRequest(res, "dronetype must be set");
        }
        try {
            SET_CONTENT(ffijson::IsDroneTypeBlocked(PARAMS(std::stoll(defensibleid), dronetype.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsDropDownActive", HAN_FN {
        std::string dropdownid = req.get_param_value("dropdownid");
        if (dropdownid.empty())
        {
            return BadRequest(res, "dropdownid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsDropDownActive(PARAMS(std::stoi(dropdownid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsDropDownMouseOverInteractionAllowed", HAN_FN {
        std::string dropdownid = req.get_param_value("dropdownid");
        if (dropdownid.empty())
        {
            return BadRequest(res, "dropdownid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsDropDownMouseOverInteractionAllowed(PARAMS(std::stoi(dropdownid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsEditBoxActive", HAN_FN {
        std::string editboxid = req.get_param_value("editboxid");
        if (editboxid.empty())
        {
            return BadRequest(res, "editboxid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsEditBoxActive(PARAMS(std::stoi(editboxid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsEditBoxInputEncrypted", HAN_FN {
        std::string editboxid = req.get_param_value("editboxid");
        if (editboxid.empty())
        {
            return BadRequest(res, "editboxid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsEditBoxInputEncrypted(PARAMS(std::stoi(editboxid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsEditBoxTextHidden", HAN_FN {
        std::string editboxid = req.get_param_value("editboxid");
        if (editboxid.empty())
        {
            return BadRequest(res, "editboxid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsEditBoxTextHidden(PARAMS(std::stoi(editboxid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsEditBoxTextSelectedOnActivation", HAN_FN {
        std::string editboxid = req.get_param_value("editboxid");
        if (editboxid.empty())
        {
            return BadRequest(res, "editboxid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsEditBoxTextSelectedOnActivation(PARAMS(std::stoi(editboxid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsEntity", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsEntity(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsErrorLogActive", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsErrorLogActive(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsExternalTargetMode", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsExternalTargetMode(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsExternalViewActive", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsExternalViewActive(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsFPSEnabled", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsFPSEnabled(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsFactionAllyToFaction", HAN_FN {
        std::string factionid = req.get_param_value("factionid");
        std::string otherfactionid = req.get_param_value("otherfactionid");
        if (factionid.empty())
        {
            return BadRequest(res, "factionid must be set");
        }
        if (otherfactionid.empty())
        {
            return BadRequest(res, "otherfactionid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsFactionAllyToFaction(PARAMS(factionid.c_str(), otherfactionid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsFactionEnemyToFaction", HAN_FN {
        std::string factionid = req.get_param_value("factionid");
        std::string otherfactionid = req.get_param_value("otherfactionid");
        if (factionid.empty())
        {
            return BadRequest(res, "factionid must be set");
        }
        if (otherfactionid.empty())
        {
            return BadRequest(res, "otherfactionid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsFactionEnemyToFaction(PARAMS(factionid.c_str(), otherfactionid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsFactionHQ", HAN_FN {
        std::string stationid = req.get_param_value("stationid");
        if (stationid.empty())
        {
            return BadRequest(res, "stationid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsFactionHQ(PARAMS(std::stoll(stationid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsFullscreenMenuDisplayed", HAN_FN {
        std::string anymenu = req.get_param_value("anymenu");
        std::string menuname = req.get_param_value("menuname");
        if (anymenu.empty())
        {
            return BadRequest(res, "anymenu must be set");
        }
        if (menuname.empty())
        {
            return BadRequest(res, "menuname must be set");
        }
        try {
            SET_CONTENT(ffijson::IsFullscreenMenuDisplayed(PARAMS(std::stoi(anymenu), menuname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsGOGVersion", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsGOGVersion(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsGameModified", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsGameModified(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsGamePaused", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsGamePaused(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsHQ", HAN_FN {
        std::string stationid = req.get_param_value("stationid");
        if (stationid.empty())
        {
            return BadRequest(res, "stationid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsHQ(PARAMS(std::stoll(stationid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsHUDActive", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsHUDActive(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsHUDRadarActive", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsHUDRadarActive(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsIconValid", HAN_FN {
        std::string iconid = req.get_param_value("iconid");
        if (iconid.empty())
        {
            return BadRequest(res, "iconid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsIconValid(PARAMS(iconid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsInfoUnlockedForPlayer", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        std::string infostring = req.get_param_value("infostring");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        if (infostring.empty())
        {
            return BadRequest(res, "infostring must be set");
        }
        try {
            SET_CONTENT(ffijson::IsInfoUnlockedForPlayer(PARAMS(std::stoll(componentid), infostring.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsJoystickSteeringAdapative", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsJoystickSteeringAdapative(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsKnownItemRead", HAN_FN {
        std::string libraryid = req.get_param_value("libraryid");
        std::string itemid = req.get_param_value("itemid");
        if (libraryid.empty())
        {
            return BadRequest(res, "libraryid must be set");
        }
        if (itemid.empty())
        {
            return BadRequest(res, "itemid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsKnownItemRead(PARAMS(libraryid.c_str(), itemid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsKnownRead", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsKnownRead(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsKnownToPlayer", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsKnownToPlayer(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsLanguageSettingEnabled", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsLanguageSettingEnabled(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsLanguageValid", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsLanguageValid(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsLaserTower", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsLaserTower(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsLeftMouseButtonDown", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsLeftMouseButtonDown(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsLoadoutValid", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string macroname = req.get_param_value("macroname");
        std::string loadoutid = req.get_param_value("loadoutid");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        if (loadoutid.empty())
        {
            return BadRequest(res, "loadoutid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsLoadoutValid(PARAMS(std::stoll(defensibleid), macroname.c_str(), loadoutid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsLockbox", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsLockbox(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsLowOnOxygen", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsLowOnOxygen(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsMasterVersion", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsMasterVersion(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsMiniWidgetSystemUsed", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsMiniWidgetSystemUsed(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsMissileIncoming", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsMissileIncoming(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsMissileLockingOn", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsMissileLockingOn(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsMouseDoubleClickMode", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsMouseDoubleClickMode(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsMouseEmulationActive", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsMouseEmulationActive(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsMouseSteeringAdapative", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsMouseSteeringAdapative(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsNavBeacon", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsNavBeacon(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsNetworkEngineEnabled", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsNetworkEngineEnabled(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsNextStartAnimationSkipped", HAN_FN {
        std::string reset = req.get_param_value("reset");
        if (reset.empty())
        {
            return BadRequest(res, "reset must be set");
        }
        try {
            SET_CONTENT(ffijson::IsNextStartAnimationSkipped(PARAMS(std::stoi(reset))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsObjectKnown", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsObjectKnown(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsOnlineEnabled", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsOnlineEnabled(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsOrderSelectableFor", HAN_FN {
        std::string orderdefid = req.get_param_value("orderdefid");
        std::string controllableid = req.get_param_value("controllableid");
        if (orderdefid.empty())
        {
            return BadRequest(res, "orderdefid must be set");
        }
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsOrderSelectableFor(PARAMS(orderdefid.c_str(), std::stoll(controllableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsPerson", HAN_FN {
        std::string person = req.get_param_value("person");
        std::string controllableid = req.get_param_value("controllableid");
        if (person.empty())
        {
            return BadRequest(res, "person must be set");
        }
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsPerson(PARAMS(std::stoll(person), std::stoll(controllableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsPersonTransferScheduled", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string person = req.get_param_value("person");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (person.empty())
        {
            return BadRequest(res, "person must be set");
        }
        try {
            SET_CONTENT(ffijson::IsPersonTransferScheduled(PARAMS(std::stoll(controllableid), std::stoll(person))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsPlayerBlacklistDefault", HAN_FN {
        std::string id = req.get_param_value("id");
        std::string listtype = req.get_param_value("listtype");
        std::string defaultgroup = req.get_param_value("defaultgroup");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (listtype.empty())
        {
            return BadRequest(res, "listtype must be set");
        }
        if (defaultgroup.empty())
        {
            return BadRequest(res, "defaultgroup must be set");
        }
        try {
            SET_CONTENT(ffijson::IsPlayerBlacklistDefault(PARAMS(std::stoll(id), listtype.c_str(), defaultgroup.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsPlayerCameraTargetViewPossible", HAN_FN {
        std::string targetid = req.get_param_value("targetid");
        std::string force = req.get_param_value("force");
        if (targetid.empty())
        {
            return BadRequest(res, "targetid must be set");
        }
        if (force.empty())
        {
            return BadRequest(res, "force must be set");
        }
        try {
            SET_CONTENT(ffijson::IsPlayerCameraTargetViewPossible(PARAMS(std::stoll(targetid), std::stoi(force))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsPlayerValid", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsPlayerValid(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsPointingWithinAimingRange", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsPointingWithinAimingRange(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsPresentModeOptionSupported", HAN_FN {
        std::string mode = req.get_param_value("mode");
        if (mode.empty())
        {
            return BadRequest(res, "mode must be set");
        }
        try {
            SET_CONTENT(ffijson::IsPresentModeOptionSupported(PARAMS(mode.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsRealComponentClass", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        std::string classname = req.get_param_value("classname");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        if (classname.empty())
        {
            return BadRequest(res, "classname must be set");
        }
        try {
            SET_CONTENT(ffijson::IsRealComponentClass(PARAMS(std::stoll(componentid), classname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsResourceProbe", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsResourceProbe(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsSatellite", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsSatellite(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsSaveListLoadingComplete", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsSaveListLoadingComplete(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsSaveValid", HAN_FN {
        std::string filename = req.get_param_value("filename");
        if (filename.empty())
        {
            return BadRequest(res, "filename must be set");
        }
        try {
            SET_CONTENT(ffijson::IsSaveValid(PARAMS(filename.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsSetaActive", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsSetaActive(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsShiftPressed", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsShiftPressed(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsShip", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsShip(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsShipAtExternalDock", HAN_FN {
        std::string shipid = req.get_param_value("shipid");
        if (shipid.empty())
        {
            return BadRequest(res, "shipid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsShipAtExternalDock(PARAMS(std::stoll(shipid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsShipBeingRetrieved", HAN_FN {
        std::string shipid = req.get_param_value("shipid");
        if (shipid.empty())
        {
            return BadRequest(res, "shipid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsShipBeingRetrieved(PARAMS(std::stoll(shipid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsSofttargetManagerActive", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsSofttargetManagerActive(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsSoftwareDefault", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string macroname = req.get_param_value("macroname");
        std::string softwarename = req.get_param_value("softwarename");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        if (softwarename.empty())
        {
            return BadRequest(res, "softwarename must be set");
        }
        try {
            SET_CONTENT(ffijson::IsSoftwareDefault(PARAMS(std::stoll(controllableid), macroname.c_str(), softwarename.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsStartmenu", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsStartmenu(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsStation", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsStation(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsStationary", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsStationary(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsSupplyManual", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string type = req.get_param_value("type");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (type.empty())
        {
            return BadRequest(res, "type must be set");
        }
        try {
            SET_CONTENT(ffijson::IsSupplyManual(PARAMS(std::stoll(containerid), type.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsSurfaceElement", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsSurfaceElement(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsTableMultiSelect", HAN_FN {
        std::string tableid = req.get_param_value("tableid");
        if (tableid.empty())
        {
            return BadRequest(res, "tableid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsTableMultiSelect(PARAMS(std::stoi(tableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsTableRowBorderBelowEnabled", HAN_FN {
        std::string tableid = req.get_param_value("tableid");
        std::string row = req.get_param_value("row");
        if (tableid.empty())
        {
            return BadRequest(res, "tableid must be set");
        }
        if (row.empty())
        {
            return BadRequest(res, "row must be set");
        }
        try {
            SET_CONTENT(ffijson::IsTableRowBorderBelowEnabled(PARAMS(std::stoi(tableid), std::stoll(row))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsTargetInPlayerWeaponRange", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsTargetInPlayerWeaponRange(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsTargetMonitorNotification", HAN_FN {
        std::string notificationid = req.get_param_value("notificationid");
        if (notificationid.empty())
        {
            return BadRequest(res, "notificationid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsTargetMonitorNotification(PARAMS(std::stoi(notificationid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsTargetable", HAN_FN {
        std::string messageid = req.get_param_value("messageid");
        if (messageid.empty())
        {
            return BadRequest(res, "messageid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsTargetable(PARAMS(std::stoll(messageid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsThrottleBidirectional", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsThrottleBidirectional(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsTitleFontString", HAN_FN {
        std::string fontstringid = req.get_param_value("fontstringid");
        if (fontstringid.empty())
        {
            return BadRequest(res, "fontstringid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsTitleFontString(PARAMS(std::stoi(fontstringid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsTobiiAvailable", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsTobiiAvailable(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsTradeShowVersion", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsTradeShowVersion(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsTurretGroupArmed", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string contextid = req.get_param_value("contextid");
        std::string path = req.get_param_value("path");
        std::string group = req.get_param_value("group");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (contextid.empty())
        {
            return BadRequest(res, "contextid must be set");
        }
        if (path.empty())
        {
            return BadRequest(res, "path must be set");
        }
        if (group.empty())
        {
            return BadRequest(res, "group must be set");
        }
        try {
            SET_CONTENT(ffijson::IsTurretGroupArmed(PARAMS(std::stoll(defensibleid), std::stoll(contextid), path.c_str(), group.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsUnit", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsUnit(PARAMS(std::stoll(controllableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsUnitMacroCompatible", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string macroname = req.get_param_value("macroname");
        std::string unitmacroname = req.get_param_value("unitmacroname");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        if (unitmacroname.empty())
        {
            return BadRequest(res, "unitmacroname must be set");
        }
        try {
            SET_CONTENT(ffijson::IsUnitMacroCompatible(PARAMS(std::stoll(containerid), macroname.c_str(), unitmacroname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsUpgradeGroupMacroCompatible", HAN_FN {
        std::string destructibleid = req.get_param_value("destructibleid");
        std::string macroname = req.get_param_value("macroname");
        std::string path = req.get_param_value("path");
        std::string group = req.get_param_value("group");
        std::string upgradetypename = req.get_param_value("upgradetypename");
        std::string upgrademacroname = req.get_param_value("upgrademacroname");
        if (destructibleid.empty())
        {
            return BadRequest(res, "destructibleid must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        if (path.empty())
        {
            return BadRequest(res, "path must be set");
        }
        if (group.empty())
        {
            return BadRequest(res, "group must be set");
        }
        if (upgradetypename.empty())
        {
            return BadRequest(res, "upgradetypename must be set");
        }
        if (upgrademacroname.empty())
        {
            return BadRequest(res, "upgrademacroname must be set");
        }
        try {
            SET_CONTENT(ffijson::IsUpgradeGroupMacroCompatible(PARAMS(std::stoll(destructibleid), macroname.c_str(), path.c_str(), group.c_str(), upgradetypename.c_str(), upgrademacroname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsUpgradeMacroCompatible", HAN_FN {
        std::string objectid = req.get_param_value("objectid");
        std::string moduleid = req.get_param_value("moduleid");
        std::string macroname = req.get_param_value("macroname");
        std::string ismodule = req.get_param_value("ismodule");
        std::string upgradetypename = req.get_param_value("upgradetypename");
        std::string slot = req.get_param_value("slot");
        std::string upgrademacroname = req.get_param_value("upgrademacroname");
        if (objectid.empty())
        {
            return BadRequest(res, "objectid must be set");
        }
        if (moduleid.empty())
        {
            return BadRequest(res, "moduleid must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        if (ismodule.empty())
        {
            return BadRequest(res, "ismodule must be set");
        }
        if (upgradetypename.empty())
        {
            return BadRequest(res, "upgradetypename must be set");
        }
        if (slot.empty())
        {
            return BadRequest(res, "slot must be set");
        }
        if (upgrademacroname.empty())
        {
            return BadRequest(res, "upgrademacroname must be set");
        }
        try {
            SET_CONTENT(ffijson::IsUpgradeMacroCompatible(PARAMS(std::stoll(objectid), std::stoll(moduleid), macroname.c_str(), std::stoi(ismodule), upgradetypename.c_str(), std::stoll(slot), upgrademacroname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsVRMode", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsVRMode(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsVROculusTouchActive", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsVROculusTouchActive(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsVRPointerActive", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsVRPointerActive(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsVRVersion", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsVRVersion(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsVRViveControllerActive", HAN_FN {
        try {
            SET_CONTENT(ffijson::IsVRViveControllerActive(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsValidComponent", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsValidComponent(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsVentureShip", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsVentureShip(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsVirtualUpgradeMacroCompatible", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string macroname = req.get_param_value("macroname");
        std::string upgradetypename = req.get_param_value("upgradetypename");
        std::string slot = req.get_param_value("slot");
        std::string upgrademacroname = req.get_param_value("upgrademacroname");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        if (upgradetypename.empty())
        {
            return BadRequest(res, "upgradetypename must be set");
        }
        if (slot.empty())
        {
            return BadRequest(res, "slot must be set");
        }
        if (upgrademacroname.empty())
        {
            return BadRequest(res, "upgrademacroname must be set");
        }
        try {
            SET_CONTENT(ffijson::IsVirtualUpgradeMacroCompatible(PARAMS(std::stoll(defensibleid), macroname.c_str(), upgradetypename.c_str(), std::stoll(slot), upgrademacroname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsWeaponArmed", HAN_FN {
        std::string weaponid = req.get_param_value("weaponid");
        if (weaponid.empty())
        {
            return BadRequest(res, "weaponid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsWeaponArmed(PARAMS(std::stoll(weaponid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsWillingToBuyFromPlayer", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        std::string warename = req.get_param_value("warename");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        if (warename.empty())
        {
            return BadRequest(res, "warename must be set");
        }
        try {
            SET_CONTENT(ffijson::IsWillingToBuyFromPlayer(PARAMS(std::stoll(componentid), warename.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsWillingToSellToPlayer", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        std::string warename = req.get_param_value("warename");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        if (warename.empty())
        {
            return BadRequest(res, "warename must be set");
        }
        try {
            SET_CONTENT(ffijson::IsWillingToSellToPlayer(PARAMS(std::stoll(componentid), warename.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/IsZone", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::IsZone(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/MarkIndicatorShown", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::MarkIndicatorShown(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/QueryGameServers", HAN_FN {
        try {
            SET_CONTENT(ffijson::QueryGameServers(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/QuickDock", HAN_FN {
        try {
            SET_CONTENT(ffijson::QuickDock(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/QuickMenuAccess", HAN_FN {
        std::string menu = req.get_param_value("menu");
        if (menu.empty())
        {
            return BadRequest(res, "menu must be set");
        }
        try {
            SET_CONTENT(ffijson::QuickMenuAccess(PARAMS(menu.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/RemoveAllOrders", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        try {
            SET_CONTENT(ffijson::RemoveAllOrders(PARAMS(std::stoll(controllableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/RemoveAttackerFromBoardingOperation", HAN_FN {
        std::string defensibleboarderid = req.get_param_value("defensibleboarderid");
        if (defensibleboarderid.empty())
        {
            return BadRequest(res, "defensibleboarderid must be set");
        }
        try {
            SET_CONTENT(ffijson::RemoveAttackerFromBoardingOperation(PARAMS(std::stoll(defensibleboarderid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/RemoveBuildPlot", HAN_FN {
        std::string stationid = req.get_param_value("stationid");
        if (stationid.empty())
        {
            return BadRequest(res, "stationid must be set");
        }
        try {
            SET_CONTENT(ffijson::RemoveBuildPlot(PARAMS(std::stoll(stationid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/RemoveCommander2", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        try {
            SET_CONTENT(ffijson::RemoveCommander2(PARAMS(std::stoll(controllableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/RemoveConstructionPlan", HAN_FN {
        std::string source = req.get_param_value("source");
        std::string id = req.get_param_value("id");
        if (source.empty())
        {
            return BadRequest(res, "source must be set");
        }
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        try {
            SET_CONTENT(ffijson::RemoveConstructionPlan(PARAMS(source.c_str(), id.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/RemoveLoadout", HAN_FN {
        std::string source = req.get_param_value("source");
        std::string macroname = req.get_param_value("macroname");
        std::string localid = req.get_param_value("localid");
        if (source.empty())
        {
            return BadRequest(res, "source must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        if (localid.empty())
        {
            return BadRequest(res, "localid must be set");
        }
        try {
            SET_CONTENT(ffijson::RemoveLoadout(PARAMS(source.c_str(), macroname.c_str(), localid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/RemoveOrder", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string idx = req.get_param_value("idx");
        std::string playercancelled = req.get_param_value("playercancelled");
        std::string checkonly = req.get_param_value("checkonly");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (idx.empty())
        {
            return BadRequest(res, "idx must be set");
        }
        if (playercancelled.empty())
        {
            return BadRequest(res, "playercancelled must be set");
        }
        if (checkonly.empty())
        {
            return BadRequest(res, "checkonly must be set");
        }
        try {
            SET_CONTENT(ffijson::RemoveOrder(PARAMS(std::stoll(controllableid), std::stoll(idx), std::stoi(playercancelled), std::stoi(checkonly))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/RemoveOrder2", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string idx = req.get_param_value("idx");
        std::string playercancelled = req.get_param_value("playercancelled");
        std::string checkonly = req.get_param_value("checkonly");
        std::string onlyimmediate = req.get_param_value("onlyimmediate");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (idx.empty())
        {
            return BadRequest(res, "idx must be set");
        }
        if (playercancelled.empty())
        {
            return BadRequest(res, "playercancelled must be set");
        }
        if (checkonly.empty())
        {
            return BadRequest(res, "checkonly must be set");
        }
        if (onlyimmediate.empty())
        {
            return BadRequest(res, "onlyimmediate must be set");
        }
        try {
            SET_CONTENT(ffijson::RemoveOrder2(PARAMS(std::stoll(controllableid), std::stoll(idx), std::stoi(playercancelled), std::stoi(checkonly), std::stoi(onlyimmediate))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/RequestDockAt", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string checkonly = req.get_param_value("checkonly");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (checkonly.empty())
        {
            return BadRequest(res, "checkonly must be set");
        }
        try {
            SET_CONTENT(ffijson::RequestDockAt(PARAMS(std::stoll(containerid), std::stoi(checkonly))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/RequestShipFromInternalStorage2", HAN_FN {
        std::string shipid = req.get_param_value("shipid");
        std::string highpriority = req.get_param_value("highpriority");
        std::string refcomponentid = req.get_param_value("refcomponentid");
        if (shipid.empty())
        {
            return BadRequest(res, "shipid must be set");
        }
        if (highpriority.empty())
        {
            return BadRequest(res, "highpriority must be set");
        }
        if (refcomponentid.empty())
        {
            return BadRequest(res, "refcomponentid must be set");
        }
        try {
            SET_CONTENT(ffijson::RequestShipFromInternalStorage2(PARAMS(std::stoll(shipid), std::stoi(highpriority), std::stoll(refcomponentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ResetResponseToSignalForControllable", HAN_FN {
        std::string signalid = req.get_param_value("signalid");
        std::string controllableid = req.get_param_value("controllableid");
        if (signalid.empty())
        {
            return BadRequest(res, "signalid must be set");
        }
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        try {
            SET_CONTENT(ffijson::ResetResponseToSignalForControllable(PARAMS(signalid.c_str(), std::stoll(controllableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetActiveFrame", HAN_FN {
        std::string frameid = req.get_param_value("frameid");
        if (frameid.empty())
        {
            return BadRequest(res, "frameid must be set");
        }
        try {
            SET_CONTENT(ffijson::SetActiveFrame(PARAMS(std::stoi(frameid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetActiveMission", HAN_FN {
        std::string missionid = req.get_param_value("missionid");
        if (missionid.empty())
        {
            return BadRequest(res, "missionid must be set");
        }
        try {
            SET_CONTENT(ffijson::SetActiveMission(PARAMS(std::stoll(missionid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetAmmoOfWeapon", HAN_FN {
        std::string weaponid = req.get_param_value("weaponid");
        std::string newammomacro = req.get_param_value("newammomacro");
        if (weaponid.empty())
        {
            return BadRequest(res, "weaponid must be set");
        }
        if (newammomacro.empty())
        {
            return BadRequest(res, "newammomacro must be set");
        }
        try {
            SET_CONTENT(ffijson::SetAmmoOfWeapon(PARAMS(std::stoll(weaponid), newammomacro.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetCommander", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string commanderid = req.get_param_value("commanderid");
        std::string assignment = req.get_param_value("assignment");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (commanderid.empty())
        {
            return BadRequest(res, "commanderid must be set");
        }
        if (assignment.empty())
        {
            return BadRequest(res, "assignment must be set");
        }
        try {
            SET_CONTENT(ffijson::SetCommander(PARAMS(std::stoll(controllableid), std::stoll(commanderid), assignment.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetDefaultResponseToSignalForControllable", HAN_FN {
        std::string newresponse = req.get_param_value("newresponse");
        std::string ask = req.get_param_value("ask");
        std::string signalid = req.get_param_value("signalid");
        std::string controllableid = req.get_param_value("controllableid");
        if (newresponse.empty())
        {
            return BadRequest(res, "newresponse must be set");
        }
        if (ask.empty())
        {
            return BadRequest(res, "ask must be set");
        }
        if (signalid.empty())
        {
            return BadRequest(res, "signalid must be set");
        }
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        try {
            SET_CONTENT(ffijson::SetDefaultResponseToSignalForControllable(PARAMS(newresponse.c_str(), std::stoi(ask), signalid.c_str(), std::stoll(controllableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetDefaultResponseToSignalForFaction", HAN_FN {
        std::string newresponse = req.get_param_value("newresponse");
        std::string ask = req.get_param_value("ask");
        std::string signalid = req.get_param_value("signalid");
        std::string factionid = req.get_param_value("factionid");
        if (newresponse.empty())
        {
            return BadRequest(res, "newresponse must be set");
        }
        if (ask.empty())
        {
            return BadRequest(res, "ask must be set");
        }
        if (signalid.empty())
        {
            return BadRequest(res, "signalid must be set");
        }
        if (factionid.empty())
        {
            return BadRequest(res, "factionid must be set");
        }
        try {
            SET_CONTENT(ffijson::SetDefaultResponseToSignalForFaction(PARAMS(newresponse.c_str(), std::stoi(ask), signalid.c_str(), factionid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetEntityToPost", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string entityid = req.get_param_value("entityid");
        std::string postid = req.get_param_value("postid");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (entityid.empty())
        {
            return BadRequest(res, "entityid must be set");
        }
        if (postid.empty())
        {
            return BadRequest(res, "postid must be set");
        }
        try {
            SET_CONTENT(ffijson::SetEntityToPost(PARAMS(std::stoll(controllableid), std::stoll(entityid), postid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetFrameInteractiveObject", HAN_FN {
        std::string frameid = req.get_param_value("frameid");
        std::string objectid = req.get_param_value("objectid");
        if (frameid.empty())
        {
            return BadRequest(res, "frameid must be set");
        }
        if (objectid.empty())
        {
            return BadRequest(res, "objectid must be set");
        }
        try {
            SET_CONTENT(ffijson::SetFrameInteractiveObject(PARAMS(std::stoi(frameid), std::stoi(objectid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetOrderSyncPointID", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string orderidx = req.get_param_value("orderidx");
        std::string syncid = req.get_param_value("syncid");
        std::string checkonly = req.get_param_value("checkonly");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (orderidx.empty())
        {
            return BadRequest(res, "orderidx must be set");
        }
        if (syncid.empty())
        {
            return BadRequest(res, "syncid must be set");
        }
        if (checkonly.empty())
        {
            return BadRequest(res, "checkonly must be set");
        }
        try {
            SET_CONTENT(ffijson::SetOrderSyncPointID(PARAMS(std::stoll(controllableid), std::stoll(orderidx), std::stoll(syncid), std::stoi(checkonly))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetRadarRenderTarget", HAN_FN {
        std::string rendertargettexture = req.get_param_value("rendertargettexture");
        std::string referencecomponent = req.get_param_value("referencecomponent");
        std::string mapmode = req.get_param_value("mapmode");
        if (rendertargettexture.empty())
        {
            return BadRequest(res, "rendertargettexture must be set");
        }
        if (referencecomponent.empty())
        {
            return BadRequest(res, "referencecomponent must be set");
        }
        if (mapmode.empty())
        {
            return BadRequest(res, "mapmode must be set");
        }
        try {
            SET_CONTENT(ffijson::SetRadarRenderTarget(PARAMS(rendertargettexture.c_str(), std::stoll(referencecomponent), std::stoi(mapmode))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetRadarRenderTargetOnTarget", HAN_FN {
        std::string rendertargettexture = req.get_param_value("rendertargettexture");
        std::string focuscomponentid = req.get_param_value("focuscomponentid");
        std::string referencecomponent = req.get_param_value("referencecomponent");
        std::string mapmode = req.get_param_value("mapmode");
        if (rendertargettexture.empty())
        {
            return BadRequest(res, "rendertargettexture must be set");
        }
        if (focuscomponentid.empty())
        {
            return BadRequest(res, "focuscomponentid must be set");
        }
        if (referencecomponent.empty())
        {
            return BadRequest(res, "referencecomponent must be set");
        }
        if (mapmode.empty())
        {
            return BadRequest(res, "mapmode must be set");
        }
        try {
            SET_CONTENT(ffijson::SetRadarRenderTargetOnTarget(PARAMS(rendertargettexture.c_str(), std::stoll(focuscomponentid), std::stoll(referencecomponent), std::stoi(mapmode))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetSofttarget", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        std::string connectionname = req.get_param_value("connectionname");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::SetSofttarget(PARAMS(std::stoll(componentid), connectionname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetStationOverviewGraphWare", HAN_FN {
        std::string stationid = req.get_param_value("stationid");
        std::string wareid = req.get_param_value("wareid");
        std::string value = req.get_param_value("value");
        if (stationid.empty())
        {
            return BadRequest(res, "stationid must be set");
        }
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetStationOverviewGraphWare(PARAMS(std::stoll(stationid), wareid.c_str(), std::stoi(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ShouldEditBoxRestoreInteractiveObject", HAN_FN {
        std::string editboxid = req.get_param_value("editboxid");
        if (editboxid.empty())
        {
            return BadRequest(res, "editboxid must be set");
        }
        try {
            SET_CONTENT(ffijson::ShouldEditBoxRestoreInteractiveObject(PARAMS(std::stoi(editboxid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ShouldSubordinateGroupDockAtCommander", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string group = req.get_param_value("group");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (group.empty())
        {
            return BadRequest(res, "group must be set");
        }
        try {
            SET_CONTENT(ffijson::ShouldSubordinateGroupDockAtCommander(PARAMS(std::stoll(controllableid), std::stoi(group))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ShowGamepadTextInput", HAN_FN {
        std::string description = req.get_param_value("description");
        std::string maxchars = req.get_param_value("maxchars");
        std::string existingtext = req.get_param_value("existingtext");
        std::string multilines = req.get_param_value("multilines");
        std::string password = req.get_param_value("password");
        if (description.empty())
        {
            return BadRequest(res, "description must be set");
        }
        if (maxchars.empty())
        {
            return BadRequest(res, "maxchars must be set");
        }
        if (existingtext.empty())
        {
            return BadRequest(res, "existingtext must be set");
        }
        if (multilines.empty())
        {
            return BadRequest(res, "multilines must be set");
        }
        if (password.empty())
        {
            return BadRequest(res, "password must be set");
        }
        try {
            SET_CONTENT(ffijson::ShowGamepadTextInput(PARAMS(description.c_str(), std::stoll(maxchars), existingtext.c_str(), std::stoi(multilines), std::stoi(password))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ShuffleMapConstructionPlan", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string checkonly = req.get_param_value("checkonly");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (checkonly.empty())
        {
            return BadRequest(res, "checkonly must be set");
        }
        try {
            SET_CONTENT(ffijson::ShuffleMapConstructionPlan(PARAMS(std::stoll(holomapid), std::stoi(checkonly))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/StartBoardingOperation", HAN_FN {
        std::string defensibletargetid = req.get_param_value("defensibletargetid");
        std::string boarderfactionid = req.get_param_value("boarderfactionid");
        if (defensibletargetid.empty())
        {
            return BadRequest(res, "defensibletargetid must be set");
        }
        if (boarderfactionid.empty())
        {
            return BadRequest(res, "boarderfactionid must be set");
        }
        try {
            SET_CONTENT(ffijson::StartBoardingOperation(PARAMS(std::stoll(defensibletargetid), boarderfactionid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/StopPanMap", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        try {
            SET_CONTENT(ffijson::StopPanMap(PARAMS(std::stoll(holomapid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/StopRotateMap", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        try {
            SET_CONTENT(ffijson::StopRotateMap(PARAMS(std::stoll(holomapid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/TakeShipFromInternalStorage", HAN_FN {
        std::string shipid = req.get_param_value("shipid");
        std::string highpriority = req.get_param_value("highpriority");
        std::string checkonly = req.get_param_value("checkonly");
        if (shipid.empty())
        {
            return BadRequest(res, "shipid must be set");
        }
        if (highpriority.empty())
        {
            return BadRequest(res, "highpriority must be set");
        }
        if (checkonly.empty())
        {
            return BadRequest(res, "checkonly must be set");
        }
        try {
            SET_CONTENT(ffijson::TakeShipFromInternalStorage(PARAMS(std::stoll(shipid), std::stoi(highpriority), std::stoi(checkonly))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/TeleportPlayerTo", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string allowcontrolling = req.get_param_value("allowcontrolling");
        std::string instant = req.get_param_value("instant");
        std::string force = req.get_param_value("force");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (allowcontrolling.empty())
        {
            return BadRequest(res, "allowcontrolling must be set");
        }
        if (instant.empty())
        {
            return BadRequest(res, "instant must be set");
        }
        if (force.empty())
        {
            return BadRequest(res, "force must be set");
        }
        try {
            SET_CONTENT(ffijson::TeleportPlayerTo(PARAMS(std::stoll(controllableid), std::stoi(allowcontrolling), std::stoi(instant), std::stoi(force))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ToggleAutoPilot", HAN_FN {
        std::string checkonly = req.get_param_value("checkonly");
        if (checkonly.empty())
        {
            return BadRequest(res, "checkonly must be set");
        }
        try {
            SET_CONTENT(ffijson::ToggleAutoPilot(PARAMS(std::stoi(checkonly))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/TriggerCompSlotAnimation", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        std::string connectionname = req.get_param_value("connectionname");
        std::string triggername = req.get_param_value("triggername");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        if (triggername.empty())
        {
            return BadRequest(res, "triggername must be set");
        }
        try {
            SET_CONTENT(ffijson::TriggerCompSlotAnimation(PARAMS(std::stoll(componentid), connectionname.c_str(), triggername.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/UpdateAttackerOfBoardingOperation", HAN_FN {
        std::string defensibletargetid = req.get_param_value("defensibletargetid");
        std::string defensibleboarderid = req.get_param_value("defensibleboarderid");
        std::string boarderfactionid = req.get_param_value("boarderfactionid");
        std::string actionid = req.get_param_value("actionid");
        std::string nummarinetiers = req.get_param_value("nummarinetiers");
        if (defensibletargetid.empty())
        {
            return BadRequest(res, "defensibletargetid must be set");
        }
        if (defensibleboarderid.empty())
        {
            return BadRequest(res, "defensibleboarderid must be set");
        }
        if (boarderfactionid.empty())
        {
            return BadRequest(res, "boarderfactionid must be set");
        }
        if (actionid.empty())
        {
            return BadRequest(res, "actionid must be set");
        }
        if (nummarinetiers.empty())
        {
            return BadRequest(res, "nummarinetiers must be set");
        }
        try {
            SET_CONTENT(ffijson::UpdateAttackerOfBoardingOperation(PARAMS(std::stoll(defensibletargetid), std::stoll(defensibleboarderid), boarderfactionid.c_str(), actionid.c_str(), std::stoll(nummarinetiers))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/UpdateBoardingOperation", HAN_FN {
        std::string defensibletargetid = req.get_param_value("defensibletargetid");
        std::string boarderfactionid = req.get_param_value("boarderfactionid");
        std::string approachthreshold = req.get_param_value("approachthreshold");
        std::string insertionthreshold = req.get_param_value("insertionthreshold");
        if (defensibletargetid.empty())
        {
            return BadRequest(res, "defensibletargetid must be set");
        }
        if (boarderfactionid.empty())
        {
            return BadRequest(res, "boarderfactionid must be set");
        }
        if (approachthreshold.empty())
        {
            return BadRequest(res, "approachthreshold must be set");
        }
        if (insertionthreshold.empty())
        {
            return BadRequest(res, "insertionthreshold must be set");
        }
        try {
            SET_CONTENT(ffijson::UpdateBoardingOperation(PARAMS(std::stoll(defensibletargetid), boarderfactionid.c_str(), std::stoll(approachthreshold), std::stoll(insertionthreshold))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/CanTeleportPlayerTo", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string allowcontrolling = req.get_param_value("allowcontrolling");
        std::string force = req.get_param_value("force");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (allowcontrolling.empty())
        {
            return BadRequest(res, "allowcontrolling must be set");
        }
        if (force.empty())
        {
            return BadRequest(res, "force must be set");
        }
        try {
            SET_CONTENT(ffijson::CanTeleportPlayerTo(PARAMS(std::stoll(controllableid), std::stoi(allowcontrolling), std::stoi(force))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GenerateFactionRelationText", HAN_FN {
        std::string factionid = req.get_param_value("factionid");
        if (factionid.empty())
        {
            return BadRequest(res, "factionid must be set");
        }
        try {
            SET_CONTENT(ffijson::GenerateFactionRelationText(PARAMS(factionid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAAOption", HAN_FN {
        std::string useconfig = req.get_param_value("useconfig");
        if (useconfig.empty())
        {
            return BadRequest(res, "useconfig must be set");
        }
        try {
            SET_CONTENT(ffijson::GetAAOption(PARAMS(std::stoi(useconfig))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetBoardingActionOfAttacker", HAN_FN {
        std::string defensibletargetid = req.get_param_value("defensibletargetid");
        std::string defensibleboarderid = req.get_param_value("defensibleboarderid");
        std::string boarderfactionid = req.get_param_value("boarderfactionid");
        if (defensibletargetid.empty())
        {
            return BadRequest(res, "defensibletargetid must be set");
        }
        if (defensibleboarderid.empty())
        {
            return BadRequest(res, "defensibleboarderid must be set");
        }
        if (boarderfactionid.empty())
        {
            return BadRequest(res, "boarderfactionid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetBoardingActionOfAttacker(PARAMS(std::stoll(defensibletargetid), std::stoll(defensibleboarderid), boarderfactionid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetBuildVersionSuffix", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetBuildVersionSuffix(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCheckBoxSymbol", HAN_FN {
        std::string checkboxid = req.get_param_value("checkboxid");
        if (checkboxid.empty())
        {
            return BadRequest(res, "checkboxid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCheckBoxSymbol(PARAMS(std::stoi(checkboxid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCompSlotPlayerActionTriggeredConnection", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        std::string connectionname = req.get_param_value("connectionname");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCompSlotPlayerActionTriggeredConnection(PARAMS(std::stoll(componentid), connectionname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetComponentClass", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetComponentClass(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetComponentName", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetComponentName(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCurrentAmmoOfWeapon", HAN_FN {
        std::string weaponid = req.get_param_value("weaponid");
        if (weaponid.empty())
        {
            return BadRequest(res, "weaponid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCurrentAmmoOfWeapon(PARAMS(std::stoll(weaponid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCurrentBoardingPhase", HAN_FN {
        std::string defensibletargetid = req.get_param_value("defensibletargetid");
        std::string boarderfactionid = req.get_param_value("boarderfactionid");
        if (defensibletargetid.empty())
        {
            return BadRequest(res, "defensibletargetid must be set");
        }
        if (boarderfactionid.empty())
        {
            return BadRequest(res, "boarderfactionid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCurrentBoardingPhase(PARAMS(std::stoll(defensibletargetid), boarderfactionid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCurrentDroneMode", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string dronetype = req.get_param_value("dronetype");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (dronetype.empty())
        {
            return BadRequest(res, "dronetype must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCurrentDroneMode(PARAMS(std::stoll(defensibleid), dronetype.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCurrentGPUNiceName", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetCurrentGPUNiceName(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCurrentSoundDevice", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetCurrentSoundDevice(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCustomGameStartStringProperty", HAN_FN {
        std::string id = req.get_param_value("id");
        std::string propertyid = req.get_param_value("propertyid");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (propertyid.empty())
        {
            return BadRequest(res, "propertyid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCustomGameStartStringProperty(PARAMS(id.c_str(), propertyid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetDefaultResponseToSignalForControllable", HAN_FN {
        std::string signalid = req.get_param_value("signalid");
        std::string controllableid = req.get_param_value("controllableid");
        if (signalid.empty())
        {
            return BadRequest(res, "signalid must be set");
        }
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetDefaultResponseToSignalForControllable(PARAMS(signalid.c_str(), std::stoll(controllableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetDefaultResponseToSignalForFaction", HAN_FN {
        std::string signalid = req.get_param_value("signalid");
        std::string factionid = req.get_param_value("factionid");
        if (signalid.empty())
        {
            return BadRequest(res, "signalid must be set");
        }
        if (factionid.empty())
        {
            return BadRequest(res, "factionid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetDefaultResponseToSignalForFaction(PARAMS(signalid.c_str(), factionid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetDetailmonitorCutsceneKey", HAN_FN {
        std::string cutsceneid = req.get_param_value("cutsceneid");
        if (cutsceneid.empty())
        {
            return BadRequest(res, "cutsceneid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetDetailmonitorCutsceneKey(PARAMS(std::stoll(cutsceneid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetDropDownStartOption", HAN_FN {
        std::string dropdownid = req.get_param_value("dropdownid");
        if (dropdownid.empty())
        {
            return BadRequest(res, "dropdownid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetDropDownStartOption(PARAMS(std::stoi(dropdownid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetEditBoxDefaultText", HAN_FN {
        std::string editboxid = req.get_param_value("editboxid");
        if (editboxid.empty())
        {
            return BadRequest(res, "editboxid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetEditBoxDefaultText(PARAMS(std::stoi(editboxid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetEditBoxDescription", HAN_FN {
        std::string editboxid = req.get_param_value("editboxid");
        if (editboxid.empty())
        {
            return BadRequest(res, "editboxid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetEditBoxDescription(PARAMS(std::stoi(editboxid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetEntityActiveIcon", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetEntityActiveIcon(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetEntityInactiveIcon", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetEntityInactiveIcon(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetEntitySelectedIcon", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetEntitySelectedIcon(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetEquipmentModPropertyName", HAN_FN {
        std::string wareid = req.get_param_value("wareid");
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetEquipmentModPropertyName(PARAMS(wareid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetFactionNameForTargetMonitorHack", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetFactionNameForTargetMonitorHack(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetFleetName", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetFleetName(PARAMS(std::stoll(controllableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetLocalizedInputName", HAN_FN {
        std::string sourceid = req.get_param_value("sourceid");
        std::string codeid = req.get_param_value("codeid");
        if (sourceid.empty())
        {
            return BadRequest(res, "sourceid must be set");
        }
        if (codeid.empty())
        {
            return BadRequest(res, "codeid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetLocalizedInputName(PARAMS(std::stoll(sourceid), std::stoll(codeid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetLocalizedInteractiveNotificationKey", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetLocalizedInteractiveNotificationKey(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetLocalizedRawMouseButtonName", HAN_FN {
        std::string keycodeid = req.get_param_value("keycodeid");
        if (keycodeid.empty())
        {
            return BadRequest(res, "keycodeid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetLocalizedRawMouseButtonName(PARAMS(std::stoll(keycodeid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetLocalizedText", HAN_FN {
        std::string pageid = req.get_param_value("pageid");
        std::string textid = req.get_param_value("textid");
        std::string defaultvalue = req.get_param_value("defaultvalue");
        if (pageid.empty())
        {
            return BadRequest(res, "pageid must be set");
        }
        if (textid.empty())
        {
            return BadRequest(res, "textid must be set");
        }
        if (defaultvalue.empty())
        {
            return BadRequest(res, "defaultvalue must be set");
        }
        try {
            SET_CONTENT(ffijson::GetLocalizedText(PARAMS(std::stoll(pageid), std::stoll(textid), defaultvalue.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetMacroClass", HAN_FN {
        std::string macroname = req.get_param_value("macroname");
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        try {
            SET_CONTENT(ffijson::GetMacroClass(PARAMS(macroname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetMacroMapPositionOnEcliptic", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetMacroMapPositionOnEcliptic(PARAMS(std::stoll(holomapid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetMappedInputName", HAN_FN {
        std::string functionkey = req.get_param_value("functionkey");
        if (functionkey.empty())
        {
            return BadRequest(res, "functionkey must be set");
        }
        try {
            SET_CONTENT(ffijson::GetMappedInputName(PARAMS(functionkey.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetMissingConstructionPlanBlueprints", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string constructionplanid = req.get_param_value("constructionplanid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (constructionplanid.empty())
        {
            return BadRequest(res, "constructionplanid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetMissingConstructionPlanBlueprints(PARAMS(std::stoll(containerid), constructionplanid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetMouseOverText", HAN_FN {
        std::string widgetid = req.get_param_value("widgetid");
        if (widgetid.empty())
        {
            return BadRequest(res, "widgetid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetMouseOverText(PARAMS(std::stoi(widgetid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetObjectIDCode", HAN_FN {
        std::string objectid = req.get_param_value("objectid");
        if (objectid.empty())
        {
            return BadRequest(res, "objectid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetObjectIDCode(PARAMS(std::stoll(objectid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPersonName", HAN_FN {
        std::string person = req.get_param_value("person");
        std::string controllableid = req.get_param_value("controllableid");
        if (person.empty())
        {
            return BadRequest(res, "person must be set");
        }
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetPersonName(PARAMS(std::stoll(person), std::stoll(controllableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPersonRole", HAN_FN {
        std::string person = req.get_param_value("person");
        std::string controllableid = req.get_param_value("controllableid");
        if (person.empty())
        {
            return BadRequest(res, "person must be set");
        }
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetPersonRole(PARAMS(std::stoll(person), std::stoll(controllableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPersonRoleName", HAN_FN {
        std::string person = req.get_param_value("person");
        std::string controllableid = req.get_param_value("controllableid");
        if (person.empty())
        {
            return BadRequest(res, "person must be set");
        }
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetPersonRoleName(PARAMS(std::stoll(person), std::stoll(controllableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPlayerClothingTheme", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetPlayerClothingTheme(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPlayerFactionName", HAN_FN {
        std::string userawname = req.get_param_value("userawname");
        if (userawname.empty())
        {
            return BadRequest(res, "userawname must be set");
        }
        try {
            SET_CONTENT(ffijson::GetPlayerFactionName(PARAMS(std::stoi(userawname))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPlayerName", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetPlayerName(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPlayerPaintTheme", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetPlayerPaintTheme(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPlayerShipSize", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetPlayerShipSize(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPresentModeOption", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetPresentModeOption(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPurposeName", HAN_FN {
        std::string purposeid = req.get_param_value("purposeid");
        if (purposeid.empty())
        {
            return BadRequest(res, "purposeid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetPurposeName(PARAMS(purposeid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetRealComponentClass", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetRealComponentClass(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetSSROption2", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetSSROption2(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetSaveLocationName", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetSaveLocationName(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetShipOrLaserTowerSize", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetShipOrLaserTowerSize(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetShipPurpose", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetShipPurpose(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetSliderCellSuffix", HAN_FN {
        std::string slidercellid = req.get_param_value("slidercellid");
        if (slidercellid.empty())
        {
            return BadRequest(res, "slidercellid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetSliderCellSuffix(PARAMS(std::stoi(slidercellid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetSliderCellText", HAN_FN {
        std::string slidercellid = req.get_param_value("slidercellid");
        if (slidercellid.empty())
        {
            return BadRequest(res, "slidercellid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetSliderCellText(PARAMS(std::stoi(slidercellid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetSlotSize", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string moduleid = req.get_param_value("moduleid");
        std::string macroname = req.get_param_value("macroname");
        std::string ismodule = req.get_param_value("ismodule");
        std::string upgradetypename = req.get_param_value("upgradetypename");
        std::string slot = req.get_param_value("slot");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (moduleid.empty())
        {
            return BadRequest(res, "moduleid must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        if (ismodule.empty())
        {
            return BadRequest(res, "ismodule must be set");
        }
        if (upgradetypename.empty())
        {
            return BadRequest(res, "upgradetypename must be set");
        }
        if (slot.empty())
        {
            return BadRequest(res, "slot must be set");
        }
        try {
            SET_CONTENT(ffijson::GetSlotSize(PARAMS(std::stoll(defensibleid), std::stoll(moduleid), macroname.c_str(), std::stoi(ismodule), upgradetypename.c_str(), std::stoll(slot))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetSoftwareMaxCompatibleVersion", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string macroname = req.get_param_value("macroname");
        std::string softwarename = req.get_param_value("softwarename");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        if (softwarename.empty())
        {
            return BadRequest(res, "softwarename must be set");
        }
        try {
            SET_CONTENT(ffijson::GetSoftwareMaxCompatibleVersion(PARAMS(std::stoll(controllableid), macroname.c_str(), softwarename.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetSteamID", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetSteamID(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetSubordinateGroupAssignment", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string group = req.get_param_value("group");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (group.empty())
        {
            return BadRequest(res, "group must be set");
        }
        try {
            SET_CONTENT(ffijson::GetSubordinateGroupAssignment(PARAMS(std::stoll(controllableid), std::stoi(group))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetTableBackgroundID", HAN_FN {
        std::string tableid = req.get_param_value("tableid");
        if (tableid.empty())
        {
            return BadRequest(res, "tableid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetTableBackgroundID(PARAMS(std::stoi(tableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetTextureQualityOption", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetTextureQualityOption(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetTobiiMode", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetTobiiMode(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetTrackerNameOption", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetTrackerNameOption(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetTrackerSDKOption", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetTrackerSDKOption(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetTurretGroupMode2", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string contextid = req.get_param_value("contextid");
        std::string path = req.get_param_value("path");
        std::string group = req.get_param_value("group");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (contextid.empty())
        {
            return BadRequest(res, "contextid must be set");
        }
        if (path.empty())
        {
            return BadRequest(res, "path must be set");
        }
        if (group.empty())
        {
            return BadRequest(res, "group must be set");
        }
        try {
            SET_CONTENT(ffijson::GetTurretGroupMode2(PARAMS(std::stoll(defensibleid), std::stoll(contextid), path.c_str(), group.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetUpgradeSlotCurrentMacro", HAN_FN {
        std::string objectid = req.get_param_value("objectid");
        std::string moduleid = req.get_param_value("moduleid");
        std::string upgradetypename = req.get_param_value("upgradetypename");
        std::string slot = req.get_param_value("slot");
        if (objectid.empty())
        {
            return BadRequest(res, "objectid must be set");
        }
        if (moduleid.empty())
        {
            return BadRequest(res, "moduleid must be set");
        }
        if (upgradetypename.empty())
        {
            return BadRequest(res, "upgradetypename must be set");
        }
        if (slot.empty())
        {
            return BadRequest(res, "slot must be set");
        }
        try {
            SET_CONTENT(ffijson::GetUpgradeSlotCurrentMacro(PARAMS(std::stoll(objectid), std::stoll(moduleid), upgradetypename.c_str(), std::stoll(slot))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetVirtualUpgradeSlotCurrentMacro", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string upgradetypename = req.get_param_value("upgradetypename");
        std::string slot = req.get_param_value("slot");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (upgradetypename.empty())
        {
            return BadRequest(res, "upgradetypename must be set");
        }
        if (slot.empty())
        {
            return BadRequest(res, "slot must be set");
        }
        try {
            SET_CONTENT(ffijson::GetVirtualUpgradeSlotCurrentMacro(PARAMS(std::stoll(defensibleid), upgradetypename.c_str(), std::stoll(slot))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetWeaponMode", HAN_FN {
        std::string weaponid = req.get_param_value("weaponid");
        if (weaponid.empty())
        {
            return BadRequest(res, "weaponid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetWeaponMode(PARAMS(std::stoll(weaponid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/RequestDockAtReason", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string checkonly = req.get_param_value("checkonly");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (checkonly.empty())
        {
            return BadRequest(res, "checkonly must be set");
        }
        try {
            SET_CONTENT(ffijson::RequestDockAtReason(PARAMS(std::stoll(containerid), std::stoi(checkonly))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/UndockPlayerShip", HAN_FN {
        std::string checkonly = req.get_param_value("checkonly");
        if (checkonly.empty())
        {
            return BadRequest(res, "checkonly must be set");
        }
        try {
            SET_CONTENT(ffijson::UndockPlayerShip(PARAMS(std::stoi(checkonly))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetBuildProcessorEstimatedTimeLeft", HAN_FN {
        std::string buildprocessorid = req.get_param_value("buildprocessorid");
        if (buildprocessorid.empty())
        {
            return BadRequest(res, "buildprocessorid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetBuildProcessorEstimatedTimeLeft(PARAMS(std::stoll(buildprocessorid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetBuildTaskDuration", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string id = req.get_param_value("id");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        try {
            SET_CONTENT(ffijson::GetBuildTaskDuration(PARAMS(std::stoll(containerid), std::stoll(id))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetContainerWareConsumption", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string wareid = req.get_param_value("wareid");
        std::string ignorestate = req.get_param_value("ignorestate");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        if (ignorestate.empty())
        {
            return BadRequest(res, "ignorestate must be set");
        }
        try {
            SET_CONTENT(ffijson::GetContainerWareConsumption(PARAMS(std::stoll(containerid), wareid.c_str(), std::stoi(ignorestate))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetContainerWareProduction", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string wareid = req.get_param_value("wareid");
        std::string ignorestate = req.get_param_value("ignorestate");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        if (ignorestate.empty())
        {
            return BadRequest(res, "ignorestate must be set");
        }
        try {
            SET_CONTENT(ffijson::GetContainerWareProduction(PARAMS(std::stoll(containerid), wareid.c_str(), std::stoi(ignorestate))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCurrentGameTime", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetCurrentGameTime(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAdaptiveSamplingOption", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetAdaptiveSamplingOption(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCockpitCameraScaleOption", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetCockpitCameraScaleOption(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetContainerBuildPriceFactor", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetContainerBuildPriceFactor(PARAMS(std::stoll(containerid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetContainerGlobalPriceFactor", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetContainerGlobalPriceFactor(PARAMS(std::stoll(containerid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCurrentBuildProgress", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCurrentBuildProgress(PARAMS(std::stoll(containerid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetDefensibleLoadoutLevel", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetDefensibleLoadoutLevel(PARAMS(std::stoll(defensibleid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPlayerGlobalLoadoutLevel", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetPlayerGlobalLoadoutLevel(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetRectangleTargetElementExtents", HAN_FN {
        std::string posid = req.get_param_value("posid");
        if (posid.empty())
        {
            return BadRequest(res, "posid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetRectangleTargetElementExtents(PARAMS(std::stoi(posid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetRemainingOxygen", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetRemainingOxygen(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetResourceBoxSize", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetResourceBoxSize(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetScanProgress", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetScanProgress(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetShieldHullBarHullPercent", HAN_FN {
        std::string shieldhullbarid = req.get_param_value("shieldhullbarid");
        if (shieldhullbarid.empty())
        {
            return BadRequest(res, "shieldhullbarid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetShieldHullBarHullPercent(PARAMS(std::stoi(shieldhullbarid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetShieldHullBarShieldPercent", HAN_FN {
        std::string shieldhullbarid = req.get_param_value("shieldhullbarid");
        if (shieldhullbarid.empty())
        {
            return BadRequest(res, "shieldhullbarid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetShieldHullBarShieldPercent(PARAMS(std::stoi(shieldhullbarid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetStatusBarCurrentValue", HAN_FN {
        std::string statusbarid = req.get_param_value("statusbarid");
        if (statusbarid.empty())
        {
            return BadRequest(res, "statusbarid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetStatusBarCurrentValue(PARAMS(std::stoi(statusbarid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetStatusBarMaxValue", HAN_FN {
        std::string statusbarid = req.get_param_value("statusbarid");
        if (statusbarid.empty())
        {
            return BadRequest(res, "statusbarid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetStatusBarMaxValue(PARAMS(std::stoi(statusbarid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetStatusBarStartValue", HAN_FN {
        std::string statusbarid = req.get_param_value("statusbarid");
        if (statusbarid.empty())
        {
            return BadRequest(res, "statusbarid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetStatusBarStartValue(PARAMS(std::stoi(statusbarid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetTextHeight", HAN_FN {
        std::string text = req.get_param_value("text");
        std::string fontname = req.get_param_value("fontname");
        std::string fontsize = req.get_param_value("fontsize");
        std::string wordwrapwidth = req.get_param_value("wordwrapwidth");
        if (text.empty())
        {
            return BadRequest(res, "text must be set");
        }
        if (fontname.empty())
        {
            return BadRequest(res, "fontname must be set");
        }
        if (fontsize.empty())
        {
            return BadRequest(res, "fontsize must be set");
        }
        if (wordwrapwidth.empty())
        {
            return BadRequest(res, "wordwrapwidth must be set");
        }
        try {
            SET_CONTENT(ffijson::GetTextHeight(PARAMS(text.c_str(), fontname.c_str(), std::stoll(fontsize), std::stof(wordwrapwidth))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetTextWidth", HAN_FN {
        std::string text = req.get_param_value("text");
        std::string fontname = req.get_param_value("fontname");
        std::string fontsize = req.get_param_value("fontsize");
        if (text.empty())
        {
            return BadRequest(res, "text must be set");
        }
        if (fontname.empty())
        {
            return BadRequest(res, "fontname must be set");
        }
        if (fontsize.empty())
        {
            return BadRequest(res, "fontsize must be set");
        }
        try {
            SET_CONTENT(ffijson::GetTextWidth(PARAMS(text.c_str(), fontname.c_str(), std::stof(fontsize))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetTobiiAngleFactor", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetTobiiAngleFactor(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetTobiiDeadzoneAngle", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetTobiiDeadzoneAngle(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetTobiiDeadzonePosition", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetTobiiDeadzonePosition(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetTobiiGazeAngleFactor", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetTobiiGazeAngleFactor(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetTobiiGazeDeadzone", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetTobiiGazeDeadzone(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetTobiiHeadPositionFactor", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetTobiiHeadPositionFactor(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetUIScale", HAN_FN {
        std::string scalewithresolution = req.get_param_value("scalewithresolution");
        if (scalewithresolution.empty())
        {
            return BadRequest(res, "scalewithresolution must be set");
        }
        try {
            SET_CONTENT(ffijson::GetUIScale(PARAMS(std::stoi(scalewithresolution))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetUIScaleFactor", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetUIScaleFactor(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetConfigSetting", HAN_FN {
        std::string setting = req.get_param_value("setting");
        if (setting.empty())
        {
            return BadRequest(res, "setting must be set");
        }
        try {
            SET_CONTENT(ffijson::GetConfigSetting(PARAMS(setting.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNotificationID", HAN_FN {
        std::string num = req.get_param_value("num");
        if (num.empty())
        {
            return BadRequest(res, "num must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNotificationID(PARAMS(std::stoll(num))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPriorityMissiontargetPOSID", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetPriorityMissiontargetPOSID(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetTableNextConnectedTable", HAN_FN {
        std::string tableid = req.get_param_value("tableid");
        if (tableid.empty())
        {
            return BadRequest(res, "tableid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetTableNextConnectedTable(PARAMS(std::stoi(tableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetTableNextHorizontalConnectedTable", HAN_FN {
        std::string tableid = req.get_param_value("tableid");
        if (tableid.empty())
        {
            return BadRequest(res, "tableid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetTableNextHorizontalConnectedTable(PARAMS(std::stoi(tableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetTablePreviousConnectedTable", HAN_FN {
        std::string tableid = req.get_param_value("tableid");
        if (tableid.empty())
        {
            return BadRequest(res, "tableid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetTablePreviousConnectedTable(PARAMS(std::stoi(tableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetTablePreviousHorizontalConnectedTable", HAN_FN {
        std::string tableid = req.get_param_value("tableid");
        if (tableid.empty())
        {
            return BadRequest(res, "tableid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetTablePreviousHorizontalConnectedTable(PARAMS(std::stoi(tableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetVRVivePointerHand", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetVRVivePointerHand(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetContainerBuyLimit", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string wareid = req.get_param_value("wareid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetContainerBuyLimit(PARAMS(std::stoll(containerid), wareid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetContainerSellLimit", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string wareid = req.get_param_value("wareid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetContainerSellLimit(PARAMS(std::stoll(containerid), wareid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCurrentLanguage", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetCurrentLanguage(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetEditBoxTextOffsetY", HAN_FN {
        std::string editboxid = req.get_param_value("editboxid");
        if (editboxid.empty())
        {
            return BadRequest(res, "editboxid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetEditBoxTextOffsetY(PARAMS(std::stoi(editboxid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetEntityCombinedSkill", HAN_FN {
        std::string entityid = req.get_param_value("entityid");
        std::string role = req.get_param_value("role");
        std::string postid = req.get_param_value("postid");
        if (entityid.empty())
        {
            return BadRequest(res, "entityid must be set");
        }
        if (role.empty())
        {
            return BadRequest(res, "role must be set");
        }
        if (postid.empty())
        {
            return BadRequest(res, "postid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetEntityCombinedSkill(PARAMS(std::stoll(entityid), role.c_str(), postid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPersonCombinedSkill", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string person = req.get_param_value("person");
        std::string role = req.get_param_value("role");
        std::string postid = req.get_param_value("postid");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (person.empty())
        {
            return BadRequest(res, "person must be set");
        }
        if (role.empty())
        {
            return BadRequest(res, "role must be set");
        }
        if (postid.empty())
        {
            return BadRequest(res, "postid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetPersonCombinedSkill(PARAMS(std::stoll(controllableid), std::stoll(person), role.c_str(), postid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPersonTier", HAN_FN {
        std::string npc = req.get_param_value("npc");
        std::string role = req.get_param_value("role");
        std::string controllableid = req.get_param_value("controllableid");
        if (npc.empty())
        {
            return BadRequest(res, "npc must be set");
        }
        if (role.empty())
        {
            return BadRequest(res, "role must be set");
        }
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetPersonTier(PARAMS(std::stoll(npc), role.c_str(), std::stoll(controllableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetRequestedLanguage", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetRequestedLanguage(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetShipCombinedSkill", HAN_FN {
        std::string shipid = req.get_param_value("shipid");
        if (shipid.empty())
        {
            return BadRequest(res, "shipid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetShipCombinedSkill(PARAMS(std::stoll(shipid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetSliderCellAccuracyOverride", HAN_FN {
        std::string slidercellid = req.get_param_value("slidercellid");
        if (slidercellid.empty())
        {
            return BadRequest(res, "slidercellid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetSliderCellAccuracyOverride(PARAMS(std::stoi(slidercellid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetUIRelation", HAN_FN {
        std::string fromfactionid = req.get_param_value("fromfactionid");
        std::string tofactionid = req.get_param_value("tofactionid");
        if (fromfactionid.empty())
        {
            return BadRequest(res, "fromfactionid must be set");
        }
        if (tofactionid.empty())
        {
            return BadRequest(res, "tofactionid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetUIRelation(PARAMS(fromfactionid.c_str(), tofactionid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetBuildPlotPayment", HAN_FN {
        std::string stationid = req.get_param_value("stationid");
        if (stationid.empty())
        {
            return BadRequest(res, "stationid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetBuildPlotPayment(PARAMS(std::stoll(stationid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetBuildWarePrice", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string warename = req.get_param_value("warename");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (warename.empty())
        {
            return BadRequest(res, "warename must be set");
        }
        try {
            SET_CONTENT(ffijson::GetBuildWarePrice(PARAMS(std::stoll(containerid), warename.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetBuilderHiringFee", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetBuilderHiringFee(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCreditsDueFromPlayerTrades", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetCreditsDueFromPlayerTrades(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCustomGameStartMoneyProperty", HAN_FN {
        std::string id = req.get_param_value("id");
        std::string propertyid = req.get_param_value("propertyid");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (propertyid.empty())
        {
            return BadRequest(res, "propertyid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCustomGameStartMoneyProperty(PARAMS(id.c_str(), propertyid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetRepairPrice", HAN_FN {
        std::string componenttorepairid = req.get_param_value("componenttorepairid");
        std::string containerid = req.get_param_value("containerid");
        if (componenttorepairid.empty())
        {
            return BadRequest(res, "componenttorepairid must be set");
        }
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetRepairPrice(PARAMS(std::stoll(componenttorepairid), std::stoll(containerid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetSupplyBudget", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetSupplyBudget(PARAMS(std::stoll(containerid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetBuildMapConstructionPlan", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string usestoredplan = req.get_param_value("usestoredplan");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (usestoredplan.empty())
        {
            return BadRequest(res, "usestoredplan must be set");
        }
        try {
            SET_CONTENT(ffijson::GetBuildMapConstructionPlan(PARAMS(std::stoll(holomapid), std::stoll(defensibleid), std::stoi(usestoredplan))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetConstructionMapVenturePlatform", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string venturedockidx = req.get_param_value("venturedockidx");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (venturedockidx.empty())
        {
            return BadRequest(res, "venturedockidx must be set");
        }
        try {
            SET_CONTENT(ffijson::GetConstructionMapVenturePlatform(PARAMS(std::stoll(holomapid), std::stoll(venturedockidx))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumAcceptedMissions", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetNumAcceptedMissions(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumBuildMapConstructionPlan", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string usestoredplan = req.get_param_value("usestoredplan");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (usestoredplan.empty())
        {
            return BadRequest(res, "usestoredplan must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumBuildMapConstructionPlan(PARAMS(std::stoll(holomapid), std::stoi(usestoredplan))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumNotifications", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetNumNotifications(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumPlannedStationModules", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string includeall = req.get_param_value("includeall");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (includeall.empty())
        {
            return BadRequest(res, "includeall must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumPlannedStationModules(PARAMS(std::stoll(defensibleid), std::stoi(includeall))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumPrimaryWeapons", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetNumPrimaryWeapons(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumSecondaryWeapons", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetNumSecondaryWeapons(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumTradeComputerOrders", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumTradeComputerOrders(PARAMS(std::stoll(controllableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumTurretSlots", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetNumTurretSlots(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumTurrets", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetNumTurrets(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumUpgradeSlots", HAN_FN {
        std::string destructibleid = req.get_param_value("destructibleid");
        std::string macroname = req.get_param_value("macroname");
        std::string upgradetypename = req.get_param_value("upgradetypename");
        if (destructibleid.empty())
        {
            return BadRequest(res, "destructibleid must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        if (upgradetypename.empty())
        {
            return BadRequest(res, "upgradetypename must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumUpgradeSlots(PARAMS(std::stoll(destructibleid), macroname.c_str(), upgradetypename.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumVirtualUpgradeSlots", HAN_FN {
        std::string objectid = req.get_param_value("objectid");
        std::string macroname = req.get_param_value("macroname");
        std::string upgradetypename = req.get_param_value("upgradetypename");
        if (objectid.empty())
        {
            return BadRequest(res, "objectid must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        if (upgradetypename.empty())
        {
            return BadRequest(res, "upgradetypename must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumVirtualUpgradeSlots(PARAMS(std::stoll(objectid), macroname.c_str(), upgradetypename.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumWeaponSlots", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetNumWeaponSlots(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPlannedStationModules", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string includeall = req.get_param_value("includeall");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (includeall.empty())
        {
            return BadRequest(res, "includeall must be set");
        }
        try {
            SET_CONTENT(ffijson::GetPlannedStationModules(PARAMS(std::stoll(defensibleid), std::stoi(includeall))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetSelectedBuildMapEntry", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetSelectedBuildMapEntry(PARAMS(std::stoll(holomapid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetTobiiGazeFilterStrength", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetTobiiGazeFilterStrength(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetTobiiHeadFilterStrength", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetTobiiHeadFilterStrength(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/CreateOrder", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string orderid = req.get_param_value("orderid");
        std::string defaultorder = req.get_param_value("defaultorder");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (orderid.empty())
        {
            return BadRequest(res, "orderid must be set");
        }
        if (defaultorder.empty())
        {
            return BadRequest(res, "defaultorder must be set");
        }
        try {
            SET_CONTENT(ffijson::CreateOrder(PARAMS(std::stoll(controllableid), orderid.c_str(), std::stoi(defaultorder))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/CreateOrder2", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string orderid = req.get_param_value("orderid");
        std::string defaultorder = req.get_param_value("defaultorder");
        std::string isoverride = req.get_param_value("isoverride");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (orderid.empty())
        {
            return BadRequest(res, "orderid must be set");
        }
        if (defaultorder.empty())
        {
            return BadRequest(res, "defaultorder must be set");
        }
        if (isoverride.empty())
        {
            return BadRequest(res, "isoverride must be set");
        }
        try {
            SET_CONTENT(ffijson::CreateOrder2(PARAMS(std::stoll(controllableid), orderid.c_str(), std::stoi(defaultorder), std::stoi(isoverride))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetActivePrimaryWeaponGroup", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetActivePrimaryWeaponGroup(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetActiveSecondaryWeaponGroup", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetActiveSecondaryWeaponGroup(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAllBlacklists", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetAllBlacklists(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAllBoardingBehaviours", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetAllBoardingBehaviours(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAllBoardingPhases", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetAllBoardingPhases(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAllControlPosts", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetAllControlPosts(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAllCountermeasures", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetAllCountermeasures(PARAMS(std::stoll(defensibleid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAllEquipment", HAN_FN {
        std::string playerblueprint = req.get_param_value("playerblueprint");
        if (playerblueprint.empty())
        {
            return BadRequest(res, "playerblueprint must be set");
        }
        try {
            SET_CONTENT(ffijson::GetAllEquipment(PARAMS(std::stoi(playerblueprint))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAllEquipmentModProperties", HAN_FN {
        std::string equipmentmodclass = req.get_param_value("equipmentmodclass");
        if (equipmentmodclass.empty())
        {
            return BadRequest(res, "equipmentmodclass must be set");
        }
        try {
            SET_CONTENT(ffijson::GetAllEquipmentModProperties(PARAMS(equipmentmodclass.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAllFactionShips", HAN_FN {
        std::string factionid = req.get_param_value("factionid");
        if (factionid.empty())
        {
            return BadRequest(res, "factionid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetAllFactionShips(PARAMS(factionid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAllFactionStations", HAN_FN {
        std::string factionid = req.get_param_value("factionid");
        if (factionid.empty())
        {
            return BadRequest(res, "factionid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetAllFactionStations(PARAMS(factionid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAllFactions", HAN_FN {
        std::string includehidden = req.get_param_value("includehidden");
        if (includehidden.empty())
        {
            return BadRequest(res, "includehidden must be set");
        }
        try {
            SET_CONTENT(ffijson::GetAllFactions(PARAMS(std::stoi(includehidden))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAllInventoryBombs", HAN_FN {
        std::string entityid = req.get_param_value("entityid");
        if (entityid.empty())
        {
            return BadRequest(res, "entityid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetAllInventoryBombs(PARAMS(std::stoll(entityid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAllLaserTowers", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetAllLaserTowers(PARAMS(std::stoll(defensibleid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAllMines", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetAllMines(PARAMS(std::stoll(defensibleid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAllMissiles", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetAllMissiles(PARAMS(std::stoll(defensibleid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAllModuleSets", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetAllModuleSets(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAllNavBeacons", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetAllNavBeacons(PARAMS(std::stoll(defensibleid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAllRaces", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetAllRaces(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAllResourceProbes", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetAllResourceProbes(PARAMS(std::stoll(defensibleid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAllResponsesToSignal", HAN_FN {
        std::string signalid = req.get_param_value("signalid");
        if (signalid.empty())
        {
            return BadRequest(res, "signalid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetAllResponsesToSignal(PARAMS(signalid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAllRoles", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetAllRoles(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAllSatellites", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetAllSatellites(PARAMS(std::stoll(defensibleid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAllShipMacros", HAN_FN {
        std::string playerblueprint = req.get_param_value("playerblueprint");
        if (playerblueprint.empty())
        {
            return BadRequest(res, "playerblueprint must be set");
        }
        try {
            SET_CONTENT(ffijson::GetAllShipMacros(PARAMS(std::stoi(playerblueprint))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAllSignals", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetAllSignals(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAllUnits", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string onlydrones = req.get_param_value("onlydrones");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (onlydrones.empty())
        {
            return BadRequest(res, "onlydrones must be set");
        }
        try {
            SET_CONTENT(ffijson::GetAllUnits(PARAMS(std::stoll(defensibleid), std::stoi(onlydrones))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAllowedWeaponSystems", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string orderidx = req.get_param_value("orderidx");
        std::string usedefault = req.get_param_value("usedefault");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (orderidx.empty())
        {
            return BadRequest(res, "orderidx must be set");
        }
        if (usedefault.empty())
        {
            return BadRequest(res, "usedefault must be set");
        }
        try {
            SET_CONTENT(ffijson::GetAllowedWeaponSystems(PARAMS(std::stoll(defensibleid), std::stoll(orderidx), std::stoi(usedefault))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAmmoStorage", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string ammotype = req.get_param_value("ammotype");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (ammotype.empty())
        {
            return BadRequest(res, "ammotype must be set");
        }
        try {
            SET_CONTENT(ffijson::GetAmmoStorage(PARAMS(std::stoll(defensibleid), ammotype.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAmountOfWareAvailable", HAN_FN {
        std::string wareid = req.get_param_value("wareid");
        std::string productionmoduleid = req.get_param_value("productionmoduleid");
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        if (productionmoduleid.empty())
        {
            return BadRequest(res, "productionmoduleid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetAmountOfWareAvailable(PARAMS(wareid.c_str(), std::stoll(productionmoduleid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAssignedConstructionVessels", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetAssignedConstructionVessels(PARAMS(std::stoll(containerid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAttackersOfBoardingOperation", HAN_FN {
        std::string defensibletargetid = req.get_param_value("defensibletargetid");
        std::string boarderfactionid = req.get_param_value("boarderfactionid");
        if (defensibletargetid.empty())
        {
            return BadRequest(res, "defensibletargetid must be set");
        }
        if (boarderfactionid.empty())
        {
            return BadRequest(res, "boarderfactionid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetAttackersOfBoardingOperation(PARAMS(std::stoll(defensibletargetid), boarderfactionid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAvailableClothingThemes", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetAvailableClothingThemes(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAvailableEquipment", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string classid = req.get_param_value("classid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (classid.empty())
        {
            return BadRequest(res, "classid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetAvailableEquipment(PARAMS(std::stoll(containerid), classid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAvailableEquipmentMods", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetAvailableEquipmentMods(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAvailableLockboxes", HAN_FN {
        std::string entityid = req.get_param_value("entityid");
        if (entityid.empty())
        {
            return BadRequest(res, "entityid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetAvailableLockboxes(PARAMS(std::stoll(entityid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetAvailablePaintThemes", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetAvailablePaintThemes(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetBlueprints", HAN_FN {
        std::string set = req.get_param_value("set");
        std::string category = req.get_param_value("category");
        std::string macroname = req.get_param_value("macroname");
        if (set.empty())
        {
            return BadRequest(res, "set must be set");
        }
        if (category.empty())
        {
            return BadRequest(res, "category must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        try {
            SET_CONTENT(ffijson::GetBlueprints(PARAMS(set.c_str(), category.c_str(), macroname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetBoardingCasualtiesOfTier", HAN_FN {
        std::string marinetierskilllevel = req.get_param_value("marinetierskilllevel");
        std::string defensibletargetid = req.get_param_value("defensibletargetid");
        std::string boarderfactionid = req.get_param_value("boarderfactionid");
        if (marinetierskilllevel.empty())
        {
            return BadRequest(res, "marinetierskilllevel must be set");
        }
        if (defensibletargetid.empty())
        {
            return BadRequest(res, "defensibletargetid must be set");
        }
        if (boarderfactionid.empty())
        {
            return BadRequest(res, "boarderfactionid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetBoardingCasualtiesOfTier(PARAMS(std::stoi(marinetierskilllevel), std::stoll(defensibletargetid), boarderfactionid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetBoardingStrengthFromOperation", HAN_FN {
        std::string defensibletargetid = req.get_param_value("defensibletargetid");
        std::string boarderfactionid = req.get_param_value("boarderfactionid");
        if (defensibletargetid.empty())
        {
            return BadRequest(res, "defensibletargetid must be set");
        }
        if (boarderfactionid.empty())
        {
            return BadRequest(res, "boarderfactionid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetBoardingStrengthFromOperation(PARAMS(std::stoll(defensibletargetid), boarderfactionid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetBoardingStrengthOfControllableTierAmounts", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string nummarinetiers = req.get_param_value("nummarinetiers");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (nummarinetiers.empty())
        {
            return BadRequest(res, "nummarinetiers must be set");
        }
        try {
            SET_CONTENT(ffijson::GetBoardingStrengthOfControllableTierAmounts(PARAMS(std::stoll(controllableid), std::stoll(nummarinetiers))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetBuildModules", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetBuildModules(PARAMS(std::stoll(containerid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetBuildSequenceResources", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetBuildSequenceResources(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetBuildTasks", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string buildmoduleid = req.get_param_value("buildmoduleid");
        std::string isinprogress = req.get_param_value("isinprogress");
        std::string includeupgrade = req.get_param_value("includeupgrade");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (buildmoduleid.empty())
        {
            return BadRequest(res, "buildmoduleid must be set");
        }
        if (isinprogress.empty())
        {
            return BadRequest(res, "isinprogress must be set");
        }
        if (includeupgrade.empty())
        {
            return BadRequest(res, "includeupgrade must be set");
        }
        try {
            SET_CONTENT(ffijson::GetBuildTasks(PARAMS(std::stoll(containerid), std::stoll(buildmoduleid), std::stoi(isinprogress), std::stoi(includeupgrade))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCargo", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string tags = req.get_param_value("tags");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (tags.empty())
        {
            return BadRequest(res, "tags must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCargo(PARAMS(std::stoll(containerid), tags.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCargoStatistics", HAN_FN {
        std::string numdatapoints = req.get_param_value("numdatapoints");
        if (numdatapoints.empty())
        {
            return BadRequest(res, "numdatapoints must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCargoStatistics(PARAMS(std::stoll(numdatapoints))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCargoTransportTypes", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string merge = req.get_param_value("merge");
        std::string aftertradeorders = req.get_param_value("aftertradeorders");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (merge.empty())
        {
            return BadRequest(res, "merge must be set");
        }
        if (aftertradeorders.empty())
        {
            return BadRequest(res, "aftertradeorders must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCargoTransportTypes(PARAMS(std::stoll(containerid), std::stoi(merge), std::stoi(aftertradeorders))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCloseOnUnhandledClickFrames", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetCloseOnUnhandledClickFrames(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetConstructionPlanInvalidPatches", HAN_FN {
        std::string constructionplanid = req.get_param_value("constructionplanid");
        if (constructionplanid.empty())
        {
            return BadRequest(res, "constructionplanid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetConstructionPlanInvalidPatches(PARAMS(constructionplanid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetConstructionPlans", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetConstructionPlans(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetContainerAllowedBuildFactions", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetContainerAllowedBuildFactions(PARAMS(std::stoll(containerid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetContainerBuildResources", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetContainerBuildResources(PARAMS(std::stoll(containerid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetContainerBuilderMacros", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetContainerBuilderMacros(PARAMS(std::stoll(containerid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetContainerStockLimitOverrides", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetContainerStockLimitOverrides(PARAMS(std::stoll(containerid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetContainerWareReservations", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetContainerWareReservations(PARAMS(std::stoll(containerid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCurrentMissionOffers", HAN_FN {
        std::string showninbbs = req.get_param_value("showninbbs");
        if (showninbbs.empty())
        {
            return BadRequest(res, "showninbbs must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCurrentMissionOffers(PARAMS(std::stoi(showninbbs))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCurrentVentureShips", HAN_FN {
        std::string ventureplatformid = req.get_param_value("ventureplatformid");
        if (ventureplatformid.empty())
        {
            return BadRequest(res, "ventureplatformid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCurrentVentureShips(PARAMS(std::stoll(ventureplatformid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCustomGameStartBlueprintDefaultProperty", HAN_FN {
        std::string id = req.get_param_value("id");
        std::string propertyid = req.get_param_value("propertyid");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (propertyid.empty())
        {
            return BadRequest(res, "propertyid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCustomGameStartBlueprintDefaultProperty(PARAMS(id.c_str(), propertyid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCustomGameStartBlueprintProperty", HAN_FN {
        std::string id = req.get_param_value("id");
        std::string propertyid = req.get_param_value("propertyid");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (propertyid.empty())
        {
            return BadRequest(res, "propertyid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCustomGameStartBlueprintProperty(PARAMS(id.c_str(), propertyid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCustomGameStartEncyclopediaProperty", HAN_FN {
        std::string id = req.get_param_value("id");
        std::string propertyid = req.get_param_value("propertyid");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (propertyid.empty())
        {
            return BadRequest(res, "propertyid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCustomGameStartEncyclopediaProperty(PARAMS(id.c_str(), propertyid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCustomGameStartEncyclopediaPropertyCounts", HAN_FN {
        std::string id = req.get_param_value("id");
        std::string propertyid = req.get_param_value("propertyid");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (propertyid.empty())
        {
            return BadRequest(res, "propertyid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCustomGameStartEncyclopediaPropertyCounts(PARAMS(id.c_str(), propertyid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCustomGameStartInventoryDefaultProperty", HAN_FN {
        std::string id = req.get_param_value("id");
        std::string propertyid = req.get_param_value("propertyid");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (propertyid.empty())
        {
            return BadRequest(res, "propertyid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCustomGameStartInventoryDefaultProperty(PARAMS(id.c_str(), propertyid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCustomGameStartInventoryProperty", HAN_FN {
        std::string id = req.get_param_value("id");
        std::string propertyid = req.get_param_value("propertyid");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (propertyid.empty())
        {
            return BadRequest(res, "propertyid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCustomGameStartInventoryProperty(PARAMS(id.c_str(), propertyid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCustomGameStartRelationsProperty", HAN_FN {
        std::string id = req.get_param_value("id");
        std::string propertyid = req.get_param_value("propertyid");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (propertyid.empty())
        {
            return BadRequest(res, "propertyid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCustomGameStartRelationsProperty(PARAMS(id.c_str(), propertyid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCustomGameStartRelationsPropertyCounts", HAN_FN {
        std::string id = req.get_param_value("id");
        std::string propertyid = req.get_param_value("propertyid");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (propertyid.empty())
        {
            return BadRequest(res, "propertyid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCustomGameStartRelationsPropertyCounts(PARAMS(id.c_str(), propertyid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCustomGameStartResearchProperty", HAN_FN {
        std::string id = req.get_param_value("id");
        std::string propertyid = req.get_param_value("propertyid");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (propertyid.empty())
        {
            return BadRequest(res, "propertyid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCustomGameStartResearchProperty(PARAMS(id.c_str(), propertyid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCustomGameStartResearchPropertyCounts", HAN_FN {
        std::string id = req.get_param_value("id");
        std::string propertyid = req.get_param_value("propertyid");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (propertyid.empty())
        {
            return BadRequest(res, "propertyid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCustomGameStartResearchPropertyCounts(PARAMS(id.c_str(), propertyid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetDamagedSubComponents", HAN_FN {
        std::string objectid = req.get_param_value("objectid");
        if (objectid.empty())
        {
            return BadRequest(res, "objectid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetDamagedSubComponents(PARAMS(std::stoll(objectid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetDefaultCountermeasureStorageCapacity", HAN_FN {
        std::string macroname = req.get_param_value("macroname");
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        try {
            SET_CONTENT(ffijson::GetDefaultCountermeasureStorageCapacity(PARAMS(macroname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetDefaultMissileStorageCapacity", HAN_FN {
        std::string macroname = req.get_param_value("macroname");
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        try {
            SET_CONTENT(ffijson::GetDefaultMissileStorageCapacity(PARAMS(macroname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetDefensibleActiveWeaponGroup", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string primary = req.get_param_value("primary");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (primary.empty())
        {
            return BadRequest(res, "primary must be set");
        }
        try {
            SET_CONTENT(ffijson::GetDefensibleActiveWeaponGroup(PARAMS(std::stoll(defensibleid), std::stoi(primary))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetDefensibleDPS", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string primary = req.get_param_value("primary");
        std::string secondary = req.get_param_value("secondary");
        std::string lasers = req.get_param_value("lasers");
        std::string missiles = req.get_param_value("missiles");
        std::string turrets = req.get_param_value("turrets");
        std::string includeheat = req.get_param_value("includeheat");
        std::string includeinactive = req.get_param_value("includeinactive");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (primary.empty())
        {
            return BadRequest(res, "primary must be set");
        }
        if (secondary.empty())
        {
            return BadRequest(res, "secondary must be set");
        }
        if (lasers.empty())
        {
            return BadRequest(res, "lasers must be set");
        }
        if (missiles.empty())
        {
            return BadRequest(res, "missiles must be set");
        }
        if (turrets.empty())
        {
            return BadRequest(res, "turrets must be set");
        }
        if (includeheat.empty())
        {
            return BadRequest(res, "includeheat must be set");
        }
        if (includeinactive.empty())
        {
            return BadRequest(res, "includeinactive must be set");
        }
        try {
            SET_CONTENT(ffijson::GetDefensibleDPS(PARAMS(std::stoll(defensibleid), std::stoi(primary), std::stoi(secondary), std::stoi(lasers), std::stoi(missiles), std::stoi(turrets), std::stoi(includeheat), std::stoi(includeinactive))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetDefensibleDeployableCapacity", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetDefensibleDeployableCapacity(PARAMS(std::stoll(defensibleid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetDockedShips", HAN_FN {
        std::string dockingbayorcontainerid = req.get_param_value("dockingbayorcontainerid");
        std::string factionid = req.get_param_value("factionid");
        if (dockingbayorcontainerid.empty())
        {
            return BadRequest(res, "dockingbayorcontainerid must be set");
        }
        if (factionid.empty())
        {
            return BadRequest(res, "factionid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetDockedShips(PARAMS(std::stoll(dockingbayorcontainerid), factionid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetDroneModes", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string dronetype = req.get_param_value("dronetype");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (dronetype.empty())
        {
            return BadRequest(res, "dronetype must be set");
        }
        try {
            SET_CONTENT(ffijson::GetDroneModes(PARAMS(std::stoll(defensibleid), dronetype.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetDropDownOptionHeight", HAN_FN {
        std::string dropdownid = req.get_param_value("dropdownid");
        if (dropdownid.empty())
        {
            return BadRequest(res, "dropdownid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetDropDownOptionHeight(PARAMS(std::stoi(dropdownid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetDropDownOptionWidth", HAN_FN {
        std::string dropdownid = req.get_param_value("dropdownid");
        if (dropdownid.empty())
        {
            return BadRequest(res, "dropdownid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetDropDownOptionWidth(PARAMS(std::stoi(dropdownid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetDropDownOptions", HAN_FN {
        std::string dropdownid = req.get_param_value("dropdownid");
        if (dropdownid.empty())
        {
            return BadRequest(res, "dropdownid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetDropDownOptions(PARAMS(std::stoi(dropdownid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetEditBoxTextOffsetX", HAN_FN {
        std::string editboxid = req.get_param_value("editboxid");
        if (editboxid.empty())
        {
            return BadRequest(res, "editboxid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetEditBoxTextOffsetX(PARAMS(std::stoi(editboxid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetFormationShapes", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetFormationShapes(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetFreeCountermeasureStorageAfterTradeOrders", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetFreeCountermeasureStorageAfterTradeOrders(PARAMS(std::stoll(defensibleid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetFreeDeployableStorageAfterTradeOrders", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetFreeDeployableStorageAfterTradeOrders(PARAMS(std::stoll(defensibleid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetFreeMissileStorageAfterTradeOrders", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetFreeMissileStorageAfterTradeOrders(PARAMS(std::stoll(defensibleid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetFreePeopleCapacity", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetFreePeopleCapacity(PARAMS(std::stoll(controllableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetGraphData", HAN_FN {
        std::string graphid = req.get_param_value("graphid");
        std::string datarecordidx = req.get_param_value("datarecordidx");
        if (graphid.empty())
        {
            return BadRequest(res, "graphid must be set");
        }
        if (datarecordidx.empty())
        {
            return BadRequest(res, "datarecordidx must be set");
        }
        try {
            SET_CONTENT(ffijson::GetGraphData(PARAMS(std::stoi(graphid), std::stoll(datarecordidx))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetGraphDataRecords", HAN_FN {
        std::string graphid = req.get_param_value("graphid");
        if (graphid.empty())
        {
            return BadRequest(res, "graphid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetGraphDataRecords(PARAMS(std::stoi(graphid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetGraphIcons", HAN_FN {
        std::string graphid = req.get_param_value("graphid");
        if (graphid.empty())
        {
            return BadRequest(res, "graphid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetGraphIcons(PARAMS(std::stoi(graphid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetGraphType", HAN_FN {
        std::string graphid = req.get_param_value("graphid");
        if (graphid.empty())
        {
            return BadRequest(res, "graphid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetGraphType(PARAMS(std::stoi(graphid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetHQs", HAN_FN {
        std::string factionid = req.get_param_value("factionid");
        if (factionid.empty())
        {
            return BadRequest(res, "factionid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetHQs(PARAMS(factionid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetIllegalToFactions", HAN_FN {
        std::string wareid = req.get_param_value("wareid");
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetIllegalToFactions(PARAMS(wareid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetInventoryPaintMods", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetInventoryPaintMods(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetLUTMode", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetLUTMode(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetLanguages", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetLanguages(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetLibraryEntryAliases", HAN_FN {
        std::string librarytypeid = req.get_param_value("librarytypeid");
        std::string id = req.get_param_value("id");
        if (librarytypeid.empty())
        {
            return BadRequest(res, "librarytypeid must be set");
        }
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        try {
            SET_CONTENT(ffijson::GetLibraryEntryAliases(PARAMS(librarytypeid.c_str(), id.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetLoadoutCounts", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string macroname = req.get_param_value("macroname");
        std::string loadoutid = req.get_param_value("loadoutid");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        if (loadoutid.empty())
        {
            return BadRequest(res, "loadoutid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetLoadoutCounts(PARAMS(std::stoll(defensibleid), macroname.c_str(), loadoutid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetLoadoutInvalidPatches", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string macroname = req.get_param_value("macroname");
        std::string loadoutid = req.get_param_value("loadoutid");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        if (loadoutid.empty())
        {
            return BadRequest(res, "loadoutid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetLoadoutInvalidPatches(PARAMS(std::stoll(defensibleid), macroname.c_str(), loadoutid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetLoadoutsInfo", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        std::string macroname = req.get_param_value("macroname");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        try {
            SET_CONTENT(ffijson::GetLoadoutsInfo(PARAMS(std::stoll(componentid), macroname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetMacroDeployableCapacity", HAN_FN {
        std::string macroname = req.get_param_value("macroname");
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        try {
            SET_CONTENT(ffijson::GetMacroDeployableCapacity(PARAMS(macroname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetMacroMissileCapacity", HAN_FN {
        std::string macroname = req.get_param_value("macroname");
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        try {
            SET_CONTENT(ffijson::GetMacroMissileCapacity(PARAMS(macroname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetMapComponentMissions", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string componentid = req.get_param_value("componentid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetMapComponentMissions(PARAMS(std::stoll(holomapid), std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetMapRenderedComponents", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetMapRenderedComponents(PARAMS(std::stoll(holomapid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetMapSelectedComponents", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetMapSelectedComponents(PARAMS(std::stoll(holomapid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetMaxProductionStorage", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetMaxProductionStorage(PARAMS(std::stoll(containerid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetMessages", HAN_FN {
        std::string start = req.get_param_value("start");
        std::string count = req.get_param_value("count");
        std::string categoryname = req.get_param_value("categoryname");
        if (start.empty())
        {
            return BadRequest(res, "start must be set");
        }
        if (count.empty())
        {
            return BadRequest(res, "count must be set");
        }
        if (categoryname.empty())
        {
            return BadRequest(res, "categoryname must be set");
        }
        try {
            SET_CONTENT(ffijson::GetMessages(PARAMS(std::stoll(start), std::stoll(count), categoryname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetMissileCargo", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetMissileCargo(PARAMS(std::stoll(containerid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetMissingBuildResources", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetMissingBuildResources(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetMissingLoadoutResources", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetMissingLoadoutResources(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetMissionThreadSubMissions", HAN_FN {
        std::string missionid = req.get_param_value("missionid");
        if (missionid.empty())
        {
            return BadRequest(res, "missionid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetMissionThreadSubMissions(PARAMS(std::stoll(missionid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetModuleNeededResources", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string cp_idx = req.get_param_value("cp_idx");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (cp_idx.empty())
        {
            return BadRequest(res, "cp_idx must be set");
        }
        try {
            SET_CONTENT(ffijson::GetModuleNeededResources(PARAMS(std::stoll(holomapid), std::stoll(cp_idx))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetModuleRecycledResources", HAN_FN {
        std::string moduleid = req.get_param_value("moduleid");
        if (moduleid.empty())
        {
            return BadRequest(res, "moduleid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetModuleRecycledResources(PARAMS(std::stoll(moduleid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetMoonInfo", HAN_FN {
        std::string clusterid = req.get_param_value("clusterid");
        std::string planetidx = req.get_param_value("planetidx");
        if (clusterid.empty())
        {
            return BadRequest(res, "clusterid must be set");
        }
        if (planetidx.empty())
        {
            return BadRequest(res, "planetidx must be set");
        }
        try {
            SET_CONTENT(ffijson::GetMoonInfo(PARAMS(std::stoll(clusterid), std::stoll(planetidx))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetMouseHUDModeOption", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetMouseHUDModeOption(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNPCAccountStatistics", HAN_FN {
        std::string entityid = req.get_param_value("entityid");
        std::string starttime = req.get_param_value("starttime");
        std::string endtime = req.get_param_value("endtime");
        if (entityid.empty())
        {
            return BadRequest(res, "entityid must be set");
        }
        if (starttime.empty())
        {
            return BadRequest(res, "starttime must be set");
        }
        if (endtime.empty())
        {
            return BadRequest(res, "endtime must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNPCAccountStatistics(PARAMS(std::stoll(entityid), std::stol(starttime), std::stol(endtime))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNotificationTypes", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetNotificationTypes(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumAllBlacklists", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetNumAllBlacklists(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumAllBoardingBehaviours", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetNumAllBoardingBehaviours(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumAllBoardingPhases", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetNumAllBoardingPhases(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumAllControlPosts", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetNumAllControlPosts(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumAllCountermeasures", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumAllCountermeasures(PARAMS(std::stoll(defensibleid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumAllEquipment", HAN_FN {
        std::string playerblueprint = req.get_param_value("playerblueprint");
        if (playerblueprint.empty())
        {
            return BadRequest(res, "playerblueprint must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumAllEquipment(PARAMS(std::stoi(playerblueprint))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumAllEquipmentModProperties", HAN_FN {
        std::string equipmentmodclass = req.get_param_value("equipmentmodclass");
        if (equipmentmodclass.empty())
        {
            return BadRequest(res, "equipmentmodclass must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumAllEquipmentModProperties(PARAMS(equipmentmodclass.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumAllFactionShips", HAN_FN {
        std::string factionid = req.get_param_value("factionid");
        if (factionid.empty())
        {
            return BadRequest(res, "factionid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumAllFactionShips(PARAMS(factionid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumAllFactionStations", HAN_FN {
        std::string factionid = req.get_param_value("factionid");
        if (factionid.empty())
        {
            return BadRequest(res, "factionid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumAllFactionStations(PARAMS(factionid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumAllFactions", HAN_FN {
        std::string includehidden = req.get_param_value("includehidden");
        if (includehidden.empty())
        {
            return BadRequest(res, "includehidden must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumAllFactions(PARAMS(std::stoi(includehidden))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumAllInventoryBombs", HAN_FN {
        std::string entityid = req.get_param_value("entityid");
        if (entityid.empty())
        {
            return BadRequest(res, "entityid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumAllInventoryBombs(PARAMS(std::stoll(entityid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumAllLaserTowers", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumAllLaserTowers(PARAMS(std::stoll(defensibleid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumAllMines", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumAllMines(PARAMS(std::stoll(defensibleid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumAllMissiles", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumAllMissiles(PARAMS(std::stoll(defensibleid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumAllModuleSets", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetNumAllModuleSets(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumAllNavBeacons", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumAllNavBeacons(PARAMS(std::stoll(defensibleid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumAllRaces", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetNumAllRaces(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumAllResourceProbes", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumAllResourceProbes(PARAMS(std::stoll(defensibleid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumAllResponsesToSignal", HAN_FN {
        std::string signalid = req.get_param_value("signalid");
        if (signalid.empty())
        {
            return BadRequest(res, "signalid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumAllResponsesToSignal(PARAMS(signalid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumAllRoles", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetNumAllRoles(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumAllSatellites", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumAllSatellites(PARAMS(std::stoll(defensibleid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumAllShipMacros", HAN_FN {
        std::string playerblueprint = req.get_param_value("playerblueprint");
        if (playerblueprint.empty())
        {
            return BadRequest(res, "playerblueprint must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumAllShipMacros(PARAMS(std::stoi(playerblueprint))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumAllSignals", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetNumAllSignals(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumAllUnits", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string onlydrones = req.get_param_value("onlydrones");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (onlydrones.empty())
        {
            return BadRequest(res, "onlydrones must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumAllUnits(PARAMS(std::stoll(defensibleid), std::stoi(onlydrones))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumAllowedWeaponSystems", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetNumAllowedWeaponSystems(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumAmmoStorage", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string ammotype = req.get_param_value("ammotype");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (ammotype.empty())
        {
            return BadRequest(res, "ammotype must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumAmmoStorage(PARAMS(std::stoll(defensibleid), ammotype.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumAssignedConstructionVessels", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumAssignedConstructionVessels(PARAMS(std::stoll(containerid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumAttackersOfBoardingOperation", HAN_FN {
        std::string defensibletargetid = req.get_param_value("defensibletargetid");
        std::string boarderfactionid = req.get_param_value("boarderfactionid");
        if (defensibletargetid.empty())
        {
            return BadRequest(res, "defensibletargetid must be set");
        }
        if (boarderfactionid.empty())
        {
            return BadRequest(res, "boarderfactionid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumAttackersOfBoardingOperation(PARAMS(std::stoll(defensibletargetid), boarderfactionid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumAvailableClothingThemes", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetNumAvailableClothingThemes(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumAvailableEquipment", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string classid = req.get_param_value("classid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (classid.empty())
        {
            return BadRequest(res, "classid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumAvailableEquipment(PARAMS(std::stoll(containerid), classid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumAvailableEquipmentMods", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetNumAvailableEquipmentMods(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumAvailableLockboxes", HAN_FN {
        std::string entityid = req.get_param_value("entityid");
        if (entityid.empty())
        {
            return BadRequest(res, "entityid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumAvailableLockboxes(PARAMS(std::stoll(entityid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumAvailablePaintThemes", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetNumAvailablePaintThemes(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumBlueprints", HAN_FN {
        std::string set = req.get_param_value("set");
        std::string category = req.get_param_value("category");
        std::string macroname = req.get_param_value("macroname");
        if (set.empty())
        {
            return BadRequest(res, "set must be set");
        }
        if (category.empty())
        {
            return BadRequest(res, "category must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumBlueprints(PARAMS(set.c_str(), category.c_str(), macroname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumBoardingMarinesFromOperation", HAN_FN {
        std::string defensibletargetid = req.get_param_value("defensibletargetid");
        std::string boarderfactionid = req.get_param_value("boarderfactionid");
        if (defensibletargetid.empty())
        {
            return BadRequest(res, "defensibletargetid must be set");
        }
        if (boarderfactionid.empty())
        {
            return BadRequest(res, "boarderfactionid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumBoardingMarinesFromOperation(PARAMS(std::stoll(defensibletargetid), boarderfactionid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumBuildModules", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumBuildModules(PARAMS(std::stoll(containerid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumBuildTasks", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string buildmoduleid = req.get_param_value("buildmoduleid");
        std::string isinprogress = req.get_param_value("isinprogress");
        std::string includeupgrade = req.get_param_value("includeupgrade");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (buildmoduleid.empty())
        {
            return BadRequest(res, "buildmoduleid must be set");
        }
        if (isinprogress.empty())
        {
            return BadRequest(res, "isinprogress must be set");
        }
        if (includeupgrade.empty())
        {
            return BadRequest(res, "includeupgrade must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumBuildTasks(PARAMS(std::stoll(containerid), std::stoll(buildmoduleid), std::stoi(isinprogress), std::stoi(includeupgrade))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumCargo", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string tags = req.get_param_value("tags");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (tags.empty())
        {
            return BadRequest(res, "tags must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumCargo(PARAMS(std::stoll(containerid), tags.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumCargoStatistics", HAN_FN {
        std::string containerorspaceid = req.get_param_value("containerorspaceid");
        std::string starttime = req.get_param_value("starttime");
        std::string endtime = req.get_param_value("endtime");
        std::string numdatapoints = req.get_param_value("numdatapoints");
        if (containerorspaceid.empty())
        {
            return BadRequest(res, "containerorspaceid must be set");
        }
        if (starttime.empty())
        {
            return BadRequest(res, "starttime must be set");
        }
        if (endtime.empty())
        {
            return BadRequest(res, "endtime must be set");
        }
        if (numdatapoints.empty())
        {
            return BadRequest(res, "numdatapoints must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumCargoStatistics(PARAMS(std::stoll(containerorspaceid), std::stol(starttime), std::stol(endtime), std::stoll(numdatapoints))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumCargoTransportTypes", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string merge = req.get_param_value("merge");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (merge.empty())
        {
            return BadRequest(res, "merge must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumCargoTransportTypes(PARAMS(std::stoll(containerid), std::stoi(merge))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumCloseOnUnhandledClickFrames", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetNumCloseOnUnhandledClickFrames(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumConstructionMapVenturePlatformDocks", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string ventureplatformidx = req.get_param_value("ventureplatformidx");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (ventureplatformidx.empty())
        {
            return BadRequest(res, "ventureplatformidx must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumConstructionMapVenturePlatformDocks(PARAMS(std::stoll(holomapid), std::stoll(ventureplatformidx))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumConstructionPlans", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetNumConstructionPlans(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumContainedKnownSpaces", HAN_FN {
        std::string spaceid = req.get_param_value("spaceid");
        if (spaceid.empty())
        {
            return BadRequest(res, "spaceid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumContainedKnownSpaces(PARAMS(std::stoll(spaceid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumContainedKnownUnreadSpaces", HAN_FN {
        std::string spaceid = req.get_param_value("spaceid");
        if (spaceid.empty())
        {
            return BadRequest(res, "spaceid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumContainedKnownUnreadSpaces(PARAMS(std::stoll(spaceid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumContainerAllowedBuildFactions", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumContainerAllowedBuildFactions(PARAMS(std::stoll(containerid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumContainerBuildResources", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumContainerBuildResources(PARAMS(std::stoll(containerid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumContainerBuilderMacros", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumContainerBuilderMacros(PARAMS(std::stoll(containerid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumContainerStockLimitOverrides", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumContainerStockLimitOverrides(PARAMS(std::stoll(containerid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumContainerWareReservations", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumContainerWareReservations(PARAMS(std::stoll(containerid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumCountermeasures", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetNumCountermeasures(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumCurrentMissionOffers", HAN_FN {
        std::string showninbbs = req.get_param_value("showninbbs");
        if (showninbbs.empty())
        {
            return BadRequest(res, "showninbbs must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumCurrentMissionOffers(PARAMS(std::stoi(showninbbs))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumDockedShips", HAN_FN {
        std::string dockingbayorcontainerid = req.get_param_value("dockingbayorcontainerid");
        std::string factionid = req.get_param_value("factionid");
        if (dockingbayorcontainerid.empty())
        {
            return BadRequest(res, "dockingbayorcontainerid must be set");
        }
        if (factionid.empty())
        {
            return BadRequest(res, "factionid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumDockedShips(PARAMS(std::stoll(dockingbayorcontainerid), factionid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumDroneModes", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string dronetype = req.get_param_value("dronetype");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (dronetype.empty())
        {
            return BadRequest(res, "dronetype must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumDroneModes(PARAMS(std::stoll(defensibleid), dronetype.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumDropDownOptions", HAN_FN {
        std::string dropdownid = req.get_param_value("dropdownid");
        if (dropdownid.empty())
        {
            return BadRequest(res, "dropdownid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumDropDownOptions(PARAMS(std::stoi(dropdownid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumFormationShapes", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetNumFormationShapes(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumGraphDataRecords", HAN_FN {
        std::string graphid = req.get_param_value("graphid");
        if (graphid.empty())
        {
            return BadRequest(res, "graphid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumGraphDataRecords(PARAMS(std::stoi(graphid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumGraphIcons", HAN_FN {
        std::string graphid = req.get_param_value("graphid");
        if (graphid.empty())
        {
            return BadRequest(res, "graphid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumGraphIcons(PARAMS(std::stoi(graphid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumHQs", HAN_FN {
        std::string factionid = req.get_param_value("factionid");
        if (factionid.empty())
        {
            return BadRequest(res, "factionid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumHQs(PARAMS(factionid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumIllegalToFactions", HAN_FN {
        std::string wareid = req.get_param_value("wareid");
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumIllegalToFactions(PARAMS(wareid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumInventoryPaintMods", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetNumInventoryPaintMods(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumLanguages", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetNumLanguages(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumLibraryEntryAliases", HAN_FN {
        std::string librarytypeid = req.get_param_value("librarytypeid");
        std::string id = req.get_param_value("id");
        if (librarytypeid.empty())
        {
            return BadRequest(res, "librarytypeid must be set");
        }
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumLibraryEntryAliases(PARAMS(librarytypeid.c_str(), id.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumLoadoutsInfo", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        std::string macroname = req.get_param_value("macroname");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumLoadoutsInfo(PARAMS(std::stoll(componentid), macroname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumMapComponentMissions", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string componentid = req.get_param_value("componentid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumMapComponentMissions(PARAMS(std::stoll(holomapid), std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumMapRenderedComponents", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumMapRenderedComponents(PARAMS(std::stoll(holomapid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumMapSelectedComponents", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumMapSelectedComponents(PARAMS(std::stoll(holomapid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumMaxProductionStorage", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumMaxProductionStorage(PARAMS(std::stoll(containerid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumMessages", HAN_FN {
        std::string categoryname = req.get_param_value("categoryname");
        std::string unknownBool = req.get_param_value("unknownBool");
        if (categoryname.empty())
        {
            return BadRequest(res, "categoryname must be set");
        }
        if (unknownBool.empty())
        {
            return BadRequest(res, "unknownBool must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumMessages(PARAMS(categoryname.c_str(), std::stoi(unknownBool))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumMissileCargo", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumMissileCargo(PARAMS(std::stoll(containerid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumMissingBuildResources2", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string numorders = req.get_param_value("numorders");
        std::string playercase = req.get_param_value("playercase");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (numorders.empty())
        {
            return BadRequest(res, "numorders must be set");
        }
        if (playercase.empty())
        {
            return BadRequest(res, "playercase must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumMissingBuildResources2(PARAMS(std::stoll(containerid), std::stoll(numorders), std::stoi(playercase))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumMissingLoadoutResources2", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string numorders = req.get_param_value("numorders");
        std::string playercase = req.get_param_value("playercase");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (numorders.empty())
        {
            return BadRequest(res, "numorders must be set");
        }
        if (playercase.empty())
        {
            return BadRequest(res, "playercase must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumMissingLoadoutResources2(PARAMS(std::stoll(containerid), std::stoll(numorders), std::stoi(playercase))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumMissionThreadSubMissions", HAN_FN {
        std::string missionid = req.get_param_value("missionid");
        if (missionid.empty())
        {
            return BadRequest(res, "missionid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumMissionThreadSubMissions(PARAMS(std::stoll(missionid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumModuleNeededResources", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string cp_idx = req.get_param_value("cp_idx");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (cp_idx.empty())
        {
            return BadRequest(res, "cp_idx must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumModuleNeededResources(PARAMS(std::stoll(holomapid), std::stoll(cp_idx))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumModuleRecycledResources", HAN_FN {
        std::string moduleid = req.get_param_value("moduleid");
        if (moduleid.empty())
        {
            return BadRequest(res, "moduleid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumModuleRecycledResources(PARAMS(std::stoll(moduleid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumNotificationTypes", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetNumNotificationTypes(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumObjectsWithSyncPoint", HAN_FN {
        std::string syncid = req.get_param_value("syncid");
        std::string onlyreached = req.get_param_value("onlyreached");
        if (syncid.empty())
        {
            return BadRequest(res, "syncid must be set");
        }
        if (onlyreached.empty())
        {
            return BadRequest(res, "onlyreached must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumObjectsWithSyncPoint(PARAMS(std::stoll(syncid), std::stoi(onlyreached))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumOrderDefinitions", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetNumOrderDefinitions(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumOrders", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumOrders(PARAMS(std::stoll(controllableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumPeopleAfterOrders", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string numorders = req.get_param_value("numorders");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (numorders.empty())
        {
            return BadRequest(res, "numorders must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumPeopleAfterOrders(PARAMS(std::stoll(controllableid), std::stoi(numorders))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumPersonSuitableControlPosts", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string personcontrollableid = req.get_param_value("personcontrollableid");
        std::string person = req.get_param_value("person");
        std::string free = req.get_param_value("free");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (personcontrollableid.empty())
        {
            return BadRequest(res, "personcontrollableid must be set");
        }
        if (person.empty())
        {
            return BadRequest(res, "person must be set");
        }
        if (free.empty())
        {
            return BadRequest(res, "free must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumPersonSuitableControlPosts(PARAMS(std::stoll(controllableid), std::stoll(personcontrollableid), std::stoll(person), std::stoi(free))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumPlannedLimitedModules", HAN_FN {
        std::string constructionplanid = req.get_param_value("constructionplanid");
        if (constructionplanid.empty())
        {
            return BadRequest(res, "constructionplanid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumPlannedLimitedModules(PARAMS(constructionplanid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumPlayerAlertSounds", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetNumPlayerAlertSounds(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumPlayerAlerts", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetNumPlayerAlerts(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumPlayerLogos", HAN_FN {
        std::string includestandard = req.get_param_value("includestandard");
        std::string includecustom = req.get_param_value("includecustom");
        if (includestandard.empty())
        {
            return BadRequest(res, "includestandard must be set");
        }
        if (includecustom.empty())
        {
            return BadRequest(res, "includecustom must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumPlayerLogos(PARAMS(std::stoi(includestandard), std::stoi(includecustom))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumPlayerShipBuildTasks", HAN_FN {
        std::string isinprogress = req.get_param_value("isinprogress");
        std::string includeupgrade = req.get_param_value("includeupgrade");
        if (isinprogress.empty())
        {
            return BadRequest(res, "isinprogress must be set");
        }
        if (includeupgrade.empty())
        {
            return BadRequest(res, "includeupgrade must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumPlayerShipBuildTasks(PARAMS(std::stoi(isinprogress), std::stoi(includeupgrade))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumRemovedConstructionPlanModules2", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string usestoredplan = req.get_param_value("usestoredplan");
        std::string checkupgrades = req.get_param_value("checkupgrades");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (usestoredplan.empty())
        {
            return BadRequest(res, "usestoredplan must be set");
        }
        if (checkupgrades.empty())
        {
            return BadRequest(res, "checkupgrades must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumRemovedConstructionPlanModules2(PARAMS(std::stoll(holomapid), std::stoll(defensibleid), std::stoi(usestoredplan), std::stoi(checkupgrades))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumRemovedStationModules", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumRemovedStationModules(PARAMS(std::stoll(defensibleid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumRepairResources", HAN_FN {
        std::string componenttorepairid = req.get_param_value("componenttorepairid");
        if (componenttorepairid.empty())
        {
            return BadRequest(res, "componenttorepairid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumRepairResources(PARAMS(std::stoll(componenttorepairid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumResearchModules", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumResearchModules(PARAMS(std::stoll(containerid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumSectorsByOwner", HAN_FN {
        std::string factionid = req.get_param_value("factionid");
        if (factionid.empty())
        {
            return BadRequest(res, "factionid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumSectorsByOwner(PARAMS(factionid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumShieldGroups", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumShieldGroups(PARAMS(std::stoll(defensibleid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumSkills", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetNumSkills(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumSoftwarePredecessors", HAN_FN {
        std::string softwarename = req.get_param_value("softwarename");
        if (softwarename.empty())
        {
            return BadRequest(res, "softwarename must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumSoftwarePredecessors(PARAMS(softwarename.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumSoftwareSlots", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string macroname = req.get_param_value("macroname");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumSoftwareSlots(PARAMS(std::stoll(controllableid), macroname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumSoundDevices", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetNumSoundDevices(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumStationModules", HAN_FN {
        std::string stationid = req.get_param_value("stationid");
        std::string includeconstructions = req.get_param_value("includeconstructions");
        std::string includewrecks = req.get_param_value("includewrecks");
        if (stationid.empty())
        {
            return BadRequest(res, "stationid must be set");
        }
        if (includeconstructions.empty())
        {
            return BadRequest(res, "includeconstructions must be set");
        }
        if (includewrecks.empty())
        {
            return BadRequest(res, "includewrecks must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumStationModules(PARAMS(std::stoll(stationid), std::stoi(includeconstructions), std::stoi(includewrecks))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumStationOverviewGraphWares", HAN_FN {
        std::string stationid = req.get_param_value("stationid");
        if (stationid.empty())
        {
            return BadRequest(res, "stationid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumStationOverviewGraphWares(PARAMS(std::stoll(stationid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumStoredUnits", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string cat = req.get_param_value("cat");
        std::string virtualammo = req.get_param_value("virtualammo");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (cat.empty())
        {
            return BadRequest(res, "cat must be set");
        }
        if (virtualammo.empty())
        {
            return BadRequest(res, "virtualammo must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumStoredUnits(PARAMS(std::stoll(defensibleid), cat.c_str(), std::stoi(virtualammo))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumSubComponents", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumSubComponents(PARAMS(std::stoll(containerid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumSuitableBuildProcessors", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string objectid = req.get_param_value("objectid");
        std::string macroname = req.get_param_value("macroname");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (objectid.empty())
        {
            return BadRequest(res, "objectid must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumSuitableBuildProcessors(PARAMS(std::stoll(containerid), std::stoll(objectid), macroname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumSuitableControlPosts", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string entityid = req.get_param_value("entityid");
        std::string free = req.get_param_value("free");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (entityid.empty())
        {
            return BadRequest(res, "entityid must be set");
        }
        if (free.empty())
        {
            return BadRequest(res, "free must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumSuitableControlPosts(PARAMS(std::stoll(controllableid), std::stoll(entityid), std::stoi(free))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumSupplyOrders", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string defaultorders = req.get_param_value("defaultorders");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (defaultorders.empty())
        {
            return BadRequest(res, "defaultorders must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumSupplyOrders(PARAMS(std::stoll(containerid), std::stoi(defaultorders))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumTableInitialMultiselectedRows", HAN_FN {
        std::string tableid = req.get_param_value("tableid");
        if (tableid.empty())
        {
            return BadRequest(res, "tableid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumTableInitialMultiselectedRows(PARAMS(std::stoi(tableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumTiersOfRole", HAN_FN {
        std::string role = req.get_param_value("role");
        if (role.empty())
        {
            return BadRequest(res, "role must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumTiersOfRole(PARAMS(role.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumTimeline", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetNumTimeline(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumTradeOfferStatistics", HAN_FN {
        std::string containerorspaceid = req.get_param_value("containerorspaceid");
        std::string starttime = req.get_param_value("starttime");
        std::string endtime = req.get_param_value("endtime");
        std::string numdatapoints = req.get_param_value("numdatapoints");
        if (containerorspaceid.empty())
        {
            return BadRequest(res, "containerorspaceid must be set");
        }
        if (starttime.empty())
        {
            return BadRequest(res, "starttime must be set");
        }
        if (endtime.empty())
        {
            return BadRequest(res, "endtime must be set");
        }
        if (numdatapoints.empty())
        {
            return BadRequest(res, "numdatapoints must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumTradeOfferStatistics(PARAMS(std::stoll(containerorspaceid), std::stol(starttime), std::stol(endtime), std::stoll(numdatapoints))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumUnavailableUnits", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string cat = req.get_param_value("cat");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (cat.empty())
        {
            return BadRequest(res, "cat must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumUnavailableUnits(PARAMS(std::stoll(defensibleid), cat.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumUnitCargo", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string onlydrones = req.get_param_value("onlydrones");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (onlydrones.empty())
        {
            return BadRequest(res, "onlydrones must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumUnitCargo(PARAMS(std::stoll(containerid), std::stoi(onlydrones))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumUnreadLibraryEntries", HAN_FN {
        std::string libraryid = req.get_param_value("libraryid");
        if (libraryid.empty())
        {
            return BadRequest(res, "libraryid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumUnreadLibraryEntries(PARAMS(libraryid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumUpgradeGroups", HAN_FN {
        std::string destructibleid = req.get_param_value("destructibleid");
        std::string macroname = req.get_param_value("macroname");
        if (destructibleid.empty())
        {
            return BadRequest(res, "destructibleid must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumUpgradeGroups(PARAMS(std::stoll(destructibleid), macroname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumUsedLimitedModules", HAN_FN {
        std::string excludedstationid = req.get_param_value("excludedstationid");
        if (excludedstationid.empty())
        {
            return BadRequest(res, "excludedstationid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumUsedLimitedModules(PARAMS(std::stoll(excludedstationid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumUsedLimitedModulesFromSubsequence", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string cp_idx = req.get_param_value("cp_idx");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (cp_idx.empty())
        {
            return BadRequest(res, "cp_idx must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumUsedLimitedModulesFromSubsequence(PARAMS(std::stoll(holomapid), std::stoll(cp_idx))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumValidTransporterTargets", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumValidTransporterTargets(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumVenturePlatformDocks", HAN_FN {
        std::string ventureplatformid = req.get_param_value("ventureplatformid");
        if (ventureplatformid.empty())
        {
            return BadRequest(res, "ventureplatformid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumVenturePlatformDocks(PARAMS(std::stoll(ventureplatformid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumVenturePlatforms", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumVenturePlatforms(PARAMS(std::stoll(defensibleid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumWareBlueprintOwners", HAN_FN {
        std::string wareid = req.get_param_value("wareid");
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumWareBlueprintOwners(PARAMS(wareid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumWareSources", HAN_FN {
        std::string wareid = req.get_param_value("wareid");
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumWareSources(PARAMS(wareid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumWares", HAN_FN {
        std::string tags = req.get_param_value("tags");
        std::string research = req.get_param_value("research");
        std::string licenceownerid = req.get_param_value("licenceownerid");
        std::string exclusiontags = req.get_param_value("exclusiontags");
        if (tags.empty())
        {
            return BadRequest(res, "tags must be set");
        }
        if (research.empty())
        {
            return BadRequest(res, "research must be set");
        }
        if (licenceownerid.empty())
        {
            return BadRequest(res, "licenceownerid must be set");
        }
        if (exclusiontags.empty())
        {
            return BadRequest(res, "exclusiontags must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumWares(PARAMS(tags.c_str(), std::stoi(research), licenceownerid.c_str(), exclusiontags.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetNumWeaponGroupsByWeapon", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string weaponid = req.get_param_value("weaponid");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (weaponid.empty())
        {
            return BadRequest(res, "weaponid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetNumWeaponGroupsByWeapon(PARAMS(std::stoll(defensibleid), std::stoll(weaponid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetOrderDefinitions", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetOrderDefinitions(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetOrders", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetOrders(PARAMS(std::stoll(controllableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetOrders2", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetOrders2(PARAMS(std::stoll(controllableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPeople", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetPeople(PARAMS(std::stoll(controllableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPeopleAfterOrders", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string numorders = req.get_param_value("numorders");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (numorders.empty())
        {
            return BadRequest(res, "numorders must be set");
        }
        try {
            SET_CONTENT(ffijson::GetPeopleAfterOrders(PARAMS(std::stoll(controllableid), std::stoi(numorders))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPeopleCapacity", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string macroname = req.get_param_value("macroname");
        std::string includecrew = req.get_param_value("includecrew");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        if (includecrew.empty())
        {
            return BadRequest(res, "includecrew must be set");
        }
        try {
            SET_CONTENT(ffijson::GetPeopleCapacity(PARAMS(std::stoll(controllableid), macroname.c_str(), std::stoi(includecrew))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPersonSkills", HAN_FN {
        std::string person = req.get_param_value("person");
        std::string controllableid = req.get_param_value("controllableid");
        if (person.empty())
        {
            return BadRequest(res, "person must be set");
        }
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetPersonSkills(PARAMS(std::stoll(person), std::stoll(controllableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPersonSkillsForAssignment", HAN_FN {
        std::string person = req.get_param_value("person");
        std::string controllableid = req.get_param_value("controllableid");
        std::string role = req.get_param_value("role");
        std::string postid = req.get_param_value("postid");
        if (person.empty())
        {
            return BadRequest(res, "person must be set");
        }
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (role.empty())
        {
            return BadRequest(res, "role must be set");
        }
        if (postid.empty())
        {
            return BadRequest(res, "postid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetPersonSkillsForAssignment(PARAMS(std::stoll(person), std::stoll(controllableid), role.c_str(), postid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPersonSuitableControlPosts", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string personcontrollableid = req.get_param_value("personcontrollableid");
        std::string person = req.get_param_value("person");
        std::string free = req.get_param_value("free");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (personcontrollableid.empty())
        {
            return BadRequest(res, "personcontrollableid must be set");
        }
        if (person.empty())
        {
            return BadRequest(res, "person must be set");
        }
        if (free.empty())
        {
            return BadRequest(res, "free must be set");
        }
        try {
            SET_CONTENT(ffijson::GetPersonSuitableControlPosts(PARAMS(std::stoll(controllableid), std::stoll(personcontrollableid), std::stoll(person), std::stoi(free))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPlannedLimitedModules", HAN_FN {
        std::string constructionplanid = req.get_param_value("constructionplanid");
        if (constructionplanid.empty())
        {
            return BadRequest(res, "constructionplanid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetPlannedLimitedModules(PARAMS(constructionplanid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPlayerAlertSounds", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetPlayerAlertSounds(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPlayerAlerts", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetPlayerAlerts(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPlayerLogos", HAN_FN {
        std::string includestandard = req.get_param_value("includestandard");
        std::string includecustom = req.get_param_value("includecustom");
        if (includestandard.empty())
        {
            return BadRequest(res, "includestandard must be set");
        }
        if (includecustom.empty())
        {
            return BadRequest(res, "includecustom must be set");
        }
        try {
            SET_CONTENT(ffijson::GetPlayerLogos(PARAMS(std::stoi(includestandard), std::stoi(includecustom))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPlayerShipBuildTasks", HAN_FN {
        std::string isinprogress = req.get_param_value("isinprogress");
        std::string includeupgrade = req.get_param_value("includeupgrade");
        if (isinprogress.empty())
        {
            return BadRequest(res, "isinprogress must be set");
        }
        if (includeupgrade.empty())
        {
            return BadRequest(res, "includeupgrade must be set");
        }
        try {
            SET_CONTENT(ffijson::GetPlayerShipBuildTasks(PARAMS(std::stoi(isinprogress), std::stoi(includeupgrade))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetPurchasableCargo", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string unknownString = req.get_param_value("unknownString");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (unknownString.empty())
        {
            return BadRequest(res, "unknownString must be set");
        }
        try {
            SET_CONTENT(ffijson::GetPurchasableCargo(PARAMS(std::stoll(containerid), unknownString.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetRemovedConstructionPlanModules2", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetRemovedConstructionPlanModules2(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetRemovedStationModules", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetRemovedStationModules(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetRenderTargetAlpha", HAN_FN {
        std::string rendertargetid = req.get_param_value("rendertargetid");
        if (rendertargetid.empty())
        {
            return BadRequest(res, "rendertargetid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetRenderTargetAlpha(PARAMS(std::stoi(rendertargetid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetRepairResources", HAN_FN {
        std::string componenttorepairid = req.get_param_value("componenttorepairid");
        if (componenttorepairid.empty())
        {
            return BadRequest(res, "componenttorepairid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetRepairResources(PARAMS(std::stoll(componenttorepairid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetResearchModules", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetResearchModules(PARAMS(std::stoll(containerid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetRoleTierNPCs", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string role = req.get_param_value("role");
        std::string skilllevel = req.get_param_value("skilllevel");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (role.empty())
        {
            return BadRequest(res, "role must be set");
        }
        if (skilllevel.empty())
        {
            return BadRequest(res, "skilllevel must be set");
        }
        try {
            SET_CONTENT(ffijson::GetRoleTierNPCs(PARAMS(std::stoll(controllableid), role.c_str(), std::stoi(skilllevel))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetRoleTiers", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string role = req.get_param_value("role");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (role.empty())
        {
            return BadRequest(res, "role must be set");
        }
        try {
            SET_CONTENT(ffijson::GetRoleTiers(PARAMS(std::stoll(controllableid), role.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetSectorsByOwner", HAN_FN {
        std::string factionid = req.get_param_value("factionid");
        if (factionid.empty())
        {
            return BadRequest(res, "factionid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetSectorsByOwner(PARAMS(factionid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetShieldGroups", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetShieldGroups(PARAMS(std::stoll(defensibleid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetSoftwarePredecessors", HAN_FN {
        std::string softwarename = req.get_param_value("softwarename");
        if (softwarename.empty())
        {
            return BadRequest(res, "softwarename must be set");
        }
        try {
            SET_CONTENT(ffijson::GetSoftwarePredecessors(PARAMS(softwarename.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetSoftwareSlots", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string macroname = req.get_param_value("macroname");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        try {
            SET_CONTENT(ffijson::GetSoftwareSlots(PARAMS(std::stoll(controllableid), macroname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetSoundDevices", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetSoundDevices(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetStandardButtonOffsetX", HAN_FN {
        std::string frameid = req.get_param_value("frameid");
        if (frameid.empty())
        {
            return BadRequest(res, "frameid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetStandardButtonOffsetX(PARAMS(std::stoi(frameid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetStandardButtonOffsetY", HAN_FN {
        std::string frameid = req.get_param_value("frameid");
        if (frameid.empty())
        {
            return BadRequest(res, "frameid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetStandardButtonOffsetY(PARAMS(std::stoi(frameid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetStationModules", HAN_FN {
        std::string stationid = req.get_param_value("stationid");
        std::string includeconstructions = req.get_param_value("includeconstructions");
        std::string includewrecks = req.get_param_value("includewrecks");
        if (stationid.empty())
        {
            return BadRequest(res, "stationid must be set");
        }
        if (includeconstructions.empty())
        {
            return BadRequest(res, "includeconstructions must be set");
        }
        if (includewrecks.empty())
        {
            return BadRequest(res, "includewrecks must be set");
        }
        try {
            SET_CONTENT(ffijson::GetStationModules(PARAMS(std::stoll(stationid), std::stoi(includeconstructions), std::stoi(includewrecks))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetStationOverviewGraphWares", HAN_FN {
        std::string stationid = req.get_param_value("stationid");
        if (stationid.empty())
        {
            return BadRequest(res, "stationid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetStationOverviewGraphWares(PARAMS(std::stoll(stationid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetSuitableControlPosts", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string entityid = req.get_param_value("entityid");
        std::string free = req.get_param_value("free");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (entityid.empty())
        {
            return BadRequest(res, "entityid must be set");
        }
        if (free.empty())
        {
            return BadRequest(res, "free must be set");
        }
        try {
            SET_CONTENT(ffijson::GetSuitableControlPosts(PARAMS(std::stoll(controllableid), std::stoll(entityid), std::stoi(free))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetSupplyOrders", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string defaultorders = req.get_param_value("defaultorders");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (defaultorders.empty())
        {
            return BadRequest(res, "defaultorders must be set");
        }
        try {
            SET_CONTENT(ffijson::GetSupplyOrders(PARAMS(std::stoll(containerid), std::stoi(defaultorders))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetTableHighlightMode", HAN_FN {
        std::string tableid = req.get_param_value("tableid");
        if (tableid.empty())
        {
            return BadRequest(res, "tableid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetTableHighlightMode(PARAMS(std::stoi(tableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetTableInitialMultiselectedRows", HAN_FN {
        std::string tableid = req.get_param_value("tableid");
        if (tableid.empty())
        {
            return BadRequest(res, "tableid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetTableInitialMultiselectedRows(PARAMS(std::stoi(tableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetTiersOfRole", HAN_FN {
        std::string role = req.get_param_value("role");
        if (role.empty())
        {
            return BadRequest(res, "role must be set");
        }
        try {
            SET_CONTENT(ffijson::GetTiersOfRole(PARAMS(role.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetTimeline", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetTimeline(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetTradeOfferStatistics", HAN_FN {
        std::string numdatapoints = req.get_param_value("numdatapoints");
        if (numdatapoints.empty())
        {
            return BadRequest(res, "numdatapoints must be set");
        }
        try {
            SET_CONTENT(ffijson::GetTradeOfferStatistics(PARAMS(std::stoll(numdatapoints))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetUnitCargo", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string onlydrones = req.get_param_value("onlydrones");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (onlydrones.empty())
        {
            return BadRequest(res, "onlydrones must be set");
        }
        try {
            SET_CONTENT(ffijson::GetUnitCargo(PARAMS(std::stoll(containerid), std::stoi(onlydrones))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetUpgradeGroups", HAN_FN {
        std::string destructibleid = req.get_param_value("destructibleid");
        std::string macroname = req.get_param_value("macroname");
        if (destructibleid.empty())
        {
            return BadRequest(res, "destructibleid must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        try {
            SET_CONTENT(ffijson::GetUpgradeGroups(PARAMS(std::stoll(destructibleid), macroname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetUpgradeGroups2", HAN_FN {
        std::string destructibleid = req.get_param_value("destructibleid");
        std::string macroname = req.get_param_value("macroname");
        if (destructibleid.empty())
        {
            return BadRequest(res, "destructibleid must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        try {
            SET_CONTENT(ffijson::GetUpgradeGroups2(PARAMS(std::stoll(destructibleid), macroname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetUsedLimitedModules", HAN_FN {
        std::string excludedstationid = req.get_param_value("excludedstationid");
        if (excludedstationid.empty())
        {
            return BadRequest(res, "excludedstationid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetUsedLimitedModules(PARAMS(std::stoll(excludedstationid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetUsedLimitedModulesFromSubsequence", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string cp_idx = req.get_param_value("cp_idx");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (cp_idx.empty())
        {
            return BadRequest(res, "cp_idx must be set");
        }
        try {
            SET_CONTENT(ffijson::GetUsedLimitedModulesFromSubsequence(PARAMS(std::stoll(holomapid), std::stoll(cp_idx))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetValidTransporterTargets", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetValidTransporterTargets(PARAMS(std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetVenturePlatformDocks", HAN_FN {
        std::string ventureplatformid = req.get_param_value("ventureplatformid");
        if (ventureplatformid.empty())
        {
            return BadRequest(res, "ventureplatformid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetVenturePlatformDocks(PARAMS(std::stoll(ventureplatformid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetVenturePlatforms", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetVenturePlatforms(PARAMS(std::stoll(defensibleid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetWareBlueprintOwners", HAN_FN {
        std::string wareid = req.get_param_value("wareid");
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetWareBlueprintOwners(PARAMS(wareid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetWareSources", HAN_FN {
        std::string wareid = req.get_param_value("wareid");
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetWareSources(PARAMS(wareid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetWares", HAN_FN {
        std::string tags = req.get_param_value("tags");
        std::string research = req.get_param_value("research");
        std::string licenceownerid = req.get_param_value("licenceownerid");
        std::string exclusiontags = req.get_param_value("exclusiontags");
        if (tags.empty())
        {
            return BadRequest(res, "tags must be set");
        }
        if (research.empty())
        {
            return BadRequest(res, "research must be set");
        }
        if (licenceownerid.empty())
        {
            return BadRequest(res, "licenceownerid must be set");
        }
        if (exclusiontags.empty())
        {
            return BadRequest(res, "exclusiontags must be set");
        }
        try {
            SET_CONTENT(ffijson::GetWares(PARAMS(tags.c_str(), std::stoi(research), licenceownerid.c_str(), exclusiontags.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetWeaponGroupsByWeapon", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string weaponid = req.get_param_value("weaponid");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (weaponid.empty())
        {
            return BadRequest(res, "weaponid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetWeaponGroupsByWeapon(PARAMS(std::stoll(defensibleid), std::stoll(weaponid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/PlayDetailmonitorCutscene", HAN_FN {
        std::string cutsceneid = req.get_param_value("cutsceneid");
        std::string rendertarget = req.get_param_value("rendertarget");
        if (cutsceneid.empty())
        {
            return BadRequest(res, "cutsceneid must be set");
        }
        if (rendertarget.empty())
        {
            return BadRequest(res, "rendertarget must be set");
        }
        try {
            SET_CONTENT(ffijson::PlayDetailmonitorCutscene(PARAMS(std::stoll(cutsceneid), rendertarget.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/PrepareBuildSequenceResources", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string stationid = req.get_param_value("stationid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (stationid.empty())
        {
            return BadRequest(res, "stationid must be set");
        }
        try {
            SET_CONTENT(ffijson::PrepareBuildSequenceResources(PARAMS(std::stoll(holomapid), std::stoll(stationid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetActiveMissionID", HAN_FN {
        try {
            SET_CONTENT(ffijson::GetActiveMissionID(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/AbortMission", HAN_FN {
        std::string missionid = req.get_param_value("missionid");
        if (missionid.empty())
        {
            return BadRequest(res, "missionid must be set");
        }
        try {
            SET_CONTENT(ffijson::AbortMission(PARAMS(std::stoll(missionid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/AddCopyToConstructionMap", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string cp_idx = req.get_param_value("cp_idx");
        std::string copysequence = req.get_param_value("copysequence");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (cp_idx.empty())
        {
            return BadRequest(res, "cp_idx must be set");
        }
        if (copysequence.empty())
        {
            return BadRequest(res, "copysequence must be set");
        }
        try {
            SET_CONTENT(ffijson::AddCopyToConstructionMap(PARAMS(std::stoll(holomapid), std::stoll(cp_idx), std::stoi(copysequence))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/AddCrewExchangeOrder", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string partnercontainerid = req.get_param_value("partnercontainerid");
        std::string numnpcs = req.get_param_value("numnpcs");
        std::string numpartnernpcs = req.get_param_value("numpartnernpcs");
        std::string tradecomputer = req.get_param_value("tradecomputer");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (partnercontainerid.empty())
        {
            return BadRequest(res, "partnercontainerid must be set");
        }
        if (numnpcs.empty())
        {
            return BadRequest(res, "numnpcs must be set");
        }
        if (numpartnernpcs.empty())
        {
            return BadRequest(res, "numpartnernpcs must be set");
        }
        if (tradecomputer.empty())
        {
            return BadRequest(res, "tradecomputer must be set");
        }
        try {
            SET_CONTENT(ffijson::AddCrewExchangeOrder(PARAMS(std::stoll(containerid), std::stoll(partnercontainerid), std::stoll(numnpcs), std::stoll(numpartnernpcs), std::stoi(tradecomputer))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/AddMacroToConstructionMap", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string macroname = req.get_param_value("macroname");
        std::string startdragging = req.get_param_value("startdragging");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        if (startdragging.empty())
        {
            return BadRequest(res, "startdragging must be set");
        }
        try {
            SET_CONTENT(ffijson::AddMacroToConstructionMap(PARAMS(std::stoll(holomapid), macroname.c_str(), std::stoi(startdragging))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/AddPlayerMoney", HAN_FN {
        std::string money = req.get_param_value("money");
        if (money.empty())
        {
            return BadRequest(res, "money must be set");
        }
        try {
            SET_CONTENT(ffijson::AddPlayerMoney(PARAMS(std::stoi(money))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/AddResearch", HAN_FN {
        std::string wareid = req.get_param_value("wareid");
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        try {
            SET_CONTENT(ffijson::AddResearch(PARAMS(wareid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/AddSimilarMapComponentsToSelection", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string componentid = req.get_param_value("componentid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::AddSimilarMapComponentsToSelection(PARAMS(std::stoll(holomapid), std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ChangeMapBuildPlot", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string x = req.get_param_value("x");
        std::string y = req.get_param_value("y");
        std::string z = req.get_param_value("z");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (x.empty())
        {
            return BadRequest(res, "x must be set");
        }
        if (y.empty())
        {
            return BadRequest(res, "y must be set");
        }
        if (z.empty())
        {
            return BadRequest(res, "z must be set");
        }
        try {
            SET_CONTENT(ffijson::ChangeMapBuildPlot(PARAMS(std::stoll(holomapid), std::stof(x), std::stof(y), std::stof(z))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/CheatDockingTraffic", HAN_FN {
        try {
            SET_CONTENT(ffijson::CheatDockingTraffic(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ClearBuildMapSelection", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        try {
            SET_CONTENT(ffijson::ClearBuildMapSelection(PARAMS(std::stoll(holomapid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ClearContainerBuyLimitOverride", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string wareid = req.get_param_value("wareid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        try {
            SET_CONTENT(ffijson::ClearContainerBuyLimitOverride(PARAMS(std::stoll(containerid), wareid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ClearContainerSellLimitOverride", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string wareid = req.get_param_value("wareid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        try {
            SET_CONTENT(ffijson::ClearContainerSellLimitOverride(PARAMS(std::stoll(containerid), wareid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ClearErrorLog", HAN_FN {
        try {
            SET_CONTENT(ffijson::ClearErrorLog(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ClearMapBehaviour", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        try {
            SET_CONTENT(ffijson::ClearMapBehaviour(PARAMS(std::stoll(holomapid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ClearMapBuildPlot", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        try {
            SET_CONTENT(ffijson::ClearMapBuildPlot(PARAMS(std::stoll(holomapid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ClearMapTradeFilterByMinTotalVolume", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        try {
            SET_CONTENT(ffijson::ClearMapTradeFilterByMinTotalVolume(PARAMS(std::stoll(holomapid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ClearMapTradeFilterByPlayerOffer", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string buysellswitch = req.get_param_value("buysellswitch");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (buysellswitch.empty())
        {
            return BadRequest(res, "buysellswitch must be set");
        }
        try {
            SET_CONTENT(ffijson::ClearMapTradeFilterByPlayerOffer(PARAMS(std::stoll(holomapid), std::stoi(buysellswitch))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ClearMapTradeFilterByWare", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        try {
            SET_CONTENT(ffijson::ClearMapTradeFilterByWare(PARAMS(std::stoll(holomapid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ClearProductionItems", HAN_FN {
        std::string productionmoduleid = req.get_param_value("productionmoduleid");
        if (productionmoduleid.empty())
        {
            return BadRequest(res, "productionmoduleid must be set");
        }
        try {
            SET_CONTENT(ffijson::ClearProductionItems(PARAMS(std::stoll(productionmoduleid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ClearRendertarget", HAN_FN {
        std::string rendertarget = req.get_param_value("rendertarget");
        if (rendertarget.empty())
        {
            return BadRequest(res, "rendertarget must be set");
        }
        try {
            SET_CONTENT(ffijson::ClearRendertarget(PARAMS(rendertarget.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ClearSelectedMapComponents", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        try {
            SET_CONTENT(ffijson::ClearSelectedMapComponents(PARAMS(std::stoll(holomapid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ClearSelectedMapMacroSlots", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        try {
            SET_CONTENT(ffijson::ClearSelectedMapMacroSlots(PARAMS(std::stoll(holomapid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ClearTrackedMenus", HAN_FN {
        try {
            SET_CONTENT(ffijson::ClearTrackedMenus(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ConnectToMultiplayerGame", HAN_FN {
        std::string serverip = req.get_param_value("serverip");
        if (serverip.empty())
        {
            return BadRequest(res, "serverip must be set");
        }
        try {
            SET_CONTENT(ffijson::ConnectToMultiplayerGame(PARAMS(serverip.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/CycleNextDroneMode", HAN_FN {
        std::string dronetype = req.get_param_value("dronetype");
        if (dronetype.empty())
        {
            return BadRequest(res, "dronetype must be set");
        }
        try {
            SET_CONTENT(ffijson::CycleNextDroneMode(PARAMS(std::stoll(dronetype))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/CycleTurretMissile", HAN_FN {
        std::string turretnum = req.get_param_value("turretnum");
        if (turretnum.empty())
        {
            return BadRequest(res, "turretnum must be set");
        }
        try {
            SET_CONTENT(ffijson::CycleTurretMissile(PARAMS(std::stoll(turretnum))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/CycleTurretMode", HAN_FN {
        std::string turretnum = req.get_param_value("turretnum");
        if (turretnum.empty())
        {
            return BadRequest(res, "turretnum must be set");
        }
        try {
            SET_CONTENT(ffijson::CycleTurretMode(PARAMS(std::stoll(turretnum))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/DeactivateDirectInput", HAN_FN {
        try {
            SET_CONTENT(ffijson::DeactivateDirectInput(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/DeactivateMouseEmulation", HAN_FN {
        try {
            SET_CONTENT(ffijson::DeactivateMouseEmulation(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/DeselectMacroForConstructionMap", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        try {
            SET_CONTENT(ffijson::DeselectMacroForConstructionMap(PARAMS(std::stoll(holomapid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/DisableAsserts", HAN_FN {
        try {
            SET_CONTENT(ffijson::DisableAsserts(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/DisableAutoMouseEmulation", HAN_FN {
        try {
            SET_CONTENT(ffijson::DisableAutoMouseEmulation(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/DisableEncryptedDirectInputMode", HAN_FN {
        try {
            SET_CONTENT(ffijson::DisableEncryptedDirectInputMode(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/DisableOptionalAsserts", HAN_FN {
        try {
            SET_CONTENT(ffijson::DisableOptionalAsserts(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/DismantleEngineMod", HAN_FN {
        std::string objectid = req.get_param_value("objectid");
        if (objectid.empty())
        {
            return BadRequest(res, "objectid must be set");
        }
        try {
            SET_CONTENT(ffijson::DismantleEngineMod(PARAMS(std::stoll(objectid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/DismantleGroupedWeaponMod", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string contextid = req.get_param_value("contextid");
        std::string group = req.get_param_value("group");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (contextid.empty())
        {
            return BadRequest(res, "contextid must be set");
        }
        if (group.empty())
        {
            return BadRequest(res, "group must be set");
        }
        try {
            SET_CONTENT(ffijson::DismantleGroupedWeaponMod(PARAMS(std::stoll(defensibleid), std::stoll(contextid), group.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/DismantleShieldMod", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string contextid = req.get_param_value("contextid");
        std::string group = req.get_param_value("group");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (contextid.empty())
        {
            return BadRequest(res, "contextid must be set");
        }
        if (group.empty())
        {
            return BadRequest(res, "group must be set");
        }
        try {
            SET_CONTENT(ffijson::DismantleShieldMod(PARAMS(std::stoll(defensibleid), std::stoll(contextid), group.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/DismantleShipMod", HAN_FN {
        std::string shipid = req.get_param_value("shipid");
        if (shipid.empty())
        {
            return BadRequest(res, "shipid must be set");
        }
        try {
            SET_CONTENT(ffijson::DismantleShipMod(PARAMS(std::stoll(shipid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/DismantleWeaponMod", HAN_FN {
        std::string weaponid = req.get_param_value("weaponid");
        if (weaponid.empty())
        {
            return BadRequest(res, "weaponid must be set");
        }
        try {
            SET_CONTENT(ffijson::DismantleWeaponMod(PARAMS(std::stoll(weaponid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/EnableAllCheats", HAN_FN {
        try {
            SET_CONTENT(ffijson::EnableAllCheats(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/EnableAsserts", HAN_FN {
        try {
            SET_CONTENT(ffijson::EnableAsserts(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/EnableAutoMouseEmulation", HAN_FN {
        try {
            SET_CONTENT(ffijson::EnableAutoMouseEmulation(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/EnableEncryptedDirectInputMode", HAN_FN {
        try {
            SET_CONTENT(ffijson::EnableEncryptedDirectInputMode(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/EnableOptionalAsserts", HAN_FN {
        try {
            SET_CONTENT(ffijson::EnableOptionalAsserts(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/EndGuidance", HAN_FN {
        try {
            SET_CONTENT(ffijson::EndGuidance(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/FadeScreen", HAN_FN {
        std::string fadeouttime = req.get_param_value("fadeouttime");
        std::string fadeintime = req.get_param_value("fadeintime");
        if (fadeouttime.empty())
        {
            return BadRequest(res, "fadeouttime must be set");
        }
        if (fadeintime.empty())
        {
            return BadRequest(res, "fadeintime must be set");
        }
        try {
            SET_CONTENT(ffijson::FadeScreen(PARAMS(std::stof(fadeouttime), std::stof(fadeintime))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GenerateModuleLoadout", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string cp_idx = req.get_param_value("cp_idx");
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string level = req.get_param_value("level");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (cp_idx.empty())
        {
            return BadRequest(res, "cp_idx must be set");
        }
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (level.empty())
        {
            return BadRequest(res, "level must be set");
        }
        try {
            SET_CONTENT(ffijson::GenerateModuleLoadout(PARAMS(std::stoll(holomapid), std::stoll(cp_idx), std::stoll(defensibleid), std::stof(level))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GenerateModuleLoadoutCounts", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string cp_idx = req.get_param_value("cp_idx");
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string level = req.get_param_value("level");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (cp_idx.empty())
        {
            return BadRequest(res, "cp_idx must be set");
        }
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (level.empty())
        {
            return BadRequest(res, "level must be set");
        }
        try {
            SET_CONTENT(ffijson::GenerateModuleLoadoutCounts(PARAMS(std::stoll(holomapid), std::stoll(cp_idx), std::stoll(defensibleid), std::stof(level))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GenerateShipKnownLoadout", HAN_FN {
        std::string macroname = req.get_param_value("macroname");
        std::string level = req.get_param_value("level");
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        if (level.empty())
        {
            return BadRequest(res, "level must be set");
        }
        try {
            SET_CONTENT(ffijson::GenerateShipKnownLoadout(PARAMS(macroname.c_str(), std::stof(level))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GenerateShipKnownLoadoutCounts", HAN_FN {
        std::string macroname = req.get_param_value("macroname");
        std::string level = req.get_param_value("level");
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        if (level.empty())
        {
            return BadRequest(res, "level must be set");
        }
        try {
            SET_CONTENT(ffijson::GenerateShipKnownLoadoutCounts(PARAMS(macroname.c_str(), std::stof(level))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GenerateShipLoadout", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string shipid = req.get_param_value("shipid");
        std::string macroname = req.get_param_value("macroname");
        std::string level = req.get_param_value("level");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (shipid.empty())
        {
            return BadRequest(res, "shipid must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        if (level.empty())
        {
            return BadRequest(res, "level must be set");
        }
        try {
            SET_CONTENT(ffijson::GenerateShipLoadout(PARAMS(std::stoll(containerid), std::stoll(shipid), macroname.c_str(), std::stof(level))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GenerateShipLoadoutCounts", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string shipid = req.get_param_value("shipid");
        std::string macroname = req.get_param_value("macroname");
        std::string level = req.get_param_value("level");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (shipid.empty())
        {
            return BadRequest(res, "shipid must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        if (level.empty())
        {
            return BadRequest(res, "level must be set");
        }
        try {
            SET_CONTENT(ffijson::GenerateShipLoadoutCounts(PARAMS(std::stoll(containerid), std::stoll(shipid), macroname.c_str(), std::stof(level))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetBuildTaskCrewTransferInfo", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string id = req.get_param_value("id");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        try {
            SET_CONTENT(ffijson::GetBuildTaskCrewTransferInfo(PARAMS(std::stoll(containerid), std::stoll(id))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetConstructionMapItemLoadout", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string itemidx = req.get_param_value("itemidx");
        std::string defensibleid = req.get_param_value("defensibleid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (itemidx.empty())
        {
            return BadRequest(res, "itemidx must be set");
        }
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetConstructionMapItemLoadout(PARAMS(std::stoll(holomapid), std::stoll(itemidx), std::stoll(defensibleid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetConstructionMapItemLoadoutCounts", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string itemidx = req.get_param_value("itemidx");
        std::string defensibleid = req.get_param_value("defensibleid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (itemidx.empty())
        {
            return BadRequest(res, "itemidx must be set");
        }
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetConstructionMapItemLoadoutCounts(PARAMS(std::stoll(holomapid), std::stoll(itemidx), std::stoll(defensibleid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCurrentLoadout", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string moduleid = req.get_param_value("moduleid");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (moduleid.empty())
        {
            return BadRequest(res, "moduleid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCurrentLoadout(PARAMS(std::stoll(defensibleid), std::stoll(moduleid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCurrentLoadoutCounts", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string moduleid = req.get_param_value("moduleid");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (moduleid.empty())
        {
            return BadRequest(res, "moduleid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCurrentLoadoutCounts(PARAMS(std::stoll(defensibleid), std::stoll(moduleid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCustomGameStartLoadoutProperty", HAN_FN {
        std::string id = req.get_param_value("id");
        std::string propertyid = req.get_param_value("propertyid");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (propertyid.empty())
        {
            return BadRequest(res, "propertyid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCustomGameStartLoadoutProperty(PARAMS(id.c_str(), propertyid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetCustomGameStartLoadoutPropertyCounts", HAN_FN {
        std::string id = req.get_param_value("id");
        std::string propertyid = req.get_param_value("propertyid");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (propertyid.empty())
        {
            return BadRequest(res, "propertyid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetCustomGameStartLoadoutPropertyCounts(PARAMS(id.c_str(), propertyid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetLoadout", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string macroname = req.get_param_value("macroname");
        std::string loadoutid = req.get_param_value("loadoutid");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        if (loadoutid.empty())
        {
            return BadRequest(res, "loadoutid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetLoadout(PARAMS(std::stoll(defensibleid), macroname.c_str(), loadoutid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/GetMapState", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        try {
            SET_CONTENT(ffijson::GetMapState(PARAMS(std::stoll(holomapid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/InvalidateRadarCursorPosition", HAN_FN {
        try {
            SET_CONTENT(ffijson::InvalidateRadarCursorPosition(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/LaunchLaserTower", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string lasertowermacroname = req.get_param_value("lasertowermacroname");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (lasertowermacroname.empty())
        {
            return BadRequest(res, "lasertowermacroname must be set");
        }
        try {
            SET_CONTENT(ffijson::LaunchLaserTower(PARAMS(std::stoll(defensibleid), lasertowermacroname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/LaunchMine", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string minemacroname = req.get_param_value("minemacroname");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (minemacroname.empty())
        {
            return BadRequest(res, "minemacroname must be set");
        }
        try {
            SET_CONTENT(ffijson::LaunchMine(PARAMS(std::stoll(defensibleid), minemacroname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/LaunchNavBeacon", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string navbeaconmacroname = req.get_param_value("navbeaconmacroname");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (navbeaconmacroname.empty())
        {
            return BadRequest(res, "navbeaconmacroname must be set");
        }
        try {
            SET_CONTENT(ffijson::LaunchNavBeacon(PARAMS(std::stoll(defensibleid), navbeaconmacroname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/LaunchResourceProbe", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string resourceprobemacroname = req.get_param_value("resourceprobemacroname");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (resourceprobemacroname.empty())
        {
            return BadRequest(res, "resourceprobemacroname must be set");
        }
        try {
            SET_CONTENT(ffijson::LaunchResourceProbe(PARAMS(std::stoll(defensibleid), resourceprobemacroname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/LaunchSatellite", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string satellitemacroname = req.get_param_value("satellitemacroname");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (satellitemacroname.empty())
        {
            return BadRequest(res, "satellitemacroname must be set");
        }
        try {
            SET_CONTENT(ffijson::LaunchSatellite(PARAMS(std::stoll(defensibleid), satellitemacroname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/LearnBlueprint", HAN_FN {
        std::string wareid = req.get_param_value("wareid");
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        try {
            SET_CONTENT(ffijson::LearnBlueprint(PARAMS(wareid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/MakePlayerOwnerOf", HAN_FN {
        std::string objectid = req.get_param_value("objectid");
        if (objectid.empty())
        {
            return BadRequest(res, "objectid must be set");
        }
        try {
            SET_CONTENT(ffijson::MakePlayerOwnerOf(PARAMS(std::stoll(objectid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/MutePlayerAlert", HAN_FN {
        std::string index = req.get_param_value("index");
        if (index.empty())
        {
            return BadRequest(res, "index must be set");
        }
        try {
            SET_CONTENT(ffijson::MutePlayerAlert(PARAMS(std::stoll(index))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/NewMultiplayerGame", HAN_FN {
        std::string modulename = req.get_param_value("modulename");
        std::string difficulty = req.get_param_value("difficulty");
        if (modulename.empty())
        {
            return BadRequest(res, "modulename must be set");
        }
        if (difficulty.empty())
        {
            return BadRequest(res, "difficulty must be set");
        }
        try {
            SET_CONTENT(ffijson::NewMultiplayerGame(PARAMS(modulename.c_str(), difficulty.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/NotifyDisplayNotification", HAN_FN {
        std::string notificationid = req.get_param_value("notificationid");
        if (notificationid.empty())
        {
            return BadRequest(res, "notificationid must be set");
        }
        try {
            SET_CONTENT(ffijson::NotifyDisplayNotification(PARAMS(std::stoi(notificationid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/NotifyErrorLogDispatching", HAN_FN {
        try {
            SET_CONTENT(ffijson::NotifyErrorLogDispatching(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/NotifyErrorLogDispatchingDone", HAN_FN {
        try {
            SET_CONTENT(ffijson::NotifyErrorLogDispatchingDone(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/NotifyInteractMenuHidden", HAN_FN {
        std::string id = req.get_param_value("id");
        std::string allclosed = req.get_param_value("allclosed");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (allclosed.empty())
        {
            return BadRequest(res, "allclosed must be set");
        }
        try {
            SET_CONTENT(ffijson::NotifyInteractMenuHidden(PARAMS(std::stoll(id), std::stoi(allclosed))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/NotifyInteractMenuShown", HAN_FN {
        std::string id = req.get_param_value("id");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        try {
            SET_CONTENT(ffijson::NotifyInteractMenuShown(PARAMS(std::stoll(id))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/OpenMovieMenu", HAN_FN {
        std::string key = req.get_param_value("key");
        if (key.empty())
        {
            return BadRequest(res, "key must be set");
        }
        try {
            SET_CONTENT(ffijson::OpenMovieMenu(PARAMS(key.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/OpenWebBrowser", HAN_FN {
        std::string url = req.get_param_value("url");
        if (url.empty())
        {
            return BadRequest(res, "url must be set");
        }
        try {
            SET_CONTENT(ffijson::OpenWebBrowser(PARAMS(url.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ReadAllInventoryWares", HAN_FN {
        try {
            SET_CONTENT(ffijson::ReadAllInventoryWares(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ReadInventoryWare", HAN_FN {
        std::string wareid = req.get_param_value("wareid");
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        try {
            SET_CONTENT(ffijson::ReadInventoryWare(PARAMS(wareid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ReadKnownItem", HAN_FN {
        std::string libraryid = req.get_param_value("libraryid");
        std::string itemid = req.get_param_value("itemid");
        std::string read = req.get_param_value("read");
        if (libraryid.empty())
        {
            return BadRequest(res, "libraryid must be set");
        }
        if (itemid.empty())
        {
            return BadRequest(res, "itemid must be set");
        }
        if (read.empty())
        {
            return BadRequest(res, "read must be set");
        }
        try {
            SET_CONTENT(ffijson::ReadKnownItem(PARAMS(libraryid.c_str(), itemid.c_str(), std::stoi(read))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ReassignPeople", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string amount = req.get_param_value("amount");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (amount.empty())
        {
            return BadRequest(res, "amount must be set");
        }
        try {
            SET_CONTENT(ffijson::ReassignPeople(PARAMS(std::stoll(controllableid), std::stoll(amount))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/RedoConstructionMapChange", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        try {
            SET_CONTENT(ffijson::RedoConstructionMapChange(PARAMS(std::stoll(holomapid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ReenableErrorLog", HAN_FN {
        try {
            SET_CONTENT(ffijson::ReenableErrorLog(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ReleaseConstructionMapState", HAN_FN {
        try {
            SET_CONTENT(ffijson::ReleaseConstructionMapState(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ReleaseInteractionDescriptor", HAN_FN {
        std::string id = req.get_param_value("id");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        try {
            SET_CONTENT(ffijson::ReleaseInteractionDescriptor(PARAMS(std::stoi(id))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ReleaseOrderSyncPoint", HAN_FN {
        std::string syncid = req.get_param_value("syncid");
        if (syncid.empty())
        {
            return BadRequest(res, "syncid must be set");
        }
        try {
            SET_CONTENT(ffijson::ReleaseOrderSyncPoint(PARAMS(std::stoll(syncid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ReleasePersonFromCrewTransfer", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string person = req.get_param_value("person");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (person.empty())
        {
            return BadRequest(res, "person must be set");
        }
        try {
            SET_CONTENT(ffijson::ReleasePersonFromCrewTransfer(PARAMS(std::stoll(controllableid), std::stoll(person))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ReloadSaveList", HAN_FN {
        try {
            SET_CONTENT(ffijson::ReloadSaveList(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/RemoveBlacklist", HAN_FN {
        std::string id = req.get_param_value("id");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        try {
            SET_CONTENT(ffijson::RemoveBlacklist(PARAMS(std::stoll(id))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/RemoveDockingBayReservation", HAN_FN {
        std::string dockingbayid = req.get_param_value("dockingbayid");
        if (dockingbayid.empty())
        {
            return BadRequest(res, "dockingbayid must be set");
        }
        try {
            SET_CONTENT(ffijson::RemoveDockingBayReservation(PARAMS(std::stoll(dockingbayid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/RemoveFill", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        std::string connectionname = req.get_param_value("connectionname");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::RemoveFill(PARAMS(std::stoll(componentid), connectionname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/RemoveHoloMap", HAN_FN {
        try {
            SET_CONTENT(ffijson::RemoveHoloMap(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/RemoveItemFromConstructionMap", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string itemidx = req.get_param_value("itemidx");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (itemidx.empty())
        {
            return BadRequest(res, "itemidx must be set");
        }
        try {
            SET_CONTENT(ffijson::RemoveItemFromConstructionMap(PARAMS(std::stoll(holomapid), std::stoll(itemidx))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/RemoveOrderSyncPointID", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string orderidx = req.get_param_value("orderidx");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (orderidx.empty())
        {
            return BadRequest(res, "orderidx must be set");
        }
        try {
            SET_CONTENT(ffijson::RemoveOrderSyncPointID(PARAMS(std::stoll(controllableid), std::stoll(orderidx))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/RemoveOutline", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        std::string connectionname = req.get_param_value("connectionname");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::RemoveOutline(PARAMS(std::stoll(componentid), connectionname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/RemovePerson", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string person = req.get_param_value("person");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (person.empty())
        {
            return BadRequest(res, "person must be set");
        }
        try {
            SET_CONTENT(ffijson::RemovePerson(PARAMS(std::stoll(controllableid), std::stoll(person))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/RemovePlannedDefaultOrder", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        try {
            SET_CONTENT(ffijson::RemovePlannedDefaultOrder(PARAMS(std::stoll(controllableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/RemovePlayerAlert", HAN_FN {
        std::string index = req.get_param_value("index");
        if (index.empty())
        {
            return BadRequest(res, "index must be set");
        }
        try {
            SET_CONTENT(ffijson::RemovePlayerAlert(PARAMS(std::stoll(index))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/RemoveReadMessages", HAN_FN {
        std::string categoryname = req.get_param_value("categoryname");
        if (categoryname.empty())
        {
            return BadRequest(res, "categoryname must be set");
        }
        try {
            SET_CONTENT(ffijson::RemoveReadMessages(PARAMS(categoryname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/RemoveTrackedMenu", HAN_FN {
        std::string menu = req.get_param_value("menu");
        if (menu.empty())
        {
            return BadRequest(res, "menu must be set");
        }
        try {
            SET_CONTENT(ffijson::RemoveTrackedMenu(PARAMS(menu.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/RemoveTradeWare", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string wareid = req.get_param_value("wareid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        try {
            SET_CONTENT(ffijson::RemoveTradeWare(PARAMS(std::stoll(containerid), wareid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/RequestLanguageChange", HAN_FN {
        std::string id = req.get_param_value("id");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        try {
            SET_CONTENT(ffijson::RequestLanguageChange(PARAMS(std::stoi(id))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/RequestSoundDeviceSwitch", HAN_FN {
        std::string device = req.get_param_value("device");
        if (device.empty())
        {
            return BadRequest(res, "device must be set");
        }
        try {
            SET_CONTENT(ffijson::RequestSoundDeviceSwitch(PARAMS(device.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ResetCustomGameStart", HAN_FN {
        std::string id = req.get_param_value("id");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        try {
            SET_CONTENT(ffijson::ResetCustomGameStart(PARAMS(id.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ResetEncryptedDirectInputData", HAN_FN {
        try {
            SET_CONTENT(ffijson::ResetEncryptedDirectInputData(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ResetMapPlayerRotation", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        try {
            SET_CONTENT(ffijson::ResetMapPlayerRotation(PARAMS(std::stoll(holomapid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/RestoreMiscOptions", HAN_FN {
        try {
            SET_CONTENT(ffijson::RestoreMiscOptions(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/RevealEncyclopedia", HAN_FN {
        try {
            SET_CONTENT(ffijson::RevealEncyclopedia(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/RevealMap", HAN_FN {
        try {
            SET_CONTENT(ffijson::RevealMap(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/RevealStations", HAN_FN {
        try {
            SET_CONTENT(ffijson::RevealStations(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SaveAAOption", HAN_FN {
        try {
            SET_CONTENT(ffijson::SaveAAOption(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SaveMapConstructionPlan", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string source = req.get_param_value("source");
        std::string id = req.get_param_value("id");
        std::string overwrite = req.get_param_value("overwrite");
        std::string name = req.get_param_value("name");
        std::string desc = req.get_param_value("desc");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (source.empty())
        {
            return BadRequest(res, "source must be set");
        }
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (overwrite.empty())
        {
            return BadRequest(res, "overwrite must be set");
        }
        if (name.empty())
        {
            return BadRequest(res, "name must be set");
        }
        if (desc.empty())
        {
            return BadRequest(res, "desc must be set");
        }
        try {
            SET_CONTENT(ffijson::SaveMapConstructionPlan(PARAMS(std::stoll(holomapid), source.c_str(), id.c_str(), std::stoi(overwrite), name.c_str(), desc.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SelectBuildMapEntry", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string cp_idx = req.get_param_value("cp_idx");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (cp_idx.empty())
        {
            return BadRequest(res, "cp_idx must be set");
        }
        try {
            SET_CONTENT(ffijson::SelectBuildMapEntry(PARAMS(std::stoll(holomapid), std::stoll(cp_idx))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SelectPickedBuildMapEntry", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        try {
            SET_CONTENT(ffijson::SelectPickedBuildMapEntry(PARAMS(std::stoll(holomapid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SelectSimilarMapComponents", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string componentid = req.get_param_value("componentid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::SelectSimilarMapComponents(PARAMS(std::stoll(holomapid), std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SellPlayerShip", HAN_FN {
        std::string shipid = req.get_param_value("shipid");
        std::string shipyardid = req.get_param_value("shipyardid");
        if (shipid.empty())
        {
            return BadRequest(res, "shipid must be set");
        }
        if (shipyardid.empty())
        {
            return BadRequest(res, "shipyardid must be set");
        }
        try {
            SET_CONTENT(ffijson::SellPlayerShip(PARAMS(std::stoll(shipid), std::stoll(shipyardid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetAAOption", HAN_FN {
        std::string fxaa = req.get_param_value("fxaa");
        if (fxaa.empty())
        {
            return BadRequest(res, "fxaa must be set");
        }
        try {
            SET_CONTENT(ffijson::SetAAOption(PARAMS(fxaa.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetAdaptiveSamplingOption", HAN_FN {
        std::string value = req.get_param_value("value");
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetAdaptiveSamplingOption(PARAMS(std::stof(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetAllMissileTurretModes", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string mode = req.get_param_value("mode");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (mode.empty())
        {
            return BadRequest(res, "mode must be set");
        }
        try {
            SET_CONTENT(ffijson::SetAllMissileTurretModes(PARAMS(std::stoll(defensibleid), mode.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetAllMissileTurretsArmed", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string arm = req.get_param_value("arm");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (arm.empty())
        {
            return BadRequest(res, "arm must be set");
        }
        try {
            SET_CONTENT(ffijson::SetAllMissileTurretsArmed(PARAMS(std::stoll(defensibleid), std::stoi(arm))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetAllNonMissileTurretModes", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string mode = req.get_param_value("mode");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (mode.empty())
        {
            return BadRequest(res, "mode must be set");
        }
        try {
            SET_CONTENT(ffijson::SetAllNonMissileTurretModes(PARAMS(std::stoll(defensibleid), mode.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetAllNonMissileTurretsArmed", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string arm = req.get_param_value("arm");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (arm.empty())
        {
            return BadRequest(res, "arm must be set");
        }
        try {
            SET_CONTENT(ffijson::SetAllNonMissileTurretsArmed(PARAMS(std::stoll(defensibleid), std::stoi(arm))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetAllTurretModes", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string mode = req.get_param_value("mode");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (mode.empty())
        {
            return BadRequest(res, "mode must be set");
        }
        try {
            SET_CONTENT(ffijson::SetAllTurretModes(PARAMS(std::stoll(defensibleid), mode.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetAllTurretsArmed", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string arm = req.get_param_value("arm");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (arm.empty())
        {
            return BadRequest(res, "arm must be set");
        }
        try {
            SET_CONTENT(ffijson::SetAllTurretsArmed(PARAMS(std::stoll(defensibleid), std::stoi(arm))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetAllowedWeaponSystems", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string orderidx = req.get_param_value("orderidx");
        std::string usedefault = req.get_param_value("usedefault");
        std::string numuiweaponsysteminfo = req.get_param_value("numuiweaponsysteminfo");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (orderidx.empty())
        {
            return BadRequest(res, "orderidx must be set");
        }
        if (usedefault.empty())
        {
            return BadRequest(res, "usedefault must be set");
        }
        if (numuiweaponsysteminfo.empty())
        {
            return BadRequest(res, "numuiweaponsysteminfo must be set");
        }
        try {
            SET_CONTENT(ffijson::SetAllowedWeaponSystems(PARAMS(std::stoll(defensibleid), std::stoll(orderidx), std::stoi(usedefault), std::stoll(numuiweaponsysteminfo))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetAutoRoll", HAN_FN {
        std::string value = req.get_param_value("value");
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetAutoRoll(PARAMS(std::stoi(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetAutosaveIntervalOption", HAN_FN {
        std::string factor = req.get_param_value("factor");
        if (factor.empty())
        {
            return BadRequest(res, "factor must be set");
        }
        try {
            SET_CONTENT(ffijson::SetAutosaveIntervalOption(PARAMS(std::stof(factor))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetBoxText", HAN_FN {
        std::string boxtextid = req.get_param_value("boxtextid");
        std::string text = req.get_param_value("text");
        if (boxtextid.empty())
        {
            return BadRequest(res, "boxtextid must be set");
        }
        if (text.empty())
        {
            return BadRequest(res, "text must be set");
        }
        try {
            SET_CONTENT(ffijson::SetBoxText(PARAMS(std::stoi(boxtextid), text.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetButtonActive", HAN_FN {
        std::string buttonid = req.get_param_value("buttonid");
        std::string active = req.get_param_value("active");
        if (buttonid.empty())
        {
            return BadRequest(res, "buttonid must be set");
        }
        if (active.empty())
        {
            return BadRequest(res, "active must be set");
        }
        try {
            SET_CONTENT(ffijson::SetButtonActive(PARAMS(std::stoi(buttonid), std::stoi(active))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetButtonIcon2ID", HAN_FN {
        std::string buttonid = req.get_param_value("buttonid");
        std::string iconid = req.get_param_value("iconid");
        if (buttonid.empty())
        {
            return BadRequest(res, "buttonid must be set");
        }
        if (iconid.empty())
        {
            return BadRequest(res, "iconid must be set");
        }
        try {
            SET_CONTENT(ffijson::SetButtonIcon2ID(PARAMS(std::stoi(buttonid), iconid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetButtonIconID", HAN_FN {
        std::string buttonid = req.get_param_value("buttonid");
        std::string iconid = req.get_param_value("iconid");
        if (buttonid.empty())
        {
            return BadRequest(res, "buttonid must be set");
        }
        if (iconid.empty())
        {
            return BadRequest(res, "iconid must be set");
        }
        try {
            SET_CONTENT(ffijson::SetButtonIconID(PARAMS(std::stoi(buttonid), iconid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetButtonText2", HAN_FN {
        std::string buttonid = req.get_param_value("buttonid");
        std::string text = req.get_param_value("text");
        if (buttonid.empty())
        {
            return BadRequest(res, "buttonid must be set");
        }
        if (text.empty())
        {
            return BadRequest(res, "text must be set");
        }
        try {
            SET_CONTENT(ffijson::SetButtonText2(PARAMS(std::stoi(buttonid), text.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetCheckBoxChecked2", HAN_FN {
        std::string checkboxid = req.get_param_value("checkboxid");
        std::string checked = req.get_param_value("checked");
        std::string update = req.get_param_value("update");
        if (checkboxid.empty())
        {
            return BadRequest(res, "checkboxid must be set");
        }
        if (checked.empty())
        {
            return BadRequest(res, "checked must be set");
        }
        if (update.empty())
        {
            return BadRequest(res, "update must be set");
        }
        try {
            SET_CONTENT(ffijson::SetCheckBoxChecked2(PARAMS(std::stoi(checkboxid), std::stoi(checked), std::stoi(update))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetChromaticAberrationOption", HAN_FN {
        std::string value = req.get_param_value("value");
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetChromaticAberrationOption(PARAMS(std::stoi(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetCockpitCameraScaleOption", HAN_FN {
        std::string value = req.get_param_value("value");
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetCockpitCameraScaleOption(PARAMS(std::stof(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetConfigSetting", HAN_FN {
        std::string setting = req.get_param_value("setting");
        std::string value = req.get_param_value("value");
        if (setting.empty())
        {
            return BadRequest(res, "setting must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetConfigSetting(PARAMS(setting.c_str(), std::stoi(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetConstructionSequenceFromConstructionMap", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string holomapid = req.get_param_value("holomapid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        try {
            SET_CONTENT(ffijson::SetConstructionSequenceFromConstructionMap(PARAMS(std::stoll(containerid), std::stoll(holomapid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetContainerBuildAllowedFactions", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string numuifactions = req.get_param_value("numuifactions");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (numuifactions.empty())
        {
            return BadRequest(res, "numuifactions must be set");
        }
        try {
            SET_CONTENT(ffijson::SetContainerBuildAllowedFactions(PARAMS(std::stoll(containerid), std::stoll(numuifactions))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetContainerBuildPriceFactor", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string value = req.get_param_value("value");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetContainerBuildPriceFactor(PARAMS(std::stoll(containerid), std::stof(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetContainerBuyLimitOverride", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string wareid = req.get_param_value("wareid");
        std::string amount = req.get_param_value("amount");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        if (amount.empty())
        {
            return BadRequest(res, "amount must be set");
        }
        try {
            SET_CONTENT(ffijson::SetContainerBuyLimitOverride(PARAMS(std::stoll(containerid), wareid.c_str(), std::stoi(amount))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetContainerFactionBuildRescricted", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string value = req.get_param_value("value");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetContainerFactionBuildRescricted(PARAMS(std::stoll(containerid), std::stoi(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetContainerGlobalPriceFactor", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string value = req.get_param_value("value");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetContainerGlobalPriceFactor(PARAMS(std::stoll(containerid), std::stof(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetContainerSellLimitOverride", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string wareid = req.get_param_value("wareid");
        std::string amount = req.get_param_value("amount");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        if (amount.empty())
        {
            return BadRequest(res, "amount must be set");
        }
        try {
            SET_CONTENT(ffijson::SetContainerSellLimitOverride(PARAMS(std::stoll(containerid), wareid.c_str(), std::stoi(amount))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetContainerWareIsBuyable", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string wareid = req.get_param_value("wareid");
        std::string allowed = req.get_param_value("allowed");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        if (allowed.empty())
        {
            return BadRequest(res, "allowed must be set");
        }
        try {
            SET_CONTENT(ffijson::SetContainerWareIsBuyable(PARAMS(std::stoll(containerid), wareid.c_str(), std::stoi(allowed))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetContainerWareIsSellable", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string wareid = req.get_param_value("wareid");
        std::string allowed = req.get_param_value("allowed");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        if (allowed.empty())
        {
            return BadRequest(res, "allowed must be set");
        }
        try {
            SET_CONTENT(ffijson::SetContainerWareIsSellable(PARAMS(std::stoll(containerid), wareid.c_str(), std::stoi(allowed))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetControllableBlacklist", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string id = req.get_param_value("id");
        std::string listtype = req.get_param_value("listtype");
        std::string value = req.get_param_value("value");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (listtype.empty())
        {
            return BadRequest(res, "listtype must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetControllableBlacklist(PARAMS(std::stoll(controllableid), std::stoll(id), listtype.c_str(), std::stoi(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetCrosshairMessage", HAN_FN {
        std::string messageid = req.get_param_value("messageid");
        if (messageid.empty())
        {
            return BadRequest(res, "messageid must be set");
        }
        try {
            SET_CONTENT(ffijson::SetCrosshairMessage(PARAMS(std::stoll(messageid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetCustomGameStartBlueprintProperty", HAN_FN {
        std::string id = req.get_param_value("id");
        std::string propertyid = req.get_param_value("propertyid");
        std::string uivaluecount = req.get_param_value("uivaluecount");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (propertyid.empty())
        {
            return BadRequest(res, "propertyid must be set");
        }
        if (uivaluecount.empty())
        {
            return BadRequest(res, "uivaluecount must be set");
        }
        try {
            SET_CONTENT(ffijson::SetCustomGameStartBlueprintProperty(PARAMS(id.c_str(), propertyid.c_str(), std::stoll(uivaluecount))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetCustomGameStartBoolProperty", HAN_FN {
        std::string id = req.get_param_value("id");
        std::string propertyid = req.get_param_value("propertyid");
        std::string uivalue = req.get_param_value("uivalue");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (propertyid.empty())
        {
            return BadRequest(res, "propertyid must be set");
        }
        if (uivalue.empty())
        {
            return BadRequest(res, "uivalue must be set");
        }
        try {
            SET_CONTENT(ffijson::SetCustomGameStartBoolProperty(PARAMS(id.c_str(), propertyid.c_str(), std::stoi(uivalue))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetCustomGameStartEncyclopediaProperty", HAN_FN {
        std::string id = req.get_param_value("id");
        std::string propertyid = req.get_param_value("propertyid");
        std::string uivaluecount = req.get_param_value("uivaluecount");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (propertyid.empty())
        {
            return BadRequest(res, "propertyid must be set");
        }
        if (uivaluecount.empty())
        {
            return BadRequest(res, "uivaluecount must be set");
        }
        try {
            SET_CONTENT(ffijson::SetCustomGameStartEncyclopediaProperty(PARAMS(id.c_str(), propertyid.c_str(), std::stoll(uivaluecount))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetCustomGameStartInventoryProperty", HAN_FN {
        std::string id = req.get_param_value("id");
        std::string propertyid = req.get_param_value("propertyid");
        std::string uivaluecount = req.get_param_value("uivaluecount");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (propertyid.empty())
        {
            return BadRequest(res, "propertyid must be set");
        }
        if (uivaluecount.empty())
        {
            return BadRequest(res, "uivaluecount must be set");
        }
        try {
            SET_CONTENT(ffijson::SetCustomGameStartInventoryProperty(PARAMS(id.c_str(), propertyid.c_str(), std::stoll(uivaluecount))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetCustomGameStartMoneyProperty", HAN_FN {
        std::string id = req.get_param_value("id");
        std::string propertyid = req.get_param_value("propertyid");
        std::string uivalue = req.get_param_value("uivalue");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (propertyid.empty())
        {
            return BadRequest(res, "propertyid must be set");
        }
        if (uivalue.empty())
        {
            return BadRequest(res, "uivalue must be set");
        }
        try {
            SET_CONTENT(ffijson::SetCustomGameStartMoneyProperty(PARAMS(id.c_str(), propertyid.c_str(), std::stoi(uivalue))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetCustomGameStartRelationsProperty", HAN_FN {
        std::string id = req.get_param_value("id");
        std::string propertyid = req.get_param_value("propertyid");
        std::string uivaluecount = req.get_param_value("uivaluecount");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (propertyid.empty())
        {
            return BadRequest(res, "propertyid must be set");
        }
        if (uivaluecount.empty())
        {
            return BadRequest(res, "uivaluecount must be set");
        }
        try {
            SET_CONTENT(ffijson::SetCustomGameStartRelationsProperty(PARAMS(id.c_str(), propertyid.c_str(), std::stoll(uivaluecount))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetCustomGameStartResearchProperty", HAN_FN {
        std::string id = req.get_param_value("id");
        std::string propertyid = req.get_param_value("propertyid");
        std::string uivaluecount = req.get_param_value("uivaluecount");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (propertyid.empty())
        {
            return BadRequest(res, "propertyid must be set");
        }
        if (uivaluecount.empty())
        {
            return BadRequest(res, "uivaluecount must be set");
        }
        try {
            SET_CONTENT(ffijson::SetCustomGameStartResearchProperty(PARAMS(id.c_str(), propertyid.c_str(), std::stoll(uivaluecount))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetCustomGameStartStringProperty", HAN_FN {
        std::string id = req.get_param_value("id");
        std::string propertyid = req.get_param_value("propertyid");
        std::string uivalue = req.get_param_value("uivalue");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (propertyid.empty())
        {
            return BadRequest(res, "propertyid must be set");
        }
        if (uivalue.empty())
        {
            return BadRequest(res, "uivalue must be set");
        }
        try {
            SET_CONTENT(ffijson::SetCustomGameStartStringProperty(PARAMS(id.c_str(), propertyid.c_str(), uivalue.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetDefensibleActiveWeaponGroup", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string primary = req.get_param_value("primary");
        std::string groupidx = req.get_param_value("groupidx");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (primary.empty())
        {
            return BadRequest(res, "primary must be set");
        }
        if (groupidx.empty())
        {
            return BadRequest(res, "groupidx must be set");
        }
        try {
            SET_CONTENT(ffijson::SetDefensibleActiveWeaponGroup(PARAMS(std::stoll(defensibleid), std::stoi(primary), std::stoll(groupidx))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetDefensibleLoadoutLevel", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string value = req.get_param_value("value");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetDefensibleLoadoutLevel(PARAMS(std::stoll(defensibleid), std::stof(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetDockingBayReservation", HAN_FN {
        std::string dockingbayid = req.get_param_value("dockingbayid");
        std::string duration = req.get_param_value("duration");
        if (dockingbayid.empty())
        {
            return BadRequest(res, "dockingbayid must be set");
        }
        if (duration.empty())
        {
            return BadRequest(res, "duration must be set");
        }
        try {
            SET_CONTENT(ffijson::SetDockingBayReservation(PARAMS(std::stoll(dockingbayid), std::stol(duration))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetDroneMode", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string dronetype = req.get_param_value("dronetype");
        std::string mode = req.get_param_value("mode");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (dronetype.empty())
        {
            return BadRequest(res, "dronetype must be set");
        }
        if (mode.empty())
        {
            return BadRequest(res, "mode must be set");
        }
        try {
            SET_CONTENT(ffijson::SetDroneMode(PARAMS(std::stoll(defensibleid), dronetype.c_str(), mode.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetDroneTypeArmed", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string dronetype = req.get_param_value("dronetype");
        std::string arm = req.get_param_value("arm");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (dronetype.empty())
        {
            return BadRequest(res, "dronetype must be set");
        }
        if (arm.empty())
        {
            return BadRequest(res, "arm must be set");
        }
        try {
            SET_CONTENT(ffijson::SetDroneTypeArmed(PARAMS(std::stoll(defensibleid), dronetype.c_str(), std::stoi(arm))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetDropDownCurOption", HAN_FN {
        std::string dropdownid = req.get_param_value("dropdownid");
        std::string id = req.get_param_value("id");
        if (dropdownid.empty())
        {
            return BadRequest(res, "dropdownid must be set");
        }
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        try {
            SET_CONTENT(ffijson::SetDropDownCurOption(PARAMS(std::stoi(dropdownid), id.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetEditBoxActive", HAN_FN {
        std::string editboxid = req.get_param_value("editboxid");
        std::string active = req.get_param_value("active");
        if (editboxid.empty())
        {
            return BadRequest(res, "editboxid must be set");
        }
        if (active.empty())
        {
            return BadRequest(res, "active must be set");
        }
        try {
            SET_CONTENT(ffijson::SetEditBoxActive(PARAMS(std::stoi(editboxid), std::stoi(active))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetEditBoxText", HAN_FN {
        std::string editboxid = req.get_param_value("editboxid");
        std::string text = req.get_param_value("text");
        if (editboxid.empty())
        {
            return BadRequest(res, "editboxid must be set");
        }
        if (text.empty())
        {
            return BadRequest(res, "text must be set");
        }
        try {
            SET_CONTENT(ffijson::SetEditBoxText(PARAMS(std::stoi(editboxid), text.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetFill", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        std::string connectionname = req.get_param_value("connectionname");
        std::string red = req.get_param_value("red");
        std::string green = req.get_param_value("green");
        std::string blue = req.get_param_value("blue");
        std::string alpha = req.get_param_value("alpha");
        std::string animated = req.get_param_value("animated");
        std::string minalpha = req.get_param_value("minalpha");
        std::string maxalpha = req.get_param_value("maxalpha");
        std::string transitiontime = req.get_param_value("transitiontime");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        if (red.empty())
        {
            return BadRequest(res, "red must be set");
        }
        if (green.empty())
        {
            return BadRequest(res, "green must be set");
        }
        if (blue.empty())
        {
            return BadRequest(res, "blue must be set");
        }
        if (alpha.empty())
        {
            return BadRequest(res, "alpha must be set");
        }
        if (animated.empty())
        {
            return BadRequest(res, "animated must be set");
        }
        if (minalpha.empty())
        {
            return BadRequest(res, "minalpha must be set");
        }
        if (maxalpha.empty())
        {
            return BadRequest(res, "maxalpha must be set");
        }
        if (transitiontime.empty())
        {
            return BadRequest(res, "transitiontime must be set");
        }
        try {
            SET_CONTENT(ffijson::SetFill(PARAMS(std::stoll(componentid), connectionname.c_str(), std::stoi(red), std::stoi(green), std::stoi(blue), std::stof(alpha), std::stoi(animated), std::stof(minalpha), std::stof(maxalpha), std::stof(transitiontime))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetFleetName", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string fleetname = req.get_param_value("fleetname");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (fleetname.empty())
        {
            return BadRequest(res, "fleetname must be set");
        }
        try {
            SET_CONTENT(ffijson::SetFleetName(PARAMS(std::stoll(controllableid), fleetname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetFlowChartNodeCaptionText", HAN_FN {
        std::string flowchartnodeid = req.get_param_value("flowchartnodeid");
        std::string text = req.get_param_value("text");
        if (flowchartnodeid.empty())
        {
            return BadRequest(res, "flowchartnodeid must be set");
        }
        if (text.empty())
        {
            return BadRequest(res, "text must be set");
        }
        try {
            SET_CONTENT(ffijson::SetFlowChartNodeCaptionText(PARAMS(std::stoi(flowchartnodeid), text.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetFlowChartNodeCurValue", HAN_FN {
        std::string flowchartnodeid = req.get_param_value("flowchartnodeid");
        std::string value = req.get_param_value("value");
        if (flowchartnodeid.empty())
        {
            return BadRequest(res, "flowchartnodeid must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetFlowChartNodeCurValue(PARAMS(std::stoi(flowchartnodeid), std::stol(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetFlowChartNodeMaxValue", HAN_FN {
        std::string flowchartnodeid = req.get_param_value("flowchartnodeid");
        std::string value = req.get_param_value("value");
        if (flowchartnodeid.empty())
        {
            return BadRequest(res, "flowchartnodeid must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetFlowChartNodeMaxValue(PARAMS(std::stoi(flowchartnodeid), std::stol(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetFlowChartNodeSlider1Value", HAN_FN {
        std::string flowchartnodeid = req.get_param_value("flowchartnodeid");
        std::string value = req.get_param_value("value");
        if (flowchartnodeid.empty())
        {
            return BadRequest(res, "flowchartnodeid must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetFlowChartNodeSlider1Value(PARAMS(std::stoi(flowchartnodeid), std::stol(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetFlowChartNodeSlider2Value", HAN_FN {
        std::string flowchartnodeid = req.get_param_value("flowchartnodeid");
        std::string value = req.get_param_value("value");
        if (flowchartnodeid.empty())
        {
            return BadRequest(res, "flowchartnodeid must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetFlowChartNodeSlider2Value(PARAMS(std::stoi(flowchartnodeid), std::stol(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetFlowChartNodeSliderStep", HAN_FN {
        std::string flowchartnodeid = req.get_param_value("flowchartnodeid");
        std::string step = req.get_param_value("step");
        if (flowchartnodeid.empty())
        {
            return BadRequest(res, "flowchartnodeid must be set");
        }
        if (step.empty())
        {
            return BadRequest(res, "step must be set");
        }
        try {
            SET_CONTENT(ffijson::SetFlowChartNodeSliderStep(PARAMS(std::stoi(flowchartnodeid), std::stol(step))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetFlowChartNodeStatusBgIcon", HAN_FN {
        std::string flowchartnodeid = req.get_param_value("flowchartnodeid");
        std::string iconid = req.get_param_value("iconid");
        if (flowchartnodeid.empty())
        {
            return BadRequest(res, "flowchartnodeid must be set");
        }
        if (iconid.empty())
        {
            return BadRequest(res, "iconid must be set");
        }
        try {
            SET_CONTENT(ffijson::SetFlowChartNodeStatusBgIcon(PARAMS(std::stoi(flowchartnodeid), iconid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetFlowChartNodeStatusIcon", HAN_FN {
        std::string flowchartnodeid = req.get_param_value("flowchartnodeid");
        std::string iconid = req.get_param_value("iconid");
        if (flowchartnodeid.empty())
        {
            return BadRequest(res, "flowchartnodeid must be set");
        }
        if (iconid.empty())
        {
            return BadRequest(res, "iconid must be set");
        }
        try {
            SET_CONTENT(ffijson::SetFlowChartNodeStatusIcon(PARAMS(std::stoi(flowchartnodeid), iconid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetFlowChartNodeStatusText", HAN_FN {
        std::string flowchartnodeid = req.get_param_value("flowchartnodeid");
        std::string text = req.get_param_value("text");
        if (flowchartnodeid.empty())
        {
            return BadRequest(res, "flowchartnodeid must be set");
        }
        if (text.empty())
        {
            return BadRequest(res, "text must be set");
        }
        try {
            SET_CONTENT(ffijson::SetFlowChartNodeStatusText(PARAMS(std::stoi(flowchartnodeid), text.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetFlowchartNodeExpanded", HAN_FN {
        std::string flowchartnodeid = req.get_param_value("flowchartnodeid");
        std::string frameid = req.get_param_value("frameid");
        std::string expandedabove = req.get_param_value("expandedabove");
        if (flowchartnodeid.empty())
        {
            return BadRequest(res, "flowchartnodeid must be set");
        }
        if (frameid.empty())
        {
            return BadRequest(res, "frameid must be set");
        }
        if (expandedabove.empty())
        {
            return BadRequest(res, "expandedabove must be set");
        }
        try {
            SET_CONTENT(ffijson::SetFlowchartNodeExpanded(PARAMS(std::stoi(flowchartnodeid), std::stoi(frameid), std::stoi(expandedabove))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetFocusMapComponent", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string componentid = req.get_param_value("componentid");
        std::string resetplayerpan = req.get_param_value("resetplayerpan");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        if (resetplayerpan.empty())
        {
            return BadRequest(res, "resetplayerpan must be set");
        }
        try {
            SET_CONTENT(ffijson::SetFocusMapComponent(PARAMS(std::stoll(holomapid), std::stoll(componentid), std::stoi(resetplayerpan))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetForceShootingAtCursorOption", HAN_FN {
        std::string value = req.get_param_value("value");
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetForceShootingAtCursorOption(PARAMS(std::stoi(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetGroupAndAssignment", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string group = req.get_param_value("group");
        std::string assignment = req.get_param_value("assignment");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (group.empty())
        {
            return BadRequest(res, "group must be set");
        }
        if (assignment.empty())
        {
            return BadRequest(res, "assignment must be set");
        }
        try {
            SET_CONTENT(ffijson::SetGroupAndAssignment(PARAMS(std::stoll(controllableid), std::stoi(group), assignment.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetHUDRadarActive", HAN_FN {
        std::string setting = req.get_param_value("setting");
        if (setting.empty())
        {
            return BadRequest(res, "setting must be set");
        }
        try {
            SET_CONTENT(ffijson::SetHUDRadarActive(PARAMS(std::stoi(setting))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetHUDRadarSeparate", HAN_FN {
        std::string setting = req.get_param_value("setting");
        if (setting.empty())
        {
            return BadRequest(res, "setting must be set");
        }
        try {
            SET_CONTENT(ffijson::SetHUDRadarSeparate(PARAMS(std::stoi(setting))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetIcon", HAN_FN {
        std::string widgeticonid = req.get_param_value("widgeticonid");
        std::string iconid = req.get_param_value("iconid");
        if (widgeticonid.empty())
        {
            return BadRequest(res, "widgeticonid must be set");
        }
        if (iconid.empty())
        {
            return BadRequest(res, "iconid must be set");
        }
        try {
            SET_CONTENT(ffijson::SetIcon(PARAMS(std::stoi(widgeticonid), iconid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetIconText", HAN_FN {
        std::string widgeticonid = req.get_param_value("widgeticonid");
        std::string text = req.get_param_value("text");
        if (widgeticonid.empty())
        {
            return BadRequest(res, "widgeticonid must be set");
        }
        if (text.empty())
        {
            return BadRequest(res, "text must be set");
        }
        try {
            SET_CONTENT(ffijson::SetIconText(PARAMS(std::stoi(widgeticonid), text.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetIconText2", HAN_FN {
        std::string widgeticonid = req.get_param_value("widgeticonid");
        std::string text = req.get_param_value("text");
        if (widgeticonid.empty())
        {
            return BadRequest(res, "widgeticonid must be set");
        }
        if (text.empty())
        {
            return BadRequest(res, "text must be set");
        }
        try {
            SET_CONTENT(ffijson::SetIconText2(PARAMS(std::stoi(widgeticonid), text.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetInversionSetting", HAN_FN {
        std::string uirangeid = req.get_param_value("uirangeid");
        std::string parametername = req.get_param_value("parametername");
        std::string value = req.get_param_value("value");
        if (uirangeid.empty())
        {
            return BadRequest(res, "uirangeid must be set");
        }
        if (parametername.empty())
        {
            return BadRequest(res, "parametername must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetInversionSetting(PARAMS(std::stoll(uirangeid), parametername.c_str(), std::stoi(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetJoystickSteeringAdapative", HAN_FN {
        std::string value = req.get_param_value("value");
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetJoystickSteeringAdapative(PARAMS(std::stoi(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetKnownRead", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        std::string read = req.get_param_value("read");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        if (read.empty())
        {
            return BadRequest(res, "read must be set");
        }
        try {
            SET_CONTENT(ffijson::SetKnownRead(PARAMS(std::stoll(componentid), std::stoi(read))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetLUTMode", HAN_FN {
        std::string mode = req.get_param_value("mode");
        if (mode.empty())
        {
            return BadRequest(res, "mode must be set");
        }
        try {
            SET_CONTENT(ffijson::SetLUTMode(PARAMS(std::stoll(mode))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetMacroMapLocalLinearHighways", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string value = req.get_param_value("value");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetMacroMapLocalLinearHighways(PARAMS(std::stoll(holomapid), std::stoi(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetMacroMapLocalRingHighways", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string value = req.get_param_value("value");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetMacroMapLocalRingHighways(PARAMS(std::stoll(holomapid), std::stoi(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetMapAlertFilter", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string alertlevel = req.get_param_value("alertlevel");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (alertlevel.empty())
        {
            return BadRequest(res, "alertlevel must be set");
        }
        try {
            SET_CONTENT(ffijson::SetMapAlertFilter(PARAMS(std::stoll(holomapid), std::stoll(alertlevel))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetMapFactionRelationColorOption", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string value = req.get_param_value("value");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetMapFactionRelationColorOption(PARAMS(std::stoll(holomapid), std::stoi(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetMapPaintMod", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string wareid = req.get_param_value("wareid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        try {
            SET_CONTENT(ffijson::SetMapPaintMod(PARAMS(std::stoll(holomapid), wareid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetMapPanOffset", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string offsetcomponentid = req.get_param_value("offsetcomponentid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (offsetcomponentid.empty())
        {
            return BadRequest(res, "offsetcomponentid must be set");
        }
        try {
            SET_CONTENT(ffijson::SetMapPanOffset(PARAMS(std::stoll(holomapid), std::stoll(offsetcomponentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetMapPicking", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string enable = req.get_param_value("enable");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (enable.empty())
        {
            return BadRequest(res, "enable must be set");
        }
        try {
            SET_CONTENT(ffijson::SetMapPicking(PARAMS(std::stoll(holomapid), std::stoi(enable))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetMapRelativeMousePosition", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string valid = req.get_param_value("valid");
        std::string x = req.get_param_value("x");
        std::string y = req.get_param_value("y");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (valid.empty())
        {
            return BadRequest(res, "valid must be set");
        }
        if (x.empty())
        {
            return BadRequest(res, "x must be set");
        }
        if (y.empty())
        {
            return BadRequest(res, "y must be set");
        }
        try {
            SET_CONTENT(ffijson::SetMapRelativeMousePosition(PARAMS(std::stoll(holomapid), std::stoi(valid), std::stof(x), std::stof(y))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetMapRenderAllAllyOrderQueues", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string value = req.get_param_value("value");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetMapRenderAllAllyOrderQueues(PARAMS(std::stoll(holomapid), std::stoi(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetMapRenderAllOrderQueues", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string value = req.get_param_value("value");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetMapRenderAllOrderQueues(PARAMS(std::stoll(holomapid), std::stoi(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetMapRenderCargoContents", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string value = req.get_param_value("value");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetMapRenderCargoContents(PARAMS(std::stoll(holomapid), std::stoi(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetMapRenderCivilianShips", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string value = req.get_param_value("value");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetMapRenderCivilianShips(PARAMS(std::stoll(holomapid), std::stoi(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetMapRenderCrewInfo", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string value = req.get_param_value("value");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetMapRenderCrewInfo(PARAMS(std::stoll(holomapid), std::stoi(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetMapRenderDockedShipInfos", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string value = req.get_param_value("value");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetMapRenderDockedShipInfos(PARAMS(std::stoll(holomapid), std::stoi(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetMapRenderEclipticLines", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string value = req.get_param_value("value");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetMapRenderEclipticLines(PARAMS(std::stoll(holomapid), std::stoi(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetMapRenderMissionGuidance", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string missionid = req.get_param_value("missionid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (missionid.empty())
        {
            return BadRequest(res, "missionid must be set");
        }
        try {
            SET_CONTENT(ffijson::SetMapRenderMissionGuidance(PARAMS(std::stoll(holomapid), std::stoll(missionid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetMapRenderMissionOffers", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string value = req.get_param_value("value");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetMapRenderMissionOffers(PARAMS(std::stoll(holomapid), std::stoi(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetMapRenderResourceInfo", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string value = req.get_param_value("value");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetMapRenderResourceInfo(PARAMS(std::stoll(holomapid), std::stoi(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetMapRenderSelectionLines", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string value = req.get_param_value("value");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetMapRenderSelectionLines(PARAMS(std::stoll(holomapid), std::stoi(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetMapRenderTradeOffers", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string value = req.get_param_value("value");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetMapRenderTradeOffers(PARAMS(std::stoll(holomapid), std::stoi(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetMapRenderWorkForceInfo", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string value = req.get_param_value("value");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetMapRenderWorkForceInfo(PARAMS(std::stoll(holomapid), std::stoi(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetMapRenderWrecks", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string value = req.get_param_value("value");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetMapRenderWrecks(PARAMS(std::stoll(holomapid), std::stoi(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetMapStationInfoBoxMargin", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string margin = req.get_param_value("margin");
        std::string width = req.get_param_value("width");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (margin.empty())
        {
            return BadRequest(res, "margin must be set");
        }
        if (width.empty())
        {
            return BadRequest(res, "width must be set");
        }
        try {
            SET_CONTENT(ffijson::SetMapStationInfoBoxMargin(PARAMS(std::stoll(holomapid), margin.c_str(), std::stoll(width))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetMapTargetDistance", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string distance = req.get_param_value("distance");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (distance.empty())
        {
            return BadRequest(res, "distance must be set");
        }
        try {
            SET_CONTENT(ffijson::SetMapTargetDistance(PARAMS(std::stoll(holomapid), std::stof(distance))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetMapTopTradesCount", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string count = req.get_param_value("count");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (count.empty())
        {
            return BadRequest(res, "count must be set");
        }
        try {
            SET_CONTENT(ffijson::SetMapTopTradesCount(PARAMS(std::stoll(holomapid), std::stoll(count))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetMapTradeFilterByMaxPrice", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string price = req.get_param_value("price");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (price.empty())
        {
            return BadRequest(res, "price must be set");
        }
        try {
            SET_CONTENT(ffijson::SetMapTradeFilterByMaxPrice(PARAMS(std::stoll(holomapid), std::stoi(price))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetMapTradeFilterByMinTotalVolume", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string minvolume = req.get_param_value("minvolume");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (minvolume.empty())
        {
            return BadRequest(res, "minvolume must be set");
        }
        try {
            SET_CONTENT(ffijson::SetMapTradeFilterByMinTotalVolume(PARAMS(std::stoll(holomapid), std::stoll(minvolume))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetMapTradeFilterByPlayerOffer", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string buysellswitch = req.get_param_value("buysellswitch");
        std::string enable = req.get_param_value("enable");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (buysellswitch.empty())
        {
            return BadRequest(res, "buysellswitch must be set");
        }
        if (enable.empty())
        {
            return BadRequest(res, "enable must be set");
        }
        try {
            SET_CONTENT(ffijson::SetMapTradeFilterByPlayerOffer(PARAMS(std::stoll(holomapid), std::stoi(buysellswitch), std::stoi(enable))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetMapTradeFilterByWare", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string numwareids = req.get_param_value("numwareids");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (numwareids.empty())
        {
            return BadRequest(res, "numwareids must be set");
        }
        try {
            SET_CONTENT(ffijson::SetMapTradeFilterByWare(PARAMS(std::stoll(holomapid), std::stoll(numwareids))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetMapTradeFilterByWareTransport", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string numtransporttypes = req.get_param_value("numtransporttypes");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (numtransporttypes.empty())
        {
            return BadRequest(res, "numtransporttypes must be set");
        }
        try {
            SET_CONTENT(ffijson::SetMapTradeFilterByWareTransport(PARAMS(std::stoll(holomapid), std::stoll(numtransporttypes))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetMessageRead", HAN_FN {
        std::string messageid = req.get_param_value("messageid");
        std::string categoryname = req.get_param_value("categoryname");
        if (messageid.empty())
        {
            return BadRequest(res, "messageid must be set");
        }
        if (categoryname.empty())
        {
            return BadRequest(res, "categoryname must be set");
        }
        try {
            SET_CONTENT(ffijson::SetMessageRead(PARAMS(std::stoll(messageid), categoryname.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetMouseCursorPosition", HAN_FN {
        std::string posx = req.get_param_value("posx");
        std::string posy = req.get_param_value("posy");
        if (posx.empty())
        {
            return BadRequest(res, "posx must be set");
        }
        if (posy.empty())
        {
            return BadRequest(res, "posy must be set");
        }
        try {
            SET_CONTENT(ffijson::SetMouseCursorPosition(PARAMS(std::stoi(posx), std::stoi(posy))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetMouseHUDModeOption", HAN_FN {
        std::string value = req.get_param_value("value");
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetMouseHUDModeOption(PARAMS(std::stoll(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetMouseOverTextOption", HAN_FN {
        std::string value = req.get_param_value("value");
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetMouseOverTextOption(PARAMS(std::stoi(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetMouseSteeringAdapative", HAN_FN {
        std::string value = req.get_param_value("value");
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetMouseSteeringAdapative(PARAMS(std::stoi(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetMouseSteeringInvertedOption", HAN_FN {
        std::string paramname = req.get_param_value("paramname");
        std::string value = req.get_param_value("value");
        if (paramname.empty())
        {
            return BadRequest(res, "paramname must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetMouseSteeringInvertedOption(PARAMS(paramname.c_str(), std::stoi(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetNotificationTypeEnabled", HAN_FN {
        std::string id = req.get_param_value("id");
        std::string value = req.get_param_value("value");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetNotificationTypeEnabled(PARAMS(id.c_str(), std::stoi(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetOutline", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        std::string connectionname = req.get_param_value("connectionname");
        std::string red = req.get_param_value("red");
        std::string green = req.get_param_value("green");
        std::string blue = req.get_param_value("blue");
        std::string animated = req.get_param_value("animated");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        if (red.empty())
        {
            return BadRequest(res, "red must be set");
        }
        if (green.empty())
        {
            return BadRequest(res, "green must be set");
        }
        if (blue.empty())
        {
            return BadRequest(res, "blue must be set");
        }
        if (animated.empty())
        {
            return BadRequest(res, "animated must be set");
        }
        try {
            SET_CONTENT(ffijson::SetOutline(PARAMS(std::stoll(componentid), connectionname.c_str(), std::stoi(red), std::stoi(green), std::stoi(blue), std::stoi(animated))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetPlayerBlacklistDefault", HAN_FN {
        std::string id = req.get_param_value("id");
        std::string listtype = req.get_param_value("listtype");
        std::string defaultgroup = req.get_param_value("defaultgroup");
        std::string value = req.get_param_value("value");
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        if (listtype.empty())
        {
            return BadRequest(res, "listtype must be set");
        }
        if (defaultgroup.empty())
        {
            return BadRequest(res, "defaultgroup must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetPlayerBlacklistDefault(PARAMS(std::stoll(id), listtype.c_str(), defaultgroup.c_str(), std::stoi(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetPlayerCameraCockpitView", HAN_FN {
        std::string force = req.get_param_value("force");
        if (force.empty())
        {
            return BadRequest(res, "force must be set");
        }
        try {
            SET_CONTENT(ffijson::SetPlayerCameraCockpitView(PARAMS(std::stoi(force))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetPlayerCameraTargetView", HAN_FN {
        std::string targetid = req.get_param_value("targetid");
        std::string force = req.get_param_value("force");
        if (targetid.empty())
        {
            return BadRequest(res, "targetid must be set");
        }
        if (force.empty())
        {
            return BadRequest(res, "force must be set");
        }
        try {
            SET_CONTENT(ffijson::SetPlayerCameraTargetView(PARAMS(std::stoll(targetid), std::stoi(force))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetPlayerClothingTheme", HAN_FN {
        std::string theme = req.get_param_value("theme");
        if (theme.empty())
        {
            return BadRequest(res, "theme must be set");
        }
        try {
            SET_CONTENT(ffijson::SetPlayerClothingTheme(PARAMS(theme.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetPlayerFactionName", HAN_FN {
        std::string name = req.get_param_value("name");
        if (name.empty())
        {
            return BadRequest(res, "name must be set");
        }
        try {
            SET_CONTENT(ffijson::SetPlayerFactionName(PARAMS(name.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetPlayerGlobalLoadoutLevel", HAN_FN {
        std::string value = req.get_param_value("value");
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetPlayerGlobalLoadoutLevel(PARAMS(std::stof(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetPlayerIllegalWare", HAN_FN {
        std::string wareid = req.get_param_value("wareid");
        std::string illegal = req.get_param_value("illegal");
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        if (illegal.empty())
        {
            return BadRequest(res, "illegal must be set");
        }
        try {
            SET_CONTENT(ffijson::SetPlayerIllegalWare(PARAMS(wareid.c_str(), std::stoi(illegal))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetPlayerPaintTheme", HAN_FN {
        std::string theme = req.get_param_value("theme");
        if (theme.empty())
        {
            return BadRequest(res, "theme must be set");
        }
        try {
            SET_CONTENT(ffijson::SetPlayerPaintTheme(PARAMS(theme.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetPresentModeOption", HAN_FN {
        std::string mode = req.get_param_value("mode");
        if (mode.empty())
        {
            return BadRequest(res, "mode must be set");
        }
        try {
            SET_CONTENT(ffijson::SetPresentModeOption(PARAMS(mode.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetRadarMousePosition", HAN_FN {
        std::string x = req.get_param_value("x");
        std::string y = req.get_param_value("y");
        if (x.empty())
        {
            return BadRequest(res, "x must be set");
        }
        if (y.empty())
        {
            return BadRequest(res, "y must be set");
        }
        try {
            SET_CONTENT(ffijson::SetRadarMousePosition(PARAMS(std::stof(x), std::stof(y))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetSSROption2", HAN_FN {
        std::string value = req.get_param_value("value");
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetSSROption2(PARAMS(value.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetSavesCompressedOption", HAN_FN {
        std::string value = req.get_param_value("value");
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetSavesCompressedOption(PARAMS(std::stoi(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetSelectedMapComponent", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string componentid = req.get_param_value("componentid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        try {
            SET_CONTENT(ffijson::SetSelectedMapComponent(PARAMS(std::stoll(holomapid), std::stoll(componentid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetSelectedMapComponents", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string numcomponentids = req.get_param_value("numcomponentids");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (numcomponentids.empty())
        {
            return BadRequest(res, "numcomponentids must be set");
        }
        try {
            SET_CONTENT(ffijson::SetSelectedMapComponents(PARAMS(std::stoll(holomapid), std::stoll(numcomponentids))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetSelectedMapGroup", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string destructibleid = req.get_param_value("destructibleid");
        std::string macroname = req.get_param_value("macroname");
        std::string path = req.get_param_value("path");
        std::string group = req.get_param_value("group");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (destructibleid.empty())
        {
            return BadRequest(res, "destructibleid must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        if (path.empty())
        {
            return BadRequest(res, "path must be set");
        }
        if (group.empty())
        {
            return BadRequest(res, "group must be set");
        }
        try {
            SET_CONTENT(ffijson::SetSelectedMapGroup(PARAMS(std::stoll(holomapid), std::stoll(destructibleid), macroname.c_str(), path.c_str(), group.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetSelectedMapMacroSlot", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string moduleid = req.get_param_value("moduleid");
        std::string macroname = req.get_param_value("macroname");
        std::string ismodule = req.get_param_value("ismodule");
        std::string upgradetypename = req.get_param_value("upgradetypename");
        std::string slot = req.get_param_value("slot");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (moduleid.empty())
        {
            return BadRequest(res, "moduleid must be set");
        }
        if (macroname.empty())
        {
            return BadRequest(res, "macroname must be set");
        }
        if (ismodule.empty())
        {
            return BadRequest(res, "ismodule must be set");
        }
        if (upgradetypename.empty())
        {
            return BadRequest(res, "upgradetypename must be set");
        }
        if (slot.empty())
        {
            return BadRequest(res, "slot must be set");
        }
        try {
            SET_CONTENT(ffijson::SetSelectedMapMacroSlot(PARAMS(std::stoll(holomapid), std::stoll(defensibleid), std::stoll(moduleid), macroname.c_str(), std::stoi(ismodule), upgradetypename.c_str(), std::stoll(slot))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetShieldHullBarHullPercent", HAN_FN {
        std::string shieldhullbarid = req.get_param_value("shieldhullbarid");
        std::string hullpercent = req.get_param_value("hullpercent");
        if (shieldhullbarid.empty())
        {
            return BadRequest(res, "shieldhullbarid must be set");
        }
        if (hullpercent.empty())
        {
            return BadRequest(res, "hullpercent must be set");
        }
        try {
            SET_CONTENT(ffijson::SetShieldHullBarHullPercent(PARAMS(std::stoi(shieldhullbarid), std::stof(hullpercent))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetShieldHullBarShieldPercent", HAN_FN {
        std::string shieldhullbarid = req.get_param_value("shieldhullbarid");
        std::string shieldpercent = req.get_param_value("shieldpercent");
        if (shieldhullbarid.empty())
        {
            return BadRequest(res, "shieldhullbarid must be set");
        }
        if (shieldpercent.empty())
        {
            return BadRequest(res, "shieldpercent must be set");
        }
        try {
            SET_CONTENT(ffijson::SetShieldHullBarShieldPercent(PARAMS(std::stoi(shieldhullbarid), std::stof(shieldpercent))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetSliderCellMaxFactor", HAN_FN {
        std::string slidercellid = req.get_param_value("slidercellid");
        std::string maxfactor = req.get_param_value("maxfactor");
        if (slidercellid.empty())
        {
            return BadRequest(res, "slidercellid must be set");
        }
        if (maxfactor.empty())
        {
            return BadRequest(res, "maxfactor must be set");
        }
        try {
            SET_CONTENT(ffijson::SetSliderCellMaxFactor(PARAMS(std::stoi(slidercellid), std::stoll(maxfactor))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetSliderCellMaxSelectValue", HAN_FN {
        std::string slidercellid = req.get_param_value("slidercellid");
        std::string value = req.get_param_value("value");
        if (slidercellid.empty())
        {
            return BadRequest(res, "slidercellid must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetSliderCellMaxSelectValue(PARAMS(std::stoi(slidercellid), std::stol(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetSliderCellMaxValue", HAN_FN {
        std::string slidercellid = req.get_param_value("slidercellid");
        std::string value = req.get_param_value("value");
        if (slidercellid.empty())
        {
            return BadRequest(res, "slidercellid must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetSliderCellMaxValue(PARAMS(std::stoi(slidercellid), std::stol(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetSliderCellValue", HAN_FN {
        std::string slidercellid = req.get_param_value("slidercellid");
        std::string value = req.get_param_value("value");
        if (slidercellid.empty())
        {
            return BadRequest(res, "slidercellid must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetSliderCellValue(PARAMS(std::stoi(slidercellid), std::stol(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetSpeakTargetNameOption", HAN_FN {
        std::string value = req.get_param_value("value");
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetSpeakTargetNameOption(PARAMS(std::stoi(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetStatusBarCurrentValue", HAN_FN {
        std::string statusbarid = req.get_param_value("statusbarid");
        std::string value = req.get_param_value("value");
        if (statusbarid.empty())
        {
            return BadRequest(res, "statusbarid must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetStatusBarCurrentValue(PARAMS(std::stoi(statusbarid), std::stof(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetStatusBarMaxValue", HAN_FN {
        std::string statusbarid = req.get_param_value("statusbarid");
        std::string value = req.get_param_value("value");
        if (statusbarid.empty())
        {
            return BadRequest(res, "statusbarid must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetStatusBarMaxValue(PARAMS(std::stoi(statusbarid), std::stof(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetStatusBarStartValue", HAN_FN {
        std::string statusbarid = req.get_param_value("statusbarid");
        std::string value = req.get_param_value("value");
        if (statusbarid.empty())
        {
            return BadRequest(res, "statusbarid must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetStatusBarStartValue(PARAMS(std::stoi(statusbarid), std::stof(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetSubordinateGroupAssignment", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string group = req.get_param_value("group");
        std::string assignment = req.get_param_value("assignment");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (group.empty())
        {
            return BadRequest(res, "group must be set");
        }
        if (assignment.empty())
        {
            return BadRequest(res, "assignment must be set");
        }
        try {
            SET_CONTENT(ffijson::SetSubordinateGroupAssignment(PARAMS(std::stoll(controllableid), std::stoi(group), assignment.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetSubordinateGroupDockAtCommander", HAN_FN {
        std::string controllableid = req.get_param_value("controllableid");
        std::string group = req.get_param_value("group");
        std::string value = req.get_param_value("value");
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        if (group.empty())
        {
            return BadRequest(res, "group must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetSubordinateGroupDockAtCommander(PARAMS(std::stoll(controllableid), std::stoi(group), std::stoi(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetSupplyManual", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string type = req.get_param_value("type");
        std::string onoff = req.get_param_value("onoff");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (type.empty())
        {
            return BadRequest(res, "type must be set");
        }
        if (onoff.empty())
        {
            return BadRequest(res, "onoff must be set");
        }
        try {
            SET_CONTENT(ffijson::SetSupplyManual(PARAMS(std::stoll(containerid), type.c_str(), std::stoi(onoff))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetTableNextConnectedTable", HAN_FN {
        std::string tableid = req.get_param_value("tableid");
        std::string nexttableid = req.get_param_value("nexttableid");
        if (tableid.empty())
        {
            return BadRequest(res, "tableid must be set");
        }
        if (nexttableid.empty())
        {
            return BadRequest(res, "nexttableid must be set");
        }
        try {
            SET_CONTENT(ffijson::SetTableNextConnectedTable(PARAMS(std::stoi(tableid), std::stoi(nexttableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetTableNextHorizontalConnectedTable", HAN_FN {
        std::string tableid = req.get_param_value("tableid");
        std::string nexttableid = req.get_param_value("nexttableid");
        if (tableid.empty())
        {
            return BadRequest(res, "tableid must be set");
        }
        if (nexttableid.empty())
        {
            return BadRequest(res, "nexttableid must be set");
        }
        try {
            SET_CONTENT(ffijson::SetTableNextHorizontalConnectedTable(PARAMS(std::stoi(tableid), std::stoi(nexttableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetTablePreviousConnectedTable", HAN_FN {
        std::string tableid = req.get_param_value("tableid");
        std::string prevtableid = req.get_param_value("prevtableid");
        if (tableid.empty())
        {
            return BadRequest(res, "tableid must be set");
        }
        if (prevtableid.empty())
        {
            return BadRequest(res, "prevtableid must be set");
        }
        try {
            SET_CONTENT(ffijson::SetTablePreviousConnectedTable(PARAMS(std::stoi(tableid), std::stoi(prevtableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetTablePreviousHorizontalConnectedTable", HAN_FN {
        std::string tableid = req.get_param_value("tableid");
        std::string prevtableid = req.get_param_value("prevtableid");
        if (tableid.empty())
        {
            return BadRequest(res, "tableid must be set");
        }
        if (prevtableid.empty())
        {
            return BadRequest(res, "prevtableid must be set");
        }
        try {
            SET_CONTENT(ffijson::SetTablePreviousHorizontalConnectedTable(PARAMS(std::stoi(tableid), std::stoi(prevtableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetTextureQualityOption", HAN_FN {
        std::string mode = req.get_param_value("mode");
        if (mode.empty())
        {
            return BadRequest(res, "mode must be set");
        }
        try {
            SET_CONTENT(ffijson::SetTextureQualityOption(PARAMS(mode.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetThrottleBidirectional", HAN_FN {
        std::string newsetting = req.get_param_value("newsetting");
        if (newsetting.empty())
        {
            return BadRequest(res, "newsetting must be set");
        }
        try {
            SET_CONTENT(ffijson::SetThrottleBidirectional(PARAMS(std::stoi(newsetting))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetTobiiAngleFactor", HAN_FN {
        std::string value = req.get_param_value("value");
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetTobiiAngleFactor(PARAMS(std::stof(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetTobiiDeadzoneAngle", HAN_FN {
        std::string value = req.get_param_value("value");
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetTobiiDeadzoneAngle(PARAMS(std::stof(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetTobiiDeadzonePosition", HAN_FN {
        std::string value = req.get_param_value("value");
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetTobiiDeadzonePosition(PARAMS(std::stof(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetTobiiGazeAngleFactor", HAN_FN {
        std::string value = req.get_param_value("value");
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetTobiiGazeAngleFactor(PARAMS(std::stof(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetTobiiGazeDeadzone", HAN_FN {
        std::string value = req.get_param_value("value");
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetTobiiGazeDeadzone(PARAMS(std::stof(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetTobiiGazeFilterStrength", HAN_FN {
        std::string value = req.get_param_value("value");
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetTobiiGazeFilterStrength(PARAMS(std::stoll(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetTobiiHeadFilterStrength", HAN_FN {
        std::string value = req.get_param_value("value");
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetTobiiHeadFilterStrength(PARAMS(std::stoll(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetTobiiHeadPositionFactor", HAN_FN {
        std::string value = req.get_param_value("value");
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetTobiiHeadPositionFactor(PARAMS(std::stof(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetTobiiMode", HAN_FN {
        std::string mode = req.get_param_value("mode");
        if (mode.empty())
        {
            return BadRequest(res, "mode must be set");
        }
        try {
            SET_CONTENT(ffijson::SetTobiiMode(PARAMS(mode.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetTrackedMenuFullscreen", HAN_FN {
        std::string menu = req.get_param_value("menu");
        std::string fullscreen = req.get_param_value("fullscreen");
        if (menu.empty())
        {
            return BadRequest(res, "menu must be set");
        }
        if (fullscreen.empty())
        {
            return BadRequest(res, "fullscreen must be set");
        }
        try {
            SET_CONTENT(ffijson::SetTrackedMenuFullscreen(PARAMS(menu.c_str(), std::stoi(fullscreen))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetTurretGroupArmed", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string contextid = req.get_param_value("contextid");
        std::string path = req.get_param_value("path");
        std::string group = req.get_param_value("group");
        std::string arm = req.get_param_value("arm");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (contextid.empty())
        {
            return BadRequest(res, "contextid must be set");
        }
        if (path.empty())
        {
            return BadRequest(res, "path must be set");
        }
        if (group.empty())
        {
            return BadRequest(res, "group must be set");
        }
        if (arm.empty())
        {
            return BadRequest(res, "arm must be set");
        }
        try {
            SET_CONTENT(ffijson::SetTurretGroupArmed(PARAMS(std::stoll(defensibleid), std::stoll(contextid), path.c_str(), group.c_str(), std::stoi(arm))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetTurretGroupMode2", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string contextid = req.get_param_value("contextid");
        std::string path = req.get_param_value("path");
        std::string group = req.get_param_value("group");
        std::string mode = req.get_param_value("mode");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (contextid.empty())
        {
            return BadRequest(res, "contextid must be set");
        }
        if (path.empty())
        {
            return BadRequest(res, "path must be set");
        }
        if (group.empty())
        {
            return BadRequest(res, "group must be set");
        }
        if (mode.empty())
        {
            return BadRequest(res, "mode must be set");
        }
        try {
            SET_CONTENT(ffijson::SetTurretGroupMode2(PARAMS(std::stoll(defensibleid), std::stoll(contextid), path.c_str(), group.c_str(), mode.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetUIScaleFactor", HAN_FN {
        std::string scale = req.get_param_value("scale");
        if (scale.empty())
        {
            return BadRequest(res, "scale must be set");
        }
        try {
            SET_CONTENT(ffijson::SetUIScaleFactor(PARAMS(std::stof(scale))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetVRVivePointerHand", HAN_FN {
        std::string hand = req.get_param_value("hand");
        if (hand.empty())
        {
            return BadRequest(res, "hand must be set");
        }
        try {
            SET_CONTENT(ffijson::SetVRVivePointerHand(PARAMS(std::stoi(hand))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetVentureOption", HAN_FN {
        std::string setting = req.get_param_value("setting");
        if (setting.empty())
        {
            return BadRequest(res, "setting must be set");
        }
        try {
            SET_CONTENT(ffijson::SetVentureOption(PARAMS(std::stoi(setting))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetVisitorNamesShownOption", HAN_FN {
        std::string setting = req.get_param_value("setting");
        if (setting.empty())
        {
            return BadRequest(res, "setting must be set");
        }
        try {
            SET_CONTENT(ffijson::SetVisitorNamesShownOption(PARAMS(std::stoi(setting))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetWeaponArmed", HAN_FN {
        std::string weaponid = req.get_param_value("weaponid");
        std::string arm = req.get_param_value("arm");
        if (weaponid.empty())
        {
            return BadRequest(res, "weaponid must be set");
        }
        if (arm.empty())
        {
            return BadRequest(res, "arm must be set");
        }
        try {
            SET_CONTENT(ffijson::SetWeaponArmed(PARAMS(std::stoll(weaponid), std::stoi(arm))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetWeaponGroup", HAN_FN {
        std::string defensibleid = req.get_param_value("defensibleid");
        std::string weaponid = req.get_param_value("weaponid");
        std::string primary = req.get_param_value("primary");
        std::string groupidx = req.get_param_value("groupidx");
        std::string value = req.get_param_value("value");
        if (defensibleid.empty())
        {
            return BadRequest(res, "defensibleid must be set");
        }
        if (weaponid.empty())
        {
            return BadRequest(res, "weaponid must be set");
        }
        if (primary.empty())
        {
            return BadRequest(res, "primary must be set");
        }
        if (groupidx.empty())
        {
            return BadRequest(res, "groupidx must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetWeaponGroup(PARAMS(std::stoll(defensibleid), std::stoll(weaponid), std::stoi(primary), std::stoll(groupidx), std::stoi(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetWeaponMode", HAN_FN {
        std::string weaponid = req.get_param_value("weaponid");
        std::string mode = req.get_param_value("mode");
        if (weaponid.empty())
        {
            return BadRequest(res, "weaponid must be set");
        }
        if (mode.empty())
        {
            return BadRequest(res, "mode must be set");
        }
        try {
            SET_CONTENT(ffijson::SetWeaponMode(PARAMS(std::stoll(weaponid), mode.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SetWidgetAssociatedElement", HAN_FN {
        std::string widgetid = req.get_param_value("widgetid");
        std::string value = req.get_param_value("value");
        if (widgetid.empty())
        {
            return BadRequest(res, "widgetid must be set");
        }
        if (value.empty())
        {
            return BadRequest(res, "value must be set");
        }
        try {
            SET_CONTENT(ffijson::SetWidgetAssociatedElement(PARAMS(std::stoi(widgetid), std::stoi(value))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ShowBuildPlotPlacementMap", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string sectorid = req.get_param_value("sectorid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (sectorid.empty())
        {
            return BadRequest(res, "sectorid must be set");
        }
        try {
            SET_CONTENT(ffijson::ShowBuildPlotPlacementMap(PARAMS(std::stoll(holomapid), std::stoll(sectorid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ShowConstructionMap", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string stationid = req.get_param_value("stationid");
        std::string constructionplanid = req.get_param_value("constructionplanid");
        std::string restore = req.get_param_value("restore");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (stationid.empty())
        {
            return BadRequest(res, "stationid must be set");
        }
        if (constructionplanid.empty())
        {
            return BadRequest(res, "constructionplanid must be set");
        }
        if (restore.empty())
        {
            return BadRequest(res, "restore must be set");
        }
        try {
            SET_CONTENT(ffijson::ShowConstructionMap(PARAMS(std::stoll(holomapid), std::stoll(stationid), constructionplanid.c_str(), std::stoi(restore))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ShowInteractMenu", HAN_FN {
        std::string componentid = req.get_param_value("componentid");
        std::string connectionname = req.get_param_value("connectionname");
        std::string id = req.get_param_value("id");
        if (componentid.empty())
        {
            return BadRequest(res, "componentid must be set");
        }
        if (id.empty())
        {
            return BadRequest(res, "id must be set");
        }
        try {
            SET_CONTENT(ffijson::ShowInteractMenu(PARAMS(std::stoll(componentid), connectionname.c_str(), std::stoll(id))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SignalObjectWithNPCSeed", HAN_FN {
        std::string objecttosignalid = req.get_param_value("objecttosignalid");
        std::string param = req.get_param_value("param");
        std::string person = req.get_param_value("person");
        std::string controllableid = req.get_param_value("controllableid");
        if (objecttosignalid.empty())
        {
            return BadRequest(res, "objecttosignalid must be set");
        }
        if (param.empty())
        {
            return BadRequest(res, "param must be set");
        }
        if (person.empty())
        {
            return BadRequest(res, "person must be set");
        }
        if (controllableid.empty())
        {
            return BadRequest(res, "controllableid must be set");
        }
        try {
            SET_CONTENT(ffijson::SignalObjectWithNPCSeed(PARAMS(std::stoll(objecttosignalid), param.c_str(), std::stoll(person), std::stoll(controllableid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/SkipNextStartAnimation", HAN_FN {
        try {
            SET_CONTENT(ffijson::SkipNextStartAnimation(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/StartBriefing", HAN_FN {
        std::string missionid = req.get_param_value("missionid");
        std::string texturename = req.get_param_value("texturename");
        std::string issubmission = req.get_param_value("issubmission");
        if (missionid.empty())
        {
            return BadRequest(res, "missionid must be set");
        }
        if (texturename.empty())
        {
            return BadRequest(res, "texturename must be set");
        }
        if (issubmission.empty())
        {
            return BadRequest(res, "issubmission must be set");
        }
        try {
            SET_CONTENT(ffijson::StartBriefing(PARAMS(std::stoll(missionid), texturename.c_str(), std::stoi(issubmission))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/StartIntroAnimation", HAN_FN {
        std::string triggername = req.get_param_value("triggername");
        if (triggername.empty())
        {
            return BadRequest(res, "triggername must be set");
        }
        try {
            SET_CONTENT(ffijson::StartIntroAnimation(PARAMS(triggername.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/StartMapBoxSelect", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string selectenemies = req.get_param_value("selectenemies");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (selectenemies.empty())
        {
            return BadRequest(res, "selectenemies must be set");
        }
        try {
            SET_CONTENT(ffijson::StartMapBoxSelect(PARAMS(std::stoll(holomapid), std::stoi(selectenemies))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/StartPanMap", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        try {
            SET_CONTENT(ffijson::StartPanMap(PARAMS(std::stoll(holomapid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/StartPlayerActivity", HAN_FN {
        std::string activityid = req.get_param_value("activityid");
        if (activityid.empty())
        {
            return BadRequest(res, "activityid must be set");
        }
        try {
            SET_CONTENT(ffijson::StartPlayerActivity(PARAMS(activityid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/StartResearch", HAN_FN {
        std::string wareid = req.get_param_value("wareid");
        std::string researchmoduleid = req.get_param_value("researchmoduleid");
        if (wareid.empty())
        {
            return BadRequest(res, "wareid must be set");
        }
        if (researchmoduleid.empty())
        {
            return BadRequest(res, "researchmoduleid must be set");
        }
        try {
            SET_CONTENT(ffijson::StartResearch(PARAMS(wareid.c_str(), std::stoll(researchmoduleid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/StartRotateMap", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        try {
            SET_CONTENT(ffijson::StartRotateMap(PARAMS(std::stoll(holomapid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/StartStartMenuBGMusic", HAN_FN {
        try {
            SET_CONTENT(ffijson::StartStartMenuBGMusic(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/StartVoiceSequence", HAN_FN {
        std::string sequenceid = req.get_param_value("sequenceid");
        std::string entityid = req.get_param_value("entityid");
        if (sequenceid.empty())
        {
            return BadRequest(res, "sequenceid must be set");
        }
        if (entityid.empty())
        {
            return BadRequest(res, "entityid must be set");
        }
        try {
            SET_CONTENT(ffijson::StartVoiceSequence(PARAMS(sequenceid.c_str(), std::stoll(entityid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/StopBriefing", HAN_FN {
        std::string missionid = req.get_param_value("missionid");
        std::string issubmission = req.get_param_value("issubmission");
        if (missionid.empty())
        {
            return BadRequest(res, "missionid must be set");
        }
        if (issubmission.empty())
        {
            return BadRequest(res, "issubmission must be set");
        }
        try {
            SET_CONTENT(ffijson::StopBriefing(PARAMS(std::stoll(missionid), std::stoi(issubmission))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/StopDetailmonitorCutscene", HAN_FN {
        std::string cutsceneid = req.get_param_value("cutsceneid");
        if (cutsceneid.empty())
        {
            return BadRequest(res, "cutsceneid must be set");
        }
        try {
            SET_CONTENT(ffijson::StopDetailmonitorCutscene(PARAMS(std::stoll(cutsceneid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/StopMapBoxSelect", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        try {
            SET_CONTENT(ffijson::StopMapBoxSelect(PARAMS(std::stoll(holomapid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/StopPlayerActivity", HAN_FN {
        std::string activityid = req.get_param_value("activityid");
        if (activityid.empty())
        {
            return BadRequest(res, "activityid must be set");
        }
        try {
            SET_CONTENT(ffijson::StopPlayerActivity(PARAMS(activityid.c_str())));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/StopStartMenuBGMusic", HAN_FN {
        try {
            SET_CONTENT(ffijson::StopStartMenuBGMusic(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/StopVoiceSequence", HAN_FN {
        try {
            SET_CONTENT(ffijson::StopVoiceSequence(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/StoreConstructionMapState", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        try {
            SET_CONTENT(ffijson::StoreConstructionMapState(PARAMS(std::stoll(holomapid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/TargetRadarComponent", HAN_FN {
        try {
            SET_CONTENT(ffijson::TargetRadarComponent(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ToggleDrones", HAN_FN {
        std::string dronetype = req.get_param_value("dronetype");
        if (dronetype.empty())
        {
            return BadRequest(res, "dronetype must be set");
        }
        try {
            SET_CONTENT(ffijson::ToggleDrones(PARAMS(std::stoll(dronetype))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ToggleFlightAssist", HAN_FN {
        try {
            SET_CONTENT(ffijson::ToggleFlightAssist(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ToggleScreenDisplayOption", HAN_FN {
        try {
            SET_CONTENT(ffijson::ToggleScreenDisplayOption(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/TrackMenu", HAN_FN {
        std::string menu = req.get_param_value("menu");
        std::string fullscreen = req.get_param_value("fullscreen");
        if (menu.empty())
        {
            return BadRequest(res, "menu must be set");
        }
        if (fullscreen.empty())
        {
            return BadRequest(res, "fullscreen must be set");
        }
        try {
            SET_CONTENT(ffijson::TrackMenu(PARAMS(menu.c_str(), std::stoi(fullscreen))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/UndoConstructionMapChange", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        try {
            SET_CONTENT(ffijson::UndoConstructionMapChange(PARAMS(std::stoll(holomapid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/UnmutePlayerAlert", HAN_FN {
        std::string index = req.get_param_value("index");
        std::string silent = req.get_param_value("silent");
        if (index.empty())
        {
            return BadRequest(res, "index must be set");
        }
        if (silent.empty())
        {
            return BadRequest(res, "silent must be set");
        }
        try {
            SET_CONTENT(ffijson::UnmutePlayerAlert(PARAMS(std::stoll(index), std::stoi(silent))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/UnsetRadarRenderTarget", HAN_FN {
        try {
            SET_CONTENT(ffijson::UnsetRadarRenderTarget(PARAMS()));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/UpdateMapBuildPlot", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        try {
            SET_CONTENT(ffijson::UpdateMapBuildPlot(PARAMS(std::stoll(holomapid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/UpdateProduction", HAN_FN {
        std::string containerormoduleid = req.get_param_value("containerormoduleid");
        std::string force = req.get_param_value("force");
        if (containerormoduleid.empty())
        {
            return BadRequest(res, "containerormoduleid must be set");
        }
        if (force.empty())
        {
            return BadRequest(res, "force must be set");
        }
        try {
            SET_CONTENT(ffijson::UpdateProduction(PARAMS(std::stoll(containerormoduleid), std::stoi(force))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/UpdateProductionTradeOffers", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        try {
            SET_CONTENT(ffijson::UpdateProductionTradeOffers(PARAMS(std::stoll(containerid))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/UpdateSupplyOverrides", HAN_FN {
        std::string containerid = req.get_param_value("containerid");
        std::string numoverrides = req.get_param_value("numoverrides");
        if (containerid.empty())
        {
            return BadRequest(res, "containerid must be set");
        }
        if (numoverrides.empty())
        {
            return BadRequest(res, "numoverrides must be set");
        }
        try {
            SET_CONTENT(ffijson::UpdateSupplyOverrides(PARAMS(std::stoll(containerid), std::stoll(numoverrides))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });

    server.Get("/ZoomMap", HAN_FN {
        std::string holomapid = req.get_param_value("holomapid");
        std::string zoomstep = req.get_param_value("zoomstep");
        if (holomapid.empty())
        {
            return BadRequest(res, "holomapid must be set");
        }
        if (zoomstep.empty())
        {
            return BadRequest(res, "zoomstep must be set");
        }
        try {
            SET_CONTENT(ffijson::ZoomMap(PARAMS(std::stoll(holomapid), std::stof(zoomstep))));
        } catch (std::exception& e) {
            return BadRequest(res, e.what());
        }
    });
}
