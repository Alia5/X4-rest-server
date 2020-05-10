
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
        const auto callResult = invoke(GetCrosshairArrowDetails, posid, radius);
        return json
        {
            {"angle", callResult.angle},
            {"inside", callResult.inside},
            {"valid", callResult.valid}
        };
    }
 
    json GetAutosaveIntervalOption(PARAMS())
    {
        const auto callResult = invoke(GetAutosaveIntervalOption);
        return json
        {
            {"mintime", callResult.mintime},
            {"maxtime", callResult.maxtime},
            {"factor", callResult.factor}
        };
    }
 
    json GetBlacklistInfoCounts(PARAMS(BlacklistID id))
    {
        const auto callResult = invoke(GetBlacklistInfoCounts, id);
        return json
        {
            {"nummacros", callResult.nummacros},
            {"numfactions", callResult.numfactions}
        };
    }
 
    json GetControllableBlacklistID(PARAMS(UniverseID controllableid,const char* listtype,const char* defaultgroup))
    {
        const auto callResult = invoke(GetControllableBlacklistID, controllableid, listtype, defaultgroup);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetBoardingRiskThresholds(PARAMS(UniverseID defensibletargetid,const char* boarderfactionid))
    {
        const auto callResult = invoke(GetBoardingRiskThresholds, defensibletargetid, boarderfactionid);
        return json
        {
            {"approach", callResult.approach},
            {"insertion", callResult.insertion}
        };
    }
 
    json GetBuildTaskInfo(PARAMS(BuildTaskID id))
    {
        const auto callResult = invoke(GetBuildTaskInfo, id);
        return json
        {
            {"id", callResult.id},
            {"buildingcontainer", callResult.buildingcontainer},
            {"component", callResult.component},
            {"macro", callResult.macro},
            {"factionid", callResult.factionid},
            {"buildercomponent", callResult.buildercomponent},
            {"price", callResult.price},
            {"ismissingresources", callResult.ismissingresources},
            {"queueposition", callResult.queueposition}
        };
    }
 
    json GetComponentDetails(PARAMS(const UniverseID componentid,const char*const connectionname))
    {
        const auto callResult = invoke(GetComponentDetails, componentid, connectionname);
        return json
        {
            {"name", callResult.name},
            {"hull", callResult.hull},
            {"shield", callResult.shield},
            {"speed", callResult.speed},
            {"hasShield", callResult.hasShield}
        };
    }
 
    json GetCenteredMousePos(PARAMS())
    {
        const auto callResult = invoke(GetCenteredMousePos);
        return json
        {
            {"x", callResult.x},
            {"y", callResult.y}
        };
    }
 
    json GetWidgetSystemSizeOverride(PARAMS())
    {
        const auto callResult = invoke(GetWidgetSystemSizeOverride);
        return json
        {
            {"x", callResult.x},
            {"y", callResult.y}
        };
    }
 
    json GetBuildPlotCenterOffset(PARAMS(UniverseID stationid))
    {
        const auto callResult = invoke(GetBuildPlotCenterOffset, stationid);
        return json
        {
            {"x", callResult.x},
            {"y", callResult.y},
            {"z", callResult.z}
        };
    }
 
    json GetBuildPlotSize(PARAMS(UniverseID stationid))
    {
        const auto callResult = invoke(GetBuildPlotSize, stationid);
        return json
        {
            {"x", callResult.x},
            {"y", callResult.y},
            {"z", callResult.z}
        };
    }
 
    json GetMinimumBuildPlotCenterOffset(PARAMS(UniverseID stationid))
    {
        const auto callResult = invoke(GetMinimumBuildPlotCenterOffset, stationid);
        return json
        {
            {"x", callResult.x},
            {"y", callResult.y},
            {"z", callResult.z}
        };
    }
 
    json GetMinimumBuildPlotSize(PARAMS(UniverseID stationid))
    {
        const auto callResult = invoke(GetMinimumBuildPlotSize, stationid);
        return json
        {
            {"x", callResult.x},
            {"y", callResult.y},
            {"z", callResult.z}
        };
    }
 
    json GetPaidBuildPlotCenterOffset(PARAMS(UniverseID stationid))
    {
        const auto callResult = invoke(GetPaidBuildPlotCenterOffset, stationid);
        return json
        {
            {"x", callResult.x},
            {"y", callResult.y},
            {"z", callResult.z}
        };
    }
 
    json GetPaidBuildPlotSize(PARAMS(UniverseID stationid))
    {
        const auto callResult = invoke(GetPaidBuildPlotSize, stationid);
        return json
        {
            {"x", callResult.x},
            {"y", callResult.y},
            {"z", callResult.z}
        };
    }
 
    json GetNumBuildTaskCrewTransferInfo(PARAMS(UniverseID containerid,BuildTaskID id))
    {
        const auto callResult = invoke(GetNumBuildTaskCrewTransferInfo, containerid, id);
        return json
        {
            {"numremoved", callResult.numremoved},
            {"numadded", callResult.numadded},
            {"numtransferred", callResult.numtransferred}
        };
    }
 
    json GetCurrentCrosshairMessage(PARAMS())
    {
        const auto callResult = invoke(GetCurrentCrosshairMessage);
        return json
        {
            {"messageID", callResult.messageID},
            {"obstructed", callResult.obstructed}
        };
    }
 
    json GetCurrentCursorInfo(PARAMS())
    {
        const auto callResult = invoke(GetCurrentCursorInfo);
        return json
        {
            {"width", callResult.width},
            {"height", callResult.height},
            {"xHotspot", callResult.xHotspot},
            {"yHotspot", callResult.yHotspot}
        };
    }
 
    json GetCustomGameStartBlueprintPropertyState(PARAMS(const char* id,const char* propertyid))
    {
        const auto callResult = invoke(GetCustomGameStartBlueprintPropertyState, id, propertyid);
        return json
        {
            {"state", callResult.state},
            {"numvalues", callResult.numvalues},
            {"numdefaultvalues", callResult.numdefaultvalues}
        };
    }
 
    json GetCustomGameStartEncyclopediaPropertyState(PARAMS(const char* id,const char* propertyid))
    {
        const auto callResult = invoke(GetCustomGameStartEncyclopediaPropertyState, id, propertyid);
        return json
        {
            {"state", callResult.state}
        };
    }
 
    json GetCustomGameStartInventoryPropertyState(PARAMS(const char* id,const char* propertyid))
    {
        const auto callResult = invoke(GetCustomGameStartInventoryPropertyState, id, propertyid);
        return json
        {
            {"state", callResult.state},
            {"numvalues", callResult.numvalues},
            {"numdefaultvalues", callResult.numdefaultvalues}
        };
    }
 
    json GetCustomGameStartLoadoutPropertyState(PARAMS(const char* id,const char* propertyid))
    {
        const auto callResult = invoke(GetCustomGameStartLoadoutPropertyState, id, propertyid);
        return json
        {
            {"state", callResult.state}
        };
    }
 
    json GetCustomGameStartRelationsPropertyState(PARAMS(const char* id,const char* propertyid))
    {
        const auto callResult = invoke(GetCustomGameStartRelationsPropertyState, id, propertyid);
        return json
        {
            {"state", callResult.state}
        };
    }
 
    json GetCustomGameStartResearchPropertyState(PARAMS(const char* id,const char* propertyid))
    {
        const auto callResult = invoke(GetCustomGameStartResearchPropertyState, id, propertyid);
        return json
        {
            {"state", callResult.state}
        };
    }
 
    json GetDroneDetails(PARAMS(const uint32_t dronetype))
    {
        const auto callResult = invoke(GetDroneDetails, dronetype);
        return json
        {
            {"armed", callResult.armed},
            {"blocked", callResult.blocked},
            {"modeIcon", callResult.modeIcon},
            {"pending", callResult.pending},
            {"possible", callResult.possible},
            {"total", callResult.total},
            {"undocked", callResult.undocked}
        };
    }
 
    json GetEquipmentModInfo(PARAMS(const char* wareid))
    {
        const auto callResult = invoke(GetEquipmentModInfo, wareid);
        return json
        {
            {"PropertyType", callResult.PropertyType},
            {"MinValueFloat", callResult.MinValueFloat},
            {"MaxValueFloat", callResult.MaxValueFloat},
            {"MinValueUINT", callResult.MinValueUINT},
            {"MaxValueUINT", callResult.MaxValueUINT},
            {"BonusMax", callResult.BonusMax},
            {"BonusChance", callResult.BonusChance}
        };
    }
 
    json GetFPS(PARAMS())
    {
        const auto callResult = invoke(GetFPS);
        return json
        {
            {"fps", callResult.fps},
            {"moveTime", callResult.moveTime},
            {"renderTime", callResult.renderTime},
            {"gpuTime", callResult.gpuTime}
        };
    }
 
    json GetFactionDetails(PARAMS(const char* factionid))
    {
        const auto callResult = invoke(GetFactionDetails, factionid);
        return json
        {
            {"factionID", callResult.factionID},
            {"factionName", callResult.factionName},
            {"factionIcon", callResult.factionIcon}
        };
    }
 
    json GetOwnerDetails(PARAMS(UniverseID componentid))
    {
        const auto callResult = invoke(GetOwnerDetails, componentid);
        return json
        {
            {"factionID", callResult.factionID},
            {"factionName", callResult.factionName},
            {"factionIcon", callResult.factionIcon}
        };
    }
 
    json GetGameVersion(PARAMS())
    {
        const auto callResult = invoke(GetGameVersion);
        return json
        {
            {"major", callResult.major},
            {"minor", callResult.minor}
        };
    }
 
    json GetMissionOfferIcons(PARAMS(const UniverseID componentid))
    {
        const auto callResult = invoke(GetMissionOfferIcons, componentid);
        return json
        {
            {"active", callResult.active},
            {"inactive", callResult.inactive},
            {"select", callResult.select}
        };
    }
 
    json GetLastAttackInfo(PARAMS(UniverseID destructibleid))
    {
        const auto callResult = invoke(GetLastAttackInfo, destructibleid);
        return json
        {
            {"attacker", callResult.attacker},
            {"time", callResult.time},
            {"method", callResult.method}
        };
    }
 
    json GetMessageDetails2(PARAMS(uint32_t messageid))
    {
        const auto callResult = invoke(GetMessageDetails2, messageid);
        return json
        {
            {"poiID", callResult.poiID},
            {"componentID", callResult.componentID},
            {"messageType", callResult.messageType},
            {"connectionName", callResult.connectionName},
            {"isAssociative", callResult.isAssociative},
            {"isMissionTarget", callResult.isMissionTarget},
            {"isPriorityMissionTarget", callResult.isPriorityMissionTarget},
            {"showIndicator", callResult.showIndicator}
        };
    }
 
    json GetMissionBriefingIcon(PARAMS(MissionID missionid))
    {
        const auto callResult = invoke(GetMissionBriefingIcon, missionid);
        return json
        {
            {"icon", callResult.icon},
            {"caption", callResult.caption}
        };
    }
 
    json GetMissionIDDetails(PARAMS(uint64_t missionid))
    {
        const auto callResult = invoke(GetMissionIDDetails, missionid);
        return json
        {
            {"missionName", callResult.missionName},
            {"missionDescription", callResult.missionDescription},
            {"difficulty", callResult.difficulty},
            {"upkeepalertlevel", callResult.upkeepalertlevel},
            {"threadType", callResult.threadType},
            {"mainType", callResult.mainType},
            {"subType", callResult.subType},
            {"subTypeName", callResult.subTypeName},
            {"faction", callResult.faction},
            {"reward", callResult.reward},
            {"rewardText", callResult.rewardText},
            {"numBriefingObjectives", callResult.numBriefingObjectives},
            {"activeBriefingStep", callResult.activeBriefingStep},
            {"opposingFaction", callResult.opposingFaction},
            {"license", callResult.license},
            {"timeLeft", callResult.timeLeft},
            {"duration", callResult.duration},
            {"abortable", callResult.abortable},
            {"hasObjective", callResult.hasObjective},
            {"associatedComponent", callResult.associatedComponent},
            {"threadMissionID", callResult.threadMissionID}
        };
    }
 
    json GetMissionGroupDetails(PARAMS(MissionID missionid))
    {
        const auto callResult = invoke(GetMissionGroupDetails, missionid);
        return json
        {
            {"id", callResult.id},
            {"name", callResult.name}
        };
    }
 
    json GetPickedMapMission(PARAMS(UniverseID holomapid))
    {
        const auto callResult = invoke(GetPickedMapMission, holomapid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetMissionInfo2(PARAMS())
    {
        const auto callResult = invoke(GetMissionInfo2);
        return json
        {
            {"active", callResult.active},
            {"callbackMode", callResult.callbackMode},
            {"barLine", callResult.barLine},
            {"barPercent", callResult.barPercent},
            {"line1Left", callResult.line1Left},
            {"line1Right", callResult.line1Right},
            {"line2Left", callResult.line2Left},
            {"line2Right", callResult.line2Right},
            {"line3Left", callResult.line3Left},
            {"line3Right", callResult.line3Right},
            {"line4Left", callResult.line4Left},
            {"line4Right", callResult.line4Right},
            {"missionBarText", callResult.missionBarText}
        };
    }
 
    json GetMissionIDObjective(PARAMS(uint64_t missionid))
    {
        const auto callResult = invoke(GetMissionIDObjective, missionid);
        return json
        {
            {"objectiveText", callResult.objectiveText},
            {"timeout", callResult.timeout},
            {"numTargets", callResult.numTargets}
        };
    }
 
    json GetMissionObjectiveStep2(PARAMS(uint64_t missionid,size_t objectiveIndex))
    {
        const auto callResult = invoke(GetMissionObjectiveStep2, missionid, objectiveIndex);
        return json
        {
            {"text", callResult.text},
            {"step", callResult.step},
            {"failed", callResult.failed}
        };
    }
 
    json GetPOIDetails(PARAMS(const uint64_t poiid))
    {
        const auto callResult = invoke(GetPOIDetails, poiid);
        return json
        {
            {"POIName", callResult.POIName},
            {"POIType", callResult.POIType}
        };
    }
 
    json GetRelativeAimOffset(PARAMS(const UniverseID componentid))
    {
        const auto callResult = invoke(GetRelativeAimOffset, componentid);
        return json
        {
            {"x", callResult.x},
            {"y", callResult.y},
            {"z", callResult.z},
            {"yaw", callResult.yaw},
            {"pitch", callResult.pitch},
            {"roll", callResult.roll}
        };
    }
 
    json GetTargetElementOffset(PARAMS(const int posid))
    {
        const auto callResult = invoke(GetTargetElementOffset, posid);
        return json
        {
            {"x", callResult.x},
            {"y", callResult.y},
            {"z", callResult.z},
            {"yaw", callResult.yaw},
            {"pitch", callResult.pitch},
            {"roll", callResult.roll}
        };
    }
 
    json GetRelativeAimScreenPosition(PARAMS(const UniverseID componentid,const uint32_t iconsizeonscreen,const uint32_t iconsizeoffscreen))
    {
        const auto callResult = invoke(GetRelativeAimScreenPosition, componentid, iconsizeonscreen, iconsizeoffscreen);
        return json
        {
            {"x", callResult.x},
            {"y", callResult.y}
        };
    }
 
    json GetFactionRelationStatus(PARAMS(const char* factionid))
    {
        const auto callResult = invoke(GetFactionRelationStatus, factionid);
        return json
        {
            {"relationStatus", callResult.relationStatus},
            {"relationValue", callResult.relationValue},
            {"relationLEDValue", callResult.relationLEDValue},
            {"isBoostedValue", callResult.isBoostedValue}
        };
    }
 
    json GetRelationStatus2(PARAMS(const UniverseID componentid,const char*const connectionname))
    {
        const auto callResult = invoke(GetRelationStatus2, componentid, connectionname);
        return json
        {
            {"relationStatus", callResult.relationStatus},
            {"relationValue", callResult.relationValue},
            {"relationLEDValue", callResult.relationLEDValue},
            {"isBoostedValue", callResult.isBoostedValue}
        };
    }
 
    json GetGameResolution(PARAMS())
    {
        const auto callResult = invoke(GetGameResolution);
        return json
        {
            {"x", callResult.x},
            {"y", callResult.y}
        };
    }
 
    json GetRenderResolutionOption(PARAMS())
    {
        const auto callResult = invoke(GetRenderResolutionOption);
        return json
        {
            {"x", callResult.x},
            {"y", callResult.y}
        };
    }
 
    json GetCameraRotation(PARAMS())
    {
        const auto callResult = invoke(GetCameraRotation);
        return json
        {
            {"yaw", callResult.yaw},
            {"pitch", callResult.pitch},
            {"roll", callResult.roll}
        };
    }
 
    json GetComponentScreenPosition(PARAMS(const UniverseID componentid,const uint32_t iconsizeonscreen,const uint32_t iconsizeoffscreen))
    {
        const auto callResult = invoke(GetComponentScreenPosition, componentid, iconsizeonscreen, iconsizeoffscreen);
        return json
        {
            {"x", callResult.x},
            {"y", callResult.y},
            {"onScreen", callResult.onScreen}
        };
    }
 
    json GetSofttarget(PARAMS())
    {
        const auto callResult = invoke(GetSofttarget);
        return json
        {
            {"softtargetID", callResult.softtargetID},
            {"softtargetConnectionName", callResult.softtargetConnectionName}
        };
    }
 
    json GetSpecialNPCs(PARAMS(const UniverseID componentid))
    {
        const auto callResult = invoke(GetSpecialNPCs, componentid);
        return json
        {
            {"factionNPC", callResult.factionNPC},
            {"missionActor", callResult.missionActor},
            {"shadyGuy", callResult.shadyGuy}
        };
    }
 
    json GetTableInitialSelectionInfo(PARAMS(const int tableid))
    {
        const auto callResult = invoke(GetTableInitialSelectionInfo, tableid);
        return json
        {
            {"toprow", callResult.toprow},
            {"selectedrow", callResult.selectedrow},
            {"selectedcol", callResult.selectedcol},
            {"shiftstart", callResult.shiftstart},
            {"shiftend", callResult.shiftend}
        };
    }
 
    json GetPickedMapTradeOffer(PARAMS(UniverseID holomapid))
    {
        const auto callResult = invoke(GetPickedMapTradeOffer, holomapid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetTurret(PARAMS(size_t turretnum))
    {
        const auto callResult = invoke(GetTurret, turretnum);
        return json
        {
            {"icon", callResult.icon},
            {"mode", callResult.mode},
            {"damageState", callResult.damageState},
            {"active", callResult.active},
            {"usesAmmo", callResult.usesAmmo},
            {"ammo", callResult.ammo}
        };
    }
 
    json SetFormationShape(PARAMS(UniverseID objectid,const char* formationshape))
    {
        const auto callResult = invoke(SetFormationShape, objectid, formationshape);
        return json
        {
            {"shape", callResult.shape},
            {"name", callResult.name},
            {"requiredSkill", callResult.requiredSkill},
            {"radius", callResult.radius},
            {"rollMembers", callResult.rollMembers},
            {"rollFormation", callResult.rollFormation},
            {"maxShipsPerLine", callResult.maxShipsPerLine}
        };
    }
 
    json GetFrameBackground2Info(PARAMS(const int frameid))
    {
        const auto callResult = invoke(GetFrameBackground2Info, frameid);
        return json
        {
            {"iconid", callResult.iconid},
            {"color", {"red", callResult.color.red},{"green", callResult.color.green},{"blue", callResult.color.blue},{"alpha", callResult.color.alpha}},
            {"width", callResult.width},
            {"height", callResult.height},
            {"rotationrate", callResult.rotationrate},
            {"rotstart", callResult.rotstart},
            {"rotduration", callResult.rotduration},
            {"rotinterval", callResult.rotinterval},
            {"initscale", callResult.initscale},
            {"scaleduration", callResult.scaleduration}
        };
    }
 
    json GetFrameBackgroundInfo(PARAMS(const int frameid))
    {
        const auto callResult = invoke(GetFrameBackgroundInfo, frameid);
        return json
        {
            {"iconid", callResult.iconid},
            {"color", {"red", callResult.color.red},{"green", callResult.color.green},{"blue", callResult.color.blue},{"alpha", callResult.color.alpha}},
            {"width", callResult.width},
            {"height", callResult.height},
            {"rotationrate", callResult.rotationrate},
            {"rotstart", callResult.rotstart},
            {"rotduration", callResult.rotduration},
            {"rotinterval", callResult.rotinterval},
            {"initscale", callResult.initscale},
            {"scaleduration", callResult.scaleduration}
        };
    }
 
    json GetFrameOverlayInfo(PARAMS(const int frameid))
    {
        const auto callResult = invoke(GetFrameOverlayInfo, frameid);
        return json
        {
            {"iconid", callResult.iconid},
            {"color", {"red", callResult.color.red},{"green", callResult.color.green},{"blue", callResult.color.blue},{"alpha", callResult.color.alpha}},
            {"width", callResult.width},
            {"height", callResult.height},
            {"rotationrate", callResult.rotationrate},
            {"rotstart", callResult.rotstart},
            {"rotduration", callResult.rotduration},
            {"rotinterval", callResult.rotinterval},
            {"initscale", callResult.initscale},
            {"scaleduration", callResult.scaleduration}
        };
    }
 
    json GetCurrentLoadoutStatistics2(PARAMS(UniverseID shipid))
    {
        const auto callResult = invoke(GetCurrentLoadoutStatistics2, shipid);
        return json
        {
            {"HullValue", callResult.HullValue},
            {"ShieldValue", callResult.ShieldValue},
            {"GroupedShieldValue", callResult.GroupedShieldValue},
            {"BurstDPS", callResult.BurstDPS},
            {"SustainedDPS", callResult.SustainedDPS},
            {"TurretBurstDPS", callResult.TurretBurstDPS},
            {"TurretSustainedDPS", callResult.TurretSustainedDPS},
            {"GroupedTurretBurstDPS", callResult.GroupedTurretBurstDPS},
            {"GroupedTurretSustainedDPS", callResult.GroupedTurretSustainedDPS},
            {"ForwardSpeed", callResult.ForwardSpeed},
            {"BoostSpeed", callResult.BoostSpeed},
            {"TravelSpeed", callResult.TravelSpeed},
            {"YawSpeed", callResult.YawSpeed},
            {"PitchSpeed", callResult.PitchSpeed},
            {"RollSpeed", callResult.RollSpeed},
            {"ForwardAcceleration", callResult.ForwardAcceleration},
            {"NumDocksShipMedium", callResult.NumDocksShipMedium},
            {"NumDocksShipSmall", callResult.NumDocksShipSmall},
            {"ShipCapacityMedium", callResult.ShipCapacityMedium},
            {"ShipCapacitySmall", callResult.ShipCapacitySmall},
            {"CrewCapacity", callResult.CrewCapacity},
            {"ContainerCapacity", callResult.ContainerCapacity},
            {"SolidCapacity", callResult.SolidCapacity},
            {"LiquidCapacity", callResult.LiquidCapacity},
            {"UnitCapacity", callResult.UnitCapacity},
            {"MissileCapacity", callResult.MissileCapacity},
            {"CountermeasureCapacity", callResult.CountermeasureCapacity},
            {"DeployableCapacity", callResult.DeployableCapacity},
            {"RadarRange", callResult.RadarRange}
        };
    }
 
    json GetMaxLoadoutStatistics2(PARAMS(UniverseID shipid,const char* macroname))
    {
        const auto callResult = invoke(GetMaxLoadoutStatistics2, shipid, macroname);
        return json
        {
            {"HullValue", callResult.HullValue},
            {"ShieldValue", callResult.ShieldValue},
            {"GroupedShieldValue", callResult.GroupedShieldValue},
            {"BurstDPS", callResult.BurstDPS},
            {"SustainedDPS", callResult.SustainedDPS},
            {"TurretBurstDPS", callResult.TurretBurstDPS},
            {"TurretSustainedDPS", callResult.TurretSustainedDPS},
            {"GroupedTurretBurstDPS", callResult.GroupedTurretBurstDPS},
            {"GroupedTurretSustainedDPS", callResult.GroupedTurretSustainedDPS},
            {"ForwardSpeed", callResult.ForwardSpeed},
            {"BoostSpeed", callResult.BoostSpeed},
            {"TravelSpeed", callResult.TravelSpeed},
            {"YawSpeed", callResult.YawSpeed},
            {"PitchSpeed", callResult.PitchSpeed},
            {"RollSpeed", callResult.RollSpeed},
            {"ForwardAcceleration", callResult.ForwardAcceleration},
            {"NumDocksShipMedium", callResult.NumDocksShipMedium},
            {"NumDocksShipSmall", callResult.NumDocksShipSmall},
            {"ShipCapacityMedium", callResult.ShipCapacityMedium},
            {"ShipCapacitySmall", callResult.ShipCapacitySmall},
            {"CrewCapacity", callResult.CrewCapacity},
            {"ContainerCapacity", callResult.ContainerCapacity},
            {"SolidCapacity", callResult.SolidCapacity},
            {"LiquidCapacity", callResult.LiquidCapacity},
            {"UnitCapacity", callResult.UnitCapacity},
            {"MissileCapacity", callResult.MissileCapacity},
            {"CountermeasureCapacity", callResult.CountermeasureCapacity},
            {"DeployableCapacity", callResult.DeployableCapacity},
            {"RadarRange", callResult.RadarRange}
        };
    }
 
    json GetCurrentPlayerLogo(PARAMS())
    {
        const auto callResult = invoke(GetCurrentPlayerLogo);
        return json
        {
            {"file", callResult.file},
            {"icon", callResult.icon},
            {"ispersonal", callResult.ispersonal}
        };
    }
 
    json GetMapTradeVolumeParameter(PARAMS())
    {
        const auto callResult = invoke(GetMapTradeVolumeParameter);
        return json
        {
            {"icon", callResult.icon},
            {"color", {"red", callResult.color.red},{"green", callResult.color.green},{"blue", callResult.color.blue},{"alpha", callResult.color.alpha}},
            {"volume_s", callResult.volume_s},
            {"volume_m", callResult.volume_m},
            {"volume_l", callResult.volume_l}
        };
    }
 
    json GetHelpOverlayInfo(PARAMS(const int widgetid))
    {
        const auto callResult = invoke(GetHelpOverlayInfo, widgetid);
        return json
        {
            {"id", callResult.id},
            {"text", callResult.text},
            {"x", callResult.x},
            {"y", callResult.y},
            {"width", callResult.width},
            {"height", callResult.height},
            {"highlightonly", callResult.highlightonly}
        };
    }
 
    json GetStandardButtonHelpOverlayInfo(PARAMS(const int frameid,const char* button))
    {
        const auto callResult = invoke(GetStandardButtonHelpOverlayInfo, frameid, button);
        return json
        {
            {"id", callResult.id},
            {"text", callResult.text},
            {"x", callResult.x},
            {"y", callResult.y},
            {"width", callResult.width},
            {"height", callResult.height},
            {"highlightonly", callResult.highlightonly}
        };
    }
 
    json GetCustomGameStartPosRotProperty(PARAMS(const char* id,const char* propertyid))
    {
        CustomGameStartPosRotPropertyState state;
        const auto callResult = invoke(GetCustomGameStartPosRotProperty, id, propertyid, &state);
          {
            return json
            {
                {"x", callResult.x},
                {"y", callResult.y},
                {"z", callResult.z},
                {"yaw", callResult.yaw},
                {"pitch", callResult.pitch},
                {"roll", callResult.roll},
                {"state", {
                    {"state", state.state},
                    {"defaultvalue", {"x", state.defaultvalue.x},{"y", state.defaultvalue.y},{"z", state.defaultvalue.z},{"yaw", state.defaultvalue.yaw},{"pitch", state.defaultvalue.pitch},{"roll", state.defaultvalue.roll}}
                }}
            };
        }
 
    }
 
    json GetObjectPositionInSector(PARAMS(UniverseID objectid))
    {
        const auto callResult = invoke(GetObjectPositionInSector, objectid);
        return json
        {
            {"x", callResult.x},
            {"y", callResult.y},
            {"z", callResult.z},
            {"yaw", callResult.yaw},
            {"pitch", callResult.pitch},
            {"roll", callResult.roll}
        };
    }
 
    json GetPlayerTargetOffset(PARAMS())
    {
        const auto callResult = invoke(GetPlayerTargetOffset);
        return json
        {
            {"x", callResult.x},
            {"y", callResult.y},
            {"z", callResult.z},
            {"yaw", callResult.yaw},
            {"pitch", callResult.pitch},
            {"roll", callResult.roll}
        };
    }
 
    json GetLastSaveInfo(PARAMS())
    {
        const auto callResult = invoke(GetLastSaveInfo);
        return json
        {
            {"filename", callResult.filename},
            {"name", callResult.name},
            {"description", callResult.description},
            {"version", callResult.version},
            {"rawversion", callResult.rawversion},
            {"time", callResult.time},
            {"rawtime", callResult.rawtime},
            {"playtime", callResult.playtime},
            {"playername", callResult.playername},
            {"location", callResult.location},
            {"money", callResult.money},
            {"error", callResult.error},
            {"invalidgameid", callResult.invalidgameid},
            {"invalidversion", callResult.invalidversion},
            {"numinvalidpatches", callResult.numinvalidpatches}
        };
    }
 
    json GetNumUISystemInfo(PARAMS(UniverseID clusterid))
    {
        const auto callResult = invoke(GetNumUISystemInfo, clusterid);
        return json
        {
            {"numsuns", callResult.numsuns},
            {"numplanets", callResult.numplanets}
        };
    }
 
    json GetCurrentVentureMissionInfo(PARAMS(UniverseID ventureplatformid))
    {
        const auto callResult = invoke(GetCurrentVentureMissionInfo, ventureplatformid);
        return json
        {
            {"name", callResult.name},
            {"icon", callResult.icon},
            {"rewardicon", callResult.rewardicon},
            {"remainingtime", callResult.remainingtime},
            {"numships", callResult.numships}
        };
    }
 
    json AddHoloMap(PARAMS(const char* texturename,float x0,float x1,float y0,float y1,float aspectx,float aspecty))
    {
        const auto callResult = invoke(AddHoloMap, texturename, x0, x1, y0, y1, aspectx, aspecty);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json CreateNPCFromPerson(PARAMS(NPCSeed person,UniverseID controllableid))
    {
        const auto callResult = invoke(CreateNPCFromPerson, person, controllableid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetCommonContext(PARAMS(UniverseID componentid,UniverseID othercomponentid,bool includeself,bool includeother,UniverseID limitid,bool includelimit))
    {
        const auto callResult = invoke(GetCommonContext, componentid, othercomponentid, includeself, includeother, limitid, includelimit);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetContextByClass(PARAMS(UniverseID componentid,const char* classname,bool includeself))
    {
        const auto callResult = invoke(GetContextByClass, componentid, classname, includeself);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetContextForTransporterCheck(PARAMS(UniverseID positionalid))
    {
        const auto callResult = invoke(GetContextForTransporterCheck, positionalid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetEnvironmentObject(PARAMS())
    {
        const auto callResult = invoke(GetEnvironmentObject);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetExternalTargetViewComponent(PARAMS())
    {
        const auto callResult = invoke(GetExternalTargetViewComponent);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetFactionRepresentative(PARAMS(const char* factionid))
    {
        const auto callResult = invoke(GetFactionRepresentative, factionid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetInstantiatedPerson(PARAMS(NPCSeed person,UniverseID controllableid))
    {
        const auto callResult = invoke(GetInstantiatedPerson, person, controllableid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetLastPlayerControlledShipID(PARAMS())
    {
        const auto callResult = invoke(GetLastPlayerControlledShipID);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetMissionIDObjectiveTarget(PARAMS(uint64_t missionid,size_t targetIndex))
    {
        const auto callResult = invoke(GetMissionIDObjectiveTarget, missionid, targetIndex);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetParentComponent(PARAMS(UniverseID componentid))
    {
        const auto callResult = invoke(GetParentComponent, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPickedMapComponent(PARAMS(UniverseID holomapid))
    {
        const auto callResult = invoke(GetPickedMapComponent, holomapid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPickedMapMissionOffer(PARAMS(UniverseID holomapid))
    {
        const auto callResult = invoke(GetPickedMapMissionOffer, holomapid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPickedMapOrder(PARAMS(UniverseID holomapid))
    {
        Order result;
        bool intermediate;
        const auto callResult = invoke(GetPickedMapOrder, holomapid, &result, &intermediate);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetPlayerComputerID(PARAMS())
    {
        const auto callResult = invoke(GetPlayerComputerID);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPlayerContainerID(PARAMS())
    {
        const auto callResult = invoke(GetPlayerContainerID);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPlayerControlledShipID(PARAMS())
    {
        const auto callResult = invoke(GetPlayerControlledShipID);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPlayerID(PARAMS())
    {
        const auto callResult = invoke(GetPlayerID);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPlayerObjectID(PARAMS())
    {
        const auto callResult = invoke(GetPlayerObjectID);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPlayerOccupiedShipID(PARAMS())
    {
        const auto callResult = invoke(GetPlayerOccupiedShipID);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPlayerShipID(PARAMS())
    {
        const auto callResult = invoke(GetPlayerShipID);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPlayerZoneID(PARAMS())
    {
        const auto callResult = invoke(GetPlayerZoneID);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetSectorControlStation(PARAMS(UniverseID sectorid))
    {
        const auto callResult = invoke(GetSectorControlStation, sectorid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetTopLevelContainer(PARAMS(UniverseID componentid))
    {
        const auto callResult = invoke(GetTopLevelContainer, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetUpgradeSlotCurrentComponent(PARAMS(UniverseID destructibleid,const char* upgradetypename,size_t slot))
    {
        const auto callResult = invoke(GetUpgradeSlotCurrentComponent, destructibleid, upgradetypename, slot);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetZoneAt(PARAMS(UniverseID sectorid))
    {
        UIPosRot uioffset;
        const auto callResult = invoke(GetZoneAt, sectorid, &uioffset);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetUpgradeSlotGroup(PARAMS(UniverseID destructibleid,const char* macroname,const char* upgradetypename,size_t slot))
    {
        const auto callResult = invoke(GetUpgradeSlotGroup, destructibleid, macroname, upgradetypename, slot);
        return json
        {
            {"path", callResult.path},
            {"group", callResult.group}
        };
    }
 
    json GetUpgradeGroupInfo(PARAMS(UniverseID destructibleid,const char* macroname,const char* path,const char* group,const char* upgradetypename))
    {
        const auto callResult = invoke(GetUpgradeGroupInfo, destructibleid, macroname, path, group, upgradetypename);
        return json
        {
            {"currentcomponent", callResult.currentcomponent},
            {"currentmacro", callResult.currentmacro},
            {"slotsize", callResult.slotsize},
            {"count", callResult.count},
            {"operational", callResult.operational},
            {"total", callResult.total}
        };
    }
 
    json GetUpgradeGroupInfo2(PARAMS(UniverseID destructibleid,const char* macroname,UniverseID contextid,const char* path,const char* group,const char* upgradetypename))
    {
        const auto callResult = invoke(GetUpgradeGroupInfo2, destructibleid, macroname, contextid, path, group, upgradetypename);
        return json
        {
            {"currentcomponent", callResult.currentcomponent},
            {"currentmacro", callResult.currentmacro},
            {"slotsize", callResult.slotsize},
            {"count", callResult.count},
            {"operational", callResult.operational},
            {"total", callResult.total}
        };
    }
 
    json GetPrimaryWeapon(PARAMS(size_t weaponnum))
    {
        const auto callResult = invoke(GetPrimaryWeapon, weaponnum);
        return json
        {
            {"icon", callResult.icon},
            {"damageState", callResult.damageState},
            {"active", callResult.active},
            {"usesAmmo", callResult.usesAmmo},
            {"ammo", callResult.ammo},
            {"mode", callResult.mode},
            {"reloadPercent", callResult.reloadPercent},
            {"heatState", callResult.heatState},
            {"heatPercent", callResult.heatPercent},
            {"lockPercent", callResult.lockPercent},
            {"counterMeasureTarget", callResult.counterMeasureTarget}
        };
    }
 
    json GetSecondaryWeapon(PARAMS(size_t weaponnum))
    {
        const auto callResult = invoke(GetSecondaryWeapon, weaponnum);
        return json
        {
            {"icon", callResult.icon},
            {"damageState", callResult.damageState},
            {"active", callResult.active},
            {"usesAmmo", callResult.usesAmmo},
            {"ammo", callResult.ammo},
            {"mode", callResult.mode},
            {"reloadPercent", callResult.reloadPercent},
            {"heatState", callResult.heatState},
            {"heatPercent", callResult.heatPercent},
            {"lockPercent", callResult.lockPercent},
            {"counterMeasureTarget", callResult.counterMeasureTarget}
        };
    }
 
    json GetWorkForceInfo(PARAMS(UniverseID containerid,const char* raceid))
    {
        const auto callResult = invoke(GetWorkForceInfo, containerid, raceid);
        return json
        {
            {"current", callResult.current},
            {"capacity", callResult.capacity},
            {"optimal", callResult.optimal},
            {"available", callResult.available},
            {"maxavailable", callResult.maxavailable},
            {"timeuntilnextupdate", callResult.timeuntilnextupdate}
        };
    }
 
    json AddAttackerToBoardingOperation(PARAMS(UniverseID defensibletargetid,UniverseID defensibleboarderid,const char* boarderfactionid,const char* actionid,uint32_t nummarinetiers))
    {
        uint32_t marinetieramounts;
        int32_t marinetierskilllevels;
        const auto callResult = invoke(AddAttackerToBoardingOperation, defensibletargetid, defensibleboarderid, boarderfactionid, actionid, &marinetieramounts, &marinetierskilllevels, nummarinetiers);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
                {"marinetieramounts", marinetieramounts},
                {"marinetierskilllevels", marinetierskilllevels}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json AdjustOrder(PARAMS(UniverseID controllableid,size_t idx,size_t newidx,bool enabled,bool forcestates,bool checkonly))
    {
        const auto callResult = invoke(AdjustOrder, controllableid, idx, newidx, enabled, forcestates, checkonly);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json AreGfxSettingsTooHigh(PARAMS())
    {
        const auto callResult = invoke(AreGfxSettingsTooHigh);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json AreMandatoryAssertsEnabled(PARAMS())
    {
        const auto callResult = invoke(AreMandatoryAssertsEnabled);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json AreOptionalAssertEnabled(PARAMS())
    {
        const auto callResult = invoke(AreOptionalAssertEnabled);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json CanAcceptSubordinate(PARAMS(UniverseID commanderid,UniverseID potentialsubordinateid))
    {
        const auto callResult = invoke(CanAcceptSubordinate, commanderid, potentialsubordinateid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json CanApplyKnownLoadout(PARAMS(const char* macroname,const char* loadoutid))
    {
        const auto callResult = invoke(CanApplyKnownLoadout, macroname, loadoutid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json CanBuildLoadout(PARAMS(UniverseID containerid,UniverseID defensibleid,const char* macroname,const char* loadoutid))
    {
        const auto callResult = invoke(CanBuildLoadout, containerid, defensibleid, macroname, loadoutid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json CanCancelConstruction(PARAMS(UniverseID containerid,BuildTaskID id))
    {
        const auto callResult = invoke(CanCancelConstruction, containerid, id);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json CanContainerEquipShip(PARAMS(UniverseID containerid,UniverseID shipid))
    {
        const auto callResult = invoke(CanContainerEquipShip, containerid, shipid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json CanContainerMineTransport(PARAMS(UniverseID containerid,const char* transportname))
    {
        const auto callResult = invoke(CanContainerMineTransport, containerid, transportname);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json CanContainerSupplyShip(PARAMS(UniverseID containerid,UniverseID shipid))
    {
        const auto callResult = invoke(CanContainerSupplyShip, containerid, shipid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json CanContainerTransport(PARAMS(UniverseID containerid,const char* transportname))
    {
        const auto callResult = invoke(CanContainerTransport, containerid, transportname);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json CanControllableHaveControlEntity(PARAMS(UniverseID controllableid,const char* postid))
    {
        const auto callResult = invoke(CanControllableHaveControlEntity, controllableid, postid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json CanGenerateValidKnownLoadout(PARAMS(const char* macroname))
    {
        const auto callResult = invoke(CanGenerateValidKnownLoadout, macroname);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json CanGenerateValidLoadout(PARAMS(UniverseID containerid,const char* macroname))
    {
        const auto callResult = invoke(CanGenerateValidLoadout, containerid, macroname);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json CanHaveCountermeasures(PARAMS())
    {
        const auto callResult = invoke(CanHaveCountermeasures);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json CanOpenWebBrowser(PARAMS())
    {
        const auto callResult = invoke(CanOpenWebBrowser);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json CanPlayerCommTarget(PARAMS(UniverseID componentid))
    {
        const auto callResult = invoke(CanPlayerCommTarget, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json CanPlayerStandUp(PARAMS())
    {
        const auto callResult = invoke(CanPlayerStandUp);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json CanRedoConstructionMapChange(PARAMS(UniverseID holomapid))
    {
        const auto callResult = invoke(CanRedoConstructionMapChange, holomapid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json CanStartTravelMode(PARAMS(UniverseID objectid))
    {
        const auto callResult = invoke(CanStartTravelMode, objectid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json CanUndoConstructionMapChange(PARAMS(UniverseID holomapid))
    {
        const auto callResult = invoke(CanUndoConstructionMapChange, holomapid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json CancelConstruction(PARAMS(UniverseID containerid,BuildTaskID id))
    {
        const auto callResult = invoke(CancelConstruction, containerid, id);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json CheckWeaponModCompatibility(PARAMS(UniverseID weaponid,const char* wareid))
    {
        const auto callResult = invoke(CheckWeaponModCompatibility, weaponid, wareid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json CompareMapConstructionSequenceWithPlanned(PARAMS(UniverseID holomapid,UniverseID defensibleid,bool usestoredplan))
    {
        const auto callResult = invoke(CompareMapConstructionSequenceWithPlanned, holomapid, defensibleid, usestoredplan);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json CopyToClipboard(PARAMS(const char*const text))
    {
        const auto callResult = invoke(CopyToClipboard, text);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json CreateBoardingOperation(PARAMS(UniverseID defensibletargetid,const char* boarderfactionid,uint32_t approachthreshold,uint32_t insertionthreshold))
    {
        const auto callResult = invoke(CreateBoardingOperation, defensibletargetid, boarderfactionid, approachthreshold, insertionthreshold);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json DeleteSavegame(PARAMS(const char* filename))
    {
        const auto callResult = invoke(DeleteSavegame, filename);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json DoesMapConstructionSequenceRequireBuilder(PARAMS(UniverseID holomapid,UniverseID defensibleid,bool usestoredplan))
    {
        const auto callResult = invoke(DoesMapConstructionSequenceRequireBuilder, holomapid, defensibleid, usestoredplan);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json DropCargo(PARAMS(UniverseID containerid,const char* wareid,uint32_t amount))
    {
        const auto callResult = invoke(DropCargo, containerid, wareid, amount);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json DropInventory(PARAMS(UniverseID entityid,const char* lockboxid,uint32_t numwares))
    {
        UIWareAmount wares;
        const auto callResult = invoke(DropInventory, entityid, lockboxid, &wares, numwares);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
                {"wares", {
                    {"wareid", wares.wareid},
                    {"amount", wares.amount}
                }}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json EnableOrder(PARAMS(UniverseID controllableid,size_t idx))
    {
        const auto callResult = invoke(EnableOrder, controllableid, idx);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json EnablePlannedDefaultOrder(PARAMS(UniverseID controllableid,bool checkonly))
    {
        const auto callResult = invoke(EnablePlannedDefaultOrder, controllableid, checkonly);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAskToSignalForControllable(PARAMS(const char* signalid,UniverseID controllableid))
    {
        const auto callResult = invoke(GetAskToSignalForControllable, signalid, controllableid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAskToSignalForFaction(PARAMS(const char* signalid,const char* factionid))
    {
        const auto callResult = invoke(GetAskToSignalForFaction, signalid, factionid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetBoardingMarineTierAmountsFromAttacker(PARAMS(uint32_t inputnummarinetiers,UniverseID defensibletargetid,UniverseID defensibleboarderid,const char* boarderfactionid))
    {
        uint32_t resultmarinetieramounts;
        int32_t inputmarinetierskilllevels;
        const auto callResult = invoke(GetBoardingMarineTierAmountsFromAttacker, &resultmarinetieramounts, &inputmarinetierskilllevels, inputnummarinetiers, defensibletargetid, defensibleboarderid, boarderfactionid);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
                {"resultmarinetieramounts", resultmarinetieramounts},
                {"inputmarinetierskilllevels", inputmarinetierskilllevels}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetBoxTextBoxColor(PARAMS(const int boxtextid))
    {
        Color color;
        const auto callResult = invoke(GetBoxTextBoxColor, boxtextid, &color);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetBoxTextInfo(PARAMS(const int boxtextid))
    {
        TextInfo textinfo;
        const auto callResult = invoke(GetBoxTextInfo, boxtextid, &textinfo);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetBuildMapStationLocation(PARAMS(UniverseID holomapid))
    {
        UIPosRot location;
        const auto callResult = invoke(GetBuildMapStationLocation, holomapid, &location);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetButtonHighlightColor(PARAMS(const int buttonid))
    {
        Color color;
        const auto callResult = invoke(GetButtonHighlightColor, buttonid, &color);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetButtonText2Details(PARAMS(const int buttonid))
    {
        TextInfo textinfo;
        const auto callResult = invoke(GetButtonText2Details, buttonid, &textinfo);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetCheckBoxColor(PARAMS(const int checkboxid))
    {
        Color color;
        const auto callResult = invoke(GetCheckBoxColor, checkboxid, &color);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetChromaticAberrationOption(PARAMS())
    {
        const auto callResult = invoke(GetChromaticAberrationOption);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetContainerWareIsBuyable(PARAMS(UniverseID containerid,const char* wareid))
    {
        const auto callResult = invoke(GetContainerWareIsBuyable, containerid, wareid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetContainerWareIsSellable(PARAMS(UniverseID containerid,const char* wareid))
    {
        const auto callResult = invoke(GetContainerWareIsSellable, containerid, wareid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetCustomGameStartBoolProperty(PARAMS(const char* id,const char* propertyid))
    {
        CustomGameStartBoolPropertyState state;
        const auto callResult = invoke(GetCustomGameStartBoolProperty, id, propertyid, &state);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
                {"state", {
                    {"state", state.state},
                    {"defaultvalue", state.defaultvalue}
                }}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetDefaultOrder(PARAMS(UniverseID controllableid))
    {
        Order result;
        const auto callResult = invoke(GetDefaultOrder, &result, controllableid);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetDropDownColor(PARAMS(const int dropdownid))
    {
        Color color;
        const auto callResult = invoke(GetDropDownColor, dropdownid, &color);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetDropDownHighlightColor(PARAMS(const int dropdownid))
    {
        Color color;
        const auto callResult = invoke(GetDropDownHighlightColor, dropdownid, &color);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetDropDownHotkeyDetails(PARAMS(const int dropdownid))
    {
        HotkeyInfo hotkeyinfo;
        const auto callResult = invoke(GetDropDownHotkeyDetails, dropdownid, &hotkeyinfo);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetDropDownIconDetails(PARAMS(const int dropdownid))
    {
        DropDownIconInfo iconinfo;
        const auto callResult = invoke(GetDropDownIconDetails, dropdownid, &iconinfo);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetDropDownOptionColor(PARAMS(const int dropdownid))
    {
        Color color;
        const auto callResult = invoke(GetDropDownOptionColor, dropdownid, &color);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetDropDownText2Details(PARAMS(const int dropdownid))
    {
        DropDownTextInfo textinfo;
        const auto callResult = invoke(GetDropDownText2Details, dropdownid, &textinfo);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetDropDownTextDetails(PARAMS(const int dropdownid))
    {
        DropDownTextInfo textinfo;
        const auto callResult = invoke(GetDropDownTextDetails, dropdownid, &textinfo);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetFontStringTitleColor(PARAMS(const int fontstringid))
    {
        Color color;
        const auto callResult = invoke(GetFontStringTitleColor, fontstringid, &color);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetForceShootingAtCursorOption(PARAMS())
    {
        const auto callResult = invoke(GetForceShootingAtCursorOption);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetGraphBackgroundColor(PARAMS(const int graphid))
    {
        Color color;
        const auto callResult = invoke(GetGraphBackgroundColor, graphid, &color);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetGraphTitle(PARAMS(const int graphid))
    {
        GraphTextInfo title;
        const auto callResult = invoke(GetGraphTitle, graphid, &title);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
                {"title", {
                    {"text", title.text},
                    {"font", {"name", title.font.name},{"size", title.font.size}},
                    {"color", {"red", title.color.red},{"green", title.color.green},{"blue", title.color.blue},{"alpha", title.color.alpha}}
                }}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetGraphXAxis(PARAMS(const int graphid))
    {
        GraphAxisInfo axis;
        const auto callResult = invoke(GetGraphXAxis, graphid, &axis);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetGraphYAxis(PARAMS(const int graphid))
    {
        GraphAxisInfo axis;
        const auto callResult = invoke(GetGraphYAxis, graphid, &axis);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetHUDSeparateRadar(PARAMS())
    {
        const auto callResult = invoke(GetHUDSeparateRadar);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetIconText2Details(PARAMS(const int iconid))
    {
        TextInfo textinfo;
        const auto callResult = invoke(GetIconText2Details, iconid, &textinfo);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetIconTextDetails(PARAMS(const int iconid))
    {
        TextInfo textinfo;
        const auto callResult = invoke(GetIconTextDetails, iconid, &textinfo);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetInstalledEngineMod(PARAMS(UniverseID objectid))
    {
        UIEngineMod enginemod;
        const auto callResult = invoke(GetInstalledEngineMod, objectid, &enginemod);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetInstalledGroupedWeaponMod(PARAMS(UniverseID defensibleid,UniverseID contextid,const char* group))
    {
        UIWeaponMod weaponmod;
        const auto callResult = invoke(GetInstalledGroupedWeaponMod, defensibleid, contextid, group, &weaponmod);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetInstalledPaintMod(PARAMS(UniverseID objectid))
    {
        UIPaintMod paintmod;
        const auto callResult = invoke(GetInstalledPaintMod, objectid, &paintmod);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetInstalledShieldMod(PARAMS(UniverseID defensibleid,UniverseID contextid,const char* group))
    {
        UIShieldMod shieldmod;
        const auto callResult = invoke(GetInstalledShieldMod, defensibleid, contextid, group, &shieldmod);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetInstalledShipMod(PARAMS(UniverseID shipid))
    {
        UIShipMod shipmod;
        const auto callResult = invoke(GetInstalledShipMod, shipid, &shipmod);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetInstalledWeaponMod(PARAMS(UniverseID weaponid))
    {
        UIWeaponMod weaponmod;
        const auto callResult = invoke(GetInstalledWeaponMod, weaponid, &weaponmod);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetLicenceInfo(PARAMS(const char* factionid,const char* licenceid))
    {
        LicenceInfo result;
        const auto callResult = invoke(GetLicenceInfo, &result, factionid, licenceid);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
                {"result", {
                    {"name", result.name},
                    {"icon", result.icon}
                }}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetMouseOverTextOption(PARAMS())
    {
        const auto callResult = invoke(GetMouseOverTextOption);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetMouseSteeringInvertedOption(PARAMS(const char* paramname))
    {
        const auto callResult = invoke(GetMouseSteeringInvertedOption, paramname);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetOrderDefinition(PARAMS(const char* orderdef))
    {
        OrderDefinition result;
        const auto callResult = invoke(GetOrderDefinition, &result, orderdef);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetPickedBuildMapEntry(PARAMS(UniverseID holomapid,UniverseID defensibleid))
    {
        UIConstructionPlanEntry result;
        const auto callResult = invoke(GetPickedBuildMapEntry, holomapid, defensibleid, &result);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetPickedMapMacroSlot(PARAMS(UniverseID holomapid,UniverseID defensibleid,UniverseID moduleid,const char* macroname,bool ismodule))
    {
        UILoadoutSlot result;
        const auto callResult = invoke(GetPickedMapMacroSlot, holomapid, defensibleid, moduleid, macroname, ismodule, &result);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
                {"result", {
                    {"upgradetype", result.upgradetype},
                    {"slot", result.slot}
                }}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPlannedDefaultOrder(PARAMS(UniverseID controllableid))
    {
        Order result;
        const auto callResult = invoke(GetPlannedDefaultOrder, &result, controllableid);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetPlayerPaintThemeMod(PARAMS(UniverseID objectid,const char* macroname))
    {
        UIPaintMod paintmod;
        const auto callResult = invoke(GetPlayerPaintThemeMod, objectid, macroname, &paintmod);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetSavesCompressedOption(PARAMS())
    {
        const auto callResult = invoke(GetSavesCompressedOption);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetScreenDisplayOption(PARAMS())
    {
        const auto callResult = invoke(GetScreenDisplayOption);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetShieldGroup(PARAMS(UniverseID defensibleid,UniverseID destructibleid))
    {
        ShieldGroup result;
        const auto callResult = invoke(GetShieldGroup, &result, defensibleid, destructibleid);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
                {"result", {
                    {"context", result.context},
                    {"group", result.group},
                    {"component", result.component}
                }}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetSliderCellBackgroundColor(PARAMS(const int slidercellid))
    {
        Color color;
        const auto callResult = invoke(GetSliderCellBackgroundColor, slidercellid, &color);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetSliderCellFont(PARAMS(const int slidercellid))
    {
        Font font;
        const auto callResult = invoke(GetSliderCellFont, slidercellid, &font);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
                {"font", {
                    {"name", font.name},
                    {"size", font.size}
                }}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetSliderCellInactiveBackgroundColor(PARAMS(const int slidercellid))
    {
        Color color;
        const auto callResult = invoke(GetSliderCellInactiveBackgroundColor, slidercellid, &color);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetSliderCellNegativeValueColor(PARAMS(const int slidercellid))
    {
        Color color;
        const auto callResult = invoke(GetSliderCellNegativeValueColor, slidercellid, &color);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetSliderCellTextColor(PARAMS(const int slidercellid))
    {
        Color color;
        const auto callResult = invoke(GetSliderCellTextColor, slidercellid, &color);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetSliderCellValueColor(PARAMS(const int slidercellid))
    {
        Color color;
        const auto callResult = invoke(GetSliderCellValueColor, slidercellid, &color);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetSliderCellValues(PARAMS(const int slidercellid))
    {
        SliderCellDetails values;
        const auto callResult = invoke(GetSliderCellValues, slidercellid, &values);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetSpeakTargetNameOption(PARAMS())
    {
        const auto callResult = invoke(GetSpeakTargetNameOption);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetStatusBarMarkerColor(PARAMS(const int statusbarid))
    {
        Color color;
        const auto callResult = invoke(GetStatusBarMarkerColor, statusbarid, &color);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetStatusBarNegChangeColor(PARAMS(const int statusbarid))
    {
        Color color;
        const auto callResult = invoke(GetStatusBarNegChangeColor, statusbarid, &color);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetStatusBarPosChangeColor(PARAMS(const int statusbarid))
    {
        Color color;
        const auto callResult = invoke(GetStatusBarPosChangeColor, statusbarid, &color);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetStatusBarValueColor(PARAMS(const int statusbarid))
    {
        Color color;
        const auto callResult = invoke(GetStatusBarValueColor, statusbarid, &color);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetSyncPointInfo(PARAMS(UniverseID controllableid,size_t orderidx))
    {
        SyncPointInfo result;
        const auto callResult = invoke(GetSyncPointInfo, controllableid, orderidx, &result);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
                {"result", {
                    {"id", result.id},
                    {"reached", result.reached}
                }}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetTableBackgroundColor(PARAMS(const int tableid))
    {
        Color color;
        const auto callResult = invoke(GetTableBackgroundColor, tableid, &color);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetUISystemInfo(PARAMS(UniverseID clusterid))
    {
        UISystemInfo result;
        const auto callResult = invoke(GetUISystemInfo, &result, clusterid);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetUp(PARAMS())
    {
        const auto callResult = invoke(GetUp);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetVentureOption(PARAMS())
    {
        const auto callResult = invoke(GetVentureOption);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetVisitorNamesShownOption(PARAMS())
    {
        const auto callResult = invoke(GetVisitorNamesShownOption);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json HasContainerBuyLimitOverride(PARAMS(UniverseID containerid,const char* wareid))
    {
        const auto callResult = invoke(HasContainerBuyLimitOverride, containerid, wareid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json HasContainerSellLimitOverride(PARAMS(UniverseID containerid,const char* wareid))
    {
        const auto callResult = invoke(HasContainerSellLimitOverride, containerid, wareid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json HasControllableOwnBlacklist(PARAMS(UniverseID controllableid,const char* listtype))
    {
        const auto callResult = invoke(HasControllableOwnBlacklist, controllableid, listtype);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json HasControllableOwnResponse(PARAMS(UniverseID controllableid,const char* signalid))
    {
        const auto callResult = invoke(HasControllableOwnResponse, controllableid, signalid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json HasDefaultLoadout(PARAMS(const char* macroname))
    {
        const auto callResult = invoke(HasDefaultLoadout, macroname);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json HasEntityMoneyLogEntries(PARAMS(UniverseID entityid))
    {
        const auto callResult = invoke(HasEntityMoneyLogEntries, entityid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json HasExtension(PARAMS(const char* extensionid,bool personal))
    {
        const auto callResult = invoke(HasExtension, extensionid, personal);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json HasFrameBrackets(PARAMS(const int frameid))
    {
        const auto callResult = invoke(HasFrameBrackets, frameid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json HasLimitedOxygenSupply(PARAMS())
    {
        const auto callResult = invoke(HasLimitedOxygenSupply);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json HasResearched(PARAMS(const char* wareid))
    {
        const auto callResult = invoke(HasResearched, wareid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json HasSavegame(PARAMS())
    {
        const auto callResult = invoke(HasSavegame);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json HasSeta(PARAMS())
    {
        const auto callResult = invoke(HasSeta);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json HasShipFlightAssist(PARAMS(UniverseID shipid))
    {
        const auto callResult = invoke(HasShipFlightAssist, shipid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json HasStartAnimation(PARAMS())
    {
        const auto callResult = invoke(HasStartAnimation);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json HasVenturerDock(PARAMS(UniverseID containerid,UniverseID shipid,UniverseID ventureplatformid))
    {
        const auto callResult = invoke(HasVenturerDock, containerid, shipid, ventureplatformid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json InstallEngineMod(PARAMS(UniverseID objectid,const char* wareid))
    {
        const auto callResult = invoke(InstallEngineMod, objectid, wareid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json InstallGroupedWeaponMod(PARAMS(UniverseID defensibleid,UniverseID contextid,const char* group,const char* wareid))
    {
        const auto callResult = invoke(InstallGroupedWeaponMod, defensibleid, contextid, group, wareid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json InstallPaintMod(PARAMS(UniverseID objectid,const char* wareid,bool useinventory))
    {
        const auto callResult = invoke(InstallPaintMod, objectid, wareid, useinventory);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json InstallShieldMod(PARAMS(UniverseID defensibleid,UniverseID contextid,const char* group,const char* wareid))
    {
        const auto callResult = invoke(InstallShieldMod, defensibleid, contextid, group, wareid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json InstallShipMod(PARAMS(UniverseID shipid,const char* wareid))
    {
        const auto callResult = invoke(InstallShipMod, shipid, wareid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json InstallWeaponMod(PARAMS(UniverseID weaponid,const char* wareid))
    {
        const auto callResult = invoke(InstallWeaponMod, weaponid, wareid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsAAOptionSupported(PARAMS(const char* mode))
    {
        const auto callResult = invoke(IsAAOptionSupported, mode);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsAdvancedSatellite(PARAMS(const UniverseID componentid))
    {
        const auto callResult = invoke(IsAdvancedSatellite, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsAmmoMacroCompatible(PARAMS(const char* weaponmacroname,const char* ammomacroname))
    {
        const auto callResult = invoke(IsAmmoMacroCompatible, weaponmacroname, ammomacroname);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsAppStoreVersion(PARAMS())
    {
        const auto callResult = invoke(IsAppStoreVersion);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsAsteroid(PARAMS(const UniverseID componentid))
    {
        const auto callResult = invoke(IsAsteroid, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsAutotargetingActive(PARAMS())
    {
        const auto callResult = invoke(IsAutotargetingActive);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsBomb(PARAMS(const UniverseID componentid))
    {
        const auto callResult = invoke(IsBomb, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsBoxTextWordWrap(PARAMS(const int boxtextid))
    {
        const auto callResult = invoke(IsBoxTextWordWrap, boxtextid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsBuilderBusy(PARAMS(UniverseID shipid))
    {
        const auto callResult = invoke(IsBuilderBusy, shipid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsCheckBoxActive(PARAMS(const int checkboxid))
    {
        const auto callResult = invoke(IsCheckBoxActive, checkboxid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsCheckBoxChecked(PARAMS(const int checkboxid))
    {
        const auto callResult = invoke(IsCheckBoxChecked, checkboxid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsCollectable(PARAMS(const UniverseID componentid))
    {
        const auto callResult = invoke(IsCollectable, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsCommander(PARAMS(const UniverseID componentid))
    {
        const auto callResult = invoke(IsCommander, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsComponentClass(PARAMS(UniverseID componentid,const char* classname))
    {
        const auto callResult = invoke(IsComponentClass, componentid, classname);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsComponentOperational(PARAMS(UniverseID componentid))
    {
        const auto callResult = invoke(IsComponentOperational, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsComponentWrecked(PARAMS(UniverseID componentid))
    {
        const auto callResult = invoke(IsComponentWrecked, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsConstructionPlanValid(PARAMS(const char* constructionplanid))
    {
        uint32_t numinvalidpatches;
        const auto callResult = invoke(IsConstructionPlanValid, constructionplanid, &numinvalidpatches);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
                {"numinvalidpatches", numinvalidpatches}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsContainerAmmoMacroCompatible(PARAMS(UniverseID containerid,const char* ammomacroname))
    {
        const auto callResult = invoke(IsContainerAmmoMacroCompatible, containerid, ammomacroname);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsContainerFactionBuildRescricted(PARAMS(UniverseID containerid))
    {
        const auto callResult = invoke(IsContainerFactionBuildRescricted, containerid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsContainerFactionTradeRescricted(PARAMS(UniverseID containerid,const char* wareid))
    {
        const auto callResult = invoke(IsContainerFactionTradeRescricted, containerid, wareid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsContestedSector(PARAMS(UniverseID sectorid))
    {
        const auto callResult = invoke(IsContestedSector, sectorid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsControlPressed(PARAMS())
    {
        const auto callResult = invoke(IsControlPressed);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsConversationActive(PARAMS())
    {
        const auto callResult = invoke(IsConversationActive);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsCrate(PARAMS(const UniverseID componentid))
    {
        const auto callResult = invoke(IsCrate, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsCrystal(PARAMS(const UniverseID componentid))
    {
        const auto callResult = invoke(IsCrystal, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsCurrentGPUDiscrete(PARAMS())
    {
        const auto callResult = invoke(IsCurrentGPUDiscrete);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsCurrentOrderCritical(PARAMS(UniverseID controllableid))
    {
        const auto callResult = invoke(IsCurrentOrderCritical, controllableid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsCurrentlyScanning(PARAMS())
    {
        const auto callResult = invoke(IsCurrentlyScanning);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsCustomGameStartPropertyChanged(PARAMS(const char* id,const char* propertyid))
    {
        const auto callResult = invoke(IsCustomGameStartPropertyChanged, id, propertyid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsDefensibleBeingBoardedBy(PARAMS(UniverseID defensibleid,const char* factionid))
    {
        const auto callResult = invoke(IsDefensibleBeingBoardedBy, defensibleid, factionid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsDemoVersion(PARAMS())
    {
        const auto callResult = invoke(IsDemoVersion);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsDeployableMacroCompatible(PARAMS(UniverseID containerid,const char* macroname,const char* deployablemacroname))
    {
        const auto callResult = invoke(IsDeployableMacroCompatible, containerid, macroname, deployablemacroname);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsDestructible2(PARAMS(const UniverseID componentid,const char*const connectionname))
    {
        const auto callResult = invoke(IsDestructible2, componentid, connectionname);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsDetailUIElement(PARAMS(const UniverseID componentid,const char*const connectionname))
    {
        const auto callResult = invoke(IsDetailUIElement, componentid, connectionname);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsDroneTypeArmed(PARAMS(UniverseID defensibleid,const char* dronetype))
    {
        const auto callResult = invoke(IsDroneTypeArmed, defensibleid, dronetype);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsDroneTypeBlocked(PARAMS(UniverseID defensibleid,const char* dronetype))
    {
        const auto callResult = invoke(IsDroneTypeBlocked, defensibleid, dronetype);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsDropDownActive(PARAMS(const int dropdownid))
    {
        const auto callResult = invoke(IsDropDownActive, dropdownid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsDropDownMouseOverInteractionAllowed(PARAMS(const int dropdownid))
    {
        const auto callResult = invoke(IsDropDownMouseOverInteractionAllowed, dropdownid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsEditBoxActive(PARAMS(const int editboxid))
    {
        const auto callResult = invoke(IsEditBoxActive, editboxid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsEditBoxInputEncrypted(PARAMS(const int editboxid))
    {
        const auto callResult = invoke(IsEditBoxInputEncrypted, editboxid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsEditBoxTextHidden(PARAMS(const int editboxid))
    {
        const auto callResult = invoke(IsEditBoxTextHidden, editboxid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsEditBoxTextSelectedOnActivation(PARAMS(const int editboxid))
    {
        const auto callResult = invoke(IsEditBoxTextSelectedOnActivation, editboxid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsEntity(PARAMS(const UniverseID componentid))
    {
        const auto callResult = invoke(IsEntity, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsErrorLogActive(PARAMS())
    {
        const auto callResult = invoke(IsErrorLogActive);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsExternalTargetMode(PARAMS())
    {
        const auto callResult = invoke(IsExternalTargetMode);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsExternalViewActive(PARAMS())
    {
        const auto callResult = invoke(IsExternalViewActive);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsFPSEnabled(PARAMS())
    {
        const auto callResult = invoke(IsFPSEnabled);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsFactionAllyToFaction(PARAMS(const char* factionid,const char* otherfactionid))
    {
        const auto callResult = invoke(IsFactionAllyToFaction, factionid, otherfactionid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsFactionEnemyToFaction(PARAMS(const char* factionid,const char* otherfactionid))
    {
        const auto callResult = invoke(IsFactionEnemyToFaction, factionid, otherfactionid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsFactionHQ(PARAMS(UniverseID stationid))
    {
        const auto callResult = invoke(IsFactionHQ, stationid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsFullscreenMenuDisplayed(PARAMS(bool anymenu,const char* menuname))
    {
        const auto callResult = invoke(IsFullscreenMenuDisplayed, anymenu, menuname);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsGOGVersion(PARAMS())
    {
        const auto callResult = invoke(IsGOGVersion);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsGameModified(PARAMS())
    {
        const auto callResult = invoke(IsGameModified);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsGamePaused(PARAMS())
    {
        const auto callResult = invoke(IsGamePaused);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsHQ(PARAMS(UniverseID stationid))
    {
        const auto callResult = invoke(IsHQ, stationid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsHUDActive(PARAMS())
    {
        const auto callResult = invoke(IsHUDActive);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsHUDRadarActive(PARAMS())
    {
        const auto callResult = invoke(IsHUDRadarActive);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsIconValid(PARAMS(const char* iconid))
    {
        const auto callResult = invoke(IsIconValid, iconid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsInfoUnlockedForPlayer(PARAMS(UniverseID componentid,const char* infostring))
    {
        const auto callResult = invoke(IsInfoUnlockedForPlayer, componentid, infostring);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsJoystickSteeringAdapative(PARAMS())
    {
        const auto callResult = invoke(IsJoystickSteeringAdapative);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsKnownItemRead(PARAMS(const char* libraryid,const char* itemid))
    {
        const auto callResult = invoke(IsKnownItemRead, libraryid, itemid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsKnownRead(PARAMS(UniverseID componentid))
    {
        const auto callResult = invoke(IsKnownRead, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsKnownToPlayer(PARAMS(UniverseID componentid))
    {
        const auto callResult = invoke(IsKnownToPlayer, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsLanguageSettingEnabled(PARAMS())
    {
        const auto callResult = invoke(IsLanguageSettingEnabled);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsLanguageValid(PARAMS())
    {
        const auto callResult = invoke(IsLanguageValid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsLaserTower(PARAMS(const UniverseID componentid))
    {
        const auto callResult = invoke(IsLaserTower, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsLeftMouseButtonDown(PARAMS())
    {
        const auto callResult = invoke(IsLeftMouseButtonDown);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsLoadoutValid(PARAMS(UniverseID defensibleid,const char* macroname,const char* loadoutid))
    {
        uint32_t numinvalidpatches;
        const auto callResult = invoke(IsLoadoutValid, defensibleid, macroname, loadoutid, &numinvalidpatches);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
                {"numinvalidpatches", numinvalidpatches}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsLockbox(PARAMS(const UniverseID componentid))
    {
        const auto callResult = invoke(IsLockbox, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsLowOnOxygen(PARAMS())
    {
        const auto callResult = invoke(IsLowOnOxygen);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsMasterVersion(PARAMS())
    {
        const auto callResult = invoke(IsMasterVersion);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsMiniWidgetSystemUsed(PARAMS())
    {
        const auto callResult = invoke(IsMiniWidgetSystemUsed);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsMissileIncoming(PARAMS())
    {
        const auto callResult = invoke(IsMissileIncoming);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsMissileLockingOn(PARAMS())
    {
        const auto callResult = invoke(IsMissileLockingOn);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsMouseDoubleClickMode(PARAMS())
    {
        const auto callResult = invoke(IsMouseDoubleClickMode);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsMouseEmulationActive(PARAMS())
    {
        const auto callResult = invoke(IsMouseEmulationActive);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsMouseSteeringAdapative(PARAMS())
    {
        const auto callResult = invoke(IsMouseSteeringAdapative);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsNavBeacon(PARAMS(const UniverseID componentid))
    {
        const auto callResult = invoke(IsNavBeacon, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsNetworkEngineEnabled(PARAMS())
    {
        const auto callResult = invoke(IsNetworkEngineEnabled);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsNextStartAnimationSkipped(PARAMS(bool reset))
    {
        const auto callResult = invoke(IsNextStartAnimationSkipped, reset);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsObjectKnown(PARAMS(const UniverseID componentid))
    {
        const auto callResult = invoke(IsObjectKnown, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsOnlineEnabled(PARAMS())
    {
        const auto callResult = invoke(IsOnlineEnabled);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsOrderSelectableFor(PARAMS(const char* orderdefid,UniverseID controllableid))
    {
        const auto callResult = invoke(IsOrderSelectableFor, orderdefid, controllableid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsPerson(PARAMS(NPCSeed person,UniverseID controllableid))
    {
        const auto callResult = invoke(IsPerson, person, controllableid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsPersonTransferScheduled(PARAMS(UniverseID controllableid,NPCSeed person))
    {
        const auto callResult = invoke(IsPersonTransferScheduled, controllableid, person);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsPlayerBlacklistDefault(PARAMS(BlacklistID id,const char* listtype,const char* defaultgroup))
    {
        const auto callResult = invoke(IsPlayerBlacklistDefault, id, listtype, defaultgroup);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsPlayerCameraTargetViewPossible(PARAMS(UniverseID targetid,bool force))
    {
        const auto callResult = invoke(IsPlayerCameraTargetViewPossible, targetid, force);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsPlayerValid(PARAMS())
    {
        const auto callResult = invoke(IsPlayerValid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsPointingWithinAimingRange(PARAMS())
    {
        const auto callResult = invoke(IsPointingWithinAimingRange);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsPresentModeOptionSupported(PARAMS(const char* mode))
    {
        const auto callResult = invoke(IsPresentModeOptionSupported, mode);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsRealComponentClass(PARAMS(UniverseID componentid,const char* classname))
    {
        const auto callResult = invoke(IsRealComponentClass, componentid, classname);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsResourceProbe(PARAMS(const UniverseID componentid))
    {
        const auto callResult = invoke(IsResourceProbe, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsSatellite(PARAMS(const UniverseID componentid))
    {
        const auto callResult = invoke(IsSatellite, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsSaveListLoadingComplete(PARAMS())
    {
        const auto callResult = invoke(IsSaveListLoadingComplete);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsSaveValid(PARAMS(const char* filename))
    {
        const auto callResult = invoke(IsSaveValid, filename);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsSetaActive(PARAMS())
    {
        const auto callResult = invoke(IsSetaActive);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsShiftPressed(PARAMS())
    {
        const auto callResult = invoke(IsShiftPressed);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsShip(PARAMS(const UniverseID componentid))
    {
        const auto callResult = invoke(IsShip, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsShipAtExternalDock(PARAMS(UniverseID shipid))
    {
        const auto callResult = invoke(IsShipAtExternalDock, shipid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsShipBeingRetrieved(PARAMS(UniverseID shipid))
    {
        const auto callResult = invoke(IsShipBeingRetrieved, shipid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsSofttargetManagerActive(PARAMS())
    {
        const auto callResult = invoke(IsSofttargetManagerActive);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsSoftwareDefault(PARAMS(UniverseID controllableid,const char* macroname,const char* softwarename))
    {
        const auto callResult = invoke(IsSoftwareDefault, controllableid, macroname, softwarename);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsStartmenu(PARAMS())
    {
        const auto callResult = invoke(IsStartmenu);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsStation(PARAMS(const UniverseID componentid))
    {
        const auto callResult = invoke(IsStation, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsStationary(PARAMS(const UniverseID componentid))
    {
        const auto callResult = invoke(IsStationary, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsSupplyManual(PARAMS(UniverseID containerid,const char* type))
    {
        const auto callResult = invoke(IsSupplyManual, containerid, type);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsSurfaceElement(PARAMS(const UniverseID componentid))
    {
        const auto callResult = invoke(IsSurfaceElement, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsTableMultiSelect(PARAMS(const int tableid))
    {
        const auto callResult = invoke(IsTableMultiSelect, tableid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsTableRowBorderBelowEnabled(PARAMS(const int tableid,uint32_t row))
    {
        const auto callResult = invoke(IsTableRowBorderBelowEnabled, tableid, row);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsTargetInPlayerWeaponRange(PARAMS(const UniverseID componentid))
    {
        const auto callResult = invoke(IsTargetInPlayerWeaponRange, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsTargetMonitorNotification(PARAMS(const int notificationid))
    {
        const auto callResult = invoke(IsTargetMonitorNotification, notificationid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsTargetable(PARAMS(const uint32_t messageid))
    {
        const auto callResult = invoke(IsTargetable, messageid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsThrottleBidirectional(PARAMS())
    {
        const auto callResult = invoke(IsThrottleBidirectional);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsTitleFontString(PARAMS(const int fontstringid))
    {
        const auto callResult = invoke(IsTitleFontString, fontstringid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsTobiiAvailable(PARAMS())
    {
        const auto callResult = invoke(IsTobiiAvailable);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsTradeShowVersion(PARAMS())
    {
        const auto callResult = invoke(IsTradeShowVersion);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsTurretGroupArmed(PARAMS(UniverseID defensibleid,UniverseID contextid,const char* path,const char* group))
    {
        const auto callResult = invoke(IsTurretGroupArmed, defensibleid, contextid, path, group);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsUnit(PARAMS(UniverseID controllableid))
    {
        const auto callResult = invoke(IsUnit, controllableid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsUnitMacroCompatible(PARAMS(UniverseID containerid,const char* macroname,const char* unitmacroname))
    {
        const auto callResult = invoke(IsUnitMacroCompatible, containerid, macroname, unitmacroname);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsUpgradeGroupMacroCompatible(PARAMS(UniverseID destructibleid,const char* macroname,const char* path,const char* group,const char* upgradetypename,const char* upgrademacroname))
    {
        const auto callResult = invoke(IsUpgradeGroupMacroCompatible, destructibleid, macroname, path, group, upgradetypename, upgrademacroname);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsUpgradeMacroCompatible(PARAMS(UniverseID objectid,UniverseID moduleid,const char* macroname,bool ismodule,const char* upgradetypename,size_t slot,const char* upgrademacroname))
    {
        const auto callResult = invoke(IsUpgradeMacroCompatible, objectid, moduleid, macroname, ismodule, upgradetypename, slot, upgrademacroname);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsVRMode(PARAMS())
    {
        const auto callResult = invoke(IsVRMode);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsVROculusTouchActive(PARAMS())
    {
        const auto callResult = invoke(IsVROculusTouchActive);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsVRPointerActive(PARAMS())
    {
        const auto callResult = invoke(IsVRPointerActive);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsVRVersion(PARAMS())
    {
        const auto callResult = invoke(IsVRVersion);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsVRViveControllerActive(PARAMS())
    {
        const auto callResult = invoke(IsVRViveControllerActive);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsValidComponent(PARAMS(const UniverseID componentid))
    {
        const auto callResult = invoke(IsValidComponent, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsVentureShip(PARAMS(const UniverseID componentid))
    {
        const auto callResult = invoke(IsVentureShip, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsVirtualUpgradeMacroCompatible(PARAMS(UniverseID defensibleid,const char* macroname,const char* upgradetypename,size_t slot,const char* upgrademacroname))
    {
        const auto callResult = invoke(IsVirtualUpgradeMacroCompatible, defensibleid, macroname, upgradetypename, slot, upgrademacroname);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsWeaponArmed(PARAMS(UniverseID weaponid))
    {
        const auto callResult = invoke(IsWeaponArmed, weaponid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsWillingToBuyFromPlayer(PARAMS(UniverseID componentid,const char* warename))
    {
        const auto callResult = invoke(IsWillingToBuyFromPlayer, componentid, warename);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsWillingToSellToPlayer(PARAMS(UniverseID componentid,const char* warename))
    {
        const auto callResult = invoke(IsWillingToSellToPlayer, componentid, warename);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json IsZone(PARAMS(const UniverseID componentid))
    {
        const auto callResult = invoke(IsZone, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json MarkIndicatorShown(PARAMS(const UniverseID componentid))
    {
        const auto callResult = invoke(MarkIndicatorShown, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json QueryGameServers(PARAMS())
    {
        const auto callResult = invoke(QueryGameServers);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json QuickDock(PARAMS())
    {
        const auto callResult = invoke(QuickDock);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json QuickMenuAccess(PARAMS(const char* menu))
    {
        const auto callResult = invoke(QuickMenuAccess, menu);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json RemoveAllOrders(PARAMS(UniverseID controllableid))
    {
        const auto callResult = invoke(RemoveAllOrders, controllableid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json RemoveAttackerFromBoardingOperation(PARAMS(UniverseID defensibleboarderid))
    {
        const auto callResult = invoke(RemoveAttackerFromBoardingOperation, defensibleboarderid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json RemoveBuildPlot(PARAMS(UniverseID stationid))
    {
        const auto callResult = invoke(RemoveBuildPlot, stationid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json RemoveCommander2(PARAMS(UniverseID controllableid))
    {
        const auto callResult = invoke(RemoveCommander2, controllableid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json RemoveConstructionPlan(PARAMS(const char* source,const char* id))
    {
        const auto callResult = invoke(RemoveConstructionPlan, source, id);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json RemoveLoadout(PARAMS(const char* source,const char* macroname,const char* localid))
    {
        const auto callResult = invoke(RemoveLoadout, source, macroname, localid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json RemoveOrder(PARAMS(UniverseID controllableid,size_t idx,bool playercancelled,bool checkonly))
    {
        const auto callResult = invoke(RemoveOrder, controllableid, idx, playercancelled, checkonly);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json RemoveOrder2(PARAMS(UniverseID controllableid,size_t idx,bool playercancelled,bool checkonly,bool onlyimmediate))
    {
        const auto callResult = invoke(RemoveOrder2, controllableid, idx, playercancelled, checkonly, onlyimmediate);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json RequestDockAt(PARAMS(UniverseID containerid,bool checkonly))
    {
        const auto callResult = invoke(RequestDockAt, containerid, checkonly);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json RequestShipFromInternalStorage2(PARAMS(UniverseID shipid,bool highpriority,UniverseID refcomponentid))
    {
        const auto callResult = invoke(RequestShipFromInternalStorage2, shipid, highpriority, refcomponentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json ResetResponseToSignalForControllable(PARAMS(const char* signalid,UniverseID controllableid))
    {
        const auto callResult = invoke(ResetResponseToSignalForControllable, signalid, controllableid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json SetActiveFrame(PARAMS(const int frameid))
    {
        const auto callResult = invoke(SetActiveFrame, frameid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json SetActiveMission(PARAMS(MissionID missionid))
    {
        const auto callResult = invoke(SetActiveMission, missionid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json SetAmmoOfWeapon(PARAMS(UniverseID weaponid,const char* newammomacro))
    {
        const auto callResult = invoke(SetAmmoOfWeapon, weaponid, newammomacro);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json SetCommander(PARAMS(UniverseID controllableid,UniverseID commanderid,const char* assignment))
    {
        const auto callResult = invoke(SetCommander, controllableid, commanderid, assignment);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json SetDefaultResponseToSignalForControllable(PARAMS(const char* newresponse,bool ask,const char* signalid,UniverseID controllableid))
    {
        const auto callResult = invoke(SetDefaultResponseToSignalForControllable, newresponse, ask, signalid, controllableid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json SetDefaultResponseToSignalForFaction(PARAMS(const char* newresponse,bool ask,const char* signalid,const char* factionid))
    {
        const auto callResult = invoke(SetDefaultResponseToSignalForFaction, newresponse, ask, signalid, factionid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json SetEntityToPost(PARAMS(UniverseID controllableid,UniverseID entityid,const char* postid))
    {
        const auto callResult = invoke(SetEntityToPost, controllableid, entityid, postid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json SetFrameInteractiveObject(PARAMS(const int frameid,const int objectid))
    {
        const auto callResult = invoke(SetFrameInteractiveObject, frameid, objectid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json SetOrderSyncPointID(PARAMS(UniverseID controllableid,size_t orderidx,uint32_t syncid,bool checkonly))
    {
        const auto callResult = invoke(SetOrderSyncPointID, controllableid, orderidx, syncid, checkonly);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json SetRadarRenderTarget(PARAMS(const char*const rendertargettexture,const UniverseID referencecomponent,const bool mapmode))
    {
        const auto callResult = invoke(SetRadarRenderTarget, rendertargettexture, referencecomponent, mapmode);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json SetRadarRenderTargetOnTarget(PARAMS(const char*const rendertargettexture,const UniverseID focuscomponentid,const UniverseID referencecomponent,const bool mapmode))
    {
        const auto callResult = invoke(SetRadarRenderTargetOnTarget, rendertargettexture, focuscomponentid, referencecomponent, mapmode);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json SetSofttarget(PARAMS(UniverseID componentid,const char*const connectionname))
    {
        const auto callResult = invoke(SetSofttarget, componentid, connectionname);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json SetStationOverviewGraphWare(PARAMS(UniverseID stationid,const char* wareid,bool value))
    {
        const auto callResult = invoke(SetStationOverviewGraphWare, stationid, wareid, value);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json ShouldEditBoxRestoreInteractiveObject(PARAMS(const int editboxid))
    {
        const auto callResult = invoke(ShouldEditBoxRestoreInteractiveObject, editboxid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json ShouldSubordinateGroupDockAtCommander(PARAMS(UniverseID controllableid,int group))
    {
        const auto callResult = invoke(ShouldSubordinateGroupDockAtCommander, controllableid, group);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json ShowGamepadTextInput(PARAMS(const char* description,uint32_t maxchars,const char* existingtext,bool multilines,bool password))
    {
        const auto callResult = invoke(ShowGamepadTextInput, description, maxchars, existingtext, multilines, password);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json ShuffleMapConstructionPlan(PARAMS(UniverseID holomapid,bool checkonly))
    {
        const auto callResult = invoke(ShuffleMapConstructionPlan, holomapid, checkonly);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json StartBoardingOperation(PARAMS(UniverseID defensibletargetid,const char* boarderfactionid))
    {
        const auto callResult = invoke(StartBoardingOperation, defensibletargetid, boarderfactionid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json StopPanMap(PARAMS(UniverseID holomapid))
    {
        const auto callResult = invoke(StopPanMap, holomapid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json StopRotateMap(PARAMS(UniverseID holomapid))
    {
        const auto callResult = invoke(StopRotateMap, holomapid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json TakeShipFromInternalStorage(PARAMS(UniverseID shipid,bool highpriority,bool checkonly))
    {
        const auto callResult = invoke(TakeShipFromInternalStorage, shipid, highpriority, checkonly);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json TeleportPlayerTo(PARAMS(UniverseID controllableid,bool allowcontrolling,bool instant,bool force))
    {
        const auto callResult = invoke(TeleportPlayerTo, controllableid, allowcontrolling, instant, force);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json ToggleAutoPilot(PARAMS(bool checkonly))
    {
        const auto callResult = invoke(ToggleAutoPilot, checkonly);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json TriggerCompSlotAnimation(PARAMS(UniverseID componentid,const char* connectionname,const char* triggername))
    {
        const auto callResult = invoke(TriggerCompSlotAnimation, componentid, connectionname, triggername);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json UpdateAttackerOfBoardingOperation(PARAMS(UniverseID defensibletargetid,UniverseID defensibleboarderid,const char* boarderfactionid,const char* actionid,uint32_t nummarinetiers))
    {
        uint32_t marinetieramounts;
        int32_t marinetierskilllevels;
        const auto callResult = invoke(UpdateAttackerOfBoardingOperation, defensibletargetid, defensibleboarderid, boarderfactionid, actionid, &marinetieramounts, &marinetierskilllevels, nummarinetiers);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
                {"marinetieramounts", marinetieramounts},
                {"marinetierskilllevels", marinetierskilllevels}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json UpdateBoardingOperation(PARAMS(UniverseID defensibletargetid,const char* boarderfactionid,uint32_t approachthreshold,uint32_t insertionthreshold))
    {
        const auto callResult = invoke(UpdateBoardingOperation, defensibletargetid, boarderfactionid, approachthreshold, insertionthreshold);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json CanTeleportPlayerTo(PARAMS(UniverseID controllableid,bool allowcontrolling,bool force))
    {
        const auto callResult = invoke(CanTeleportPlayerTo, controllableid, allowcontrolling, force);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GenerateFactionRelationText(PARAMS(const char* factionid))
    {
        const auto callResult = invoke(GenerateFactionRelationText, factionid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAAOption(PARAMS(bool useconfig))
    {
        const auto callResult = invoke(GetAAOption, useconfig);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetBoardingActionOfAttacker(PARAMS(UniverseID defensibletargetid,UniverseID defensibleboarderid,const char* boarderfactionid))
    {
        const auto callResult = invoke(GetBoardingActionOfAttacker, defensibletargetid, defensibleboarderid, boarderfactionid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetBuildVersionSuffix(PARAMS())
    {
        const auto callResult = invoke(GetBuildVersionSuffix);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetCheckBoxSymbol(PARAMS(const int checkboxid))
    {
        const auto callResult = invoke(GetCheckBoxSymbol, checkboxid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetCompSlotPlayerActionTriggeredConnection(PARAMS(UniverseID componentid,const char* connectionname))
    {
        const auto callResult = invoke(GetCompSlotPlayerActionTriggeredConnection, componentid, connectionname);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetComponentClass(PARAMS(UniverseID componentid))
    {
        const auto callResult = invoke(GetComponentClass, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetComponentName(PARAMS(UniverseID componentid))
    {
        const auto callResult = invoke(GetComponentName, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetCurrentAmmoOfWeapon(PARAMS(UniverseID weaponid))
    {
        const auto callResult = invoke(GetCurrentAmmoOfWeapon, weaponid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetCurrentBoardingPhase(PARAMS(UniverseID defensibletargetid,const char* boarderfactionid))
    {
        const auto callResult = invoke(GetCurrentBoardingPhase, defensibletargetid, boarderfactionid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetCurrentDroneMode(PARAMS(UniverseID defensibleid,const char* dronetype))
    {
        const auto callResult = invoke(GetCurrentDroneMode, defensibleid, dronetype);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetCurrentGPUNiceName(PARAMS())
    {
        const auto callResult = invoke(GetCurrentGPUNiceName);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetCurrentSoundDevice(PARAMS())
    {
        const auto callResult = invoke(GetCurrentSoundDevice);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetCustomGameStartStringProperty(PARAMS(const char* id,const char* propertyid))
    {
        CustomGameStartStringPropertyState state;
        const auto callResult = invoke(GetCustomGameStartStringProperty, id, propertyid, &state);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
                {"state", {
                    {"state", state.state},
                    {"defaultvalue", state.defaultvalue},
                    {"options", state.options}
                }}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetDefaultResponseToSignalForControllable(PARAMS(const char* signalid,UniverseID controllableid))
    {
        const auto callResult = invoke(GetDefaultResponseToSignalForControllable, signalid, controllableid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetDefaultResponseToSignalForFaction(PARAMS(const char* signalid,const char* factionid))
    {
        const auto callResult = invoke(GetDefaultResponseToSignalForFaction, signalid, factionid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetDetailmonitorCutsceneKey(PARAMS(uint32_t cutsceneid))
    {
        const auto callResult = invoke(GetDetailmonitorCutsceneKey, cutsceneid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetDropDownStartOption(PARAMS(const int dropdownid))
    {
        const auto callResult = invoke(GetDropDownStartOption, dropdownid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetEditBoxDefaultText(PARAMS(const int editboxid))
    {
        const auto callResult = invoke(GetEditBoxDefaultText, editboxid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetEditBoxDescription(PARAMS(const int editboxid))
    {
        const auto callResult = invoke(GetEditBoxDescription, editboxid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetEntityActiveIcon(PARAMS(const UniverseID componentid))
    {
        const auto callResult = invoke(GetEntityActiveIcon, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetEntityInactiveIcon(PARAMS(const UniverseID componentid))
    {
        const auto callResult = invoke(GetEntityInactiveIcon, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetEntitySelectedIcon(PARAMS(const UniverseID componentid))
    {
        const auto callResult = invoke(GetEntitySelectedIcon, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetEquipmentModPropertyName(PARAMS(const char* wareid))
    {
        const auto callResult = invoke(GetEquipmentModPropertyName, wareid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetFactionNameForTargetMonitorHack(PARAMS(UniverseID componentid))
    {
        const auto callResult = invoke(GetFactionNameForTargetMonitorHack, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetFleetName(PARAMS(UniverseID controllableid))
    {
        const auto callResult = invoke(GetFleetName, controllableid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetLocalizedInputName(PARAMS(uint32_t sourceid,uint32_t codeid))
    {
        const auto callResult = invoke(GetLocalizedInputName, sourceid, codeid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetLocalizedInteractiveNotificationKey(PARAMS())
    {
        const auto callResult = invoke(GetLocalizedInteractiveNotificationKey);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetLocalizedRawMouseButtonName(PARAMS(uint32_t keycodeid))
    {
        const auto callResult = invoke(GetLocalizedRawMouseButtonName, keycodeid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetLocalizedText(PARAMS(uint32_t pageid,uint32_t textid,const char* defaultvalue))
    {
        const auto callResult = invoke(GetLocalizedText, pageid, textid, defaultvalue);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetMacroClass(PARAMS(const char* macroname))
    {
        const auto callResult = invoke(GetMacroClass, macroname);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetMacroMapPositionOnEcliptic(PARAMS(UniverseID holomapid))
    {
        UIPosRot position;
        const auto callResult = invoke(GetMacroMapPositionOnEcliptic, holomapid, &position);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetMappedInputName(PARAMS(const char* functionkey))
    {
        const auto callResult = invoke(GetMappedInputName, functionkey);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetMissingConstructionPlanBlueprints(PARAMS(UniverseID containerid,const char* constructionplanid))
    {
        const auto callResult = invoke(GetMissingConstructionPlanBlueprints, containerid, constructionplanid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetMouseOverText(PARAMS(const int widgetid))
    {
        const auto callResult = invoke(GetMouseOverText, widgetid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetObjectIDCode(PARAMS(UniverseID objectid))
    {
        const auto callResult = invoke(GetObjectIDCode, objectid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPersonName(PARAMS(NPCSeed person,UniverseID controllableid))
    {
        const auto callResult = invoke(GetPersonName, person, controllableid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPersonRole(PARAMS(NPCSeed person,UniverseID controllableid))
    {
        const auto callResult = invoke(GetPersonRole, person, controllableid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPersonRoleName(PARAMS(NPCSeed person,UniverseID controllableid))
    {
        const auto callResult = invoke(GetPersonRoleName, person, controllableid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPlayerClothingTheme(PARAMS())
    {
        const auto callResult = invoke(GetPlayerClothingTheme);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPlayerFactionName(PARAMS(bool userawname))
    {
        const auto callResult = invoke(GetPlayerFactionName, userawname);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPlayerName(PARAMS())
    {
        const auto callResult = invoke(GetPlayerName);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPlayerPaintTheme(PARAMS())
    {
        const auto callResult = invoke(GetPlayerPaintTheme);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPlayerShipSize(PARAMS())
    {
        const auto callResult = invoke(GetPlayerShipSize);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPresentModeOption(PARAMS())
    {
        const auto callResult = invoke(GetPresentModeOption);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPurposeName(PARAMS(const char* purposeid))
    {
        const auto callResult = invoke(GetPurposeName, purposeid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetRealComponentClass(PARAMS(UniverseID componentid))
    {
        const auto callResult = invoke(GetRealComponentClass, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetSSROption2(PARAMS())
    {
        const auto callResult = invoke(GetSSROption2);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetSaveLocationName(PARAMS())
    {
        const auto callResult = invoke(GetSaveLocationName);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetShipOrLaserTowerSize(PARAMS(const UniverseID componentid))
    {
        const auto callResult = invoke(GetShipOrLaserTowerSize, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetShipPurpose(PARAMS(const UniverseID componentid))
    {
        const auto callResult = invoke(GetShipPurpose, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetSliderCellSuffix(PARAMS(const int slidercellid))
    {
        const auto callResult = invoke(GetSliderCellSuffix, slidercellid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetSliderCellText(PARAMS(const int slidercellid))
    {
        const auto callResult = invoke(GetSliderCellText, slidercellid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetSlotSize(PARAMS(UniverseID defensibleid,UniverseID moduleid,const char* macroname,bool ismodule,const char* upgradetypename,size_t slot))
    {
        const auto callResult = invoke(GetSlotSize, defensibleid, moduleid, macroname, ismodule, upgradetypename, slot);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetSoftwareMaxCompatibleVersion(PARAMS(UniverseID controllableid,const char* macroname,const char* softwarename))
    {
        const auto callResult = invoke(GetSoftwareMaxCompatibleVersion, controllableid, macroname, softwarename);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetSteamID(PARAMS())
    {
        const auto callResult = invoke(GetSteamID);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetSubordinateGroupAssignment(PARAMS(UniverseID controllableid,int group))
    {
        const auto callResult = invoke(GetSubordinateGroupAssignment, controllableid, group);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetTableBackgroundID(PARAMS(const int tableid))
    {
        const auto callResult = invoke(GetTableBackgroundID, tableid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetTextureQualityOption(PARAMS())
    {
        const auto callResult = invoke(GetTextureQualityOption);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetTobiiMode(PARAMS())
    {
        const auto callResult = invoke(GetTobiiMode);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetTrackerNameOption(PARAMS())
    {
        const auto callResult = invoke(GetTrackerNameOption);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetTrackerSDKOption(PARAMS())
    {
        const auto callResult = invoke(GetTrackerSDKOption);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetTurretGroupMode2(PARAMS(UniverseID defensibleid,UniverseID contextid,const char* path,const char* group))
    {
        const auto callResult = invoke(GetTurretGroupMode2, defensibleid, contextid, path, group);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetUpgradeSlotCurrentMacro(PARAMS(UniverseID objectid,UniverseID moduleid,const char* upgradetypename,size_t slot))
    {
        const auto callResult = invoke(GetUpgradeSlotCurrentMacro, objectid, moduleid, upgradetypename, slot);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetVirtualUpgradeSlotCurrentMacro(PARAMS(UniverseID defensibleid,const char* upgradetypename,size_t slot))
    {
        const auto callResult = invoke(GetVirtualUpgradeSlotCurrentMacro, defensibleid, upgradetypename, slot);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetWeaponMode(PARAMS(UniverseID weaponid))
    {
        const auto callResult = invoke(GetWeaponMode, weaponid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json RequestDockAtReason(PARAMS(UniverseID containerid,bool checkonly))
    {
        const auto callResult = invoke(RequestDockAtReason, containerid, checkonly);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json UndockPlayerShip(PARAMS(bool checkonly))
    {
        const auto callResult = invoke(UndockPlayerShip, checkonly);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetBuildProcessorEstimatedTimeLeft(PARAMS(UniverseID buildprocessorid))
    {
        const auto callResult = invoke(GetBuildProcessorEstimatedTimeLeft, buildprocessorid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetBuildTaskDuration(PARAMS(UniverseID containerid,BuildTaskID id))
    {
        const auto callResult = invoke(GetBuildTaskDuration, containerid, id);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetContainerWareConsumption(PARAMS(UniverseID containerid,const char* wareid,bool ignorestate))
    {
        const auto callResult = invoke(GetContainerWareConsumption, containerid, wareid, ignorestate);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetContainerWareProduction(PARAMS(UniverseID containerid,const char* wareid,bool ignorestate))
    {
        const auto callResult = invoke(GetContainerWareProduction, containerid, wareid, ignorestate);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetCurrentGameTime(PARAMS())
    {
        const auto callResult = invoke(GetCurrentGameTime);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAdaptiveSamplingOption(PARAMS())
    {
        const auto callResult = invoke(GetAdaptiveSamplingOption);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetCockpitCameraScaleOption(PARAMS())
    {
        const auto callResult = invoke(GetCockpitCameraScaleOption);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetContainerBuildPriceFactor(PARAMS(UniverseID containerid))
    {
        const auto callResult = invoke(GetContainerBuildPriceFactor, containerid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetContainerGlobalPriceFactor(PARAMS(UniverseID containerid))
    {
        const auto callResult = invoke(GetContainerGlobalPriceFactor, containerid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetCurrentBuildProgress(PARAMS(UniverseID containerid))
    {
        const auto callResult = invoke(GetCurrentBuildProgress, containerid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetDefensibleLoadoutLevel(PARAMS(UniverseID defensibleid))
    {
        const auto callResult = invoke(GetDefensibleLoadoutLevel, defensibleid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPlayerGlobalLoadoutLevel(PARAMS())
    {
        const auto callResult = invoke(GetPlayerGlobalLoadoutLevel);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetRectangleTargetElementExtents(PARAMS(const int posid))
    {
        const auto callResult = invoke(GetRectangleTargetElementExtents, posid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetRemainingOxygen(PARAMS())
    {
        const auto callResult = invoke(GetRemainingOxygen);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetResourceBoxSize(PARAMS())
    {
        const auto callResult = invoke(GetResourceBoxSize);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetScanProgress(PARAMS())
    {
        const auto callResult = invoke(GetScanProgress);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetShieldHullBarHullPercent(PARAMS(const int shieldhullbarid))
    {
        const auto callResult = invoke(GetShieldHullBarHullPercent, shieldhullbarid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetShieldHullBarShieldPercent(PARAMS(const int shieldhullbarid))
    {
        const auto callResult = invoke(GetShieldHullBarShieldPercent, shieldhullbarid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetStatusBarCurrentValue(PARAMS(const int statusbarid))
    {
        const auto callResult = invoke(GetStatusBarCurrentValue, statusbarid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetStatusBarMaxValue(PARAMS(const int statusbarid))
    {
        const auto callResult = invoke(GetStatusBarMaxValue, statusbarid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetStatusBarStartValue(PARAMS(const int statusbarid))
    {
        const auto callResult = invoke(GetStatusBarStartValue, statusbarid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetTextHeight(PARAMS(const char*const text,const char*const fontname,const uint32_t fontsize,const float wordwrapwidth))
    {
        const auto callResult = invoke(GetTextHeight, text, fontname, fontsize, wordwrapwidth);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetTextWidth(PARAMS(const char*const text,const char*const fontname,const float fontsize))
    {
        const auto callResult = invoke(GetTextWidth, text, fontname, fontsize);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetTobiiAngleFactor(PARAMS())
    {
        const auto callResult = invoke(GetTobiiAngleFactor);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetTobiiDeadzoneAngle(PARAMS())
    {
        const auto callResult = invoke(GetTobiiDeadzoneAngle);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetTobiiDeadzonePosition(PARAMS())
    {
        const auto callResult = invoke(GetTobiiDeadzonePosition);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetTobiiGazeAngleFactor(PARAMS())
    {
        const auto callResult = invoke(GetTobiiGazeAngleFactor);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetTobiiGazeDeadzone(PARAMS())
    {
        const auto callResult = invoke(GetTobiiGazeDeadzone);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetTobiiHeadPositionFactor(PARAMS())
    {
        const auto callResult = invoke(GetTobiiHeadPositionFactor);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetUIScale(PARAMS(const bool scalewithresolution))
    {
        const auto callResult = invoke(GetUIScale, scalewithresolution);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetUIScaleFactor(PARAMS())
    {
        const auto callResult = invoke(GetUIScaleFactor);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetConfigSetting(PARAMS(const char*const setting))
    {
        const auto callResult = invoke(GetConfigSetting, setting);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNotificationID(PARAMS(const size_t num))
    {
        const auto callResult = invoke(GetNotificationID, num);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPriorityMissiontargetPOSID(PARAMS())
    {
        const auto callResult = invoke(GetPriorityMissiontargetPOSID);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetTableNextConnectedTable(PARAMS(const int tableid))
    {
        const auto callResult = invoke(GetTableNextConnectedTable, tableid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetTableNextHorizontalConnectedTable(PARAMS(const int tableid))
    {
        const auto callResult = invoke(GetTableNextHorizontalConnectedTable, tableid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetTablePreviousConnectedTable(PARAMS(const int tableid))
    {
        const auto callResult = invoke(GetTablePreviousConnectedTable, tableid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetTablePreviousHorizontalConnectedTable(PARAMS(const int tableid))
    {
        const auto callResult = invoke(GetTablePreviousHorizontalConnectedTable, tableid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetVRVivePointerHand(PARAMS())
    {
        const auto callResult = invoke(GetVRVivePointerHand);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetContainerBuyLimit(PARAMS(UniverseID containerid,const char* wareid))
    {
        const auto callResult = invoke(GetContainerBuyLimit, containerid, wareid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetContainerSellLimit(PARAMS(UniverseID containerid,const char* wareid))
    {
        const auto callResult = invoke(GetContainerSellLimit, containerid, wareid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetCurrentLanguage(PARAMS())
    {
        const auto callResult = invoke(GetCurrentLanguage);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetEditBoxTextOffsetY(PARAMS(const int editboxid))
    {
        const auto callResult = invoke(GetEditBoxTextOffsetY, editboxid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetEntityCombinedSkill(PARAMS(UniverseID entityid,const char* role,const char* postid))
    {
        const auto callResult = invoke(GetEntityCombinedSkill, entityid, role, postid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPersonCombinedSkill(PARAMS(UniverseID controllableid,NPCSeed person,const char* role,const char* postid))
    {
        const auto callResult = invoke(GetPersonCombinedSkill, controllableid, person, role, postid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPersonTier(PARAMS(NPCSeed npc,const char* role,UniverseID controllableid))
    {
        const auto callResult = invoke(GetPersonTier, npc, role, controllableid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetRequestedLanguage(PARAMS())
    {
        const auto callResult = invoke(GetRequestedLanguage);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetShipCombinedSkill(PARAMS(UniverseID shipid))
    {
        const auto callResult = invoke(GetShipCombinedSkill, shipid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetSliderCellAccuracyOverride(PARAMS(const int slidercellid))
    {
        const auto callResult = invoke(GetSliderCellAccuracyOverride, slidercellid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetUIRelation(PARAMS(const char* fromfactionid,const char* tofactionid))
    {
        const auto callResult = invoke(GetUIRelation, fromfactionid, tofactionid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetBuildPlotPayment(PARAMS(UniverseID stationid))
    {
        bool positionchanged;
        const auto callResult = invoke(GetBuildPlotPayment, stationid, &positionchanged);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
                {"positionchanged", positionchanged}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetBuildWarePrice(PARAMS(UniverseID containerid,const char* warename))
    {
        const auto callResult = invoke(GetBuildWarePrice, containerid, warename);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetBuilderHiringFee(PARAMS())
    {
        const auto callResult = invoke(GetBuilderHiringFee);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetCreditsDueFromPlayerTrades(PARAMS())
    {
        const auto callResult = invoke(GetCreditsDueFromPlayerTrades);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetCustomGameStartMoneyProperty(PARAMS(const char* id,const char* propertyid))
    {
        CustomGameStartMoneyPropertyState state;
        const auto callResult = invoke(GetCustomGameStartMoneyProperty, id, propertyid, &state);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetRepairPrice(PARAMS(UniverseID componenttorepairid,UniverseID containerid))
    {
        const auto callResult = invoke(GetRepairPrice, componenttorepairid, containerid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetSupplyBudget(PARAMS(UniverseID containerid))
    {
        const auto callResult = invoke(GetSupplyBudget, containerid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetBuildMapConstructionPlan(PARAMS(UniverseID holomapid,UniverseID defensibleid,bool usestoredplan))
    {
        uint32_t resultlen = 32767;
        std::vector<UIConstructionPlanEntry> result;
        result.resize(resultlen);
        const auto callResult = invoke(GetBuildMapConstructionPlan, holomapid, defensibleid, usestoredplan, result.data(), resultlen);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetConstructionMapVenturePlatform(PARAMS(UniverseID holomapid,size_t venturedockidx))
    {
        const auto callResult = invoke(GetConstructionMapVenturePlatform, holomapid, venturedockidx);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumAcceptedMissions(PARAMS())
    {
        const auto callResult = invoke(GetNumAcceptedMissions);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumBuildMapConstructionPlan(PARAMS(UniverseID holomapid,bool usestoredplan))
    {
        const auto callResult = invoke(GetNumBuildMapConstructionPlan, holomapid, usestoredplan);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumNotifications(PARAMS())
    {
        const auto callResult = invoke(GetNumNotifications);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumPlannedStationModules(PARAMS(UniverseID defensibleid,bool includeall))
    {
        const auto callResult = invoke(GetNumPlannedStationModules, defensibleid, includeall);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumPrimaryWeapons(PARAMS())
    {
        const auto callResult = invoke(GetNumPrimaryWeapons);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumSecondaryWeapons(PARAMS())
    {
        const auto callResult = invoke(GetNumSecondaryWeapons);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumTradeComputerOrders(PARAMS(UniverseID controllableid))
    {
        const auto callResult = invoke(GetNumTradeComputerOrders, controllableid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumTurretSlots(PARAMS())
    {
        const auto callResult = invoke(GetNumTurretSlots);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumTurrets(PARAMS())
    {
        const auto callResult = invoke(GetNumTurrets);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumUpgradeSlots(PARAMS(UniverseID destructibleid,const char* macroname,const char* upgradetypename))
    {
        const auto callResult = invoke(GetNumUpgradeSlots, destructibleid, macroname, upgradetypename);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumVirtualUpgradeSlots(PARAMS(UniverseID objectid,const char* macroname,const char* upgradetypename))
    {
        const auto callResult = invoke(GetNumVirtualUpgradeSlots, objectid, macroname, upgradetypename);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumWeaponSlots(PARAMS())
    {
        const auto callResult = invoke(GetNumWeaponSlots);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPlannedStationModules(PARAMS(UniverseID defensibleid,bool includeall))
    {
        uint32_t resultlen = 32767;
        std::vector<UIConstructionPlanEntry> result;
        result.resize(resultlen);
        const auto callResult = invoke(GetPlannedStationModules, result.data(), resultlen, defensibleid, includeall);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetSelectedBuildMapEntry(PARAMS(UniverseID holomapid))
    {
        const auto callResult = invoke(GetSelectedBuildMapEntry, holomapid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetTobiiGazeFilterStrength(PARAMS())
    {
        const auto callResult = invoke(GetTobiiGazeFilterStrength);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetTobiiHeadFilterStrength(PARAMS())
    {
        const auto callResult = invoke(GetTobiiHeadFilterStrength);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json CreateOrder(PARAMS(UniverseID controllableid,const char* orderid,bool defaultorder))
    {
        uint32_t callResult = invoke(CreateOrder, controllableid, orderid, defaultorder);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json CreateOrder2(PARAMS(UniverseID controllableid,const char* orderid,bool defaultorder,bool isoverride))
    {
        uint32_t callResult = invoke(CreateOrder2, controllableid, orderid, defaultorder, isoverride);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetActivePrimaryWeaponGroup(PARAMS())
    {
        uint32_t callResult = invoke(GetActivePrimaryWeaponGroup);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetActiveSecondaryWeaponGroup(PARAMS())
    {
        uint32_t callResult = invoke(GetActiveSecondaryWeaponGroup);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAllBlacklists(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<BlacklistID> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetAllBlacklists, result.data(), resultlen);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAllBoardingBehaviours(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<BoardingBehaviour> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetAllBoardingBehaviours, result.data(), resultlen);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"id", v.id},
                    {"text", v.text}
                });
            }
            return json
            {
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAllBoardingPhases(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<BoardingPhase> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetAllBoardingPhases, result.data(), resultlen);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"id", v.id},
                    {"text", v.text}
                });
            }
            return json
            {
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAllControlPosts(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<ControlPostInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetAllControlPosts, result.data(), resultlen);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"id", v.id},
                    {"name", v.name}
                });
            }
            return json
            {
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAllCountermeasures(PARAMS(UniverseID defensibleid))
    {
        uint32_t resultlen = 32767;
        std::vector<AmmoData> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetAllCountermeasures, result.data(), resultlen, defensibleid);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAllEquipment(PARAMS(bool playerblueprint))
    {
        uint32_t resultlen = 32767;
        std::vector<EquipmentWareInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetAllEquipment, result.data(), resultlen, playerblueprint);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAllEquipmentModProperties(PARAMS(const char* equipmentmodclass))
    {
        uint32_t resultlen = 32767;
        std::vector<EquipmentModPropertyInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetAllEquipmentModProperties, result.data(), resultlen, equipmentmodclass);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAllFactionShips(PARAMS(const char* factionid))
    {
        uint32_t resultlen = 32767;
        std::vector<UniverseID> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetAllFactionShips, result.data(), resultlen, factionid);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAllFactionStations(PARAMS(const char* factionid))
    {
        uint32_t resultlen = 32767;
        std::vector<UniverseID> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetAllFactionStations, result.data(), resultlen, factionid);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAllFactions(PARAMS(bool includehidden))
    {
        uint32_t resultlen = 32767;
        std::vector<const char*> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetAllFactions, result.data(), resultlen, includehidden);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAllInventoryBombs(PARAMS(UniverseID entityid))
    {
        uint32_t resultlen = 32767;
        std::vector<AmmoData> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetAllInventoryBombs, result.data(), resultlen, entityid);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAllLaserTowers(PARAMS(UniverseID defensibleid))
    {
        uint32_t resultlen = 32767;
        std::vector<AmmoData> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetAllLaserTowers, result.data(), resultlen, defensibleid);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAllMines(PARAMS(UniverseID defensibleid))
    {
        uint32_t resultlen = 32767;
        std::vector<AmmoData> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetAllMines, result.data(), resultlen, defensibleid);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAllMissiles(PARAMS(UniverseID defensibleid))
    {
        uint32_t resultlen = 32767;
        std::vector<AmmoData> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetAllMissiles, result.data(), resultlen, defensibleid);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAllModuleSets(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<UIModuleSet> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetAllModuleSets, result.data(), resultlen);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"id", v.id},
                    {"name", v.name}
                });
            }
            return json
            {
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAllNavBeacons(PARAMS(UniverseID defensibleid))
    {
        uint32_t resultlen = 32767;
        std::vector<AmmoData> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetAllNavBeacons, result.data(), resultlen, defensibleid);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAllRaces(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<RaceInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetAllRaces, result.data(), resultlen);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAllResourceProbes(PARAMS(UniverseID defensibleid))
    {
        uint32_t resultlen = 32767;
        std::vector<AmmoData> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetAllResourceProbes, result.data(), resultlen, defensibleid);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAllResponsesToSignal(PARAMS(const char* signalid))
    {
        uint32_t resultlen = 32767;
        std::vector<ResponseInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetAllResponsesToSignal, result.data(), resultlen, signalid);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAllRoles(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<PeopleInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetAllRoles, result.data(), resultlen);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAllSatellites(PARAMS(UniverseID defensibleid))
    {
        uint32_t resultlen = 32767;
        std::vector<AmmoData> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetAllSatellites, result.data(), resultlen, defensibleid);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAllShipMacros(PARAMS(bool playerblueprint))
    {
        uint32_t resultlen = 32767;
        std::vector<const char*> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetAllShipMacros, result.data(), resultlen, playerblueprint);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAllSignals(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<SignalInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetAllSignals, result.data(), resultlen);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAllUnits(PARAMS(UniverseID defensibleid,bool onlydrones))
    {
        uint32_t resultlen = 32767;
        std::vector<UnitData> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetAllUnits, result.data(), resultlen, defensibleid, onlydrones);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAllowedWeaponSystems(PARAMS(UniverseID defensibleid,size_t orderidx,bool usedefault))
    {
        uint32_t resultlen = 32767;
        std::vector<WeaponSystemInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetAllowedWeaponSystems, result.data(), resultlen, defensibleid, orderidx, usedefault);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAmmoStorage(PARAMS(UniverseID defensibleid,const char* ammotype))
    {
        uint32_t resultlen = 32767;
        std::vector<AmmoData> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetAmmoStorage, result.data(), resultlen, defensibleid, ammotype);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAmountOfWareAvailable(PARAMS(const char* wareid,UniverseID productionmoduleid))
    {
        uint32_t callResult = invoke(GetAmountOfWareAvailable, wareid, productionmoduleid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAssignedConstructionVessels(PARAMS(UniverseID containerid))
    {
        uint32_t resultlen = 32767;
        std::vector<UniverseID> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetAssignedConstructionVessels, result.data(), resultlen, containerid);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAttackersOfBoardingOperation(PARAMS(UniverseID defensibletargetid,const char* boarderfactionid))
    {
        uint32_t resultlen = 32767;
        std::vector<UniverseID> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetAttackersOfBoardingOperation, result.data(), resultlen, defensibletargetid, boarderfactionid);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAvailableClothingThemes(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<UIClothingTheme> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetAvailableClothingThemes, result.data(), resultlen);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAvailableEquipment(PARAMS(UniverseID containerid,const char* classid))
    {
        uint32_t resultlen = 32767;
        std::vector<EquipmentWareInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetAvailableEquipment, result.data(), resultlen, containerid, classid);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAvailableEquipmentMods(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<UIEquipmentMod> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetAvailableEquipmentMods, result.data(), resultlen);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAvailableLockboxes(PARAMS(UniverseID entityid))
    {
        uint32_t resultlen = 32767;
        std::vector<const char*> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetAvailableLockboxes, result.data(), resultlen, entityid);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetAvailablePaintThemes(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<UIPaintTheme> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetAvailablePaintThemes, result.data(), resultlen);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetBlueprints(PARAMS(const char* set,const char* category,const char* macroname))
    {
        uint32_t resultlen = 32767;
        std::vector<UIBlueprint> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetBlueprints, result.data(), resultlen, set, category, macroname);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetBoardingCasualtiesOfTier(PARAMS(int32_t marinetierskilllevel,UniverseID defensibletargetid,const char* boarderfactionid))
    {
        uint32_t callResult = invoke(GetBoardingCasualtiesOfTier, marinetierskilllevel, defensibletargetid, boarderfactionid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetBoardingStrengthFromOperation(PARAMS(UniverseID defensibletargetid,const char* boarderfactionid))
    {
        uint32_t callResult = invoke(GetBoardingStrengthFromOperation, defensibletargetid, boarderfactionid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetBoardingStrengthOfControllableTierAmounts(PARAMS(UniverseID controllableid,uint32_t nummarinetiers))
    {
        uint32_t marinetieramounts;
        int32_t marinetierskilllevels;
        uint32_t callResult = invoke(GetBoardingStrengthOfControllableTierAmounts, controllableid, &marinetieramounts, &marinetierskilllevels, nummarinetiers);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
                {"marinetieramounts", marinetieramounts},
                {"marinetierskilllevels", marinetierskilllevels}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetBuildModules(PARAMS(UniverseID containerid))
    {
        uint32_t resultlen = 32767;
        std::vector<UniverseID> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetBuildModules, result.data(), resultlen, containerid);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetBuildSequenceResources(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<UIWareInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetBuildSequenceResources, result.data(), resultlen);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetBuildTasks(PARAMS(UniverseID containerid,UniverseID buildmoduleid,bool isinprogress,bool includeupgrade))
    {
        uint32_t resultlen = 32767;
        std::vector<BuildTaskInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetBuildTasks, result.data(), resultlen, containerid, buildmoduleid, isinprogress, includeupgrade);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetCargo(PARAMS(UniverseID containerid,const char* tags))
    {
        uint32_t resultlen = 32767;
        std::vector<UIWareInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetCargo, result.data(), resultlen, containerid, tags);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetCargoStatistics(PARAMS(size_t numdatapoints))
    {
        uint32_t resultlen = 32767;
        std::vector<UICargoStat> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetCargoStatistics, result.data(), resultlen, numdatapoints);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetCargoTransportTypes(PARAMS(UniverseID containerid,bool merge,bool aftertradeorders))
    {
        uint32_t resultlen = 32767;
        std::vector<StorageInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetCargoTransportTypes, result.data(), resultlen, containerid, merge, aftertradeorders);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetCloseOnUnhandledClickFrames(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<int> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetCloseOnUnhandledClickFrames, result.data(), resultlen);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetConstructionPlanInvalidPatches(PARAMS(const char* constructionplanid))
    {
        uint32_t resultlen = 32767;
        std::vector<InvalidPatchInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetConstructionPlanInvalidPatches, result.data(), resultlen, constructionplanid);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetConstructionPlans(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<UIConstructionPlan> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetConstructionPlans, result.data(), resultlen);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetContainerAllowedBuildFactions(PARAMS(UniverseID containerid))
    {
        uint32_t resultlen = 32767;
        std::vector<const char*> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetContainerAllowedBuildFactions, result.data(), resultlen, containerid);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetContainerBuildResources(PARAMS(UniverseID containerid))
    {
        uint32_t resultlen = 32767;
        std::vector<const char*> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetContainerBuildResources, result.data(), resultlen, containerid);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetContainerBuilderMacros(PARAMS(UniverseID containerid))
    {
        uint32_t resultlen = 32767;
        std::vector<const char*> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetContainerBuilderMacros, result.data(), resultlen, containerid);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetContainerStockLimitOverrides(PARAMS(UniverseID containerid))
    {
        uint32_t resultlen = 32767;
        std::vector<UIWareInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetContainerStockLimitOverrides, result.data(), resultlen, containerid);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetContainerWareReservations(PARAMS(UniverseID containerid))
    {
        uint32_t resultlen = 32767;
        std::vector<WareReservationInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetContainerWareReservations, result.data(), resultlen, containerid);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetCurrentMissionOffers(PARAMS(bool showninbbs))
    {
        uint32_t resultlen = 32767;
        std::vector<uint64_t> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetCurrentMissionOffers, result.data(), resultlen, showninbbs);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetCurrentVentureShips(PARAMS(UniverseID ventureplatformid))
    {
        uint32_t resultlen = 32767;
        std::vector<UniverseID> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetCurrentVentureShips, result.data(), resultlen, ventureplatformid);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetCustomGameStartBlueprintDefaultProperty(PARAMS(const char* id,const char* propertyid))
    {
        uint32_t resultlen = 32767;
        std::vector<CustomGameStartBlueprint> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetCustomGameStartBlueprintDefaultProperty, result.data(), resultlen, id, propertyid);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"ware", v.ware}
                });
            }
            return json
            {
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetCustomGameStartBlueprintProperty(PARAMS(const char* id,const char* propertyid))
    {
        uint32_t resultlen = 32767;
        std::vector<CustomGameStartBlueprint> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetCustomGameStartBlueprintProperty, result.data(), resultlen, id, propertyid);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"ware", v.ware}
                });
            }
            return json
            {
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetCustomGameStartEncyclopediaProperty(PARAMS(const char* id,const char* propertyid))
    {
        uint32_t resultlen = 32767;
        std::vector<CustomGameStartEncyclopediaEntry> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetCustomGameStartEncyclopediaProperty, result.data(), resultlen, id, propertyid);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"library", v.library},
                    {"item", v.item}
                });
            }
            return json
            {
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetCustomGameStartEncyclopediaPropertyCounts(PARAMS(const char* id,const char* propertyid))
    {
        uint32_t callResult = invoke(GetCustomGameStartEncyclopediaPropertyCounts, id, propertyid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetCustomGameStartInventoryDefaultProperty(PARAMS(const char* id,const char* propertyid))
    {
        uint32_t resultlen = 32767;
        std::vector<CustomGameStartInventory> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetCustomGameStartInventoryDefaultProperty, result.data(), resultlen, id, propertyid);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"ware", v.ware},
                    {"amount", v.amount}
                });
            }
            return json
            {
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetCustomGameStartInventoryProperty(PARAMS(const char* id,const char* propertyid))
    {
        uint32_t resultlen = 32767;
        std::vector<CustomGameStartInventory> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetCustomGameStartInventoryProperty, result.data(), resultlen, id, propertyid);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"ware", v.ware},
                    {"amount", v.amount}
                });
            }
            return json
            {
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetCustomGameStartRelationsProperty(PARAMS(const char* id,const char* propertyid))
    {
        uint32_t resultlen = 32767;
        std::vector<CustomGameStartRelationInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetCustomGameStartRelationsProperty, result.data(), resultlen, id, propertyid);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetCustomGameStartRelationsPropertyCounts(PARAMS(const char* id,const char* propertyid))
    {
        uint32_t callResult = invoke(GetCustomGameStartRelationsPropertyCounts, id, propertyid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetCustomGameStartResearchProperty(PARAMS(const char* id,const char* propertyid))
    {
        uint32_t resultlen = 32767;
        std::vector<const char*> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetCustomGameStartResearchProperty, result.data(), resultlen, id, propertyid);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetCustomGameStartResearchPropertyCounts(PARAMS(const char* id,const char* propertyid))
    {
        uint32_t callResult = invoke(GetCustomGameStartResearchPropertyCounts, id, propertyid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetDamagedSubComponents(PARAMS(UniverseID objectid))
    {
        uint32_t resultlen = 32767;
        std::vector<UniverseID> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetDamagedSubComponents, result.data(), resultlen, objectid);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetDefaultCountermeasureStorageCapacity(PARAMS(const char* macroname))
    {
        uint32_t callResult = invoke(GetDefaultCountermeasureStorageCapacity, macroname);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetDefaultMissileStorageCapacity(PARAMS(const char* macroname))
    {
        uint32_t callResult = invoke(GetDefaultMissileStorageCapacity, macroname);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetDefensibleActiveWeaponGroup(PARAMS(UniverseID defensibleid,bool primary))
    {
        uint32_t callResult = invoke(GetDefensibleActiveWeaponGroup, defensibleid, primary);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetDefensibleDPS(PARAMS(UniverseID defensibleid,bool primary,bool secondary,bool lasers,bool missiles,bool turrets,bool includeheat,bool includeinactive))
    {
        DPSData result;
        uint32_t callResult = invoke(GetDefensibleDPS, &result, defensibleid, primary, secondary, lasers, missiles, turrets, includeheat, includeinactive);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
                {"result", {
                    {"dps", result.dps},
                    {"quadranttextid", result.quadranttextid}
                }}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetDefensibleDeployableCapacity(PARAMS(UniverseID defensibleid))
    {
        uint32_t callResult = invoke(GetDefensibleDeployableCapacity, defensibleid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetDockedShips(PARAMS(UniverseID dockingbayorcontainerid,const char* factionid))
    {
        uint32_t resultlen = 32767;
        std::vector<UniverseID> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetDockedShips, result.data(), resultlen, dockingbayorcontainerid, factionid);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetDroneModes(PARAMS(UniverseID defensibleid,const char* dronetype))
    {
        uint32_t resultlen = 32767;
        std::vector<DroneModeInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetDroneModes, result.data(), resultlen, defensibleid, dronetype);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetDropDownOptionHeight(PARAMS(const int dropdownid))
    {
        uint32_t callResult = invoke(GetDropDownOptionHeight, dropdownid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetDropDownOptionWidth(PARAMS(const int dropdownid))
    {
        uint32_t callResult = invoke(GetDropDownOptionWidth, dropdownid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetDropDownOptions(PARAMS(const int dropdownid))
    {
        uint32_t resultlen = 32767;
        std::vector<DropDownOption> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetDropDownOptions, result.data(), resultlen, dropdownid);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetEditBoxTextOffsetX(PARAMS(const int editboxid))
    {
        uint32_t callResult = invoke(GetEditBoxTextOffsetX, editboxid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetFormationShapes(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<UIFormationInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetFormationShapes, result.data(), resultlen);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetFreeCountermeasureStorageAfterTradeOrders(PARAMS(UniverseID defensibleid))
    {
        uint32_t callResult = invoke(GetFreeCountermeasureStorageAfterTradeOrders, defensibleid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetFreeDeployableStorageAfterTradeOrders(PARAMS(UniverseID defensibleid))
    {
        uint32_t callResult = invoke(GetFreeDeployableStorageAfterTradeOrders, defensibleid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetFreeMissileStorageAfterTradeOrders(PARAMS(UniverseID defensibleid))
    {
        uint32_t callResult = invoke(GetFreeMissileStorageAfterTradeOrders, defensibleid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetFreePeopleCapacity(PARAMS(UniverseID controllableid))
    {
        uint32_t callResult = invoke(GetFreePeopleCapacity, controllableid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetGraphData(PARAMS(const int graphid,const size_t datarecordidx))
    {
        uint32_t resultlen = 32767;
        std::vector<GraphDataPoint> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetGraphData, result.data(), resultlen, graphid, datarecordidx);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"x", v.x},
                    {"y", v.y}
                });
            }
            return json
            {
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetGraphDataRecords(PARAMS(int graphid))
    {
        uint32_t resultlen = 32767;
        std::vector<GraphDataRecord> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetGraphDataRecords, result.data(), resultlen, graphid);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetGraphIcons(PARAMS(int graphid))
    {
        uint32_t resultlen = 32767;
        std::vector<GraphIcon> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetGraphIcons, result.data(), resultlen, graphid);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetGraphType(PARAMS(const int graphid))
    {
        uint32_t callResult = invoke(GetGraphType, graphid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetHQs(PARAMS(const char* factionid))
    {
        uint32_t resultlen = 32767;
        std::vector<UniverseID> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetHQs, result.data(), resultlen, factionid);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetIllegalToFactions(PARAMS(const char* wareid))
    {
        uint32_t resultlen = 32767;
        std::vector<const char*> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetIllegalToFactions, result.data(), resultlen, wareid);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetInventoryPaintMods(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<UIPaintMod> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetInventoryPaintMods, result.data(), resultlen);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetLUTMode(PARAMS())
    {
        uint32_t callResult = invoke(GetLUTMode);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetLanguages(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<LanguageInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetLanguages, result.data(), resultlen);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetLibraryEntryAliases(PARAMS(const char* librarytypeid,const char* id))
    {
        uint32_t resultlen = 32767;
        std::vector<const char*> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetLibraryEntryAliases, result.data(), resultlen, librarytypeid, id);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetLoadoutCounts(PARAMS(UniverseID defensibleid,const char* macroname,const char* loadoutid))
    {
        UILoadoutCounts result;
        uint32_t callResult = invoke(GetLoadoutCounts, &result, defensibleid, macroname, loadoutid);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetLoadoutInvalidPatches(PARAMS(UniverseID defensibleid,const char* macroname,const char* loadoutid))
    {
        uint32_t resultlen = 32767;
        std::vector<InvalidPatchInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetLoadoutInvalidPatches, result.data(), resultlen, defensibleid, macroname, loadoutid);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetLoadoutsInfo(PARAMS(UniverseID componentid,const char* macroname))
    {
        uint32_t resultlen = 32767;
        std::vector<UILoadoutInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetLoadoutsInfo, result.data(), resultlen, componentid, macroname);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetMacroDeployableCapacity(PARAMS(const char* macroname))
    {
        uint32_t callResult = invoke(GetMacroDeployableCapacity, macroname);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetMacroMissileCapacity(PARAMS(const char* macroname))
    {
        uint32_t callResult = invoke(GetMacroMissileCapacity, macroname);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetMapComponentMissions(PARAMS(UniverseID holomapid,UniverseID componentid))
    {
        uint32_t resultlen = 32767;
        std::vector<MissionID> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetMapComponentMissions, result.data(), resultlen, holomapid, componentid);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetMapRenderedComponents(PARAMS(UniverseID holomapid))
    {
        uint32_t resultlen = 32767;
        std::vector<UniverseID> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetMapRenderedComponents, result.data(), resultlen, holomapid);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetMapSelectedComponents(PARAMS(UniverseID holomapid))
    {
        uint32_t resultlen = 32767;
        std::vector<UniverseID> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetMapSelectedComponents, result.data(), resultlen, holomapid);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetMaxProductionStorage(PARAMS(UniverseID containerid))
    {
        uint32_t resultlen = 32767;
        std::vector<UIWareAmount> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetMaxProductionStorage, result.data(), resultlen, containerid);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"wareid", v.wareid},
                    {"amount", v.amount}
                });
            }
            return json
            {
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetMessages(PARAMS(size_t start,size_t count,const char* categoryname))
    {
        uint32_t resultlen = 32767;
        std::vector<MessageInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetMessages, result.data(), resultlen, start, count, categoryname);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetMissileCargo(PARAMS(UniverseID containerid))
    {
        uint32_t resultlen = 32767;
        std::vector<UIWareInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetMissileCargo, result.data(), resultlen, containerid);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetMissingBuildResources(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<UIWareInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetMissingBuildResources, result.data(), resultlen);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetMissingLoadoutResources(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<UIWareInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetMissingLoadoutResources, result.data(), resultlen);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetMissionThreadSubMissions(PARAMS(MissionID missionid))
    {
        uint32_t resultlen = 32767;
        std::vector<MissionID> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetMissionThreadSubMissions, result.data(), resultlen, missionid);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetModuleNeededResources(PARAMS(UniverseID holomapid,size_t cp_idx))
    {
        uint32_t resultlen = 32767;
        std::vector<UIWareInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetModuleNeededResources, result.data(), resultlen, holomapid, cp_idx);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetModuleRecycledResources(PARAMS(UniverseID moduleid))
    {
        uint32_t resultlen = 32767;
        std::vector<UIWareInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetModuleRecycledResources, result.data(), resultlen, moduleid);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetMoonInfo(PARAMS(UniverseID clusterid,uint32_t planetidx))
    {
        uint32_t resultlen = 32767;
        std::vector<UICelestialBodyInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetMoonInfo, result.data(), resultlen, clusterid, planetidx);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetMouseHUDModeOption(PARAMS())
    {
        uint32_t callResult = invoke(GetMouseHUDModeOption);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNPCAccountStatistics(PARAMS(UniverseID entityid,double starttime,double endtime))
    {
        uint32_t resultlen = 32767;
        std::vector<UIAccountStatData> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetNPCAccountStatistics, result.data(), resultlen, entityid, starttime, endtime);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"time", v.time},
                    {"money", v.money}
                });
            }
            return json
            {
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNotificationTypes(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<UINotificationType> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetNotificationTypes, result.data(), resultlen);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumAllBlacklists(PARAMS())
    {
        uint32_t callResult = invoke(GetNumAllBlacklists);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumAllBoardingBehaviours(PARAMS())
    {
        uint32_t callResult = invoke(GetNumAllBoardingBehaviours);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumAllBoardingPhases(PARAMS())
    {
        uint32_t callResult = invoke(GetNumAllBoardingPhases);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumAllControlPosts(PARAMS())
    {
        uint32_t callResult = invoke(GetNumAllControlPosts);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumAllCountermeasures(PARAMS(UniverseID defensibleid))
    {
        uint32_t callResult = invoke(GetNumAllCountermeasures, defensibleid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumAllEquipment(PARAMS(bool playerblueprint))
    {
        uint32_t callResult = invoke(GetNumAllEquipment, playerblueprint);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumAllEquipmentModProperties(PARAMS(const char* equipmentmodclass))
    {
        uint32_t callResult = invoke(GetNumAllEquipmentModProperties, equipmentmodclass);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumAllFactionShips(PARAMS(const char* factionid))
    {
        uint32_t callResult = invoke(GetNumAllFactionShips, factionid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumAllFactionStations(PARAMS(const char* factionid))
    {
        uint32_t callResult = invoke(GetNumAllFactionStations, factionid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumAllFactions(PARAMS(bool includehidden))
    {
        uint32_t callResult = invoke(GetNumAllFactions, includehidden);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumAllInventoryBombs(PARAMS(UniverseID entityid))
    {
        uint32_t callResult = invoke(GetNumAllInventoryBombs, entityid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumAllLaserTowers(PARAMS(UniverseID defensibleid))
    {
        uint32_t callResult = invoke(GetNumAllLaserTowers, defensibleid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumAllMines(PARAMS(UniverseID defensibleid))
    {
        uint32_t callResult = invoke(GetNumAllMines, defensibleid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumAllMissiles(PARAMS(UniverseID defensibleid))
    {
        uint32_t callResult = invoke(GetNumAllMissiles, defensibleid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumAllModuleSets(PARAMS())
    {
        uint32_t callResult = invoke(GetNumAllModuleSets);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumAllNavBeacons(PARAMS(UniverseID defensibleid))
    {
        uint32_t callResult = invoke(GetNumAllNavBeacons, defensibleid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumAllRaces(PARAMS())
    {
        uint32_t callResult = invoke(GetNumAllRaces);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumAllResourceProbes(PARAMS(UniverseID defensibleid))
    {
        uint32_t callResult = invoke(GetNumAllResourceProbes, defensibleid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumAllResponsesToSignal(PARAMS(const char* signalid))
    {
        uint32_t callResult = invoke(GetNumAllResponsesToSignal, signalid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumAllRoles(PARAMS())
    {
        uint32_t callResult = invoke(GetNumAllRoles);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumAllSatellites(PARAMS(UniverseID defensibleid))
    {
        uint32_t callResult = invoke(GetNumAllSatellites, defensibleid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumAllShipMacros(PARAMS(bool playerblueprint))
    {
        uint32_t callResult = invoke(GetNumAllShipMacros, playerblueprint);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumAllSignals(PARAMS())
    {
        uint32_t callResult = invoke(GetNumAllSignals);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumAllUnits(PARAMS(UniverseID defensibleid,bool onlydrones))
    {
        uint32_t callResult = invoke(GetNumAllUnits, defensibleid, onlydrones);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumAllowedWeaponSystems(PARAMS())
    {
        uint32_t callResult = invoke(GetNumAllowedWeaponSystems);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumAmmoStorage(PARAMS(UniverseID defensibleid,const char* ammotype))
    {
        uint32_t callResult = invoke(GetNumAmmoStorage, defensibleid, ammotype);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumAssignedConstructionVessels(PARAMS(UniverseID containerid))
    {
        uint32_t callResult = invoke(GetNumAssignedConstructionVessels, containerid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumAttackersOfBoardingOperation(PARAMS(UniverseID defensibletargetid,const char* boarderfactionid))
    {
        uint32_t callResult = invoke(GetNumAttackersOfBoardingOperation, defensibletargetid, boarderfactionid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumAvailableClothingThemes(PARAMS())
    {
        uint32_t callResult = invoke(GetNumAvailableClothingThemes);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumAvailableEquipment(PARAMS(UniverseID containerid,const char* classid))
    {
        uint32_t callResult = invoke(GetNumAvailableEquipment, containerid, classid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumAvailableEquipmentMods(PARAMS())
    {
        uint32_t callResult = invoke(GetNumAvailableEquipmentMods);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumAvailableLockboxes(PARAMS(UniverseID entityid))
    {
        uint32_t callResult = invoke(GetNumAvailableLockboxes, entityid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumAvailablePaintThemes(PARAMS())
    {
        uint32_t callResult = invoke(GetNumAvailablePaintThemes);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumBlueprints(PARAMS(const char* set,const char* category,const char* macroname))
    {
        uint32_t callResult = invoke(GetNumBlueprints, set, category, macroname);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumBoardingMarinesFromOperation(PARAMS(UniverseID defensibletargetid,const char* boarderfactionid))
    {
        uint32_t callResult = invoke(GetNumBoardingMarinesFromOperation, defensibletargetid, boarderfactionid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumBuildModules(PARAMS(UniverseID containerid))
    {
        uint32_t callResult = invoke(GetNumBuildModules, containerid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumBuildTasks(PARAMS(UniverseID containerid,UniverseID buildmoduleid,bool isinprogress,bool includeupgrade))
    {
        uint32_t callResult = invoke(GetNumBuildTasks, containerid, buildmoduleid, isinprogress, includeupgrade);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumCargo(PARAMS(UniverseID containerid,const char* tags))
    {
        uint32_t callResult = invoke(GetNumCargo, containerid, tags);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumCargoStatistics(PARAMS(UniverseID containerorspaceid,double starttime,double endtime,size_t numdatapoints))
    {
        uint32_t callResult = invoke(GetNumCargoStatistics, containerorspaceid, starttime, endtime, numdatapoints);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumCargoTransportTypes(PARAMS(UniverseID containerid,bool merge))
    {
        uint32_t callResult = invoke(GetNumCargoTransportTypes, containerid, merge);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumCloseOnUnhandledClickFrames(PARAMS())
    {
        uint32_t callResult = invoke(GetNumCloseOnUnhandledClickFrames);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumConstructionMapVenturePlatformDocks(PARAMS(UniverseID holomapid,size_t ventureplatformidx))
    {
        uint32_t callResult = invoke(GetNumConstructionMapVenturePlatformDocks, holomapid, ventureplatformidx);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumConstructionPlans(PARAMS())
    {
        uint32_t callResult = invoke(GetNumConstructionPlans);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumContainedKnownSpaces(PARAMS(UniverseID spaceid))
    {
        uint32_t callResult = invoke(GetNumContainedKnownSpaces, spaceid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumContainedKnownUnreadSpaces(PARAMS(UniverseID spaceid))
    {
        uint32_t callResult = invoke(GetNumContainedKnownUnreadSpaces, spaceid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumContainerAllowedBuildFactions(PARAMS(UniverseID containerid))
    {
        uint32_t callResult = invoke(GetNumContainerAllowedBuildFactions, containerid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumContainerBuildResources(PARAMS(UniverseID containerid))
    {
        uint32_t callResult = invoke(GetNumContainerBuildResources, containerid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumContainerBuilderMacros(PARAMS(UniverseID containerid))
    {
        uint32_t callResult = invoke(GetNumContainerBuilderMacros, containerid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumContainerStockLimitOverrides(PARAMS(UniverseID containerid))
    {
        uint32_t callResult = invoke(GetNumContainerStockLimitOverrides, containerid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumContainerWareReservations(PARAMS(UniverseID containerid))
    {
        uint32_t callResult = invoke(GetNumContainerWareReservations, containerid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumCountermeasures(PARAMS())
    {
        uint32_t callResult = invoke(GetNumCountermeasures);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumCurrentMissionOffers(PARAMS(bool showninbbs))
    {
        uint32_t callResult = invoke(GetNumCurrentMissionOffers, showninbbs);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumDockedShips(PARAMS(UniverseID dockingbayorcontainerid,const char* factionid))
    {
        uint32_t callResult = invoke(GetNumDockedShips, dockingbayorcontainerid, factionid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumDroneModes(PARAMS(UniverseID defensibleid,const char* dronetype))
    {
        uint32_t callResult = invoke(GetNumDroneModes, defensibleid, dronetype);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumDropDownOptions(PARAMS(const int dropdownid))
    {
        uint32_t callResult = invoke(GetNumDropDownOptions, dropdownid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumFormationShapes(PARAMS())
    {
        uint32_t callResult = invoke(GetNumFormationShapes);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumGraphDataRecords(PARAMS(int graphid))
    {
        uint32_t callResult = invoke(GetNumGraphDataRecords, graphid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumGraphIcons(PARAMS(int graphid))
    {
        uint32_t callResult = invoke(GetNumGraphIcons, graphid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumHQs(PARAMS(const char* factionid))
    {
        uint32_t callResult = invoke(GetNumHQs, factionid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumIllegalToFactions(PARAMS(const char* wareid))
    {
        uint32_t callResult = invoke(GetNumIllegalToFactions, wareid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumInventoryPaintMods(PARAMS())
    {
        uint32_t callResult = invoke(GetNumInventoryPaintMods);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumLanguages(PARAMS())
    {
        uint32_t callResult = invoke(GetNumLanguages);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumLibraryEntryAliases(PARAMS(const char* librarytypeid,const char* id))
    {
        uint32_t callResult = invoke(GetNumLibraryEntryAliases, librarytypeid, id);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumLoadoutsInfo(PARAMS(UniverseID componentid,const char* macroname))
    {
        uint32_t callResult = invoke(GetNumLoadoutsInfo, componentid, macroname);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumMapComponentMissions(PARAMS(UniverseID holomapid,UniverseID componentid))
    {
        uint32_t callResult = invoke(GetNumMapComponentMissions, holomapid, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumMapRenderedComponents(PARAMS(UniverseID holomapid))
    {
        uint32_t callResult = invoke(GetNumMapRenderedComponents, holomapid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumMapSelectedComponents(PARAMS(UniverseID holomapid))
    {
        uint32_t callResult = invoke(GetNumMapSelectedComponents, holomapid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumMaxProductionStorage(PARAMS(UniverseID containerid))
    {
        uint32_t callResult = invoke(GetNumMaxProductionStorage, containerid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumMessages(PARAMS(const char* categoryname,bool unknownBool))
    {
        uint32_t callResult = invoke(GetNumMessages, categoryname, unknownBool);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumMissileCargo(PARAMS(UniverseID containerid))
    {
        uint32_t callResult = invoke(GetNumMissileCargo, containerid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumMissingBuildResources2(PARAMS(UniverseID containerid,uint32_t numorders,bool playercase))
    {
        UIBuildOrderList orders;
        uint32_t callResult = invoke(GetNumMissingBuildResources2, containerid, &orders, numorders, playercase);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetNumMissingLoadoutResources2(PARAMS(UniverseID containerid,uint32_t numorders,bool playercase))
    {
        UIBuildOrderList orders;
        uint32_t callResult = invoke(GetNumMissingLoadoutResources2, containerid, &orders, numorders, playercase);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
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
            {"callResult", callResult}
        };
    }
 
    json GetNumMissionThreadSubMissions(PARAMS(MissionID missionid))
    {
        uint32_t callResult = invoke(GetNumMissionThreadSubMissions, missionid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumModuleNeededResources(PARAMS(UniverseID holomapid,size_t cp_idx))
    {
        uint32_t callResult = invoke(GetNumModuleNeededResources, holomapid, cp_idx);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumModuleRecycledResources(PARAMS(UniverseID moduleid))
    {
        uint32_t callResult = invoke(GetNumModuleRecycledResources, moduleid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumNotificationTypes(PARAMS())
    {
        uint32_t callResult = invoke(GetNumNotificationTypes);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumObjectsWithSyncPoint(PARAMS(uint32_t syncid,bool onlyreached))
    {
        uint32_t callResult = invoke(GetNumObjectsWithSyncPoint, syncid, onlyreached);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumOrderDefinitions(PARAMS())
    {
        uint32_t callResult = invoke(GetNumOrderDefinitions);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumOrders(PARAMS(UniverseID controllableid))
    {
        uint32_t callResult = invoke(GetNumOrders, controllableid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumPeopleAfterOrders(PARAMS(UniverseID controllableid,int32_t numorders))
    {
        uint32_t callResult = invoke(GetNumPeopleAfterOrders, controllableid, numorders);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumPersonSuitableControlPosts(PARAMS(UniverseID controllableid,UniverseID personcontrollableid,NPCSeed person,bool free))
    {
        uint32_t callResult = invoke(GetNumPersonSuitableControlPosts, controllableid, personcontrollableid, person, free);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumPlannedLimitedModules(PARAMS(const char* constructionplanid))
    {
        uint32_t callResult = invoke(GetNumPlannedLimitedModules, constructionplanid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumPlayerAlertSounds(PARAMS())
    {
        uint32_t callResult = invoke(GetNumPlayerAlertSounds);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumPlayerAlerts(PARAMS())
    {
        uint32_t callResult = invoke(GetNumPlayerAlerts);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumPlayerLogos(PARAMS(bool includestandard,bool includecustom))
    {
        uint32_t callResult = invoke(GetNumPlayerLogos, includestandard, includecustom);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumPlayerShipBuildTasks(PARAMS(bool isinprogress,bool includeupgrade))
    {
        uint32_t callResult = invoke(GetNumPlayerShipBuildTasks, isinprogress, includeupgrade);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumRemovedConstructionPlanModules2(PARAMS(UniverseID holomapid,UniverseID defensibleid,bool usestoredplan,bool checkupgrades))
    {
        uint32_t newIndex;
        uint32_t numChangedIndices;
        uint32_t callResult = invoke(GetNumRemovedConstructionPlanModules2, holomapid, defensibleid, &newIndex, usestoredplan, &numChangedIndices, checkupgrades);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
                {"newIndex", newIndex},
                {"numChangedIndices", numChangedIndices}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumRemovedStationModules(PARAMS(UniverseID defensibleid))
    {
        uint32_t newIndex;
        uint32_t callResult = invoke(GetNumRemovedStationModules, defensibleid, &newIndex);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
                {"newIndex", newIndex}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumRepairResources(PARAMS(UniverseID componenttorepairid))
    {
        uint32_t callResult = invoke(GetNumRepairResources, componenttorepairid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumResearchModules(PARAMS(UniverseID containerid))
    {
        uint32_t callResult = invoke(GetNumResearchModules, containerid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumSectorsByOwner(PARAMS(const char* factionid))
    {
        uint32_t callResult = invoke(GetNumSectorsByOwner, factionid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumShieldGroups(PARAMS(UniverseID defensibleid))
    {
        uint32_t callResult = invoke(GetNumShieldGroups, defensibleid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumSkills(PARAMS())
    {
        uint32_t callResult = invoke(GetNumSkills);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumSoftwarePredecessors(PARAMS(const char* softwarename))
    {
        uint32_t callResult = invoke(GetNumSoftwarePredecessors, softwarename);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumSoftwareSlots(PARAMS(UniverseID controllableid,const char* macroname))
    {
        uint32_t callResult = invoke(GetNumSoftwareSlots, controllableid, macroname);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumSoundDevices(PARAMS())
    {
        uint32_t callResult = invoke(GetNumSoundDevices);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumStationModules(PARAMS(UniverseID stationid,bool includeconstructions,bool includewrecks))
    {
        uint32_t callResult = invoke(GetNumStationModules, stationid, includeconstructions, includewrecks);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumStationOverviewGraphWares(PARAMS(UniverseID stationid))
    {
        bool initialized;
        uint32_t callResult = invoke(GetNumStationOverviewGraphWares, stationid, &initialized);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
                {"initialized", initialized}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumStoredUnits(PARAMS(UniverseID defensibleid,const char* cat,bool virtualammo))
    {
        uint32_t callResult = invoke(GetNumStoredUnits, defensibleid, cat, virtualammo);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumSubComponents(PARAMS(UniverseID containerid))
    {
        uint32_t callResult = invoke(GetNumSubComponents, containerid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumSuitableBuildProcessors(PARAMS(UniverseID containerid,UniverseID objectid,const char* macroname))
    {
        uint32_t callResult = invoke(GetNumSuitableBuildProcessors, containerid, objectid, macroname);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumSuitableControlPosts(PARAMS(UniverseID controllableid,UniverseID entityid,bool free))
    {
        uint32_t callResult = invoke(GetNumSuitableControlPosts, controllableid, entityid, free);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumSupplyOrders(PARAMS(UniverseID containerid,bool defaultorders))
    {
        uint32_t callResult = invoke(GetNumSupplyOrders, containerid, defaultorders);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumTableInitialMultiselectedRows(PARAMS(const int tableid))
    {
        uint32_t callResult = invoke(GetNumTableInitialMultiselectedRows, tableid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumTiersOfRole(PARAMS(const char* role))
    {
        uint32_t callResult = invoke(GetNumTiersOfRole, role);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumTimeline(PARAMS())
    {
        uint32_t callResult = invoke(GetNumTimeline);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumTradeOfferStatistics(PARAMS(UniverseID containerorspaceid,double starttime,double endtime,size_t numdatapoints))
    {
        uint32_t callResult = invoke(GetNumTradeOfferStatistics, containerorspaceid, starttime, endtime, numdatapoints);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumUnavailableUnits(PARAMS(UniverseID defensibleid,const char* cat))
    {
        uint32_t callResult = invoke(GetNumUnavailableUnits, defensibleid, cat);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumUnitCargo(PARAMS(UniverseID containerid,bool onlydrones))
    {
        uint32_t callResult = invoke(GetNumUnitCargo, containerid, onlydrones);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumUnreadLibraryEntries(PARAMS(const char* libraryid))
    {
        uint32_t callResult = invoke(GetNumUnreadLibraryEntries, libraryid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumUpgradeGroups(PARAMS(UniverseID destructibleid,const char* macroname))
    {
        uint32_t callResult = invoke(GetNumUpgradeGroups, destructibleid, macroname);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumUsedLimitedModules(PARAMS(UniverseID excludedstationid))
    {
        uint32_t callResult = invoke(GetNumUsedLimitedModules, excludedstationid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumUsedLimitedModulesFromSubsequence(PARAMS(UniverseID holomapid,size_t cp_idx))
    {
        uint32_t callResult = invoke(GetNumUsedLimitedModulesFromSubsequence, holomapid, cp_idx);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumValidTransporterTargets(PARAMS(UniverseID componentid))
    {
        uint32_t callResult = invoke(GetNumValidTransporterTargets, componentid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumVenturePlatformDocks(PARAMS(UniverseID ventureplatformid))
    {
        uint32_t callResult = invoke(GetNumVenturePlatformDocks, ventureplatformid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumVenturePlatforms(PARAMS(UniverseID defensibleid))
    {
        uint32_t callResult = invoke(GetNumVenturePlatforms, defensibleid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumWareBlueprintOwners(PARAMS(const char* wareid))
    {
        uint32_t callResult = invoke(GetNumWareBlueprintOwners, wareid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumWareSources(PARAMS(const char* wareid))
    {
        uint32_t callResult = invoke(GetNumWareSources, wareid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumWares(PARAMS(const char* tags,bool research,const char* licenceownerid,const char* exclusiontags))
    {
        uint32_t callResult = invoke(GetNumWares, tags, research, licenceownerid, exclusiontags);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetNumWeaponGroupsByWeapon(PARAMS(UniverseID defensibleid,UniverseID weaponid))
    {
        uint32_t callResult = invoke(GetNumWeaponGroupsByWeapon, defensibleid, weaponid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetOrderDefinitions(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<OrderDefinition> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetOrderDefinitions, result.data(), resultlen);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetOrders(PARAMS(UniverseID controllableid))
    {
        uint32_t resultlen = 32767;
        std::vector<Order> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetOrders, result.data(), resultlen, controllableid);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetOrders2(PARAMS(UniverseID controllableid))
    {
        uint32_t resultlen = 32767;
        std::vector<Order2> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetOrders2, result.data(), resultlen, controllableid);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPeople(PARAMS(UniverseID controllableid))
    {
        uint32_t resultlen = 32767;
        std::vector<PeopleInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetPeople, result.data(), resultlen, controllableid);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPeopleAfterOrders(PARAMS(UniverseID controllableid,int32_t numorders))
    {
        uint32_t resultlen = 32767;
        std::vector<NPCInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetPeopleAfterOrders, result.data(), resultlen, controllableid, numorders);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPeopleCapacity(PARAMS(UniverseID controllableid,const char* macroname,bool includecrew))
    {
        uint32_t callResult = invoke(GetPeopleCapacity, controllableid, macroname, includecrew);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPersonSkills(PARAMS(NPCSeed person,UniverseID controllableid))
    {
        Skill result;
        uint32_t callResult = invoke(GetPersonSkills, &result, person, controllableid);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
                {"result", {
                    {"textid", result.textid},
                    {"value", result.value},
                    {"relevance", result.relevance}
                }}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPersonSkillsForAssignment(PARAMS(NPCSeed person,UniverseID controllableid,const char* role,const char* postid))
    {
        Skill2 result;
        uint32_t callResult = invoke(GetPersonSkillsForAssignment, &result, person, controllableid, role, postid);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
                {"result", {
                    {"textid", result.textid},
                    {"value", result.value},
                    {"relevance", result.relevance}
                }}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPersonSuitableControlPosts(PARAMS(UniverseID controllableid,UniverseID personcontrollableid,NPCSeed person,bool free))
    {
        uint32_t resultlen = 32767;
        std::vector<ControlPostInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetPersonSuitableControlPosts, result.data(), resultlen, controllableid, personcontrollableid, person, free);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"id", v.id},
                    {"name", v.name}
                });
            }
            return json
            {
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPlannedLimitedModules(PARAMS(const char* constructionplanid))
    {
        uint32_t resultlen = 32767;
        std::vector<UIMacroCount> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetPlannedLimitedModules, result.data(), resultlen, constructionplanid);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"macro", v.macro},
                    {"amount", v.amount}
                });
            }
            return json
            {
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPlayerAlertSounds(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<SoundInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetPlayerAlertSounds, result.data(), resultlen);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"id", v.id},
                    {"name", v.name}
                });
            }
            return json
            {
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPlayerAlerts(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<PlayerAlertInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetPlayerAlerts, result.data(), resultlen);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPlayerLogos(PARAMS(bool includestandard,bool includecustom))
    {
        uint32_t resultlen = 32767;
        std::vector<UILogo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetPlayerLogos, result.data(), resultlen, includestandard, includecustom);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPlayerShipBuildTasks(PARAMS(bool isinprogress,bool includeupgrade))
    {
        uint32_t resultlen = 32767;
        std::vector<BuildTaskInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetPlayerShipBuildTasks, result.data(), resultlen, isinprogress, includeupgrade);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetPurchasableCargo(PARAMS(UniverseID containerid,const char* unknownString))
    {
        uint32_t callResult = invoke(GetPurchasableCargo, containerid, unknownString);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetRemovedConstructionPlanModules2(PARAMS())
    {
        uint32_t changedIndices;
        uint32_t numChangedIndices;
        uint32_t resultlen = 32767;
        std::vector<UniverseID> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetRemovedConstructionPlanModules2, result.data(), resultlen, &changedIndices, &numChangedIndices);
         if (callResult) {
            return json
            {
                {"callResult", callResult},
                {"changedIndices", changedIndices},
                {"numChangedIndices", numChangedIndices}
            };
        }
 
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetRemovedStationModules(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<UniverseID> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetRemovedStationModules, result.data(), resultlen);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetRenderTargetAlpha(PARAMS(const int rendertargetid))
    {
        uint32_t callResult = invoke(GetRenderTargetAlpha, rendertargetid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetRepairResources(PARAMS(UniverseID componenttorepairid))
    {
        uint32_t resultlen = 32767;
        std::vector<UIWareInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetRepairResources, result.data(), resultlen, componenttorepairid);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetResearchModules(PARAMS(UniverseID containerid))
    {
        uint32_t resultlen = 32767;
        std::vector<UniverseID> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetResearchModules, result.data(), resultlen, containerid);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetRoleTierNPCs(PARAMS(UniverseID controllableid,const char* role,int32_t skilllevel))
    {
        uint32_t resultlen = 32767;
        std::vector<NPCSeed> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetRoleTierNPCs, result.data(), resultlen, controllableid, role, skilllevel);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetRoleTiers(PARAMS(UniverseID controllableid,const char* role))
    {
        uint32_t resultlen = 32767;
        std::vector<RoleTierData> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetRoleTiers, result.data(), resultlen, controllableid, role);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetSectorsByOwner(PARAMS(const char* factionid))
    {
        uint32_t resultlen = 32767;
        std::vector<UniverseID> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetSectorsByOwner, result.data(), resultlen, factionid);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetShieldGroups(PARAMS(UniverseID defensibleid))
    {
        uint32_t resultlen = 32767;
        std::vector<ShieldGroup> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetShieldGroups, result.data(), resultlen, defensibleid);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetSoftwarePredecessors(PARAMS(const char* softwarename))
    {
        uint32_t resultlen = 32767;
        std::vector<const char*> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetSoftwarePredecessors, result.data(), resultlen, softwarename);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetSoftwareSlots(PARAMS(UniverseID controllableid,const char* macroname))
    {
        uint32_t resultlen = 32767;
        std::vector<SoftwareSlot> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetSoftwareSlots, result.data(), resultlen, controllableid, macroname);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"max", v.max},
                    {"current", v.current}
                });
            }
            return json
            {
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetSoundDevices(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<const char*> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetSoundDevices, result.data(), resultlen);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetStandardButtonOffsetX(PARAMS(const int frameid))
    {
        uint32_t callResult = invoke(GetStandardButtonOffsetX, frameid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetStandardButtonOffsetY(PARAMS(const int frameid))
    {
        uint32_t callResult = invoke(GetStandardButtonOffsetY, frameid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetStationModules(PARAMS(UniverseID stationid,bool includeconstructions,bool includewrecks))
    {
        uint32_t resultlen = 32767;
        std::vector<UniverseID> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetStationModules, result.data(), resultlen, stationid, includeconstructions, includewrecks);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetStationOverviewGraphWares(PARAMS(UniverseID stationid))
    {
        uint32_t resultlen = 32767;
        std::vector<const char*> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetStationOverviewGraphWares, result.data(), resultlen, stationid);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetSuitableControlPosts(PARAMS(UniverseID controllableid,UniverseID entityid,bool free))
    {
        uint32_t resultlen = 32767;
        std::vector<ControlPostInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetSuitableControlPosts, result.data(), resultlen, controllableid, entityid, free);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"id", v.id},
                    {"name", v.name}
                });
            }
            return json
            {
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetSupplyOrders(PARAMS(UniverseID containerid,bool defaultorders))
    {
        uint32_t resultlen = 32767;
        std::vector<SupplyOverride> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetSupplyOrders, result.data(), resultlen, containerid, defaultorders);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"macro", v.macro},
                    {"amount", v.amount}
                });
            }
            return json
            {
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetTableHighlightMode(PARAMS(const int tableid))
    {
        uint32_t callResult = invoke(GetTableHighlightMode, tableid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetTableInitialMultiselectedRows(PARAMS(const int tableid))
    {
        uint32_t resultlen = 32767;
        std::vector<uint32_t> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetTableInitialMultiselectedRows, result.data(), resultlen, tableid);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetTiersOfRole(PARAMS(const char* role))
    {
        uint32_t resultlen = 32767;
        std::vector<RoleTierData> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetTiersOfRole, result.data(), resultlen, role);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetTimeline(PARAMS())
    {
        uint32_t resultlen = 32767;
        std::vector<TimelineInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetTimeline, result.data(), resultlen);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetTradeOfferStatistics(PARAMS(size_t numdatapoints))
    {
        uint32_t resultlen = 32767;
        std::vector<UITradeOfferStat> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetTradeOfferStatistics, result.data(), resultlen, numdatapoints);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetUnitCargo(PARAMS(UniverseID containerid,bool onlydrones))
    {
        uint32_t resultlen = 32767;
        std::vector<UIWareInfo> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetUnitCargo, result.data(), resultlen, containerid, onlydrones);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
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
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetUpgradeGroups(PARAMS(UniverseID destructibleid,const char* macroname))
    {
        uint32_t resultlen = 32767;
        std::vector<UpgradeGroup> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetUpgradeGroups, result.data(), resultlen, destructibleid, macroname);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"path", v.path},
                    {"group", v.group}
                });
            }
            return json
            {
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetUpgradeGroups2(PARAMS(UniverseID destructibleid,const char* macroname))
    {
        uint32_t resultlen = 32767;
        std::vector<UpgradeGroup2> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetUpgradeGroups2, result.data(), resultlen, destructibleid, macroname);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"path", v.path},
                    {"group", v.group}
                });
            }
            return json
            {
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetUsedLimitedModules(PARAMS(UniverseID excludedstationid))
    {
        uint32_t resultlen = 32767;
        std::vector<UIMacroCount> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetUsedLimitedModules, result.data(), resultlen, excludedstationid);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"macro", v.macro},
                    {"amount", v.amount}
                });
            }
            return json
            {
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetUsedLimitedModulesFromSubsequence(PARAMS(UniverseID holomapid,size_t cp_idx))
    {
        uint32_t resultlen = 32767;
        std::vector<UIMacroCount> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetUsedLimitedModulesFromSubsequence, result.data(), resultlen, holomapid, cp_idx);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"macro", v.macro},
                    {"amount", v.amount}
                });
            }
            return json
            {
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetValidTransporterTargets(PARAMS(UniverseID componentid))
    {
        uint32_t resultlen = 32767;
        std::vector<UIComponentSlot> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetValidTransporterTargets, result.data(), resultlen, componentid);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"component", v.component},
                    {"connection", v.connection}
                });
            }
            return json
            {
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetVenturePlatformDocks(PARAMS(UniverseID ventureplatformid))
    {
        uint32_t resultlen = 32767;
        std::vector<UniverseID> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetVenturePlatformDocks, result.data(), resultlen, ventureplatformid);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetVenturePlatforms(PARAMS(UniverseID defensibleid))
    {
        uint32_t resultlen = 32767;
        std::vector<UniverseID> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetVenturePlatforms, result.data(), resultlen, defensibleid);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetWareBlueprintOwners(PARAMS(const char* wareid))
    {
        uint32_t resultlen = 32767;
        std::vector<const char*> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetWareBlueprintOwners, result.data(), resultlen, wareid);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetWareSources(PARAMS(const char* wareid))
    {
        uint32_t resultlen = 32767;
        std::vector<WareSource> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetWareSources, result.data(), resultlen, wareid);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"sourcetype", v.sourcetype},
                    {"sourcelocation", v.sourcelocation}
                });
            }
            return json
            {
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetWares(PARAMS(const char* tags,bool research,const char* licenceownerid,const char* exclusiontags))
    {
        uint32_t resultlen = 32767;
        std::vector<const char*> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetWares, result.data(), resultlen, tags, research, licenceownerid, exclusiontags);
         if (callResult) {
            result.resize(callResult);
            return json
            {
                {"callResult", callResult},
                {"result", result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetWeaponGroupsByWeapon(PARAMS(UniverseID defensibleid,UniverseID weaponid))
    {
        uint32_t resultlen = 32767;
        std::vector<UIWeaponGroup> result;
        result.resize(resultlen);
        uint32_t callResult = invoke(GetWeaponGroupsByWeapon, result.data(), resultlen, defensibleid, weaponid);
         if (callResult) {
            result.resize(callResult);
            std::vector<json> json_result;
            json_result.reserve(callResult);
        	for (const auto& v : result)
            {
                json_result.push_back({
                    {"primary", v.primary},
                    {"idx", v.idx}
                });
            }
            return json
            {
                {"callResult", callResult},
                {"result", json_result}
            };
        }
 
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json PlayDetailmonitorCutscene(PARAMS(uint32_t cutsceneid,const char* rendertarget))
    {
        uint32_t callResult = invoke(PlayDetailmonitorCutscene, cutsceneid, rendertarget);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json PrepareBuildSequenceResources(PARAMS(UniverseID holomapid,UniverseID stationid))
    {
        uint32_t callResult = invoke(PrepareBuildSequenceResources, holomapid, stationid);
        return json
        {
            {"callResult", callResult}
        };
    }
 
    json GetActiveMissionID(PARAMS())
    {
        uint64_t callResult = invoke(GetActiveMissionID);
        return json
        {
            {"callResult", callResult}
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
