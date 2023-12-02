#pragma once

namespace Gameplay
{
struct PUBLIC_API_EXPORT GameModeSubsystem
    : public Graphics::SceneSubsystem
{
    using This = GameModeSubsystem;
    using Super = Graphics::SceneSubsystem;
    SharedReference<Input::Context> PlayerInputContexts {};

    virtual ~GameModeSubsystem() {}
    template<typename T>
    void Serialize(T &&data)
    {
        data["PlayerInputContexts"] & PlayerInputContexts;
    }

    void Initialize()
    {
        Super::Initialize();
    }
};
}
