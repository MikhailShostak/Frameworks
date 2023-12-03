#pragma once

#include "View.gen.h"

namespace UI
{

class PUBLIC_API_EXPORT SuggestionsAdapter
{
public:
    virtual void requestSuggestions(const String &text) = 0;
    virtual SharedReference<View> getView() const = 0;
};

}
