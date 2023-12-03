#pragma once

class AObject;

class PUBLIC_API_EXPORT AEvent
{

    AObject &sender;

public:

    AEvent(AObject &sender):
        sender(sender)
    {}

    virtual ~AEvent() {}

    AObject &getSender() const
    {
        return sender;
    }

};

class PUBLIC_API_EXPORT AAcceptableEvent : public AEvent
{
    bool accepted = false;
public:

    using AEvent::AEvent;

    bool isAccepted() const
    {
        return accepted;
    }

    void accept()
    {
        accepted = true;
    }

    void reject()
    {
        accepted = false;
    }
};
