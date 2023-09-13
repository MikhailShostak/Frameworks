#pragma once

namespace UI2
{
struct PUBLIC_API_EXPORT View
{
    using This = View;
    String TextID {};
    Int2 Position {};
    Int2 Size {};
    bool Visible {};
    Array<SharedReference<UI2::View>> Views {};
    View();

    virtual ~View() {}
    template<typename T>
    void Serialize(T &&data)
    {
        data["Position"] & Position;
        data["Size"] & Size;
        data["Visible"] & Visible;
    }
    virtual void Draw(Graphics::Scene & Scene);
    virtual void OnDraw(Graphics::Scene & Scene);

    void Initialize()
    {
    }
};
}
