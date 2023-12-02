#pragma once

namespace Gameplay
{
struct PUBLIC_API_EXPORT PlatformerMovementComponent
    : public ECS::EntityComponent
{
    using This = PlatformerMovementComponent;
    using Super = ECS::EntityComponent;
    float Damping { 10 };
    float Speed { 50000 };
    float DashStrength { 5 };
    bool Dash {};
    bool Jump {};

    template<typename T>
    void Serialize(T &&data)
    {
        data["Damping"] & Damping;
        data["Speed"] & Speed;
        data["DashStrength"] & DashStrength;
    }

    void Initialize()
    {
        Super::Initialize();
    }
};
}
