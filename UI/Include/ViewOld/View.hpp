#pragma once

namespace UI
{
struct PUBLIC_API_EXPORT View
{
    using This = View;
    String TextID {};
    Int2 Position {};
    Int2 Size {};
    Array<SharedReference<UI::View>> Views {};
    View();

    virtual ~View() {}
    template<typename T>
    void Serialize(T &&data)
    {
        data["Position"] & Position;
        data["Size"] & Size;
    }
    virtual void Layout();
    virtual void PreDraw();
    virtual void Draw();
    virtual void PostDraw();
    virtual void Update();

    void Initialize()
    {
    }
};
}
