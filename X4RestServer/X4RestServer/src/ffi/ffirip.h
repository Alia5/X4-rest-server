#pragma once
#include <cstdint>

namespace X4FFI
{

	typedef int32_t BlacklistID;
	typedef uint64_t MessageID;
	typedef uint64_t UniverseID;
	typedef struct {
		uint32_t nummacros;
		uint32_t numfactions;
	} BlacklistCounts;
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
		uint32_t amount;
		uint32_t numtiers;
		bool canhire;
	} PeopleInfo;
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
		const char* name;
		int32_t skilllevel;
		uint32_t amount;
	} RoleTierData;
	typedef struct {
		uint32_t textid;
		uint32_t value;
		uint32_t relevance;
	} Skill;
	typedef struct {
		const char* id;
		const char* name;
	} SoundInfo;
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
		const char* file;
		const char* icon;
		bool ispersonal;
	} UILogo;
	typedef struct {
		const char* macro;
		uint32_t amount;
	} UIMacroCount;
	typedef struct {
		const char* id;
		const char* name;
		const char* desc;
		const char* category;
		bool enabled;
	} UINotificationType;
	typedef struct {
		const char* ID;
		const char* Name;
		const char* RawName;
		const char* Icon;
	} UIPaintTheme;
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


	// TODO: Add remaining structs
	using GetPlayerName = const char* (*)(void);

	// TODO: Add remaining funcs (and put a regex in the comments for easy replacement...)

}
