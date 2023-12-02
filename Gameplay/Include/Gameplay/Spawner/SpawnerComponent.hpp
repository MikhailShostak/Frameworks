#pragma once

namespace Gameplay
{
struct PUBLIC_API_EXPORT SpawnerComponent
    : public ECS::EntityComponent
{
    using This = SpawnerComponent;
    using Super = ECS::EntityComponent;
    SharedReference<ECS::EntityDefinition> Definition {};
    int32_t Amount {};
    DateTime::SecondRatio CooldownDuration {};
    DateTime::Timer<DateTime::Steady::Clock> CooldownTimer {};
    Float3 BoxExtent {};
    float OffsetRadius {};
    Array<ECS::Entity> Entities {};

    template<typename T>
    void Serialize(T &&data)
    {
        data["Definition"] & Definition;
        data["Amount"] & Amount;
        data["CooldownDuration"] & CooldownDuration;
        data["BoxExtent"] & BoxExtent;
        data["OffsetRadius"] & OffsetRadius;
    }

    void Initialize()
    {
        Super::Initialize();
    }
};
}
