#pragma once
#include <string>

inline std::string dump_lua = R"(

return json.encode(_G)

)";