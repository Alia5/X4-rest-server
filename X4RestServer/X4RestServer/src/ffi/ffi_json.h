#pragma once

#include <nlohmann/json.hpp>
#include "../ffi/FFIInvoke.h"
#include "../__generated__/ffi_funcs.h"

using json = nlohmann::json;

#define Q(x) #x
#define QUOTE(x) Q(x)

#define invoke(FuncName, ...) \
  ffi_invoke.invokeFn<X4FFI::FuncName>(QUOTE(FuncName), __VA_ARGS__);

#define PARAMS(...) \
	FFIInvoke& ffi_invoke, __VA_ARGS__

// ---

namespace JSONIMPL
{
	using namespace X4FFI;

    //         using GetDefaultOrder = bool (*)(Order* result, UniverseID controllableid);

	
    json GetDefaultOrder(PARAMS(UniverseID controllableid))
    {
        Order order;
        const auto res = invoke(GetDefaultOrder, &order, controllableid);
    	if (res)
    	{
            return json
            {
                {"success", res},
                {"order", {
                    {"queueidx", order.queueidx},
                    {"state", order.state},
                    {"statename", order.statename},
                    {"orderdef", order.orderdef},
                    {"actualparams", order.actualparams},
                    {"enabled", order.enabled},
                    {"isinfinite", order.isinfinite},
                    {"issyncpointreached", order.issyncpointreached},
                    {"istemporder", order.istemporder}
                }}
            };
    	}
 
        return json
        {
            {"success", res}
        };
    }


	//     using GetAllFactions = uint32_t (*)(const char** result, uint32_t resultlen, bool includehidden);

	json GetAllFactions(PARAMS(bool includehidden))
    {
        std::vector<const char*> result;
        result.resize(10000);
        const auto func_res = invoke(GetAllFactions, result.data(), result.size(), includehidden);
    	if (func_res)
    	{
            result.resize(func_res);
            return json
    		{
                {"value", func_res},
            	{"result", result}
            };
    	}

        return json
        {
            {"value", func_res}
        };
    }

	//     using GetFormationShapes = uint32_t (*)(UIFormationInfo* result, uint32_t resultlen);

    //typedef struct {
    //    const char* shape;
    //    const char* name;
    //    uint32_t requiredSkill;
    //    float radius;
    //    bool rollMembers;
    //    bool rollFormation;
    //    size_t maxShipsPerLine;
    //} UIFormationInfo;
	
    json GetFormationShapes(PARAMS())
    {
        std::vector<UIFormationInfo> result;
        result.resize(10000);
        const auto func_res = invoke(GetFormationShapes, result.data(), result.size());
        if (func_res)
        {
            result.resize(func_res);
            std::vector<json> json_result;
        	for (auto& v : result)
        	{
                json_result.push_back({
                    {"shape", v.shape},
                    {"name", v.name},
                    {"requiredSkill", v.requiredSkill},
                    {"radius", v.radius},
                    {"rollMembers", v.rollMembers},
                    {"rollFormation", v.rollFormation},
                    {"maxShipsPerLine", v.maxShipsPerLine}
                });
        	}
            return json
        	{
                {"value", func_res},
                {"result", json_result}
            };
        }

        return json
        {
            {"value", func_res}
        };
    }
	
}