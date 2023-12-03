#pragma once

#include <LegacyFoundation.hpp>

class AGraphicsContext;

class PUBLIC_API_EXPORT AGraphicsEvent : public AEvent
{
public:
    AGraphicsEvent(AGraphicsContext &sender);
    AGraphicsContext &getContext() const;
};

class PUBLIC_API_EXPORT AUpdateGraphicsEvent : public AGraphicsEvent
{
public:

    enum UpdateType
    {
        UpdateColor,
        UpdateViewort,
        UpdateCamera,
        UpdateBlending,
        UpdateCulling,
        UpdateWritingDepth,
        UpdateUsingDepth,
        UpdateDepthFunction,
    };

private:
    UpdateType type;

public:
    AUpdateGraphicsEvent(AGraphicsContext &sender, UpdateType type);
    UpdateType getType() const;
};

class PUBLIC_API_EXPORT AClearGraphicsEvent : public AGraphicsEvent
{
public:
    using AGraphicsEvent::AGraphicsEvent;
};

class PUBLIC_API_EXPORT ADrawGraphicsEvent : public AGraphicsEvent
{
public:
    using AGraphicsEvent::AGraphicsEvent;
};

class PUBLIC_API_EXPORT AFlushGraphicsEvent : public AGraphicsEvent
{
public:
    using AGraphicsEvent::AGraphicsEvent;
};
