#pragma once

#include <LegacyFoundation.hpp>

#include "ACamera.h"

class PUBLIC_API_EXPORT APerspectiveCamera : public ACamera
{

public:

    float fieldOfView = 45.0f;
    float nearClipping = 0.1f;
    float farClipping = 100.0f;

    Math::Matrix getProjectionMatrix() const
    {
        return Math::Matrix::getPerspective(resolution.getXYAspectRatio(), fieldOfView, nearClipping, farClipping);
    }

};