#pragma once

#include <LegacyFoundation.hpp>

class OSProjectFeatureDataInstance
{

public:

    virtual ~OSProjectFeatureDataInstance() {}

    virtual void build(const APath &projectPath) = 0;
    virtual void clean(const APath &projectPath) = 0;

};
