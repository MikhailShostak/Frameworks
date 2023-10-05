#pragma once

namespace
{

struct PUBLIC_API_EXPORT GraphicsSFMLReflectionType
{
    GraphicsSFMLReflectionType()
    {
        Reflection::Add<Graphics::SFMLRHIContext>("Graphics.SFMLRHIContext");
        Reflection::Add<Graphics::SFMLRHISubsystem>("Graphics.SFMLRHISubsystem");
        Reflection::Add<Graphics::SFMLSubsystem>("Graphics.SFMLSubsystem");
        Reflection::Add<Graphics::SFMLWindow>("Graphics.SFMLWindow");
    }
} inline GraphicsSFMLReflection;

}
