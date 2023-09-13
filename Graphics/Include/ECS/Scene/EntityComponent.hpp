#pragma once

namespace ECS
{
struct PUBLIC_API_EXPORT EntityComponent
{
    using This = EntityComponent;
    bool Reserved = {};

    virtual ~EntityComponent() {}
    template<typename T>
    void Serialize(T &&data)
    {
    }

    void Initialize()
    {
    }
};
}
