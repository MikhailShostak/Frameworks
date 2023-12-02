#pragma once

namespace Gameplay
{
struct PUBLIC_API_EXPORT ProjectileComponent
    : public ECS::EntityComponent
{
    using This = ProjectileComponent;
    using Super = ECS::EntityComponent;
    DateTime::Seconds LifetimeDuration {};
    DateTime::Timer<DateTime::Steady::Clock> LifetimeTimer {};

    template<typename T>
    void Serialize(T &&data)
    {
        data["LifetimeDuration"] & LifetimeDuration;
    }

    void Initialize()
    {
        Super::Initialize();
    }
};
}
