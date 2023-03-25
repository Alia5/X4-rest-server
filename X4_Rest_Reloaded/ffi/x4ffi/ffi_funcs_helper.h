#pragma once
#include "ffi_typedef.h"
#include "ffi_typedef_struct.h"

// Regex to convert the lua definitions to c++ typedefs
//   \t(.+?)(([0-z])+?)\(
//   using $2 = $1(*)(

namespace X4FFI {
    using AddTradeWare = void (*)(UniverseID containerid, const char* wareid);
    using AreVenturesEnabled = bool (*)(void);
    using CancelPlayerInvolvedTradeDeal = bool (*)(
        UniverseID containerid, TradeID tradeid, bool checkonly);
    using CanResearch = bool (*)(void);
    using ClearContainerBuyLimitOverride = void (*)(UniverseID containerid, const char* wareid);
    using ClearContainerSellLimitOverride = void (*)(
        UniverseID containerid, const char* wareid);
    using ClearTrackedMenus = void (*)(void);
    using DisableAutoMouseEmulation = void (*)(void);
    using EnableAutoMouseEmulation = void (*)(void);
    using GetAllBlacklists = uint32_t (*)(BlacklistID* result, uint32_t resultlen);
    using GetAllEquipmentModProperties = uint32_t (*)(
        EquipmentModPropertyInfo* result, uint32_t resultlen, const char* equipmentmodclass);
    using GetAllFightRules = uint32_t (*)(FightRuleID* result, uint32_t resultlen);
    using GetAllTradeRules = uint32_t (*)(TradeRuleID* result, uint32_t resultlen);
    using GetBlacklistInfoCounts = BlacklistCounts (*)(BlacklistID id);
    using GetBlacklistInfo2 = bool (*)(BlacklistInfo2* info, BlacklistID id);
    using GetCargoTransportTypes = uint32_t (*)(StorageInfo* result, uint32_t resultlen,
        UniverseID containerid, bool merge, bool aftertradeorders);
    using GetComponentName = const char* (*)(UniverseID componentid);
    using GetContainerBuyLimit = int32_t (*)(UniverseID containerid, const char* wareid);
    using GetContainerSellLimit = int32_t (*)(UniverseID containerid, const char* wareid);
    using GetContainerStockLimitOverrides = uint32_t (*)(
        UIWareInfo* result, uint32_t resultlen, UniverseID containerid);
    using GetContainerTradeRuleID = TradeRuleID (*)(
        UniverseID containerid, const char* ruletype, const char* wareid);
    using GetContainerWareConsumption = double (*)(
        UniverseID containerid, const char* wareid, bool ignorestate);
    using GetContainerWareIsBuyable = bool (*)(UniverseID containerid, const char* wareid);
    using GetContainerWareIsSellable = bool (*)(UniverseID containerid, const char* wareid);
    using GetContainerWareMaxProductionStorageForTime = int32_t (*)(
        UniverseID containerid, const char* wareid, double duration, bool ignoreoverrides);
    using GetContainerWareProduction = double (*)(
        UniverseID containerid, const char* wareid, bool ignorestate);
    using GetContainerWareReservations2 = uint32_t (*)(WareReservationInfo2* result,
        uint32_t resultlen, UniverseID containerid, bool includevirtual, bool includemission,
        bool includesupply);
    using GetContextByClass = UniverseID (*)(
        UniverseID componentid, const char* classname, bool includeself);
    using GetCreditsDueFromPlayerBuilds = int64_t (*)(void);
    using GetCreditsDueFromPlayerTrades = int64_t (*)(void);
    using GetCurrentGameTime = double (*)(void);
    using GetCurrentUTCDataTime = int64_t (*)(void);
    using GetCurrentVentureInfo = UIVentureInfo (*)(UniverseID ventureplatformid);
    using GetCurrentVentureShips = uint32_t (*)(
        UniverseID* result, uint32_t resultlen, UniverseID ventureplatformid);
    using GetDockedShips = uint32_t (*)(UniverseID* result, uint32_t resultlen,
        UniverseID dockingbayorcontainerid, const char* factionid);
    using GetFightRuleInfo = bool (*)(FightRuleInfo* info, FightRuleID id);
    using GetFightRuleInfoCounts = FightRuleCounts (*)(FightRuleID id);
    using GetInstalledEngineMod = bool (*)(UniverseID objectid, UIEngineMod* enginemod);
    using GetInstalledGroupedWeaponMod = bool (*)(UniverseID defensibleid, UniverseID contextid,
        const char* group, UIWeaponMod* weaponmod);
    using GetInstalledShieldMod = bool (*)(UniverseID defensibleid, UniverseID contextid,
        const char* group, UIShieldMod* shieldmod);
    using GetInstalledShipMod2 = bool (*)(UniverseID shipid, UIShipMod2* shipmod);
    using GetInstalledWeaponMod = bool (*)(UniverseID weaponid, UIWeaponMod* weaponmod);
    using GetMappedInputName = const char* (*)(const char* functionkey);
    using GetMoneyLog = uint32_t (*)(MoneyLogEntry* result, size_t resultlen,
        UniverseID componentid, double starttime, double endtime);
    using GetNumAllBlacklists = uint32_t (*)(void);
    using GetNumAllEquipmentModProperties = uint32_t (*)(const char* equipmentmodclass);
    using GetNumAllFightRules = uint32_t (*)(void);
    using GetNumAllTradeRules = uint32_t (*)(void);
    using GetNumCargoTransportTypes = uint32_t (*)(UniverseID containerid, bool merge);
    using GetNumContainerStockLimitOverrides = uint32_t (*)(UniverseID containerid);
    using GetNumContainerWareReservations2 = uint32_t (*)(
        UniverseID containerid, bool includevirtual, bool includemission, bool includesupply);
    using GetNumDockedShips = uint32_t (*)(
        UniverseID dockingbayorcontainerid, const char* factionid);
    using GetNumTerraformingProjects = uint32_t (*)(UniverseID clusterid, bool useevents);
    using GetNumTransactionLog = uint32_t (*)(
        UniverseID componentid, double starttime, double endtime);
    using GetNumVenturePlatformDocks = uint32_t (*)(UniverseID ventureplatformid);
    using GetNumVenturePlatforms = uint32_t (*)(UniverseID defensibleid);
    using GetObjectIDCode = const char* (*)(UniverseID objectid);
    using GetObjectPositionInSector = UIPosRot (*)(UniverseID objectid);
    using GetPlayerCoverFaction = const char* (*)(void);
    using GetPlayerCurrentControlGroup = const char* (*)(void);
    using GetPlayerID = UniverseID (*)(void);
    using GetPlayerName = const char* (*)(void);
    using GetPlayerOccupiedShipID = UniverseID (*)(void);
    using GetTerraformingProjectBlockingProjects = uint32_t (*)(
        const char** result, uint32_t resultlen, UniverseID clusterid, const char* projectid);
    using GetTerraformingProjectConditions = uint32_t (*)(
        UITerraformingProjectCondition* result, uint32_t resultlen, UniverseID clusterid,
        const char* projectid);
    using GetTerraformingProjectEffects = uint32_t (*)(UITerraformingProjectEffect* result,
        uint32_t resultlen, UniverseID clusterid, const char* projectid);
    using GetTerraformingProjectPredecessorGroups = uint32_t (*)(
        UITerraformingProjectPredecessorGroup* result, uint32_t resultlen, UniverseID clusterid,
        const char* projectid);
    using GetTerraformingProjectPredecessors = uint32_t (*)(
        const char** result, uint32_t resultlen, UniverseID clusterid, const char* projectid);
    using GetTerraformingProjectRebatedResources = uint32_t (*)(
        UIWareInfo* result, uint32_t resultlen, UniverseID clusterid, const char* projectid);
    using GetTerraformingProjectRebates = uint32_t (*)(UITerraformingProjectRebate* result,
        uint32_t resultlen, UniverseID clusterid, const char* projectid);
    using GetTerraformingProjectRemovedProjects = uint32_t (*)(
        const char** result, uint32_t resultlen, UniverseID clusterid, const char* projectid);
    using GetTextHeight = float (*)(const char* const text, const char* const fontname,
        const float fontsize, const float wordwrapwidth);
    using GetTextWidth = float (*)(
        const char* const text, const char* const fontname, const float fontsize);
    using GetTransactionLog = uint32_t (*)(TransactionLogEntry* result, uint32_t resultlen,
        UniverseID componentid, double starttime, double endtime);
    using GetTopLevelContainer = UniverseID (*)(UniverseID componentid);
    using GetTradeRuleInfo = bool (*)(TradeRuleInfo* info, TradeRuleID id);
    using GetTradeRuleInfoCounts = TradeRuleCounts (*)(TradeRuleID id);
    using GetUIScale = float (*)(const bool scalewithresolution);
    using GetUpgradeSlotGroup = UpgradeGroup (*)(UniverseID destructibleid,
        const char* macroname, const char* upgradetypename, size_t slot);
    using GetVenturePlatformDocks = uint32_t (*)(
        UniverseID* result, uint32_t resultlen, UniverseID ventureplatformid);
    using GetVenturePlatforms = uint32_t (*)(
        UniverseID* result, uint32_t resultlen, UniverseID defensibleid);
    using GetWorkForceInfo = WorkForceInfo (*)(UniverseID containerid, const char* raceid);
    using HasContainerBuyLimitOverride = bool (*)(UniverseID containerid, const char* wareid);
    using HasContainerOwnTradeRule = bool (*)(
        UniverseID containerid, const char* ruletype, const char* wareid);
    using HasContainerSellLimitOverride = bool (*)(UniverseID containerid, const char* wareid);
    using IsComponentClass = bool (*)(UniverseID componentid, const char* classname);
    using IsComponentOperational = bool (*)(UniverseID componentid);
    using IsConversationActive = bool (*)(void);
    using IsConversationCancelling = bool (*)(void);
    using IsDemoVersion = bool (*)(void);
    using IsInfoUnlockedForPlayer = bool (*)(UniverseID componentid, const char* infostring);
    using IsGameOver = bool (*)(void);
    using IsNextStartAnimationSkipped = bool (*)(bool reset);
    using IsOnlineEnabled = bool (*)(void);
    using IsPlayerBlacklistDefault = bool (*)(
        BlacklistID id, const char* listtype, const char* defaultgroup);
    using IsPlayerFightRuleDefault = bool (*)(FightRuleID id, const char* listtype);
    using IsSetaActive = bool (*)();
    using IsStartmenu = bool (*)();
    using IsTerraformingProjectOngoing = bool (*)(UniverseID clusterid, const char* projectid);
    using IsVRMode = bool (*)(void);
    using IsWeaponModeCompatible = bool (*)(
        UniverseID weaponid, const char* macroname, const char* weaponmodeid);
    using ReleaseConstructionMapState = void (*)(void);
    using ReleaseDetachedSubordinateGroup = void (*)(UniverseID controllableid, int group);
    using RemoveTrackedMenu = void (*)(const char* menu);
    using RemoveTradeWare = void (*)(UniverseID containerid, const char* wareid);
    using SetBoxText = void (*)(const int boxtextid, const char* text);
    using SetBoxTextBoxColor = void (*)(const int boxtextid, Color color);
    using SetBoxTextColor = void (*)(const int boxtextid, Color color);
    using SetButtonActive = void (*)(const int buttonid, bool active);
    using SetButtonHighlightColor = void (*)(const int buttonid, Color color);
    using SetButtonIconColor = void (*)(const int buttonid, Color color);
    using SetButtonIcon2Color = void (*)(const int buttonid, Color color);
    using SetButtonIconID = void (*)(const int buttonid, const char* iconid);
    using SetButtonIcon2ID = void (*)(const int buttonid, const char* iconid);
    using SetButtonTextColor = void (*)(const int buttonid, Color color);
    using SetButtonText2 = void (*)(const int buttonid, const char* text);
    using SetButtonText2Color = void (*)(const int buttonid, Color color);
    using SetCheckBoxChecked2 = void (*)(const int checkboxid, bool checked, bool update);
    using SetCheckBoxColor = void (*)(const int checkboxid, Color color);
    using SetContainerBuyLimitOverride = void (*)(
        UniverseID containerid, const char* wareid, int32_t amount);
    using SetContainerSellLimitOverride = void (*)(
        UniverseID containerid, const char* wareid, int32_t amount);
    using SetContainerTradeRule = void (*)(UniverseID containerid, TradeRuleID id,
        const char* ruletype, const char* wareid, bool value);
    using SetContainerWareIsBuyable = void (*)(
        UniverseID containerid, const char* wareid, bool allowed);
    using SetContainerWareIsSellable = void (*)(
        UniverseID containerid, const char* wareid, bool allowed);
    using SetDropDownCurOption = void (*)(const int dropdownid, const char* id);
    using SetEditBoxActive = void (*)(const int editboxid, bool active);
    using SetEditBoxText = void (*)(const int editboxid, const char* text);
    using SetEditBoxTextHidden = void (*)(const int editboxid, bool hidden);
    using SetFlowChartEdgeColor = void (*)(const int flowchartedgeid, Color color);
    using SetFlowChartNodeCaptionText = void (*)(const int flowchartnodeid, const char* text);
    using SetFlowChartNodeCaptionTextColor = void (*)(const int flowchartnodeid, Color color);
    using SetFlowChartNodeCurValue = void (*)(const int flowchartnodeid, double value);
    using SetFlowchartNodeExpanded = void (*)(
        const int flowchartnodeid, const int frameid, bool expandedabove);
    using SetFlowChartNodeMaxValue = void (*)(const int flowchartnodeid, double value);
    using SetFlowChartNodeOutlineColor = void (*)(const int flowchartnodeid, Color color);
    using SetFlowChartNodeSlider1Value = void (*)(const int flowchartnodeid, double value);
    using SetFlowChartNodeSlider2Value = void (*)(const int flowchartnodeid, double value);
    using SetFlowChartNodeSliderStep = void (*)(const int flowchartnodeid, double step);
    using SetFlowChartNodeStatusBgIcon = void (*)(
        const int flowchartnodeid, const char* iconid);
    using SetFlowChartNodeStatusIcon = void (*)(const int flowchartnodeid, const char* iconid);
    using SetFlowChartNodeStatusIconMouseOverText = void (*)(
        const int flowchartnodeid, const char* mouseovertext);
    using SetFlowChartNodeStatusText = void (*)(const int flowchartnodeid, const char* text);
    using SetFlowChartNodeStatusColor = void (*)(const int flowchartnodeid, Color color);
    using SetIcon = void (*)(const int widgeticonid, const char* iconid);
    using SetIconColor = void (*)(const int widgeticonid, Color color);
    using SetIconText = void (*)(const int widgeticonid, const char* text);
    using SetIconText2 = void (*)(const int widgeticonid, const char* text);
    using SetMouseOverText = void (*)(int widgetid, const char* text);
    using SetShieldHullBarHullPercent = void (*)(const int shieldhullbarid, float hullpercent);
    using SetShieldHullBarShieldPercent = void (*)(
        const int shieldhullbarid, float shieldpercent);
    using SetSliderCellMaxSelectValue = void (*)(const int slidercellid, double value);
    using SetSliderCellMaxValue = void (*)(const int slidercellid, double value);
    using SetSubordinateGroupAssignment = void (*)(
        UniverseID controllableid, int group, const char* assignment);
    using SetSubordinateGroupProtectedLocation = void (*)(
        UniverseID controllableid, int group, UniverseID sectorid, UIPosRot offset);
    using SetStatusBarCurrentValue = void (*)(const int statusbarid, float value);
    using SetStatusBarMaxValue = void (*)(const int statusbarid, float value);
    using SetStatusBarStartValue = void (*)(const int statusbarid, float value);
    using SetTableNextConnectedTable = void (*)(const int tableid, const int nexttableid);
    using SetTablePreviousConnectedTable = void (*)(const int tableid, const int prevtableid);
    using SetTableNextHorizontalConnectedTable = void (*)(
        const int tableid, const int nexttableid);
    using SetTablePreviousHorizontalConnectedTable = void (*)(
        const int tableid, const int prevtableid);
    using SetWidgetViewScheduled = void (*)(bool scheduled);
    using SkipNextStartAnimation = void (*)(void);
    using TrackMenu = void (*)(const char* menu, bool fullscreen);
}