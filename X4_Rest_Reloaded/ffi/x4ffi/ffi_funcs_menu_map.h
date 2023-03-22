#pragma once
#include "ffi_typedef.h"
#include "ffi_typedef_struct.h"

// Regex to convert the lua definitions to c++ typedefs
//   \t(.+?)(([0-z])+?)\(
//   using $2 = $1(*)(

namespace X4FFI {

    using AbortBoardingOperation = bool (*)(UniverseID defensibletargetid, const char* boarderfactionid);
    using AbortMission = void (*)(MissionID missionid);
    using AddAttackerToBoardingOperation = bool (*)(UniverseID defensibletargetid, UniverseID defensibleboarderid,
                                                    const char* boarderfactionid, const char* actionid,
                                                    uint32_t* marinetieramounts, int32_t* marinetierskilllevels,
                                                    uint32_t nummarinetiers);
    using AddHoloMap = UniverseID (*)(const char* texturename, float x0, float x1, float y0, float y1, float aspectx,
                                      float aspecty);
    using AddPlayerMoney = void (*)(int64_t money);
    using AddResearch = void (*)(const char* wareid);
    using AddSimilarMapComponentsToSelection = void (*)(UniverseID holomapid, UniverseID componentid);
    using AdjustOrder = bool (*)(UniverseID controllableid, size_t idx, size_t newidx, bool enabled, bool forcestates,
                                 bool checkonly);
    using AreVenturesEnabled = bool (*)(void);
    using AssignHiredActor = const char* (*)(GenericActor actor, UniverseID targetcontrollableid, const char* postid,
                                             const char* roleid, bool checkonly);
    using GetAskToSignalForControllable = bool (*)(const char* signalid, UniverseID controllableid);
    using GetAskToSignalForFaction = bool (*)(const char* signalid, const char* factionid);
    using GetAttackersOfBoardingOperation = uint32_t (*)(UniverseID* result, uint32_t resultlen,
                                                         UniverseID defensibletargetid, const char* boarderfactionid);
    using CanContainerMineTransport = bool (*)(UniverseID containerid, const char* transportname);
    using CanContainerTransport = bool (*)(UniverseID containerid, const char* transportname);
    using CanControllableHaveAnyTrainees = bool (*)(UniverseID controllableid);
    using CanControllableHaveControlEntity = bool (*)(UniverseID controllableid, const char* postid);
    using CanPlayerCommTarget = bool (*)(UniverseID componentid);
    using ChangeMapBuildPlot = void (*)(UniverseID holomapid, float x, float y, float z);
    using CheatDockingTraffic = void (*)(void);
    using CheatLiveStreamViewChannels = void (*)(void);
    using ClearSelectedMapComponents = void (*)(UniverseID holomapid);
    using ClearMapBuildPlot = void (*)(UniverseID holomapid);
    using ClearMapObjectFilter = void (*)(UniverseID holomapid);
    using ClearMapOrderParamObjectFilter = void (*)(UniverseID holomapid);
    using ClearMapTradeFilterByMinTotalVolume = void (*)(UniverseID holomapid);
    using ClearMapTradeFilterByPlayerOffer = void (*)(UniverseID holomapid, bool buysellswitch);
    using ClearMapTradeFilterByWare = void (*)(UniverseID holomapid);
    using ClearMapTradeFilterByWillingToTradeWithPlayer = void (*)(UniverseID holomapid);
    using ConvertInputString = const char* (*)(const char* text, const char* defaultvalue);
    using ConvertStringTo64Bit = uint64_t (*)(const char* idstring);
    using CreateBoardingOperation = bool (*)(UniverseID defensibletargetid, const char* boarderfactionid,
                                             uint32_t approachthreshold, uint32_t insertionthreshold);
    using CreateDeployToStationOrder = uint32_t (*)(UniverseID controllableid);
    using CreateNPCFromPerson = UniverseID (*)(NPCSeed person, UniverseID controllableid);
    using CreateOrder = uint32_t (*)(UniverseID controllableid, const char* orderid, bool defaultValue);
    using CreateOrder3 = uint32_t (*)(UniverseID controllableid, const char* orderid, bool defaultorder,
                                      bool isoverride, bool istemp);
    using DropCargo = bool (*)(UniverseID containerid, const char* wareid, uint32_t amount);
    using EnableAllCheats = void (*)(void);
    using EnableOrder = bool (*)(UniverseID controllableid, size_t idx);
    using EnablePlannedDefaultOrder = bool (*)(UniverseID controllableid, bool checkonly);
    using EndGuidance = void (*)(void);
    using ExtendBuildPlot = bool (*)(UniverseID stationid, Coord3D poschange, Coord3D negchange, bool allowreduction);
    using FilterComponentByText = bool (*)(UniverseID componentid, uint32_t numtexts, const char** textarray,
                                           bool includecontainedobjects);
    using FilterComponentForDefaultOrderParamObjectMode = bool (*)(UniverseID componentid,
                                                                   UniverseID ordercontrollableid, bool planned,
                                                                   size_t paramidx);
    using FilterComponentForMapMode = bool (*)(UniverseID componentid, const char** classes, uint32_t numclasses,
                                               int32_t playerowned, bool allowentitydeliverymissionobject);
    using FilterComponentForOrderParamObjectMode = bool (*)(UniverseID componentid, UniverseID ordercontrollableid,
                                                            size_t orderidx, size_t paramidx);
    using GetActiveMissionID = uint64_t (*)();
    using GetAllBoardingBehaviours = uint32_t (*)(BoardingBehaviour* result, uint32_t resultlen);
    using GetAllBoardingPhases = uint32_t (*)(BoardingPhase* result, uint32_t resultlen);
    using GetAllControlPosts = uint32_t (*)(ControlPostInfo* result, uint32_t resultlen);
    using GetAllCountermeasures = uint32_t (*)(AmmoData* result, uint32_t resultlen, UniverseID defensibleid);
    using GetAllInventoryBombs = uint32_t (*)(AmmoData* result, uint32_t resultlen, UniverseID entityid);
    using GetAllLaserTowers = uint32_t (*)(AmmoData* result, uint32_t resultlen, UniverseID defensibleid);
    using GetAllMines = uint32_t (*)(AmmoData* result, uint32_t resultlen, UniverseID defensibleid);
    using GetAllMissiles = uint32_t (*)(AmmoData* result, uint32_t resultlen, UniverseID defensibleid);
    using GetAllNavBeacons = uint32_t (*)(AmmoData* result, uint32_t resultlen, UniverseID defensibleid);
    using GetAllRaces = uint32_t (*)(RaceInfo* result, uint32_t resultlen);
    using GetAllResourceProbes = uint32_t (*)(AmmoData* result, uint32_t resultlen, UniverseID defensibleid);
    using GetAllSatellites = uint32_t (*)(AmmoData* result, uint32_t resultlen, UniverseID defensibleid);
    using GetAllModuleSets = uint32_t (*)(UIModuleSet* result, uint32_t resultlen);
    using GetAllowedWeaponSystems = uint32_t (*)(WeaponSystemInfo* result, uint32_t resultlen, UniverseID defensibleid,
                                                 size_t orderidx, bool usedefault);
    using GetAllResponsesToSignal = uint32_t (*)(ResponseInfo* result, uint32_t resultlen, const char* signalid);
    using GetAllSignals = uint32_t (*)(SignalInfo* result, uint32_t resultlen);
    using GetAllWareGroups = uint32_t (*)(WareGroupInfo* result, uint32_t resultlen);
    using GetBoardingActionOfAttacker = const char* (*)(UniverseID defensibletargetid, UniverseID defensibleboarderid,
                                                        const char* boarderfactionid);
    using GetBoardingCasualtiesOfTier = uint32_t (*)(int32_t marinetierskilllevel, UniverseID defensibletargetid,
                                                     const char* boarderfactionid);
    using GetBoardingMarineTierAmountsFromAttacker =
        bool (*)(uint32_t* resultmarinetieramounts, int32_t* inputmarinetierskilllevels, uint32_t inputnummarinetiers,
                 UniverseID defensibletargetid, UniverseID defensibleboarderid, const char* boarderfactionid);
    using GetBoardingRiskThresholds = BoardingRiskThresholds (*)(UniverseID defensibletargetid,
                                                                 const char* boarderfactionid);
    using GetBoardingStrengthFromOperation = uint32_t (*)(UniverseID defensibletargetid, const char* boarderfactionid);
    using GetBoardingStrengthOfControllableTierAmounts = uint32_t (*)(UniverseID controllableid,
                                                                      uint32_t* marinetieramounts,
                                                                      int32_t* marinetierskilllevels,
                                                                      uint32_t nummarinetiers);
    using GetBuilderHiringFee = int64_t (*)(void);
    using GetBuildMapStationLocation2 = UniverseID (*)(UniverseID holomapid, UIPosRot* location);
    using GetBuildProcessorEstimatedTimeLeft = double (*)(UniverseID buildprocessorid);
    using GetBuildPlotCenterOffset = Coord3D (*)(UniverseID stationid);
    using GetBuildPlotPayment = int64_t (*)(UniverseID stationid, bool* positionchanged);
    using GetBuildPlotPrice = int64_t (*)(UniverseID sectorid, UIPosRot location, float x, float y, float z,
                                          const char* factionid);
    using GetBuildPlotSize = Coord3D (*)(UniverseID stationid);
    using GetBuildTaskDuration = double (*)(UniverseID containerid, BuildTaskID id);
    using GetBuildTasks = uint32_t (*)(BuildTaskInfo* result, uint32_t resultlen, UniverseID containerid,
                                       UniverseID buildmoduleid, bool isinprogress, bool includeupgrade);
    using GetCargoTransportTypes = uint32_t (*)(StorageInfo* result, uint32_t resultlen, UniverseID containerid,
                                                bool merge, bool aftertradeorders);
    using GetCenteredMousePos = Coord2D (*)(void);
    using GetCommonContext = UniverseID (*)(UniverseID componentid, UniverseID othercomponentid, bool includeself,
                                            bool includeother, UniverseID limitid, bool includelimit);
    using GetComponentClass = const char* (*)(UniverseID componentid);
    using GetComponentName = const char* (*)(UniverseID componentid);
    using GetConfigSetting = int (*)(const char* const setting);
    using GetContainerBuildMethod = const char* (*)(UniverseID containerid);
    using GetContainerTradeRuleID = TradeRuleID (*)(UniverseID containerid, const char* ruletype, const char* wareid);
    using GetContainerWareReservations2 = uint32_t (*)(WareReservationInfo2* result, uint32_t resultlen,
                                                       UniverseID containerid, bool includevirtual, bool includemission,
                                                       bool includesupply);
    using GetContextByClass = UniverseID (*)(UniverseID componentid, const char* classname, bool includeself);
    using GetContextByRealClass = UniverseID (*)(UniverseID componentid, const char* classname, bool includeself);
    using GetControllableBlacklistID = BlacklistID (*)(UniverseID controllableid, const char* listtype,
                                                       const char* defaultgroup);
    using GetControllableFightRuleID = FightRuleID (*)(UniverseID controllableid, const char* listtype);
    using GetCurrentAmmoOfWeapon = const char* (*)(UniverseID weaponid);
    using GetCurrentBoardingPhase = const char* (*)(UniverseID defensibletargetid, const char* boarderfactionid);
    using GetCurrentBuildProgress = float (*)(UniverseID containerid);
    using GetCurrentDroneMode = const char* (*)(UniverseID defensibleid, const char* dronetype);
    using GetCurrentFleetLogo = UILogo (*)(UniverseID controllableid);
    using GetCurrentMissionOffers = uint32_t (*)(uint64_t* result, uint32_t resultlen, bool showninbbs);
    using GetCurrentPlayerLogo = UILogo (*)(void);
    using GetCurrentUTCDataTime = int64_t (*)(void);
    using GetDefaultOrder = bool (*)(Order* result, UniverseID controllableid);
    using GetDefaultOrderFailure = bool (*)(OrderFailure* result, UniverseID controllableid);
    using GetDefaultResponseToSignalForControllable = const char* (*)(const char* signalid, UniverseID controllableid);
    using GetDefaultResponseToSignalForFaction = const char* (*)(const char* signalid, const char* factionid);
    using GetDefensibleActiveWeaponGroup = uint32_t (*)(UniverseID defensibleid, bool primary);
    using GetDefensibleDPS = uint32_t (*)(DPSData* result, UniverseID defensibleid, bool primary, bool secondary,
                                          bool lasers, bool missiles, bool turrets, bool includeheat,
                                          bool includeinactive);
    using GetDefensibleDeployableCapacity = uint32_t (*)(UniverseID defensibleid);
    using GetDefensibleLoadoutLevel = float (*)(UniverseID defensibleid);
    using GetDiscoveredSectorResources = uint32_t (*)(WareYield* result, uint32_t resultlen, UniverseID sectorid);
    using GetDockedShips = uint32_t (*)(UniverseID* result, uint32_t resultlen, UniverseID dockingbayorcontainerid,
                                        const char* factionid);
    using GetDroneModes = uint32_t (*)(DroneModeInfo* result, uint32_t resultlen, UniverseID defensibleid,
                                       const char* dronetype);
    using GetEntityCombinedSkill = int32_t (*)(UniverseID entityid, const char* role, const char* postid);
    using GetFactionDetails = FactionDetails (*)(const char* factionid);
    using GetFleetName = const char* (*)(UniverseID controllableid);
    using GetFormationShapes = uint32_t (*)(UIFormationInfo* result, uint32_t resultlen);
    using GetFreeCountermeasureStorageAfterTradeOrders = uint32_t (*)(UniverseID defensibleid);
    using GetFreeDeployableStorageAfterTradeOrders = uint32_t (*)(UniverseID defensibleid);
    using GetFreeMissileStorageAfterTradeOrders = uint32_t (*)(UniverseID defensibleid);
    using GetFreePeopleCapacity = uint32_t (*)(UniverseID controllableid);
    using GetIllegalToFactions = uint32_t (*)(const char** result, uint32_t resultlen, const char* wareid);
    using GetInstantiatedPerson = UniverseID (*)(NPCSeed person, UniverseID controllableid);
    using GetMapComponentMissions = uint32_t (*)(MissionID* result, uint32_t resultlen, UniverseID holomapid,
                                                 UniverseID componentid);
    using GetMapFocusComponent = UniverseID (*)(UniverseID holomapid);
    using GetMapPositionOnEcliptic2 = UniverseID (*)(UniverseID holomapid, UIPosRot* position, bool adaptiveecliptic,
                                                     UniverseID eclipticsectorid, UIPosRot eclipticoffset);
    using GetMapRenderedComponents = uint32_t (*)(UniverseID* result, uint32_t resultlen, UniverseID holomapid);
    using GetMapSelectedComponents = uint32_t (*)(UniverseID* result, uint32_t resultlen, UniverseID holomapid);
    using GetMapState = void (*)(UniverseID holomapid, HoloMapState* state);
    using GetMapTradeVolumeParameter = UIMapTradeVolumeParameter (*)(void);
    using GetMaxProductionStorage = uint32_t (*)(UIWareAmount* result, uint32_t resultlen, UniverseID containerid);
    using GetMineablesAtSectorPos = uint32_t (*)(YieldInfo* result, uint32_t resultlen, UniverseID sectorid,
                                                 Coord3D position);
    using GetMinimumBuildPlotCenterOffset = Coord3D (*)(UniverseID stationid);
    using GetMinimumBuildPlotSize = Coord3D (*)(UniverseID stationid);
    using GetMissionBriefingIcon = MissionBriefingIconInfo (*)(MissionID missionid);
    using GetMissionDeliveryWares = void (*)(MissionWareDeliveryInfo* result, MissionID missionid);
    using GetMissionGroupDetails = MissionGroupDetails (*)(MissionID missionid);
    using GetMissionHelpOverlayID = const char* (*)(MissionID missionid);
    using GetMissionIDObjective2 = MissionObjective2 (*)(uint64_t missionid);
    using GetMissionIDDetails = MissionDetails (*)(uint64_t missionid);
    using GetMissionObjectiveStep3 = MissionObjectiveStep3 (*)(uint64_t missionid, size_t objectiveIndex);
    using GetMissionOnlineInfo = OnlineMissionInfo (*)(MissionID missionid);
    using GetMissionThreadSubMissions = uint32_t (*)(MissionID* result, uint32_t resultlen, MissionID missionid);
    using GetNumAllBoardingBehaviours = uint32_t (*)(void);
    using GetNumAllBoardingPhases = uint32_t (*)(void);
    using GetNumAllControlPosts = uint32_t (*)(void);
    using GetNumAllCountermeasures = uint32_t (*)(UniverseID defensibleid);
    using GetNumAllInventoryBombs = uint32_t (*)(UniverseID entityid);
    using GetNumAllLaserTowers = uint32_t (*)(UniverseID defensibleid);
    using GetNumAllMines = uint32_t (*)(UniverseID defensibleid);
    using GetNumAllMissiles = uint32_t (*)(UniverseID defensibleid);
    using GetNumAllNavBeacons = uint32_t (*)(UniverseID defensibleid);
    using GetNumAllResourceProbes = uint32_t (*)(UniverseID defensibleid);
    using GetNumAllSatellites = uint32_t (*)(UniverseID defensibleid);
    using GetNumAllModuleSets = uint32_t (*)();
    using GetNumAllowedWeaponSystems = uint32_t (*)(void);
    using GetNumAllRaces = uint32_t (*)(void);
    using GetNumAllResponsesToSignal = uint32_t (*)(const char* signalid);
    using GetNumAllRoles = uint32_t (*)(void);
    using GetNumAllSignals = uint32_t (*)(void);
    using GetNumAllWareGroups = uint32_t (*)(void);
    using GetNumAttackersOfBoardingOperation = uint32_t (*)(UniverseID defensibletargetid,
                                                            const char* boarderfactionid);
    using GetNumBoardingMarinesFromOperation = uint32_t (*)(UniverseID defensibletargetid,
                                                            const char* boarderfactionid);
    using GetNumBuildTasks = uint32_t (*)(UniverseID containerid, UniverseID buildmoduleid, bool isinprogress,
                                          bool includeupgrade);
    using GetNumCargoTransportTypes = uint32_t (*)(UniverseID containerid, bool merge);
    using GetNumContainerWareReservations2 = uint32_t (*)(UniverseID containerid, bool includevirtual,
                                                          bool includemission, bool includesupply);
    using GetNumCurrentMissionOffers = uint32_t (*)(bool showninbbs);
    using GetNumDiscoveredSectorResources = uint32_t (*)(UniverseID sectorid);
    using GetNumDockedShips = uint32_t (*)(UniverseID dockingbayorcontainerid, const char* factionid);
    using GetNumDroneModes = uint32_t (*)(UniverseID defensibleid, const char* dronetype);
    using GetNumFormationShapes = uint32_t (*)(void);
    using GetNumIllegalToFactions = uint32_t (*)(const char* wareid);
    using GetNumMapComponentMissions = uint32_t (*)(UniverseID holomapid, UniverseID componentid);
    using GetNumMapRenderedComponents = uint32_t (*)(UniverseID holomapid);
    using GetNumMapSelectedComponents = uint32_t (*)(UniverseID holomapid);
    using GetNumMaxProductionStorage = uint32_t (*)(UniverseID containerid);
    using GetNumMineablesAtSectorPos = uint32_t (*)(UniverseID sectorid, Coord3D position);
    using GetNumMissionDeliveryWares = uint32_t (*)(MissionID missionid);
    using GetNumMissionThreadSubMissions = uint32_t (*)(MissionID missionid);
    using GetNumObjectsWithSyncPoint = uint32_t (*)(uint32_t syncid, bool onlyreached);
    using GetNumOrderDefinitions = uint32_t (*)(void);
    using GetNumOrderFailures = uint32_t (*)(UniverseID controllableid, bool includelooporders);
    using GetNumOrderLocationData = uint32_t (*)(UniverseID controllableid, size_t orderidx, bool usedefault);
    using GetNumOrders = uint32_t (*)(UniverseID controllableid);
    using GetNumPeopleAfterOrders = uint32_t (*)(UniverseID controllableid, int32_t numorders);
    using GetNumPersonSuitableControlPosts = uint32_t (*)(UniverseID controllableid, UniverseID personcontrollableid,
                                                          NPCSeed person, bool free);
    using GetNumPlannedStationModules = size_t (*)(UniverseID defensibleid, bool includeall);
    using GetNumPlayerBuildMethods = uint32_t (*)(void);
    using GetNumPlayerLogos = uint32_t (*)(bool includestandard, bool includecustom);
    using GetNumPlayerShipBuildTasks = uint32_t (*)(bool isinprogress, bool includeupgrade);
    using GetNumRequestedMissionNPCs = uint32_t (*)(UniverseID containerid);
    using GetNumSkills = uint32_t (*)(void);
    using GetNumShieldGroups = uint32_t (*)(UniverseID defensibleid);
    using GetNumSoftwareSlots = uint32_t (*)(UniverseID controllableid, const char* macroname);
    using GetNumStationModules = uint32_t (*)(UniverseID stationid, bool includeconstructions, bool includewrecks);
    using GetNumStoredUnits = uint32_t (*)(UniverseID defensibleid, const char* cat, bool virtualammo);
    using GetNumSubordinatesOfGroup = uint32_t (*)(UniverseID commanderid, int group);
    using GetNumSuitableControlPosts = uint32_t (*)(UniverseID controllableid, UniverseID entityid, bool free);
    using GetNumTiersOfRole = uint32_t (*)(const char* role);
    using GetNumTradeComputerOrders = size_t (*)(UniverseID controllableid);
    using GetNumUpgradeGroups = uint32_t (*)(UniverseID destructibleid, const char* macroname);
    using GetNumUpgradeSlots = size_t (*)(UniverseID destructibleid, const char* macroname,
                                          const char* upgradetypename);
    using GetNumVirtualUpgradeSlots = size_t (*)(UniverseID objectid, const char* macroname,
                                                 const char* upgradetypename);
    using GetNumWareBlueprintOwners = uint32_t (*)(const char* wareid);
    using GetNumWares = uint32_t (*)(const char* tags, bool research, const char* licenceownerid,
                                     const char* exclusiontags);
    using GetNumWeaponGroupsByWeapon = uint32_t (*)(UniverseID defensibleid, UniverseID weaponid);
    using GetObjectIDCode = const char* (*)(UniverseID objectid);
    using GetObjectPositionInSector = UIPosRot (*)(UniverseID objectid);
    using GetOrderDefinition = bool (*)(OrderDefinition* result, const char* orderdef);
    using GetOrderDefinitions = uint32_t (*)(OrderDefinition* result, uint32_t resultlen);
    using GetOrderFailures = uint32_t (*)(OrderFailure* result, uint32_t resultlen, UniverseID controllableid,
                                          bool includelooporders);
    using GetOrderID = AIOrderID (*)(UniverseID controllableid, size_t orderidx);
    using GetOrderLocationData = uint32_t (*)(UniverseID* result, uint32_t resultlen, UniverseID controllableid,
                                              size_t orderidx, bool usedefault);
    using GetOrderLoopSkillLimit = uint32_t (*)();
    using GetOrderQueueCurrentIdx = size_t (*)(UniverseID controllableid);
    using GetOrderQueueFirstLoopIdx = size_t (*)(UniverseID controllableid, bool* isvalid);
    using GetOrders = uint32_t (*)(Order* result, uint32_t resultlen, UniverseID controllableid);
    using GetOrders2 = uint32_t (*)(Order2* result, uint32_t resultlen, UniverseID controllableid);
    using GetOwnerDetails = FactionDetails (*)(UniverseID componentid);
    using GetPaidBuildPlotCenterOffset = Coord3D (*)(UniverseID stationid);
    using GetPaidBuildPlotSize = Coord3D (*)(UniverseID stationid);
    using GetParentComponent = UniverseID (*)(UniverseID componentid);
    using GetPeople2 = uint32_t (*)(PeopleInfo* result, uint32_t resultlen, UniverseID controllableid,
                                    bool includearriving);
    using GetPeopleAfterOrders = uint32_t (*)(NPCInfo* result, uint32_t resultlen, UniverseID controllableid,
                                              int32_t numorders);
    using GetPeopleCapacity = uint32_t (*)(UniverseID controllableid, const char* macroname, bool includecrew);
    using GetPersonCombinedSkill = int32_t (*)(UniverseID controllableid, NPCSeed person, const char* role,
                                               const char* postid);
    using GetPersonName = const char* (*)(NPCSeed person, UniverseID controllableid);
    using GetPersonRole = const char* (*)(NPCSeed person, UniverseID controllableid);
    using GetPersonSkills3 = uint32_t (*)(SkillInfo* result, uint32_t resultlen, NPCSeed person,
                                          UniverseID controllableid);
    using GetPersonSkillsForAssignment = uint32_t (*)(Skill2* result, NPCSeed person, UniverseID controllableid,
                                                      const char* role, const char* postid);
    using GetPersonSuitableControlPosts = uint32_t (*)(ControlPostInfo* result, uint32_t resultlen,
                                                       UniverseID controllableid, UniverseID personcontrollableid,
                                                       NPCSeed person, bool free);
    using GetPersonTier = int32_t (*)(NPCSeed npc, const char* role, UniverseID controllableid);
    using GetPickedMapComponent = UniverseID (*)(UniverseID holomapid);
    using GetPickedMapInterSectorDefence = SubordinateGroup (*)(UniverseID holomapid);
    using GetPickedMapMission = MissionID (*)(UniverseID holomapid);
    using GetPickedMapMissionOffer = UniverseID (*)(UniverseID holomapid);
    using GetPickedMapOrder = UniverseID (*)(UniverseID holomapid, Order* result, bool* intermediate);
    using GetPickedMapSyncPoint = uint32_t (*)(UniverseID holomapid);
    using GetPickedMapSyncPointOwningOrder = UniverseID (*)(UniverseID holomapid, Order* result);
    using GetPickedMapTradeOffer = TradeID (*)(UniverseID holomapid);
    using GetPickedMultiverseMapPlayer = MultiverseMapPickInfo (*)(UniverseID holomapid);
    using GetPlannedDefaultOrder = bool (*)(Order* result, UniverseID controllableid);
    using GetPlannedStationModules = size_t (*)(UIConstructionPlanEntry* result, uint32_t resultlen,
                                                UniverseID defensibleid, bool includeall);
    using GetPlayerBuildMethod = const char* (*)(void);
    using GetPlayerBuildMethods = uint32_t (*)(ProductionMethodInfo* result, uint32_t resultlen);
    using GetPlayerComputerID = UniverseID (*)(void);
    using GetPlayerContainerID = UniverseID (*)(void);
    using GetPlayerControlledShipID = UniverseID (*)(void);
    using GetPlayerGlobalLoadoutLevel = float (*)(void);
    using GetPlayerID = UniverseID (*)(void);
    using GetPlayerLogos = uint32_t (*)(UILogo* result, uint32_t resultlen, bool includestandard, bool includecustom);
    using GetPlayerObjectID = UniverseID (*)(void);
    using GetPlayerOccupiedShipID = UniverseID (*)(void);
    using GetPlayerShipBuildTasks = uint32_t (*)(BuildTaskInfo* result, uint32_t resultlen, bool isinprogress,
                                                 bool includeupgrade);
    using GetPlayerGlobalTradeLoopCargoReservationSetting = bool (*)(void);
    using GetPlayerTargetOffset = UIPosRot (*)(void);
    using GetRealComponentClass = const char* (*)(UniverseID componentid);
    using GetRequestedMissionNPCs = uint32_t (*)(MissionNPCInfo* result, uint32_t resultlen, UniverseID containerid);
    using GetRoleTierNPCs = uint32_t (*)(NPCSeed* result, uint32_t resultlen, UniverseID controllableid,
                                         const char* role, int32_t skilllevel);
    using GetRoleTiers = uint32_t (*)(RoleTierData* result, uint32_t resultlen, UniverseID controllableid,
                                      const char* role);
    using GetRoleTiers2 = uint32_t (*)(RoleTierData* result, uint32_t resultlen, UniverseID controllableid,
                                       const char* role, bool includearriving);
    using GetSectorControlStation = UniverseID (*)(UniverseID sectorid);
    using GetSectorPopulation = uint64_t (*)(UniverseID sectorid);
    using GetShieldGroups = uint32_t (*)(ShieldGroup* result, uint32_t resultlen, UniverseID defensibleid);
    using GetShipCombinedSkill = int32_t (*)(UniverseID shipid);
    using GetShipTradeLoopCargoReservationSetting = bool (*)(UniverseID shipid);
    using GetSofttarget = SofttargetDetails (*)(void);
    using GetSoftwareSlots = uint32_t (*)(SoftwareSlot* result, uint32_t resultlen, UniverseID controllableid,
                                          const char* macroname);
    using GetStationModules = uint32_t (*)(UniverseID* result, uint32_t resultlen, UniverseID stationid,
                                           bool includeconstructions, bool includewrecks);
    using GetSubordinateGroupAssignment = const char* (*)(UniverseID controllableid, int group);
    using GetSubordinateGroupProtectedPosition = UIPosRot (*)(UniverseID controllableid, int group);
    using GetSubordinateGroupProtectedSector = UniverseID (*)(UniverseID controllableid, int group);
    using GetSubordinatesOfGroup = uint32_t (*)(UniverseID* result, uint32_t resultlen, UniverseID commanderid,
                                                int group);
    using GetSuitableControlPosts = uint32_t (*)(ControlPostInfo* result, uint32_t resultlen, UniverseID controllableid,
                                                 UniverseID entityid, bool free);
    using GetSyncPointAutoRelease = bool (*)(uint32_t syncid, bool checkall);
    using GetSyncPointAutoReleaseFromOrder = bool (*)(UniverseID controllableid, size_t orderidx, bool checkall);
    using GetSyncPointInfo2 = bool (*)(UniverseID controllableid, size_t orderidx, SyncPointInfo2* result);
    using GetTextHeight = float (*)(const char* const text, const char* const fontname, const float fontsize,
                                    const float wordwrapwidth);
    using GetTiersOfRole = uint32_t (*)(RoleTierData* result, uint32_t resultlen, const char* role);
    using GetTopLevelContainer = UniverseID (*)(UniverseID componentid);
    using GetTradeWareBudget = int64_t (*)(UniverseID containerid);
    using GetTurretGroupMode2 = const char* (*)(UniverseID defensibleid, UniverseID contextid, const char* path,
                                                const char* group);
    using GetUpgradeGroupInfo2 = UpgradeGroupInfo (*)(UniverseID destructibleid, const char* macroname,
                                                      UniverseID contextid, const char* path, const char* group,
                                                      const char* upgradetypename);
    using GetUpgradeGroups2 = uint32_t (*)(UpgradeGroup2* result, uint32_t resultlen, UniverseID destructibleid,
                                           const char* macroname);
    using GetUpgradeSlotCurrentComponent = UniverseID (*)(UniverseID destructibleid, const char* upgradetypename,
                                                          size_t slot);
    using GetUpgradeSlotGroup = UpgradeGroup (*)(UniverseID destructibleid, const char* macroname,
                                                 const char* upgradetypename, size_t slot);
    using GetVirtualUpgradeSlotCurrentMacro = const char* (*)(UniverseID defensibleid, const char* upgradetypename,
                                                              size_t slot);
    using GetWareBlueprintOwners = uint32_t (*)(const char** result, uint32_t resultlen, const char* wareid);
    using GetWareReservationsForWare = uint32_t (*)(UniverseID containerid, const char* wareid, bool buy);
    using GetWares = uint32_t (*)(const char** result, uint32_t resultlen, const char* tags, bool research,
                                  const char* licenceownerid, const char* exclusiontags);
    using GetWeaponGroupsByWeapon = uint32_t (*)(UIWeaponGroup* result, uint32_t resultlen, UniverseID defensibleid,
                                                 UniverseID weaponid);
    using GetWeaponMode = const char* (*)(UniverseID weaponid);
    using GetWorkForceInfo = WorkForceInfo (*)(UniverseID containerid, const char* raceid);
    using GetZoneAt = UniverseID (*)(UniverseID sectorid, UIPosRot* uioffset);
    using HasAcceptedOnlineMission = bool (*)(void);
    using HasContainerOwnTradeRule = bool (*)(UniverseID containerid, const char* ruletype, const char* wareid);
    using HasControllableAnyOrderFailures = bool (*)(UniverseID controllableid);
    using HasControllableOwnBlacklist = bool (*)(UniverseID controllableid, const char* listtype);
    using HasControllableOwnFightRule = bool (*)(UniverseID controllableid, const char* listtype);
    using HasControllableOwnResponse = bool (*)(UniverseID controllableid, const char* signalid);
    using HasPersonArrived = bool (*)(UniverseID controllableid, NPCSeed person);
    using HasShipTradeLoopCargoReservationOverride = bool (*)(UniverseID shipid);
    using HasSubordinateAssignment = bool (*)(UniverseID controllableid, const char* assignment);
    using IsAmmoMacroCompatible = bool (*)(const char* weaponmacroname, const char* ammomacroname);
    using IsBuilderBusy = bool (*)(UniverseID shipid);
    using IsComponentBlacklisted = bool (*)(UniverseID componentid, const char* listtype, const char* defaultgroup,
                                            UniverseID controllableid);
    using IsComponentClass = bool (*)(UniverseID componentid, const char* classname);
    using IsComponentOperational = bool (*)(UniverseID componentid);
    using IsComponentWrecked = bool (*)(UniverseID componentid);
    using IsContainerTradingWithFactionRescricted = bool (*)(UniverseID containerid, const char* factionid);
    using IsContestedSector = bool (*)(UniverseID sectorid);
    using IsControlPressed = bool (*)(void);
    using IsCurrentBuildMapPlotPositionDiscovered = bool (*)(UniverseID sectorid, UIPosRot location, float x, float y,
                                                             float z);
    using IsCurrentBuildMapPlotValid = bool (*)(UniverseID holomapid);
    using IsCurrentOrderCritical = bool (*)(UniverseID controllableid);
    using IsDefensibleBeingBoardedBy = bool (*)(UniverseID defensibleid, const char* factionid);
    using IsDroneTypeArmed = bool (*)(UniverseID defensibleid, const char* dronetype);
    using IsDroneTypeBlocked = bool (*)(UniverseID defensibleid, const char* dronetype);
    using IsExternalTargetMode = bool (*)();
    using IsExternalViewActive = bool (*)();
    using IsFactionHQ = bool (*)(UniverseID stationid);
    using IsIconValid = bool (*)(const char* iconid);
    using IsInfoUnlockedForPlayer = bool (*)(UniverseID componentid, const char* infostring);
    using IsKnownToPlayer = bool (*)(UniverseID componentid);
    using IsMasterVersion = bool (*)(void);
    using IsMissionLimitReached = bool (*)(bool includeupkeep, bool includeguidance, bool includeplot);
    using IsObjectKnown = bool (*)(const UniverseID componentid);
    using IsOrderLoopable = bool (*)(const char* orderdefid);
    using IsOrderSelectableFor = bool (*)(const char* orderdefid, UniverseID controllableid);
    using IsPerson = bool (*)(NPCSeed person, UniverseID controllableid);
    using IsPersonTransferScheduled = bool (*)(UniverseID controllableid, NPCSeed person);
    using IsPlayerCameraTargetViewPossible = bool (*)(UniverseID targetid, bool force);
    using IsRealComponentClass = bool (*)(UniverseID componentid, const char* classname);
    using IsShiftPressed = bool (*)(void);
    using IsShipAtExternalDock = bool (*)(UniverseID shipid);
    using IsStoryFeatureUnlocked = bool (*)(const char* featureid);
    using IsTurretGroupArmed = bool (*)(UniverseID defensibleid, UniverseID contextid, const char* path,
                                        const char* group);
    using IsUICoverOverridden = bool (*)(void);
    using IsUnit = bool (*)(UniverseID controllableid);
    using IsWeaponArmed = bool (*)(UniverseID weaponid);
    using LaunchLaserTower = void (*)(UniverseID defensibleid, const char* lasertowermacroname);
    using LaunchMine = void (*)(UniverseID defensibleid, const char* minemacroname);
    using LaunchNavBeacon = void (*)(UniverseID defensibleid, const char* navbeaconmacroname);
    using LaunchResourceProbe = void (*)(UniverseID defensibleid, const char* resourceprobemacroname);
    using LaunchSatellite = void (*)(UniverseID defensibleid, const char* satellitemacroname);
    using PayBuildPlotSize = void (*)(UniverseID stationid, Coord3D plotsize, Coord3D plotcenter);
    using PerformCrewExchange2 = UICrewExchangeResult (*)(UniverseID controllableid, UniverseID partnercontrollableid,
                                                          NPCSeed* npcs, uint32_t numnpcs, NPCSeed* partnernpcs,
                                                          uint32_t numpartnernpcs, NPCSeed captainfromcontainer,
                                                          NPCSeed captainfrompartner, bool exchangecaptains,
                                                          bool checkonly);
    using ReassignPeople = void (*)(UniverseID controllableid, CrewTransferContainer* reassignedcrew, uint32_t amount);
    using ReleasePersonFromCrewTransfer = void (*)(UniverseID controllableid, NPCSeed person);
    using ReleaseOrderSyncPoint = void (*)(uint32_t syncid);
    using ReleaseOrderSyncPointFromOrder = void (*)(UniverseID controllableid, size_t idx);
    using RemoveAllOrders = bool (*)(UniverseID controllableid);
    using RemoveAttackerFromBoardingOperation = bool (*)(UniverseID defensibleboarderid);
    using RemoveBuildPlot = bool (*)(UniverseID stationid);
    using RemoveCommander2 = bool (*)(UniverseID controllableid);
    using RemoveDefaultOrderFailure = void (*)(UniverseID controllableid);
    using RemoveHoloMap = void (*)(void);
    using RemoveOrder = bool (*)(UniverseID controllableid, size_t idx, bool playercancelled, bool checkonly);
    using RemoveOrderFailure = void (*)(UniverseID controllableid, uint32_t id);
    using RemoveOrderSyncPointID = void (*)(UniverseID controllableid, size_t orderidx);
    using RemovePerson = void (*)(UniverseID controllableid, NPCSeed person);
    using RemovePlannedDefaultOrder = void (*)(UniverseID controllableid);
    using RemoveShipTradeLoopCargoReservationOverride = void (*)(UniverseID shipid);
    using ReserveBuildPlot = UniverseID (*)(UniverseID sectorid, const char* factionid, const char* set,
                                            UIPosRot location, float x, float y, float z);
    using ResetOrderLoop = void (*)(UniverseID controllableid);
    using ResetResponseToSignalForControllable = bool (*)(const char* signalid, UniverseID controllableid);
    using RevealEncyclopedia = void (*)(void);
    using RevealMap = void (*)(void);
    using RevealStations = void (*)(void);
    using SetActiveMission = bool (*)(MissionID missionid);
    using SelectSimilarMapComponents = void (*)(UniverseID holomapid, UniverseID componentid);
    using SellPlayerShip = void (*)(UniverseID shipid, UniverseID shipyardid);
    using SetAllMissileTurretModes = void (*)(UniverseID defensibleid, const char* mode);
    using SetAllMissileTurretsArmed = void (*)(UniverseID defensibleid, bool arm);
    using SetAllNonMissileTurretModes = void (*)(UniverseID defensibleid, const char* mode);
    using SetAllNonMissileTurretsArmed = void (*)(UniverseID defensibleid, bool arm);
    using SetAllowedWeaponSystems = void (*)(UniverseID defensibleid, size_t orderidx, bool usedefault,
                                             WeaponSystemInfo* uiweaponsysteminfo, uint32_t numuiweaponsysteminfo);
    using SetAllTurretModes = void (*)(UniverseID defensibleid, const char* mode);
    using SetAllTurretsArmed = void (*)(UniverseID defensibleid, bool arm);
    using SetAmmoOfWeapon = bool (*)(UniverseID weaponid, const char* newammomacro);
    using SetCheckBoxChecked2 = void (*)(const int checkboxid, bool checked, bool update);
    using SetCommander = bool (*)(UniverseID controllableid, UniverseID commanderid, const char* assignment);
    using SetConfigSetting = void (*)(const char* const setting, const bool value);
    using SetContainerBuildMethod = void (*)(UniverseID containerid, const char* buildmethodid);
    using SetContainerTradeRule = void (*)(UniverseID containerid, TradeRuleID id, const char* ruletype,
                                           const char* wareid, bool value);
    using SetControllableBlacklist = void (*)(UniverseID controllableid, BlacklistID id, const char* listtype,
                                              bool value);
    using SetControllableFightRule = void (*)(UniverseID controllableid, FightRuleID id, const char* listtype,
                                              bool value);
    using SetDefaultResponseToSignalForControllable = bool (*)(const char* newresponse, bool ask, const char* signalid,
                                                               UniverseID controllableid);
    using SetDefaultResponseToSignalForFaction = bool (*)(const char* newresponse, bool ask, const char* signalid,
                                                          const char* factionid);
    using SetDefensibleActiveWeaponGroup = void (*)(UniverseID defensibleid, bool primary, uint32_t groupidx);
    using SetDefensibleLoadoutLevel = void (*)(UniverseID defensibleid, float value);
    using SetDroneMode = void (*)(UniverseID defensibleid, const char* dronetype, const char* mode);
    using SetDroneTypeArmed = void (*)(UniverseID defensibleid, const char* dronetype, bool arm);
    using SetEditBoxText = void (*)(const int editboxid, const char* text);
    using SetFleetLogo = void (*)(UniverseID controllableid, UILogo logo);
    using SetFleetName = void (*)(UniverseID controllableid, const char* fleetname);
    using SetFocusMapComponent = void (*)(UniverseID holomapid, UniverseID componentid, bool resetplayerpan);
    using SetFocusMapOrder = void (*)(UniverseID holomapid, UniverseID controllableid, size_t orderidx,
                                      bool resetplayerpan);
    using SetFormationShape = UIFormationInfo (*)(UniverseID objectid, const char* formationshape);
    using SetEntityToPost = bool (*)(UniverseID controllableid, UniverseID entityid, const char* postid);
    using SetGuidance = void (*)(UniverseID componentid, UIPosRot offset);
    using SetMapDefaultOrderParamObjectFilter = void (*)(UniverseID holomapid, UniverseID ordercontrollableid,
                                                         bool planned, size_t paramidx);
    using SetMapFactionRelationColorOption = void (*)(UniverseID holomapid, bool value);
    using SetMapFilterString = void (*)(UniverseID holomapid, uint32_t numtexts, const char** textarray);
    using SetMapObjectFilter = void (*)(UniverseID holomapid, const char** classes, uint32_t numclasses,
                                        int32_t playerowned, bool allowentitydeliverymissionobject);
    using SetMapOrderParamObjectFilter = void (*)(UniverseID holomapid, UniverseID ordercontrollableid, size_t orderidx,
                                                  size_t paramidx);
    using SetMapPanOffset = void (*)(UniverseID holomapid, UniverseID offsetcomponentid);
    using SetMapPicking = void (*)(UniverseID holomapid, bool enable);
    using SetMapRelativeMousePosition = void (*)(UniverseID holomapid, bool valid, float x, float y);
    using SetMapRenderAllAllyOrderQueues = void (*)(UniverseID holomapid, bool value);
    using SetMapRenderAllGateConnections = void (*)(UniverseID holomapid, bool value);
    using SetMapRenderAllOrderQueues = void (*)(UniverseID holomapid, bool value);
    using SetMapRenderCivilianShips = void (*)(UniverseID holomapid, bool value);
    using SetMapRenderEclipticLines = void (*)(UniverseID holomapid, bool value);
    using SetMapRenderMissionGuidance = void (*)(UniverseID holomapid, MissionID missionid);
    using SetMapRenderMissionOffers = void (*)(UniverseID holomapid, bool value);
    using SetMapRenderResourceInfo = void (*)(UniverseID holomapid, bool value);
    using SetMapRenderSatelliteRadarRange = void (*)(UniverseID holomapid, bool value);
    using SetMapRenderSelectionLines = void (*)(UniverseID holomapid, bool value);
    using SetMapRenderTradeOffers = void (*)(UniverseID holomapid, bool value);
    using SetMapRenderWrecks = void (*)(UniverseID holomapid, bool value);
    using SetMapSelectedFleetCommander = void (*)(UniverseID holomapid, UniverseID controllableid);
    using SetMapState = void (*)(UniverseID holomapid, HoloMapState state);
    using SetMapStationInfoBoxMargin = void (*)(UniverseID holomapid, const char* margin, uint32_t width);
    using SetMapTargetDistance = void (*)(UniverseID holomapid, float distance);
    using SetMapTopTradesCount = void (*)(UniverseID holomapid, uint32_t count);
    using SetMapTradeFilterByMaxPrice = void (*)(UniverseID holomapid, int64_t price);
    using SetMapTradeFilterByMinTotalVolume = void (*)(UniverseID holomapid, uint32_t minvolume);
    using SetMapTradeFilterByPlayerOffer = void (*)(UniverseID holomapid, bool buysellswitch, bool enable);
    using SetMapTradeFilterByWare = void (*)(UniverseID holomapid, const char** wareids, uint32_t numwareids);
    using SetMapTradeFilterByWareTransport = void (*)(UniverseID holomapid, const char** transporttypes,
                                                      uint32_t numtransporttypes);
    using SetMapTradeFilterByWillingToTradeWithPlayer = void (*)(UniverseID holomapid);
    using SetMapAlertFilter = void (*)(UniverseID holomapid, uint32_t alertlevel);
    using SetOrderLoop = bool (*)(UniverseID controllableid, size_t orderidx, bool checkonly);
    using SetOrderSyncPointID = bool (*)(UniverseID controllableid, size_t orderidx, uint32_t syncid, bool checkonly);
    using SetPlayerCameraCockpitView = void (*)(bool force);
    using SetPlayerCameraTargetView = void (*)(UniverseID targetid, bool force);
    using SetSelectedMapComponent = void (*)(UniverseID holomapid, UniverseID componentid);
    using SetSelectedMapComponents = void (*)(UniverseID holomapid, UniverseID* componentids, uint32_t numcomponentids);
    using SetShipTradeLoopCargoReservationOverride = void (*)(UniverseID shipid, bool value);
    using SetSofttarget = bool (*)(UniverseID componentid, const char* const connectionname);
    using SetSubordinateGroupDockAtCommander = void (*)(UniverseID controllableid, int group, bool value);
    using SetSubordinateGroupProtectedLocation = void (*)(UniverseID controllableid, int group, UniverseID sectorid,
                                                          UIPosRot offset);
    using SetSyncPointAutoRelease = void (*)(uint32_t syncid, bool all, bool any);
    using SetSyncPointAutoReleaseFromOrder = void (*)(UniverseID controllableid, size_t orderidx, bool all, bool any);
    using SetTrackedMenuFullscreen = void (*)(const char* menu, bool fullscreen);
    using SetTurretGroupArmed = void (*)(UniverseID defensibleid, UniverseID contextid, const char* path,
                                         const char* group, bool arm);
    using SetTurretGroupMode2 = void (*)(UniverseID defensibleid, UniverseID contextid, const char* path,
                                         const char* group, const char* mode);
    using SetUICoverOverride = void (*)(bool override);
    using SetWeaponArmed = void (*)(UniverseID weaponid, bool arm);
    using SetWeaponGroup = void (*)(UniverseID defensibleid, UniverseID weaponid, bool primary, uint32_t groupidx,
                                    bool value);
    using SetWeaponMode = void (*)(UniverseID weaponid, const char* mode);
    using ShouldSubordinateGroupDockAtCommander = bool (*)(UniverseID controllableid, int group);
    using ShowBuildPlotPlacementMap = void (*)(UniverseID holomapid, UniverseID sectorid);
    using ShowMultiverseMap = void (*)(UniverseID holomapid);
    using ShowUniverseMap2 = void (*)(UniverseID holomapid, bool setoffset, bool showzone, bool forcebuildershipicons,
                                      UniverseID startsectorid, UIPosRot startpos);
    using SignalObjectWithNPCSeedAndMissionID = void (*)(UniverseID objecttosignalid, const char* param,
                                                         MissionID missionid, NPCSeed person,
                                                         UniverseID controllableid);
    using StartBoardingOperation = bool (*)(UniverseID defensibletargetid, const char* boarderfactionid);
    using StartPanMap = void (*)(UniverseID holomapid);
    using StartRotateMap = void (*)(UniverseID holomapid);
    using StopPanMap = bool (*)(UniverseID holomapid);
    using StopRotateMap = bool (*)(UniverseID holomapid);
    using ZoomMap = void (*)(UniverseID holomapid, float zoomstep);
    using StartMapBoxSelect = void (*)(UniverseID holomapid, bool selectenemies);
    using StopMapBoxSelect = void (*)(UniverseID holomapid);
    using ToggleAutoPilot = bool (*)(bool checkonly);
    using UpdateAttackerOfBoardingOperation = bool (*)(UniverseID defensibletargetid, UniverseID defensibleboarderid,
                                                       const char* boarderfactionid, const char* actionid,
                                                       uint32_t* marinetieramounts, int32_t* marinetierskilllevels,
                                                       uint32_t nummarinetiers);
    using UpdateBoardingOperation = bool (*)(UniverseID defensibletargetid, const char* boarderfactionid,
                                             uint32_t approachthreshold, uint32_t insertionthreshold);
    using UpdateMapBuildPlot = void (*)(UniverseID holomapid);

} // namespace X4FFI