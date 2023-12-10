#pragma once

#include <LegacyFoundation.hpp>

#include "VisualDebug.h"

class AGraphicsContext;
namespace Legacy::Graphics
{

class Material;
class Mesh;

class PUBLIC_API_EXPORT ARenderer
{
public:
    const char *debugName = nullptr;

    virtual void addMesh(const ::SharedReference<Mesh> &mesh, const ::SharedReference<MaterialInterface> &material) = 0;

    virtual void clear() = 0;
    virtual void render() = 0;
};

}