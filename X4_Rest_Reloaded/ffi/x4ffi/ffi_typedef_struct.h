#pragma once

#include "ffi_typedef.h"

#include <cstdint>

namespace X4FFI {

    typedef struct {
        const char* name;
        uint32_t size;
    } Font;

    typedef struct {
        uint32_t red;
        uint32_t green;
        uint32_t blue;
        uint32_t alpha;
    } Color;
    typedef struct {
        int x;
        int y;
    } Coord2D;
    typedef struct {
        uint32_t width;
        uint32_t height;
        uint32_t xHotspot;
        uint32_t yHotspot;
    } CursorInfo;
    typedef struct {
        Color color;
        uint32_t width;
        uint32_t height;
        uint32_t x;
        uint32_t y;
    } DropDownIconInfo;
    typedef struct {
        const char* id;
        const char* iconid;
        const char* text;
        const char* text2;
        const char* mouseovertext;
        Color overrideColor;
        bool displayRemoveOption;
        bool active;
        bool hasOverrideColor;
    } DropDownOption;
    typedef struct {
        Color color;
        Font font;
        const char* alignment;
        uint32_t x;
        uint32_t y;
        const char* textOverride;
    } DropDownTextInfo;
    typedef struct {
        double x;
        double y;
        bool inactive;
    } GraphDataPoint2;
    typedef struct {
        uint32_t MarkerType;
        uint32_t MarkerSize;
        Color MarkerColor;
        uint32_t LineType;
        uint32_t LineWidth;
        Color LineColor;
        size_t NumData;
        bool Highlighted;
        const char* MouseOverText;
    } GraphDataRecord;
    typedef struct {
        size_t DataRecordIdx;
        size_t DataIdx;
        const char* IconID;
        const char* MouseOverText;
    } GraphIcon;
    typedef struct {
        const char* text;
        Font font;
        Color color;
    } GraphTextInfo;
    typedef struct {
        GraphTextInfo label;
        double startvalue;
        double endvalue;
        double granularity;
        double offset;
        bool grid;
        Color color;
        Color gridcolor;
    } GraphAxisInfo;
    typedef struct {
        const char* iconid;
        uint32_t x;
        uint32_t y;
        bool display;
    } HotkeyInfo;
    typedef struct {
        int x;
        int y;
    } ResolutionInfo;
    typedef struct {
        double min;
        double minSelect;
        double max;
        double maxSelect;
        double start;
        double step;
        double infinitevalue;
        uint32_t maxfactor;
        bool exceedmax;
        bool hidemaxvalue;
        bool righttoleft;
        bool fromcenter;
        bool readonly;
        bool useinfinitevalue;
        bool usetimeformat;
    } SliderCellDetails;
    typedef struct {
        uint32_t toprow;
        uint32_t selectedrow;
        uint32_t selectedcol;
        uint32_t shiftstart;
        uint32_t shiftend;
    } TableSelectionInfo;
    typedef struct {
        const char* text;
        uint32_t x;
        int32_t y;
        const char* alignment;
        Color color;
        Font font;
    } TextInfo;
    typedef struct {
        const char* iconid;
        Color color;
        uint32_t width;
        uint32_t height;
        int32_t rotationrate;
        uint32_t rotstart;
        float rotduration;
        float rotinterval;
        float initscale;
        float scaleduration;
    } UIFrameTextureInfo;
    typedef struct {
        const char* id;
        const char* text;
        uint32_t x;
        uint32_t y;
        uint32_t width;
        uint32_t height;
        bool highlightonly;
        bool usebackgroundspan;
    } UIOverlayInfo2;

    typedef struct {
        const char* id;
        uint32_t textid;
        uint32_t descriptionid;
        uint32_t value;
        uint32_t relevance;
        const char* ware;
    } SkillInfo;

    typedef struct {
        const char* macro;
        const char* ware;
        uint32_t amount;
        uint32_t capacity;
    } AmmoData;
    typedef struct {
        const char* id;
        const char* text;
    } BoardingBehaviour;
    typedef struct {
        const char* id;
        const char* text;
    } BoardingPhase;
    typedef struct {
        uint32_t approach;
        uint32_t insertion;
    } BoardingRiskThresholds;
    typedef struct {
        BuildTaskID id;
        UniverseID buildingcontainer;
        UniverseID component;
        const char* macro;
        const char* factionid;
        UniverseID buildercomponent;
        int64_t price;
        bool ismissingresources;
        uint32_t queueposition;
    } BuildTaskInfo;
    typedef struct {
        const char* newroleid;
        NPCSeed seed;
        uint32_t amount;
    } CrewTransferContainer;
    typedef struct {
        const char* id;
        const char* name;
    } ControlPostInfo;
    typedef struct {
        UniverseID entity;
        UniverseID personcontrollable;
        NPCSeed personseed;
    } GenericActor;
    typedef struct {
        const char* id;
        const char* name;
        const char* description;
    } ResponseInfo;
    typedef struct {
        const char* id;
        const char* name;
        const char* description;
        uint32_t numresponses;
        const char* defaultresponse;
        bool ask;
    } SignalInfo;
    typedef struct {
        const char* name;
        const char* transport;
        uint32_t spaceused;
        uint32_t capacity;
    } StorageInfo;
    typedef struct {
        float x;
        float y;
        float z;
    } Coord3D;
    typedef struct {
        float dps;
        uint32_t quadranttextid;
    } DPSData;
    typedef struct {
        const char* id;
        const char* name;
        bool possible;
    } DroneModeInfo;
    typedef struct {
        const char* factionID;
        const char* factionName;
        const char* factionIcon;
    } FactionDetails;
    typedef struct {
        const char* icon;
        const char* caption;
    } MissionBriefingIconInfo;
    typedef struct {
        const char* missionName;
        const char* missionDescription;
        int difficulty;
        int upkeepalertlevel;
        const char* threadType;
        const char* mainType;
        const char* subType;
        const char* subTypeName;
        const char* faction;
        int64_t reward;
        const char* rewardText;
        size_t numBriefingObjectives;
        int activeBriefingStep;
        const char* opposingFaction;
        const char* license;
        float timeLeft;
        double duration;
        bool abortable;
        bool hasObjective;
        UniverseID associatedComponent;
        UniverseID threadMissionID;
    } MissionDetails;
    typedef struct {
        const char* id;
        const char* name;
    } MissionGroupDetails;
    typedef struct {
        MissionID missionid;
        uint32_t amount;
        uint32_t numskills;
        SkillInfo* skills;
    } MissionNPCInfo;
    typedef struct {
        const char* text;
        const char* actiontext;
        const char* detailtext;
        int step;
        bool failed;
        bool completedoutofsequence;
    } MissionObjectiveStep3;
    typedef struct {
        uint32_t id;
        bool ispin;
        bool ishome;
    } MultiverseMapPickInfo;
    typedef struct {
        NPCSeed seed;
        const char* roleid;
        int32_t tierid;
        const char* name;
        int32_t combinedskill;
    } NPCInfo;
    typedef struct {
        const char* chapter;
        const char* onlineid;
    } OnlineMissionInfo;
    typedef struct {
        const char* id;
        const char* name;
        const char* icon;
        const char* description;
        const char* category;
        const char* categoryname;
        bool infinite;
        uint32_t requiredSkill;
    } OrderDefinition;
    typedef struct {
        size_t queueidx;
        const char* state;
        const char* statename;
        const char* orderdef;
        size_t actualparams;
        bool enabled;
        bool isinfinite;
        bool issyncpointreached;
        bool istemporder;
    } Order;
    typedef struct {
        size_t queueidx;
        const char* state;
        const char* statename;
        const char* orderdef;
        size_t actualparams;
        bool enabled;
        bool isinfinite;
        bool issyncpointreached;
        bool istemporder;
        bool isoverride;
    } Order2;
    typedef struct {
        uint32_t id;
        AIOrderID orderid;
        const char* orderdef;
        const char* message;
        double timestamp;
        bool wasdefaultorder;
        bool wasinloop;
    } OrderFailure;
    typedef struct {
        const char* id;
        const char* name;
        const char* desc;
        uint32_t amount;
        uint32_t numtiers;
        bool canhire;
    } PeopleInfo;
    typedef struct {
        const char* id;
        const char* name;
    } ProductionMethodInfo;
    typedef struct {
        const char* id;
        const char* name;
        const char* shortname;
        const char* description;
        const char* icon;
    } RaceInfo;
    typedef struct {
        const char* name;
        int32_t skilllevel;
        uint32_t amount;
    } RoleTierData;
    typedef struct {
        UniverseID context;
        const char* group;
        UniverseID component;
    } ShieldGroup;
    typedef struct {
        uint32_t textid;
        uint32_t descriptionid;
        uint32_t value;
        uint32_t relevance;
    } Skill2;
    typedef struct {
        UniverseID softtargetID;
        const char* softtargetConnectionName;
    } SofttargetDetails;
    typedef struct {
        const char* max;
        const char* current;
    } SoftwareSlot;
    typedef struct {
        UniverseID controllableid;
        int group;
    } SubordinateGroup;
    typedef struct {
        uint32_t id;
        UniverseID owningcontrollable;
        size_t owningorderidx;
        bool reached;
    } SyncPointInfo2;
    typedef struct {
        const char* reason;
        NPCSeed person;
        NPCSeed partnerperson;
    } UICrewExchangeResult;
    typedef struct {
        const char* shape;
        const char* name;
        uint32_t requiredSkill;
        float radius;
        bool rollMembers;
        bool rollFormation;
        size_t maxShipsPerLine;
    } UIFormationInfo;
    typedef struct {
        const char* file;
        const char* icon;
        bool ispersonal;
    } UILogo;
    typedef struct {
        const char* icon;
        Color color;
        uint32_t volume_s;
        uint32_t volume_m;
        uint32_t volume_l;
    } UIMapTradeVolumeParameter;
    typedef struct {
        const char* id;
        const char* name;
    } UIModuleSet;
    typedef struct {
        const float x;
        const float y;
        const float z;
        const float yaw;
        const float pitch;
        const float roll;
    } UIPosRot;
    typedef struct {
        const char* wareid;
        uint32_t amount;
    } UIWareAmount;
    typedef struct {
        bool primary;
        uint32_t idx;
    } UIWeaponGroup;
    typedef struct {
        UniverseID contextid;
        const char* path;
        const char* group;
    } UpgradeGroup2;
    typedef struct {
        UniverseID currentcomponent;
        const char* currentmacro;
        const char* slotsize;
        uint32_t count;
        uint32_t operational;
        uint32_t total;
    } UpgradeGroupInfo;
    typedef struct {
        const char* id;
        const char* icon;
        const char* factoryname;
        const char* factorydesc;
        const char* factorymapicon;
        const char* factoryhudicon;
        uint32_t tier;
    } WareGroupInfo;
    typedef struct {
        UniverseID reserverid;
        const char* ware;
        uint32_t amount;
        bool isbuyreservation;
        double eta;
        TradeID tradedealid;
        MissionID missionid;
        bool isvirtual;
        bool issupply;
    } WareReservationInfo2;
    typedef struct {
        const char* ware;
        int32_t current;
        int32_t max;
    } WareYield;
    typedef struct {
        const char* id;
        const char* name;
        bool active;
    } WeaponSystemInfo;
    typedef struct {
        uint32_t current;
        uint32_t capacity;
        uint32_t optimal;
        uint32_t available;
        uint32_t maxavailable;
        double timeuntilnextupdate;
    } WorkForceInfo;
    typedef struct {
        const char* wareid;
        int32_t amount;
    } YieldInfo;

    typedef struct {
        UIPosRot offset;
        float cameradistance;
    } HoloMapState;
    typedef struct {
        UniverseID target;
        UIWareAmount* wares;
        uint32_t numwares;
    } MissionWareDeliveryInfo;
    typedef struct {
        size_t idx;
        const char* macroid;
        UniverseID componentid;
        UIPosRot offset;
        const char* connectionid;
        size_t predecessoridx;
        const char* predecessorconnectionid;
        bool isfixed;
    } UIConstructionPlanEntry;
    typedef struct {
        const char* objectiveText;
        float timeout;
        const char* progressname;
        uint32_t curProgress;
        uint32_t maxProgress;
        size_t numTargets;
    } MissionObjective2;

    typedef struct {
        const char* path;
        const char* group;
    } UpgradeGroup;

    typedef struct {
        size_t index;
        double interval;
        bool repeats;
        bool muted;
        uint32_t numspaces;
        UniverseID* spaceids;
        const char* objectclass;
        const char* objectpurpose;
        const char* objectidcode;
        const char* objectowner;
        const char* name;
        const char* message;
        const char* soundid;
    } PlayerAlertInfo2;

    typedef struct {
        uint32_t id;
        const char* type;
        const char* name;
        bool usemacrowhitelist;
        uint32_t nummacros;
        const char** macros;
        bool usefactionwhitelist;
        uint32_t numfactions;
        const char** factions;
        const char* relation;
        bool hazardous;
    } BlacklistInfo2;

    typedef struct {
        const char* factionid;
        const char* civiliansetting;
        const char* militarysetting;
    } UIFightRuleSetting;

    typedef struct {
        FightRuleID id;
        const char* name;
        uint32_t numfactions;
        UIFightRuleSetting* factions;
    } FightRuleInfo;

    typedef struct {
        uint32_t id;
        const char* name;
        uint32_t numfactions;
        const char** factions;
        bool iswhitelist;
    } TradeRuleInfo;

    typedef struct {
        const char* ID;
        const char* Name;
        const char* RawName;
    } UIClothingTheme;

    typedef struct {
        const char* Name;
        const char* RawName;
        const char* Ware;
        uint32_t Quality;
    } UIEquipmentMod;

    typedef struct {
        const char* ID;
        const char* Name;
        const char* RawName;
        const char* Icon;
    } UIPaintTheme;

    typedef struct {
        MessageID id;
        double time;
        const char* category;
        const char* title;
        const char* text;
        const char* source;
        UniverseID sourcecomponent;
        const char* interaction;
        UniverseID interactioncomponent;
        const char* interactiontext;
        const char* interactionshorttext;
        const char* cutscenekey;
        const char* entityname;
        const char* factionname;
        int64_t money;
        int64_t bonus;
        bool highlighted;
        bool isread;
    } MessageInfo;

    typedef struct {
        const char* id;
        const char* name;
        const char* desc;
        const char* category;
        bool enabled;
    } UINotificationType;

    typedef struct {
        uint32_t numspaces;
    } PlayerAlertCounts;

    typedef struct {
        const char* id;
        const char* name;
    } SoundInfo;

    typedef struct {
        uint32_t numfactions;
    } TradeRuleCounts;

    typedef struct {
        uint32_t nummacros;
        uint32_t numfactions;
    } BlacklistCounts;

    typedef struct {
        uint32_t numfactions;
    } FightRuleCounts;

    typedef struct {
        const char* id;
        const char* name;
        const char* description;
        const char* propdatatype;
        float basevalue;
        bool poseffect;
    } EquipmentModPropertyInfo;

    typedef struct {
        const char* Name;
        const char* RawName;
        const char* Ware;
        uint32_t Quality;
        const char* PropertyType;
        float DamageFactor;
        float CoolingFactor;
        float ReloadFactor;
        float SpeedFactor;
        float LifeTimeFactor;
        float MiningFactor;
        float StickTimeFactor;
        float ChargeTimeFactor;
        float BeamLengthFactor;
        uint32_t AddedAmount;
        float RotationSpeedFactor;
        float SurfaceElementFactor;
    } UIWeaponMod;

    typedef struct {
        double time;
        int64_t money;
        int64_t entryid;
    } MoneyLogEntry;

    typedef struct {
        const char* name;
        const char* rawname;
        const char* icon;
        const char* rewardicon;
        int64_t remainingtime;
        uint32_t numships;
    } UIVentureInfo;

    typedef struct {
        const char* ware;
        const char* macro;
        int amount;
    } UIWareInfo;

    typedef struct {
        const char* Name;
        const char* RawName;
        const char* Ware;
        uint32_t Quality;
        const char* PropertyType;
        float ForwardThrustFactor;
        float StrafeThrustFactor;
        float RotationThrustFactor;
        float BoostThrustFactor;
        float BoostDurationFactor;
        float BoostAttackTimeFactor;
        float BoostReleaseTimeFactor;
        float BoostChargeTimeFactor;
        float BoostRechargeTimeFactor;
        float TravelThrustFactor;
        float TravelStartThrustFactor;
        float TravelAttackTimeFactor;
        float TravelReleaseTimeFactor;
        float TravelChargeTimeFactor;
    } UIEngineMod;

    typedef struct {
        const char* Name;
        const char* RawName;
        const char* Ware;
        uint32_t Quality;
        const char* PropertyType;
        float CapacityFactor;
        float RechargeDelayFactor;
        float RechargeRateFactor;
    } UIShieldMod;

    typedef struct {
        double time;
        int64_t money;
        int64_t entryid;
        const char* eventtype;
        const char* eventtypename;
        UniverseID partnerid;
        const char* partnername;
        const char* partneridcode;
        int64_t tradeentryid;
        const char* tradeeventtype;
        const char* tradeeventtypename;
        UniverseID buyerid;
        UniverseID sellerid;
        const char* ware;
        uint32_t amount;
        int64_t price;
        bool complete;
    } TransactionLogEntry;

    typedef struct {
        const char* Name;
        const char* RawName;
        const char* Ware;
        uint32_t Quality;
        const char* PropertyType;
        float MassFactor;
        float DragFactor;
        float MaxHullFactor;
        float RadarRangeFactor;
        uint32_t AddedUnitCapacity;
        uint32_t AddedMissileCapacity;
        uint32_t AddedCountermeasureCapacity;
        uint32_t AddedDeployableCapacity;
        float RadarCloakFactor;
        float RegionDamageProtection;
        float HideCargoChance;
    } UIShipMod2;

    typedef struct {
        const char* stat;
        uint32_t min;
        uint32_t max;
        uint64_t minvalue;
        uint64_t maxvalue;
        bool issatisfied;
    } UITerraformingProjectCondition;
    typedef struct {
        const char* text;
        const char* stat;
        int32_t change;
        uint64_t value;
        uint64_t minvalue;
        uint64_t maxvalue;
        bool onfail;
        bool issideeffect;
        uint32_t chance;
        uint32_t setbackpercent;
        bool isbeneficial;
    } UITerraformingProjectEffect;
    typedef struct {
        const char* id;
        const char* name;
    } UITerraformingProjectGroup;
    typedef struct {
        const char* id;
        bool anyproject;
    } UITerraformingProjectPredecessorGroup;
    typedef struct {
        const char* ware;
        const char* waregroupname;
        uint32_t value;
    } UITerraformingProjectRebate;

    typedef struct {
        const char* macro;
        uint32_t amount;
        bool optional;
    } UILoadoutAmmoData;
    typedef struct {
        const char* macro;
        const char* path;
        const char* group;
        uint32_t count;
        bool optional;
    } UILoadoutGroupData;
    typedef struct {
        const char* macro;
        const char* upgradetypename;
        size_t slot;
        bool optional;
    } UILoadoutMacroData;
    typedef struct {
        const char* ware;
    } UILoadoutSoftwareData;
    typedef struct {
        const char* macro;
        bool optional;
    } UILoadoutVirtualMacroData;
    typedef struct {
        UILoadoutMacroData* weapons;
        uint32_t numweapons;
        UILoadoutMacroData* turrets;
        uint32_t numturrets;
        UILoadoutMacroData* shields;
        uint32_t numshields;
        UILoadoutMacroData* engines;
        uint32_t numengines;
        UILoadoutGroupData* turretgroups;
        uint32_t numturretgroups;
        UILoadoutGroupData* shieldgroups;
        uint32_t numshieldgroups;
        UILoadoutAmmoData* ammo;
        uint32_t numammo;
        UILoadoutAmmoData* units;
        uint32_t numunits;
        UILoadoutSoftwareData* software;
        uint32_t numsoftware;
        UILoadoutVirtualMacroData thruster;
    } UILoadout;
    typedef struct {
        uint32_t numweapons;
        uint32_t numturrets;
        uint32_t numshields;
        uint32_t numengines;
        uint32_t numturretgroups;
        uint32_t numshieldgroups;
        uint32_t numammo;
        uint32_t numunits;
        uint32_t numsoftware;
    } UILoadoutCounts;
    typedef struct {
        const char* id;
        const char* name;
        const char* iconid;
        bool deleteable;
    } UILoadoutInfo;
    typedef struct {
        const char* upgradetype;
        size_t slot;
    } UILoadoutSlot;


    typedef struct {
        const char* macro;
        const char* ware;
        const char* productionmethodid;
    } UIBlueprint;

    typedef struct {
        const char* id;
        const char* name;
        int32_t state;
        const char* requiredversion;
        const char* installedversion;
    } InvalidPatchInfo;

    typedef struct {
        const char* filename;
        const char* name;
        const char* id;
    } UIConstructionPlanInfo;

    typedef struct {
        const char* name;
        const char* id;
        const char* source;
        bool deleteable;
    } UIConstructionPlan;

    typedef struct {
        const char* macro;
        uint32_t amount;
    } UIMacroCount;

    typedef struct {
        const char* tag;
        const char* name;
    } EquipmentCompatibilityInfo;

} // namespace X4FFI