
#pragma once

#include <nlohmann/json.hpp>
#include "ffi_funcs.h"
#include "../ffi/FFIInvoke.h"

using json = nlohmann::json;
using uint = unsigned int;

#define Q(x) #x
#define QUOTE(x) Q(x)

#define invoke(FuncName, ...)   ffi_invoke.invokeFn<X4FFI::FuncName>(QUOTE(FuncName), ##__VA_ARGS__);

#define PARAMS(...)     FFIInvoke& ffi_invoke, ##__VA_ARGS__

// ---

namespace ffijson
{
    using namespace X4FFI;


    json GetCrosshairArrowDetails(PARAMS(int posid,float radius))
    {
        const auto func_res_1 = invoke(GetCrosshairArrowDetails, posid, radius);
        return json
        {
            {"angle", func_res_1.angle},
            {"inside", func_res_1.inside},
            {"valid", func_res_1.valid}
        };
    }
 
    json GetAutosaveIntervalOption(PARAMS())
    {
        const auto func_res_1 = invoke(GetAutosaveIntervalOption);
        return json
        {
            {"mintime", func_res_1.mintime},
            {"maxtime", func_res_1.maxtime},
            {"factor", func_res_1.factor}
        };
    }
 
    json GetBlacklistInfoCounts(PARAMS(BlacklistID id))
    {
        const auto func_res_1 = invoke(GetBlacklistInfoCounts, id);
        return json
        {
            {"nummacros", func_res_1.nummacros},
            {"numfactions", func_res_1.numfactions}
        };
    }
 
    json GetControllableBlacklistID(PARAMS(UniverseID controllableid,const char* listtype,const char* defaultgroup))
    {
        const auto func_res_1 = invoke(GetControllableBlacklistID, controllableid, listtype, defaultgroup);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetBoardingRiskThresholds(PARAMS(UniverseID defensibletargetid,const char* boarderfactionid))
    {
        const auto func_res_1 = invoke(GetBoardingRiskThresholds, defensibletargetid, boarderfactionid);
        return json
        {
            {"approach", func_res_1.approach},
            {"insertion", func_res_1.insertion}
        };
    }
 
    json GetBuildTaskInfo(PARAMS(BuildTaskID id))
    {
        const auto func_res_1 = invoke(GetBuildTaskInfo, id);
        return json
        {
            {"id", func_res_1.id},
            {"buildingcontainer", func_res_1.buildingcontainer},
            {"component", func_res_1.component},
            {"macro", func_res_1.macro},
            {"factionid", func_res_1.factionid},
            {"buildercomponent", func_res_1.buildercomponent},
            {"price", func_res_1.price},
            {"ismissingresources", func_res_1.ismissingresources},
            {"queueposition", func_res_1.queueposition}
        };
    }
 
    json GetComponentDetails(PARAMS(const UniverseID componentid,const char*const connectionname))
    {
        const auto func_res_1 = invoke(GetComponentDetails, componentid, connectionname);
        return json
        {
            {"name", func_res_1.name},
            {"hull", func_res_1.hull},
            {"shield", func_res_1.shield},
            {"speed", func_res_1.speed},
            {"hasShield", func_res_1.hasShield}
        };
    }
 
    json GetCenteredMousePos(PARAMS())
    {
        const auto func_res_1 = invoke(GetCenteredMousePos);
        return json
        {
            {"x", func_res_1.x},
            {"y", func_res_1.y}
        };
    }
 
    json GetWidgetSystemSizeOverride(PARAMS())
    {
        const auto func_res_1 = invoke(GetWidgetSystemSizeOverride);
        return json
        {
            {"x", func_res_1.x},
            {"y", func_res_1.y}
        };
    }
 
    json GetBuildPlotCenterOffset(PARAMS(UniverseID stationid))
    {
        const auto func_res_1 = invoke(GetBuildPlotCenterOffset, stationid);
        return json
        {
            {"x", func_res_1.x},
            {"y", func_res_1.y},
            {"z", func_res_1.z}
        };
    }
 
    json GetBuildPlotSize(PARAMS(UniverseID stationid))
    {
        const auto func_res_1 = invoke(GetBuildPlotSize, stationid);
        return json
        {
            {"x", func_res_1.x},
            {"y", func_res_1.y},
            {"z", func_res_1.z}
        };
    }
 
    json GetMinimumBuildPlotCenterOffset(PARAMS(UniverseID stationid))
    {
        const auto func_res_1 = invoke(GetMinimumBuildPlotCenterOffset, stationid);
        return json
        {
            {"x", func_res_1.x},
            {"y", func_res_1.y},
            {"z", func_res_1.z}
        };
    }
 
    json GetMinimumBuildPlotSize(PARAMS(UniverseID stationid))
    {
        const auto func_res_1 = invoke(GetMinimumBuildPlotSize, stationid);
        return json
        {
            {"x", func_res_1.x},
            {"y", func_res_1.y},
            {"z", func_res_1.z}
        };
    }
 
    json GetPaidBuildPlotCenterOffset(PARAMS(UniverseID stationid))
    {
        const auto func_res_1 = invoke(GetPaidBuildPlotCenterOffset, stationid);
        return json
        {
            {"x", func_res_1.x},
            {"y", func_res_1.y},
            {"z", func_res_1.z}
        };
    }
 
    json GetPaidBuildPlotSize(PARAMS(UniverseID stationid))
    {
        const auto func_res_1 = invoke(GetPaidBuildPlotSize, stationid);
        return json
        {
            {"x", func_res_1.x},
            {"y", func_res_1.y},
            {"z", func_res_1.z}
        };
    }
 
    json GetNumBuildTaskCrewTransferInfo(PARAMS(UniverseID containerid,BuildTaskID id))
    {
        const auto func_res_1 = invoke(GetNumBuildTaskCrewTransferInfo, containerid, id);
        return json
        {
            {"numremoved", func_res_1.numremoved},
            {"numadded", func_res_1.numadded},
            {"numtransferred", func_res_1.numtransferred}
        };
    }
 
    json GetCurrentCrosshairMessage(PARAMS())
    {
        const auto func_res_1 = invoke(GetCurrentCrosshairMessage);
        return json
        {
            {"messageID", func_res_1.messageID},
            {"obstructed", func_res_1.obstructed}
        };
    }
 
    json GetCurrentCursorInfo(PARAMS())
    {
        const auto func_res_1 = invoke(GetCurrentCursorInfo);
        return json
        {
            {"width", func_res_1.width},
            {"height", func_res_1.height},
            {"xHotspot", func_res_1.xHotspot},
            {"yHotspot", func_res_1.yHotspot}
        };
    }
 
    json GetCustomGameStartBlueprintPropertyState(PARAMS(const char* id,const char* propertyid))
    {
        const auto func_res_1 = invoke(GetCustomGameStartBlueprintPropertyState, id, propertyid);
        return json
        {
            {"state", func_res_1.state},
            {"numvalues", func_res_1.numvalues},
            {"numdefaultvalues", func_res_1.numdefaultvalues}
        };
    }
 
    json GetCustomGameStartEncyclopediaPropertyState(PARAMS(const char* id,const char* propertyid))
    {
        const auto func_res_1 = invoke(GetCustomGameStartEncyclopediaPropertyState, id, propertyid);
        return json
        {
            {"state", func_res_1.state}
        };
    }
 
    json GetCustomGameStartInventoryPropertyState(PARAMS(const char* id,const char* propertyid))
    {
        const auto func_res_1 = invoke(GetCustomGameStartInventoryPropertyState, id, propertyid);
        return json
        {
            {"state", func_res_1.state},
            {"numvalues", func_res_1.numvalues},
            {"numdefaultvalues", func_res_1.numdefaultvalues}
        };
    }
 
    json GetCustomGameStartLoadoutPropertyState(PARAMS(const char* id,const char* propertyid))
    {
        const auto func_res_1 = invoke(GetCustomGameStartLoadoutPropertyState, id, propertyid);
        return json
        {
            {"state", func_res_1.state}
        };
    }
 
    json GetCustomGameStartRelationsPropertyState(PARAMS(const char* id,const char* propertyid))
    {
        const auto func_res_1 = invoke(GetCustomGameStartRelationsPropertyState, id, propertyid);
        return json
        {
            {"state", func_res_1.state}
        };
    }
 
    json GetCustomGameStartResearchPropertyState(PARAMS(const char* id,const char* propertyid))
    {
        const auto func_res_1 = invoke(GetCustomGameStartResearchPropertyState, id, propertyid);
        return json
        {
            {"state", func_res_1.state}
        };
    }
 
    json GetDroneDetails(PARAMS(const uint32_t dronetype))
    {
        const auto func_res_1 = invoke(GetDroneDetails, dronetype);
        return json
        {
            {"armed", func_res_1.armed},
            {"blocked", func_res_1.blocked},
            {"modeIcon", func_res_1.modeIcon},
            {"pending", func_res_1.pending},
            {"possible", func_res_1.possible},
            {"total", func_res_1.total},
            {"undocked", func_res_1.undocked}
        };
    }
 
    json GetEquipmentModInfo(PARAMS(const char* wareid))
    {
        const auto func_res_1 = invoke(GetEquipmentModInfo, wareid);
        return json
        {
            {"PropertyType", func_res_1.PropertyType},
            {"MinValueFloat", func_res_1.MinValueFloat},
            {"MaxValueFloat", func_res_1.MaxValueFloat},
            {"MinValueUINT", func_res_1.MinValueUINT},
            {"MaxValueUINT", func_res_1.MaxValueUINT},
            {"BonusMax", func_res_1.BonusMax},
            {"BonusChance", func_res_1.BonusChance}
        };
    }
 
    json GetFPS(PARAMS())
    {
        const auto func_res_1 = invoke(GetFPS);
        return json
        {
            {"fps", func_res_1.fps},
            {"moveTime", func_res_1.moveTime},
            {"renderTime", func_res_1.renderTime},
            {"gpuTime", func_res_1.gpuTime}
        };
    }
 
    json GetFactionDetails(PARAMS(const char* factionid))
    {
        const auto func_res_1 = invoke(GetFactionDetails, factionid);
        return json
        {
            {"factionID", func_res_1.factionID},
            {"factionName", func_res_1.factionName},
            {"factionIcon", func_res_1.factionIcon}
        };
    }
 
    json GetOwnerDetails(PARAMS(UniverseID componentid))
    {
        const auto func_res_1 = invoke(GetOwnerDetails, componentid);
        return json
        {
            {"factionID", func_res_1.factionID},
            {"factionName", func_res_1.factionName},
            {"factionIcon", func_res_1.factionIcon}
        };
    }
 
    json GetGameVersion(PARAMS())
    {
        const auto func_res_1 = invoke(GetGameVersion);
        return json
        {
            {"major", func_res_1.major},
            {"minor", func_res_1.minor}
        };
    }
 
    json GetMissionOfferIcons(PARAMS(const UniverseID componentid))
    {
        const auto func_res_1 = invoke(GetMissionOfferIcons, componentid);
        return json
        {
            {"active", func_res_1.active},
            {"inactive", func_res_1.inactive},
            {"select", func_res_1.select}
        };
    }
 
    json GetLastAttackInfo(PARAMS(UniverseID destructibleid))
    {
        const auto func_res_1 = invoke(GetLastAttackInfo, destructibleid);
        return json
        {
            {"attacker", func_res_1.attacker},
            {"time", func_res_1.time},
            {"method", func_res_1.method}
        };
    }
 
    json GetMessageDetails2(PARAMS(uint32_t messageid))
    {
        const auto func_res_1 = invoke(GetMessageDetails2, messageid);
        return json
        {
            {"poiID", func_res_1.poiID},
            {"componentID", func_res_1.componentID},
            {"messageType", func_res_1.messageType},
            {"connectionName", func_res_1.connectionName},
            {"isAssociative", func_res_1.isAssociative},
            {"isMissionTarget", func_res_1.isMissionTarget},
            {"isPriorityMissionTarget", func_res_1.isPriorityMissionTarget},
            {"showIndicator", func_res_1.showIndicator}
        };
    }
 
    json GetMissionBriefingIcon(PARAMS(MissionID missionid))
    {
        const auto func_res_1 = invoke(GetMissionBriefingIcon, missionid);
        return json
        {
            {"icon", func_res_1.icon},
            {"caption", func_res_1.caption}
        };
    }
 
    json GetMissionIDDetails(PARAMS(uint64_t missionid))
    {
        const auto func_res_1 = invoke(GetMissionIDDetails, missionid);
        return json
        {
            {"missionName", func_res_1.missionName},
            {"missionDescription", func_res_1.missionDescription},
            {"difficulty", func_res_1.difficulty},
            {"upkeepalertlevel", func_res_1.upkeepalertlevel},
            {"threadType", func_res_1.threadType},
            {"mainType", func_res_1.mainType},
            {"subType", func_res_1.subType},
            {"subTypeName", func_res_1.subTypeName},
            {"faction", func_res_1.faction},
            {"reward", func_res_1.reward},
            {"rewardText", func_res_1.rewardText},
            {"numBriefingObjectives", func_res_1.numBriefingObjectives},
            {"activeBriefingStep", func_res_1.activeBriefingStep},
            {"opposingFaction", func_res_1.opposingFaction},
            {"license", func_res_1.license},
            {"timeLeft", func_res_1.timeLeft},
            {"duration", func_res_1.duration},
            {"abortable", func_res_1.abortable},
            {"hasObjective", func_res_1.hasObjective},
            {"associatedComponent", func_res_1.associatedComponent},
            {"threadMissionID", func_res_1.threadMissionID}
        };
    }
 
    json GetMissionGroupDetails(PARAMS(MissionID missionid))
    {
        const auto func_res_1 = invoke(GetMissionGroupDetails, missionid);
        return json
        {
            {"id", func_res_1.id},
            {"name", func_res_1.name}
        };
    }
 
    json GetPickedMapMission(PARAMS(UniverseID holomapid))
    {
        const auto func_res_1 = invoke(GetPickedMapMission, holomapid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetMissionInfo2(PARAMS())
    {
        const auto func_res_1 = invoke(GetMissionInfo2);
        return json
        {
            {"active", func_res_1.active},
            {"callbackMode", func_res_1.callbackMode},
            {"barLine", func_res_1.barLine},
            {"barPercent", func_res_1.barPercent},
            {"line1Left", func_res_1.line1Left},
            {"line1Right", func_res_1.line1Right},
            {"line2Left", func_res_1.line2Left},
            {"line2Right", func_res_1.line2Right},
            {"line3Left", func_res_1.line3Left},
            {"line3Right", func_res_1.line3Right},
            {"line4Left", func_res_1.line4Left},
            {"line4Right", func_res_1.line4Right},
            {"missionBarText", func_res_1.missionBarText}
        };
    }
 
    json GetMissionIDObjective(PARAMS(uint64_t missionid))
    {
        const auto func_res_1 = invoke(GetMissionIDObjective, missionid);
        return json
        {
            {"objectiveText", func_res_1.objectiveText},
            {"timeout", func_res_1.timeout},
            {"numTargets", func_res_1.numTargets}
        };
    }
 
    json GetMissionObjectiveStep2(PARAMS(uint64_t missionid,size_t objectiveIndex))
    {
        const auto func_res_1 = invoke(GetMissionObjectiveStep2, missionid, objectiveIndex);
        return json
        {
            {"text", func_res_1.text},
            {"step", func_res_1.step},
            {"failed", func_res_1.failed}
        };
    }
 
    json GetPOIDetails(PARAMS(const uint64_t poiid))
    {
        const auto func_res_1 = invoke(GetPOIDetails, poiid);
        return json
        {
            {"POIName", func_res_1.POIName},
            {"POIType", func_res_1.POIType}
        };
    }
 
    json GetRelativeAimOffset(PARAMS(const UniverseID componentid))
    {
        const auto func_res_1 = invoke(GetRelativeAimOffset, componentid);
        return json
        {
            {"x", func_res_1.x},
            {"y", func_res_1.y},
            {"z", func_res_1.z},
            {"yaw", func_res_1.yaw},
            {"pitch", func_res_1.pitch},
            {"roll", func_res_1.roll}
        };
    }
 
    json GetTargetElementOffset(PARAMS(const int posid))
    {
        const auto func_res_1 = invoke(GetTargetElementOffset, posid);
        return json
        {
            {"x", func_res_1.x},
            {"y", func_res_1.y},
            {"z", func_res_1.z},
            {"yaw", func_res_1.yaw},
            {"pitch", func_res_1.pitch},
            {"roll", func_res_1.roll}
        };
    }
 
    json GetRelativeAimScreenPosition(PARAMS(const UniverseID componentid,const uint32_t iconsizeonscreen,const uint32_t iconsizeoffscreen))
    {
        const auto func_res_1 = invoke(GetRelativeAimScreenPosition, componentid, iconsizeonscreen, iconsizeoffscreen);
        return json
        {
            {"x", func_res_1.x},
            {"y", func_res_1.y}
        };
    }
 
    json GetFactionRelationStatus(PARAMS(const char* factionid))
    {
        const auto func_res_1 = invoke(GetFactionRelationStatus, factionid);
        return json
        {
            {"relationStatus", func_res_1.relationStatus},
            {"relationValue", func_res_1.relationValue},
            {"relationLEDValue", func_res_1.relationLEDValue},
            {"isBoostedValue", func_res_1.isBoostedValue}
        };
    }
 
    json GetRelationStatus2(PARAMS(const UniverseID componentid,const char*const connectionname))
    {
        const auto func_res_1 = invoke(GetRelationStatus2, componentid, connectionname);
        return json
        {
            {"relationStatus", func_res_1.relationStatus},
            {"relationValue", func_res_1.relationValue},
            {"relationLEDValue", func_res_1.relationLEDValue},
            {"isBoostedValue", func_res_1.isBoostedValue}
        };
    }
 
    json GetGameResolution(PARAMS())
    {
        const auto func_res_1 = invoke(GetGameResolution);
        return json
        {
            {"x", func_res_1.x},
            {"y", func_res_1.y}
        };
    }
 
    json GetRenderResolutionOption(PARAMS())
    {
        const auto func_res_1 = invoke(GetRenderResolutionOption);
        return json
        {
            {"x", func_res_1.x},
            {"y", func_res_1.y}
        };
    }
 
    json GetCameraRotation(PARAMS())
    {
        const auto func_res_1 = invoke(GetCameraRotation);
        return json
        {
            {"yaw", func_res_1.yaw},
            {"pitch", func_res_1.pitch},
            {"roll", func_res_1.roll}
        };
    }
 
    json GetComponentScreenPosition(PARAMS(const UniverseID componentid,const uint32_t iconsizeonscreen,const uint32_t iconsizeoffscreen))
    {
        const auto func_res_1 = invoke(GetComponentScreenPosition, componentid, iconsizeonscreen, iconsizeoffscreen);
        return json
        {
            {"x", func_res_1.x},
            {"y", func_res_1.y},
            {"onScreen", func_res_1.onScreen}
        };
    }
 
    json GetSofttarget(PARAMS())
    {
        const auto func_res_1 = invoke(GetSofttarget);
        return json
        {
            {"softtargetID", func_res_1.softtargetID},
            {"softtargetConnectionName", func_res_1.softtargetConnectionName}
        };
    }
 
    json GetSpecialNPCs(PARAMS(const UniverseID componentid))
    {
        const auto func_res_1 = invoke(GetSpecialNPCs, componentid);
        return json
        {
            {"factionNPC", func_res_1.factionNPC},
            {"missionActor", func_res_1.missionActor},
            {"shadyGuy", func_res_1.shadyGuy}
        };
    }
 
    json GetTableInitialSelectionInfo(PARAMS(const int tableid))
    {
        const auto func_res_1 = invoke(GetTableInitialSelectionInfo, tableid);
        return json
        {
            {"toprow", func_res_1.toprow},
            {"selectedrow", func_res_1.selectedrow},
            {"selectedcol", func_res_1.selectedcol},
            {"shiftstart", func_res_1.shiftstart},
            {"shiftend", func_res_1.shiftend}
        };
    }
 
    json GetPickedMapTradeOffer(PARAMS(UniverseID holomapid))
    {
        const auto func_res_1 = invoke(GetPickedMapTradeOffer, holomapid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetTurret(PARAMS(size_t turretnum))
    {
        const auto func_res_1 = invoke(GetTurret, turretnum);
        return json
        {
            {"icon", func_res_1.icon},
            {"mode", func_res_1.mode},
            {"damageState", func_res_1.damageState},
            {"active", func_res_1.active},
            {"usesAmmo", func_res_1.usesAmmo},
            {"ammo", func_res_1.ammo}
        };
    }
 
    json SetFormationShape(PARAMS(UniverseID objectid,const char* formationshape))
    {
        const auto func_res_1 = invoke(SetFormationShape, objectid, formationshape);
        return json
        {
            {"shape", func_res_1.shape},
            {"name", func_res_1.name},
            {"requiredSkill", func_res_1.requiredSkill},
            {"radius", func_res_1.radius},
            {"rollMembers", func_res_1.rollMembers},
            {"rollFormation", func_res_1.rollFormation},
            {"maxShipsPerLine", func_res_1.maxShipsPerLine}
        };
    }
 
    json GetFrameBackground2Info(PARAMS(const int frameid))
    {
        const auto func_res_1 = invoke(GetFrameBackground2Info, frameid);
        return json
        {
            {"iconid", func_res_1.iconid},
            {"color", {"red", func_res_1.color.red},{"green", func_res_1.color.green},{"blue", func_res_1.color.blue},{"alpha", func_res_1.color.alpha}},
            {"width", func_res_1.width},
            {"height", func_res_1.height},
            {"rotationrate", func_res_1.rotationrate},
            {"rotstart", func_res_1.rotstart},
            {"rotduration", func_res_1.rotduration},
            {"rotinterval", func_res_1.rotinterval},
            {"initscale", func_res_1.initscale},
            {"scaleduration", func_res_1.scaleduration}
        };
    }
 
    json GetFrameBackgroundInfo(PARAMS(const int frameid))
    {
        const auto func_res_1 = invoke(GetFrameBackgroundInfo, frameid);
        return json
        {
            {"iconid", func_res_1.iconid},
            {"color", {"red", func_res_1.color.red},{"green", func_res_1.color.green},{"blue", func_res_1.color.blue},{"alpha", func_res_1.color.alpha}},
            {"width", func_res_1.width},
            {"height", func_res_1.height},
            {"rotationrate", func_res_1.rotationrate},
            {"rotstart", func_res_1.rotstart},
            {"rotduration", func_res_1.rotduration},
            {"rotinterval", func_res_1.rotinterval},
            {"initscale", func_res_1.initscale},
            {"scaleduration", func_res_1.scaleduration}
        };
    }
 
    json GetFrameOverlayInfo(PARAMS(const int frameid))
    {
        const auto func_res_1 = invoke(GetFrameOverlayInfo, frameid);
        return json
        {
            {"iconid", func_res_1.iconid},
            {"color", {"red", func_res_1.color.red},{"green", func_res_1.color.green},{"blue", func_res_1.color.blue},{"alpha", func_res_1.color.alpha}},
            {"width", func_res_1.width},
            {"height", func_res_1.height},
            {"rotationrate", func_res_1.rotationrate},
            {"rotstart", func_res_1.rotstart},
            {"rotduration", func_res_1.rotduration},
            {"rotinterval", func_res_1.rotinterval},
            {"initscale", func_res_1.initscale},
            {"scaleduration", func_res_1.scaleduration}
        };
    }
 
    json GetCurrentLoadoutStatistics2(PARAMS(UniverseID shipid))
    {
        const auto func_res_1 = invoke(GetCurrentLoadoutStatistics2, shipid);
        return json
        {
            {"HullValue", func_res_1.HullValue},
            {"ShieldValue", func_res_1.ShieldValue},
            {"GroupedShieldValue", func_res_1.GroupedShieldValue},
            {"BurstDPS", func_res_1.BurstDPS},
            {"SustainedDPS", func_res_1.SustainedDPS},
            {"TurretBurstDPS", func_res_1.TurretBurstDPS},
            {"TurretSustainedDPS", func_res_1.TurretSustainedDPS},
            {"GroupedTurretBurstDPS", func_res_1.GroupedTurretBurstDPS},
            {"GroupedTurretSustainedDPS", func_res_1.GroupedTurretSustainedDPS},
            {"ForwardSpeed", func_res_1.ForwardSpeed},
            {"BoostSpeed", func_res_1.BoostSpeed},
            {"TravelSpeed", func_res_1.TravelSpeed},
            {"YawSpeed", func_res_1.YawSpeed},
            {"PitchSpeed", func_res_1.PitchSpeed},
            {"RollSpeed", func_res_1.RollSpeed},
            {"ForwardAcceleration", func_res_1.ForwardAcceleration},
            {"NumDocksShipMedium", func_res_1.NumDocksShipMedium},
            {"NumDocksShipSmall", func_res_1.NumDocksShipSmall},
            {"ShipCapacityMedium", func_res_1.ShipCapacityMedium},
            {"ShipCapacitySmall", func_res_1.ShipCapacitySmall},
            {"CrewCapacity", func_res_1.CrewCapacity},
            {"ContainerCapacity", func_res_1.ContainerCapacity},
            {"SolidCapacity", func_res_1.SolidCapacity},
            {"LiquidCapacity", func_res_1.LiquidCapacity},
            {"UnitCapacity", func_res_1.UnitCapacity},
            {"MissileCapacity", func_res_1.MissileCapacity},
            {"CountermeasureCapacity", func_res_1.CountermeasureCapacity},
            {"DeployableCapacity", func_res_1.DeployableCapacity},
            {"RadarRange", func_res_1.RadarRange}
        };
    }
 
    json GetMaxLoadoutStatistics2(PARAMS(UniverseID shipid,const char* macroname))
    {
        const auto func_res_1 = invoke(GetMaxLoadoutStatistics2, shipid, macroname);
        return json
        {
            {"HullValue", func_res_1.HullValue},
            {"ShieldValue", func_res_1.ShieldValue},
            {"GroupedShieldValue", func_res_1.GroupedShieldValue},
            {"BurstDPS", func_res_1.BurstDPS},
            {"SustainedDPS", func_res_1.SustainedDPS},
            {"TurretBurstDPS", func_res_1.TurretBurstDPS},
            {"TurretSustainedDPS", func_res_1.TurretSustainedDPS},
            {"GroupedTurretBurstDPS", func_res_1.GroupedTurretBurstDPS},
            {"GroupedTurretSustainedDPS", func_res_1.GroupedTurretSustainedDPS},
            {"ForwardSpeed", func_res_1.ForwardSpeed},
            {"BoostSpeed", func_res_1.BoostSpeed},
            {"TravelSpeed", func_res_1.TravelSpeed},
            {"YawSpeed", func_res_1.YawSpeed},
            {"PitchSpeed", func_res_1.PitchSpeed},
            {"RollSpeed", func_res_1.RollSpeed},
            {"ForwardAcceleration", func_res_1.ForwardAcceleration},
            {"NumDocksShipMedium", func_res_1.NumDocksShipMedium},
            {"NumDocksShipSmall", func_res_1.NumDocksShipSmall},
            {"ShipCapacityMedium", func_res_1.ShipCapacityMedium},
            {"ShipCapacitySmall", func_res_1.ShipCapacitySmall},
            {"CrewCapacity", func_res_1.CrewCapacity},
            {"ContainerCapacity", func_res_1.ContainerCapacity},
            {"SolidCapacity", func_res_1.SolidCapacity},
            {"LiquidCapacity", func_res_1.LiquidCapacity},
            {"UnitCapacity", func_res_1.UnitCapacity},
            {"MissileCapacity", func_res_1.MissileCapacity},
            {"CountermeasureCapacity", func_res_1.CountermeasureCapacity},
            {"DeployableCapacity", func_res_1.DeployableCapacity},
            {"RadarRange", func_res_1.RadarRange}
        };
    }
 
    json GetCurrentPlayerLogo(PARAMS())
    {
        const auto func_res_1 = invoke(GetCurrentPlayerLogo);
        return json
        {
            {"file", func_res_1.file},
            {"icon", func_res_1.icon},
            {"ispersonal", func_res_1.ispersonal}
        };
    }
 
    json GetMapTradeVolumeParameter(PARAMS())
    {
        const auto func_res_1 = invoke(GetMapTradeVolumeParameter);
        return json
        {
            {"icon", func_res_1.icon},
            {"color", {"red", func_res_1.color.red},{"green", func_res_1.color.green},{"blue", func_res_1.color.blue},{"alpha", func_res_1.color.alpha}},
            {"volume_s", func_res_1.volume_s},
            {"volume_m", func_res_1.volume_m},
            {"volume_l", func_res_1.volume_l}
        };
    }
 
    json GetHelpOverlayInfo(PARAMS(const int widgetid))
    {
        const auto func_res_1 = invoke(GetHelpOverlayInfo, widgetid);
        return json
        {
            {"id", func_res_1.id},
            {"text", func_res_1.text},
            {"x", func_res_1.x},
            {"y", func_res_1.y},
            {"width", func_res_1.width},
            {"height", func_res_1.height},
            {"highlightonly", func_res_1.highlightonly}
        };
    }
 
    json GetStandardButtonHelpOverlayInfo(PARAMS(const int frameid,const char* button))
    {
        const auto func_res_1 = invoke(GetStandardButtonHelpOverlayInfo, frameid, button);
        return json
        {
            {"id", func_res_1.id},
            {"text", func_res_1.text},
            {"x", func_res_1.x},
            {"y", func_res_1.y},
            {"width", func_res_1.width},
            {"height", func_res_1.height},
            {"highlightonly", func_res_1.highlightonly}
        };
    }
 
    json GetCustomGameStartPosRotProperty(PARAMS(const char* id,const char* propertyid))
    {
        CustomGameStartPosRotPropertyState state;
        const auto func_res_1 = invoke(GetCustomGameStartPosRotProperty, id, propertyid, &state);
          {
            return json
            {
                {"x", func_res_1.x},
                {"y", func_res_1.y},
                {"z", func_res_1.z},
                {"yaw", func_res_1.yaw},
                {"pitch", func_res_1.pitch},
                {"roll", func_res_1.roll},
                {"state", {
                    {"state", state.state},
                    {"defaultvalue", {"x", state.defaultvalue.x},{"y", state.defaultvalue.y},{"z", state.defaultvalue.z},{"yaw", state.defaultvalue.yaw},{"pitch", state.defaultvalue.pitch},{"roll", state.defaultvalue.roll}}
                }}
            };
        }
 
    }
 
    json GetObjectPositionInSector(PARAMS(UniverseID objectid))
    {
        const auto func_res_1 = invoke(GetObjectPositionInSector, objectid);
        return json
        {
            {"x", func_res_1.x},
            {"y", func_res_1.y},
            {"z", func_res_1.z},
            {"yaw", func_res_1.yaw},
            {"pitch", func_res_1.pitch},
            {"roll", func_res_1.roll}
        };
    }
 
    json GetPlayerTargetOffset(PARAMS())
    {
        const auto func_res_1 = invoke(GetPlayerTargetOffset);
        return json
        {
            {"x", func_res_1.x},
            {"y", func_res_1.y},
            {"z", func_res_1.z},
            {"yaw", func_res_1.yaw},
            {"pitch", func_res_1.pitch},
            {"roll", func_res_1.roll}
        };
    }
 
    json GetLastSaveInfo(PARAMS())
    {
        const auto func_res_1 = invoke(GetLastSaveInfo);
        return json
        {
            {"filename", func_res_1.filename},
            {"name", func_res_1.name},
            {"description", func_res_1.description},
            {"version", func_res_1.version},
            {"rawversion", func_res_1.rawversion},
            {"time", func_res_1.time},
            {"rawtime", func_res_1.rawtime},
            {"playtime", func_res_1.playtime},
            {"playername", func_res_1.playername},
            {"location", func_res_1.location},
            {"money", func_res_1.money},
            {"error", func_res_1.error},
            {"invalidgameid", func_res_1.invalidgameid},
            {"invalidversion", func_res_1.invalidversion},
            {"numinvalidpatches", func_res_1.numinvalidpatches}
        };
    }
 
    json GetNumUISystemInfo(PARAMS(UniverseID clusterid))
    {
        const auto func_res_1 = invoke(GetNumUISystemInfo, clusterid);
        return json
        {
            {"numsuns", func_res_1.numsuns},
            {"numplanets", func_res_1.numplanets}
        };
    }
 
    json GetCurrentVentureMissionInfo(PARAMS(UniverseID ventureplatformid))
    {
        const auto func_res_1 = invoke(GetCurrentVentureMissionInfo, ventureplatformid);
        return json
        {
            {"name", func_res_1.name},
            {"icon", func_res_1.icon},
            {"rewardicon", func_res_1.rewardicon},
            {"remainingtime", func_res_1.remainingtime},
            {"numships", func_res_1.numships}
        };
    }
 
    json AddHoloMap(PARAMS(const char* texturename,float x0,float x1,float y0,float y1,float aspectx,float aspecty))
    {
        const auto func_res_1 = invoke(AddHoloMap, texturename, x0, x1, y0, y1, aspectx, aspecty);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json CreateNPCFromPerson(PARAMS(NPCSeed person,UniverseID controllableid))
    {
        const auto func_res_1 = invoke(CreateNPCFromPerson, person, controllableid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetCommonContext(PARAMS(UniverseID componentid,UniverseID othercomponentid,bool includeself,bool includeother,UniverseID limitid,bool includelimit))
    {
        const auto func_res_1 = invoke(GetCommonContext, componentid, othercomponentid, includeself, includeother, limitid, includelimit);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetContextByClass(PARAMS(UniverseID componentid,const char* classname,bool includeself))
    {
        const auto func_res_1 = invoke(GetContextByClass, componentid, classname, includeself);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetContextForTransporterCheck(PARAMS(UniverseID positionalid))
    {
        const auto func_res_1 = invoke(GetContextForTransporterCheck, positionalid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetEnvironmentObject(PARAMS())
    {
        const auto func_res_1 = invoke(GetEnvironmentObject);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetExternalTargetViewComponent(PARAMS())
    {
        const auto func_res_1 = invoke(GetExternalTargetViewComponent);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetFactionRepresentative(PARAMS(const char* factionid))
    {
        const auto func_res_1 = invoke(GetFactionRepresentative, factionid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetInstantiatedPerson(PARAMS(NPCSeed person,UniverseID controllableid))
    {
        const auto func_res_1 = invoke(GetInstantiatedPerson, person, controllableid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetLastPlayerControlledShipID(PARAMS())
    {
        const auto func_res_1 = invoke(GetLastPlayerControlledShipID);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetMissionIDObjectiveTarget(PARAMS(uint64_t missionid,size_t targetIndex))
    {
        const auto func_res_1 = invoke(GetMissionIDObjectiveTarget, missionid, targetIndex);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetParentComponent(PARAMS(UniverseID componentid))
    {
        const auto func_res_1 = invoke(GetParentComponent, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPickedMapComponent(PARAMS(UniverseID holomapid))
    {
        const auto func_res_1 = invoke(GetPickedMapComponent, holomapid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPickedMapMissionOffer(PARAMS(UniverseID holomapid))
    {
        const auto func_res_1 = invoke(GetPickedMapMissionOffer, holomapid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPickedMapOrder(PARAMS(UniverseID holomapid))
    {
        Order result;
        bool intermediate;
        const auto func_res_1 = invoke(GetPickedMapOrder, holomapid, &result, &intermediate);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"result", {
                    {"queueidx", result.queueidx},
                    {"state", result.state},
                    {"statename", result.statename},
                    {"orderdef", result.orderdef},
                    {"actualparams", result.actualparams},
                    {"enabled", result.enabled},
                    {"isinfinite", result.isinfinite},
                    {"issyncpointreached", result.issyncpointreached},
                    {"istemporder", result.istemporder}
                }},
                {"intermediate", intermediate}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPlayerComputerID(PARAMS())
    {
        const auto func_res_1 = invoke(GetPlayerComputerID);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPlayerContainerID(PARAMS())
    {
        const auto func_res_1 = invoke(GetPlayerContainerID);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPlayerControlledShipID(PARAMS())
    {
        const auto func_res_1 = invoke(GetPlayerControlledShipID);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPlayerID(PARAMS())
    {
        const auto func_res_1 = invoke(GetPlayerID);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPlayerObjectID(PARAMS())
    {
        const auto func_res_1 = invoke(GetPlayerObjectID);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPlayerOccupiedShipID(PARAMS())
    {
        const auto func_res_1 = invoke(GetPlayerOccupiedShipID);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPlayerShipID(PARAMS())
    {
        const auto func_res_1 = invoke(GetPlayerShipID);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPlayerZoneID(PARAMS())
    {
        const auto func_res_1 = invoke(GetPlayerZoneID);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetSectorControlStation(PARAMS(UniverseID sectorid))
    {
        const auto func_res_1 = invoke(GetSectorControlStation, sectorid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetTopLevelContainer(PARAMS(UniverseID componentid))
    {
        const auto func_res_1 = invoke(GetTopLevelContainer, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetUpgradeSlotCurrentComponent(PARAMS(UniverseID destructibleid,const char* upgradetypename,size_t slot))
    {
        const auto func_res_1 = invoke(GetUpgradeSlotCurrentComponent, destructibleid, upgradetypename, slot);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetZoneAt(PARAMS(UniverseID sectorid))
    {
        UIPosRot uioffset;
        const auto func_res_1 = invoke(GetZoneAt, sectorid, &uioffset);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"uioffset", {
                    {"x", uioffset.x},
                    {"y", uioffset.y},
                    {"z", uioffset.z},
                    {"yaw", uioffset.yaw},
                    {"pitch", uioffset.pitch},
                    {"roll", uioffset.roll}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetUpgradeSlotGroup(PARAMS(UniverseID destructibleid,const char* macroname,const char* upgradetypename,size_t slot))
    {
        const auto func_res_1 = invoke(GetUpgradeSlotGroup, destructibleid, macroname, upgradetypename, slot);
        return json
        {
            {"path", func_res_1.path},
            {"group", func_res_1.group}
        };
    }
 
    json GetUpgradeGroupInfo(PARAMS(UniverseID destructibleid,const char* macroname,const char* path,const char* group,const char* upgradetypename))
    {
        const auto func_res_1 = invoke(GetUpgradeGroupInfo, destructibleid, macroname, path, group, upgradetypename);
        return json
        {
            {"currentcomponent", func_res_1.currentcomponent},
            {"currentmacro", func_res_1.currentmacro},
            {"slotsize", func_res_1.slotsize},
            {"count", func_res_1.count},
            {"operational", func_res_1.operational},
            {"total", func_res_1.total}
        };
    }
 
    json GetUpgradeGroupInfo2(PARAMS(UniverseID destructibleid,const char* macroname,UniverseID contextid,const char* path,const char* group,const char* upgradetypename))
    {
        const auto func_res_1 = invoke(GetUpgradeGroupInfo2, destructibleid, macroname, contextid, path, group, upgradetypename);
        return json
        {
            {"currentcomponent", func_res_1.currentcomponent},
            {"currentmacro", func_res_1.currentmacro},
            {"slotsize", func_res_1.slotsize},
            {"count", func_res_1.count},
            {"operational", func_res_1.operational},
            {"total", func_res_1.total}
        };
    }
 
    json GetPrimaryWeapon(PARAMS(size_t weaponnum))
    {
        const auto func_res_1 = invoke(GetPrimaryWeapon, weaponnum);
        return json
        {
            {"icon", func_res_1.icon},
            {"damageState", func_res_1.damageState},
            {"active", func_res_1.active},
            {"usesAmmo", func_res_1.usesAmmo},
            {"ammo", func_res_1.ammo},
            {"mode", func_res_1.mode},
            {"reloadPercent", func_res_1.reloadPercent},
            {"heatState", func_res_1.heatState},
            {"heatPercent", func_res_1.heatPercent},
            {"lockPercent", func_res_1.lockPercent},
            {"counterMeasureTarget", func_res_1.counterMeasureTarget}
        };
    }
 
    json GetSecondaryWeapon(PARAMS(size_t weaponnum))
    {
        const auto func_res_1 = invoke(GetSecondaryWeapon, weaponnum);
        return json
        {
            {"icon", func_res_1.icon},
            {"damageState", func_res_1.damageState},
            {"active", func_res_1.active},
            {"usesAmmo", func_res_1.usesAmmo},
            {"ammo", func_res_1.ammo},
            {"mode", func_res_1.mode},
            {"reloadPercent", func_res_1.reloadPercent},
            {"heatState", func_res_1.heatState},
            {"heatPercent", func_res_1.heatPercent},
            {"lockPercent", func_res_1.lockPercent},
            {"counterMeasureTarget", func_res_1.counterMeasureTarget}
        };
    }
 
    json GetWorkForceInfo(PARAMS(UniverseID containerid,const char* raceid))
    {
        const auto func_res_1 = invoke(GetWorkForceInfo, containerid, raceid);
        return json
        {
            {"current", func_res_1.current},
            {"capacity", func_res_1.capacity},
            {"optimal", func_res_1.optimal},
            {"available", func_res_1.available},
            {"maxavailable", func_res_1.maxavailable},
            {"timeuntilnextupdate", func_res_1.timeuntilnextupdate}
        };
    }
 
    json AddAttackerToBoardingOperation(PARAMS(UniverseID defensibletargetid,UniverseID defensibleboarderid,const char* boarderfactionid,const char* actionid,uint32_t nummarinetiers))
    {
        uint32_t marinetieramounts;
        int32_t marinetierskilllevels;
        const auto func_res_1 = invoke(AddAttackerToBoardingOperation, defensibletargetid, defensibleboarderid, boarderfactionid, actionid, &marinetieramounts, &marinetierskilllevels, nummarinetiers);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"marinetieramounts", marinetieramounts},
                {"marinetierskilllevels", marinetierskilllevels}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json AdjustOrder(PARAMS(UniverseID controllableid,size_t idx,size_t newidx,bool enabled,bool forcestates,bool checkonly))
    {
        const auto func_res_1 = invoke(AdjustOrder, controllableid, idx, newidx, enabled, forcestates, checkonly);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json AreGfxSettingsTooHigh(PARAMS())
    {
        const auto func_res_1 = invoke(AreGfxSettingsTooHigh);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json AreMandatoryAssertsEnabled(PARAMS())
    {
        const auto func_res_1 = invoke(AreMandatoryAssertsEnabled);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json AreOptionalAssertEnabled(PARAMS())
    {
        const auto func_res_1 = invoke(AreOptionalAssertEnabled);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json CanAcceptSubordinate(PARAMS(UniverseID commanderid,UniverseID potentialsubordinateid))
    {
        const auto func_res_1 = invoke(CanAcceptSubordinate, commanderid, potentialsubordinateid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json CanApplyKnownLoadout(PARAMS(const char* macroname,const char* loadoutid))
    {
        const auto func_res_1 = invoke(CanApplyKnownLoadout, macroname, loadoutid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json CanBuildLoadout(PARAMS(UniverseID containerid,UniverseID defensibleid,const char* macroname,const char* loadoutid))
    {
        const auto func_res_1 = invoke(CanBuildLoadout, containerid, defensibleid, macroname, loadoutid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json CanCancelConstruction(PARAMS(UniverseID containerid,BuildTaskID id))
    {
        const auto func_res_1 = invoke(CanCancelConstruction, containerid, id);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json CanContainerEquipShip(PARAMS(UniverseID containerid,UniverseID shipid))
    {
        const auto func_res_1 = invoke(CanContainerEquipShip, containerid, shipid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json CanContainerMineTransport(PARAMS(UniverseID containerid,const char* transportname))
    {
        const auto func_res_1 = invoke(CanContainerMineTransport, containerid, transportname);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json CanContainerSupplyShip(PARAMS(UniverseID containerid,UniverseID shipid))
    {
        const auto func_res_1 = invoke(CanContainerSupplyShip, containerid, shipid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json CanContainerTransport(PARAMS(UniverseID containerid,const char* transportname))
    {
        const auto func_res_1 = invoke(CanContainerTransport, containerid, transportname);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json CanControllableHaveControlEntity(PARAMS(UniverseID controllableid,const char* postid))
    {
        const auto func_res_1 = invoke(CanControllableHaveControlEntity, controllableid, postid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json CanGenerateValidKnownLoadout(PARAMS(const char* macroname))
    {
        const auto func_res_1 = invoke(CanGenerateValidKnownLoadout, macroname);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json CanGenerateValidLoadout(PARAMS(UniverseID containerid,const char* macroname))
    {
        const auto func_res_1 = invoke(CanGenerateValidLoadout, containerid, macroname);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json CanHaveCountermeasures(PARAMS())
    {
        const auto func_res_1 = invoke(CanHaveCountermeasures);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json CanOpenWebBrowser(PARAMS())
    {
        const auto func_res_1 = invoke(CanOpenWebBrowser);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json CanPlayerCommTarget(PARAMS(UniverseID componentid))
    {
        const auto func_res_1 = invoke(CanPlayerCommTarget, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json CanPlayerStandUp(PARAMS())
    {
        const auto func_res_1 = invoke(CanPlayerStandUp);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json CanRedoConstructionMapChange(PARAMS(UniverseID holomapid))
    {
        const auto func_res_1 = invoke(CanRedoConstructionMapChange, holomapid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json CanStartTravelMode(PARAMS(UniverseID objectid))
    {
        const auto func_res_1 = invoke(CanStartTravelMode, objectid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json CanUndoConstructionMapChange(PARAMS(UniverseID holomapid))
    {
        const auto func_res_1 = invoke(CanUndoConstructionMapChange, holomapid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json CancelConstruction(PARAMS(UniverseID containerid,BuildTaskID id))
    {
        const auto func_res_1 = invoke(CancelConstruction, containerid, id);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json CheckWeaponModCompatibility(PARAMS(UniverseID weaponid,const char* wareid))
    {
        const auto func_res_1 = invoke(CheckWeaponModCompatibility, weaponid, wareid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json CompareMapConstructionSequenceWithPlanned(PARAMS(UniverseID holomapid,UniverseID defensibleid,bool usestoredplan))
    {
        const auto func_res_1 = invoke(CompareMapConstructionSequenceWithPlanned, holomapid, defensibleid, usestoredplan);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json CopyToClipboard(PARAMS(const char*const text))
    {
        const auto func_res_1 = invoke(CopyToClipboard, text);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json CreateBoardingOperation(PARAMS(UniverseID defensibletargetid,const char* boarderfactionid,uint32_t approachthreshold,uint32_t insertionthreshold))
    {
        const auto func_res_1 = invoke(CreateBoardingOperation, defensibletargetid, boarderfactionid, approachthreshold, insertionthreshold);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json DeleteSavegame(PARAMS(const char* filename))
    {
        const auto func_res_1 = invoke(DeleteSavegame, filename);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json DoesMapConstructionSequenceRequireBuilder(PARAMS(UniverseID holomapid,UniverseID defensibleid,bool usestoredplan))
    {
        const auto func_res_1 = invoke(DoesMapConstructionSequenceRequireBuilder, holomapid, defensibleid, usestoredplan);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json DropCargo(PARAMS(UniverseID containerid,const char* wareid,uint32_t amount))
    {
        const auto func_res_1 = invoke(DropCargo, containerid, wareid, amount);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json DropInventory(PARAMS(UniverseID entityid,const char* lockboxid,uint32_t numwares))
    {
        UIWareAmount wares;
        const auto func_res_1 = invoke(DropInventory, entityid, lockboxid, &wares, numwares);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"wares", {
                    {"wareid", wares.wareid},
                    {"amount", wares.amount}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json EnableOrder(PARAMS(UniverseID controllableid,size_t idx))
    {
        const auto func_res_1 = invoke(EnableOrder, controllableid, idx);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json EnablePlannedDefaultOrder(PARAMS(UniverseID controllableid,bool checkonly))
    {
        const auto func_res_1 = invoke(EnablePlannedDefaultOrder, controllableid, checkonly);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAskToSignalForControllable(PARAMS(const char* signalid,UniverseID controllableid))
    {
        const auto func_res_1 = invoke(GetAskToSignalForControllable, signalid, controllableid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAskToSignalForFaction(PARAMS(const char* signalid,const char* factionid))
    {
        const auto func_res_1 = invoke(GetAskToSignalForFaction, signalid, factionid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetBoardingMarineTierAmountsFromAttacker(PARAMS(uint32_t inputnummarinetiers,UniverseID defensibletargetid,UniverseID defensibleboarderid,const char* boarderfactionid))
    {
        uint32_t resultmarinetieramounts;
        int32_t inputmarinetierskilllevels;
        const auto func_res_1 = invoke(GetBoardingMarineTierAmountsFromAttacker, &resultmarinetieramounts, &inputmarinetierskilllevels, inputnummarinetiers, defensibletargetid, defensibleboarderid, boarderfactionid);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"resultmarinetieramounts", resultmarinetieramounts},
                {"inputmarinetierskilllevels", inputmarinetierskilllevels}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetBoxTextBoxColor(PARAMS(const int boxtextid))
    {
        Color color;
        const auto func_res_1 = invoke(GetBoxTextBoxColor, boxtextid, &color);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"color", {
                    {"red", color.red},
                    {"green", color.green},
                    {"blue", color.blue},
                    {"alpha", color.alpha}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetBoxTextInfo(PARAMS(const int boxtextid))
    {
        TextInfo textinfo;
        const auto func_res_1 = invoke(GetBoxTextInfo, boxtextid, &textinfo);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"textinfo", {
                    {"text", textinfo.text},
                    {"x", textinfo.x},
                    {"y", textinfo.y},
                    {"alignment", textinfo.alignment},
                    {"color", {"red", textinfo.color.red},{"green", textinfo.color.green},{"blue", textinfo.color.blue},{"alpha", textinfo.color.alpha}},
                    {"font", {"name", textinfo.font.name},{"size", textinfo.font.size}}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetBuildMapStationLocation(PARAMS(UniverseID holomapid))
    {
        UIPosRot location;
        const auto func_res_1 = invoke(GetBuildMapStationLocation, holomapid, &location);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"location", {
                    {"x", location.x},
                    {"y", location.y},
                    {"z", location.z},
                    {"yaw", location.yaw},
                    {"pitch", location.pitch},
                    {"roll", location.roll}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetButtonHighlightColor(PARAMS(const int buttonid))
    {
        Color color;
        const auto func_res_1 = invoke(GetButtonHighlightColor, buttonid, &color);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"color", {
                    {"red", color.red},
                    {"green", color.green},
                    {"blue", color.blue},
                    {"alpha", color.alpha}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetButtonText2Details(PARAMS(const int buttonid))
    {
        TextInfo textinfo;
        const auto func_res_1 = invoke(GetButtonText2Details, buttonid, &textinfo);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"textinfo", {
                    {"text", textinfo.text},
                    {"x", textinfo.x},
                    {"y", textinfo.y},
                    {"alignment", textinfo.alignment},
                    {"color", {"red", textinfo.color.red},{"green", textinfo.color.green},{"blue", textinfo.color.blue},{"alpha", textinfo.color.alpha}},
                    {"font", {"name", textinfo.font.name},{"size", textinfo.font.size}}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetCheckBoxColor(PARAMS(const int checkboxid))
    {
        Color color;
        const auto func_res_1 = invoke(GetCheckBoxColor, checkboxid, &color);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"color", {
                    {"red", color.red},
                    {"green", color.green},
                    {"blue", color.blue},
                    {"alpha", color.alpha}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetChromaticAberrationOption(PARAMS())
    {
        const auto func_res_1 = invoke(GetChromaticAberrationOption);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetContainerWareIsBuyable(PARAMS(UniverseID containerid,const char* wareid))
    {
        const auto func_res_1 = invoke(GetContainerWareIsBuyable, containerid, wareid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetContainerWareIsSellable(PARAMS(UniverseID containerid,const char* wareid))
    {
        const auto func_res_1 = invoke(GetContainerWareIsSellable, containerid, wareid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetCustomGameStartBoolProperty(PARAMS(const char* id,const char* propertyid))
    {
        CustomGameStartBoolPropertyState state;
        const auto func_res_1 = invoke(GetCustomGameStartBoolProperty, id, propertyid, &state);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"state", {
                    {"state", state.state},
                    {"defaultvalue", state.defaultvalue}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetDefaultOrder(PARAMS(UniverseID controllableid))
    {
        Order result;
        const auto func_res_1 = invoke(GetDefaultOrder, &result, controllableid);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"result", {
                    {"queueidx", result.queueidx},
                    {"state", result.state},
                    {"statename", result.statename},
                    {"orderdef", result.orderdef},
                    {"actualparams", result.actualparams},
                    {"enabled", result.enabled},
                    {"isinfinite", result.isinfinite},
                    {"issyncpointreached", result.issyncpointreached},
                    {"istemporder", result.istemporder}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetDropDownColor(PARAMS(const int dropdownid))
    {
        Color color;
        const auto func_res_1 = invoke(GetDropDownColor, dropdownid, &color);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"color", {
                    {"red", color.red},
                    {"green", color.green},
                    {"blue", color.blue},
                    {"alpha", color.alpha}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetDropDownHighlightColor(PARAMS(const int dropdownid))
    {
        Color color;
        const auto func_res_1 = invoke(GetDropDownHighlightColor, dropdownid, &color);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"color", {
                    {"red", color.red},
                    {"green", color.green},
                    {"blue", color.blue},
                    {"alpha", color.alpha}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetDropDownHotkeyDetails(PARAMS(const int dropdownid))
    {
        HotkeyInfo hotkeyinfo;
        const auto func_res_1 = invoke(GetDropDownHotkeyDetails, dropdownid, &hotkeyinfo);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"hotkeyinfo", {
                    {"iconid", hotkeyinfo.iconid},
                    {"x", hotkeyinfo.x},
                    {"y", hotkeyinfo.y},
                    {"display", hotkeyinfo.display}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetDropDownIconDetails(PARAMS(const int dropdownid))
    {
        DropDownIconInfo iconinfo;
        const auto func_res_1 = invoke(GetDropDownIconDetails, dropdownid, &iconinfo);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"iconinfo", {
                    {"color", {"red", iconinfo.color.red},{"green", iconinfo.color.green},{"blue", iconinfo.color.blue},{"alpha", iconinfo.color.alpha}},
                    {"width", iconinfo.width},
                    {"height", iconinfo.height},
                    {"x", iconinfo.x},
                    {"y", iconinfo.y}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetDropDownOptionColor(PARAMS(const int dropdownid))
    {
        Color color;
        const auto func_res_1 = invoke(GetDropDownOptionColor, dropdownid, &color);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"color", {
                    {"red", color.red},
                    {"green", color.green},
                    {"blue", color.blue},
                    {"alpha", color.alpha}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetDropDownText2Details(PARAMS(const int dropdownid))
    {
        DropDownTextInfo textinfo;
        const auto func_res_1 = invoke(GetDropDownText2Details, dropdownid, &textinfo);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"textinfo", {
                    {"color", {"red", textinfo.color.red},{"green", textinfo.color.green},{"blue", textinfo.color.blue},{"alpha", textinfo.color.alpha}},
                    {"font", {"name", textinfo.font.name},{"size", textinfo.font.size}},
                    {"alignment", textinfo.alignment},
                    {"x", textinfo.x},
                    {"y", textinfo.y},
                    {"textOverride", textinfo.textOverride}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetDropDownTextDetails(PARAMS(const int dropdownid))
    {
        DropDownTextInfo textinfo;
        const auto func_res_1 = invoke(GetDropDownTextDetails, dropdownid, &textinfo);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"textinfo", {
                    {"color", {"red", textinfo.color.red},{"green", textinfo.color.green},{"blue", textinfo.color.blue},{"alpha", textinfo.color.alpha}},
                    {"font", {"name", textinfo.font.name},{"size", textinfo.font.size}},
                    {"alignment", textinfo.alignment},
                    {"x", textinfo.x},
                    {"y", textinfo.y},
                    {"textOverride", textinfo.textOverride}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetFontStringTitleColor(PARAMS(const int fontstringid))
    {
        Color color;
        const auto func_res_1 = invoke(GetFontStringTitleColor, fontstringid, &color);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"color", {
                    {"red", color.red},
                    {"green", color.green},
                    {"blue", color.blue},
                    {"alpha", color.alpha}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetForceShootingAtCursorOption(PARAMS())
    {
        const auto func_res_1 = invoke(GetForceShootingAtCursorOption);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetGraphBackgroundColor(PARAMS(const int graphid))
    {
        Color color;
        const auto func_res_1 = invoke(GetGraphBackgroundColor, graphid, &color);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"color", {
                    {"red", color.red},
                    {"green", color.green},
                    {"blue", color.blue},
                    {"alpha", color.alpha}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetGraphTitle(PARAMS(const int graphid))
    {
        GraphTextInfo title;
        const auto func_res_1 = invoke(GetGraphTitle, graphid, &title);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"title", {
                    {"text", title.text},
                    {"font", {"name", title.font.name},{"size", title.font.size}},
                    {"color", {"red", title.color.red},{"green", title.color.green},{"blue", title.color.blue},{"alpha", title.color.alpha}}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetGraphXAxis(PARAMS(const int graphid))
    {
        GraphAxisInfo axis;
        const auto func_res_1 = invoke(GetGraphXAxis, graphid, &axis);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"axis", {
                    {"label", {"text", axis.label.text},{"font", {"name", axis.label.font.name},{"size", axis.label.font.size}},{"color", {"red", axis.label.color.red},{"green", axis.label.color.green},{"blue", axis.label.color.blue},{"alpha", axis.label.color.alpha}}},
                    {"startvalue", axis.startvalue},
                    {"endvalue", axis.endvalue},
                    {"granularity", axis.granularity},
                    {"offset", axis.offset},
                    {"grid", axis.grid},
                    {"color", {"red", axis.color.red},{"green", axis.color.green},{"blue", axis.color.blue},{"alpha", axis.color.alpha}},
                    {"gridcolor", {"red", axis.gridcolor.red},{"green", axis.gridcolor.green},{"blue", axis.gridcolor.blue},{"alpha", axis.gridcolor.alpha}}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetGraphYAxis(PARAMS(const int graphid))
    {
        GraphAxisInfo axis;
        const auto func_res_1 = invoke(GetGraphYAxis, graphid, &axis);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"axis", {
                    {"label", {"text", axis.label.text},{"font", {"name", axis.label.font.name},{"size", axis.label.font.size}},{"color", {"red", axis.label.color.red},{"green", axis.label.color.green},{"blue", axis.label.color.blue},{"alpha", axis.label.color.alpha}}},
                    {"startvalue", axis.startvalue},
                    {"endvalue", axis.endvalue},
                    {"granularity", axis.granularity},
                    {"offset", axis.offset},
                    {"grid", axis.grid},
                    {"color", {"red", axis.color.red},{"green", axis.color.green},{"blue", axis.color.blue},{"alpha", axis.color.alpha}},
                    {"gridcolor", {"red", axis.gridcolor.red},{"green", axis.gridcolor.green},{"blue", axis.gridcolor.blue},{"alpha", axis.gridcolor.alpha}}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetHUDSeparateRadar(PARAMS())
    {
        const auto func_res_1 = invoke(GetHUDSeparateRadar);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetIconText2Details(PARAMS(const int iconid))
    {
        TextInfo textinfo;
        const auto func_res_1 = invoke(GetIconText2Details, iconid, &textinfo);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"textinfo", {
                    {"text", textinfo.text},
                    {"x", textinfo.x},
                    {"y", textinfo.y},
                    {"alignment", textinfo.alignment},
                    {"color", {"red", textinfo.color.red},{"green", textinfo.color.green},{"blue", textinfo.color.blue},{"alpha", textinfo.color.alpha}},
                    {"font", {"name", textinfo.font.name},{"size", textinfo.font.size}}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetIconTextDetails(PARAMS(const int iconid))
    {
        TextInfo textinfo;
        const auto func_res_1 = invoke(GetIconTextDetails, iconid, &textinfo);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"textinfo", {
                    {"text", textinfo.text},
                    {"x", textinfo.x},
                    {"y", textinfo.y},
                    {"alignment", textinfo.alignment},
                    {"color", {"red", textinfo.color.red},{"green", textinfo.color.green},{"blue", textinfo.color.blue},{"alpha", textinfo.color.alpha}},
                    {"font", {"name", textinfo.font.name},{"size", textinfo.font.size}}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetInstalledEngineMod(PARAMS(UniverseID objectid))
    {
        UIEngineMod enginemod;
        const auto func_res_1 = invoke(GetInstalledEngineMod, objectid, &enginemod);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"enginemod", {
                    {"Name", enginemod.Name},
                    {"RawName", enginemod.RawName},
                    {"Ware", enginemod.Ware},
                    {"Quality", enginemod.Quality},
                    {"PropertyType", enginemod.PropertyType},
                    {"ForwardThrustFactor", enginemod.ForwardThrustFactor},
                    {"StrafeThrustFactor", enginemod.StrafeThrustFactor},
                    {"RotationThrustFactor", enginemod.RotationThrustFactor},
                    {"BoostThrustFactor", enginemod.BoostThrustFactor},
                    {"BoostDurationFactor", enginemod.BoostDurationFactor},
                    {"BoostAttackTimeFactor", enginemod.BoostAttackTimeFactor},
                    {"BoostReleaseTimeFactor", enginemod.BoostReleaseTimeFactor},
                    {"BoostChargeTimeFactor", enginemod.BoostChargeTimeFactor},
                    {"BoostRechargeTimeFactor", enginemod.BoostRechargeTimeFactor},
                    {"TravelThrustFactor", enginemod.TravelThrustFactor},
                    {"TravelStartThrustFactor", enginemod.TravelStartThrustFactor},
                    {"TravelAttackTimeFactor", enginemod.TravelAttackTimeFactor},
                    {"TravelReleaseTimeFactor", enginemod.TravelReleaseTimeFactor},
                    {"TravelChargeTimeFactor", enginemod.TravelChargeTimeFactor}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetInstalledGroupedWeaponMod(PARAMS(UniverseID defensibleid,UniverseID contextid,const char* group))
    {
        UIWeaponMod weaponmod;
        const auto func_res_1 = invoke(GetInstalledGroupedWeaponMod, defensibleid, contextid, group, &weaponmod);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"weaponmod", {
                    {"Name", weaponmod.Name},
                    {"RawName", weaponmod.RawName},
                    {"Ware", weaponmod.Ware},
                    {"Quality", weaponmod.Quality},
                    {"PropertyType", weaponmod.PropertyType},
                    {"DamageFactor", weaponmod.DamageFactor},
                    {"CoolingFactor", weaponmod.CoolingFactor},
                    {"ReloadFactor", weaponmod.ReloadFactor},
                    {"SpeedFactor", weaponmod.SpeedFactor},
                    {"LifeTimeFactor", weaponmod.LifeTimeFactor},
                    {"MiningFactor", weaponmod.MiningFactor},
                    {"StickTimeFactor", weaponmod.StickTimeFactor},
                    {"ChargeTimeFactor", weaponmod.ChargeTimeFactor},
                    {"BeamLengthFactor", weaponmod.BeamLengthFactor},
                    {"AddedAmount", weaponmod.AddedAmount},
                    {"RotationSpeedFactor", weaponmod.RotationSpeedFactor},
                    {"SurfaceElementFactor", weaponmod.SurfaceElementFactor}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetInstalledPaintMod(PARAMS(UniverseID objectid))
    {
        UIPaintMod paintmod;
        const auto func_res_1 = invoke(GetInstalledPaintMod, objectid, &paintmod);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"paintmod", {
                    {"Name", paintmod.Name},
                    {"RawName", paintmod.RawName},
                    {"Ware", paintmod.Ware},
                    {"Quality", paintmod.Quality},
                    {"Amount", paintmod.Amount}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetInstalledShieldMod(PARAMS(UniverseID defensibleid,UniverseID contextid,const char* group))
    {
        UIShieldMod shieldmod;
        const auto func_res_1 = invoke(GetInstalledShieldMod, defensibleid, contextid, group, &shieldmod);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"shieldmod", {
                    {"Name", shieldmod.Name},
                    {"RawName", shieldmod.RawName},
                    {"Ware", shieldmod.Ware},
                    {"Quality", shieldmod.Quality},
                    {"PropertyType", shieldmod.PropertyType},
                    {"CapacityFactor", shieldmod.CapacityFactor},
                    {"RechargeDelayFactor", shieldmod.RechargeDelayFactor},
                    {"RechargeRateFactor", shieldmod.RechargeRateFactor}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetInstalledShipMod(PARAMS(UniverseID shipid))
    {
        UIShipMod shipmod;
        const auto func_res_1 = invoke(GetInstalledShipMod, shipid, &shipmod);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"shipmod", {
                    {"Name", shipmod.Name},
                    {"RawName", shipmod.RawName},
                    {"Ware", shipmod.Ware},
                    {"Quality", shipmod.Quality},
                    {"PropertyType", shipmod.PropertyType},
                    {"MassFactor", shipmod.MassFactor},
                    {"DragFactor", shipmod.DragFactor},
                    {"MaxHullFactor", shipmod.MaxHullFactor},
                    {"RadarRangeFactor", shipmod.RadarRangeFactor},
                    {"AddedUnitCapacity", shipmod.AddedUnitCapacity},
                    {"AddedMissileCapacity", shipmod.AddedMissileCapacity},
                    {"AddedCountermeasureCapacity", shipmod.AddedCountermeasureCapacity},
                    {"AddedDeployableCapacity", shipmod.AddedDeployableCapacity}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetInstalledWeaponMod(PARAMS(UniverseID weaponid))
    {
        UIWeaponMod weaponmod;
        const auto func_res_1 = invoke(GetInstalledWeaponMod, weaponid, &weaponmod);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"weaponmod", {
                    {"Name", weaponmod.Name},
                    {"RawName", weaponmod.RawName},
                    {"Ware", weaponmod.Ware},
                    {"Quality", weaponmod.Quality},
                    {"PropertyType", weaponmod.PropertyType},
                    {"DamageFactor", weaponmod.DamageFactor},
                    {"CoolingFactor", weaponmod.CoolingFactor},
                    {"ReloadFactor", weaponmod.ReloadFactor},
                    {"SpeedFactor", weaponmod.SpeedFactor},
                    {"LifeTimeFactor", weaponmod.LifeTimeFactor},
                    {"MiningFactor", weaponmod.MiningFactor},
                    {"StickTimeFactor", weaponmod.StickTimeFactor},
                    {"ChargeTimeFactor", weaponmod.ChargeTimeFactor},
                    {"BeamLengthFactor", weaponmod.BeamLengthFactor},
                    {"AddedAmount", weaponmod.AddedAmount},
                    {"RotationSpeedFactor", weaponmod.RotationSpeedFactor},
                    {"SurfaceElementFactor", weaponmod.SurfaceElementFactor}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetLicenceInfo(PARAMS(const char* factionid,const char* licenceid))
    {
        LicenceInfo result;
        const auto func_res_1 = invoke(GetLicenceInfo, &result, factionid, licenceid);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"result", {
                    {"name", result.name},
                    {"icon", result.icon}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetMouseOverTextOption(PARAMS())
    {
        const auto func_res_1 = invoke(GetMouseOverTextOption);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetMouseSteeringInvertedOption(PARAMS(const char* paramname))
    {
        const auto func_res_1 = invoke(GetMouseSteeringInvertedOption, paramname);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetOrderDefinition(PARAMS(const char* orderdef))
    {
        OrderDefinition result;
        const auto func_res_1 = invoke(GetOrderDefinition, &result, orderdef);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"result", {
                    {"id", result.id},
                    {"name", result.name},
                    {"icon", result.icon},
                    {"description", result.description},
                    {"category", result.category},
                    {"categoryname", result.categoryname},
                    {"infinite", result.infinite},
                    {"requiredSkill", result.requiredSkill}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPickedBuildMapEntry(PARAMS(UniverseID holomapid,UniverseID defensibleid))
    {
        UIConstructionPlanEntry result;
        const auto func_res_1 = invoke(GetPickedBuildMapEntry, holomapid, defensibleid, &result);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"result", {
                    {"idx", result.idx},
                    {"macroid", result.macroid},
                    {"componentid", result.componentid},
                    {"offset", {"x", result.offset.x},{"y", result.offset.y},{"z", result.offset.z},{"yaw", result.offset.yaw},{"pitch", result.offset.pitch},{"roll", result.offset.roll}},
                    {"connectionid", result.connectionid},
                    {"predecessoridx", result.predecessoridx},
                    {"predecessorconnectionid", result.predecessorconnectionid},
                    {"isfixed", result.isfixed}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPickedMapMacroSlot(PARAMS(UniverseID holomapid,UniverseID defensibleid,UniverseID moduleid,const char* macroname,bool ismodule))
    {
        UILoadoutSlot result;
        const auto func_res_1 = invoke(GetPickedMapMacroSlot, holomapid, defensibleid, moduleid, macroname, ismodule, &result);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"result", {
                    {"upgradetype", result.upgradetype},
                    {"slot", result.slot}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPlannedDefaultOrder(PARAMS(UniverseID controllableid))
    {
        Order result;
        const auto func_res_1 = invoke(GetPlannedDefaultOrder, &result, controllableid);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"result", {
                    {"queueidx", result.queueidx},
                    {"state", result.state},
                    {"statename", result.statename},
                    {"orderdef", result.orderdef},
                    {"actualparams", result.actualparams},
                    {"enabled", result.enabled},
                    {"isinfinite", result.isinfinite},
                    {"issyncpointreached", result.issyncpointreached},
                    {"istemporder", result.istemporder}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPlayerPaintThemeMod(PARAMS(UniverseID objectid,const char* macroname))
    {
        UIPaintMod paintmod;
        const auto func_res_1 = invoke(GetPlayerPaintThemeMod, objectid, macroname, &paintmod);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"paintmod", {
                    {"Name", paintmod.Name},
                    {"RawName", paintmod.RawName},
                    {"Ware", paintmod.Ware},
                    {"Quality", paintmod.Quality},
                    {"Amount", paintmod.Amount}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetSavesCompressedOption(PARAMS())
    {
        const auto func_res_1 = invoke(GetSavesCompressedOption);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetScreenDisplayOption(PARAMS())
    {
        const auto func_res_1 = invoke(GetScreenDisplayOption);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetShieldGroup(PARAMS(UniverseID defensibleid,UniverseID destructibleid))
    {
        ShieldGroup result;
        const auto func_res_1 = invoke(GetShieldGroup, &result, defensibleid, destructibleid);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"result", {
                    {"context", result.context},
                    {"group", result.group},
                    {"component", result.component}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetSliderCellBackgroundColor(PARAMS(const int slidercellid))
    {
        Color color;
        const auto func_res_1 = invoke(GetSliderCellBackgroundColor, slidercellid, &color);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"color", {
                    {"red", color.red},
                    {"green", color.green},
                    {"blue", color.blue},
                    {"alpha", color.alpha}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetSliderCellFont(PARAMS(const int slidercellid))
    {
        Font font;
        const auto func_res_1 = invoke(GetSliderCellFont, slidercellid, &font);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"font", {
                    {"name", font.name},
                    {"size", font.size}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetSliderCellInactiveBackgroundColor(PARAMS(const int slidercellid))
    {
        Color color;
        const auto func_res_1 = invoke(GetSliderCellInactiveBackgroundColor, slidercellid, &color);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"color", {
                    {"red", color.red},
                    {"green", color.green},
                    {"blue", color.blue},
                    {"alpha", color.alpha}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetSliderCellNegativeValueColor(PARAMS(const int slidercellid))
    {
        Color color;
        const auto func_res_1 = invoke(GetSliderCellNegativeValueColor, slidercellid, &color);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"color", {
                    {"red", color.red},
                    {"green", color.green},
                    {"blue", color.blue},
                    {"alpha", color.alpha}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetSliderCellTextColor(PARAMS(const int slidercellid))
    {
        Color color;
        const auto func_res_1 = invoke(GetSliderCellTextColor, slidercellid, &color);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"color", {
                    {"red", color.red},
                    {"green", color.green},
                    {"blue", color.blue},
                    {"alpha", color.alpha}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetSliderCellValueColor(PARAMS(const int slidercellid))
    {
        Color color;
        const auto func_res_1 = invoke(GetSliderCellValueColor, slidercellid, &color);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"color", {
                    {"red", color.red},
                    {"green", color.green},
                    {"blue", color.blue},
                    {"alpha", color.alpha}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetSliderCellValues(PARAMS(const int slidercellid))
    {
        SliderCellDetails values;
        const auto func_res_1 = invoke(GetSliderCellValues, slidercellid, &values);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"values", {
                    {"min", values.min},
                    {"minSelect", values.minSelect},
                    {"max", values.max},
                    {"maxSelect", values.maxSelect},
                    {"start", values.start},
                    {"step", values.step},
                    {"infinitevalue", values.infinitevalue},
                    {"maxfactor", values.maxfactor},
                    {"exceedmax", values.exceedmax},
                    {"hidemaxvalue", values.hidemaxvalue},
                    {"righttoleft", values.righttoleft},
                    {"fromcenter", values.fromcenter},
                    {"readonly", values.readonly},
                    {"useinfinitevalue", values.useinfinitevalue},
                    {"usetimeformat", values.usetimeformat}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetSpeakTargetNameOption(PARAMS())
    {
        const auto func_res_1 = invoke(GetSpeakTargetNameOption);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetStatusBarMarkerColor(PARAMS(const int statusbarid))
    {
        Color color;
        const auto func_res_1 = invoke(GetStatusBarMarkerColor, statusbarid, &color);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"color", {
                    {"red", color.red},
                    {"green", color.green},
                    {"blue", color.blue},
                    {"alpha", color.alpha}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetStatusBarNegChangeColor(PARAMS(const int statusbarid))
    {
        Color color;
        const auto func_res_1 = invoke(GetStatusBarNegChangeColor, statusbarid, &color);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"color", {
                    {"red", color.red},
                    {"green", color.green},
                    {"blue", color.blue},
                    {"alpha", color.alpha}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetStatusBarPosChangeColor(PARAMS(const int statusbarid))
    {
        Color color;
        const auto func_res_1 = invoke(GetStatusBarPosChangeColor, statusbarid, &color);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"color", {
                    {"red", color.red},
                    {"green", color.green},
                    {"blue", color.blue},
                    {"alpha", color.alpha}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetStatusBarValueColor(PARAMS(const int statusbarid))
    {
        Color color;
        const auto func_res_1 = invoke(GetStatusBarValueColor, statusbarid, &color);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"color", {
                    {"red", color.red},
                    {"green", color.green},
                    {"blue", color.blue},
                    {"alpha", color.alpha}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetSyncPointInfo(PARAMS(UniverseID controllableid,size_t orderidx))
    {
        SyncPointInfo result;
        const auto func_res_1 = invoke(GetSyncPointInfo, controllableid, orderidx, &result);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"result", {
                    {"id", result.id},
                    {"reached", result.reached}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetTableBackgroundColor(PARAMS(const int tableid))
    {
        Color color;
        const auto func_res_1 = invoke(GetTableBackgroundColor, tableid, &color);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"color", {
                    {"red", color.red},
                    {"green", color.green},
                    {"blue", color.blue},
                    {"alpha", color.alpha}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetUISystemInfo(PARAMS(UniverseID clusterid))
    {
        UISystemInfo result;
        const auto func_res_1 = invoke(GetUISystemInfo, &result, clusterid);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"result", {
                    {"space", {"environment", result.space.environment}},
                    {"numsuns", result.numsuns},
                    {"suns", {"name", result.suns->name},{"typeclass", result.suns->typeclass}},
                    {"numplanets", result.numplanets},
                    {"planets", {"name", result.planets->name},{"typeclass", result.planets->typeclass},{"geology", result.planets->geology},{"atmosphere", result.planets->atmosphere},{"population", result.planets->population},{"settlements", result.planets->settlements},{"nummoons", result.planets->nummoons}}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetUp(PARAMS())
    {
        const auto func_res_1 = invoke(GetUp);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetVentureOption(PARAMS())
    {
        const auto func_res_1 = invoke(GetVentureOption);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetVisitorNamesShownOption(PARAMS())
    {
        const auto func_res_1 = invoke(GetVisitorNamesShownOption);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json HasContainerBuyLimitOverride(PARAMS(UniverseID containerid,const char* wareid))
    {
        const auto func_res_1 = invoke(HasContainerBuyLimitOverride, containerid, wareid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json HasContainerSellLimitOverride(PARAMS(UniverseID containerid,const char* wareid))
    {
        const auto func_res_1 = invoke(HasContainerSellLimitOverride, containerid, wareid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json HasControllableOwnBlacklist(PARAMS(UniverseID controllableid,const char* listtype))
    {
        const auto func_res_1 = invoke(HasControllableOwnBlacklist, controllableid, listtype);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json HasControllableOwnResponse(PARAMS(UniverseID controllableid,const char* signalid))
    {
        const auto func_res_1 = invoke(HasControllableOwnResponse, controllableid, signalid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json HasDefaultLoadout(PARAMS(const char* macroname))
    {
        const auto func_res_1 = invoke(HasDefaultLoadout, macroname);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json HasEntityMoneyLogEntries(PARAMS(UniverseID entityid))
    {
        const auto func_res_1 = invoke(HasEntityMoneyLogEntries, entityid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json HasExtension(PARAMS(const char* extensionid,bool personal))
    {
        const auto func_res_1 = invoke(HasExtension, extensionid, personal);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json HasFrameBrackets(PARAMS(const int frameid))
    {
        const auto func_res_1 = invoke(HasFrameBrackets, frameid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json HasLimitedOxygenSupply(PARAMS())
    {
        const auto func_res_1 = invoke(HasLimitedOxygenSupply);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json HasResearched(PARAMS(const char* wareid))
    {
        const auto func_res_1 = invoke(HasResearched, wareid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json HasSavegame(PARAMS())
    {
        const auto func_res_1 = invoke(HasSavegame);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json HasSeta(PARAMS())
    {
        const auto func_res_1 = invoke(HasSeta);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json HasShipFlightAssist(PARAMS(UniverseID shipid))
    {
        const auto func_res_1 = invoke(HasShipFlightAssist, shipid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json HasStartAnimation(PARAMS())
    {
        const auto func_res_1 = invoke(HasStartAnimation);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json HasVenturerDock(PARAMS(UniverseID containerid,UniverseID shipid,UniverseID ventureplatformid))
    {
        const auto func_res_1 = invoke(HasVenturerDock, containerid, shipid, ventureplatformid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json InstallEngineMod(PARAMS(UniverseID objectid,const char* wareid))
    {
        const auto func_res_1 = invoke(InstallEngineMod, objectid, wareid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json InstallGroupedWeaponMod(PARAMS(UniverseID defensibleid,UniverseID contextid,const char* group,const char* wareid))
    {
        const auto func_res_1 = invoke(InstallGroupedWeaponMod, defensibleid, contextid, group, wareid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json InstallPaintMod(PARAMS(UniverseID objectid,const char* wareid,bool useinventory))
    {
        const auto func_res_1 = invoke(InstallPaintMod, objectid, wareid, useinventory);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json InstallShieldMod(PARAMS(UniverseID defensibleid,UniverseID contextid,const char* group,const char* wareid))
    {
        const auto func_res_1 = invoke(InstallShieldMod, defensibleid, contextid, group, wareid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json InstallShipMod(PARAMS(UniverseID shipid,const char* wareid))
    {
        const auto func_res_1 = invoke(InstallShipMod, shipid, wareid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json InstallWeaponMod(PARAMS(UniverseID weaponid,const char* wareid))
    {
        const auto func_res_1 = invoke(InstallWeaponMod, weaponid, wareid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsAAOptionSupported(PARAMS(const char* mode))
    {
        const auto func_res_1 = invoke(IsAAOptionSupported, mode);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsAdvancedSatellite(PARAMS(const UniverseID componentid))
    {
        const auto func_res_1 = invoke(IsAdvancedSatellite, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsAmmoMacroCompatible(PARAMS(const char* weaponmacroname,const char* ammomacroname))
    {
        const auto func_res_1 = invoke(IsAmmoMacroCompatible, weaponmacroname, ammomacroname);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsAppStoreVersion(PARAMS())
    {
        const auto func_res_1 = invoke(IsAppStoreVersion);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsAsteroid(PARAMS(const UniverseID componentid))
    {
        const auto func_res_1 = invoke(IsAsteroid, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsAutotargetingActive(PARAMS())
    {
        const auto func_res_1 = invoke(IsAutotargetingActive);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsBomb(PARAMS(const UniverseID componentid))
    {
        const auto func_res_1 = invoke(IsBomb, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsBoxTextWordWrap(PARAMS(const int boxtextid))
    {
        const auto func_res_1 = invoke(IsBoxTextWordWrap, boxtextid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsBuilderBusy(PARAMS(UniverseID shipid))
    {
        const auto func_res_1 = invoke(IsBuilderBusy, shipid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsCheckBoxActive(PARAMS(const int checkboxid))
    {
        const auto func_res_1 = invoke(IsCheckBoxActive, checkboxid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsCheckBoxChecked(PARAMS(const int checkboxid))
    {
        const auto func_res_1 = invoke(IsCheckBoxChecked, checkboxid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsCollectable(PARAMS(const UniverseID componentid))
    {
        const auto func_res_1 = invoke(IsCollectable, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsCommander(PARAMS(const UniverseID componentid))
    {
        const auto func_res_1 = invoke(IsCommander, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsComponentClass(PARAMS(UniverseID componentid,const char* classname))
    {
        const auto func_res_1 = invoke(IsComponentClass, componentid, classname);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsComponentOperational(PARAMS(UniverseID componentid))
    {
        const auto func_res_1 = invoke(IsComponentOperational, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsComponentWrecked(PARAMS(UniverseID componentid))
    {
        const auto func_res_1 = invoke(IsComponentWrecked, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsConstructionPlanValid(PARAMS(const char* constructionplanid))
    {
        uint32_t numinvalidpatches;
        const auto func_res_1 = invoke(IsConstructionPlanValid, constructionplanid, &numinvalidpatches);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"numinvalidpatches", numinvalidpatches}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsContainerAmmoMacroCompatible(PARAMS(UniverseID containerid,const char* ammomacroname))
    {
        const auto func_res_1 = invoke(IsContainerAmmoMacroCompatible, containerid, ammomacroname);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsContainerFactionBuildRescricted(PARAMS(UniverseID containerid))
    {
        const auto func_res_1 = invoke(IsContainerFactionBuildRescricted, containerid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsContainerFactionTradeRescricted(PARAMS(UniverseID containerid,const char* wareid))
    {
        const auto func_res_1 = invoke(IsContainerFactionTradeRescricted, containerid, wareid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsContestedSector(PARAMS(UniverseID sectorid))
    {
        const auto func_res_1 = invoke(IsContestedSector, sectorid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsControlPressed(PARAMS())
    {
        const auto func_res_1 = invoke(IsControlPressed);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsConversationActive(PARAMS())
    {
        const auto func_res_1 = invoke(IsConversationActive);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsCrate(PARAMS(const UniverseID componentid))
    {
        const auto func_res_1 = invoke(IsCrate, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsCrystal(PARAMS(const UniverseID componentid))
    {
        const auto func_res_1 = invoke(IsCrystal, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsCurrentGPUDiscrete(PARAMS())
    {
        const auto func_res_1 = invoke(IsCurrentGPUDiscrete);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsCurrentOrderCritical(PARAMS(UniverseID controllableid))
    {
        const auto func_res_1 = invoke(IsCurrentOrderCritical, controllableid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsCurrentlyScanning(PARAMS())
    {
        const auto func_res_1 = invoke(IsCurrentlyScanning);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsCustomGameStartPropertyChanged(PARAMS(const char* id,const char* propertyid))
    {
        const auto func_res_1 = invoke(IsCustomGameStartPropertyChanged, id, propertyid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsDefensibleBeingBoardedBy(PARAMS(UniverseID defensibleid,const char* factionid))
    {
        const auto func_res_1 = invoke(IsDefensibleBeingBoardedBy, defensibleid, factionid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsDemoVersion(PARAMS())
    {
        const auto func_res_1 = invoke(IsDemoVersion);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsDeployableMacroCompatible(PARAMS(UniverseID containerid,const char* macroname,const char* deployablemacroname))
    {
        const auto func_res_1 = invoke(IsDeployableMacroCompatible, containerid, macroname, deployablemacroname);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsDestructible2(PARAMS(const UniverseID componentid,const char*const connectionname))
    {
        const auto func_res_1 = invoke(IsDestructible2, componentid, connectionname);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsDetailUIElement(PARAMS(const UniverseID componentid,const char*const connectionname))
    {
        const auto func_res_1 = invoke(IsDetailUIElement, componentid, connectionname);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsDroneTypeArmed(PARAMS(UniverseID defensibleid,const char* dronetype))
    {
        const auto func_res_1 = invoke(IsDroneTypeArmed, defensibleid, dronetype);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsDroneTypeBlocked(PARAMS(UniverseID defensibleid,const char* dronetype))
    {
        const auto func_res_1 = invoke(IsDroneTypeBlocked, defensibleid, dronetype);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsDropDownActive(PARAMS(const int dropdownid))
    {
        const auto func_res_1 = invoke(IsDropDownActive, dropdownid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsDropDownMouseOverInteractionAllowed(PARAMS(const int dropdownid))
    {
        const auto func_res_1 = invoke(IsDropDownMouseOverInteractionAllowed, dropdownid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsEditBoxActive(PARAMS(const int editboxid))
    {
        const auto func_res_1 = invoke(IsEditBoxActive, editboxid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsEditBoxInputEncrypted(PARAMS(const int editboxid))
    {
        const auto func_res_1 = invoke(IsEditBoxInputEncrypted, editboxid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsEditBoxTextHidden(PARAMS(const int editboxid))
    {
        const auto func_res_1 = invoke(IsEditBoxTextHidden, editboxid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsEditBoxTextSelectedOnActivation(PARAMS(const int editboxid))
    {
        const auto func_res_1 = invoke(IsEditBoxTextSelectedOnActivation, editboxid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsEntity(PARAMS(const UniverseID componentid))
    {
        const auto func_res_1 = invoke(IsEntity, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsErrorLogActive(PARAMS())
    {
        const auto func_res_1 = invoke(IsErrorLogActive);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsExternalTargetMode(PARAMS())
    {
        const auto func_res_1 = invoke(IsExternalTargetMode);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsExternalViewActive(PARAMS())
    {
        const auto func_res_1 = invoke(IsExternalViewActive);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsFPSEnabled(PARAMS())
    {
        const auto func_res_1 = invoke(IsFPSEnabled);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsFactionAllyToFaction(PARAMS(const char* factionid,const char* otherfactionid))
    {
        const auto func_res_1 = invoke(IsFactionAllyToFaction, factionid, otherfactionid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsFactionEnemyToFaction(PARAMS(const char* factionid,const char* otherfactionid))
    {
        const auto func_res_1 = invoke(IsFactionEnemyToFaction, factionid, otherfactionid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsFactionHQ(PARAMS(UniverseID stationid))
    {
        const auto func_res_1 = invoke(IsFactionHQ, stationid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsFullscreenMenuDisplayed(PARAMS(bool anymenu,const char* menuname))
    {
        const auto func_res_1 = invoke(IsFullscreenMenuDisplayed, anymenu, menuname);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsGOGVersion(PARAMS())
    {
        const auto func_res_1 = invoke(IsGOGVersion);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsGameModified(PARAMS())
    {
        const auto func_res_1 = invoke(IsGameModified);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsGamePaused(PARAMS())
    {
        const auto func_res_1 = invoke(IsGamePaused);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsHQ(PARAMS(UniverseID stationid))
    {
        const auto func_res_1 = invoke(IsHQ, stationid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsHUDActive(PARAMS())
    {
        const auto func_res_1 = invoke(IsHUDActive);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsHUDRadarActive(PARAMS())
    {
        const auto func_res_1 = invoke(IsHUDRadarActive);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsIconValid(PARAMS(const char* iconid))
    {
        const auto func_res_1 = invoke(IsIconValid, iconid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsInfoUnlockedForPlayer(PARAMS(UniverseID componentid,const char* infostring))
    {
        const auto func_res_1 = invoke(IsInfoUnlockedForPlayer, componentid, infostring);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsJoystickSteeringAdapative(PARAMS())
    {
        const auto func_res_1 = invoke(IsJoystickSteeringAdapative);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsKnownItemRead(PARAMS(const char* libraryid,const char* itemid))
    {
        const auto func_res_1 = invoke(IsKnownItemRead, libraryid, itemid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsKnownRead(PARAMS(UniverseID componentid))
    {
        const auto func_res_1 = invoke(IsKnownRead, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsKnownToPlayer(PARAMS(UniverseID componentid))
    {
        const auto func_res_1 = invoke(IsKnownToPlayer, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsLanguageSettingEnabled(PARAMS())
    {
        const auto func_res_1 = invoke(IsLanguageSettingEnabled);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsLanguageValid(PARAMS())
    {
        const auto func_res_1 = invoke(IsLanguageValid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsLaserTower(PARAMS(const UniverseID componentid))
    {
        const auto func_res_1 = invoke(IsLaserTower, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsLeftMouseButtonDown(PARAMS())
    {
        const auto func_res_1 = invoke(IsLeftMouseButtonDown);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsLoadoutValid(PARAMS(UniverseID defensibleid,const char* macroname,const char* loadoutid))
    {
        uint32_t numinvalidpatches;
        const auto func_res_1 = invoke(IsLoadoutValid, defensibleid, macroname, loadoutid, &numinvalidpatches);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"numinvalidpatches", numinvalidpatches}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsLockbox(PARAMS(const UniverseID componentid))
    {
        const auto func_res_1 = invoke(IsLockbox, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsLowOnOxygen(PARAMS())
    {
        const auto func_res_1 = invoke(IsLowOnOxygen);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsMasterVersion(PARAMS())
    {
        const auto func_res_1 = invoke(IsMasterVersion);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsMiniWidgetSystemUsed(PARAMS())
    {
        const auto func_res_1 = invoke(IsMiniWidgetSystemUsed);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsMissileIncoming(PARAMS())
    {
        const auto func_res_1 = invoke(IsMissileIncoming);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsMissileLockingOn(PARAMS())
    {
        const auto func_res_1 = invoke(IsMissileLockingOn);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsMouseDoubleClickMode(PARAMS())
    {
        const auto func_res_1 = invoke(IsMouseDoubleClickMode);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsMouseEmulationActive(PARAMS())
    {
        const auto func_res_1 = invoke(IsMouseEmulationActive);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsMouseSteeringAdapative(PARAMS())
    {
        const auto func_res_1 = invoke(IsMouseSteeringAdapative);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsNavBeacon(PARAMS(const UniverseID componentid))
    {
        const auto func_res_1 = invoke(IsNavBeacon, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsNetworkEngineEnabled(PARAMS())
    {
        const auto func_res_1 = invoke(IsNetworkEngineEnabled);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsNextStartAnimationSkipped(PARAMS(bool reset))
    {
        const auto func_res_1 = invoke(IsNextStartAnimationSkipped, reset);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsObjectKnown(PARAMS(const UniverseID componentid))
    {
        const auto func_res_1 = invoke(IsObjectKnown, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsOnlineEnabled(PARAMS())
    {
        const auto func_res_1 = invoke(IsOnlineEnabled);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsOrderSelectableFor(PARAMS(const char* orderdefid,UniverseID controllableid))
    {
        const auto func_res_1 = invoke(IsOrderSelectableFor, orderdefid, controllableid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsPerson(PARAMS(NPCSeed person,UniverseID controllableid))
    {
        const auto func_res_1 = invoke(IsPerson, person, controllableid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsPersonTransferScheduled(PARAMS(UniverseID controllableid,NPCSeed person))
    {
        const auto func_res_1 = invoke(IsPersonTransferScheduled, controllableid, person);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsPlayerBlacklistDefault(PARAMS(BlacklistID id,const char* listtype,const char* defaultgroup))
    {
        const auto func_res_1 = invoke(IsPlayerBlacklistDefault, id, listtype, defaultgroup);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsPlayerCameraTargetViewPossible(PARAMS(UniverseID targetid,bool force))
    {
        const auto func_res_1 = invoke(IsPlayerCameraTargetViewPossible, targetid, force);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsPlayerValid(PARAMS())
    {
        const auto func_res_1 = invoke(IsPlayerValid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsPointingWithinAimingRange(PARAMS())
    {
        const auto func_res_1 = invoke(IsPointingWithinAimingRange);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsPresentModeOptionSupported(PARAMS(const char* mode))
    {
        const auto func_res_1 = invoke(IsPresentModeOptionSupported, mode);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsRealComponentClass(PARAMS(UniverseID componentid,const char* classname))
    {
        const auto func_res_1 = invoke(IsRealComponentClass, componentid, classname);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsResourceProbe(PARAMS(const UniverseID componentid))
    {
        const auto func_res_1 = invoke(IsResourceProbe, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsSatellite(PARAMS(const UniverseID componentid))
    {
        const auto func_res_1 = invoke(IsSatellite, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsSaveListLoadingComplete(PARAMS())
    {
        const auto func_res_1 = invoke(IsSaveListLoadingComplete);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsSaveValid(PARAMS(const char* filename))
    {
        const auto func_res_1 = invoke(IsSaveValid, filename);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsSetaActive(PARAMS())
    {
        const auto func_res_1 = invoke(IsSetaActive);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsShiftPressed(PARAMS())
    {
        const auto func_res_1 = invoke(IsShiftPressed);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsShip(PARAMS(const UniverseID componentid))
    {
        const auto func_res_1 = invoke(IsShip, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsShipAtExternalDock(PARAMS(UniverseID shipid))
    {
        const auto func_res_1 = invoke(IsShipAtExternalDock, shipid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsShipBeingRetrieved(PARAMS(UniverseID shipid))
    {
        const auto func_res_1 = invoke(IsShipBeingRetrieved, shipid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsSofttargetManagerActive(PARAMS())
    {
        const auto func_res_1 = invoke(IsSofttargetManagerActive);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsSoftwareDefault(PARAMS(UniverseID controllableid,const char* macroname,const char* softwarename))
    {
        const auto func_res_1 = invoke(IsSoftwareDefault, controllableid, macroname, softwarename);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsStartmenu(PARAMS())
    {
        const auto func_res_1 = invoke(IsStartmenu);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsStation(PARAMS(const UniverseID componentid))
    {
        const auto func_res_1 = invoke(IsStation, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsStationary(PARAMS(const UniverseID componentid))
    {
        const auto func_res_1 = invoke(IsStationary, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsSupplyManual(PARAMS(UniverseID containerid,const char* type))
    {
        const auto func_res_1 = invoke(IsSupplyManual, containerid, type);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsSurfaceElement(PARAMS(const UniverseID componentid))
    {
        const auto func_res_1 = invoke(IsSurfaceElement, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsTableMultiSelect(PARAMS(const int tableid))
    {
        const auto func_res_1 = invoke(IsTableMultiSelect, tableid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsTableRowBorderBelowEnabled(PARAMS(const int tableid,uint32_t row))
    {
        const auto func_res_1 = invoke(IsTableRowBorderBelowEnabled, tableid, row);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsTargetInPlayerWeaponRange(PARAMS(const UniverseID componentid))
    {
        const auto func_res_1 = invoke(IsTargetInPlayerWeaponRange, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsTargetMonitorNotification(PARAMS(const int notificationid))
    {
        const auto func_res_1 = invoke(IsTargetMonitorNotification, notificationid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsTargetable(PARAMS(const uint32_t messageid))
    {
        const auto func_res_1 = invoke(IsTargetable, messageid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsThrottleBidirectional(PARAMS())
    {
        const auto func_res_1 = invoke(IsThrottleBidirectional);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsTitleFontString(PARAMS(const int fontstringid))
    {
        const auto func_res_1 = invoke(IsTitleFontString, fontstringid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsTobiiAvailable(PARAMS())
    {
        const auto func_res_1 = invoke(IsTobiiAvailable);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsTradeShowVersion(PARAMS())
    {
        const auto func_res_1 = invoke(IsTradeShowVersion);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsTurretGroupArmed(PARAMS(UniverseID defensibleid,UniverseID contextid,const char* path,const char* group))
    {
        const auto func_res_1 = invoke(IsTurretGroupArmed, defensibleid, contextid, path, group);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsUnit(PARAMS(UniverseID controllableid))
    {
        const auto func_res_1 = invoke(IsUnit, controllableid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsUnitMacroCompatible(PARAMS(UniverseID containerid,const char* macroname,const char* unitmacroname))
    {
        const auto func_res_1 = invoke(IsUnitMacroCompatible, containerid, macroname, unitmacroname);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsUpgradeGroupMacroCompatible(PARAMS(UniverseID destructibleid,const char* macroname,const char* path,const char* group,const char* upgradetypename,const char* upgrademacroname))
    {
        const auto func_res_1 = invoke(IsUpgradeGroupMacroCompatible, destructibleid, macroname, path, group, upgradetypename, upgrademacroname);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsUpgradeMacroCompatible(PARAMS(UniverseID objectid,UniverseID moduleid,const char* macroname,bool ismodule,const char* upgradetypename,size_t slot,const char* upgrademacroname))
    {
        const auto func_res_1 = invoke(IsUpgradeMacroCompatible, objectid, moduleid, macroname, ismodule, upgradetypename, slot, upgrademacroname);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsVRMode(PARAMS())
    {
        const auto func_res_1 = invoke(IsVRMode);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsVROculusTouchActive(PARAMS())
    {
        const auto func_res_1 = invoke(IsVROculusTouchActive);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsVRPointerActive(PARAMS())
    {
        const auto func_res_1 = invoke(IsVRPointerActive);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsVRVersion(PARAMS())
    {
        const auto func_res_1 = invoke(IsVRVersion);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsVRViveControllerActive(PARAMS())
    {
        const auto func_res_1 = invoke(IsVRViveControllerActive);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsValidComponent(PARAMS(const UniverseID componentid))
    {
        const auto func_res_1 = invoke(IsValidComponent, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsVentureShip(PARAMS(const UniverseID componentid))
    {
        const auto func_res_1 = invoke(IsVentureShip, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsVirtualUpgradeMacroCompatible(PARAMS(UniverseID defensibleid,const char* macroname,const char* upgradetypename,size_t slot,const char* upgrademacroname))
    {
        const auto func_res_1 = invoke(IsVirtualUpgradeMacroCompatible, defensibleid, macroname, upgradetypename, slot, upgrademacroname);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsWeaponArmed(PARAMS(UniverseID weaponid))
    {
        const auto func_res_1 = invoke(IsWeaponArmed, weaponid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsWillingToBuyFromPlayer(PARAMS(UniverseID componentid,const char* warename))
    {
        const auto func_res_1 = invoke(IsWillingToBuyFromPlayer, componentid, warename);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsWillingToSellToPlayer(PARAMS(UniverseID componentid,const char* warename))
    {
        const auto func_res_1 = invoke(IsWillingToSellToPlayer, componentid, warename);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json IsZone(PARAMS(const UniverseID componentid))
    {
        const auto func_res_1 = invoke(IsZone, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json MarkIndicatorShown(PARAMS(const UniverseID componentid))
    {
        const auto func_res_1 = invoke(MarkIndicatorShown, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json QueryGameServers(PARAMS())
    {
        const auto func_res_1 = invoke(QueryGameServers);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json QuickDock(PARAMS())
    {
        const auto func_res_1 = invoke(QuickDock);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json QuickMenuAccess(PARAMS(const char* menu))
    {
        const auto func_res_1 = invoke(QuickMenuAccess, menu);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json RemoveAllOrders(PARAMS(UniverseID controllableid))
    {
        const auto func_res_1 = invoke(RemoveAllOrders, controllableid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json RemoveAttackerFromBoardingOperation(PARAMS(UniverseID defensibleboarderid))
    {
        const auto func_res_1 = invoke(RemoveAttackerFromBoardingOperation, defensibleboarderid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json RemoveBuildPlot(PARAMS(UniverseID stationid))
    {
        const auto func_res_1 = invoke(RemoveBuildPlot, stationid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json RemoveCommander2(PARAMS(UniverseID controllableid))
    {
        const auto func_res_1 = invoke(RemoveCommander2, controllableid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json RemoveConstructionPlan(PARAMS(const char* source,const char* id))
    {
        const auto func_res_1 = invoke(RemoveConstructionPlan, source, id);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json RemoveLoadout(PARAMS(const char* source,const char* macroname,const char* localid))
    {
        const auto func_res_1 = invoke(RemoveLoadout, source, macroname, localid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json RemoveOrder(PARAMS(UniverseID controllableid,size_t idx,bool playercancelled,bool checkonly))
    {
        const auto func_res_1 = invoke(RemoveOrder, controllableid, idx, playercancelled, checkonly);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json RemoveOrder2(PARAMS(UniverseID controllableid,size_t idx,bool playercancelled,bool checkonly,bool onlyimmediate))
    {
        const auto func_res_1 = invoke(RemoveOrder2, controllableid, idx, playercancelled, checkonly, onlyimmediate);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json RequestDockAt(PARAMS(UniverseID containerid,bool checkonly))
    {
        const auto func_res_1 = invoke(RequestDockAt, containerid, checkonly);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json RequestShipFromInternalStorage2(PARAMS(UniverseID shipid,bool highpriority,UniverseID refcomponentid))
    {
        const auto func_res_1 = invoke(RequestShipFromInternalStorage2, shipid, highpriority, refcomponentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json ResetResponseToSignalForControllable(PARAMS(const char* signalid,UniverseID controllableid))
    {
        const auto func_res_1 = invoke(ResetResponseToSignalForControllable, signalid, controllableid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json SetActiveFrame(PARAMS(const int frameid))
    {
        const auto func_res_1 = invoke(SetActiveFrame, frameid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json SetActiveMission(PARAMS(MissionID missionid))
    {
        const auto func_res_1 = invoke(SetActiveMission, missionid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json SetAmmoOfWeapon(PARAMS(UniverseID weaponid,const char* newammomacro))
    {
        const auto func_res_1 = invoke(SetAmmoOfWeapon, weaponid, newammomacro);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json SetCommander(PARAMS(UniverseID controllableid,UniverseID commanderid,const char* assignment))
    {
        const auto func_res_1 = invoke(SetCommander, controllableid, commanderid, assignment);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json SetDefaultResponseToSignalForControllable(PARAMS(const char* newresponse,bool ask,const char* signalid,UniverseID controllableid))
    {
        const auto func_res_1 = invoke(SetDefaultResponseToSignalForControllable, newresponse, ask, signalid, controllableid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json SetDefaultResponseToSignalForFaction(PARAMS(const char* newresponse,bool ask,const char* signalid,const char* factionid))
    {
        const auto func_res_1 = invoke(SetDefaultResponseToSignalForFaction, newresponse, ask, signalid, factionid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json SetEntityToPost(PARAMS(UniverseID controllableid,UniverseID entityid,const char* postid))
    {
        const auto func_res_1 = invoke(SetEntityToPost, controllableid, entityid, postid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json SetFrameInteractiveObject(PARAMS(const int frameid,const int objectid))
    {
        const auto func_res_1 = invoke(SetFrameInteractiveObject, frameid, objectid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json SetOrderSyncPointID(PARAMS(UniverseID controllableid,size_t orderidx,uint32_t syncid,bool checkonly))
    {
        const auto func_res_1 = invoke(SetOrderSyncPointID, controllableid, orderidx, syncid, checkonly);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json SetRadarRenderTarget(PARAMS(const char*const rendertargettexture,const UniverseID referencecomponent,const bool mapmode))
    {
        const auto func_res_1 = invoke(SetRadarRenderTarget, rendertargettexture, referencecomponent, mapmode);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json SetRadarRenderTargetOnTarget(PARAMS(const char*const rendertargettexture,const UniverseID focuscomponentid,const UniverseID referencecomponent,const bool mapmode))
    {
        const auto func_res_1 = invoke(SetRadarRenderTargetOnTarget, rendertargettexture, focuscomponentid, referencecomponent, mapmode);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json SetSofttarget(PARAMS(UniverseID componentid,const char*const connectionname))
    {
        const auto func_res_1 = invoke(SetSofttarget, componentid, connectionname);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json SetStationOverviewGraphWare(PARAMS(UniverseID stationid,const char* wareid,bool value))
    {
        const auto func_res_1 = invoke(SetStationOverviewGraphWare, stationid, wareid, value);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json ShouldEditBoxRestoreInteractiveObject(PARAMS(const int editboxid))
    {
        const auto func_res_1 = invoke(ShouldEditBoxRestoreInteractiveObject, editboxid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json ShouldSubordinateGroupDockAtCommander(PARAMS(UniverseID controllableid,int group))
    {
        const auto func_res_1 = invoke(ShouldSubordinateGroupDockAtCommander, controllableid, group);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json ShowGamepadTextInput(PARAMS(const char* description,uint32_t maxchars,const char* existingtext,bool multilines,bool password))
    {
        const auto func_res_1 = invoke(ShowGamepadTextInput, description, maxchars, existingtext, multilines, password);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json ShuffleMapConstructionPlan(PARAMS(UniverseID holomapid,bool checkonly))
    {
        const auto func_res_1 = invoke(ShuffleMapConstructionPlan, holomapid, checkonly);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json StartBoardingOperation(PARAMS(UniverseID defensibletargetid,const char* boarderfactionid))
    {
        const auto func_res_1 = invoke(StartBoardingOperation, defensibletargetid, boarderfactionid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json StopPanMap(PARAMS(UniverseID holomapid))
    {
        const auto func_res_1 = invoke(StopPanMap, holomapid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json StopRotateMap(PARAMS(UniverseID holomapid))
    {
        const auto func_res_1 = invoke(StopRotateMap, holomapid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json TakeShipFromInternalStorage(PARAMS(UniverseID shipid,bool highpriority,bool checkonly))
    {
        const auto func_res_1 = invoke(TakeShipFromInternalStorage, shipid, highpriority, checkonly);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json TeleportPlayerTo(PARAMS(UniverseID controllableid,bool allowcontrolling,bool instant,bool force))
    {
        const auto func_res_1 = invoke(TeleportPlayerTo, controllableid, allowcontrolling, instant, force);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json ToggleAutoPilot(PARAMS(bool checkonly))
    {
        const auto func_res_1 = invoke(ToggleAutoPilot, checkonly);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json TriggerCompSlotAnimation(PARAMS(UniverseID componentid,const char* connectionname,const char* triggername))
    {
        const auto func_res_1 = invoke(TriggerCompSlotAnimation, componentid, connectionname, triggername);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json UpdateAttackerOfBoardingOperation(PARAMS(UniverseID defensibletargetid,UniverseID defensibleboarderid,const char* boarderfactionid,const char* actionid,uint32_t nummarinetiers))
    {
        uint32_t marinetieramounts;
        int32_t marinetierskilllevels;
        const auto func_res_1 = invoke(UpdateAttackerOfBoardingOperation, defensibletargetid, defensibleboarderid, boarderfactionid, actionid, &marinetieramounts, &marinetierskilllevels, nummarinetiers);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"marinetieramounts", marinetieramounts},
                {"marinetierskilllevels", marinetierskilllevels}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json UpdateBoardingOperation(PARAMS(UniverseID defensibletargetid,const char* boarderfactionid,uint32_t approachthreshold,uint32_t insertionthreshold))
    {
        const auto func_res_1 = invoke(UpdateBoardingOperation, defensibletargetid, boarderfactionid, approachthreshold, insertionthreshold);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json CanTeleportPlayerTo(PARAMS(UniverseID controllableid,bool allowcontrolling,bool force))
    {
        const auto func_res_1 = invoke(CanTeleportPlayerTo, controllableid, allowcontrolling, force);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GenerateFactionRelationText(PARAMS(const char* factionid))
    {
        const auto func_res_1 = invoke(GenerateFactionRelationText, factionid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAAOption(PARAMS(bool useconfig))
    {
        const auto func_res_1 = invoke(GetAAOption, useconfig);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetBoardingActionOfAttacker(PARAMS(UniverseID defensibletargetid,UniverseID defensibleboarderid,const char* boarderfactionid))
    {
        const auto func_res_1 = invoke(GetBoardingActionOfAttacker, defensibletargetid, defensibleboarderid, boarderfactionid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetBuildVersionSuffix(PARAMS())
    {
        const auto func_res_1 = invoke(GetBuildVersionSuffix);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetCheckBoxSymbol(PARAMS(const int checkboxid))
    {
        const auto func_res_1 = invoke(GetCheckBoxSymbol, checkboxid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetCompSlotPlayerActionTriggeredConnection(PARAMS(UniverseID componentid,const char* connectionname))
    {
        const auto func_res_1 = invoke(GetCompSlotPlayerActionTriggeredConnection, componentid, connectionname);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetComponentClass(PARAMS(UniverseID componentid))
    {
        const auto func_res_1 = invoke(GetComponentClass, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetComponentName(PARAMS(UniverseID componentid))
    {
        const auto func_res_1 = invoke(GetComponentName, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetCurrentAmmoOfWeapon(PARAMS(UniverseID weaponid))
    {
        const auto func_res_1 = invoke(GetCurrentAmmoOfWeapon, weaponid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetCurrentBoardingPhase(PARAMS(UniverseID defensibletargetid,const char* boarderfactionid))
    {
        const auto func_res_1 = invoke(GetCurrentBoardingPhase, defensibletargetid, boarderfactionid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetCurrentDroneMode(PARAMS(UniverseID defensibleid,const char* dronetype))
    {
        const auto func_res_1 = invoke(GetCurrentDroneMode, defensibleid, dronetype);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetCurrentGPUNiceName(PARAMS())
    {
        const auto func_res_1 = invoke(GetCurrentGPUNiceName);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetCurrentSoundDevice(PARAMS())
    {
        const auto func_res_1 = invoke(GetCurrentSoundDevice);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetCustomGameStartStringProperty(PARAMS(const char* id,const char* propertyid))
    {
        CustomGameStartStringPropertyState state;
        const auto func_res_1 = invoke(GetCustomGameStartStringProperty, id, propertyid, &state);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"state", {
                    {"state", state.state},
                    {"defaultvalue", state.defaultvalue},
                    {"options", state.options}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetDefaultResponseToSignalForControllable(PARAMS(const char* signalid,UniverseID controllableid))
    {
        const auto func_res_1 = invoke(GetDefaultResponseToSignalForControllable, signalid, controllableid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetDefaultResponseToSignalForFaction(PARAMS(const char* signalid,const char* factionid))
    {
        const auto func_res_1 = invoke(GetDefaultResponseToSignalForFaction, signalid, factionid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetDetailmonitorCutsceneKey(PARAMS(uint32_t cutsceneid))
    {
        const auto func_res_1 = invoke(GetDetailmonitorCutsceneKey, cutsceneid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetDropDownStartOption(PARAMS(const int dropdownid))
    {
        const auto func_res_1 = invoke(GetDropDownStartOption, dropdownid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetEditBoxDefaultText(PARAMS(const int editboxid))
    {
        const auto func_res_1 = invoke(GetEditBoxDefaultText, editboxid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetEditBoxDescription(PARAMS(const int editboxid))
    {
        const auto func_res_1 = invoke(GetEditBoxDescription, editboxid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetEntityActiveIcon(PARAMS(const UniverseID componentid))
    {
        const auto func_res_1 = invoke(GetEntityActiveIcon, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetEntityInactiveIcon(PARAMS(const UniverseID componentid))
    {
        const auto func_res_1 = invoke(GetEntityInactiveIcon, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetEntitySelectedIcon(PARAMS(const UniverseID componentid))
    {
        const auto func_res_1 = invoke(GetEntitySelectedIcon, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetEquipmentModPropertyName(PARAMS(const char* wareid))
    {
        const auto func_res_1 = invoke(GetEquipmentModPropertyName, wareid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetFactionNameForTargetMonitorHack(PARAMS(UniverseID componentid))
    {
        const auto func_res_1 = invoke(GetFactionNameForTargetMonitorHack, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetFleetName(PARAMS(UniverseID controllableid))
    {
        const auto func_res_1 = invoke(GetFleetName, controllableid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetLocalizedInputName(PARAMS(uint32_t sourceid,uint32_t codeid))
    {
        const auto func_res_1 = invoke(GetLocalizedInputName, sourceid, codeid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetLocalizedInteractiveNotificationKey(PARAMS())
    {
        const auto func_res_1 = invoke(GetLocalizedInteractiveNotificationKey);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetLocalizedRawMouseButtonName(PARAMS(uint32_t keycodeid))
    {
        const auto func_res_1 = invoke(GetLocalizedRawMouseButtonName, keycodeid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetLocalizedText(PARAMS(uint32_t pageid,uint32_t textid,const char* defaultvalue))
    {
        const auto func_res_1 = invoke(GetLocalizedText, pageid, textid, defaultvalue);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetMacroClass(PARAMS(const char* macroname))
    {
        const auto func_res_1 = invoke(GetMacroClass, macroname);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetMacroMapPositionOnEcliptic(PARAMS(UniverseID holomapid))
    {
        UIPosRot position;
        const auto func_res_1 = invoke(GetMacroMapPositionOnEcliptic, holomapid, &position);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"position", {
                    {"x", position.x},
                    {"y", position.y},
                    {"z", position.z},
                    {"yaw", position.yaw},
                    {"pitch", position.pitch},
                    {"roll", position.roll}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetMappedInputName(PARAMS(const char* functionkey))
    {
        const auto func_res_1 = invoke(GetMappedInputName, functionkey);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetMissingConstructionPlanBlueprints(PARAMS(UniverseID containerid,const char* constructionplanid))
    {
        const auto func_res_1 = invoke(GetMissingConstructionPlanBlueprints, containerid, constructionplanid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetMouseOverText(PARAMS(const int widgetid))
    {
        const auto func_res_1 = invoke(GetMouseOverText, widgetid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetObjectIDCode(PARAMS(UniverseID objectid))
    {
        const auto func_res_1 = invoke(GetObjectIDCode, objectid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPersonName(PARAMS(NPCSeed person,UniverseID controllableid))
    {
        const auto func_res_1 = invoke(GetPersonName, person, controllableid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPersonRole(PARAMS(NPCSeed person,UniverseID controllableid))
    {
        const auto func_res_1 = invoke(GetPersonRole, person, controllableid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPersonRoleName(PARAMS(NPCSeed person,UniverseID controllableid))
    {
        const auto func_res_1 = invoke(GetPersonRoleName, person, controllableid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPlayerClothingTheme(PARAMS())
    {
        const auto func_res_1 = invoke(GetPlayerClothingTheme);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPlayerFactionName(PARAMS(bool userawname))
    {
        const auto func_res_1 = invoke(GetPlayerFactionName, userawname);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPlayerName(PARAMS())
    {
        const auto func_res_1 = invoke(GetPlayerName);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPlayerPaintTheme(PARAMS())
    {
        const auto func_res_1 = invoke(GetPlayerPaintTheme);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPlayerShipSize(PARAMS())
    {
        const auto func_res_1 = invoke(GetPlayerShipSize);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPresentModeOption(PARAMS())
    {
        const auto func_res_1 = invoke(GetPresentModeOption);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPurposeName(PARAMS(const char* purposeid))
    {
        const auto func_res_1 = invoke(GetPurposeName, purposeid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetRealComponentClass(PARAMS(UniverseID componentid))
    {
        const auto func_res_1 = invoke(GetRealComponentClass, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetSSROption2(PARAMS())
    {
        const auto func_res_1 = invoke(GetSSROption2);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetSaveLocationName(PARAMS())
    {
        const auto func_res_1 = invoke(GetSaveLocationName);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetShipOrLaserTowerSize(PARAMS(const UniverseID componentid))
    {
        const auto func_res_1 = invoke(GetShipOrLaserTowerSize, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetShipPurpose(PARAMS(const UniverseID componentid))
    {
        const auto func_res_1 = invoke(GetShipPurpose, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetSliderCellSuffix(PARAMS(const int slidercellid))
    {
        const auto func_res_1 = invoke(GetSliderCellSuffix, slidercellid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetSliderCellText(PARAMS(const int slidercellid))
    {
        const auto func_res_1 = invoke(GetSliderCellText, slidercellid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetSlotSize(PARAMS(UniverseID defensibleid,UniverseID moduleid,const char* macroname,bool ismodule,const char* upgradetypename,size_t slot))
    {
        const auto func_res_1 = invoke(GetSlotSize, defensibleid, moduleid, macroname, ismodule, upgradetypename, slot);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetSoftwareMaxCompatibleVersion(PARAMS(UniverseID controllableid,const char* macroname,const char* softwarename))
    {
        const auto func_res_1 = invoke(GetSoftwareMaxCompatibleVersion, controllableid, macroname, softwarename);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetSteamID(PARAMS())
    {
        const auto func_res_1 = invoke(GetSteamID);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetSubordinateGroupAssignment(PARAMS(UniverseID controllableid,int group))
    {
        const auto func_res_1 = invoke(GetSubordinateGroupAssignment, controllableid, group);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetTableBackgroundID(PARAMS(const int tableid))
    {
        const auto func_res_1 = invoke(GetTableBackgroundID, tableid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetTextureQualityOption(PARAMS())
    {
        const auto func_res_1 = invoke(GetTextureQualityOption);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetTobiiMode(PARAMS())
    {
        const auto func_res_1 = invoke(GetTobiiMode);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetTrackerNameOption(PARAMS())
    {
        const auto func_res_1 = invoke(GetTrackerNameOption);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetTrackerSDKOption(PARAMS())
    {
        const auto func_res_1 = invoke(GetTrackerSDKOption);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetTurretGroupMode2(PARAMS(UniverseID defensibleid,UniverseID contextid,const char* path,const char* group))
    {
        const auto func_res_1 = invoke(GetTurretGroupMode2, defensibleid, contextid, path, group);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetUpgradeSlotCurrentMacro(PARAMS(UniverseID objectid,UniverseID moduleid,const char* upgradetypename,size_t slot))
    {
        const auto func_res_1 = invoke(GetUpgradeSlotCurrentMacro, objectid, moduleid, upgradetypename, slot);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetVirtualUpgradeSlotCurrentMacro(PARAMS(UniverseID defensibleid,const char* upgradetypename,size_t slot))
    {
        const auto func_res_1 = invoke(GetVirtualUpgradeSlotCurrentMacro, defensibleid, upgradetypename, slot);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetWeaponMode(PARAMS(UniverseID weaponid))
    {
        const auto func_res_1 = invoke(GetWeaponMode, weaponid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json RequestDockAtReason(PARAMS(UniverseID containerid,bool checkonly))
    {
        const auto func_res_1 = invoke(RequestDockAtReason, containerid, checkonly);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json UndockPlayerShip(PARAMS(bool checkonly))
    {
        const auto func_res_1 = invoke(UndockPlayerShip, checkonly);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetBuildProcessorEstimatedTimeLeft(PARAMS(UniverseID buildprocessorid))
    {
        const auto func_res_1 = invoke(GetBuildProcessorEstimatedTimeLeft, buildprocessorid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetBuildTaskDuration(PARAMS(UniverseID containerid,BuildTaskID id))
    {
        const auto func_res_1 = invoke(GetBuildTaskDuration, containerid, id);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetContainerWareConsumption(PARAMS(UniverseID containerid,const char* wareid,bool ignorestate))
    {
        const auto func_res_1 = invoke(GetContainerWareConsumption, containerid, wareid, ignorestate);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetContainerWareProduction(PARAMS(UniverseID containerid,const char* wareid,bool ignorestate))
    {
        const auto func_res_1 = invoke(GetContainerWareProduction, containerid, wareid, ignorestate);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetCurrentGameTime(PARAMS())
    {
        const auto func_res_1 = invoke(GetCurrentGameTime);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAdaptiveSamplingOption(PARAMS())
    {
        const auto func_res_1 = invoke(GetAdaptiveSamplingOption);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetCockpitCameraScaleOption(PARAMS())
    {
        const auto func_res_1 = invoke(GetCockpitCameraScaleOption);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetContainerBuildPriceFactor(PARAMS(UniverseID containerid))
    {
        const auto func_res_1 = invoke(GetContainerBuildPriceFactor, containerid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetContainerGlobalPriceFactor(PARAMS(UniverseID containerid))
    {
        const auto func_res_1 = invoke(GetContainerGlobalPriceFactor, containerid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetCurrentBuildProgress(PARAMS(UniverseID containerid))
    {
        const auto func_res_1 = invoke(GetCurrentBuildProgress, containerid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetDefensibleLoadoutLevel(PARAMS(UniverseID defensibleid))
    {
        const auto func_res_1 = invoke(GetDefensibleLoadoutLevel, defensibleid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPlayerGlobalLoadoutLevel(PARAMS())
    {
        const auto func_res_1 = invoke(GetPlayerGlobalLoadoutLevel);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetRectangleTargetElementExtents(PARAMS(const int posid))
    {
        const auto func_res_1 = invoke(GetRectangleTargetElementExtents, posid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetRemainingOxygen(PARAMS())
    {
        const auto func_res_1 = invoke(GetRemainingOxygen);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetResourceBoxSize(PARAMS())
    {
        const auto func_res_1 = invoke(GetResourceBoxSize);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetScanProgress(PARAMS())
    {
        const auto func_res_1 = invoke(GetScanProgress);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetShieldHullBarHullPercent(PARAMS(const int shieldhullbarid))
    {
        const auto func_res_1 = invoke(GetShieldHullBarHullPercent, shieldhullbarid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetShieldHullBarShieldPercent(PARAMS(const int shieldhullbarid))
    {
        const auto func_res_1 = invoke(GetShieldHullBarShieldPercent, shieldhullbarid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetStatusBarCurrentValue(PARAMS(const int statusbarid))
    {
        const auto func_res_1 = invoke(GetStatusBarCurrentValue, statusbarid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetStatusBarMaxValue(PARAMS(const int statusbarid))
    {
        const auto func_res_1 = invoke(GetStatusBarMaxValue, statusbarid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetStatusBarStartValue(PARAMS(const int statusbarid))
    {
        const auto func_res_1 = invoke(GetStatusBarStartValue, statusbarid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetTextHeight(PARAMS(const char*const text,const char*const fontname,const uint32_t fontsize,const float wordwrapwidth))
    {
        const auto func_res_1 = invoke(GetTextHeight, text, fontname, fontsize, wordwrapwidth);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetTextWidth(PARAMS(const char*const text,const char*const fontname,const float fontsize))
    {
        const auto func_res_1 = invoke(GetTextWidth, text, fontname, fontsize);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetTobiiAngleFactor(PARAMS())
    {
        const auto func_res_1 = invoke(GetTobiiAngleFactor);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetTobiiDeadzoneAngle(PARAMS())
    {
        const auto func_res_1 = invoke(GetTobiiDeadzoneAngle);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetTobiiDeadzonePosition(PARAMS())
    {
        const auto func_res_1 = invoke(GetTobiiDeadzonePosition);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetTobiiGazeAngleFactor(PARAMS())
    {
        const auto func_res_1 = invoke(GetTobiiGazeAngleFactor);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetTobiiGazeDeadzone(PARAMS())
    {
        const auto func_res_1 = invoke(GetTobiiGazeDeadzone);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetTobiiHeadPositionFactor(PARAMS())
    {
        const auto func_res_1 = invoke(GetTobiiHeadPositionFactor);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetUIScale(PARAMS(const bool scalewithresolution))
    {
        const auto func_res_1 = invoke(GetUIScale, scalewithresolution);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetUIScaleFactor(PARAMS())
    {
        const auto func_res_1 = invoke(GetUIScaleFactor);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetConfigSetting(PARAMS(const char*const setting))
    {
        const auto func_res_1 = invoke(GetConfigSetting, setting);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNotificationID(PARAMS(const size_t num))
    {
        const auto func_res_1 = invoke(GetNotificationID, num);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPriorityMissiontargetPOSID(PARAMS())
    {
        const auto func_res_1 = invoke(GetPriorityMissiontargetPOSID);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetTableNextConnectedTable(PARAMS(const int tableid))
    {
        const auto func_res_1 = invoke(GetTableNextConnectedTable, tableid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetTableNextHorizontalConnectedTable(PARAMS(const int tableid))
    {
        const auto func_res_1 = invoke(GetTableNextHorizontalConnectedTable, tableid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetTablePreviousConnectedTable(PARAMS(const int tableid))
    {
        const auto func_res_1 = invoke(GetTablePreviousConnectedTable, tableid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetTablePreviousHorizontalConnectedTable(PARAMS(const int tableid))
    {
        const auto func_res_1 = invoke(GetTablePreviousHorizontalConnectedTable, tableid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetVRVivePointerHand(PARAMS())
    {
        const auto func_res_1 = invoke(GetVRVivePointerHand);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetContainerBuyLimit(PARAMS(UniverseID containerid,const char* wareid))
    {
        const auto func_res_1 = invoke(GetContainerBuyLimit, containerid, wareid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetContainerSellLimit(PARAMS(UniverseID containerid,const char* wareid))
    {
        const auto func_res_1 = invoke(GetContainerSellLimit, containerid, wareid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetCurrentLanguage(PARAMS())
    {
        const auto func_res_1 = invoke(GetCurrentLanguage);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetEditBoxTextOffsetY(PARAMS(const int editboxid))
    {
        const auto func_res_1 = invoke(GetEditBoxTextOffsetY, editboxid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetEntityCombinedSkill(PARAMS(UniverseID entityid,const char* role,const char* postid))
    {
        const auto func_res_1 = invoke(GetEntityCombinedSkill, entityid, role, postid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPersonCombinedSkill(PARAMS(UniverseID controllableid,NPCSeed person,const char* role,const char* postid))
    {
        const auto func_res_1 = invoke(GetPersonCombinedSkill, controllableid, person, role, postid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPersonTier(PARAMS(NPCSeed npc,const char* role,UniverseID controllableid))
    {
        const auto func_res_1 = invoke(GetPersonTier, npc, role, controllableid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetRequestedLanguage(PARAMS())
    {
        const auto func_res_1 = invoke(GetRequestedLanguage);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetShipCombinedSkill(PARAMS(UniverseID shipid))
    {
        const auto func_res_1 = invoke(GetShipCombinedSkill, shipid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetSliderCellAccuracyOverride(PARAMS(const int slidercellid))
    {
        const auto func_res_1 = invoke(GetSliderCellAccuracyOverride, slidercellid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetUIRelation(PARAMS(const char* fromfactionid,const char* tofactionid))
    {
        const auto func_res_1 = invoke(GetUIRelation, fromfactionid, tofactionid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetBuildPlotPayment(PARAMS(UniverseID stationid))
    {
        bool positionchanged;
        const auto func_res_1 = invoke(GetBuildPlotPayment, stationid, &positionchanged);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"positionchanged", positionchanged}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetBuildWarePrice(PARAMS(UniverseID containerid,const char* warename))
    {
        const auto func_res_1 = invoke(GetBuildWarePrice, containerid, warename);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetBuilderHiringFee(PARAMS())
    {
        const auto func_res_1 = invoke(GetBuilderHiringFee);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetCreditsDueFromPlayerTrades(PARAMS())
    {
        const auto func_res_1 = invoke(GetCreditsDueFromPlayerTrades);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetCustomGameStartMoneyProperty(PARAMS(const char* id,const char* propertyid))
    {
        CustomGameStartMoneyPropertyState state;
        const auto func_res_1 = invoke(GetCustomGameStartMoneyProperty, id, propertyid, &state);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"state", {
                    {"state", state.state},
                    {"defaultvalue", state.defaultvalue},
                    {"minvalue", state.minvalue},
                    {"maxvalue", state.maxvalue}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetRepairPrice(PARAMS(UniverseID componenttorepairid,UniverseID containerid))
    {
        const auto func_res_1 = invoke(GetRepairPrice, componenttorepairid, containerid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetSupplyBudget(PARAMS(UniverseID containerid))
    {
        const auto func_res_1 = invoke(GetSupplyBudget, containerid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetBuildMapConstructionPlan(PARAMS(UniverseID holomapid,UniverseID defensibleid,bool usestoredplan))
    {
        uint32_t resultlen = 32767;
        std::vector<UIConstructionPlanEntry> result;
        result.resize(resultlen);
        const auto func_res_1 = invoke(GetBuildMapConstructionPlan, holomapid, defensibleid, usestoredplan, result.data(), resultlen);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"idx", v.idx},
                    {"macroid", v.macroid},
                    {"componentid", v.componentid},
                    {"offset", {"x", v.offset.x},{"y", v.offset.y},{"z", v.offset.z},{"yaw", v.offset.yaw},{"pitch", v.offset.pitch},{"roll", v.offset.roll}},
                    {"connectionid", v.connectionid},
                    {"predecessoridx", v.predecessoridx},
                    {"predecessorconnectionid", v.predecessorconnectionid},
                    {"isfixed", v.isfixed}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetConstructionMapVenturePlatform(PARAMS(UniverseID holomapid,size_t venturedockidx))
    {
        const auto func_res_1 = invoke(GetConstructionMapVenturePlatform, holomapid, venturedockidx);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumAcceptedMissions(PARAMS())
    {
        const auto func_res_1 = invoke(GetNumAcceptedMissions);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumBuildMapConstructionPlan(PARAMS(UniverseID holomapid,bool usestoredplan))
    {
        const auto func_res_1 = invoke(GetNumBuildMapConstructionPlan, holomapid, usestoredplan);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumNotifications(PARAMS())
    {
        const auto func_res_1 = invoke(GetNumNotifications);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumPlannedStationModules(PARAMS(UniverseID defensibleid,bool includeall))
    {
        const auto func_res_1 = invoke(GetNumPlannedStationModules, defensibleid, includeall);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumPrimaryWeapons(PARAMS())
    {
        const auto func_res_1 = invoke(GetNumPrimaryWeapons);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumSecondaryWeapons(PARAMS())
    {
        const auto func_res_1 = invoke(GetNumSecondaryWeapons);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumTradeComputerOrders(PARAMS(UniverseID controllableid))
    {
        const auto func_res_1 = invoke(GetNumTradeComputerOrders, controllableid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumTurretSlots(PARAMS())
    {
        const auto func_res_1 = invoke(GetNumTurretSlots);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumTurrets(PARAMS())
    {
        const auto func_res_1 = invoke(GetNumTurrets);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumUpgradeSlots(PARAMS(UniverseID destructibleid,const char* macroname,const char* upgradetypename))
    {
        const auto func_res_1 = invoke(GetNumUpgradeSlots, destructibleid, macroname, upgradetypename);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumVirtualUpgradeSlots(PARAMS(UniverseID objectid,const char* macroname,const char* upgradetypename))
    {
        const auto func_res_1 = invoke(GetNumVirtualUpgradeSlots, objectid, macroname, upgradetypename);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumWeaponSlots(PARAMS())
    {
        const auto func_res_1 = invoke(GetNumWeaponSlots);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPlannedStationModules(PARAMS(UniverseID defensibleid,bool includeall))
    {
        uint32_t resultlen = 32767;
        std::vector<UIConstructionPlanEntry> result;
        result.resize(resultlen);
        const auto func_res_1 = invoke(GetPlannedStationModules, result.data(), resultlen, defensibleid, includeall);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"idx", v.idx},
                    {"macroid", v.macroid},
                    {"componentid", v.componentid},
                    {"offset", {"x", v.offset.x},{"y", v.offset.y},{"z", v.offset.z},{"yaw", v.offset.yaw},{"pitch", v.offset.pitch},{"roll", v.offset.roll}},
                    {"connectionid", v.connectionid},
                    {"predecessoridx", v.predecessoridx},
                    {"predecessorconnectionid", v.predecessorconnectionid},
                    {"isfixed", v.isfixed}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetSelectedBuildMapEntry(PARAMS(UniverseID holomapid))
    {
        const auto func_res_1 = invoke(GetSelectedBuildMapEntry, holomapid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetTobiiGazeFilterStrength(PARAMS())
    {
        const auto func_res_1 = invoke(GetTobiiGazeFilterStrength);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetTobiiHeadFilterStrength(PARAMS())
    {
        const auto func_res_1 = invoke(GetTobiiHeadFilterStrength);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json CreateOrder(PARAMS(UniverseID controllableid,const char* orderid,bool defaultorder))
    {
        uint32_t func_res_1 = invoke(CreateOrder, controllableid, orderid, defaultorder);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json CreateOrder2(PARAMS(UniverseID controllableid,const char* orderid,bool defaultorder,bool isoverride))
    {
        uint32_t func_res_1 = invoke(CreateOrder2, controllableid, orderid, defaultorder, isoverride);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetActivePrimaryWeaponGroup(PARAMS())
    {
        uint32_t func_res_1 = invoke(GetActivePrimaryWeaponGroup);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetActiveSecondaryWeaponGroup(PARAMS())
    {
        uint32_t func_res_1 = invoke(GetActiveSecondaryWeaponGroup);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAllBlacklists(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<BlacklistID> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetAllBlacklists, result.data(), resultlen);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAllBoardingBehaviours(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<BoardingBehaviour> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetAllBoardingBehaviours, result.data(), resultlen);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"id", v.id},
                    {"text", v.text}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAllBoardingPhases(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<BoardingPhase> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetAllBoardingPhases, result.data(), resultlen);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"id", v.id},
                    {"text", v.text}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAllControlPosts(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<ControlPostInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetAllControlPosts, result.data(), resultlen);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"id", v.id},
                    {"name", v.name}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAllCountermeasures(PARAMS(UniverseID defensibleid))
    {
        uint32_t resultlen = 32767;
        std::vector<AmmoData> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetAllCountermeasures, result.data(), resultlen, defensibleid);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"macro", v.macro},
                    {"ware", v.ware},
                    {"amount", v.amount},
                    {"capacity", v.capacity}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAllEquipment(PARAMS(bool playerblueprint))
    {
        uint32_t resultlen = 32767;
        std::vector<EquipmentWareInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetAllEquipment, result.data(), resultlen, playerblueprint);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"type", v.type},
                    {"ware", v.ware},
                    {"macro", v.macro},
                    {"amount", v.amount}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAllEquipmentModProperties(PARAMS(const char* equipmentmodclass))
    {
        uint32_t resultlen = 32767;
        std::vector<EquipmentModPropertyInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetAllEquipmentModProperties, result.data(), resultlen, equipmentmodclass);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"id", v.id},
                    {"name", v.name},
                    {"description", v.description},
                    {"propdatatype", v.propdatatype},
                    {"basevalue", v.basevalue},
                    {"poseffect", v.poseffect}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAllFactionShips(PARAMS(const char* factionid))
    {
        uint32_t resultlen = 32767;
        std::vector<UniverseID> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetAllFactionShips, result.data(), resultlen, factionid);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAllFactionStations(PARAMS(const char* factionid))
    {
        uint32_t resultlen = 32767;
        std::vector<UniverseID> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetAllFactionStations, result.data(), resultlen, factionid);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAllFactions(PARAMS(bool includehidden))
    {
        uint32_t resultlen = 32767;
        std::vector<const char*> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetAllFactions, result.data(), resultlen, includehidden);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAllInventoryBombs(PARAMS(UniverseID entityid))
    {
        uint32_t resultlen = 32767;
        std::vector<AmmoData> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetAllInventoryBombs, result.data(), resultlen, entityid);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"macro", v.macro},
                    {"ware", v.ware},
                    {"amount", v.amount},
                    {"capacity", v.capacity}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAllLaserTowers(PARAMS(UniverseID defensibleid))
    {
        uint32_t resultlen = 32767;
        std::vector<AmmoData> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetAllLaserTowers, result.data(), resultlen, defensibleid);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"macro", v.macro},
                    {"ware", v.ware},
                    {"amount", v.amount},
                    {"capacity", v.capacity}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAllMines(PARAMS(UniverseID defensibleid))
    {
        uint32_t resultlen = 32767;
        std::vector<AmmoData> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetAllMines, result.data(), resultlen, defensibleid);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"macro", v.macro},
                    {"ware", v.ware},
                    {"amount", v.amount},
                    {"capacity", v.capacity}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAllMissiles(PARAMS(UniverseID defensibleid))
    {
        uint32_t resultlen = 32767;
        std::vector<AmmoData> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetAllMissiles, result.data(), resultlen, defensibleid);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"macro", v.macro},
                    {"ware", v.ware},
                    {"amount", v.amount},
                    {"capacity", v.capacity}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAllModuleSets(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<UIModuleSet> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetAllModuleSets, result.data(), resultlen);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"id", v.id},
                    {"name", v.name}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAllNavBeacons(PARAMS(UniverseID defensibleid))
    {
        uint32_t resultlen = 32767;
        std::vector<AmmoData> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetAllNavBeacons, result.data(), resultlen, defensibleid);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"macro", v.macro},
                    {"ware", v.ware},
                    {"amount", v.amount},
                    {"capacity", v.capacity}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAllRaces(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<RaceInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetAllRaces, result.data(), resultlen);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"id", v.id},
                    {"name", v.name},
                    {"shortname", v.shortname},
                    {"description", v.description},
                    {"icon", v.icon}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAllResourceProbes(PARAMS(UniverseID defensibleid))
    {
        uint32_t resultlen = 32767;
        std::vector<AmmoData> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetAllResourceProbes, result.data(), resultlen, defensibleid);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"macro", v.macro},
                    {"ware", v.ware},
                    {"amount", v.amount},
                    {"capacity", v.capacity}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAllResponsesToSignal(PARAMS(const char* signalid))
    {
        uint32_t resultlen = 32767;
        std::vector<ResponseInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetAllResponsesToSignal, result.data(), resultlen, signalid);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"id", v.id},
                    {"name", v.name},
                    {"description", v.description}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAllRoles(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<PeopleInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetAllRoles, result.data(), resultlen);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"id", v.id},
                    {"name", v.name},
                    {"desc", v.desc},
                    {"amount", v.amount},
                    {"numtiers", v.numtiers},
                    {"canhire", v.canhire}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAllSatellites(PARAMS(UniverseID defensibleid))
    {
        uint32_t resultlen = 32767;
        std::vector<AmmoData> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetAllSatellites, result.data(), resultlen, defensibleid);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"macro", v.macro},
                    {"ware", v.ware},
                    {"amount", v.amount},
                    {"capacity", v.capacity}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAllShipMacros(PARAMS(bool playerblueprint))
    {
        uint32_t resultlen = 32767;
        std::vector<const char*> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetAllShipMacros, result.data(), resultlen, playerblueprint);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAllSignals(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<SignalInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetAllSignals, result.data(), resultlen);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"id", v.id},
                    {"name", v.name},
                    {"description", v.description},
                    {"numresponses", v.numresponses},
                    {"defaultresponse", v.defaultresponse},
                    {"ask", v.ask}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAllUnits(PARAMS(UniverseID defensibleid,bool onlydrones))
    {
        uint32_t resultlen = 32767;
        std::vector<UnitData> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetAllUnits, result.data(), resultlen, defensibleid, onlydrones);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"macro", v.macro},
                    {"category", v.category},
                    {"amount", v.amount}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAllowedWeaponSystems(PARAMS(UniverseID defensibleid,size_t orderidx,bool usedefault))
    {
        uint32_t resultlen = 32767;
        std::vector<WeaponSystemInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetAllowedWeaponSystems, result.data(), resultlen, defensibleid, orderidx, usedefault);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"id", v.id},
                    {"name", v.name},
                    {"active", v.active}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAmmoStorage(PARAMS(UniverseID defensibleid,const char* ammotype))
    {
        uint32_t resultlen = 32767;
        std::vector<AmmoData> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetAmmoStorage, result.data(), resultlen, defensibleid, ammotype);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"macro", v.macro},
                    {"ware", v.ware},
                    {"amount", v.amount},
                    {"capacity", v.capacity}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAmountOfWareAvailable(PARAMS(const char* wareid,UniverseID productionmoduleid))
    {
        uint32_t func_res_1 = invoke(GetAmountOfWareAvailable, wareid, productionmoduleid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAssignedConstructionVessels(PARAMS(UniverseID containerid))
    {
        uint32_t resultlen = 32767;
        std::vector<UniverseID> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetAssignedConstructionVessels, result.data(), resultlen, containerid);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAttackersOfBoardingOperation(PARAMS(UniverseID defensibletargetid,const char* boarderfactionid))
    {
        uint32_t resultlen = 32767;
        std::vector<UniverseID> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetAttackersOfBoardingOperation, result.data(), resultlen, defensibletargetid, boarderfactionid);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAvailableClothingThemes(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<UIClothingTheme> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetAvailableClothingThemes, result.data(), resultlen);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"ID", v.ID},
                    {"Name", v.Name},
                    {"RawName", v.RawName}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAvailableEquipment(PARAMS(UniverseID containerid,const char* classid))
    {
        uint32_t resultlen = 32767;
        std::vector<EquipmentWareInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetAvailableEquipment, result.data(), resultlen, containerid, classid);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"type", v.type},
                    {"ware", v.ware},
                    {"macro", v.macro},
                    {"amount", v.amount}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAvailableEquipmentMods(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<UIEquipmentMod> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetAvailableEquipmentMods, result.data(), resultlen);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"Name", v.Name},
                    {"RawName", v.RawName},
                    {"Ware", v.Ware},
                    {"Quality", v.Quality}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAvailableLockboxes(PARAMS(UniverseID entityid))
    {
        uint32_t resultlen = 32767;
        std::vector<const char*> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetAvailableLockboxes, result.data(), resultlen, entityid);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetAvailablePaintThemes(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<UIPaintTheme> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetAvailablePaintThemes, result.data(), resultlen);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"ID", v.ID},
                    {"Name", v.Name},
                    {"RawName", v.RawName},
                    {"Icon", v.Icon}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetBlueprints(PARAMS(const char* set,const char* category,const char* macroname))
    {
        uint32_t resultlen = 32767;
        std::vector<UIBlueprint> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetBlueprints, result.data(), resultlen, set, category, macroname);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"macro", v.macro},
                    {"ware", v.ware},
                    {"productionmethodid", v.productionmethodid}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetBoardingCasualtiesOfTier(PARAMS(int32_t marinetierskilllevel,UniverseID defensibletargetid,const char* boarderfactionid))
    {
        uint32_t func_res_1 = invoke(GetBoardingCasualtiesOfTier, marinetierskilllevel, defensibletargetid, boarderfactionid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetBoardingStrengthFromOperation(PARAMS(UniverseID defensibletargetid,const char* boarderfactionid))
    {
        uint32_t func_res_1 = invoke(GetBoardingStrengthFromOperation, defensibletargetid, boarderfactionid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetBoardingStrengthOfControllableTierAmounts(PARAMS(UniverseID controllableid,uint32_t nummarinetiers))
    {
        uint32_t marinetieramounts;
        int32_t marinetierskilllevels;
        uint32_t func_res_1 = invoke(GetBoardingStrengthOfControllableTierAmounts, controllableid, &marinetieramounts, &marinetierskilllevels, nummarinetiers);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"marinetieramounts", marinetieramounts},
                {"marinetierskilllevels", marinetierskilllevels}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetBuildModules(PARAMS(UniverseID containerid))
    {
        uint32_t resultlen = 32767;
        std::vector<UniverseID> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetBuildModules, result.data(), resultlen, containerid);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetBuildSequenceResources(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<UIWareInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetBuildSequenceResources, result.data(), resultlen);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"ware", v.ware},
                    {"macro", v.macro},
                    {"amount", v.amount}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetBuildTasks(PARAMS(UniverseID containerid,UniverseID buildmoduleid,bool isinprogress,bool includeupgrade))
    {
        uint32_t resultlen = 32767;
        std::vector<BuildTaskInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetBuildTasks, result.data(), resultlen, containerid, buildmoduleid, isinprogress, includeupgrade);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"id", v.id},
                    {"buildingcontainer", v.buildingcontainer},
                    {"component", v.component},
                    {"macro", v.macro},
                    {"factionid", v.factionid},
                    {"buildercomponent", v.buildercomponent},
                    {"price", v.price},
                    {"ismissingresources", v.ismissingresources},
                    {"queueposition", v.queueposition}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetCargo(PARAMS(UniverseID containerid,const char* tags))
    {
        uint32_t resultlen = 32767;
        std::vector<UIWareInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetCargo, result.data(), resultlen, containerid, tags);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"ware", v.ware},
                    {"macro", v.macro},
                    {"amount", v.amount}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetCargoStatistics(PARAMS(size_t numdatapoints))
    {
        uint32_t resultlen = 32767;
        std::vector<UICargoStat> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetCargoStatistics, result.data(), resultlen, numdatapoints);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"wareid", v.wareid},
                    {"data", {"time", v.data->time},{"amount", v.data->amount}},
                    {"numdata", v.numdata}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetCargoTransportTypes(PARAMS(UniverseID containerid,bool merge,bool aftertradeorders))
    {
        uint32_t resultlen = 32767;
        std::vector<StorageInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetCargoTransportTypes, result.data(), resultlen, containerid, merge, aftertradeorders);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"name", v.name},
                    {"transport", v.transport},
                    {"spaceused", v.spaceused},
                    {"capacity", v.capacity}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetCloseOnUnhandledClickFrames(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<int> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetCloseOnUnhandledClickFrames, result.data(), resultlen);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetConstructionPlanInvalidPatches(PARAMS(const char* constructionplanid))
    {
        uint32_t resultlen = 32767;
        std::vector<InvalidPatchInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetConstructionPlanInvalidPatches, result.data(), resultlen, constructionplanid);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"id", v.id},
                    {"name", v.name},
                    {"state", v.state},
                    {"requiredversion", v.requiredversion},
                    {"installedversion", v.installedversion}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetConstructionPlans(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<UIConstructionPlan> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetConstructionPlans, result.data(), resultlen);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"name", v.name},
                    {"id", v.id},
                    {"source", v.source},
                    {"deleteable", v.deleteable}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetContainerAllowedBuildFactions(PARAMS(UniverseID containerid))
    {
        uint32_t resultlen = 32767;
        std::vector<const char*> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetContainerAllowedBuildFactions, result.data(), resultlen, containerid);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetContainerBuildResources(PARAMS(UniverseID containerid))
    {
        uint32_t resultlen = 32767;
        std::vector<const char*> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetContainerBuildResources, result.data(), resultlen, containerid);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetContainerBuilderMacros(PARAMS(UniverseID containerid))
    {
        uint32_t resultlen = 32767;
        std::vector<const char*> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetContainerBuilderMacros, result.data(), resultlen, containerid);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetContainerStockLimitOverrides(PARAMS(UniverseID containerid))
    {
        uint32_t resultlen = 32767;
        std::vector<UIWareInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetContainerStockLimitOverrides, result.data(), resultlen, containerid);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"ware", v.ware},
                    {"macro", v.macro},
                    {"amount", v.amount}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetContainerWareReservations(PARAMS(UniverseID containerid))
    {
        uint32_t resultlen = 32767;
        std::vector<WareReservationInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetContainerWareReservations, result.data(), resultlen, containerid);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"reserverid", v.reserverid},
                    {"ware", v.ware},
                    {"amount", v.amount},
                    {"isbuyreservation", v.isbuyreservation},
                    {"eta", v.eta}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetCurrentMissionOffers(PARAMS(bool showninbbs))
    {
        uint32_t resultlen = 32767;
        std::vector<uint64_t> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetCurrentMissionOffers, result.data(), resultlen, showninbbs);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetCurrentVentureShips(PARAMS(UniverseID ventureplatformid))
    {
        uint32_t resultlen = 32767;
        std::vector<UniverseID> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetCurrentVentureShips, result.data(), resultlen, ventureplatformid);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetCustomGameStartBlueprintDefaultProperty(PARAMS(const char* id,const char* propertyid))
    {
        uint32_t resultlen = 32767;
        std::vector<CustomGameStartBlueprint> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetCustomGameStartBlueprintDefaultProperty, result.data(), resultlen, id, propertyid);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"ware", v.ware}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetCustomGameStartBlueprintProperty(PARAMS(const char* id,const char* propertyid))
    {
        uint32_t resultlen = 32767;
        std::vector<CustomGameStartBlueprint> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetCustomGameStartBlueprintProperty, result.data(), resultlen, id, propertyid);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"ware", v.ware}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetCustomGameStartEncyclopediaProperty(PARAMS(const char* id,const char* propertyid))
    {
        uint32_t resultlen = 32767;
        std::vector<CustomGameStartEncyclopediaEntry> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetCustomGameStartEncyclopediaProperty, result.data(), resultlen, id, propertyid);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"library", v.library},
                    {"item", v.item}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetCustomGameStartEncyclopediaPropertyCounts(PARAMS(const char* id,const char* propertyid))
    {
        uint32_t func_res_1 = invoke(GetCustomGameStartEncyclopediaPropertyCounts, id, propertyid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetCustomGameStartInventoryDefaultProperty(PARAMS(const char* id,const char* propertyid))
    {
        uint32_t resultlen = 32767;
        std::vector<CustomGameStartInventory> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetCustomGameStartInventoryDefaultProperty, result.data(), resultlen, id, propertyid);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"ware", v.ware},
                    {"amount", v.amount}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetCustomGameStartInventoryProperty(PARAMS(const char* id,const char* propertyid))
    {
        uint32_t resultlen = 32767;
        std::vector<CustomGameStartInventory> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetCustomGameStartInventoryProperty, result.data(), resultlen, id, propertyid);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"ware", v.ware},
                    {"amount", v.amount}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetCustomGameStartRelationsProperty(PARAMS(const char* id,const char* propertyid))
    {
        uint32_t resultlen = 32767;
        std::vector<CustomGameStartRelationInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetCustomGameStartRelationsProperty, result.data(), resultlen, id, propertyid);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"factionid", v.factionid},
                    {"otherfactionid", v.otherfactionid},
                    {"relation", v.relation}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetCustomGameStartRelationsPropertyCounts(PARAMS(const char* id,const char* propertyid))
    {
        uint32_t func_res_1 = invoke(GetCustomGameStartRelationsPropertyCounts, id, propertyid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetCustomGameStartResearchProperty(PARAMS(const char* id,const char* propertyid))
    {
        uint32_t resultlen = 32767;
        std::vector<const char*> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetCustomGameStartResearchProperty, result.data(), resultlen, id, propertyid);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetCustomGameStartResearchPropertyCounts(PARAMS(const char* id,const char* propertyid))
    {
        uint32_t func_res_1 = invoke(GetCustomGameStartResearchPropertyCounts, id, propertyid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetDamagedSubComponents(PARAMS(UniverseID objectid))
    {
        uint32_t resultlen = 32767;
        std::vector<UniverseID> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetDamagedSubComponents, result.data(), resultlen, objectid);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetDefaultCountermeasureStorageCapacity(PARAMS(const char* macroname))
    {
        uint32_t func_res_1 = invoke(GetDefaultCountermeasureStorageCapacity, macroname);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetDefaultMissileStorageCapacity(PARAMS(const char* macroname))
    {
        uint32_t func_res_1 = invoke(GetDefaultMissileStorageCapacity, macroname);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetDefensibleActiveWeaponGroup(PARAMS(UniverseID defensibleid,bool primary))
    {
        uint32_t func_res_1 = invoke(GetDefensibleActiveWeaponGroup, defensibleid, primary);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetDefensibleDPS(PARAMS(UniverseID defensibleid,bool primary,bool secondary,bool lasers,bool missiles,bool turrets,bool includeheat,bool includeinactive))
    {
        DPSData result;
        uint32_t func_res_1 = invoke(GetDefensibleDPS, &result, defensibleid, primary, secondary, lasers, missiles, turrets, includeheat, includeinactive);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"result", {
                    {"dps", result.dps},
                    {"quadranttextid", result.quadranttextid}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetDefensibleDeployableCapacity(PARAMS(UniverseID defensibleid))
    {
        uint32_t func_res_1 = invoke(GetDefensibleDeployableCapacity, defensibleid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetDockedShips(PARAMS(UniverseID dockingbayorcontainerid,const char* factionid))
    {
        uint32_t resultlen = 32767;
        std::vector<UniverseID> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetDockedShips, result.data(), resultlen, dockingbayorcontainerid, factionid);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetDroneModes(PARAMS(UniverseID defensibleid,const char* dronetype))
    {
        uint32_t resultlen = 32767;
        std::vector<DroneModeInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetDroneModes, result.data(), resultlen, defensibleid, dronetype);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"id", v.id},
                    {"name", v.name},
                    {"possible", v.possible}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetDropDownOptionHeight(PARAMS(const int dropdownid))
    {
        uint32_t func_res_1 = invoke(GetDropDownOptionHeight, dropdownid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetDropDownOptionWidth(PARAMS(const int dropdownid))
    {
        uint32_t func_res_1 = invoke(GetDropDownOptionWidth, dropdownid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetDropDownOptions(PARAMS(const int dropdownid))
    {
        uint32_t resultlen = 32767;
        std::vector<DropDownOption> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetDropDownOptions, result.data(), resultlen, dropdownid);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"id", v.id},
                    {"iconid", v.iconid},
                    {"text", v.text},
                    {"text2", v.text2},
                    {"mouseovertext", v.mouseovertext},
                    {"overrideColor", {"red", v.overrideColor.red},{"green", v.overrideColor.green},{"blue", v.overrideColor.blue},{"alpha", v.overrideColor.alpha}},
                    {"displayRemoveOption", v.displayRemoveOption},
                    {"active", v.active},
                    {"hasOverrideColor", v.hasOverrideColor}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetEditBoxTextOffsetX(PARAMS(const int editboxid))
    {
        uint32_t func_res_1 = invoke(GetEditBoxTextOffsetX, editboxid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetFormationShapes(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<UIFormationInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetFormationShapes, result.data(), resultlen);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"shape", v.shape},
                    {"name", v.name},
                    {"requiredSkill", v.requiredSkill},
                    {"radius", v.radius},
                    {"rollMembers", v.rollMembers},
                    {"rollFormation", v.rollFormation},
                    {"maxShipsPerLine", v.maxShipsPerLine}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetFreeCountermeasureStorageAfterTradeOrders(PARAMS(UniverseID defensibleid))
    {
        uint32_t func_res_1 = invoke(GetFreeCountermeasureStorageAfterTradeOrders, defensibleid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetFreeDeployableStorageAfterTradeOrders(PARAMS(UniverseID defensibleid))
    {
        uint32_t func_res_1 = invoke(GetFreeDeployableStorageAfterTradeOrders, defensibleid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetFreeMissileStorageAfterTradeOrders(PARAMS(UniverseID defensibleid))
    {
        uint32_t func_res_1 = invoke(GetFreeMissileStorageAfterTradeOrders, defensibleid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetFreePeopleCapacity(PARAMS(UniverseID controllableid))
    {
        uint32_t func_res_1 = invoke(GetFreePeopleCapacity, controllableid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetGraphData(PARAMS(const int graphid,const size_t datarecordidx))
    {
        uint32_t resultlen = 32767;
        std::vector<GraphDataPoint> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetGraphData, result.data(), resultlen, graphid, datarecordidx);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"x", v.x},
                    {"y", v.y}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetGraphDataRecords(PARAMS(int graphid))
    {
        uint32_t resultlen = 32767;
        std::vector<GraphDataRecord> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetGraphDataRecords, result.data(), resultlen, graphid);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"MarkerType", v.MarkerType},
                    {"MarkerSize", v.MarkerSize},
                    {"MarkerColor", {"red", v.MarkerColor.red},{"green", v.MarkerColor.green},{"blue", v.MarkerColor.blue},{"alpha", v.MarkerColor.alpha}},
                    {"LineType", v.LineType},
                    {"LineWidth", v.LineWidth},
                    {"LineColor", {"red", v.LineColor.red},{"green", v.LineColor.green},{"blue", v.LineColor.blue},{"alpha", v.LineColor.alpha}},
                    {"NumData", v.NumData},
                    {"Highlighted", v.Highlighted},
                    {"MouseOverText", v.MouseOverText}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetGraphIcons(PARAMS(int graphid))
    {
        uint32_t resultlen = 32767;
        std::vector<GraphIcon> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetGraphIcons, result.data(), resultlen, graphid);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"DataRecordIdx", v.DataRecordIdx},
                    {"DataIdx", v.DataIdx},
                    {"IconID", v.IconID},
                    {"MouseOverText", v.MouseOverText}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetGraphType(PARAMS(const int graphid))
    {
        uint32_t func_res_1 = invoke(GetGraphType, graphid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetHQs(PARAMS(const char* factionid))
    {
        uint32_t resultlen = 32767;
        std::vector<UniverseID> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetHQs, result.data(), resultlen, factionid);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetIllegalToFactions(PARAMS(const char* wareid))
    {
        uint32_t resultlen = 32767;
        std::vector<const char*> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetIllegalToFactions, result.data(), resultlen, wareid);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetInventoryPaintMods(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<UIPaintMod> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetInventoryPaintMods, result.data(), resultlen);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"Name", v.Name},
                    {"RawName", v.RawName},
                    {"Ware", v.Ware},
                    {"Quality", v.Quality},
                    {"Amount", v.Amount}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetLUTMode(PARAMS())
    {
        uint32_t func_res_1 = invoke(GetLUTMode);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetLanguages(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<LanguageInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetLanguages, result.data(), resultlen);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"id", v.id},
                    {"name", v.name},
                    {"warning", v.warning},
                    {"font", v.font},
                    {"voice", v.voice}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetLibraryEntryAliases(PARAMS(const char* librarytypeid,const char* id))
    {
        uint32_t resultlen = 32767;
        std::vector<const char*> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetLibraryEntryAliases, result.data(), resultlen, librarytypeid, id);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetLoadoutCounts(PARAMS(UniverseID defensibleid,const char* macroname,const char* loadoutid))
    {
        UILoadoutCounts result;
        uint32_t func_res_1 = invoke(GetLoadoutCounts, &result, defensibleid, macroname, loadoutid);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"result", {
                    {"numweapons", result.numweapons},
                    {"numturrets", result.numturrets},
                    {"numshields", result.numshields},
                    {"numengines", result.numengines},
                    {"numturretgroups", result.numturretgroups},
                    {"numshieldgroups", result.numshieldgroups},
                    {"numammo", result.numammo},
                    {"numunits", result.numunits},
                    {"numsoftware", result.numsoftware}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetLoadoutInvalidPatches(PARAMS(UniverseID defensibleid,const char* macroname,const char* loadoutid))
    {
        uint32_t resultlen = 32767;
        std::vector<InvalidPatchInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetLoadoutInvalidPatches, result.data(), resultlen, defensibleid, macroname, loadoutid);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"id", v.id},
                    {"name", v.name},
                    {"state", v.state},
                    {"requiredversion", v.requiredversion},
                    {"installedversion", v.installedversion}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetLoadoutsInfo(PARAMS(UniverseID componentid,const char* macroname))
    {
        uint32_t resultlen = 32767;
        std::vector<UILoadoutInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetLoadoutsInfo, result.data(), resultlen, componentid, macroname);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"id", v.id},
                    {"name", v.name},
                    {"iconid", v.iconid},
                    {"deleteable", v.deleteable}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetMacroDeployableCapacity(PARAMS(const char* macroname))
    {
        uint32_t func_res_1 = invoke(GetMacroDeployableCapacity, macroname);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetMacroMissileCapacity(PARAMS(const char* macroname))
    {
        uint32_t func_res_1 = invoke(GetMacroMissileCapacity, macroname);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetMapComponentMissions(PARAMS(UniverseID holomapid,UniverseID componentid))
    {
        uint32_t resultlen = 32767;
        std::vector<MissionID> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetMapComponentMissions, result.data(), resultlen, holomapid, componentid);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetMapRenderedComponents(PARAMS(UniverseID holomapid))
    {
        uint32_t resultlen = 32767;
        std::vector<UniverseID> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetMapRenderedComponents, result.data(), resultlen, holomapid);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetMapSelectedComponents(PARAMS(UniverseID holomapid))
    {
        uint32_t resultlen = 32767;
        std::vector<UniverseID> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetMapSelectedComponents, result.data(), resultlen, holomapid);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetMaxProductionStorage(PARAMS(UniverseID containerid))
    {
        uint32_t resultlen = 32767;
        std::vector<UIWareAmount> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetMaxProductionStorage, result.data(), resultlen, containerid);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"wareid", v.wareid},
                    {"amount", v.amount}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetMessages(PARAMS(size_t start,size_t count,const char* categoryname))
    {
        uint32_t resultlen = 32767;
        std::vector<MessageInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetMessages, result.data(), resultlen, start, count, categoryname);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"id", v.id},
                    {"time", v.time},
                    {"category", v.category},
                    {"title", v.title},
                    {"text", v.text},
                    {"source", v.source},
                    {"sourcecomponent", v.sourcecomponent},
                    {"interaction", v.interaction},
                    {"interactioncomponent", v.interactioncomponent},
                    {"interactiontext", v.interactiontext},
                    {"interactionshorttext", v.interactionshorttext},
                    {"cutscenekey", v.cutscenekey},
                    {"entityname", v.entityname},
                    {"factionname", v.factionname},
                    {"money", v.money},
                    {"bonus", v.bonus},
                    {"highlighted", v.highlighted},
                    {"isread", v.isread}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetMissileCargo(PARAMS(UniverseID containerid))
    {
        uint32_t resultlen = 32767;
        std::vector<UIWareInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetMissileCargo, result.data(), resultlen, containerid);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"ware", v.ware},
                    {"macro", v.macro},
                    {"amount", v.amount}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetMissingBuildResources(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<UIWareInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetMissingBuildResources, result.data(), resultlen);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"ware", v.ware},
                    {"macro", v.macro},
                    {"amount", v.amount}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetMissingLoadoutResources(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<UIWareInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetMissingLoadoutResources, result.data(), resultlen);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"ware", v.ware},
                    {"macro", v.macro},
                    {"amount", v.amount}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetMissionThreadSubMissions(PARAMS(MissionID missionid))
    {
        uint32_t resultlen = 32767;
        std::vector<MissionID> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetMissionThreadSubMissions, result.data(), resultlen, missionid);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetModuleNeededResources(PARAMS(UniverseID holomapid,size_t cp_idx))
    {
        uint32_t resultlen = 32767;
        std::vector<UIWareInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetModuleNeededResources, result.data(), resultlen, holomapid, cp_idx);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"ware", v.ware},
                    {"macro", v.macro},
                    {"amount", v.amount}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetModuleRecycledResources(PARAMS(UniverseID moduleid))
    {
        uint32_t resultlen = 32767;
        std::vector<UIWareInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetModuleRecycledResources, result.data(), resultlen, moduleid);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"ware", v.ware},
                    {"macro", v.macro},
                    {"amount", v.amount}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetMoonInfo(PARAMS(UniverseID clusterid,uint32_t planetidx))
    {
        uint32_t resultlen = 32767;
        std::vector<UICelestialBodyInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetMoonInfo, result.data(), resultlen, clusterid, planetidx);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"name", v.name},
                    {"typeclass", v.typeclass},
                    {"geology", v.geology},
                    {"atmosphere", v.atmosphere},
                    {"population", v.population},
                    {"settlements", v.settlements},
                    {"nummoons", v.nummoons}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetMouseHUDModeOption(PARAMS())
    {
        uint32_t func_res_1 = invoke(GetMouseHUDModeOption);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNPCAccountStatistics(PARAMS(UniverseID entityid,double starttime,double endtime))
    {
        uint32_t resultlen = 32767;
        std::vector<UIAccountStatData> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetNPCAccountStatistics, result.data(), resultlen, entityid, starttime, endtime);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"time", v.time},
                    {"money", v.money}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNotificationTypes(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<UINotificationType> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetNotificationTypes, result.data(), resultlen);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"id", v.id},
                    {"name", v.name},
                    {"desc", v.desc},
                    {"category", v.category},
                    {"enabled", v.enabled}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumAllBlacklists(PARAMS())
    {
        uint32_t func_res_1 = invoke(GetNumAllBlacklists);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumAllBoardingBehaviours(PARAMS())
    {
        uint32_t func_res_1 = invoke(GetNumAllBoardingBehaviours);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumAllBoardingPhases(PARAMS())
    {
        uint32_t func_res_1 = invoke(GetNumAllBoardingPhases);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumAllControlPosts(PARAMS())
    {
        uint32_t func_res_1 = invoke(GetNumAllControlPosts);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumAllCountermeasures(PARAMS(UniverseID defensibleid))
    {
        uint32_t func_res_1 = invoke(GetNumAllCountermeasures, defensibleid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumAllEquipment(PARAMS(bool playerblueprint))
    {
        uint32_t func_res_1 = invoke(GetNumAllEquipment, playerblueprint);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumAllEquipmentModProperties(PARAMS(const char* equipmentmodclass))
    {
        uint32_t func_res_1 = invoke(GetNumAllEquipmentModProperties, equipmentmodclass);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumAllFactionShips(PARAMS(const char* factionid))
    {
        uint32_t func_res_1 = invoke(GetNumAllFactionShips, factionid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumAllFactionStations(PARAMS(const char* factionid))
    {
        uint32_t func_res_1 = invoke(GetNumAllFactionStations, factionid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumAllFactions(PARAMS(bool includehidden))
    {
        uint32_t func_res_1 = invoke(GetNumAllFactions, includehidden);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumAllInventoryBombs(PARAMS(UniverseID entityid))
    {
        uint32_t func_res_1 = invoke(GetNumAllInventoryBombs, entityid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumAllLaserTowers(PARAMS(UniverseID defensibleid))
    {
        uint32_t func_res_1 = invoke(GetNumAllLaserTowers, defensibleid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumAllMines(PARAMS(UniverseID defensibleid))
    {
        uint32_t func_res_1 = invoke(GetNumAllMines, defensibleid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumAllMissiles(PARAMS(UniverseID defensibleid))
    {
        uint32_t func_res_1 = invoke(GetNumAllMissiles, defensibleid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumAllModuleSets(PARAMS())
    {
        uint32_t func_res_1 = invoke(GetNumAllModuleSets);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumAllNavBeacons(PARAMS(UniverseID defensibleid))
    {
        uint32_t func_res_1 = invoke(GetNumAllNavBeacons, defensibleid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumAllRaces(PARAMS())
    {
        uint32_t func_res_1 = invoke(GetNumAllRaces);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumAllResourceProbes(PARAMS(UniverseID defensibleid))
    {
        uint32_t func_res_1 = invoke(GetNumAllResourceProbes, defensibleid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumAllResponsesToSignal(PARAMS(const char* signalid))
    {
        uint32_t func_res_1 = invoke(GetNumAllResponsesToSignal, signalid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumAllRoles(PARAMS())
    {
        uint32_t func_res_1 = invoke(GetNumAllRoles);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumAllSatellites(PARAMS(UniverseID defensibleid))
    {
        uint32_t func_res_1 = invoke(GetNumAllSatellites, defensibleid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumAllShipMacros(PARAMS(bool playerblueprint))
    {
        uint32_t func_res_1 = invoke(GetNumAllShipMacros, playerblueprint);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumAllSignals(PARAMS())
    {
        uint32_t func_res_1 = invoke(GetNumAllSignals);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumAllUnits(PARAMS(UniverseID defensibleid,bool onlydrones))
    {
        uint32_t func_res_1 = invoke(GetNumAllUnits, defensibleid, onlydrones);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumAllowedWeaponSystems(PARAMS())
    {
        uint32_t func_res_1 = invoke(GetNumAllowedWeaponSystems);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumAmmoStorage(PARAMS(UniverseID defensibleid,const char* ammotype))
    {
        uint32_t func_res_1 = invoke(GetNumAmmoStorage, defensibleid, ammotype);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumAssignedConstructionVessels(PARAMS(UniverseID containerid))
    {
        uint32_t func_res_1 = invoke(GetNumAssignedConstructionVessels, containerid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumAttackersOfBoardingOperation(PARAMS(UniverseID defensibletargetid,const char* boarderfactionid))
    {
        uint32_t func_res_1 = invoke(GetNumAttackersOfBoardingOperation, defensibletargetid, boarderfactionid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumAvailableClothingThemes(PARAMS())
    {
        uint32_t func_res_1 = invoke(GetNumAvailableClothingThemes);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumAvailableEquipment(PARAMS(UniverseID containerid,const char* classid))
    {
        uint32_t func_res_1 = invoke(GetNumAvailableEquipment, containerid, classid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumAvailableEquipmentMods(PARAMS())
    {
        uint32_t func_res_1 = invoke(GetNumAvailableEquipmentMods);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumAvailableLockboxes(PARAMS(UniverseID entityid))
    {
        uint32_t func_res_1 = invoke(GetNumAvailableLockboxes, entityid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumAvailablePaintThemes(PARAMS())
    {
        uint32_t func_res_1 = invoke(GetNumAvailablePaintThemes);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumBlueprints(PARAMS(const char* set,const char* category,const char* macroname))
    {
        uint32_t func_res_1 = invoke(GetNumBlueprints, set, category, macroname);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumBoardingMarinesFromOperation(PARAMS(UniverseID defensibletargetid,const char* boarderfactionid))
    {
        uint32_t func_res_1 = invoke(GetNumBoardingMarinesFromOperation, defensibletargetid, boarderfactionid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumBuildModules(PARAMS(UniverseID containerid))
    {
        uint32_t func_res_1 = invoke(GetNumBuildModules, containerid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumBuildTasks(PARAMS(UniverseID containerid,UniverseID buildmoduleid,bool isinprogress,bool includeupgrade))
    {
        uint32_t func_res_1 = invoke(GetNumBuildTasks, containerid, buildmoduleid, isinprogress, includeupgrade);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumCargo(PARAMS(UniverseID containerid,const char* tags))
    {
        uint32_t func_res_1 = invoke(GetNumCargo, containerid, tags);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumCargoStatistics(PARAMS(UniverseID containerorspaceid,double starttime,double endtime,size_t numdatapoints))
    {
        uint32_t func_res_1 = invoke(GetNumCargoStatistics, containerorspaceid, starttime, endtime, numdatapoints);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumCargoTransportTypes(PARAMS(UniverseID containerid,bool merge))
    {
        uint32_t func_res_1 = invoke(GetNumCargoTransportTypes, containerid, merge);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumCloseOnUnhandledClickFrames(PARAMS())
    {
        uint32_t func_res_1 = invoke(GetNumCloseOnUnhandledClickFrames);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumConstructionMapVenturePlatformDocks(PARAMS(UniverseID holomapid,size_t ventureplatformidx))
    {
        uint32_t func_res_1 = invoke(GetNumConstructionMapVenturePlatformDocks, holomapid, ventureplatformidx);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumConstructionPlans(PARAMS())
    {
        uint32_t func_res_1 = invoke(GetNumConstructionPlans);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumContainedKnownSpaces(PARAMS(UniverseID spaceid))
    {
        uint32_t func_res_1 = invoke(GetNumContainedKnownSpaces, spaceid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumContainedKnownUnreadSpaces(PARAMS(UniverseID spaceid))
    {
        uint32_t func_res_1 = invoke(GetNumContainedKnownUnreadSpaces, spaceid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumContainerAllowedBuildFactions(PARAMS(UniverseID containerid))
    {
        uint32_t func_res_1 = invoke(GetNumContainerAllowedBuildFactions, containerid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumContainerBuildResources(PARAMS(UniverseID containerid))
    {
        uint32_t func_res_1 = invoke(GetNumContainerBuildResources, containerid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumContainerBuilderMacros(PARAMS(UniverseID containerid))
    {
        uint32_t func_res_1 = invoke(GetNumContainerBuilderMacros, containerid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumContainerStockLimitOverrides(PARAMS(UniverseID containerid))
    {
        uint32_t func_res_1 = invoke(GetNumContainerStockLimitOverrides, containerid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumContainerWareReservations(PARAMS(UniverseID containerid))
    {
        uint32_t func_res_1 = invoke(GetNumContainerWareReservations, containerid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumCountermeasures(PARAMS())
    {
        uint32_t func_res_1 = invoke(GetNumCountermeasures);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumCurrentMissionOffers(PARAMS(bool showninbbs))
    {
        uint32_t func_res_1 = invoke(GetNumCurrentMissionOffers, showninbbs);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumDockedShips(PARAMS(UniverseID dockingbayorcontainerid,const char* factionid))
    {
        uint32_t func_res_1 = invoke(GetNumDockedShips, dockingbayorcontainerid, factionid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumDroneModes(PARAMS(UniverseID defensibleid,const char* dronetype))
    {
        uint32_t func_res_1 = invoke(GetNumDroneModes, defensibleid, dronetype);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumDropDownOptions(PARAMS(const int dropdownid))
    {
        uint32_t func_res_1 = invoke(GetNumDropDownOptions, dropdownid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumFormationShapes(PARAMS())
    {
        uint32_t func_res_1 = invoke(GetNumFormationShapes);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumGraphDataRecords(PARAMS(int graphid))
    {
        uint32_t func_res_1 = invoke(GetNumGraphDataRecords, graphid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumGraphIcons(PARAMS(int graphid))
    {
        uint32_t func_res_1 = invoke(GetNumGraphIcons, graphid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumHQs(PARAMS(const char* factionid))
    {
        uint32_t func_res_1 = invoke(GetNumHQs, factionid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumIllegalToFactions(PARAMS(const char* wareid))
    {
        uint32_t func_res_1 = invoke(GetNumIllegalToFactions, wareid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumInventoryPaintMods(PARAMS())
    {
        uint32_t func_res_1 = invoke(GetNumInventoryPaintMods);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumLanguages(PARAMS())
    {
        uint32_t func_res_1 = invoke(GetNumLanguages);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumLibraryEntryAliases(PARAMS(const char* librarytypeid,const char* id))
    {
        uint32_t func_res_1 = invoke(GetNumLibraryEntryAliases, librarytypeid, id);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumLoadoutsInfo(PARAMS(UniverseID componentid,const char* macroname))
    {
        uint32_t func_res_1 = invoke(GetNumLoadoutsInfo, componentid, macroname);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumMapComponentMissions(PARAMS(UniverseID holomapid,UniverseID componentid))
    {
        uint32_t func_res_1 = invoke(GetNumMapComponentMissions, holomapid, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumMapRenderedComponents(PARAMS(UniverseID holomapid))
    {
        uint32_t func_res_1 = invoke(GetNumMapRenderedComponents, holomapid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumMapSelectedComponents(PARAMS(UniverseID holomapid))
    {
        uint32_t func_res_1 = invoke(GetNumMapSelectedComponents, holomapid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumMaxProductionStorage(PARAMS(UniverseID containerid))
    {
        uint32_t func_res_1 = invoke(GetNumMaxProductionStorage, containerid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumMessages(PARAMS(const char* categoryname,bool unknownBool))
    {
        uint32_t func_res_1 = invoke(GetNumMessages, categoryname, unknownBool);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumMissileCargo(PARAMS(UniverseID containerid))
    {
        uint32_t func_res_1 = invoke(GetNumMissileCargo, containerid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumMissingBuildResources2(PARAMS(UniverseID containerid,uint32_t numorders,bool playercase))
    {
        UIBuildOrderList orders;
        uint32_t func_res_1 = invoke(GetNumMissingBuildResources2, containerid, &orders, numorders, playercase);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"orders", {
                    {"shipid", orders.shipid},
                    {"macroname", orders.macroname},
                    {"loadout", {"weapons", {"macro", orders.loadout.weapons->macro},{"upgradetypename", orders.loadout.weapons->upgradetypename},{"slot", orders.loadout.weapons->slot},{"optional", orders.loadout.weapons->optional}},{"numweapons", orders.loadout.numweapons},{"turrets", {"macro", orders.loadout.turrets->macro},{"upgradetypename", orders.loadout.turrets->upgradetypename},{"slot", orders.loadout.turrets->slot},{"optional", orders.loadout.turrets->optional}},{"numturrets", orders.loadout.numturrets},{"shields", {"macro", orders.loadout.shields->macro},{"upgradetypename", orders.loadout.shields->upgradetypename},{"slot", orders.loadout.shields->slot},{"optional", orders.loadout.shields->optional}},{"numshields", orders.loadout.numshields},{"engines", {"macro", orders.loadout.engines->macro},{"upgradetypename", orders.loadout.engines->upgradetypename},{"slot", orders.loadout.engines->slot},{"optional", orders.loadout.engines->optional}},{"numengines", orders.loadout.numengines},{"turretgroups", {"macro", orders.loadout.turretgroups->macro},{"path", orders.loadout.turretgroups->path},{"group", orders.loadout.turretgroups->group},{"count", orders.loadout.turretgroups->count},{"optional", orders.loadout.turretgroups->optional}},{"numturretgroups", orders.loadout.numturretgroups},{"shieldgroups", {"macro", orders.loadout.shieldgroups->macro},{"path", orders.loadout.shieldgroups->path},{"group", orders.loadout.shieldgroups->group},{"count", orders.loadout.shieldgroups->count},{"optional", orders.loadout.shieldgroups->optional}},{"numshieldgroups", orders.loadout.numshieldgroups},{"ammo", {"macro", orders.loadout.ammo->macro},{"amount", orders.loadout.ammo->amount},{"optional", orders.loadout.ammo->optional}},{"numammo", orders.loadout.numammo},{"units", {"macro", orders.loadout.units->macro},{"amount", orders.loadout.units->amount},{"optional", orders.loadout.units->optional}},{"numunits", orders.loadout.numunits},{"software", {"ware", orders.loadout.software->ware}},{"numsoftware", orders.loadout.numsoftware},{"thruster", {"macro", orders.loadout.thruster.macro},{"optional", orders.loadout.thruster.optional}}},
                    {"amount", orders.amount}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumMissingLoadoutResources2(PARAMS(UniverseID containerid,uint32_t numorders,bool playercase))
    {
        UIBuildOrderList orders;
        uint32_t func_res_1 = invoke(GetNumMissingLoadoutResources2, containerid, &orders, numorders, playercase);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"orders", {
                    {"shipid", orders.shipid},
                    {"macroname", orders.macroname},
                    {"loadout", {"weapons", {"macro", orders.loadout.weapons->macro},{"upgradetypename", orders.loadout.weapons->upgradetypename},{"slot", orders.loadout.weapons->slot},{"optional", orders.loadout.weapons->optional}},{"numweapons", orders.loadout.numweapons},{"turrets", {"macro", orders.loadout.turrets->macro},{"upgradetypename", orders.loadout.turrets->upgradetypename},{"slot", orders.loadout.turrets->slot},{"optional", orders.loadout.turrets->optional}},{"numturrets", orders.loadout.numturrets},{"shields", {"macro", orders.loadout.shields->macro},{"upgradetypename", orders.loadout.shields->upgradetypename},{"slot", orders.loadout.shields->slot},{"optional", orders.loadout.shields->optional}},{"numshields", orders.loadout.numshields},{"engines", {"macro", orders.loadout.engines->macro},{"upgradetypename", orders.loadout.engines->upgradetypename},{"slot", orders.loadout.engines->slot},{"optional", orders.loadout.engines->optional}},{"numengines", orders.loadout.numengines},{"turretgroups", {"macro", orders.loadout.turretgroups->macro},{"path", orders.loadout.turretgroups->path},{"group", orders.loadout.turretgroups->group},{"count", orders.loadout.turretgroups->count},{"optional", orders.loadout.turretgroups->optional}},{"numturretgroups", orders.loadout.numturretgroups},{"shieldgroups", {"macro", orders.loadout.shieldgroups->macro},{"path", orders.loadout.shieldgroups->path},{"group", orders.loadout.shieldgroups->group},{"count", orders.loadout.shieldgroups->count},{"optional", orders.loadout.shieldgroups->optional}},{"numshieldgroups", orders.loadout.numshieldgroups},{"ammo", {"macro", orders.loadout.ammo->macro},{"amount", orders.loadout.ammo->amount},{"optional", orders.loadout.ammo->optional}},{"numammo", orders.loadout.numammo},{"units", {"macro", orders.loadout.units->macro},{"amount", orders.loadout.units->amount},{"optional", orders.loadout.units->optional}},{"numunits", orders.loadout.numunits},{"software", {"ware", orders.loadout.software->ware}},{"numsoftware", orders.loadout.numsoftware},{"thruster", {"macro", orders.loadout.thruster.macro},{"optional", orders.loadout.thruster.optional}}},
                    {"amount", orders.amount}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumMissionThreadSubMissions(PARAMS(MissionID missionid))
    {
        uint32_t func_res_1 = invoke(GetNumMissionThreadSubMissions, missionid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumModuleNeededResources(PARAMS(UniverseID holomapid,size_t cp_idx))
    {
        uint32_t func_res_1 = invoke(GetNumModuleNeededResources, holomapid, cp_idx);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumModuleRecycledResources(PARAMS(UniverseID moduleid))
    {
        uint32_t func_res_1 = invoke(GetNumModuleRecycledResources, moduleid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumNotificationTypes(PARAMS())
    {
        uint32_t func_res_1 = invoke(GetNumNotificationTypes);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumObjectsWithSyncPoint(PARAMS(uint32_t syncid,bool onlyreached))
    {
        uint32_t func_res_1 = invoke(GetNumObjectsWithSyncPoint, syncid, onlyreached);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumOrderDefinitions(PARAMS())
    {
        uint32_t func_res_1 = invoke(GetNumOrderDefinitions);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumOrders(PARAMS(UniverseID controllableid))
    {
        uint32_t func_res_1 = invoke(GetNumOrders, controllableid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumPeopleAfterOrders(PARAMS(UniverseID controllableid,int32_t numorders))
    {
        uint32_t func_res_1 = invoke(GetNumPeopleAfterOrders, controllableid, numorders);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumPersonSuitableControlPosts(PARAMS(UniverseID controllableid,UniverseID personcontrollableid,NPCSeed person,bool free))
    {
        uint32_t func_res_1 = invoke(GetNumPersonSuitableControlPosts, controllableid, personcontrollableid, person, free);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumPlannedLimitedModules(PARAMS(const char* constructionplanid))
    {
        uint32_t func_res_1 = invoke(GetNumPlannedLimitedModules, constructionplanid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumPlayerAlertSounds(PARAMS())
    {
        uint32_t func_res_1 = invoke(GetNumPlayerAlertSounds);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumPlayerAlerts(PARAMS())
    {
        uint32_t func_res_1 = invoke(GetNumPlayerAlerts);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumPlayerLogos(PARAMS(bool includestandard,bool includecustom))
    {
        uint32_t func_res_1 = invoke(GetNumPlayerLogos, includestandard, includecustom);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumPlayerShipBuildTasks(PARAMS(bool isinprogress,bool includeupgrade))
    {
        uint32_t func_res_1 = invoke(GetNumPlayerShipBuildTasks, isinprogress, includeupgrade);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumRemovedConstructionPlanModules2(PARAMS(UniverseID holomapid,UniverseID defensibleid,bool usestoredplan,bool checkupgrades))
    {
        uint32_t newIndex;
        uint32_t numChangedIndices;
        uint32_t func_res_1 = invoke(GetNumRemovedConstructionPlanModules2, holomapid, defensibleid, &newIndex, usestoredplan, &numChangedIndices, checkupgrades);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"newIndex", newIndex},
                {"numChangedIndices", numChangedIndices}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumRemovedStationModules(PARAMS(UniverseID defensibleid))
    {
        uint32_t newIndex;
        uint32_t func_res_1 = invoke(GetNumRemovedStationModules, defensibleid, &newIndex);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"newIndex", newIndex}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumRepairResources(PARAMS(UniverseID componenttorepairid))
    {
        uint32_t func_res_1 = invoke(GetNumRepairResources, componenttorepairid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumResearchModules(PARAMS(UniverseID containerid))
    {
        uint32_t func_res_1 = invoke(GetNumResearchModules, containerid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumSectorsByOwner(PARAMS(const char* factionid))
    {
        uint32_t func_res_1 = invoke(GetNumSectorsByOwner, factionid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumShieldGroups(PARAMS(UniverseID defensibleid))
    {
        uint32_t func_res_1 = invoke(GetNumShieldGroups, defensibleid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumSkills(PARAMS())
    {
        uint32_t func_res_1 = invoke(GetNumSkills);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumSoftwarePredecessors(PARAMS(const char* softwarename))
    {
        uint32_t func_res_1 = invoke(GetNumSoftwarePredecessors, softwarename);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumSoftwareSlots(PARAMS(UniverseID controllableid,const char* macroname))
    {
        uint32_t func_res_1 = invoke(GetNumSoftwareSlots, controllableid, macroname);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumSoundDevices(PARAMS())
    {
        uint32_t func_res_1 = invoke(GetNumSoundDevices);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumStationModules(PARAMS(UniverseID stationid,bool includeconstructions,bool includewrecks))
    {
        uint32_t func_res_1 = invoke(GetNumStationModules, stationid, includeconstructions, includewrecks);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumStationOverviewGraphWares(PARAMS(UniverseID stationid))
    {
        bool initialized;
        uint32_t func_res_1 = invoke(GetNumStationOverviewGraphWares, stationid, &initialized);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"initialized", initialized}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumStoredUnits(PARAMS(UniverseID defensibleid,const char* cat,bool virtualammo))
    {
        uint32_t func_res_1 = invoke(GetNumStoredUnits, defensibleid, cat, virtualammo);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumSubComponents(PARAMS(UniverseID containerid))
    {
        uint32_t func_res_1 = invoke(GetNumSubComponents, containerid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumSuitableBuildProcessors(PARAMS(UniverseID containerid,UniverseID objectid,const char* macroname))
    {
        uint32_t func_res_1 = invoke(GetNumSuitableBuildProcessors, containerid, objectid, macroname);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumSuitableControlPosts(PARAMS(UniverseID controllableid,UniverseID entityid,bool free))
    {
        uint32_t func_res_1 = invoke(GetNumSuitableControlPosts, controllableid, entityid, free);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumSupplyOrders(PARAMS(UniverseID containerid,bool defaultorders))
    {
        uint32_t func_res_1 = invoke(GetNumSupplyOrders, containerid, defaultorders);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumTableInitialMultiselectedRows(PARAMS(const int tableid))
    {
        uint32_t func_res_1 = invoke(GetNumTableInitialMultiselectedRows, tableid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumTiersOfRole(PARAMS(const char* role))
    {
        uint32_t func_res_1 = invoke(GetNumTiersOfRole, role);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumTimeline(PARAMS())
    {
        uint32_t func_res_1 = invoke(GetNumTimeline);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumTradeOfferStatistics(PARAMS(UniverseID containerorspaceid,double starttime,double endtime,size_t numdatapoints))
    {
        uint32_t func_res_1 = invoke(GetNumTradeOfferStatistics, containerorspaceid, starttime, endtime, numdatapoints);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumUnavailableUnits(PARAMS(UniverseID defensibleid,const char* cat))
    {
        uint32_t func_res_1 = invoke(GetNumUnavailableUnits, defensibleid, cat);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumUnitCargo(PARAMS(UniverseID containerid,bool onlydrones))
    {
        uint32_t func_res_1 = invoke(GetNumUnitCargo, containerid, onlydrones);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumUnreadLibraryEntries(PARAMS(const char* libraryid))
    {
        uint32_t func_res_1 = invoke(GetNumUnreadLibraryEntries, libraryid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumUpgradeGroups(PARAMS(UniverseID destructibleid,const char* macroname))
    {
        uint32_t func_res_1 = invoke(GetNumUpgradeGroups, destructibleid, macroname);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumUsedLimitedModules(PARAMS(UniverseID excludedstationid))
    {
        uint32_t func_res_1 = invoke(GetNumUsedLimitedModules, excludedstationid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumUsedLimitedModulesFromSubsequence(PARAMS(UniverseID holomapid,size_t cp_idx))
    {
        uint32_t func_res_1 = invoke(GetNumUsedLimitedModulesFromSubsequence, holomapid, cp_idx);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumValidTransporterTargets(PARAMS(UniverseID componentid))
    {
        uint32_t func_res_1 = invoke(GetNumValidTransporterTargets, componentid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumVenturePlatformDocks(PARAMS(UniverseID ventureplatformid))
    {
        uint32_t func_res_1 = invoke(GetNumVenturePlatformDocks, ventureplatformid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumVenturePlatforms(PARAMS(UniverseID defensibleid))
    {
        uint32_t func_res_1 = invoke(GetNumVenturePlatforms, defensibleid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumWareBlueprintOwners(PARAMS(const char* wareid))
    {
        uint32_t func_res_1 = invoke(GetNumWareBlueprintOwners, wareid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumWareSources(PARAMS(const char* wareid))
    {
        uint32_t func_res_1 = invoke(GetNumWareSources, wareid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumWares(PARAMS(const char* tags,bool research,const char* licenceownerid,const char* exclusiontags))
    {
        uint32_t func_res_1 = invoke(GetNumWares, tags, research, licenceownerid, exclusiontags);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetNumWeaponGroupsByWeapon(PARAMS(UniverseID defensibleid,UniverseID weaponid))
    {
        uint32_t func_res_1 = invoke(GetNumWeaponGroupsByWeapon, defensibleid, weaponid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetOrderDefinitions(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<OrderDefinition> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetOrderDefinitions, result.data(), resultlen);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"id", v.id},
                    {"name", v.name},
                    {"icon", v.icon},
                    {"description", v.description},
                    {"category", v.category},
                    {"categoryname", v.categoryname},
                    {"infinite", v.infinite},
                    {"requiredSkill", v.requiredSkill}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetOrders(PARAMS(UniverseID controllableid))
    {
        uint32_t resultlen = 32767;
        std::vector<Order> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetOrders, result.data(), resultlen, controllableid);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"queueidx", v.queueidx},
                    {"state", v.state},
                    {"statename", v.statename},
                    {"orderdef", v.orderdef},
                    {"actualparams", v.actualparams},
                    {"enabled", v.enabled},
                    {"isinfinite", v.isinfinite},
                    {"issyncpointreached", v.issyncpointreached},
                    {"istemporder", v.istemporder}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetOrders2(PARAMS(UniverseID controllableid))
    {
        uint32_t resultlen = 32767;
        std::vector<Order2> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetOrders2, result.data(), resultlen, controllableid);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"queueidx", v.queueidx},
                    {"state", v.state},
                    {"statename", v.statename},
                    {"orderdef", v.orderdef},
                    {"actualparams", v.actualparams},
                    {"enabled", v.enabled},
                    {"isinfinite", v.isinfinite},
                    {"issyncpointreached", v.issyncpointreached},
                    {"istemporder", v.istemporder}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPeople(PARAMS(UniverseID controllableid))
    {
        uint32_t resultlen = 32767;
        std::vector<PeopleInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetPeople, result.data(), resultlen, controllableid);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"id", v.id},
                    {"name", v.name},
                    {"desc", v.desc},
                    {"amount", v.amount},
                    {"numtiers", v.numtiers},
                    {"canhire", v.canhire}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPeopleAfterOrders(PARAMS(UniverseID controllableid,int32_t numorders))
    {
        uint32_t resultlen = 32767;
        std::vector<NPCInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetPeopleAfterOrders, result.data(), resultlen, controllableid, numorders);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"seed", v.seed},
                    {"roleid", v.roleid},
                    {"tierid", v.tierid},
                    {"name", v.name},
                    {"combinedskill", v.combinedskill}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPeopleCapacity(PARAMS(UniverseID controllableid,const char* macroname,bool includecrew))
    {
        uint32_t func_res_1 = invoke(GetPeopleCapacity, controllableid, macroname, includecrew);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPersonSkills(PARAMS(NPCSeed person,UniverseID controllableid))
    {
        Skill result;
        uint32_t func_res_1 = invoke(GetPersonSkills, &result, person, controllableid);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"result", {
                    {"textid", result.textid},
                    {"value", result.value},
                    {"relevance", result.relevance}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPersonSkillsForAssignment(PARAMS(NPCSeed person,UniverseID controllableid,const char* role,const char* postid))
    {
        Skill2 result;
        uint32_t func_res_1 = invoke(GetPersonSkillsForAssignment, &result, person, controllableid, role, postid);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"result", {
                    {"textid", result.textid},
                    {"value", result.value},
                    {"relevance", result.relevance}
                }}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPersonSuitableControlPosts(PARAMS(UniverseID controllableid,UniverseID personcontrollableid,NPCSeed person,bool free))
    {
        uint32_t resultlen = 32767;
        std::vector<ControlPostInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetPersonSuitableControlPosts, result.data(), resultlen, controllableid, personcontrollableid, person, free);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"id", v.id},
                    {"name", v.name}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPlannedLimitedModules(PARAMS(const char* constructionplanid))
    {
        uint32_t resultlen = 32767;
        std::vector<UIMacroCount> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetPlannedLimitedModules, result.data(), resultlen, constructionplanid);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"macro", v.macro},
                    {"amount", v.amount}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPlayerAlertSounds(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<SoundInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetPlayerAlertSounds, result.data(), resultlen);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"id", v.id},
                    {"name", v.name}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPlayerAlerts(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<PlayerAlertInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetPlayerAlerts, result.data(), resultlen);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"index", v.index},
                    {"interval", v.interval},
                    {"repeats", v.repeats},
                    {"muted", v.muted},
                    {"spaceid", v.spaceid},
                    {"objectclass", v.objectclass},
                    {"objectpurpose", v.objectpurpose},
                    {"objectidcode", v.objectidcode},
                    {"objectowner", v.objectowner},
                    {"name", v.name},
                    {"message", v.message},
                    {"soundid", v.soundid}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPlayerLogos(PARAMS(bool includestandard,bool includecustom))
    {
        uint32_t resultlen = 32767;
        std::vector<UILogo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetPlayerLogos, result.data(), resultlen, includestandard, includecustom);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"file", v.file},
                    {"icon", v.icon},
                    {"ispersonal", v.ispersonal}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPlayerShipBuildTasks(PARAMS(bool isinprogress,bool includeupgrade))
    {
        uint32_t resultlen = 32767;
        std::vector<BuildTaskInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetPlayerShipBuildTasks, result.data(), resultlen, isinprogress, includeupgrade);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"id", v.id},
                    {"buildingcontainer", v.buildingcontainer},
                    {"component", v.component},
                    {"macro", v.macro},
                    {"factionid", v.factionid},
                    {"buildercomponent", v.buildercomponent},
                    {"price", v.price},
                    {"ismissingresources", v.ismissingresources},
                    {"queueposition", v.queueposition}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetPurchasableCargo(PARAMS(UniverseID containerid,const char* unknownString))
    {
        uint32_t func_res_1 = invoke(GetPurchasableCargo, containerid, unknownString);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetRemovedConstructionPlanModules2(PARAMS())
    {
        uint32_t changedIndices;
        uint32_t numChangedIndices;
        uint32_t resultlen = 32767;
        std::vector<UniverseID> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetRemovedConstructionPlanModules2, result.data(), resultlen, &changedIndices, &numChangedIndices);
         if (func_res_1) {
            return json
            {
                {"func_res", func_res_1},
                {"changedIndices", changedIndices},
                {"numChangedIndices", numChangedIndices}
            };
        }
 
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetRemovedStationModules(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<UniverseID> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetRemovedStationModules, result.data(), resultlen);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetRenderTargetAlpha(PARAMS(const int rendertargetid))
    {
        uint32_t func_res_1 = invoke(GetRenderTargetAlpha, rendertargetid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetRepairResources(PARAMS(UniverseID componenttorepairid))
    {
        uint32_t resultlen = 32767;
        std::vector<UIWareInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetRepairResources, result.data(), resultlen, componenttorepairid);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"ware", v.ware},
                    {"macro", v.macro},
                    {"amount", v.amount}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetResearchModules(PARAMS(UniverseID containerid))
    {
        uint32_t resultlen = 32767;
        std::vector<UniverseID> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetResearchModules, result.data(), resultlen, containerid);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetRoleTierNPCs(PARAMS(UniverseID controllableid,const char* role,int32_t skilllevel))
    {
        uint32_t resultlen = 32767;
        std::vector<NPCSeed> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetRoleTierNPCs, result.data(), resultlen, controllableid, role, skilllevel);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetRoleTiers(PARAMS(UniverseID controllableid,const char* role))
    {
        uint32_t resultlen = 32767;
        std::vector<RoleTierData> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetRoleTiers, result.data(), resultlen, controllableid, role);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"name", v.name},
                    {"skilllevel", v.skilllevel},
                    {"amount", v.amount}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetSectorsByOwner(PARAMS(const char* factionid))
    {
        uint32_t resultlen = 32767;
        std::vector<UniverseID> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetSectorsByOwner, result.data(), resultlen, factionid);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetShieldGroups(PARAMS(UniverseID defensibleid))
    {
        uint32_t resultlen = 32767;
        std::vector<ShieldGroup> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetShieldGroups, result.data(), resultlen, defensibleid);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"context", v.context},
                    {"group", v.group},
                    {"component", v.component}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetSoftwarePredecessors(PARAMS(const char* softwarename))
    {
        uint32_t resultlen = 32767;
        std::vector<const char*> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetSoftwarePredecessors, result.data(), resultlen, softwarename);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetSoftwareSlots(PARAMS(UniverseID controllableid,const char* macroname))
    {
        uint32_t resultlen = 32767;
        std::vector<SoftwareSlot> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetSoftwareSlots, result.data(), resultlen, controllableid, macroname);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"max", v.max},
                    {"current", v.current}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetSoundDevices(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<const char*> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetSoundDevices, result.data(), resultlen);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetStandardButtonOffsetX(PARAMS(const int frameid))
    {
        uint32_t func_res_1 = invoke(GetStandardButtonOffsetX, frameid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetStandardButtonOffsetY(PARAMS(const int frameid))
    {
        uint32_t func_res_1 = invoke(GetStandardButtonOffsetY, frameid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetStationModules(PARAMS(UniverseID stationid,bool includeconstructions,bool includewrecks))
    {
        uint32_t resultlen = 32767;
        std::vector<UniverseID> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetStationModules, result.data(), resultlen, stationid, includeconstructions, includewrecks);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetStationOverviewGraphWares(PARAMS(UniverseID stationid))
    {
        uint32_t resultlen = 32767;
        std::vector<const char*> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetStationOverviewGraphWares, result.data(), resultlen, stationid);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetSuitableControlPosts(PARAMS(UniverseID controllableid,UniverseID entityid,bool free))
    {
        uint32_t resultlen = 32767;
        std::vector<ControlPostInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetSuitableControlPosts, result.data(), resultlen, controllableid, entityid, free);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"id", v.id},
                    {"name", v.name}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetSupplyOrders(PARAMS(UniverseID containerid,bool defaultorders))
    {
        uint32_t resultlen = 32767;
        std::vector<SupplyOverride> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetSupplyOrders, result.data(), resultlen, containerid, defaultorders);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"macro", v.macro},
                    {"amount", v.amount}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetTableHighlightMode(PARAMS(const int tableid))
    {
        uint32_t func_res_1 = invoke(GetTableHighlightMode, tableid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetTableInitialMultiselectedRows(PARAMS(const int tableid))
    {
        uint32_t resultlen = 32767;
        std::vector<uint32_t> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetTableInitialMultiselectedRows, result.data(), resultlen, tableid);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetTiersOfRole(PARAMS(const char* role))
    {
        uint32_t resultlen = 32767;
        std::vector<RoleTierData> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetTiersOfRole, result.data(), resultlen, role);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"name", v.name},
                    {"skilllevel", v.skilllevel},
                    {"amount", v.amount}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetTimeline(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<TimelineInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetTimeline, result.data(), resultlen);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"id", v.id},
                    {"name", v.name},
                    {"description", v.description},
                    {"image", v.image},
                    {"video", v.video},
                    {"voice", v.voice},
                    {"date", v.date},
                    {"group", v.group}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetTradeOfferStatistics(PARAMS(size_t numdatapoints))
    {
        uint32_t resultlen = 32767;
        std::vector<UITradeOfferStat> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetTradeOfferStatistics, result.data(), resultlen, numdatapoints);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"wareid", v.wareid},
                    {"isSellOffer", v.isSellOffer},
                    {"data", {"time", v.data->time},{"price", v.data->price},{"amount", v.data->amount},{"limit", v.data->limit}},
                    {"numdata", v.numdata}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetUnitCargo(PARAMS(UniverseID containerid,bool onlydrones))
    {
        uint32_t resultlen = 32767;
        std::vector<UIWareInfo> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetUnitCargo, result.data(), resultlen, containerid, onlydrones);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"ware", v.ware},
                    {"macro", v.macro},
                    {"amount", v.amount}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetUpgradeGroups(PARAMS(UniverseID destructibleid,const char* macroname))
    {
        uint32_t resultlen = 32767;
        std::vector<UpgradeGroup> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetUpgradeGroups, result.data(), resultlen, destructibleid, macroname);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"path", v.path},
                    {"group", v.group}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetUpgradeGroups2(PARAMS(UniverseID destructibleid,const char* macroname))
    {
        uint32_t resultlen = 32767;
        std::vector<UpgradeGroup2> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetUpgradeGroups2, result.data(), resultlen, destructibleid, macroname);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"path", v.path},
                    {"group", v.group}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetUsedLimitedModules(PARAMS(UniverseID excludedstationid))
    {
        uint32_t resultlen = 32767;
        std::vector<UIMacroCount> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetUsedLimitedModules, result.data(), resultlen, excludedstationid);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"macro", v.macro},
                    {"amount", v.amount}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetUsedLimitedModulesFromSubsequence(PARAMS(UniverseID holomapid,size_t cp_idx))
    {
        uint32_t resultlen = 32767;
        std::vector<UIMacroCount> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetUsedLimitedModulesFromSubsequence, result.data(), resultlen, holomapid, cp_idx);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"macro", v.macro},
                    {"amount", v.amount}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetValidTransporterTargets(PARAMS(UniverseID componentid))
    {
        uint32_t resultlen = 32767;
        std::vector<UIComponentSlot> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetValidTransporterTargets, result.data(), resultlen, componentid);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"component", v.component},
                    {"connection", v.connection}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetVenturePlatformDocks(PARAMS(UniverseID ventureplatformid))
    {
        uint32_t resultlen = 32767;
        std::vector<UniverseID> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetVenturePlatformDocks, result.data(), resultlen, ventureplatformid);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetVenturePlatforms(PARAMS(UniverseID defensibleid))
    {
        uint32_t resultlen = 32767;
        std::vector<UniverseID> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetVenturePlatforms, result.data(), resultlen, defensibleid);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetWareBlueprintOwners(PARAMS(const char* wareid))
    {
        uint32_t resultlen = 32767;
        std::vector<const char*> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetWareBlueprintOwners, result.data(), resultlen, wareid);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetWareSources(PARAMS(const char* wareid))
    {
        uint32_t resultlen = 32767;
        std::vector<WareSource> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetWareSources, result.data(), resultlen, wareid);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"sourcetype", v.sourcetype},
                    {"sourcelocation", v.sourcelocation}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetWares(PARAMS(const char* tags,bool research,const char* licenceownerid,const char* exclusiontags))
    {
        uint32_t resultlen = 32767;
        std::vector<const char*> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetWares, result.data(), resultlen, tags, research, licenceownerid, exclusiontags);
         if (func_res_1) {
            result.resize(func_res_1);
            return json
            {
                {"func_res", func_res_1},
                {"result", result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetWeaponGroupsByWeapon(PARAMS(UniverseID defensibleid,UniverseID weaponid))
    {
        uint32_t resultlen = 32767;
        std::vector<UIWeaponGroup> result;
        result.resize(resultlen);
        uint32_t func_res_1 = invoke(GetWeaponGroupsByWeapon, result.data(), resultlen, defensibleid, weaponid);
         if (func_res_1) {
            result.resize(func_res_1);
            std::vector<json> json_result;
            json_result.reserve(func_res_1);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"primary", v.primary},
                    {"idx", v.idx}
                });
            }
            return json
            {
                {"func_res", func_res_1},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json PlayDetailmonitorCutscene(PARAMS(uint32_t cutsceneid,const char* rendertarget))
    {
        uint32_t func_res_1 = invoke(PlayDetailmonitorCutscene, cutsceneid, rendertarget);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json PrepareBuildSequenceResources(PARAMS(UniverseID holomapid,UniverseID stationid))
    {
        uint32_t func_res_1 = invoke(PrepareBuildSequenceResources, holomapid, stationid);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json GetActiveMissionID(PARAMS())
    {
        uint64_t func_res_1 = invoke(GetActiveMissionID);
        return json
        {
            {"func_res", func_res_1}
        };
    }
 
    json AbortMission(PARAMS(MissionID missionid))
    {
        invoke(AbortMission, missionid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json AddCopyToConstructionMap(PARAMS(UniverseID holomapid,size_t cp_idx,bool copysequence))
    {
        invoke(AddCopyToConstructionMap, holomapid, cp_idx, copysequence);
        return json
        {
            {"func_res", true}
        };
    }
 
    json AddCrewExchangeOrder(PARAMS(UniverseID containerid,UniverseID partnercontainerid,uint32_t numnpcs,uint32_t numpartnernpcs,bool tradecomputer))
    {
        NPCSeed npcs;
        NPCSeed partnernpcs;
        invoke(AddCrewExchangeOrder, containerid, partnercontainerid, &npcs, numnpcs, &partnernpcs, numpartnernpcs, tradecomputer);
          {
            return json
            {
                {"func_res", true},
                {"npcs", npcs},
                {"partnernpcs", partnernpcs}
            };
        }
 
    }
 
    json AddMacroToConstructionMap(PARAMS(UniverseID holomapid,const char* macroname,bool startdragging))
    {
        invoke(AddMacroToConstructionMap, holomapid, macroname, startdragging);
        return json
        {
            {"func_res", true}
        };
    }
 
    json AddPlayerMoney(PARAMS(int64_t money))
    {
        invoke(AddPlayerMoney, money);
        return json
        {
            {"func_res", true}
        };
    }
 
    json AddResearch(PARAMS(const char* wareid))
    {
        invoke(AddResearch, wareid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json AddSimilarMapComponentsToSelection(PARAMS(UniverseID holomapid,UniverseID componentid))
    {
        invoke(AddSimilarMapComponentsToSelection, holomapid, componentid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json ChangeMapBuildPlot(PARAMS(UniverseID holomapid,float x,float y,float z))
    {
        invoke(ChangeMapBuildPlot, holomapid, x, y, z);
        return json
        {
            {"func_res", true}
        };
    }
 
    json CheatDockingTraffic(PARAMS())
    {
        invoke(CheatDockingTraffic);
        return json
        {
            {"func_res", true}
        };
    }
 
    json ClearBuildMapSelection(PARAMS(UniverseID holomapid))
    {
        invoke(ClearBuildMapSelection, holomapid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json ClearContainerBuyLimitOverride(PARAMS(UniverseID containerid,const char* wareid))
    {
        invoke(ClearContainerBuyLimitOverride, containerid, wareid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json ClearContainerSellLimitOverride(PARAMS(UniverseID containerid,const char* wareid))
    {
        invoke(ClearContainerSellLimitOverride, containerid, wareid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json ClearErrorLog(PARAMS())
    {
        invoke(ClearErrorLog);
        return json
        {
            {"func_res", true}
        };
    }
 
    json ClearMapBehaviour(PARAMS(UniverseID holomapid))
    {
        invoke(ClearMapBehaviour, holomapid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json ClearMapBuildPlot(PARAMS(UniverseID holomapid))
    {
        invoke(ClearMapBuildPlot, holomapid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json ClearMapTradeFilterByMinTotalVolume(PARAMS(UniverseID holomapid))
    {
        invoke(ClearMapTradeFilterByMinTotalVolume, holomapid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json ClearMapTradeFilterByPlayerOffer(PARAMS(UniverseID holomapid,bool buysellswitch))
    {
        invoke(ClearMapTradeFilterByPlayerOffer, holomapid, buysellswitch);
        return json
        {
            {"func_res", true}
        };
    }
 
    json ClearMapTradeFilterByWare(PARAMS(UniverseID holomapid))
    {
        invoke(ClearMapTradeFilterByWare, holomapid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json ClearProductionItems(PARAMS(UniverseID productionmoduleid))
    {
        invoke(ClearProductionItems, productionmoduleid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json ClearRendertarget(PARAMS(const char* rendertarget))
    {
        invoke(ClearRendertarget, rendertarget);
        return json
        {
            {"func_res", true}
        };
    }
 
    json ClearSelectedMapComponents(PARAMS(UniverseID holomapid))
    {
        invoke(ClearSelectedMapComponents, holomapid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json ClearSelectedMapMacroSlots(PARAMS(UniverseID holomapid))
    {
        invoke(ClearSelectedMapMacroSlots, holomapid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json ClearTrackedMenus(PARAMS())
    {
        invoke(ClearTrackedMenus);
        return json
        {
            {"func_res", true}
        };
    }
 
    json ConnectToMultiplayerGame(PARAMS(const char* serverip))
    {
        invoke(ConnectToMultiplayerGame, serverip);
        return json
        {
            {"func_res", true}
        };
    }
 
    json CycleNextDroneMode(PARAMS(uint32_t dronetype))
    {
        invoke(CycleNextDroneMode, dronetype);
        return json
        {
            {"func_res", true}
        };
    }
 
    json CycleTurretMissile(PARAMS(size_t turretnum))
    {
        invoke(CycleTurretMissile, turretnum);
        return json
        {
            {"func_res", true}
        };
    }
 
    json CycleTurretMode(PARAMS(size_t turretnum))
    {
        invoke(CycleTurretMode, turretnum);
        return json
        {
            {"func_res", true}
        };
    }
 
    json DeactivateDirectInput(PARAMS())
    {
        invoke(DeactivateDirectInput);
        return json
        {
            {"func_res", true}
        };
    }
 
    json DeactivateMouseEmulation(PARAMS())
    {
        invoke(DeactivateMouseEmulation);
        return json
        {
            {"func_res", true}
        };
    }
 
    json DeselectMacroForConstructionMap(PARAMS(UniverseID holomapid))
    {
        invoke(DeselectMacroForConstructionMap, holomapid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json DisableAsserts(PARAMS())
    {
        invoke(DisableAsserts);
        return json
        {
            {"func_res", true}
        };
    }
 
    json DisableAutoMouseEmulation(PARAMS())
    {
        invoke(DisableAutoMouseEmulation);
        return json
        {
            {"func_res", true}
        };
    }
 
    json DisableEncryptedDirectInputMode(PARAMS())
    {
        invoke(DisableEncryptedDirectInputMode);
        return json
        {
            {"func_res", true}
        };
    }
 
    json DisableOptionalAsserts(PARAMS())
    {
        invoke(DisableOptionalAsserts);
        return json
        {
            {"func_res", true}
        };
    }
 
    json DismantleEngineMod(PARAMS(UniverseID objectid))
    {
        invoke(DismantleEngineMod, objectid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json DismantleGroupedWeaponMod(PARAMS(UniverseID defensibleid,UniverseID contextid,const char* group))
    {
        invoke(DismantleGroupedWeaponMod, defensibleid, contextid, group);
        return json
        {
            {"func_res", true}
        };
    }
 
    json DismantleShieldMod(PARAMS(UniverseID defensibleid,UniverseID contextid,const char* group))
    {
        invoke(DismantleShieldMod, defensibleid, contextid, group);
        return json
        {
            {"func_res", true}
        };
    }
 
    json DismantleShipMod(PARAMS(UniverseID shipid))
    {
        invoke(DismantleShipMod, shipid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json DismantleWeaponMod(PARAMS(UniverseID weaponid))
    {
        invoke(DismantleWeaponMod, weaponid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json EnableAllCheats(PARAMS())
    {
        invoke(EnableAllCheats);
        return json
        {
            {"func_res", true}
        };
    }
 
    json EnableAsserts(PARAMS())
    {
        invoke(EnableAsserts);
        return json
        {
            {"func_res", true}
        };
    }
 
    json EnableAutoMouseEmulation(PARAMS())
    {
        invoke(EnableAutoMouseEmulation);
        return json
        {
            {"func_res", true}
        };
    }
 
    json EnableEncryptedDirectInputMode(PARAMS())
    {
        invoke(EnableEncryptedDirectInputMode);
        return json
        {
            {"func_res", true}
        };
    }
 
    json EnableOptionalAsserts(PARAMS())
    {
        invoke(EnableOptionalAsserts);
        return json
        {
            {"func_res", true}
        };
    }
 
    json EndGuidance(PARAMS())
    {
        invoke(EndGuidance);
        return json
        {
            {"func_res", true}
        };
    }
 
    json FadeScreen(PARAMS(float fadeouttime,float fadeintime))
    {
        invoke(FadeScreen, fadeouttime, fadeintime);
        return json
        {
            {"func_res", true}
        };
    }
 
    json GenerateModuleLoadout(PARAMS(UniverseID holomapid,size_t cp_idx,UniverseID defensibleid,float level))
    {
        UILoadout result;
        invoke(GenerateModuleLoadout, &result, holomapid, cp_idx, defensibleid, level);
          {
            return json
            {
                {"func_res", true},
                {"result", {
                    {"weapons", {"macro", result.weapons->macro},{"upgradetypename", result.weapons->upgradetypename},{"slot", result.weapons->slot},{"optional", result.weapons->optional}},
                    {"numweapons", result.numweapons},
                    {"turrets", {"macro", result.turrets->macro},{"upgradetypename", result.turrets->upgradetypename},{"slot", result.turrets->slot},{"optional", result.turrets->optional}},
                    {"numturrets", result.numturrets},
                    {"shields", {"macro", result.shields->macro},{"upgradetypename", result.shields->upgradetypename},{"slot", result.shields->slot},{"optional", result.shields->optional}},
                    {"numshields", result.numshields},
                    {"engines", {"macro", result.engines->macro},{"upgradetypename", result.engines->upgradetypename},{"slot", result.engines->slot},{"optional", result.engines->optional}},
                    {"numengines", result.numengines},
                    {"turretgroups", {"macro", result.turretgroups->macro},{"path", result.turretgroups->path},{"group", result.turretgroups->group},{"count", result.turretgroups->count},{"optional", result.turretgroups->optional}},
                    {"numturretgroups", result.numturretgroups},
                    {"shieldgroups", {"macro", result.shieldgroups->macro},{"path", result.shieldgroups->path},{"group", result.shieldgroups->group},{"count", result.shieldgroups->count},{"optional", result.shieldgroups->optional}},
                    {"numshieldgroups", result.numshieldgroups},
                    {"ammo", {"macro", result.ammo->macro},{"amount", result.ammo->amount},{"optional", result.ammo->optional}},
                    {"numammo", result.numammo},
                    {"units", {"macro", result.units->macro},{"amount", result.units->amount},{"optional", result.units->optional}},
                    {"numunits", result.numunits},
                    {"software", {"ware", result.software->ware}},
                    {"numsoftware", result.numsoftware},
                    {"thruster", {"macro", result.thruster.macro},{"optional", result.thruster.optional}}
                }}
            };
        }
 
    }
 
    json GenerateModuleLoadoutCounts(PARAMS(UniverseID holomapid,size_t cp_idx,UniverseID defensibleid,float level))
    {
        UILoadoutCounts result;
        invoke(GenerateModuleLoadoutCounts, &result, holomapid, cp_idx, defensibleid, level);
          {
            return json
            {
                {"func_res", true},
                {"result", {
                    {"numweapons", result.numweapons},
                    {"numturrets", result.numturrets},
                    {"numshields", result.numshields},
                    {"numengines", result.numengines},
                    {"numturretgroups", result.numturretgroups},
                    {"numshieldgroups", result.numshieldgroups},
                    {"numammo", result.numammo},
                    {"numunits", result.numunits},
                    {"numsoftware", result.numsoftware}
                }}
            };
        }
 
    }
 
    json GenerateShipKnownLoadout(PARAMS(const char* macroname,float level))
    {
        UILoadout result;
        invoke(GenerateShipKnownLoadout, &result, macroname, level);
          {
            return json
            {
                {"func_res", true},
                {"result", {
                    {"weapons", {"macro", result.weapons->macro},{"upgradetypename", result.weapons->upgradetypename},{"slot", result.weapons->slot},{"optional", result.weapons->optional}},
                    {"numweapons", result.numweapons},
                    {"turrets", {"macro", result.turrets->macro},{"upgradetypename", result.turrets->upgradetypename},{"slot", result.turrets->slot},{"optional", result.turrets->optional}},
                    {"numturrets", result.numturrets},
                    {"shields", {"macro", result.shields->macro},{"upgradetypename", result.shields->upgradetypename},{"slot", result.shields->slot},{"optional", result.shields->optional}},
                    {"numshields", result.numshields},
                    {"engines", {"macro", result.engines->macro},{"upgradetypename", result.engines->upgradetypename},{"slot", result.engines->slot},{"optional", result.engines->optional}},
                    {"numengines", result.numengines},
                    {"turretgroups", {"macro", result.turretgroups->macro},{"path", result.turretgroups->path},{"group", result.turretgroups->group},{"count", result.turretgroups->count},{"optional", result.turretgroups->optional}},
                    {"numturretgroups", result.numturretgroups},
                    {"shieldgroups", {"macro", result.shieldgroups->macro},{"path", result.shieldgroups->path},{"group", result.shieldgroups->group},{"count", result.shieldgroups->count},{"optional", result.shieldgroups->optional}},
                    {"numshieldgroups", result.numshieldgroups},
                    {"ammo", {"macro", result.ammo->macro},{"amount", result.ammo->amount},{"optional", result.ammo->optional}},
                    {"numammo", result.numammo},
                    {"units", {"macro", result.units->macro},{"amount", result.units->amount},{"optional", result.units->optional}},
                    {"numunits", result.numunits},
                    {"software", {"ware", result.software->ware}},
                    {"numsoftware", result.numsoftware},
                    {"thruster", {"macro", result.thruster.macro},{"optional", result.thruster.optional}}
                }}
            };
        }
 
    }
 
    json GenerateShipKnownLoadoutCounts(PARAMS(const char* macroname,float level))
    {
        UILoadoutCounts result;
        invoke(GenerateShipKnownLoadoutCounts, &result, macroname, level);
          {
            return json
            {
                {"func_res", true},
                {"result", {
                    {"numweapons", result.numweapons},
                    {"numturrets", result.numturrets},
                    {"numshields", result.numshields},
                    {"numengines", result.numengines},
                    {"numturretgroups", result.numturretgroups},
                    {"numshieldgroups", result.numshieldgroups},
                    {"numammo", result.numammo},
                    {"numunits", result.numunits},
                    {"numsoftware", result.numsoftware}
                }}
            };
        }
 
    }
 
    json GenerateShipLoadout(PARAMS(UniverseID containerid,UniverseID shipid,const char* macroname,float level))
    {
        UILoadout result;
        invoke(GenerateShipLoadout, &result, containerid, shipid, macroname, level);
          {
            return json
            {
                {"func_res", true},
                {"result", {
                    {"weapons", {"macro", result.weapons->macro},{"upgradetypename", result.weapons->upgradetypename},{"slot", result.weapons->slot},{"optional", result.weapons->optional}},
                    {"numweapons", result.numweapons},
                    {"turrets", {"macro", result.turrets->macro},{"upgradetypename", result.turrets->upgradetypename},{"slot", result.turrets->slot},{"optional", result.turrets->optional}},
                    {"numturrets", result.numturrets},
                    {"shields", {"macro", result.shields->macro},{"upgradetypename", result.shields->upgradetypename},{"slot", result.shields->slot},{"optional", result.shields->optional}},
                    {"numshields", result.numshields},
                    {"engines", {"macro", result.engines->macro},{"upgradetypename", result.engines->upgradetypename},{"slot", result.engines->slot},{"optional", result.engines->optional}},
                    {"numengines", result.numengines},
                    {"turretgroups", {"macro", result.turretgroups->macro},{"path", result.turretgroups->path},{"group", result.turretgroups->group},{"count", result.turretgroups->count},{"optional", result.turretgroups->optional}},
                    {"numturretgroups", result.numturretgroups},
                    {"shieldgroups", {"macro", result.shieldgroups->macro},{"path", result.shieldgroups->path},{"group", result.shieldgroups->group},{"count", result.shieldgroups->count},{"optional", result.shieldgroups->optional}},
                    {"numshieldgroups", result.numshieldgroups},
                    {"ammo", {"macro", result.ammo->macro},{"amount", result.ammo->amount},{"optional", result.ammo->optional}},
                    {"numammo", result.numammo},
                    {"units", {"macro", result.units->macro},{"amount", result.units->amount},{"optional", result.units->optional}},
                    {"numunits", result.numunits},
                    {"software", {"ware", result.software->ware}},
                    {"numsoftware", result.numsoftware},
                    {"thruster", {"macro", result.thruster.macro},{"optional", result.thruster.optional}}
                }}
            };
        }
 
    }
 
    json GenerateShipLoadoutCounts(PARAMS(UniverseID containerid,UniverseID shipid,const char* macroname,float level))
    {
        UILoadoutCounts result;
        invoke(GenerateShipLoadoutCounts, &result, containerid, shipid, macroname, level);
          {
            return json
            {
                {"func_res", true},
                {"result", {
                    {"numweapons", result.numweapons},
                    {"numturrets", result.numturrets},
                    {"numshields", result.numshields},
                    {"numengines", result.numengines},
                    {"numturretgroups", result.numturretgroups},
                    {"numshieldgroups", result.numshieldgroups},
                    {"numammo", result.numammo},
                    {"numunits", result.numunits},
                    {"numsoftware", result.numsoftware}
                }}
            };
        }
 
    }
 
    json GetBuildTaskCrewTransferInfo(PARAMS(UniverseID containerid,BuildTaskID id))
    {
        CrewTransferInfo result;
        invoke(GetBuildTaskCrewTransferInfo, &result, containerid, id);
          {
            return json
            {
                {"func_res", true},
                {"result", {
                    {"removed", {"newroleid", result.removed->newroleid},{"seed", result.removed->seed},{"amount", result.removed->amount}},
                    {"numremoved", result.numremoved},
                    {"added", {"newroleid", result.added->newroleid},{"seed", result.added->seed},{"amount", result.added->amount}},
                    {"numadded", result.numadded},
                    {"transferred", {"newroleid", result.transferred->newroleid},{"seed", result.transferred->seed},{"amount", result.transferred->amount}},
                    {"numtransferred", result.numtransferred}
                }}
            };
        }
 
    }
 
    json GetConstructionMapItemLoadout(PARAMS(UniverseID holomapid,size_t itemidx,UniverseID defensibleid))
    {
        UILoadout result;
        invoke(GetConstructionMapItemLoadout, &result, holomapid, itemidx, defensibleid);
          {
            return json
            {
                {"func_res", true},
                {"result", {
                    {"weapons", {"macro", result.weapons->macro},{"upgradetypename", result.weapons->upgradetypename},{"slot", result.weapons->slot},{"optional", result.weapons->optional}},
                    {"numweapons", result.numweapons},
                    {"turrets", {"macro", result.turrets->macro},{"upgradetypename", result.turrets->upgradetypename},{"slot", result.turrets->slot},{"optional", result.turrets->optional}},
                    {"numturrets", result.numturrets},
                    {"shields", {"macro", result.shields->macro},{"upgradetypename", result.shields->upgradetypename},{"slot", result.shields->slot},{"optional", result.shields->optional}},
                    {"numshields", result.numshields},
                    {"engines", {"macro", result.engines->macro},{"upgradetypename", result.engines->upgradetypename},{"slot", result.engines->slot},{"optional", result.engines->optional}},
                    {"numengines", result.numengines},
                    {"turretgroups", {"macro", result.turretgroups->macro},{"path", result.turretgroups->path},{"group", result.turretgroups->group},{"count", result.turretgroups->count},{"optional", result.turretgroups->optional}},
                    {"numturretgroups", result.numturretgroups},
                    {"shieldgroups", {"macro", result.shieldgroups->macro},{"path", result.shieldgroups->path},{"group", result.shieldgroups->group},{"count", result.shieldgroups->count},{"optional", result.shieldgroups->optional}},
                    {"numshieldgroups", result.numshieldgroups},
                    {"ammo", {"macro", result.ammo->macro},{"amount", result.ammo->amount},{"optional", result.ammo->optional}},
                    {"numammo", result.numammo},
                    {"units", {"macro", result.units->macro},{"amount", result.units->amount},{"optional", result.units->optional}},
                    {"numunits", result.numunits},
                    {"software", {"ware", result.software->ware}},
                    {"numsoftware", result.numsoftware},
                    {"thruster", {"macro", result.thruster.macro},{"optional", result.thruster.optional}}
                }}
            };
        }
 
    }
 
    json GetConstructionMapItemLoadoutCounts(PARAMS(UniverseID holomapid,size_t itemidx,UniverseID defensibleid))
    {
        UILoadoutCounts result;
        invoke(GetConstructionMapItemLoadoutCounts, &result, holomapid, itemidx, defensibleid);
          {
            return json
            {
                {"func_res", true},
                {"result", {
                    {"numweapons", result.numweapons},
                    {"numturrets", result.numturrets},
                    {"numshields", result.numshields},
                    {"numengines", result.numengines},
                    {"numturretgroups", result.numturretgroups},
                    {"numshieldgroups", result.numshieldgroups},
                    {"numammo", result.numammo},
                    {"numunits", result.numunits},
                    {"numsoftware", result.numsoftware}
                }}
            };
        }
 
    }
 
    json GetCurrentLoadout(PARAMS(UniverseID defensibleid,UniverseID moduleid))
    {
        UILoadout result;
        invoke(GetCurrentLoadout, &result, defensibleid, moduleid);
          {
            return json
            {
                {"func_res", true},
                {"result", {
                    {"weapons", {"macro", result.weapons->macro},{"upgradetypename", result.weapons->upgradetypename},{"slot", result.weapons->slot},{"optional", result.weapons->optional}},
                    {"numweapons", result.numweapons},
                    {"turrets", {"macro", result.turrets->macro},{"upgradetypename", result.turrets->upgradetypename},{"slot", result.turrets->slot},{"optional", result.turrets->optional}},
                    {"numturrets", result.numturrets},
                    {"shields", {"macro", result.shields->macro},{"upgradetypename", result.shields->upgradetypename},{"slot", result.shields->slot},{"optional", result.shields->optional}},
                    {"numshields", result.numshields},
                    {"engines", {"macro", result.engines->macro},{"upgradetypename", result.engines->upgradetypename},{"slot", result.engines->slot},{"optional", result.engines->optional}},
                    {"numengines", result.numengines},
                    {"turretgroups", {"macro", result.turretgroups->macro},{"path", result.turretgroups->path},{"group", result.turretgroups->group},{"count", result.turretgroups->count},{"optional", result.turretgroups->optional}},
                    {"numturretgroups", result.numturretgroups},
                    {"shieldgroups", {"macro", result.shieldgroups->macro},{"path", result.shieldgroups->path},{"group", result.shieldgroups->group},{"count", result.shieldgroups->count},{"optional", result.shieldgroups->optional}},
                    {"numshieldgroups", result.numshieldgroups},
                    {"ammo", {"macro", result.ammo->macro},{"amount", result.ammo->amount},{"optional", result.ammo->optional}},
                    {"numammo", result.numammo},
                    {"units", {"macro", result.units->macro},{"amount", result.units->amount},{"optional", result.units->optional}},
                    {"numunits", result.numunits},
                    {"software", {"ware", result.software->ware}},
                    {"numsoftware", result.numsoftware},
                    {"thruster", {"macro", result.thruster.macro},{"optional", result.thruster.optional}}
                }}
            };
        }
 
    }
 
    json GetCurrentLoadoutCounts(PARAMS(UniverseID defensibleid,UniverseID moduleid))
    {
        UILoadoutCounts result;
        invoke(GetCurrentLoadoutCounts, &result, defensibleid, moduleid);
          {
            return json
            {
                {"func_res", true},
                {"result", {
                    {"numweapons", result.numweapons},
                    {"numturrets", result.numturrets},
                    {"numshields", result.numshields},
                    {"numengines", result.numengines},
                    {"numturretgroups", result.numturretgroups},
                    {"numshieldgroups", result.numshieldgroups},
                    {"numammo", result.numammo},
                    {"numunits", result.numunits},
                    {"numsoftware", result.numsoftware}
                }}
            };
        }
 
    }
 
    json GetCustomGameStartLoadoutProperty(PARAMS(const char* id,const char* propertyid))
    {
        UILoadout result;
        invoke(GetCustomGameStartLoadoutProperty, &result, id, propertyid);
          {
            return json
            {
                {"func_res", true},
                {"result", {
                    {"weapons", {"macro", result.weapons->macro},{"upgradetypename", result.weapons->upgradetypename},{"slot", result.weapons->slot},{"optional", result.weapons->optional}},
                    {"numweapons", result.numweapons},
                    {"turrets", {"macro", result.turrets->macro},{"upgradetypename", result.turrets->upgradetypename},{"slot", result.turrets->slot},{"optional", result.turrets->optional}},
                    {"numturrets", result.numturrets},
                    {"shields", {"macro", result.shields->macro},{"upgradetypename", result.shields->upgradetypename},{"slot", result.shields->slot},{"optional", result.shields->optional}},
                    {"numshields", result.numshields},
                    {"engines", {"macro", result.engines->macro},{"upgradetypename", result.engines->upgradetypename},{"slot", result.engines->slot},{"optional", result.engines->optional}},
                    {"numengines", result.numengines},
                    {"turretgroups", {"macro", result.turretgroups->macro},{"path", result.turretgroups->path},{"group", result.turretgroups->group},{"count", result.turretgroups->count},{"optional", result.turretgroups->optional}},
                    {"numturretgroups", result.numturretgroups},
                    {"shieldgroups", {"macro", result.shieldgroups->macro},{"path", result.shieldgroups->path},{"group", result.shieldgroups->group},{"count", result.shieldgroups->count},{"optional", result.shieldgroups->optional}},
                    {"numshieldgroups", result.numshieldgroups},
                    {"ammo", {"macro", result.ammo->macro},{"amount", result.ammo->amount},{"optional", result.ammo->optional}},
                    {"numammo", result.numammo},
                    {"units", {"macro", result.units->macro},{"amount", result.units->amount},{"optional", result.units->optional}},
                    {"numunits", result.numunits},
                    {"software", {"ware", result.software->ware}},
                    {"numsoftware", result.numsoftware},
                    {"thruster", {"macro", result.thruster.macro},{"optional", result.thruster.optional}}
                }}
            };
        }
 
    }
 
    json GetCustomGameStartLoadoutPropertyCounts(PARAMS(const char* id,const char* propertyid))
    {
        UILoadoutCounts result;
        invoke(GetCustomGameStartLoadoutPropertyCounts, &result, id, propertyid);
          {
            return json
            {
                {"func_res", true},
                {"result", {
                    {"numweapons", result.numweapons},
                    {"numturrets", result.numturrets},
                    {"numshields", result.numshields},
                    {"numengines", result.numengines},
                    {"numturretgroups", result.numturretgroups},
                    {"numshieldgroups", result.numshieldgroups},
                    {"numammo", result.numammo},
                    {"numunits", result.numunits},
                    {"numsoftware", result.numsoftware}
                }}
            };
        }
 
    }
 
    json GetLoadout(PARAMS(UniverseID defensibleid,const char* macroname,const char* loadoutid))
    {
        UILoadout result;
        invoke(GetLoadout, &result, defensibleid, macroname, loadoutid);
          {
            return json
            {
                {"func_res", true},
                {"result", {
                    {"weapons", {"macro", result.weapons->macro},{"upgradetypename", result.weapons->upgradetypename},{"slot", result.weapons->slot},{"optional", result.weapons->optional}},
                    {"numweapons", result.numweapons},
                    {"turrets", {"macro", result.turrets->macro},{"upgradetypename", result.turrets->upgradetypename},{"slot", result.turrets->slot},{"optional", result.turrets->optional}},
                    {"numturrets", result.numturrets},
                    {"shields", {"macro", result.shields->macro},{"upgradetypename", result.shields->upgradetypename},{"slot", result.shields->slot},{"optional", result.shields->optional}},
                    {"numshields", result.numshields},
                    {"engines", {"macro", result.engines->macro},{"upgradetypename", result.engines->upgradetypename},{"slot", result.engines->slot},{"optional", result.engines->optional}},
                    {"numengines", result.numengines},
                    {"turretgroups", {"macro", result.turretgroups->macro},{"path", result.turretgroups->path},{"group", result.turretgroups->group},{"count", result.turretgroups->count},{"optional", result.turretgroups->optional}},
                    {"numturretgroups", result.numturretgroups},
                    {"shieldgroups", {"macro", result.shieldgroups->macro},{"path", result.shieldgroups->path},{"group", result.shieldgroups->group},{"count", result.shieldgroups->count},{"optional", result.shieldgroups->optional}},
                    {"numshieldgroups", result.numshieldgroups},
                    {"ammo", {"macro", result.ammo->macro},{"amount", result.ammo->amount},{"optional", result.ammo->optional}},
                    {"numammo", result.numammo},
                    {"units", {"macro", result.units->macro},{"amount", result.units->amount},{"optional", result.units->optional}},
                    {"numunits", result.numunits},
                    {"software", {"ware", result.software->ware}},
                    {"numsoftware", result.numsoftware},
                    {"thruster", {"macro", result.thruster.macro},{"optional", result.thruster.optional}}
                }}
            };
        }
 
    }
 
    json GetMapState(PARAMS(UniverseID holomapid))
    {
        HoloMapState state;
        invoke(GetMapState, holomapid, &state);
          {
            return json
            {
                {"func_res", true},
                {"state", {
                    {"offset", {"x", state.offset.x},{"y", state.offset.y},{"z", state.offset.z},{"yaw", state.offset.yaw},{"pitch", state.offset.pitch},{"roll", state.offset.roll}},
                    {"cameradistance", state.cameradistance}
                }}
            };
        }
 
    }
 
    json InvalidateRadarCursorPosition(PARAMS())
    {
        invoke(InvalidateRadarCursorPosition);
        return json
        {
            {"func_res", true}
        };
    }
 
    json LaunchLaserTower(PARAMS(UniverseID defensibleid,const char* lasertowermacroname))
    {
        invoke(LaunchLaserTower, defensibleid, lasertowermacroname);
        return json
        {
            {"func_res", true}
        };
    }
 
    json LaunchMine(PARAMS(UniverseID defensibleid,const char* minemacroname))
    {
        invoke(LaunchMine, defensibleid, minemacroname);
        return json
        {
            {"func_res", true}
        };
    }
 
    json LaunchNavBeacon(PARAMS(UniverseID defensibleid,const char* navbeaconmacroname))
    {
        invoke(LaunchNavBeacon, defensibleid, navbeaconmacroname);
        return json
        {
            {"func_res", true}
        };
    }
 
    json LaunchResourceProbe(PARAMS(UniverseID defensibleid,const char* resourceprobemacroname))
    {
        invoke(LaunchResourceProbe, defensibleid, resourceprobemacroname);
        return json
        {
            {"func_res", true}
        };
    }
 
    json LaunchSatellite(PARAMS(UniverseID defensibleid,const char* satellitemacroname))
    {
        invoke(LaunchSatellite, defensibleid, satellitemacroname);
        return json
        {
            {"func_res", true}
        };
    }
 
    json LearnBlueprint(PARAMS(const char* wareid))
    {
        invoke(LearnBlueprint, wareid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json MakePlayerOwnerOf(PARAMS(UniverseID objectid))
    {
        invoke(MakePlayerOwnerOf, objectid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json MutePlayerAlert(PARAMS(size_t index))
    {
        invoke(MutePlayerAlert, index);
        return json
        {
            {"func_res", true}
        };
    }
 
    json NewMultiplayerGame(PARAMS(const char* modulename,const char* difficulty))
    {
        invoke(NewMultiplayerGame, modulename, difficulty);
        return json
        {
            {"func_res", true}
        };
    }
 
    json NotifyDisplayNotification(PARAMS(const int notificationid))
    {
        invoke(NotifyDisplayNotification, notificationid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json NotifyErrorLogDispatching(PARAMS())
    {
        invoke(NotifyErrorLogDispatching);
        return json
        {
            {"func_res", true}
        };
    }
 
    json NotifyErrorLogDispatchingDone(PARAMS())
    {
        invoke(NotifyErrorLogDispatchingDone);
        return json
        {
            {"func_res", true}
        };
    }
 
    json NotifyInteractMenuHidden(PARAMS(const uint32_t id,const bool allclosed))
    {
        invoke(NotifyInteractMenuHidden, id, allclosed);
        return json
        {
            {"func_res", true}
        };
    }
 
    json NotifyInteractMenuShown(PARAMS(const uint32_t id))
    {
        invoke(NotifyInteractMenuShown, id);
        return json
        {
            {"func_res", true}
        };
    }
 
    json OpenMovieMenu(PARAMS(const char* key))
    {
        invoke(OpenMovieMenu, key);
        return json
        {
            {"func_res", true}
        };
    }
 
    json OpenWebBrowser(PARAMS(const char* url))
    {
        invoke(OpenWebBrowser, url);
        return json
        {
            {"func_res", true}
        };
    }
 
    json ReadAllInventoryWares(PARAMS())
    {
        invoke(ReadAllInventoryWares);
        return json
        {
            {"func_res", true}
        };
    }
 
    json ReadInventoryWare(PARAMS(const char* wareid))
    {
        invoke(ReadInventoryWare, wareid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json ReadKnownItem(PARAMS(const char* libraryid,const char* itemid,bool read))
    {
        invoke(ReadKnownItem, libraryid, itemid, read);
        return json
        {
            {"func_res", true}
        };
    }
 
    json ReassignPeople(PARAMS(UniverseID controllableid,uint32_t amount))
    {
        CrewTransferContainer reassignedcrew;
        invoke(ReassignPeople, controllableid, &reassignedcrew, amount);
          {
            return json
            {
                {"func_res", true},
                {"reassignedcrew", {
                    {"newroleid", reassignedcrew.newroleid},
                    {"seed", reassignedcrew.seed},
                    {"amount", reassignedcrew.amount}
                }}
            };
        }
 
    }
 
    json RedoConstructionMapChange(PARAMS(UniverseID holomapid))
    {
        invoke(RedoConstructionMapChange, holomapid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json ReenableErrorLog(PARAMS())
    {
        invoke(ReenableErrorLog);
        return json
        {
            {"func_res", true}
        };
    }
 
    json ReleaseConstructionMapState(PARAMS())
    {
        invoke(ReleaseConstructionMapState);
        return json
        {
            {"func_res", true}
        };
    }
 
    json ReleaseInteractionDescriptor(PARAMS(int32_t id))
    {
        invoke(ReleaseInteractionDescriptor, id);
        return json
        {
            {"func_res", true}
        };
    }
 
    json ReleaseOrderSyncPoint(PARAMS(uint32_t syncid))
    {
        invoke(ReleaseOrderSyncPoint, syncid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json ReleasePersonFromCrewTransfer(PARAMS(UniverseID controllableid,NPCSeed person))
    {
        invoke(ReleasePersonFromCrewTransfer, controllableid, person);
        return json
        {
            {"func_res", true}
        };
    }
 
    json ReloadSaveList(PARAMS())
    {
        invoke(ReloadSaveList);
        return json
        {
            {"func_res", true}
        };
    }
 
    json RemoveBlacklist(PARAMS(BlacklistID id))
    {
        invoke(RemoveBlacklist, id);
        return json
        {
            {"func_res", true}
        };
    }
 
    json RemoveDockingBayReservation(PARAMS(UniverseID dockingbayid))
    {
        invoke(RemoveDockingBayReservation, dockingbayid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json RemoveFill(PARAMS(const UniverseID componentid,const char*const connectionname))
    {
        invoke(RemoveFill, componentid, connectionname);
        return json
        {
            {"func_res", true}
        };
    }
 
    json RemoveHoloMap(PARAMS())
    {
        invoke(RemoveHoloMap);
        return json
        {
            {"func_res", true}
        };
    }
 
    json RemoveItemFromConstructionMap(PARAMS(UniverseID holomapid,size_t itemidx))
    {
        invoke(RemoveItemFromConstructionMap, holomapid, itemidx);
        return json
        {
            {"func_res", true}
        };
    }
 
    json RemoveOrderSyncPointID(PARAMS(UniverseID controllableid,size_t orderidx))
    {
        invoke(RemoveOrderSyncPointID, controllableid, orderidx);
        return json
        {
            {"func_res", true}
        };
    }
 
    json RemoveOutline(PARAMS(const UniverseID componentid,const char*const connectionname))
    {
        invoke(RemoveOutline, componentid, connectionname);
        return json
        {
            {"func_res", true}
        };
    }
 
    json RemovePerson(PARAMS(UniverseID controllableid,NPCSeed person))
    {
        invoke(RemovePerson, controllableid, person);
        return json
        {
            {"func_res", true}
        };
    }
 
    json RemovePlannedDefaultOrder(PARAMS(UniverseID controllableid))
    {
        invoke(RemovePlannedDefaultOrder, controllableid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json RemovePlayerAlert(PARAMS(size_t index))
    {
        invoke(RemovePlayerAlert, index);
        return json
        {
            {"func_res", true}
        };
    }
 
    json RemoveReadMessages(PARAMS(const char* categoryname))
    {
        invoke(RemoveReadMessages, categoryname);
        return json
        {
            {"func_res", true}
        };
    }
 
    json RemoveTrackedMenu(PARAMS(const char* menu))
    {
        invoke(RemoveTrackedMenu, menu);
        return json
        {
            {"func_res", true}
        };
    }
 
    json RemoveTradeWare(PARAMS(UniverseID containerid,const char* wareid))
    {
        invoke(RemoveTradeWare, containerid, wareid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json RequestLanguageChange(PARAMS(int32_t id))
    {
        invoke(RequestLanguageChange, id);
        return json
        {
            {"func_res", true}
        };
    }
 
    json RequestSoundDeviceSwitch(PARAMS(const char* device))
    {
        invoke(RequestSoundDeviceSwitch, device);
        return json
        {
            {"func_res", true}
        };
    }
 
    json ResetCustomGameStart(PARAMS(const char* id))
    {
        invoke(ResetCustomGameStart, id);
        return json
        {
            {"func_res", true}
        };
    }
 
    json ResetEncryptedDirectInputData(PARAMS())
    {
        invoke(ResetEncryptedDirectInputData);
        return json
        {
            {"func_res", true}
        };
    }
 
    json ResetMapPlayerRotation(PARAMS(UniverseID holomapid))
    {
        invoke(ResetMapPlayerRotation, holomapid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json RestoreMiscOptions(PARAMS())
    {
        invoke(RestoreMiscOptions);
        return json
        {
            {"func_res", true}
        };
    }
 
    json RevealEncyclopedia(PARAMS())
    {
        invoke(RevealEncyclopedia);
        return json
        {
            {"func_res", true}
        };
    }
 
    json RevealMap(PARAMS())
    {
        invoke(RevealMap);
        return json
        {
            {"func_res", true}
        };
    }
 
    json RevealStations(PARAMS())
    {
        invoke(RevealStations);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SaveAAOption(PARAMS())
    {
        invoke(SaveAAOption);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SaveMapConstructionPlan(PARAMS(UniverseID holomapid,const char* source,const char* id,bool overwrite,const char* name,const char* desc))
    {
        invoke(SaveMapConstructionPlan, holomapid, source, id, overwrite, name, desc);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SelectBuildMapEntry(PARAMS(UniverseID holomapid,size_t cp_idx))
    {
        invoke(SelectBuildMapEntry, holomapid, cp_idx);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SelectPickedBuildMapEntry(PARAMS(UniverseID holomapid))
    {
        invoke(SelectPickedBuildMapEntry, holomapid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SelectSimilarMapComponents(PARAMS(UniverseID holomapid,UniverseID componentid))
    {
        invoke(SelectSimilarMapComponents, holomapid, componentid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SellPlayerShip(PARAMS(UniverseID shipid,UniverseID shipyardid))
    {
        invoke(SellPlayerShip, shipid, shipyardid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetAAOption(PARAMS(const char* fxaa))
    {
        invoke(SetAAOption, fxaa);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetAdaptiveSamplingOption(PARAMS(float value))
    {
        invoke(SetAdaptiveSamplingOption, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetAllMissileTurretModes(PARAMS(UniverseID defensibleid,const char* mode))
    {
        invoke(SetAllMissileTurretModes, defensibleid, mode);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetAllMissileTurretsArmed(PARAMS(UniverseID defensibleid,bool arm))
    {
        invoke(SetAllMissileTurretsArmed, defensibleid, arm);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetAllNonMissileTurretModes(PARAMS(UniverseID defensibleid,const char* mode))
    {
        invoke(SetAllNonMissileTurretModes, defensibleid, mode);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetAllNonMissileTurretsArmed(PARAMS(UniverseID defensibleid,bool arm))
    {
        invoke(SetAllNonMissileTurretsArmed, defensibleid, arm);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetAllTurretModes(PARAMS(UniverseID defensibleid,const char* mode))
    {
        invoke(SetAllTurretModes, defensibleid, mode);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetAllTurretsArmed(PARAMS(UniverseID defensibleid,bool arm))
    {
        invoke(SetAllTurretsArmed, defensibleid, arm);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetAllowedWeaponSystems(PARAMS(UniverseID defensibleid,size_t orderidx,bool usedefault,uint32_t numuiweaponsysteminfo))
    {
        WeaponSystemInfo uiweaponsysteminfo;
        invoke(SetAllowedWeaponSystems, defensibleid, orderidx, usedefault, &uiweaponsysteminfo, numuiweaponsysteminfo);
          {
            return json
            {
                {"func_res", true},
                {"uiweaponsysteminfo", {
                    {"id", uiweaponsysteminfo.id},
                    {"name", uiweaponsysteminfo.name},
                    {"active", uiweaponsysteminfo.active}
                }}
            };
        }
 
    }
 
    json SetAutoRoll(PARAMS(bool value))
    {
        invoke(SetAutoRoll, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetAutosaveIntervalOption(PARAMS(float factor))
    {
        invoke(SetAutosaveIntervalOption, factor);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetBoxText(PARAMS(const int boxtextid,const char* text))
    {
        invoke(SetBoxText, boxtextid, text);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetButtonActive(PARAMS(const int buttonid,bool active))
    {
        invoke(SetButtonActive, buttonid, active);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetButtonIcon2ID(PARAMS(const int buttonid,const char* iconid))
    {
        invoke(SetButtonIcon2ID, buttonid, iconid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetButtonIconID(PARAMS(const int buttonid,const char* iconid))
    {
        invoke(SetButtonIconID, buttonid, iconid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetButtonText2(PARAMS(const int buttonid,const char* text))
    {
        invoke(SetButtonText2, buttonid, text);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetCheckBoxChecked2(PARAMS(const int checkboxid,bool checked,bool update))
    {
        invoke(SetCheckBoxChecked2, checkboxid, checked, update);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetChromaticAberrationOption(PARAMS(bool value))
    {
        invoke(SetChromaticAberrationOption, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetCockpitCameraScaleOption(PARAMS(float value))
    {
        invoke(SetCockpitCameraScaleOption, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetConfigSetting(PARAMS(const char*const setting,const bool value))
    {
        invoke(SetConfigSetting, setting, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetConstructionSequenceFromConstructionMap(PARAMS(UniverseID containerid,UniverseID holomapid))
    {
        invoke(SetConstructionSequenceFromConstructionMap, containerid, holomapid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetContainerBuildAllowedFactions(PARAMS(UniverseID containerid,uint32_t numuifactions))
    {
        uint32_t resultlen = 32767;
        std::vector<const char*> uifactions;
        uifactions.resize(resultlen);
        invoke(SetContainerBuildAllowedFactions, containerid, uifactions.data(), numuifactions);
          {
            uifactions.resize(numuifactions);
            return json
            {
                {"func_res", true},
                {"uifactions", uifactions}
            };
        }
 
    }
 
    json SetContainerBuildPriceFactor(PARAMS(UniverseID containerid,float value))
    {
        invoke(SetContainerBuildPriceFactor, containerid, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetContainerBuyLimitOverride(PARAMS(UniverseID containerid,const char* wareid,int32_t amount))
    {
        invoke(SetContainerBuyLimitOverride, containerid, wareid, amount);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetContainerFactionBuildRescricted(PARAMS(UniverseID containerid,bool value))
    {
        invoke(SetContainerFactionBuildRescricted, containerid, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetContainerGlobalPriceFactor(PARAMS(UniverseID containerid,float value))
    {
        invoke(SetContainerGlobalPriceFactor, containerid, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetContainerSellLimitOverride(PARAMS(UniverseID containerid,const char* wareid,int32_t amount))
    {
        invoke(SetContainerSellLimitOverride, containerid, wareid, amount);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetContainerWareIsBuyable(PARAMS(UniverseID containerid,const char* wareid,bool allowed))
    {
        invoke(SetContainerWareIsBuyable, containerid, wareid, allowed);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetContainerWareIsSellable(PARAMS(UniverseID containerid,const char* wareid,bool allowed))
    {
        invoke(SetContainerWareIsSellable, containerid, wareid, allowed);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetControllableBlacklist(PARAMS(UniverseID controllableid,BlacklistID id,const char* listtype,bool value))
    {
        invoke(SetControllableBlacklist, controllableid, id, listtype, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetCrosshairMessage(PARAMS(const uint32_t messageid))
    {
        invoke(SetCrosshairMessage, messageid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetCustomGameStartBlueprintProperty(PARAMS(const char* id,const char* propertyid,uint32_t uivaluecount))
    {
        CustomGameStartBlueprint uivalue;
        invoke(SetCustomGameStartBlueprintProperty, id, propertyid, &uivalue, uivaluecount);
          {
            return json
            {
                {"func_res", true},
                {"uivalue", {
                    {"ware", uivalue.ware}
                }}
            };
        }
 
    }
 
    json SetCustomGameStartBoolProperty(PARAMS(const char* id,const char* propertyid,bool uivalue))
    {
        invoke(SetCustomGameStartBoolProperty, id, propertyid, uivalue);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetCustomGameStartEncyclopediaProperty(PARAMS(const char* id,const char* propertyid,uint32_t uivaluecount))
    {
        CustomGameStartEncyclopediaEntry uivalue;
        invoke(SetCustomGameStartEncyclopediaProperty, id, propertyid, &uivalue, uivaluecount);
          {
            return json
            {
                {"func_res", true},
                {"uivalue", {
                    {"library", uivalue.library},
                    {"item", uivalue.item}
                }}
            };
        }
 
    }
 
    json SetCustomGameStartInventoryProperty(PARAMS(const char* id,const char* propertyid,uint32_t uivaluecount))
    {
        CustomGameStartInventory uivalue;
        invoke(SetCustomGameStartInventoryProperty, id, propertyid, &uivalue, uivaluecount);
          {
            return json
            {
                {"func_res", true},
                {"uivalue", {
                    {"ware", uivalue.ware},
                    {"amount", uivalue.amount}
                }}
            };
        }
 
    }
 
    json SetCustomGameStartMoneyProperty(PARAMS(const char* id,const char* propertyid,int64_t uivalue))
    {
        invoke(SetCustomGameStartMoneyProperty, id, propertyid, uivalue);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetCustomGameStartRelationsProperty(PARAMS(const char* id,const char* propertyid,uint32_t uivaluecount))
    {
        CustomGameStartRelationInfo uivalue;
        invoke(SetCustomGameStartRelationsProperty, id, propertyid, &uivalue, uivaluecount);
          {
            return json
            {
                {"func_res", true},
                {"uivalue", {
                    {"factionid", uivalue.factionid},
                    {"otherfactionid", uivalue.otherfactionid},
                    {"relation", uivalue.relation}
                }}
            };
        }
 
    }
 
    json SetCustomGameStartResearchProperty(PARAMS(const char* id,const char* propertyid,uint32_t uivaluecount))
    {
        uint32_t resultlen = 32767;
        std::vector<const char*> uivalue;
        uivalue.resize(resultlen);
        invoke(SetCustomGameStartResearchProperty, id, propertyid, uivalue.data(), uivaluecount);
          {
            uivalue.resize(uivaluecount);
            return json
            {
                {"func_res", true},
                {"uivalue", uivalue}
            };
        }
 
    }
 
    json SetCustomGameStartStringProperty(PARAMS(const char* id,const char* propertyid,const char* uivalue))
    {
        invoke(SetCustomGameStartStringProperty, id, propertyid, uivalue);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetDefensibleActiveWeaponGroup(PARAMS(UniverseID defensibleid,bool primary,uint32_t groupidx))
    {
        invoke(SetDefensibleActiveWeaponGroup, defensibleid, primary, groupidx);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetDefensibleLoadoutLevel(PARAMS(UniverseID defensibleid,float value))
    {
        invoke(SetDefensibleLoadoutLevel, defensibleid, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetDockingBayReservation(PARAMS(UniverseID dockingbayid,double duration))
    {
        invoke(SetDockingBayReservation, dockingbayid, duration);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetDroneMode(PARAMS(UniverseID defensibleid,const char* dronetype,const char* mode))
    {
        invoke(SetDroneMode, defensibleid, dronetype, mode);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetDroneTypeArmed(PARAMS(UniverseID defensibleid,const char* dronetype,bool arm))
    {
        invoke(SetDroneTypeArmed, defensibleid, dronetype, arm);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetDropDownCurOption(PARAMS(const int dropdownid,const char* id))
    {
        invoke(SetDropDownCurOption, dropdownid, id);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetEditBoxActive(PARAMS(const int editboxid,bool active))
    {
        invoke(SetEditBoxActive, editboxid, active);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetEditBoxText(PARAMS(const int editboxid,const char* text))
    {
        invoke(SetEditBoxText, editboxid, text);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetFill(PARAMS(const UniverseID componentid,const char*const connectionname,const uint8_t red,const uint8_t green,const uint8_t blue,const float alpha,const bool animated,const float minalpha,const float maxalpha,const float transitiontime))
    {
        invoke(SetFill, componentid, connectionname, red, green, blue, alpha, animated, minalpha, maxalpha, transitiontime);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetFleetName(PARAMS(UniverseID controllableid,const char* fleetname))
    {
        invoke(SetFleetName, controllableid, fleetname);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetFlowChartNodeCaptionText(PARAMS(const int flowchartnodeid,const char* text))
    {
        invoke(SetFlowChartNodeCaptionText, flowchartnodeid, text);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetFlowChartNodeCurValue(PARAMS(const int flowchartnodeid,double value))
    {
        invoke(SetFlowChartNodeCurValue, flowchartnodeid, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetFlowChartNodeMaxValue(PARAMS(const int flowchartnodeid,double value))
    {
        invoke(SetFlowChartNodeMaxValue, flowchartnodeid, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetFlowChartNodeSlider1Value(PARAMS(const int flowchartnodeid,double value))
    {
        invoke(SetFlowChartNodeSlider1Value, flowchartnodeid, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetFlowChartNodeSlider2Value(PARAMS(const int flowchartnodeid,double value))
    {
        invoke(SetFlowChartNodeSlider2Value, flowchartnodeid, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetFlowChartNodeSliderStep(PARAMS(const int flowchartnodeid,double step))
    {
        invoke(SetFlowChartNodeSliderStep, flowchartnodeid, step);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetFlowChartNodeStatusBgIcon(PARAMS(const int flowchartnodeid,const char* iconid))
    {
        invoke(SetFlowChartNodeStatusBgIcon, flowchartnodeid, iconid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetFlowChartNodeStatusIcon(PARAMS(const int flowchartnodeid,const char* iconid))
    {
        invoke(SetFlowChartNodeStatusIcon, flowchartnodeid, iconid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetFlowChartNodeStatusText(PARAMS(const int flowchartnodeid,const char* text))
    {
        invoke(SetFlowChartNodeStatusText, flowchartnodeid, text);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetFlowchartNodeExpanded(PARAMS(const int flowchartnodeid,const int frameid,bool expandedabove))
    {
        invoke(SetFlowchartNodeExpanded, flowchartnodeid, frameid, expandedabove);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetFocusMapComponent(PARAMS(UniverseID holomapid,UniverseID componentid,bool resetplayerpan))
    {
        invoke(SetFocusMapComponent, holomapid, componentid, resetplayerpan);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetForceShootingAtCursorOption(PARAMS(bool value))
    {
        invoke(SetForceShootingAtCursorOption, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetGroupAndAssignment(PARAMS(UniverseID controllableid,int group,const char* assignment))
    {
        invoke(SetGroupAndAssignment, controllableid, group, assignment);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetHUDRadarActive(PARAMS(bool setting))
    {
        invoke(SetHUDRadarActive, setting);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetHUDRadarSeparate(PARAMS(bool setting))
    {
        invoke(SetHUDRadarSeparate, setting);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetIcon(PARAMS(const int widgeticonid,const char* iconid))
    {
        invoke(SetIcon, widgeticonid, iconid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetIconText(PARAMS(const int widgeticonid,const char* text))
    {
        invoke(SetIconText, widgeticonid, text);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetIconText2(PARAMS(const int widgeticonid,const char* text))
    {
        invoke(SetIconText2, widgeticonid, text);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetInversionSetting(PARAMS(uint32_t uirangeid,const char* parametername,bool value))
    {
        invoke(SetInversionSetting, uirangeid, parametername, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetJoystickSteeringAdapative(PARAMS(bool value))
    {
        invoke(SetJoystickSteeringAdapative, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetKnownRead(PARAMS(UniverseID componentid,bool read))
    {
        invoke(SetKnownRead, componentid, read);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetLUTMode(PARAMS(uint32_t mode))
    {
        invoke(SetLUTMode, mode);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetMacroMapLocalLinearHighways(PARAMS(UniverseID holomapid,bool value))
    {
        invoke(SetMacroMapLocalLinearHighways, holomapid, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetMacroMapLocalRingHighways(PARAMS(UniverseID holomapid,bool value))
    {
        invoke(SetMacroMapLocalRingHighways, holomapid, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetMapAlertFilter(PARAMS(UniverseID holomapid,uint32_t alertlevel))
    {
        invoke(SetMapAlertFilter, holomapid, alertlevel);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetMapFactionRelationColorOption(PARAMS(UniverseID holomapid,bool value))
    {
        invoke(SetMapFactionRelationColorOption, holomapid, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetMapPaintMod(PARAMS(UniverseID holomapid,const char* wareid))
    {
        invoke(SetMapPaintMod, holomapid, wareid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetMapPanOffset(PARAMS(UniverseID holomapid,UniverseID offsetcomponentid))
    {
        invoke(SetMapPanOffset, holomapid, offsetcomponentid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetMapPicking(PARAMS(UniverseID holomapid,bool enable))
    {
        invoke(SetMapPicking, holomapid, enable);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetMapRelativeMousePosition(PARAMS(UniverseID holomapid,bool valid,float x,float y))
    {
        invoke(SetMapRelativeMousePosition, holomapid, valid, x, y);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetMapRenderAllAllyOrderQueues(PARAMS(UniverseID holomapid,bool value))
    {
        invoke(SetMapRenderAllAllyOrderQueues, holomapid, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetMapRenderAllOrderQueues(PARAMS(UniverseID holomapid,bool value))
    {
        invoke(SetMapRenderAllOrderQueues, holomapid, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetMapRenderCargoContents(PARAMS(UniverseID holomapid,bool value))
    {
        invoke(SetMapRenderCargoContents, holomapid, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetMapRenderCivilianShips(PARAMS(UniverseID holomapid,bool value))
    {
        invoke(SetMapRenderCivilianShips, holomapid, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetMapRenderCrewInfo(PARAMS(UniverseID holomapid,bool value))
    {
        invoke(SetMapRenderCrewInfo, holomapid, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetMapRenderDockedShipInfos(PARAMS(UniverseID holomapid,bool value))
    {
        invoke(SetMapRenderDockedShipInfos, holomapid, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetMapRenderEclipticLines(PARAMS(UniverseID holomapid,bool value))
    {
        invoke(SetMapRenderEclipticLines, holomapid, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetMapRenderMissionGuidance(PARAMS(UniverseID holomapid,MissionID missionid))
    {
        invoke(SetMapRenderMissionGuidance, holomapid, missionid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetMapRenderMissionOffers(PARAMS(UniverseID holomapid,bool value))
    {
        invoke(SetMapRenderMissionOffers, holomapid, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetMapRenderResourceInfo(PARAMS(UniverseID holomapid,bool value))
    {
        invoke(SetMapRenderResourceInfo, holomapid, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetMapRenderSelectionLines(PARAMS(UniverseID holomapid,bool value))
    {
        invoke(SetMapRenderSelectionLines, holomapid, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetMapRenderTradeOffers(PARAMS(UniverseID holomapid,bool value))
    {
        invoke(SetMapRenderTradeOffers, holomapid, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetMapRenderWorkForceInfo(PARAMS(UniverseID holomapid,bool value))
    {
        invoke(SetMapRenderWorkForceInfo, holomapid, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetMapRenderWrecks(PARAMS(UniverseID holomapid,bool value))
    {
        invoke(SetMapRenderWrecks, holomapid, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetMapStationInfoBoxMargin(PARAMS(UniverseID holomapid,const char* margin,uint32_t width))
    {
        invoke(SetMapStationInfoBoxMargin, holomapid, margin, width);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetMapTargetDistance(PARAMS(UniverseID holomapid,float distance))
    {
        invoke(SetMapTargetDistance, holomapid, distance);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetMapTopTradesCount(PARAMS(UniverseID holomapid,uint32_t count))
    {
        invoke(SetMapTopTradesCount, holomapid, count);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetMapTradeFilterByMaxPrice(PARAMS(UniverseID holomapid,int64_t price))
    {
        invoke(SetMapTradeFilterByMaxPrice, holomapid, price);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetMapTradeFilterByMinTotalVolume(PARAMS(UniverseID holomapid,uint32_t minvolume))
    {
        invoke(SetMapTradeFilterByMinTotalVolume, holomapid, minvolume);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetMapTradeFilterByPlayerOffer(PARAMS(UniverseID holomapid,bool buysellswitch,bool enable))
    {
        invoke(SetMapTradeFilterByPlayerOffer, holomapid, buysellswitch, enable);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetMapTradeFilterByWare(PARAMS(UniverseID holomapid,uint32_t numwareids))
    {
        uint32_t resultlen = 32767;
        std::vector<const char*> wareids;
        wareids.resize(resultlen);
        invoke(SetMapTradeFilterByWare, holomapid, wareids.data(), numwareids);
          {
            wareids.resize(numwareids);
            return json
            {
                {"func_res", true},
                {"wareids", wareids}
            };
        }
 
    }
 
    json SetMapTradeFilterByWareTransport(PARAMS(UniverseID holomapid,uint32_t numtransporttypes))
    {
        uint32_t resultlen = 32767;
        std::vector<const char*> transporttypes;
        transporttypes.resize(resultlen);
        invoke(SetMapTradeFilterByWareTransport, holomapid, transporttypes.data(), numtransporttypes);
          {
            transporttypes.resize(numtransporttypes);
            return json
            {
                {"func_res", true},
                {"transporttypes", transporttypes}
            };
        }
 
    }
 
    json SetMessageRead(PARAMS(MessageID messageid,const char* categoryname))
    {
        invoke(SetMessageRead, messageid, categoryname);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetMouseCursorPosition(PARAMS(const int32_t posx,const int32_t posy))
    {
        invoke(SetMouseCursorPosition, posx, posy);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetMouseHUDModeOption(PARAMS(uint32_t value))
    {
        invoke(SetMouseHUDModeOption, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetMouseOverTextOption(PARAMS(bool value))
    {
        invoke(SetMouseOverTextOption, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetMouseSteeringAdapative(PARAMS(bool value))
    {
        invoke(SetMouseSteeringAdapative, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetMouseSteeringInvertedOption(PARAMS(const char* paramname,bool value))
    {
        invoke(SetMouseSteeringInvertedOption, paramname, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetNotificationTypeEnabled(PARAMS(const char* id,bool value))
    {
        invoke(SetNotificationTypeEnabled, id, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetOutline(PARAMS(const UniverseID componentid,const char*const connectionname,const uint8_t red,const uint8_t green,const uint8_t blue,const bool animated))
    {
        invoke(SetOutline, componentid, connectionname, red, green, blue, animated);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetPlayerBlacklistDefault(PARAMS(BlacklistID id,const char* listtype,const char* defaultgroup,bool value))
    {
        invoke(SetPlayerBlacklistDefault, id, listtype, defaultgroup, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetPlayerCameraCockpitView(PARAMS(bool force))
    {
        invoke(SetPlayerCameraCockpitView, force);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetPlayerCameraTargetView(PARAMS(UniverseID targetid,bool force))
    {
        invoke(SetPlayerCameraTargetView, targetid, force);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetPlayerClothingTheme(PARAMS(const char* theme))
    {
        invoke(SetPlayerClothingTheme, theme);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetPlayerFactionName(PARAMS(const char* name))
    {
        invoke(SetPlayerFactionName, name);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetPlayerGlobalLoadoutLevel(PARAMS(float value))
    {
        invoke(SetPlayerGlobalLoadoutLevel, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetPlayerIllegalWare(PARAMS(const char* wareid,bool illegal))
    {
        invoke(SetPlayerIllegalWare, wareid, illegal);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetPlayerPaintTheme(PARAMS(const char* theme))
    {
        invoke(SetPlayerPaintTheme, theme);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetPresentModeOption(PARAMS(const char* mode))
    {
        invoke(SetPresentModeOption, mode);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetRadarMousePosition(PARAMS(float x,float y))
    {
        invoke(SetRadarMousePosition, x, y);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetSSROption2(PARAMS(const char* value))
    {
        invoke(SetSSROption2, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetSavesCompressedOption(PARAMS(bool value))
    {
        invoke(SetSavesCompressedOption, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetSelectedMapComponent(PARAMS(UniverseID holomapid,UniverseID componentid))
    {
        invoke(SetSelectedMapComponent, holomapid, componentid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetSelectedMapComponents(PARAMS(UniverseID holomapid,uint32_t numcomponentids))
    {
        UniverseID componentids;
        invoke(SetSelectedMapComponents, holomapid, &componentids, numcomponentids);
          {
            return json
            {
                {"func_res", true},
                {"componentids", componentids}
            };
        }
 
    }
 
    json SetSelectedMapGroup(PARAMS(UniverseID holomapid,UniverseID destructibleid,const char* macroname,const char* path,const char* group))
    {
        invoke(SetSelectedMapGroup, holomapid, destructibleid, macroname, path, group);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetSelectedMapMacroSlot(PARAMS(UniverseID holomapid,UniverseID defensibleid,UniverseID moduleid,const char* macroname,bool ismodule,const char* upgradetypename,size_t slot))
    {
        invoke(SetSelectedMapMacroSlot, holomapid, defensibleid, moduleid, macroname, ismodule, upgradetypename, slot);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetShieldHullBarHullPercent(PARAMS(const int shieldhullbarid,float hullpercent))
    {
        invoke(SetShieldHullBarHullPercent, shieldhullbarid, hullpercent);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetShieldHullBarShieldPercent(PARAMS(const int shieldhullbarid,float shieldpercent))
    {
        invoke(SetShieldHullBarShieldPercent, shieldhullbarid, shieldpercent);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetSliderCellMaxFactor(PARAMS(const int slidercellid,uint32_t maxfactor))
    {
        invoke(SetSliderCellMaxFactor, slidercellid, maxfactor);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetSliderCellMaxSelectValue(PARAMS(const int slidercellid,double value))
    {
        invoke(SetSliderCellMaxSelectValue, slidercellid, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetSliderCellMaxValue(PARAMS(const int slidercellid,double value))
    {
        invoke(SetSliderCellMaxValue, slidercellid, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetSliderCellValue(PARAMS(const int slidercellid,double value))
    {
        invoke(SetSliderCellValue, slidercellid, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetSpeakTargetNameOption(PARAMS(bool value))
    {
        invoke(SetSpeakTargetNameOption, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetStatusBarCurrentValue(PARAMS(const int statusbarid,float value))
    {
        invoke(SetStatusBarCurrentValue, statusbarid, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetStatusBarMaxValue(PARAMS(const int statusbarid,float value))
    {
        invoke(SetStatusBarMaxValue, statusbarid, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetStatusBarStartValue(PARAMS(const int statusbarid,float value))
    {
        invoke(SetStatusBarStartValue, statusbarid, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetSubordinateGroupAssignment(PARAMS(UniverseID controllableid,int group,const char* assignment))
    {
        invoke(SetSubordinateGroupAssignment, controllableid, group, assignment);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetSubordinateGroupDockAtCommander(PARAMS(UniverseID controllableid,int group,bool value))
    {
        invoke(SetSubordinateGroupDockAtCommander, controllableid, group, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetSupplyManual(PARAMS(UniverseID containerid,const char* type,bool onoff))
    {
        invoke(SetSupplyManual, containerid, type, onoff);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetTableNextConnectedTable(PARAMS(const int tableid,const int nexttableid))
    {
        invoke(SetTableNextConnectedTable, tableid, nexttableid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetTableNextHorizontalConnectedTable(PARAMS(const int tableid,const int nexttableid))
    {
        invoke(SetTableNextHorizontalConnectedTable, tableid, nexttableid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetTablePreviousConnectedTable(PARAMS(const int tableid,const int prevtableid))
    {
        invoke(SetTablePreviousConnectedTable, tableid, prevtableid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetTablePreviousHorizontalConnectedTable(PARAMS(const int tableid,const int prevtableid))
    {
        invoke(SetTablePreviousHorizontalConnectedTable, tableid, prevtableid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetTextureQualityOption(PARAMS(const char* mode))
    {
        invoke(SetTextureQualityOption, mode);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetThrottleBidirectional(PARAMS(bool newsetting))
    {
        invoke(SetThrottleBidirectional, newsetting);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetTobiiAngleFactor(PARAMS(float value))
    {
        invoke(SetTobiiAngleFactor, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetTobiiDeadzoneAngle(PARAMS(float value))
    {
        invoke(SetTobiiDeadzoneAngle, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetTobiiDeadzonePosition(PARAMS(float value))
    {
        invoke(SetTobiiDeadzonePosition, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetTobiiGazeAngleFactor(PARAMS(float value))
    {
        invoke(SetTobiiGazeAngleFactor, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetTobiiGazeDeadzone(PARAMS(float value))
    {
        invoke(SetTobiiGazeDeadzone, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetTobiiGazeFilterStrength(PARAMS(size_t value))
    {
        invoke(SetTobiiGazeFilterStrength, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetTobiiHeadFilterStrength(PARAMS(size_t value))
    {
        invoke(SetTobiiHeadFilterStrength, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetTobiiHeadPositionFactor(PARAMS(float value))
    {
        invoke(SetTobiiHeadPositionFactor, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetTobiiMode(PARAMS(const char* mode))
    {
        invoke(SetTobiiMode, mode);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetTrackedMenuFullscreen(PARAMS(const char* menu,bool fullscreen))
    {
        invoke(SetTrackedMenuFullscreen, menu, fullscreen);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetTurretGroupArmed(PARAMS(UniverseID defensibleid,UniverseID contextid,const char* path,const char* group,bool arm))
    {
        invoke(SetTurretGroupArmed, defensibleid, contextid, path, group, arm);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetTurretGroupMode2(PARAMS(UniverseID defensibleid,UniverseID contextid,const char* path,const char* group,const char* mode))
    {
        invoke(SetTurretGroupMode2, defensibleid, contextid, path, group, mode);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetUIScaleFactor(PARAMS(const float scale))
    {
        invoke(SetUIScaleFactor, scale);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetVRVivePointerHand(PARAMS(int hand))
    {
        invoke(SetVRVivePointerHand, hand);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetVentureOption(PARAMS(bool setting))
    {
        invoke(SetVentureOption, setting);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetVisitorNamesShownOption(PARAMS(bool setting))
    {
        invoke(SetVisitorNamesShownOption, setting);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetWeaponArmed(PARAMS(UniverseID weaponid,bool arm))
    {
        invoke(SetWeaponArmed, weaponid, arm);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetWeaponGroup(PARAMS(UniverseID defensibleid,UniverseID weaponid,bool primary,uint32_t groupidx,bool value))
    {
        invoke(SetWeaponGroup, defensibleid, weaponid, primary, groupidx, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetWeaponMode(PARAMS(UniverseID weaponid,const char* mode))
    {
        invoke(SetWeaponMode, weaponid, mode);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SetWidgetAssociatedElement(PARAMS(const int widgetid,bool value))
    {
        invoke(SetWidgetAssociatedElement, widgetid, value);
        return json
        {
            {"func_res", true}
        };
    }
 
    json ShowBuildPlotPlacementMap(PARAMS(UniverseID holomapid,UniverseID sectorid))
    {
        invoke(ShowBuildPlotPlacementMap, holomapid, sectorid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json ShowConstructionMap(PARAMS(UniverseID holomapid,UniverseID stationid,const char* constructionplanid,bool restore))
    {
        invoke(ShowConstructionMap, holomapid, stationid, constructionplanid, restore);
        return json
        {
            {"func_res", true}
        };
    }
 
    json ShowInteractMenu(PARAMS(const UniverseID componentid,const char*const connectionname,const uint32_t id))
    {
        invoke(ShowInteractMenu, componentid, connectionname, id);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SignalObjectWithNPCSeed(PARAMS(UniverseID objecttosignalid,const char* param,NPCSeed person,UniverseID controllableid))
    {
        invoke(SignalObjectWithNPCSeed, objecttosignalid, param, person, controllableid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json SkipNextStartAnimation(PARAMS())
    {
        invoke(SkipNextStartAnimation);
        return json
        {
            {"func_res", true}
        };
    }
 
    json StartBriefing(PARAMS(MissionID missionid,const char* texturename,bool issubmission))
    {
        invoke(StartBriefing, missionid, texturename, issubmission);
        return json
        {
            {"func_res", true}
        };
    }
 
    json StartIntroAnimation(PARAMS(const char* triggername))
    {
        invoke(StartIntroAnimation, triggername);
        return json
        {
            {"func_res", true}
        };
    }
 
    json StartMapBoxSelect(PARAMS(UniverseID holomapid,bool selectenemies))
    {
        invoke(StartMapBoxSelect, holomapid, selectenemies);
        return json
        {
            {"func_res", true}
        };
    }
 
    json StartPanMap(PARAMS(UniverseID holomapid))
    {
        invoke(StartPanMap, holomapid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json StartPlayerActivity(PARAMS(const char* activityid))
    {
        invoke(StartPlayerActivity, activityid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json StartResearch(PARAMS(const char* wareid,UniverseID researchmoduleid))
    {
        invoke(StartResearch, wareid, researchmoduleid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json StartRotateMap(PARAMS(UniverseID holomapid))
    {
        invoke(StartRotateMap, holomapid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json StartStartMenuBGMusic(PARAMS())
    {
        invoke(StartStartMenuBGMusic);
        return json
        {
            {"func_res", true}
        };
    }
 
    json StartVoiceSequence(PARAMS(const char* sequenceid,UniverseID entityid))
    {
        invoke(StartVoiceSequence, sequenceid, entityid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json StopBriefing(PARAMS(MissionID missionid,bool issubmission))
    {
        invoke(StopBriefing, missionid, issubmission);
        return json
        {
            {"func_res", true}
        };
    }
 
    json StopDetailmonitorCutscene(PARAMS(uint32_t cutsceneid))
    {
        invoke(StopDetailmonitorCutscene, cutsceneid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json StopMapBoxSelect(PARAMS(UniverseID holomapid))
    {
        invoke(StopMapBoxSelect, holomapid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json StopPlayerActivity(PARAMS(const char* activityid))
    {
        invoke(StopPlayerActivity, activityid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json StopStartMenuBGMusic(PARAMS())
    {
        invoke(StopStartMenuBGMusic);
        return json
        {
            {"func_res", true}
        };
    }
 
    json StopVoiceSequence(PARAMS())
    {
        invoke(StopVoiceSequence);
        return json
        {
            {"func_res", true}
        };
    }
 
    json StoreConstructionMapState(PARAMS(UniverseID holomapid))
    {
        invoke(StoreConstructionMapState, holomapid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json TargetRadarComponent(PARAMS())
    {
        invoke(TargetRadarComponent);
        return json
        {
            {"func_res", true}
        };
    }
 
    json ToggleDrones(PARAMS(uint32_t dronetype))
    {
        invoke(ToggleDrones, dronetype);
        return json
        {
            {"func_res", true}
        };
    }
 
    json ToggleFlightAssist(PARAMS())
    {
        invoke(ToggleFlightAssist);
        return json
        {
            {"func_res", true}
        };
    }
 
    json ToggleScreenDisplayOption(PARAMS())
    {
        invoke(ToggleScreenDisplayOption);
        return json
        {
            {"func_res", true}
        };
    }
 
    json TrackMenu(PARAMS(const char* menu,bool fullscreen))
    {
        invoke(TrackMenu, menu, fullscreen);
        return json
        {
            {"func_res", true}
        };
    }
 
    json UndoConstructionMapChange(PARAMS(UniverseID holomapid))
    {
        invoke(UndoConstructionMapChange, holomapid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json UnmutePlayerAlert(PARAMS(size_t index,bool silent))
    {
        invoke(UnmutePlayerAlert, index, silent);
        return json
        {
            {"func_res", true}
        };
    }
 
    json UnsetRadarRenderTarget(PARAMS())
    {
        invoke(UnsetRadarRenderTarget);
        return json
        {
            {"func_res", true}
        };
    }
 
    json UpdateMapBuildPlot(PARAMS(UniverseID holomapid))
    {
        invoke(UpdateMapBuildPlot, holomapid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json UpdateProduction(PARAMS(UniverseID containerormoduleid,bool force))
    {
        invoke(UpdateProduction, containerormoduleid, force);
        return json
        {
            {"func_res", true}
        };
    }
 
    json UpdateProductionTradeOffers(PARAMS(UniverseID containerid))
    {
        invoke(UpdateProductionTradeOffers, containerid);
        return json
        {
            {"func_res", true}
        };
    }
 
    json UpdateSupplyOverrides(PARAMS(UniverseID containerid,uint32_t numoverrides))
    {
        SupplyOverride overrides;
        invoke(UpdateSupplyOverrides, containerid, &overrides, numoverrides);
          {
            return json
            {
                {"func_res", true},
                {"overrides", {
                    {"macro", overrides.macro},
                    {"amount", overrides.amount}
                }}
            };
        }
 
    }
 
    json ZoomMap(PARAMS(UniverseID holomapid,float zoomstep))
    {
        invoke(ZoomMap, holomapid, zoomstep);
        return json
        {
            {"func_res", true}
        };
    }
 
}
