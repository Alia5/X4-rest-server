#pragma once
#include "ffi_typedef.h"
#include "ffi_typedef_struct.h"

// Regex to convert the lua definitions to c++ typedefs
//   \t(.+?)(([0-z])+?)\(
//   using $2 = $1(*)(

namespace X4FFI {
    using AddFloatingSequenceToConstructionPlan = void (*)(UniverseID holomapid);
    using AddCopyToConstructionMap = void (*)(
        UniverseID holomapid, size_t cp_idx, bool copysequence);
    using AddMacroToConstructionMap = void (*)(
        UniverseID holomapid, const char* macroname, bool startdragging);
    using AreConstructionPlanLoadoutsCompatible = bool (*)(const char* constructionplanid);
    using CanBuildLoadout = bool (*)(UniverseID containerid, UniverseID defensibleid,
        const char* macroname, const char* loadoutid);
    using CanOpenWebBrowser = bool (*)(void);
    using CheckConstructionPlanForMacros = bool (*)(
        const char* constructionplanid, const char** macroids, uint32_t nummacroids);
    using ClearBuildMapSelection = void (*)(UniverseID holomapid);
    using CompareMapConstructionSequenceWithPlanned = bool (*)(
        UniverseID holomapid, UniverseID defensibleid, bool usestoredplan);
    using ConvertInputString = const char* (*)(const char* text, const char* defaultvalue);
    using DeselectMacroForConstructionMap = void (*)(UniverseID holomapid);
    using DoesConstructionSequenceRequireBuilder = bool (*)(UniverseID containerid);
    using ExportMapConstructionPlan = void (*)(UniverseID holomapid, const char* filename,
        const char* id, bool overwrite, const char* name, const char* desc);
    using ForceBuildCompletion = void (*)(UniverseID containerid);
    using GenerateModuleLoadout = void (*)(UILoadout* result, UniverseID holomapid,
        size_t cp_idx, UniverseID defensibleid, float level);
    using GenerateModuleLoadoutCounts = void (*)(UILoadoutCounts* result, UniverseID holomapid,
        size_t cp_idx, UniverseID defensibleid, float level);
    using GetAssignedConstructionVessels = uint32_t (*)(
        UniverseID* result, uint32_t resultlen, UniverseID containerid);
    using GetBlueprints = uint32_t (*)(UIBlueprint* result, uint32_t resultlen, const char* set,
        const char* category, const char* macroname);
    using GetBuildMapConstructionPlan = size_t (*)(UniverseID holomapid,
        UniverseID defensibleid, bool usestoredplan, UIConstructionPlanEntry* result,
        uint32_t resultlen);
    using GetBuildProcessorEstimatedTimeLeft = double (*)(UniverseID buildprocessorid);
    using GetCargo = uint32_t (*)(
        UIWareInfo* result, uint32_t resultlen, UniverseID containerid, const char* tags);
    using GetConstructionPlanInvalidPatches = uint32_t (*)(
        InvalidPatchInfo* result, uint32_t resultlen, const char* constructionplanid);
    using GetConstructionPlans = uint32_t (*)(UIConstructionPlan* result, uint32_t resultlen);
    using GetConstructionMapItemLoadout2 = void (*)(UILoadout* result, UniverseID holomapid,
        size_t itemidx, UniverseID defensibleid, UniverseID moduleid);
    using GetConstructionMapItemLoadoutCounts2 = void (*)(UILoadoutCounts* result,
        UniverseID holomapid, size_t itemidx, UniverseID defensibleid, UniverseID moduleid);
    using GetConstructionMapVenturePlatform = size_t (*)(
        UniverseID holomapid, size_t venturedockidx);
    using GetContainerGlobalPriceFactor = float (*)(UniverseID containerid);
    using GetContainerTradeRuleID = TradeRuleID (*)(
        UniverseID containerid, const char* ruletype, const char* wareid);
    using GetContainerWareReservations2 = uint32_t (*)(WareReservationInfo2* result,
        uint32_t resultlen, UniverseID containerid, bool includevirtual, bool includemission,
        bool includesupply);
    using GetContextByClass = UniverseID (*)(
        UniverseID componentid, const char* classname, bool includeself);
    using GetCurrentBuildProgress = float (*)(UniverseID containerid);
    using GetCurrentLoadout = void (*)(
        UILoadout* result, UniverseID defensibleid, UniverseID moduleid);
    using GetCurrentLoadoutCounts = void (*)(
        UILoadoutCounts* result, UniverseID defensibleid, UniverseID moduleid);
    using GetDefensibleLoadoutLevel = float (*)(UniverseID defensibleid);
    using GetGameStartName = const char* (*)();
    using GetImportableConstructionPlans = uint32_t (*)(
        UIConstructionPlanInfo* result, uint32_t resultlen);
    using GetLoadout = void (*)(UILoadout* result, UniverseID defensibleid,
        const char* macroname, const char* loadoutid);
    using GetLoadoutCounts = uint32_t (*)(UILoadoutCounts* result, UniverseID defensibleid,
        const char* macroname, const char* loadoutid);
    using GetLoadoutInvalidPatches = uint32_t (*)(InvalidPatchInfo* result, uint32_t resultlen,
        UniverseID defensibleid, const char* macroname, const char* loadoutid);
    using GetLoadoutsInfo = uint32_t (*)(UILoadoutInfo* result, uint32_t resultlen,
        UniverseID componentid, const char* macroname);
    using GetMissingConstructionPlanBlueprints3 = const char* (*)(UniverseID containerid,
        UniverseID holomapid, const char* constructionplanid, bool useplanned);
    using GetNumAssignedConstructionVessels = uint32_t (*)(UniverseID containerid);
    using GetNumBlueprints = uint32_t (*)(
        const char* set, const char* category, const char* macroname);
    using GetNumBuildMapConstructionPlan = size_t (*)(UniverseID holomapid, bool usestoredplan);
    using GetNumCargo = uint32_t (*)(UniverseID containerid, const char* tags);
    using GetNumConstructionMapVenturePlatformDocks = uint32_t (*)(
        UniverseID holomapid, size_t ventureplatformidx);
    using GetNumConstructionPlans = uint32_t (*)(void);
    using GetNumContainerWareReservations2 = uint32_t (*)(
        UniverseID containerid, bool includevirtual, bool includemission, bool includesupply);
    using GetNumImportableConstructionPlans = uint32_t (*)();
    using GetNumLoadoutsInfo = uint32_t (*)(UniverseID componentid, const char* macroname);
    using GetNumPlannedLimitedModules = uint32_t (*)(const char* constructionplanid);
    using GetNumRemovedConstructionPlanModules2 = uint32_t (*)(UniverseID holomapid,
        UniverseID defensibleid, uint32_t* newIndex, bool usestoredplan,
        uint32_t* numChangedIndices, bool checkupgrades);
    using GetNumUpgradeGroupCompatibilities = uint32_t (*)(UniverseID destructibleid,
        const char* macroname, UniverseID contextid, const char* path, const char* group,
        const char* upgradetypename);
    using GetNumUpgradeGroups = uint32_t (*)(UniverseID destructibleid, const char* macroname);
    using GetNumUpgradeSlots = size_t (*)(
        UniverseID destructibleid, const char* macroname, const char* upgradetypename);
    using GetNumUsedLimitedModules = uint32_t (*)(UniverseID excludedstationid);
    using GetNumUsedLimitedModulesFromSubsequence = uint32_t (*)(
        UniverseID holomapid, size_t cp_idx);
    using GetNumWares = uint32_t (*)(
        const char* tags, bool research, const char* licenceownerid, const char* exclusiontags);
    using GetObjectIDCode = const char* (*)(UniverseID objectid);
    using GetPickedBuildMapEntry2 = bool (*)(UniverseID holomapid, UniverseID defensibleid,
        UIConstructionPlanEntry* result, bool requirecomponentid);
    using SelectPickedBuildMapEntry = void (*)(UniverseID holomapid);
    using GetPickedMapMacroSlot = bool (*)(UniverseID holomapid, UniverseID defensibleid,
        UniverseID moduleid, const char* macroname, bool ismodule, UILoadoutSlot* result);
    using GetPlannedLimitedModules = uint32_t (*)(
        UIMacroCount* result, uint32_t resultlen, const char* constructionplanid);
    using GetRemovedConstructionPlanModules2 = uint32_t (*)(UniverseID* result,
        uint32_t resultlen, uint32_t* changedIndices, uint32_t* numChangedIndices);
    using GetSelectedBuildMapEntry = size_t (*)(UniverseID holomapid);
    using GetUpgradeGroupCompatibilities = uint32_t (*)(EquipmentCompatibilityInfo* result,
        uint32_t resultlen, UniverseID destructibleid, const char* macroname,
        UniverseID contextid, const char* path, const char* group, const char* upgradetypename);
    using GetUpgradeGroupInfo = UpgradeGroupInfo (*)(UniverseID destructibleid,
        const char* macroname, const char* path, const char* group,
        const char* upgradetypename);
    using GetUpgradeGroups = uint32_t (*)(UpgradeGroup* result, uint32_t resultlen,
        UniverseID destructibleid, const char* macroname);
    using GetUpgradeSlotCurrentMacro = const char* (*)(UniverseID objectid, UniverseID moduleid,
        const char* upgradetypename, size_t slot);
    using GetUpgradeSlotGroup = UpgradeGroup (*)(UniverseID destructibleid,
        const char* macroname, const char* upgradetypename, size_t slot);
    using GetUsedLimitedModules = uint32_t (*)(
        UIMacroCount* result, uint32_t resultlen, UniverseID excludedstationid);
    using GetUsedLimitedModulesFromSubsequence = uint32_t (*)(
        UIMacroCount* result, uint32_t resultlen, UniverseID holomapid, size_t cp_idx);
    using GetWares = uint32_t (*)(const char** result, uint32_t resultlen, const char* tags,
        bool research, const char* licenceownerid, const char* exclusiontags);
    using GetWorkForceInfo = WorkForceInfo (*)(UniverseID containerid, const char* raceid);
    using HasContainerOwnTradeRule = bool (*)(
        UniverseID containerid, const char* ruletype, const char* wareid);
    using ImportMapConstructionPlan = void (*)(const char* filename, const char* id);
    using IsBuildWaitingForSecondaryComponentResources = bool (*)(UniverseID containerid);
    using IsConstructionPlanValid = bool (*)(
        const char* constructionplanid, uint32_t* numinvalidpatches);
    using IsLoadoutCompatible = bool (*)(const char* macroname, const char* loadoutid);
    using IsLoadoutValid = bool (*)(UniverseID defensibleid, const char* macroname,
        const char* loadoutid, uint32_t* numinvalidpatches);
    using IsIconValid = bool (*)(const char* iconid);
    using IsMasterVersion = bool (*)(void);
    using IsNextStartAnimationSkipped = bool (*)(bool reset);
    using IsPlayerTradeRuleDefault = bool (*)(TradeRuleID id, const char* ruletype);
    using IsUpgradeGroupMacroCompatible = bool (*)(UniverseID destructibleid,
        const char* macroname, const char* path, const char* group, const char* upgradetypename,
        const char* upgrademacroname);
    using IsUpgradeMacroCompatible = bool (*)(UniverseID objectid, UniverseID moduleid,
        const char* macroname, bool ismodule, const char* upgradetypename, size_t slot,
        const char* upgrademacroname);
    using IsVentureVersion = bool (*)(void);
    using OpenWebBrowser = void (*)(const char* url);
    using ReleaseConstructionMapState = void (*)(void);
    using RemoveConstructionPlan = bool (*)(const char* source, const char* id);
    using RemoveFloatingSequenceFromConstructionPlan = void (*)(UniverseID holomapid);
    using RemoveItemFromConstructionMap2 = void (*)(
        UniverseID holomapid, size_t itemidx, bool removesequence);
    using RemoveOrder2 = bool (*)(UniverseID controllableid, size_t idx, bool playercancelled,
        bool checkonly, bool onlyimmediate);
    using ResetConstructionMapModuleRotation = void (*)(UniverseID holomapid, size_t cp_idx);
    using ResetMapPlayerRotation = void (*)(UniverseID holomapid);
    using SaveLoadout = void (*)(const char* macroname, UILoadout uiloadout, const char* source,
        const char* id, bool overwrite, const char* name, const char* desc);
    using SaveMapConstructionPlan = void (*)(UniverseID holomapid, const char* source,
        const char* id, bool overwrite, const char* name, const char* desc);
    using SelectBuildMapEntry = void (*)(UniverseID holomapid, size_t cp_idx);
    using SetConstructionMapBuildAngleStep = void (*)(UniverseID holomapid, float angle);
    using SetConstructionMapCollisionDetection = void (*)(UniverseID holomapid, bool value);
    using SetConstructionMapRenderSectorBackground = void (*)(UniverseID holomapid, bool value);
    using SetConstructionSequenceFromConstructionMap = void (*)(
        UniverseID containerid, UniverseID holomapid);
    using SetContainerGlobalPriceFactor = void (*)(UniverseID containerid, float value);
    using SetContainerTradeRule = void (*)(UniverseID containerid, TradeRuleID id,
        const char* ruletype, const char* wareid, bool value);
    using SetFocusMapConstructionPlanEntry = void (*)(
        UniverseID holomapid, size_t cp_idx, bool resetplayerpan);
    using SetMapPicking = void (*)(UniverseID holomapid, bool enable);
    using SetSelectedMapGroup = void (*)(UniverseID holomapid, UniverseID destructibleid,
        const char* macroname, const char* path, const char* group);
    using SetSelectedMapMacroSlot = void (*)(UniverseID holomapid, UniverseID defensibleid,
        UniverseID moduleid, const char* macroname, bool ismodule, const char* upgradetypename,
        size_t slot);
    using SetupConstructionSequenceModulesCache = void (*)(
        UniverseID holomapid, UniverseID defensibleid, bool enable);
    using ShowConstructionMap = void (*)(UniverseID holomapid, UniverseID stationid,
        const char* constructionplanid, bool restore);
    using ShowObjectConfigurationMap2 = void (*)(UniverseID holomapid, UniverseID defensibleid,
        UniverseID moduleid, const char* macroname, bool ismodule, UILoadout uiloadout,
        size_t cp_idx);
    using ShuffleMapConstructionPlan = bool (*)(UniverseID holomapid, bool checkonly);
    using StartPanMap = void (*)(UniverseID holomapid);
    using StartRotateMap = void (*)(UniverseID holomapid);
    using StopPanMap = bool (*)(UniverseID holomapid);
    using StopRotateMap = bool (*)(UniverseID holomapid);
    using StoreConstructionMapState = void (*)(UniverseID holomapid);
    using UpdateConstructionMapItemLoadout = void (*)(
        UniverseID holomapid, size_t itemidx, UniverseID defensibleid, UILoadout uiloadout);
    using UpdateObjectConfigurationMap = void (*)(UniverseID holomapid, UniverseID defensibleid,
        UniverseID moduleid, const char* macroname, bool ismodule, UILoadout uiloadout);
    using ZoomMap = void (*)(UniverseID holomapid, float zoomstep);
    using CanUndoConstructionMapChange = bool (*)(UniverseID holomapid);
    using UndoConstructionMapChange = void (*)(UniverseID holomapid);
    using CanRedoConstructionMapChange = bool (*)(UniverseID holomapid);
    using RedoConstructionMapChange = void (*)(UniverseID holomapid);

    using PrepareBuildSequenceResources2 = uint32_t (*)(
        UniverseID holomapid, UniverseID stationid, bool useplanned);
    using GetBuildSequenceResources = uint32_t (*)(UIWareInfo* result, uint32_t resultlen);
    using GetNumModuleRecycledResources = uint32_t (*)(UniverseID moduleid);
    using GetModuleRecycledResources = uint32_t (*)(
        UIWareInfo* result, uint32_t resultlen, UniverseID moduleid);
    using GetNumModuleNeededResources = uint32_t (*)(UniverseID holomapid, size_t cp_idx);
    using GetModuleNeededResources = uint32_t (*)(
        UIWareInfo* result, uint32_t resultlen, UniverseID holomapid, size_t cp_idx);
    using SetContainerBuildMethod = void (*)(UniverseID containerid, const char* buildmethodid);
}