#pragma once

namespace
{

struct GraphicsReflectionType
{
    GraphicsReflectionType()
    {
        Reflection::Add<Graphics::Scene>("Graphics.Scene");
    }
} inline GraphicsReflection;

}
