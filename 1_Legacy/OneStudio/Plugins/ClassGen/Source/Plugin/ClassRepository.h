#pragma once

#include <LegacyExperimental.hpp>

#include "ClassDataInstance.h"

namespace LegacyClassGen
{

struct ClassRepository : public ASingleton<ClassRepository>
{
    Map<String, SharedReference<ClassDataInstance>> indexedTypes;
};

}
