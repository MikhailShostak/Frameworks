#pragma once

namespace ECS
{
struct PUBLIC_API_EXPORT TransformComponent
    : public ECS::EntityComponent
{
    using This = TransformComponent;
    using Super = ECS::EntityComponent;
    Graphics::Transform Transform {};

protected:
    Graphics::Transform *GetIndirectValue();
public:
    Graphics::Transform &operator*() { return *GetIndirectValue(); }
    const Graphics::Transform &operator*() const { return *ConstCast(this)->GetIndirectValue(); }
    Graphics::Transform *operator->() { return GetIndirectValue(); }
    const Graphics::Transform *operator->() const { return ConstCast(this)->GetIndirectValue(); }

    template<typename T>
    void Serialize(T &&data)
    {
        data["Transform"] & Transform;
    }

    void Initialize()
    {
        Super::Initialize();
    }
};
}
