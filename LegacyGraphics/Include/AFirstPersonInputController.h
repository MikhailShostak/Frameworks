#pragma once

#include "AInputController.h"

class PUBLIC_API_EXPORT AFirstPersonInputController : public AInputController
{
public:
    using AInputController::AInputController;
protected:
    void onTouchDown(AWindowTouchDownEvent &event) override
    {

    }

    void onTouchMove(AWindowTouchMoveEvent &event) override
    {

    }

    void onTouchUp(AWindowTouchUpEvent &event) override
    {

    }
};
