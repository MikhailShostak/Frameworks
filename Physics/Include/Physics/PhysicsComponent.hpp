#pragma once

namespace Physics2D
{
struct PUBLIC_API_EXPORT PhysicsComponent
    : public ECS::EntityComponent
{
    using This = PhysicsComponent;
    using Super = ECS::EntityComponent;
    Array<Physics2D::PhysicsComponent*> IgnoreList {};
    float Radius { 0.1f };
    Float3 InitialLinearVelocity {};
    float InitialAngularVelocity {};
    b2Body* Body {};
    b2BodyType BodyType { b2BodyType::b2_dynamicBody };
    b2MassData MassData {};
    Array<Physics::CollisionReportCallback> OnHit {};

    template<typename T>
    void Serialize(T &&data)
    {
        data["Radius"] & Radius;
    }

    void Initialize()
    {
        Super::Initialize();
    }
};
}
