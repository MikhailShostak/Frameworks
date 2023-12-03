#pragma once

#include "AEvent.h"

class AEntity;

class PUBLIC_API_EXPORT AEntityEvent : public AEvent
{
public:
    AEntityEvent(AEntity &sender);
    AEntity &getEntity() const;
};
