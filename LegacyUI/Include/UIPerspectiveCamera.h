#pragma once

#include "APerspectiveCamera.h"

namespace UI
{

class PUBLIC_API_EXPORT PerspectiveCamera : public APerspectiveCamera
{
public:
    Math::Matrix getViewMatrix() const override;
    Math::Matrix getProjectionMatrix() const override;
};

}
