#pragma once

namespace Gameplay
{
struct PUBLIC_API_EXPORT FactionComponent
    : public ECS::EntityComponent
{
    using This = FactionComponent;
    using Super = ECS::EntityComponent;
    SharedReference<FactionDefinition> Definition {};

protected:
    FactionDefinition *GetIndirectValue();
public:
    FactionDefinition &operator*() { return *GetIndirectValue(); }
    const FactionDefinition &operator*() const { return *ConstCast(this)->GetIndirectValue(); }
    FactionDefinition *operator->() { return GetIndirectValue(); }
    const FactionDefinition *operator->() const { return ConstCast(this)->GetIndirectValue(); }

    template<typename T>
    void Serialize(T &&data)
    {
        data["Definition"] & Definition;
    }

    void Initialize()
    {
        Super::Initialize();
    }
};
}
