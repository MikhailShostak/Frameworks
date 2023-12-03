#pragma once

#include <LegacyFoundation.hpp>

namespace Legacy::Graphics
{

class Canvas;
class Material;
class MaterialInterface;
class Mesh;
class Texture;

namespace API
{

template<typename Object>
struct HardwareObject;

enum class PUBLIC_API_EXPORT DepthFunction
{
    Never = 0,
    Less,
    Equal,
    LessOrEqual,
    Greater,
    NotEqual,
    GreaterOrEqual,
    Always,
};

void PUBLIC_API_EXPORT load();
void PUBLIC_API_EXPORT unload();

void PUBLIC_API_EXPORT setViewport(const Math::IntegerRectangle &viewport);
void PUBLIC_API_EXPORT setBackgroundColor(const AColor &color);
void PUBLIC_API_EXPORT setBlending(bool blending);
void PUBLIC_API_EXPORT setCulling(bool culling);
void PUBLIC_API_EXPORT setUsingDepth(bool usingDepth);
void PUBLIC_API_EXPORT setWritingDepth(bool writingDepth);
void PUBLIC_API_EXPORT setDepthFunction(DepthFunction depthFuntion);
void PUBLIC_API_EXPORT clear();
void PUBLIC_API_EXPORT flush();

}

}
#if defined(DIRECT_X_API)
#include "DirectX/DirectXImplementation.h"
#else
#include "OpenGL/OpenGLImplementation.h"
#endif
