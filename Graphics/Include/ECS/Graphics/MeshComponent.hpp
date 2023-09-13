#pragma once

namespace ECS
{
struct PUBLIC_API_EXPORT MeshComponent
    : public ECS::EntityComponent
{
    using This = MeshComponent;
    using Super = ECS::EntityComponent;
    SharedReference<Graphics::Mesh> Mesh = {};
    SharedReference<Graphics::Material> Material = {};
    bool Visible = {};

    template<typename T>
    void Serialize(T &&data)
    {
        data["Mesh"] & Mesh;
        data["Material"] & Material;
        data["Visible"] & Visible;
    }

    void Initialize()
    {
        Super::Initialize();
        {
            String data =
R"(
true
)";
            Serialization::FromString(data, Visible);
        }
    }
};
}
