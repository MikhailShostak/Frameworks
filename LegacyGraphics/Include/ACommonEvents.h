#pragma once

#include <LegacyFoundation.hpp>

class PUBLIC_API_EXPORT ACreateEvent : public AEvent
{
public:
    using AEvent::AEvent;
};

class PUBLIC_API_EXPORT ADestroyEvent : public AEvent
{
public:
    using AEvent::AEvent;
};

class PUBLIC_API_EXPORT AUpdateEvent : public AEvent
{
public:
    using AEvent::AEvent;
};

class PUBLIC_API_EXPORT ASaveEvent : public AEvent
{
public:
    using AEvent::AEvent;
};

class PUBLIC_API_EXPORT ALoadEvent : public AEvent
{
public:
    using AEvent::AEvent;
};

class PUBLIC_API_EXPORT AUnloadEvent : public AEvent
{
public:
    using AEvent::AEvent;
};

class PUBLIC_API_EXPORT ATransformEvent : public AEvent
{
public:
    using AEvent::AEvent;
};

class PUBLIC_API_EXPORT AShowEvent : public AEvent
{
public:
    using AEvent::AEvent;
};

class PUBLIC_API_EXPORT AHideEvent : public AEvent
{
public:
    using AEvent::AEvent;
};

class PUBLIC_API_EXPORT ACloseEvent : public AEvent
{
public:
    using AEvent::AEvent;
};

class PUBLIC_API_EXPORT AFocusInEvent : public AEvent
{
public:
    using AEvent::AEvent;
};

class PUBLIC_API_EXPORT AFocusOutEvent : public AEvent
{
public:
    using AEvent::AEvent;
};

class PUBLIC_API_EXPORT AMinimizeEvent : public AEvent
{
public:
    using AEvent::AEvent;
};

class PUBLIC_API_EXPORT AMaximizeEvent : public AEvent
{
public:
    using AEvent::AEvent;
};

template<typename Type>
class PUBLIC_API_EXPORT UIPropertyChangeEvent : public AEvent
{
    Type value;
public:

    UIPropertyChangeEvent(AObject &sender, const Type &value):
        AEvent(sender),
        value(value)
    {}

    UIPropertyChangeEvent(AObject &sender, Type &&value):
        AEvent(sender),
        value(std::move(value))
    {}

    const Type &getValue() const { return this->value; }
};

class PUBLIC_API_EXPORT UITitleChangeEvent : public UIPropertyChangeEvent<String>
{
public:
    using Super = UIPropertyChangeEvent<String>;
    using Super::Super;
};

class PUBLIC_API_EXPORT UIMoveEvent : public UIPropertyChangeEvent<Math::IntegerVector>
{
public:
    using Super = UIPropertyChangeEvent<Math::IntegerVector>;
    using Super::Super;
};

class PUBLIC_API_EXPORT UIResizeEvent : public UIPropertyChangeEvent<Math::IntegerVector>
{
public:
    using Super = UIPropertyChangeEvent<Math::IntegerVector>;
    using Super::Super;
};

class PUBLIC_API_EXPORT UIGeometryChangeEvent : public UIPropertyChangeEvent<Math::IntegerRectangle>
{
public:
    using Super = UIPropertyChangeEvent<Math::IntegerRectangle>;
    using Super::Super;
};
