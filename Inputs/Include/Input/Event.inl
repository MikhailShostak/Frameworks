#pragma once

namespace Input
{

inline Graphics::Scene&/*GetScene*/ Event::GetScene() const
{
    return *Window->Scene;
}

}
