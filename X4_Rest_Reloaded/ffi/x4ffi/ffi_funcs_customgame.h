#pragma once
#include "ffi_typedef.h"
#include "ffi_typedef_struct.h"

// Regex to convert the lua definitions to c++ typedefs
//   \t(.+?)(([0-z])+?)\(
//   using $2 = $1(*)(

namespace X4FFI {
    using AreConstructionPlanLoadoutsCompatible = bool (*)(const char* constructionplanid);
    using CanPlayerUseRace = bool (*)(const char* raceid, const char* postid);
    using ExportCustomGameStart = void (*)(
        const char* filename, const char* id, const char* name);
    using GenerateFactionRelationTextFromRelation = const char* (*)(int32_t uirelation);
    using GetAllFactions = uint32_t (*)(
        const char** result, uint32_t resultlen, bool includehidden);
    using GetAllRaces = uint32_t (*)(RaceInfo* result, uint32_t resultlen);
    // using GetAvailableCustomGameStarts = uint32_t (*)(CustomGameStartInfo* result, uint32_t
    // resultlen, const char* id);
    using GetConstructionPlanInfo = size_t (*)(
        UIConstructionPlanEntry* result, size_t resultlen, const char* constructionplanid);
    // using GetCustomGameStartBlueprintDefaultProperty = uint32_t (*)(CustomGameStartBlueprint*
    // result, uint32_t resultlen, const char* id, const char* propertyid); using
    // GetCustomGameStartBlueprintProperty = uint32_t (*)(CustomGameStartBlueprint* result,
    // uint32_t resultlen, const char* id, const char* propertyid); using
    // GetCustomGameStartBlueprintPropertyState = CustomGameStartBlueprintPropertyState
    // (*)(const char* id, const char* propertyid); using GetCustomGameStartBoolProperty = bool
    // (*)(const char* id, const char* propertyid, CustomGameStartBoolPropertyState* state);
    // using GetCustomGameStartBudget = CustomGameStartBudgetInfo (*)(const char* id, const
    // char* budgetid); using GetCustomGameStartBudgetDetails = uint32_t
    // (*)(CustomGameStartBudgetDetail* result, uint32_t resultlen, const char* id, const char*
    // budgetid); using GetCustomGameStartBudgetGroupInfo = CustomGameStartBudgetGroupInfo
    // (*)(const char* id, const char* budgetgroupid);
    using GetCustomGameStartBudgetGroups = uint32_t (*)(
        const char** result, uint32_t resultlen, const char* id);
    // using GetCustomGameStartEncyclopediaProperty = uint32_t
    // (*)(CustomGameStartEncyclopediaEntry* result, uint32_t resultlen, const char* id, const
    // char* propertyid);
    using GetCustomGameStartEncyclopediaPropertyCounts = uint32_t (*)(
        const char* id, const char* propertyid);
    // using GetCustomGameStartEncyclopediaPropertyState =
    // CustomGameStartEncyclopediaPropertyState (*)(const char* id, const char* propertyid);
    // using GetCustomGameStartInventoryDefaultProperty = uint32_t (*)(CustomGameStartInventory*
    // result, uint32_t resultlen, const char* id, const char* propertyid); using
    // GetCustomGameStartInventoryProperty = uint32_t (*)(CustomGameStartInventory* result,
    // uint32_t resultlen, const char* id, const char* propertyid); using
    // GetCustomGameStartInventoryPropertyState = CustomGameStartInventoryPropertyState
    // (*)(const char* id, const char* propertyid); using
    // GetCustomGameStartKnownDefaultProperty2 = uint32_t (*)(CustomGameStartKnownEntry2*
    // result, uint32_t resultlen, const char* id, const char* propertyid); using
    // GetCustomGameStartKnownProperty2 = uint32_t (*)(CustomGameStartKnownEntry2* result,
    // uint32_t resultlen, const char* id, const char* propertyid); using
    // GetCustomGameStartKnownPropertyBudgetValue2 = bool (*)(const char* id, const char*
    // propertyid, CustomGameStartKnownEntry2* uivalue); using
    // GetCustomGameStartKnownPropertyNumStateDependencies = uint32_t (*)(uint32_t* result,
    // uint32_t resultlen, const char* id, const char* propertyid, CustomGameStartKnownEntry2
    // uivalue); using GetCustomGameStartKnownPropertyNumStateDependencyLists = uint32_t
    // (*)(const char* id, const char* propertyid, CustomGameStartKnownEntry2 uivalue); using
    // GetCustomGameStartKnownPropertyState = CustomGameStartKnownPropertyState (*)(const char*
    // id, const char* propertyid); using GetCustomGameStartKnownPropertyStateDependencies =
    // uint32_t (*)(const char** result, uint32_t resultlen, const char* id, const char*
    // propertyid, CustomGameStartKnownEntry2 uivalue); using GetCustomGameStartContentCounts =
    // CustomGameStartContentCounts (*)(const char* id, const char* filename, const char*
    // gamestartid); using GetCustomGameStartContent = void (*)(CustomGameStartContentData*
    // result, const char* id, const char* filename, const char* gamestartid); using
    // GetCustomGameStartMoneyProperty = int64_t (*)(const char* id, const char* propertyid,
    // CustomGameStartMoneyPropertyState* state);
    using GetCustomGameStartPaintThemes = uint32_t (*)(
        UIPaintTheme* result, uint32_t resultlen, const char* id);
    // using GetCustomGameStartPlayerPropertyCounts = uint32_t
    // (*)(CustomGameStartPlayerPropertyCounts* result, uint32_t resultlen, const char* id,
    // const char* propertyid);
    using GetCustomGameStartPlayerPropertyPeopleValue = int64_t (*)(
        const char* id, const char* propertyid, const char* entryid);
    // using GetCustomGameStartPlayerPropertyPerson = bool (*)(CustomGameStartPersonEntry*
    // result, const char* id, const char* propertyid, const char* entryid); using
    // GetCustomGameStartPlayerPropertyProperty3 = uint32_t (*)(CustomGameStartPlayerProperty3*
    // result, uint32_t resultlen, const char* id, const char* propertyid); using
    // GetCustomGameStartPlayerPropertyPropertyState =
    // CustomGameStartPlayerPropertyPropertyState (*)(const char* id, const char* propertyid);
    using GetCustomGameStartPlayerPropertySector = const char* (*)(const char* id,
        const char* propertyid, const char* entryid);
    using GetCustomGameStartPlayerPropertyValue = int64_t (*)(
        const char* id, const char* propertyid, const char* entryid);
    // using GetCustomGameStartPosRotProperty = UIPosRot (*)(const char* id, const char*
    // propertyid, CustomGameStartPosRotPropertyState* state); using
    // GetCustomGameStartRelationsProperty = uint32_t (*)(CustomGameStartRelationInfo* result,
    // uint32_t resultlen, const char* id, const char* propertyid); using
    // GetCustomGameStartRelationsPropertyBudgetValue = int64_t (*)(const char* id, const char*
    // propertyid, CustomGameStartRelationInfo uivalue);
    using GetCustomGameStartRelationsPropertyCounts = uint32_t (*)(
        const char* id, const char* propertyid);
    // using GetCustomGameStartRelationsPropertyState = CustomGameStartRelationsPropertyState
    // (*)(const char* id, const char* propertyid);
    using GetCustomGameStartResearchProperty = uint32_t (*)(
        const char** result, uint32_t resultlen, const char* id, const char* propertyid);
    using GetCustomGameStartResearchPropertyCounts = uint32_t (*)(
        const char* id, const char* propertyid);
    // using GetCustomGameStartResearchPropertyState = CustomGameStartResearchPropertyState
    // (*)(const char* id, const char* propertyid); using GetCustomGameStartShipPersonValue =
    // int64_t (*)(const char* id, CustomGameStartPersonEntry uivalue); using
    // GetCustomGameStartStoryBudgets = uint32_t (*)(CustomGameStartStoryInfo* result, uint32_t
    // resultlen, const char* id);
    using GetNumCustomGameStartStoryBudgetDependencyLists = uint32_t (*)(
        uint32_t* result, uint32_t resultlen, const char* id, const char* storyid);
    using GetCustomGameStartStoryBudgetDependencies = uint32_t (*)(
        const char** result, uint32_t resultlen, const char* id, const char* storyid);
    using GetCustomGameStartStoryDefaultProperty = uint32_t (*)(
        const char** result, uint32_t resultlen, const char* id, const char* propertyid);
    using GetCustomGameStartStoryProperty = uint32_t (*)(
        const char** result, uint32_t resultlen, const char* id, const char* propertyid);
    // using GetCustomGameStartStoryPropertyState = CustomGameStartStoryState (*)(const char*
    // id, const char* propertyid); using GetCustomGameStartStringProperty = const char*
    // (*)(const char* id, const char* propertyid, CustomGameStartStringPropertyState* state);
    using GetMacroMapPositionOnEcliptic = const char* (*)(UniverseID holomapid,
        UIPosRot* position);
    using GetNumAllFactions = uint32_t (*)(bool includehidden);
    using GetNumAllRaces = uint32_t (*)(void);
    using GetNumAvailableCustomGameStarts = uint32_t (*)(const char* id);
    using GetNumConstructionPlanInfo = size_t (*)(const char* constructionplanid);
    using GetNumCustomGameStartBudgetGroups = uint32_t (*)(const char* id);
    using GetNumCustomGameStartPaintThemes = uint32_t (*)(const char* id);
    using GetNumCustomGameStartStoryBudgets = uint32_t (*)(const char* id);
    using GetNumPlannedLimitedModules = uint32_t (*)(const char* constructionplanid);
    using GetNumPlayerBuildMethods = uint32_t (*)(void);
    using GetNumWares = uint32_t (*)(
        const char* tags, bool research, const char* licenceownerid, const char* exclusiontags);
    using GetPlannedLimitedModules = uint32_t (*)(
        UIMacroCount* result, uint32_t resultlen, const char* constructionplanid);
    using GetPlayerBuildMethods = uint32_t (*)(
        ProductionMethodInfo* result, uint32_t resultlen);
    using GetStationValue = int64_t (*)(const char* macroname, const char* constructionplanid);
    using GetUIDefaultBaseRelation = int32_t (*)(
        const char* fromfactionid, const char* tofactionid);
    using GetWares = uint32_t (*)(const char** result, uint32_t resultlen, const char* tags,
        bool research, const char* licenceownerid, const char* exclusiontags);
    using HasCustomGameStartBudget = bool (*)(const char* id, const char* budgetid);
    using ImportCustomGameStart = void (*)(
        const char* id, const char* filename, const char* gamestartid);
    using IsConstructionPlanAvailableInCustomGameStart = bool (*)(
        const char* constructionplanid);
    using IsCustomGameStartPropertyChanged = bool (*)(const char* id, const char* propertyid);
    using IsGameStartModified = bool (*)(const char* id);
    using NewMultiplayerGame = void (*)(const char* modulename, const char* difficulty);
    using RemoveCustomGameStartPlayerProperty = void (*)(
        const char* id, const char* propertyid, const char* entryid);
    using RemoveHoloMap = void (*)(void);
    using ResetCustomGameStart = void (*)(const char* id);
    using ResetCustomGameStartProperty = void (*)(const char* id, const char* propertyid);
    // using SetCustomGameStartBlueprintProperty = void (*)(const char* id, const char*
    // propertyid, CustomGameStartBlueprint* uivalue, uint32_t uivaluecount);
    using SetCustomGameStartBoolProperty = void (*)(
        const char* id, const char* propertyid, bool uivalue);
    // using SetCustomGameStartEncyclopediaProperty = void (*)(const char* id, const char*
    // propertyid, CustomGameStartEncyclopediaEntry* uivalue, uint32_t uivaluecount); using
    // SetCustomGameStartInventoryProperty = void (*)(const char* id, const char* propertyid,
    // CustomGameStartInventory* uivalue, uint32_t uivaluecount); using
    // SetCustomGameStartKnownProperty2 = void (*)(const char* id, const char* propertyid,
    // CustomGameStartKnownEntry2* uivalue, uint32_t uivaluecount);
    using SetCustomGameStartMoneyProperty = void (*)(
        const char* id, const char* propertyid, int64_t uivalue);
    using SetCustomGameStartPlayerPropertyCount = void (*)(
        const char* id, const char* propertyid, const char* entryid, uint32_t count);
    using SetCustomGameStartPlayerPropertyObjectMacro = const char* (*)(const char* id,
        const char* propertyid, const char* entryid, const char* macroname);
    using SetCustomGameStartPlayerPropertyMacroAndConstructionPlan2 =
        const char* (*)(const char* id, const char* propertyid, const char* entryid,
            const char* macroname, const char* constructionplanid);
    using SetCustomGameStartPlayerPropertyName = void (*)(
        const char* id, const char* propertyid, const char* entryid, const char* name);
    using SetCustomGameStartPlayerPropertyPeople = void (*)(
        const char* id, const char* propertyid, const char* entryid, const char* peopledefid);
    using SetCustomGameStartPlayerPropertyPeopleFillPercentage2 = void (*)(
        const char* id, const char* propertyid, const char* entryid, float fillpercentage);
    // using SetCustomGameStartPlayerPropertyPerson = void (*)(const char* id, const char*
    // propertyid, const char* entryid, CustomGameStartPersonEntry uivalue);
    using SetCustomGameStartPlayerPropertySectorAndOffset = void (*)(const char* id,
        const char* propertyid, const char* entryid, const char* sectormacroname,
        UIPosRot uivalue);
    using SetCustomGameStartPosRotProperty = void (*)(
        const char* id, const char* propertyid, UIPosRot uivalue);
    // using SetCustomGameStartRelationsProperty = void (*)(const char* id, const char*
    // propertyid, CustomGameStartRelationInfo* uivalue, uint32_t uivaluecount);
    using SetCustomGameStartResearchProperty = void (*)(
        const char* id, const char* propertyid, const char** uivalue, uint32_t uivaluecount);
    using SetCustomGameStartShipAndEmptyLoadout = void (*)(const char* id,
        const char* shippropertyid, const char* loadoutpropertyid, const char* macroname);
    using SetCustomGameStartStringProperty = void (*)(
        const char* id, const char* propertyid, const char* uivalue);
    using SetCustomGameStartStory = void (*)(
        const char* id, const char* propertyid, const char** uivalue, uint32_t uivaluecount);
    using SetMacroMapLocalLinearHighways = void (*)(UniverseID holomapid, bool value);
    using SetMacroMapLocalRingHighways = void (*)(UniverseID holomapid, bool value);
    using SetMacroMapSelection = void (*)(
        UniverseID holomapid, bool selectplayer, const char* propertyentryid);
    using SetMapRelativeMousePosition = void (*)(
        UniverseID holomapid, bool valid, float x, float y);
    using ShowUniverseMacroMap2 = void (*)(UniverseID holomapid, const char* macroname,
        const char* startsectormacroname, UIPosRot sectoroffset, bool setoffset, bool showzone,
        const char* gamestartid);
    using StartPanMap = void (*)(UniverseID holomapid);
    using StopPanMap = bool (*)(UniverseID holomapid);
    using ZoomMap = void (*)(UniverseID holomapid, float zoomstep);
}