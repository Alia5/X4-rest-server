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
	
}