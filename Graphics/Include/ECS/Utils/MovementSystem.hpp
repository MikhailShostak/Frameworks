#pragma once

namespace ECS
{
struct PUBLIC_API_EXPORT MovementSystem
    : public ECS::System
{
    using This = MovementSystem;
    using Super = ECS::System;

    template<typename T>
    void Serialize(T &&data)
    {
    }
    virtual void OnUpdate(EScene & Scene);

    void Initialize()
    {
        Super::Initialize();
    }
};
}
