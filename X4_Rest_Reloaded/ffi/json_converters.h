#pragma once
#include <nlohmann/json.hpp>

#include "x4ffi/ffi_typedef_struct.h"

using json = nlohmann::json;

namespace X4FFI {
    inline void to_json(json& j, const MessageInfo& m) {
        j = nlohmann::json{
            {"id", m.id},
            {"time", m.time},
            {"category", m.category},
            {"title", m.title},
            {"text", m.text},
            {"source", m.source},
            {"sourcecomponent", m.sourcecomponent},
            {"interaction", m.interaction},
            {"interactioncomponent", m.interactioncomponent},
            {"interactiontext", m.interactiontext},
            {"interactionshorttext", m.interactionshorttext},
            {"cutscenekey", m.cutscenekey},
            {"entityname", m.entityname},
            {"factionname", m.factionname},
            {"money", m.money},
            {"bonus", m.bonus},
            {"highlighted", m.highlighted},
            {"isread", m.isread},
        };
    }

    inline void to_json(json& j, const UIPosRot& m) {
        j = nlohmann::json{{"x", m.x}, {"y", m.y}, {"z", m.z}, {"pitch", m.pitch},
            {"yaw", m.yaw}, {"roll", m.roll}};
    };

    inline void to_json(json& j, const SofttargetDetails& s) {
        j = nlohmann::json{
            {"softtargetID", s.softtargetID},
            {"softtargetConnectionName", s.softtargetConnectionName},
        };
    }
    inline void to_json(json& j, const RaceInfo& r) {
        j = nlohmann::json{{"id", r.id}, {"name", r.name}, {"shortname", r.shortname},
            {"description", r.description}, {"icon", r.icon}};
    }
}
