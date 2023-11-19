#pragma once

namespace Graphics
{
struct PUBLIC_API_EXPORT Scene
{
    using This = Scene;
    DateTime::Counter<DateTime::HighResolution::Clock> FrameCounter {};
    DateTime::SecondRatio DeltaTime {};
    ECS::SceneRegistry Registry {};
    Queue<std::function<void(Graphics::Window&Window, Graphics::Scene&Scene)>> CommandQueue {};
    Scene();

    virtual ~Scene();
    template<typename T>
    void Serialize(T &&data)
    {
    }
    virtual void Execute(Graphics::Window & Window);

    void Initialize()
    {
    }
};
}
