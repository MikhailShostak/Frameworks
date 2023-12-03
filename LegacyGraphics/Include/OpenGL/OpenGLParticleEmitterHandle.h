#pragma once

#include "AParticleEmitter.h"

#include "OpenGLPlatform.h"

class PUBLIC_API_EXPORT AOpenGLParticleEmitterHandle final : public AParticleEmitterHandle
{
    WeakReference<AParticleEmitter> emitter;
    GLuint vertexBuffer = 0;
public:
    virtual ~AOpenGLParticleEmitterHandle() { unload(); }
    virtual void draw() const;
    void load(const WeakReference<AParticleEmitter> &emitter);
    void unload();
};
