#pragma once

#include "Gameplay/Projectile/ProjectileComponent.hpp"
#include "Gameplay/AbilityComponent.hpp"

namespace Gameplay
{

inline ECS::Entity LaunchProjectile(Graphics::Scene &Scene, const ECS::EntityDefinition &Definition, const Graphics::Transform &Transform, const Float3 &Velocity, Array<Physics2D::PhysicsComponent*> IgnoreList = {})
{
    auto Entity = ECS::CreateEntity(Scene, Definition);
    
    Entity.GetComponent<ECS::TransformComponent>().Transform = Transform;

    auto &PhysicsComponent = Entity.GetComponent<Physics2D::PhysicsComponent>();
    PhysicsComponent.InitialLinearVelocity = Velocity;
    PhysicsComponent.IgnoreList = std::move(IgnoreList);
    PhysicsComponent.OnHit.push_back([Entity](const Physics::CollisionReport &Report)
    {
        if (AbilityComponent* AbilityComponent = Report.Entity.FindComponent<Gameplay::AbilityComponent>(); AbilityComponent)
        {
            Report.Entity.Destroy();
        }
        Entity.Destroy();
    });

    auto &Projectile = Entity.GetComponent<Gameplay::ProjectileComponent>();
    Projectile.LifetimeTimer.Start(Projectile.LifetimeDuration);

    return Entity;
}

inline ECS::Entity LaunchProjectile(Graphics::Scene &Scene, const StringID &EntityID, const Graphics::Transform &Transform, const Float3 &Velocity, Array<Physics2D::PhysicsComponent*> IgnoreList = {})
{
    SharedReference<ECS::EntityDefinition> Definition = RuntimeAssetStorage::Find<ECS::EntityDefinition>(EntityID);
    return LaunchProjectile(Scene, *Definition, Transform, Velocity, IgnoreList);
}

}
