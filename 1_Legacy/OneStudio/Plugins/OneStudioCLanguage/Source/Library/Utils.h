#pragma once
#include <LegacyFoundation.hpp>

inline Array<String> quoteStrings(const Array<String> &input)
{
    Array<String> output;
    output.reserve(input.size());
    for (const String &value : input)
    {
        output.append(value.quote());
    }
    return output;
};
