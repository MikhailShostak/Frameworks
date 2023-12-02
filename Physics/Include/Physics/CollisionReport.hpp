#pragma once

namespace Physics
{
struct PUBLIC_API_EXPORT CollisionReport
{
    using This = CollisionReport;
    ECS::Entity Entity {};
    Physics2D::PhysicsComponent* PhysicsComponent {};
    Float3 HitPoint {};

    template<typename T>
    void Serialize(T &&data)
    {
    }

    void Initialize()
    {
    }
};
}
