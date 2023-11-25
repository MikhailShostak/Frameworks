#pragma once

namespace ECS
{
struct PUBLIC_API_EXPORT GraphicsSystem
    : public Graphics::SceneSubsystem
{
    using This = GraphicsSystem;
    using Super = Graphics::SceneSubsystem;
    Graphics::DrawBatch<hlslpp::float4x4> Transforms = {};
    Graphics::RenderTarget GBuffer = {};
    ECS::Entity CurrentCamera = {};
    Array<UniqueReference<ECS::PostProcessStep>> PostProcessSteps = {};
    StaticArray<Graphics::RenderTarget, 2> RenderTargets = {};
    size_t CurrentTarget = {};

    template<typename T>
    void Serialize(T &&data)
    {
        data["CurrentCamera"] & CurrentCamera;
        data["PostProcessSteps"] & PostProcessSteps;
    }
    virtual void OnLoad(EScene & Scene);
    virtual void OnUnload(EScene & Scene);
    virtual void OnUpdate(EScene & Scene);
    virtual void Render(EScene & Scene);

    void Initialize()
    {
        Super::Initialize();
    }
};
}
