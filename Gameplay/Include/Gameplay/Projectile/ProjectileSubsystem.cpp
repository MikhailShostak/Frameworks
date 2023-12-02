#include "Gameplay/Projectile/ProjectileComponent.hpp"
#include "Gameplay/Projectile/ProjectileSubsystem.hpp"

namespace Gameplay
{

void ProjectileSubsystem::UpdateScene(Graphics::Scene & Scene)
{
    ECS::Query(Scene, [&](ECS::EntityID Entity, Gameplay::ProjectileComponent& Projectile, Physics2D::PhysicsComponent& PhysicsComponent)
    {
        if (Projectile.LifetimeTimer.IsElapsed())
        {
            Scene.Registry.destroy(Entity);
        }
    });
}

}
