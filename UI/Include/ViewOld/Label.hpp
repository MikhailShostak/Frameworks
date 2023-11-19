#pragma once

namespace Experimental::UI
{
struct PUBLIC_API_EXPORT Label
    : public UI::View
{
    using This = Label;
    using Super = UI::View;
    String Text {};

    virtual ~Label() {}
    template<typename T>
    void Serialize(T &&data)
    {
        data["Text"] & Text;
    }
    virtual void Draw();

    void Initialize()
    {
        Super::Initialize();
    }
};
}
