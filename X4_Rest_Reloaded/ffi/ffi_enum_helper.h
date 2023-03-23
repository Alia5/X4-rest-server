#pragma once
#include <string>

// FUCK c++ enums!

namespace MessageCategory {
    using Type = std::string;
    Type all = "all";
    Type highprio = "highprio";
    Type lowprio = "lowprio";

    inline bool is_valid(const Type& type) {
        return type == all || type == highprio || type == lowprio;
    }
}

namespace LogbookCategory {
    using Type = std::string;
    Type all = "all";
    Type general = "general";
    Type missions = "missions";
    Type news = "news";
    Type alerts = "alerts";
    Type upkeep = "upkeep";
    Type tips = "tips";

    inline bool is_valid(const Type& type) {
        return type == all || type == general || type == missions || type == news ||
               type == alerts || type == upkeep || type == tips;
    }
}

namespace ComponentClasses {
    using Type = std::string;
    Type ship = "ship";
    Type ship_xs = "ship_xs";
    Type ship_s = "ship_s";
    Type ship_m = "ship_m";
    Type ship_l = "ship_l";
    Type ship_xl = "ship_xl";
    Type station = "station";
    Type controllable = "controllable";
    Type isdeployable = "isdeployable";
    Type lockbox = "lockbox";
    Type container = "container";
    Type object = "object";
    Type sector = "sector";
    Type gate = "gate";
    Type mine = "mine";
    Type navbeacon = "navbeacon";
    Type resourceprobe = "resourceprobe";
    Type satellite = "satellite";
    Type asteroid = "asteroid";
    Type collectablewares = "collectablewares";

    inline bool is_valid(const Type& type) {
        return type == ship || type == ship_xs || type == ship_s || type == ship_m ||
               type == ship_l || type == ship_xl || type == station || type == controllable ||
               type == isdeployable || type == lockbox || type == container || type == object ||
               type == sector || type == gate || type == mine || type == navbeacon ||
               type == resourceprobe || type == satellite || type == asteroid ||
               type == collectablewares;
    }
}