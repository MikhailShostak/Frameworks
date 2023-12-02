#pragma once

struct PUBLIC_API_EXPORT GameModeSubsystem
    : public Graphics::SceneSubsystem
{
    using This = GameModeSubsystem;
    using Super = Graphics::SceneSubsystem;

    virtual ~GameModeSubsystem() {}
    template<typename T>
    void Serialize(T &&data)
    {
    }

    void Initialize()
    {
        Super::Initialize();
    }
};
