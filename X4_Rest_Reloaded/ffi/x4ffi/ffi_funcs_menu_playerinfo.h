#pragma once
#include "ffi_typedef.h"
#include "ffi_typedef_struct.h"

// Regex to convert the lua definitions to c++ typedefs
//   \t(.+?)(([0-z])+?)\(
//   using $2 = $1(*)(

namespace X4FFI {

    using AddPlayerAlert2 = void (*)(PlayerAlertInfo2 alert);
    using AreVenturesCompatible = bool (*)(void);
    using CreateBlacklist2 = BlacklistID (*)(BlacklistInfo2 info);
    using CreateFightRule = FightRuleID (*)(FightRuleInfo info);
    using CreateNPCFromPerson = UniverseID (*)(NPCSeed person, UniverseID controllableid);
    using CreateTradeRule = TradeRuleID (*)(TradeRuleInfo info);
    using DropInventory = bool (*)(UniverseID entityid, const char* lockboxid, UIWareAmount* wares, uint32_t numwares);
    using GenerateFactionRelationText = const char* (*)(const char* factionid);
    using GetAllFactionShips = uint32_t (*)(UniverseID* result, uint32_t resultlen, const char* factionid);
    using GetAllFactionStations = uint32_t (*)(UniverseID* result, uint32_t resultlen, const char* factionid);
    using GetAllTradeRules = uint32_t (*)(TradeRuleID* result, uint32_t resultlen);
    using GetAvailableClothingThemes = uint32_t (*)(UIClothingTheme* result, uint32_t resultlen);
    using GetAvailableEquipmentMods = uint32_t (*)(UIEquipmentMod* result, uint32_t resultlen);
    using GetAvailableLockboxes = uint32_t (*)(const char** result, uint32_t resultlen, UniverseID entityid);
    using GetAvailablePaintThemes = uint32_t (*)(UIPaintTheme* result, uint32_t resultlen);
    using GetComponentName = const char* (*)(UniverseID componentid);
    using GetContextByClass = UniverseID (*)(UniverseID componentid, const char* classname, bool includeself);
    using GetCurrentGameTime = double (*)(void);
    using GetCurrentPlayerLogo = UILogo (*)(void);
    using GetEntityCombinedSkill = int32_t (*)(UniverseID entityid, const char* role, const char* postid);
    using GetEntitySkillsForAssignment = uint32_t (*)(
        Skill2* result, UniverseID entityid, const char* role, const char* postid);
    using GetFactionDefaultWeaponMode = const char* (*)(const char* factionid);
    using GetLastPlayerControlledShipID = UniverseID (*)(void);
    using GetMessageInteractPosition = UIPosRot (*)(MessageID messageid);
    using GetMessages = uint32_t (*)(
        MessageInfo* result, uint32_t resultlen, size_t start, size_t count, const char* categoryname);
    using GetNotificationTypes = uint32_t (*)(UINotificationType* result, uint32_t resultlen);
    using GetNumAllFactionShips = uint32_t (*)(const char* factionid);
    using GetNumAllFactionStations = uint32_t (*)(const char* factionid);
    using GetNumAllRoles = uint32_t (*)(void);
    using GetNumAllTradeRules = uint32_t (*)(void);
    using GetNumAvailableClothingThemes = uint32_t (*)();
    using GetNumAvailableEquipmentMods = uint32_t (*)();
    using GetNumAvailableLockboxes = uint32_t (*)(UniverseID entityid);
    using GetNumAvailablePaintThemes = uint32_t (*)();
    using GetNumMessages = uint32_t (*)(const char* categoryname, bool);
    using GetNumNotificationTypes = uint32_t (*)(void);
    using GetNumPlayerAlerts = uint32_t (*)(void);
    using GetNumPlayerAlertSounds2 = uint32_t (*)(const char* tags);
    using GetNumPlayerBuildMethods = uint32_t (*)(void);
    using GetNumPlayerLogos = uint32_t (*)(bool includestandard, bool includecustom);
    using GetNumSkills = uint32_t (*)(void);
    using GetNumStationModules = uint32_t (*)(UniverseID stationid, bool includeconstructions, bool includewrecks);
    using GetNumTransactionLog = uint32_t (*)(UniverseID componentid, double starttime, double endtime);
    using GetPersonCombinedSkill = int32_t (*)(
        UniverseID controllableid, NPCSeed person, const char* role, const char* postid);
    using GetPersonName = const char* (*)(NPCSeed person, UniverseID controllableid);
    using GetPersonRoleName = const char* (*)(NPCSeed person, UniverseID controllableid);
    using GetPersonSkills3 = uint32_t (*)(
        SkillInfo* result, uint32_t resultlen, NPCSeed person, UniverseID controllableid);
    using GetPeople2 = uint32_t (*)(
        PeopleInfo* result, uint32_t resultlen, UniverseID controllableid, bool includearriving);
    using GetPlayerAlertCounts = uint32_t (*)(PlayerAlertCounts* result, uint32_t resultlen);
    using GetPlayerAlerts2 = uint32_t (*)(PlayerAlertInfo2* result, uint32_t resultlen);
    using GetPlayerAlertSounds2 = uint32_t (*)(SoundInfo* result, uint32_t resultlen, const char* tags);
    using GetPlayerBuildMethod = const char* (*)(void);
    using GetPlayerBuildMethods = uint32_t (*)(ProductionMethodInfo* result, uint32_t resultlen);
    using GetPlayerClothingTheme = const char* (*)(void);
    using GetPlayerFactionName = const char* (*)(bool userawname);
    using GetPlayerGlobalLoadoutLevel = float (*)(void);
    using GetPlayerID = UniverseID (*)(void);
    using GetPlayerLogos = uint32_t (*)(UILogo* result, uint32_t resultlen, bool includestandard, bool includecustom);
    using GetPlayerPaintTheme = const char* (*)(void);
    using GetPlayerName = const char* (*)(void);
    using GetPlayerOccupiedShipID = UniverseID (*)(void);
    using GetPlayerGlobalTradeLoopCargoReservationSetting = bool (*)(void);
    using GetPlayerZoneID = UniverseID (*)(void);
    using GetPurposeName = const char* (*)(const char* purposeid);
    using GetRelationRangeUIMaxValue = int32_t (*)(const char* relationrangeid);
    using GetRoleTierNPCs = uint32_t (*)(
        NPCSeed* result, uint32_t resultlen, UniverseID controllableid, const char* role, int32_t skilllevel);
    using GetRoleTiers = uint32_t (*)(
        RoleTierData* result, uint32_t resultlen, UniverseID controllableid, const char* role);
    using GetSupplyBudget = int64_t (*)(UniverseID containerid);
    using GetStationModules = uint32_t (*)(
        UniverseID* result, uint32_t resultlen, UniverseID stationid, bool includeconstructions, bool includewrecks);
    using GetTextHeight = float (*)(
        const char* const text, const char* const fontname, const float fontsize, const float wordwrapwidth);
    using GetTradeRuleInfo = bool (*)(TradeRuleInfo* info, TradeRuleID id);
    using GetTradeRuleInfoCounts = TradeRuleCounts (*)(TradeRuleID id);
    using GetTradeWareBudget = int64_t (*)(UniverseID containerid);
    using HasPersonArrived = bool (*)(UniverseID controllableid, NPCSeed person);
    using IsComponentClass = bool (*)(UniverseID componentid, const char* classname);
    using IsComponentOperational = bool (*)(UniverseID componentid);
    using IsMouseEmulationActive = bool (*)(void);
    using IsPersonTransferScheduled = bool (*)(UniverseID controllableid, NPCSeed person);
    using IsPlayerTradeRuleDefault = bool (*)(TradeRuleID id, const char* ruletype);
    using IsShipAtExternalDock = bool (*)(UniverseID shipid);
    using IsUnit = bool (*)(UniverseID controllableid);
    using MutePlayerAlert = void (*)(size_t index);
    using ReadAllInventoryWares = void (*)(void);
    using ReadInventoryWare = void (*)(const char* wareid);
    using ReleasePersonFromCrewTransfer = void (*)(UniverseID controllableid, NPCSeed person);
    using RemoveBlacklist = void (*)(BlacklistID id);
    using RemoveFightRule = void (*)(FightRuleID id);
    using RemovePerson = void (*)(UniverseID controllableid, NPCSeed person);
    using RemovePlayerAlert = void (*)(size_t index);
    using RemoveTradeRule = void (*)(TradeRuleID id);
    using SetEditBoxText = void (*)(const int editboxid, const char* text);
    using SetFactionBuildMethod = void (*)(const char* factionid, const char* buildmethodid);
    using SetFactionRelationToPlayerFaction = void (*)(const char* factionid, const char* reasonid, float boostvalue);
    using SetFactionDefaultWeaponMode = void (*)(const char* factionid, const char* weaponmode);
    using SetGuidance = void (*)(UniverseID componentid, UIPosRot offset);
    using SetMessageRead = void (*)(MessageID messageid, const char* categoryname);
    using SetNotificationTypeEnabled = void (*)(const char* id, bool value);
    using SetPlayerBlacklistDefault = void (*)(
        BlacklistID id, const char* listtype, const char* defaultgroup, bool value);
    using SetPlayerClothingTheme = void (*)(const char* theme);
    using SetPlayerFactionName = void (*)(const char* name);
    using SetPlayerFightRuleDefault = void (*)(FightRuleID id, const char* listtype, bool value);
    using SetPlayerGlobalLoadoutLevel = void (*)(float value);
    using SetPlayerIllegalWare = void (*)(const char* wareid, bool illegal);
    using SetPlayerLogo = void (*)(UILogo logo);
    using SetPlayerPaintTheme = void (*)(const char* theme);
    using SetPlayerShipsWaitForPlayer = void (*)(bool value);
    using SetPlayerTaxiWaitsForPlayer = void (*)(bool value);
    using SetPlayerTradeLoopCargoReservationSetting = void (*)(bool value);
    using SetPlayerTradeRuleDefault = void (*)(TradeRuleID id, const char* ruletype, bool value);
    using ShouldPlayerShipsWaitForPlayer = bool (*)(void);
    using ShouldPlayerTaxiWaitForPlayer = bool (*)(void);
    using SignalObjectWithNPCSeed = void (*)(
        UniverseID objecttosignalid, const char* param, NPCSeed person, UniverseID controllableid);
    using UnmutePlayerAlert = void (*)(size_t index, bool silent);
    using UpdateBlacklist2 = void (*)(BlacklistInfo2 info);
    using UpdateFightRule = void (*)(FightRuleInfo info);
    using UpdatePlayerAlert2 = void (*)(PlayerAlertInfo2 uialert);
    using UpdateTradeRule = void (*)(TradeRuleInfo info);

} // namespace X4FFI