#pragma once

#include <LegacyFoundation.hpp>
#include "ACommonEvents.h"
class ASpace;
class AWindow;
class AEntity;

class PUBLIC_API_EXPORT AComponent : public AObject
{
    friend class AEntity;
    AEntity &owner;
public:
    using This = AComponent;
    using Super = AObject;
    AComponent(AEntity &owner);
    virtual ~AComponent();
    AEntity &getOwner() const;
    ASpace *getSpace() const;
    AWindow *getWindow() const;

protected:
    virtual void onLoad(ALoadEvent &event);
    virtual void onUnload(AUnloadEvent &event);
    virtual void onUpdate(AUpdateEvent &event);

    virtual bool shouldReceiveUpdates() const;

private:
    void registerForUpdates();
    void unregisterForUpdates();
};
