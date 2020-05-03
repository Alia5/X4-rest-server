const OPTIONAL_PARAMS: readonly string[] = [
    'connectionname'
] as const;

const TYPE_CONVERSIONS = {
    'const char': (p: string): string => `${p}.c_str()`,
    'float': (p: string): string => `std::stof(${p})`,
    'double': (p: string): string => `std::stol(${p})`,
    'UniverseID': (p: string): string => `std::stoll(${p})`,
    'BlacklistID': (p: string): string => `std::stoll(${p})`,
    'BuildTaskID': (p: string): string => `std::stoll(${p})`,
    'MessageID': (p: string): string => `std::stoll(${p})`,
    'MissionID': (p: string): string => `std::stoll(${p})`,
    'NPCSeed': (p: string): string => `std::stoll(${p})`,
    'TradeID': (p: string): string => `std::stoll(${p})`,
    'uint32_t': (p: string): string => `std::stoll(${p})`,
    'size_t': (p: string): string => `std::stoll(${p})`,
    'uint64_t': (p: string): string => `std::stoll(${p})`,
    'int': (p: string): string => `std::stoi(${p})`,
    'bool': (p: string): string => `std::stoi(${p})`
} as const;

const convertParams = (paramTypes: string[], paramNames: string[]): string => {
    if (!paramNames || !paramTypes) {
        return '';
    }
    if (paramNames?.length !== paramTypes?.length) {
        throw new Error('types and names array bust be same size');
    }
    return paramTypes.map((pt, i) => {
        const converterKey = Object.keys(TYPE_CONVERSIONS)
            .find((ct) => pt.trim().includes(ct)) as (keyof typeof TYPE_CONVERSIONS);
        if (!(TYPE_CONVERSIONS?.[converterKey])) {
            throw new Error('cannot create endpoint for function');
        }
        // TODO: convert structs to input
        return ((TYPE_CONVERSIONS?.[converterKey]) ? (TYPE_CONVERSIONS?.[converterKey])(paramNames[i]) : '');
    }).join(', ');
};

export const getHttpFuncsCpp = (jsonFuncStrings: string[]): string => {

    const funcs = jsonFuncStrings
        .map((func) =>
            (/(?<=json\s)(.*)?(\(PARAMS\()(.*?)(?=\))/g).exec(func)
                .filter((v, i) => i === 1 || i === 3)
        );

    return funcs.map((func) => {

        // eslint-disable-next-line no-console
        console.log(`generating Function: ${func[0]}...`);

        const paramNames = `${func[1]}, `.match(/\S+?(?=,)/g);
        const paramTypes = `${func[1]}, `.match(/\S*\s*\S+?(?=\s\S+,)/g);
        const result = [
            `server.Get("/${func[0]}", HAN_FN {`
        ];
        if (paramNames) {
            result.push(...paramNames.map((p) =>
                `        std::string ${p} = req.get_param_value("${p}");`
            ));
            result.push(...paramNames
                .filter((p) => !OPTIONAL_PARAMS.includes(p.trim()))
                .map((p) => [
                    `        if (${p}.empty())`,
                    '        {',
                    `            return BadRequest(res, "${p} must be set");`,
                    '        }'
                ].join('\n')
                )
            );
        }
        result.push(...[
            '        try {',
            `            SET_CONTENT(ffijson::${func[0]}(PARAMS(${convertParams(paramTypes, paramNames)})));`,
            '        } catch (std::exception& e) {',
            '            return BadRequest(res, e.what());',
            '        }'
        ]);
        result.push('    });');
        return result.join('\n');
    }).map((line) => `    ${line}`)
        .join('\n\n');
};
