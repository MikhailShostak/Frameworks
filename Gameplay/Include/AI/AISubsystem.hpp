#pragma once

namespace AI
{
struct PUBLIC_API_EXPORT AISubsystem
    : public Graphics::SceneSubsystem
{
    using This = AISubsystem;
    using Super = Graphics::SceneSubsystem;
    DateTime::SecondRatio UpdateRate {};
    DateTime::Timer<DateTime::Steady::Clock> UpdateTimer {};

    virtual ~AISubsystem() {}
    template<typename T>
    void Serialize(T &&data)
    {
        data["UpdateRate"] & UpdateRate;
    }
    virtual void UpdateScene(Graphics::Scene & Scene);

    void Initialize()
    {
        Super::Initialize();
    }
};
}
