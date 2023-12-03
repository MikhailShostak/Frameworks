#pragma once

#include <LegacyFoundation.hpp>

namespace Legacy::Graphics
{
class Mesh;
class Texture;
}
class AParticleEmitter;

/*class APlatformGraphicsContext
{

public:

    virtual ~APlatformGraphicsContext() {}

    virtual void applyViewPort(const Math::IntegerRectangle &rectangle) const = 0;
    virtual void applyClearColor(const AColor &color) = 0;

    virtual void setBlending(bool blending) = 0;
    virtual void setCulling(bool culling) = 0;

    virtual void clear() const = 0;
    virtual void flush() const = 0;

    virtual void load(const WeakReference<AMesh> &mesh) const = 0;
    virtual void load(const WeakReference<AMaterial> &material) const = 0;
    virtual void load(const WeakReference<Texture> &texture) const = 0;
    virtual void load(const WeakReference<AParticleEmitter> &emitter) const = 0;

};*/

class AWindow;
class AGraphicsContext;

class PUBLIC_API_EXPORT APlatform
{
public:
    virtual ~APlatform() {}

    virtual AError main(ARunnable &runnable) = 0;
    virtual void stop(const AError &error = AError::getEmptyError()) = 0;

    virtual UniqueReference<AObject> createWindow(AWindow &owner) const = 0;
    virtual UniqueReference<AObject> createGraphicsContext(AGraphicsContext &owner) const = 0;
};

PUBLIC_API_EXPORT APlatform &APlatformInstance();
PUBLIC_API_EXPORT void SetPlatformInstance(APlatform &platform);

#define ARegisterPlatform(Platform, Window, GraphicsContext)\
class PUBLIC_API_EXPORT Platform : public APlatform\
{\
public:\
    AError main(ARunnable &runnable) override;\
    void stop(const AError &error = AError::getEmptyError()) override;\
    UniqueReference<AObject> createWindow(AWindow &owner) const override { return UniqueReference<AObject>(new Window(owner)); }\
    UniqueReference<AObject> createGraphicsContext(AGraphicsContext &owner) const override { return UniqueReference<AObject>(new GraphicsContext(owner)); }\
};\
AStaticRun(Platform){ static Platform platform; SetPlatformInstance(platform); }
