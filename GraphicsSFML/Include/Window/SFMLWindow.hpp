#pragma once

namespace Graphics
{
struct PUBLIC_API_EXPORT SFMLWindow
    : public Graphics::Window
{
    using This = SFMLWindow;
    using Super = Graphics::Window;
    sf::RenderWindow Handle {};
    bool Initialized {};
    Int2 UnitSize {};

    virtual ~SFMLWindow() {}
    template<typename T>
    void Serialize(T &&data)
    {
    }

    void Initialize()
    {
        Super::Initialize();
    }
};
}
