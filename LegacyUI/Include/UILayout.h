#pragma once

#include <LegacyFoundation.hpp>

namespace UI
{

class View;

class PUBLIC_API_EXPORT Layout : public AObject
{
public:
    virtual ~Layout() {}

    virtual void load(View &parent) {}
    virtual void unload() {}

    virtual Math::IntegerVector getContentSize() const = 0;

    virtual void onLayout(View &view) = 0;
};

}
