#pragma once
#include <string>

// FUCK c++ enums!

namespace MessageCategory {
    using Type  = std::string ;
    Type all = "all";
    Type highprio = "highprio";
    Type lowprio = "lowprio";

    inline bool is_valid(const Type& type) { return type == all || type == highprio || type == lowprio; }
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
        return type == all || type == general || type == missions || type == news || type == alerts || type == upkeep ||
               type == tips;
    }
}