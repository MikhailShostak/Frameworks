#pragma once

#include <LegacySystem.hpp>

inline auto RunProcess(const Array<String> &args)
{
    return OS::Process::Open(args | rngv::join(" ") | rng::to<std::string>());
}