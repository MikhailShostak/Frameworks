#pragma once

namespace
{

struct GraphicsReflectionType
{
    GraphicsReflectionType()
    {
        Reflection::Add<Graphics::Texture>("Graphics.Texture");
        Reflection::Add<Graphics::Mesh>("Graphics.Mesh");
        Reflection::Add<Graphics::Material>("Graphics.Material");
        Reflection::Add<Graphics::ShaderMetatype>("Graphics.ShaderMetatype");
        Reflection::Add<Graphics::ShaderVariable<float>>("Graphics.ShaderVariable<float>");
        Reflection::Add<Graphics::ShaderVariable<Float2>>("Graphics.ShaderVariable<Float2>");
        Reflection::Add<Graphics::ShaderVariable<Float3>>("Graphics.ShaderVariable<Float3>");
        Reflection::Add<Graphics::ShaderVariable<Float4>>("Graphics.ShaderVariable<Float4>");
        Reflection::Add<Graphics::ShaderVariable<int32_t>>("Graphics.ShaderVariable<int>");
        Reflection::Add<Graphics::ShaderVariable<Int2>>("Graphics.ShaderVariable<Int2>");
        Reflection::Add<Graphics::ShaderVariable<Int3>>("Graphics.ShaderVariable<Int3>");
        Reflection::Add<Graphics::ShaderVariable<Int4>>("Graphics.ShaderVariable<Int4>");
        Reflection::Add<Graphics::Material>("Graphics.Shader");
        Reflection::Add<Graphics::Scene>("Graphics.Scene");
    }
} inline GraphicsReflection;

}
