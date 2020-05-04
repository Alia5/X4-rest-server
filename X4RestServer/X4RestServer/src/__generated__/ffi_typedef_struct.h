#pragma once
#include "ffi_typedef.h"

namespace X4FFI
{
    typedef struct {
        int unknown;
    } mach_header;
    typedef struct {
        int unknown;
    } mach_header_64;
    typedef struct {
        int unknown;
    } mach_fat_header;
    typedef struct {
        int unknown;
    } mach_fat_arch;
    typedef struct {
      uint32_t strx;
      uint8_t type, sect;
      uint16_t desc;
      uint64_t value;
    } mach_nlist_64;
    typedef struct {
      uint32_t cmd, cmdsize;
      char segname[16];
      uint64_t vmaddr, vmsize, fileoff, filesize;
      uint32_t maxprot, initprot, nsects, flags;
    } mach_segment_command_64;
    typedef struct {
      uint32_t cmd, cmdsize;
      char segname[16];
      uint32_t vmaddr, vmsize, fileoff, filesize;
      uint32_t maxprot, initprot, nsects, flags;
    } mach_segment_command;
    typedef struct {
      uint32_t cmd, cmdsize, symoff, nsyms, stroff, strsize;
    } mach_symtab_command;
    typedef struct {
      int32_t strx;
      uint8_t type, sect;
      int16_t desc;
      uint32_t value;
    } mach_nlist;
    typedef struct {
      char sectname[16], segname[16];
      uint64_t addr, size;
      uint32_t offset, align, reloff, nreloc, flags;
      uint32_t reserved1, reserved2, reserved3;
    } mach_section_64;
    typedef struct {
      char sectname[16], segname[16];
      uint32_t addr, size;
      uint32_t offset, align, reloff, nreloc, flags;
      uint32_t reserved1, reserved2;
    } mach_section;
    typedef struct {
    		uint32_t red;
    		uint32_t green;
    		uint32_t blue;
    		uint32_t alpha;
    	} Color;
    typedef struct {
    		float x;
    		float y;
    		float z;
    		float yaw;
    		float pitch;
    		float roll;
    	} UIPosRot;
    typedef struct {
    		double time;
    		uint64_t amount;
    	} UICargoStatData;
    typedef struct {
    		double time;
    		int64_t price;
    		int amount;
    		int limit;
    	} UITradeOfferStatData;
    typedef struct {
    		const char* ware;
    	} UILoadoutSoftwareData;
    typedef struct {
    		const char* newroleid;
    		NPCSeed seed;
    		uint32_t amount;
    	} CrewTransferContainer;
    typedef struct {
    		const char* name;
    		uint32_t size;
    	} Font;
    typedef struct {
    		const char* name;
    		const char* typeclass;
    	} UISunInfo;
    typedef struct {
    		const char* name;
    		const char* typeclass;
    		const char* geology;
    		const char* atmosphere;
    		const char* population;
    		const char* settlements;
    		uint32_t nummoons;
    	} UICelestialBodyInfo;
    typedef struct {
    		const char* macro;
    		uint32_t amount;
    		bool optional;
    	} UILoadoutAmmoData;
    typedef struct {
    		const char* macro;
    		const char* upgradetypename;
    		size_t slot;
    		bool optional;
    	} UILoadoutMacroData;
    typedef struct {
    		const char* macro;
    		const char* path;
    		const char* group;
    		uint32_t count;
    		bool optional;
    	} UILoadoutGroupData;
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
      struct {
        mach_header_64 hdr;
        mach_segment_command_64 seg;
        mach_section_64 sec;
        mach_symtab_command sym;
      } arch[1];
      mach_nlist_64 sym_entry;
      uint8_t space[4096];
    } mach_obj_64;
    typedef struct {
      struct {
        mach_header hdr;
        mach_segment_command seg;
        mach_section sec;
        mach_symtab_command sym;
      } arch[1];
      mach_nlist sym_entry;
      uint8_t space[4096];
    } mach_obj;
    typedef struct {
      mach_fat_header fat;
      mach_fat_arch fat_arch[4];
      struct {
        mach_header hdr;
        mach_segment_command seg;
        mach_section sec;
        mach_symtab_command sym;
      } arch[4];
      mach_nlist sym_entry;
      uint8_t space[4096];
    } mach_fat_obj;
    typedef struct {
    		uint64_t poiID;
    		UniverseID componentID;
    		const char* messageType;
    		const char* connectionName;
    		bool isAssociative;
    		bool isMissionTarget;
    		bool isPriorityMissionTarget;
    		bool showIndicator;
    	} MessageDetails2;
    typedef struct {
    		uint64_t poiID;
    		UniverseID componentID;
    		const char* messageType;
    		const char* connectionName;
    		bool isAssociative;
    		bool isMissionObjective;
    		bool showIndicator;
    	} MessageDetails;
    typedef struct {
    		uint32_t width;
    		uint32_t height;
    		uint32_t xHotspot;
    		uint32_t yHotspot;
    	} CursorInfo;
    typedef struct {
    		uint32_t toprow;
    		uint32_t selectedrow;
    		uint32_t selectedcol;
    		uint32_t shiftstart;
    		uint32_t shiftend;
    	} TableSelectionInfo;
    typedef struct {
    		uint32_t textid;
    		uint32_t value;
    		uint32_t relevance;
    	} Skill;
    typedef struct {
    		uint32_t textid;
    		uint32_t descriptionid;
    		uint32_t value;
    		uint32_t relevance;
    	} Skill2;
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
    		uint32_t numsuns;
    		uint32_t numplanets;
    	} UISystemInfoCounts;
    typedef struct {
    		uint32_t numremoved;
    		uint32_t numadded;
    		uint32_t numtransferred;
    	} CrewTransferInfoCounts;
    typedef struct {
    		uint32_t nummacros;
    		uint32_t numfactions;
    	} BlacklistCounts;
    typedef struct {
    		uint32_t mintime;
    		uint32_t maxtime;
    		float factor;
    	} AutosaveIntervalInfo;
    typedef struct {
    		uint32_t messageID;
    		bool obstructed;
    	} CrosshairMessage;
    typedef struct {
    		uint32_t id;
    		const char* type;
    		const char* name;
    		uint32_t nummacros;
    		const char** macros;
    		uint32_t numfactions;
    		const char** factions;
    		const char* relation;
    		bool hazardous;
    	} BlacklistInfo;
    typedef struct {
    		uint32_t id;
    		const char* text;
    		const char* type;
    		bool ispossible;
    		bool istobedisplayed;
    	} UIAction;
    typedef struct {
    		uint32_t id;
    		bool reached;
    	} SyncPointInfo;
    typedef struct {
    		uint32_t current;
    		uint32_t capacity;
    		uint32_t optimal;
    		uint32_t available;
    		uint32_t maxavailable;
    		double timeuntilnextupdate;
    	} WorkForceInfo;
    typedef struct {
    		uint32_t approach;
    		uint32_t insertion;
    	} BoardingRiskThresholds;
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
    		size_t index;
    		double interval;
    		bool repeats;
    		bool muted;
    		UniverseID spaceid;
    		const char* objectclass;
    		const char* objectpurpose;
    		const char* objectidcode;
    		const char* objectowner;
    		const char* name;
    		const char* message;
    		const char* soundid;
    	} PlayerAlertInfo;
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
    		size_t DataRecordIdx;
    		size_t DataIdx;
    		const char* IconID;
    		const char* MouseOverText;
    	} GraphIcon;
    typedef struct {
    		int64_t trade;
    		int64_t defence;
    		int64_t build;
    		int64_t repair;
    		int64_t missile;
    	} SupplyBudget;
    typedef struct {
    		int32_t id;
    		const char* name;
    		const char* warning;
    		const char* font;
    		bool voice;
    	} LanguageInfo;
    typedef struct {
    		int x;
    		int y;
    	} ResolutionInfo;
    typedef struct {
    		int x;
    		int y;
    	} Coord2D;
    typedef struct {
    		int relationStatus;
    		int relationValue;
    		int relationLEDValue;
    		bool isBoostedValue;
    	} RelationDetails;
    typedef struct {
    		int major;
    		int minor;
    	} GameVersion;
    typedef struct {
    		float yaw;
    		float pitch;
    		float roll;
    	} Rotation;
    typedef struct {
    		float x;
    		float y;
    	} Position2D;
    typedef struct {
    		float x;
    		float y;
    		float z;
    	} Coord3D;
    typedef struct {
    		float x;
    		float y;
    		float z;
    		float yaw;
    		float pitch;
    		float roll;
    	} PosRot;
    typedef struct {
    		float x;
    		float y;
    		bool onScreen;
    	} ScreenPos;
    typedef struct {
    		float dps;
    		uint32_t quadranttextid;
    	} DPSData;
    typedef struct {
    		float angle;
    		bool inside;
    		bool valid;
    	} ArrowDetails;
    typedef struct {
    		float HullValue;
    		float ShieldValue;
    		float GroupedShieldValue;
    		float BurstDPS;
    		float SustainedDPS;
    		float TurretBurstDPS;
    		float TurretSustainedDPS;
    		float GroupedTurretBurstDPS;
    		float GroupedTurretSustainedDPS;
    		float ForwardSpeed;
    		float BoostSpeed;
    		float TravelSpeed;
    		float YawSpeed;
    		float PitchSpeed;
    		float RollSpeed;
    		float ForwardAcceleration;
    		uint32_t NumDocksShipMedium;
    		uint32_t NumDocksShipSmall;
    		uint32_t ShipCapacityMedium;
    		uint32_t ShipCapacitySmall;
    		uint32_t CrewCapacity;
    		uint32_t ContainerCapacity;
    		uint32_t SolidCapacity;
    		uint32_t LiquidCapacity;
    		uint32_t UnitCapacity;
    		uint32_t MissileCapacity;
    		uint32_t CountermeasureCapacity;
    		uint32_t DeployableCapacity;
    		float RadarRange;
    	} UILoadoutStatistics2;
    typedef struct {
    		double x;
    		double y;
    	} GraphDataPoint;
    typedef struct {
    		double time;
    		int64_t money;
    	} UIAccountStatData;
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
    		double fps;
    		double moveTime;
    		double renderTime;
    		double gpuTime;
    	} FPSDetails;
    typedef struct {
    		const char* wareid;
    		uint32_t amount;
    	} UIWareAmount;
    typedef struct {
    		const char* wareid;
    		int32_t amount;
    	} YieldInfo;
    typedef struct {
    		const char* wareid;
    		bool isSellOffer;
    		UITradeOfferStatData* data;
    		uint32_t numdata;
    	} UITradeOfferStat;
    typedef struct {
    		const char* wareid;
    		UICargoStatData* data;
    		uint32_t numdata;
    	} UICargoStat;
    typedef struct {
    		const char* ware;
    	} CustomGameStartBlueprint;
    typedef struct {
    		const char* ware;
    		int32_t amount;
    	} CustomGameStartInventory;
    typedef struct {
    		const char* ware;
    		const char* macro;
    		int amount;
    	} UIWareInfo;
    typedef struct {
    		const char* upgradetype;
    		size_t slot;
    	} UILoadoutSlot;
    typedef struct {
    		const char* type;
    		const char* ware;
    		const char* macro;
    		int amount;
    	} EquipmentWareInfo;
    typedef struct {
    		const char* text;
    		uint32_t x;
    		int32_t y;
    		const char* alignment;
    		Color color;
    		Font font;
    	} TextInfo;
    typedef struct {
    		const char* text;
    		int step;
    		bool failed;
    	} MissionObjectiveStep2;
    typedef struct {
    		const char* text;
    		Font font;
    		Color color;
    	} GraphTextInfo;
    typedef struct {
    		const char* state;
    	} CustomGameStartResearchPropertyState;
    typedef struct {
    		const char* state;
    	} CustomGameStartRelationsPropertyState;
    typedef struct {
    		const char* state;
    	} CustomGameStartLoadoutPropertyState;
    typedef struct {
    		const char* state;
    	} CustomGameStartEncyclopediaPropertyState;
    typedef struct {
    		const char* state;
    		uint32_t numvalues;
    		uint32_t numdefaultvalues;
    	} CustomGameStartInventoryPropertyState;
    typedef struct {
    		const char* state;
    		uint32_t numvalues;
    		uint32_t numdefaultvalues;
    	} CustomGameStartBlueprintPropertyState;
    typedef struct {
    		const char* state;
    		int64_t defaultvalue;
    		int64_t minvalue;
    		int64_t maxvalue;
    	} CustomGameStartMoneyPropertyState;
    typedef struct {
    		const char* state;
    		const char* defaultvalue;
    		const char* options;
    	} CustomGameStartStringPropertyState;
    typedef struct {
    		const char* state;
    		bool defaultvalue;
    	} CustomGameStartBoolPropertyState;
    typedef struct {
    		const char* state;
    		UIPosRot defaultvalue;
    	} CustomGameStartPosRotPropertyState;
    typedef struct {
    		const char* sourcetype;
    		const char* sourcelocation;
    	} WareSource;
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
    		const char* path;
    		const char* group;
    	} UpgradeGroup;
    typedef struct {
    		const char* objectiveText;
    		float timeout;
    		size_t numTargets;
    	} MissionObjective;
    typedef struct {
    		const char* name;
    		int32_t skilllevel;
    		uint32_t amount;
    	} RoleTierData;
    typedef struct {
    		const char* name;
    		float hull;
    		float shield;
    		int speed;
    		bool hasShield;
    	} ComponentDetails;
    typedef struct {
    		const char* name;
    		const char* transport;
    		uint32_t spaceused;
    		uint32_t capacity;
    	} StorageInfo;
    typedef struct {
    		const char* name;
    		const char* id;
    		const char* source;
    		bool deleteable;
    	} UIConstructionPlan;
    typedef struct {
    		const char* name;
    		const char* icon;
    	} LicenceInfo;
    typedef struct {
    		const char* name;
    		const char* icon;
    		const char* rewardicon;
    		int64_t remainingtime;
    		uint32_t numships;
    	} UIVentureMissionInfo;
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
    		const char* max;
    		const char* current;
    	} SoftwareSlot;
    typedef struct {
    		const char* macro;
    		uint32_t amount;
    	} UIMacroCount;
    typedef struct {
    		const char* macro;
    		int amount;
    	} SupplyOverride;
    typedef struct {
    		const char* macro;
    		const char* ware;
    		uint32_t amount;
    		uint32_t capacity;
    	} AmmoData;
    typedef struct {
    		const char* macro;
    		const char* ware;
    		const char* productionmethodid;
    	} UIBlueprint;
    typedef struct {
    		const char* macro;
    		const char* category;
    		uint32_t amount;
    	} UnitData;
    typedef struct {
    		const char* library;
    		const char* item;
    	} CustomGameStartEncyclopediaEntry;
    typedef struct {
    		const char* id;
    		const char* text;
    	} BoardingPhase;
    typedef struct {
    		const char* id;
    		const char* text;
    	} BoardingBehaviour;
    typedef struct {
    		const char* id;
    		const char* text;
    		uint32_t x;
    		uint32_t y;
    		uint32_t width;
    		uint32_t height;
    		bool highlightonly;
    	} UIOverlayInfo;
    typedef struct {
    		const char* id;
    		const char* name;
    	} UIModuleSet;
    typedef struct {
    		const char* id;
    		const char* name;
    	} SoundInfo;
    typedef struct {
    		const char* id;
    		const char* name;
    	} MissionGroupDetails;
    typedef struct {
    		const char* id;
    		const char* name;
    	} ControlPostInfo;
    typedef struct {
    		const char* id;
    		const char* name;
    		int32_t state;
    		const char* requiredversion;
    		const char* installedversion;
    	} InvalidPatchInfo;
    typedef struct {
    		const char* id;
    		const char* name;
    		const char* shortname;
    		const char* description;
    		const char* icon;
    	} RaceInfo;
    typedef struct {
    		const char* id;
    		const char* name;
    		const char* iconid;
    		bool deleteable;
    	} UILoadoutInfo;
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
    		const char* id;
    		const char* name;
    		const char* description;
    		const char* propdatatype;
    		float basevalue;
    		bool poseffect;
    	} EquipmentModPropertyInfo;
    typedef struct {
    		const char* id;
    		const char* name;
    		const char* description;
    		const char* image;
    		const char* video;
    		const char* voice;
    		float date;
    		uint32_t group;
    	} TimelineInfo;
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
    		const char* desc;
    		const char* category;
    		bool enabled;
    	} UINotificationType;
    typedef struct {
    		const char* id;
    		const char* name;
    		bool possible;
    	} DroneModeInfo;
    typedef struct {
    		const char* id;
    		const char* name;
    		bool active;
    	} WeaponSystemInfo;
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
    		const char* iconid;
    		uint32_t x;
    		uint32_t y;
    		bool display;
    	} HotkeyInfo;
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
    		const char* icon;
    		uint32_t damageState;
    		bool active;
    		bool usesAmmo;
    		uint32_t ammo;
    		uint32_t mode;
    		float reloadPercent;
    		uint32_t heatState;
    		float heatPercent;
    		float lockPercent;
    		uint64_t counterMeasureTarget;
    	} WeaponDetails;
    typedef struct {
    		const char* icon;
    		const char* mode;
    		uint32_t damageState;
    		bool active;
    		bool usesAmmo;
    		uint32_t ammo;
    	} TurretDetails;
    typedef struct {
    		const char* icon;
    		const char* caption;
    	} MissionBriefingIconInfo;
    typedef struct {
    		const char* icon;
    		Color color;
    		uint32_t volume_s;
    		uint32_t volume_m;
    		uint32_t volume_l;
    	} UIMapTradeVolumeParameter;
    typedef struct {
    		const char* filename;
    		const char* name;
    		const char* description;
    		const char* version;
    		uint32_t rawversion;
    		const char* time;
    		int64_t rawtime;
    		double playtime;
    		const char* playername;
    		const char* location;
    		int64_t money;
    		bool error;
    		bool invalidgameid;
    		bool invalidversion;
    		uint32_t numinvalidpatches;
    	} UISaveInfo;
    typedef struct {
    		const char* file;
    		const char* icon;
    		bool ispersonal;
    	} UILogo;
    typedef struct {
    		const char* factionid;
    		const char* otherfactionid;
    		int32_t relation;
    	} CustomGameStartRelationInfo;
    typedef struct {
    		const char* factionID;
    		const char* factionName;
    		const char* factionIcon;
    	} FactionDetails;
    typedef struct {
    		const char* environment;
    	} UISpaceInfo;
    typedef struct {
    		const char* active;
    		const char* inactive;
    		const char* select;
    	} IconSet;
    typedef struct {
    		const char* PropertyType;
    		float MinValueFloat;
    		float MaxValueFloat;
    		uint32_t MinValueUINT;
    		uint32_t MaxValueUINT;
    		uint32_t BonusMax;
    		float BonusChance;
    	} EquipmentModInfo;
    typedef struct {
    		const char* POIName;
    		const char* POIType;
    	} POIDetails;
    typedef struct {
    		const char* Name;
    		const char* RawName;
    		const char* Ware;
    		uint32_t Quality;
    	} UIEquipmentMod;
    typedef struct {
    		const char* Name;
    		const char* RawName;
    		const char* Ware;
    		uint32_t Quality;
    		uint32_t Amount;
    	} UIPaintMod;
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
    	} UIShipMod;
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
    		const char* ID;
    		const char* Name;
    		const char* RawName;
    	} UIClothingTheme;
    typedef struct {
    		const char* ID;
    		const char* Name;
    		const char* RawName;
    		const char* Icon;
    	} UIPaintTheme;
    typedef struct {
    		const char* HintText;
    		uint32_t HintID;
    	} LoadingHint;
    typedef struct {
    		bool primary;
    		uint32_t idx;
    	} UIWeaponGroup;
    typedef struct {
    		bool factionNPC;
    		bool missionActor;
    		bool shadyGuy;
    	} SpecialNPCSet;
    typedef struct {
    		bool armed;
    		bool blocked;
    		const char* modeIcon;
    		bool pending;
    		bool possible;
    		uint32_t total;
    		uint32_t undocked;
    	} DroneState;
    typedef struct {
    		bool active;
    		bool callbackMode;
    		uint32_t barLine;
    		float barPercent;
    		const char* line1Left;
    		const char* line1Right;
    		const char* line2Left;
    		const char* line2Right;
    		const char* line3Left;
    		const char* line3Right;
    		const char* line4Left;
    		const char* line4Right;
    		const char* missionBarText;
    	} MissionInfo2;
    typedef struct {
    		UniverseID softtargetID;
    		const char* softtargetConnectionName;
    	} SofttargetDetails;
    typedef struct {
    		UniverseID shipid;
    		const char* macroname;
    		UILoadout loadout;
    		uint32_t amount;
    	} UIBuildOrderList;
    typedef struct {
    		UniverseID reserverid;
    		const char* ware;
    		uint32_t amount;
    		bool isbuyreservation;
    		double eta;
    	} WareReservationInfo;
    typedef struct {
    		UniverseID currentcomponent;
    		const char* currentmacro;
    		const char* slotsize;
    		uint32_t count;
    		uint32_t operational;
    		uint32_t total;
    	} UpgradeGroupInfo;
    typedef struct {
    		UniverseID contextid;
    		const char* path;
    		const char* group;
    	} UpgradeGroup2;
    typedef struct {
    		UniverseID context;
    		const char* group;
    		UniverseID component;
    	} ShieldGroup;
    typedef struct {
    		UniverseID component;
    		const char* connection;
    	} UIComponentSlot;
    typedef struct {
    		UniverseID attacker;
    		double time;
    		const char* method;
    	} LastAttackerInfo;
    typedef struct {
    		UISpaceInfo space;
    		uint32_t numsuns;
    		UISunInfo* suns;
    		uint32_t numplanets;
    		UICelestialBodyInfo* planets;
    	} UISystemInfo;
    typedef struct {
    		UIPosRot offset;
    		float cameradistance;
    	} HoloMapState;
    typedef struct {
    		NPCSeed seed;
    		const char* roleid;
    		int32_t tierid;
    		const char* name;
    		int32_t combinedskill;
    	} NPCInfo;
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
    		CrewTransferContainer* removed;
    		uint32_t numremoved;
    		CrewTransferContainer* added;
    		uint32_t numadded;
    		CrewTransferContainer* transferred;
    		uint32_t numtransferred;
    	} CrewTransferInfo;
    typedef struct {
    		Color color;
    		uint32_t width;
    		uint32_t height;
    		uint32_t x;
    		uint32_t y;
    	} DropDownIconInfo;
    typedef struct {
    		Color color;
    		Font font;
    		const char* alignment;
    		uint32_t x;
    		uint32_t y;
    		const char* textOverride;
    	} DropDownTextInfo;
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
}
