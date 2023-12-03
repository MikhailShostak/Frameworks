#pragma once

namespace ECS
{
struct PUBLIC_API_EXPORT UITextComponent
    : public ECS::EntityComponent
{
    using This = UITextComponent;
    using Super = ECS::EntityComponent;
    String Text = {};

    template<typename T>
    void Serialize(T &&data)
    {
        data["Text"] & Text;
    }

    void Initialize()
    {
        Super::Initialize();
    }
};
}
