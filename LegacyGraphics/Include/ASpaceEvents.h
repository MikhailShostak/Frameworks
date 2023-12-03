#pragma once

#include "AEvent.h"

class ASpace;

class PUBLIC_API_EXPORT ASpaceEvent : public AEvent
{
public:
    ASpaceEvent(ASpace &sender);
    ASpace &getSpace() const;
};

class PUBLIC_API_EXPORT AAddToSpaceEvent : public ASpaceEvent
{
public:
    using ASpaceEvent::ASpaceEvent;
};

class PUBLIC_API_EXPORT ARemoveFromSpaceEvent : public ASpaceEvent
{
public:
    using ASpaceEvent::ASpaceEvent;
};
