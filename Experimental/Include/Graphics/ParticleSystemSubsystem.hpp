#pragma once

#include "Graphics/.Graphics.hpp"
#include "Graphics/TransformComponent.hpp"
#include "Graphics/ParticleSystemComponent.hpp"

namespace Graphics2D
{

class ParticleSystemSubsystem : public Graphics::RenderingSubsystem
{
public:
    void Load() override
    {

    }

    void RenderScene(Graphics::Window &Window, Graphics::Scene &Scene) override
    {
        /*auto SFMLWindow = DynamicCast<Graphics::SFMLWindow>(&Window);
        ECS::Query(Scene, [&](const ECS::TransformComponent& Transform, Graphics2D::ParticleSystemComponent& ParticleSystem)
        {
            ParticleSystem.particles.setEmitter(sfVector(Transform->Position.xy));
            ParticleSystem.particles.update(Scene.DeltaTime.count());
            SFMLWindow->Handle.draw(ParticleSystem.particles);
        });*/
    }
};

}
