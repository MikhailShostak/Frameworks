#pragma once

#include "StateMachine.h"
#include "Controllers/Controller.h"
#include "Assets.h"

template<typename BundleType, size_t assetID>
class PUBLIC_API_EXPORT ControllerState : public AObject, public State
{
    ::SharedReference<Controller> controller = BundleType::getInstance().findObject<Controller>(assetID);
public:

    void onEnter(StateMachine &stateMachine) override
    {
        AAssert(controller, "Controller is not set");
        controller->onActivate();
    }

    void onExit(StateMachine &stateMachine) override
    {
        AAssert(controller, "Controller is not set");
        controller->onDeactivate();
    }
};
