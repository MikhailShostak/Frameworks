#pragma once

#include <LegacyFoundation.hpp>

class PUBLIC_API_EXPORT Controller : public AObject
{
public:
    virtual void onActivate() {}
    virtual void onDeactivate() {}
};
