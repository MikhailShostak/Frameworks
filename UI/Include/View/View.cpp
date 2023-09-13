
namespace UI2
{

View::View()
{
    Visible = true;
}

void View::Draw(Graphics::Scene & Scene)
{
    if (!Visible)
    {
        return;
    }

    for (auto &View : Views)
    {
        View->Draw(Scene);
    }

    OnDraw(Scene);
}

void View::OnDraw(Graphics::Scene & Scene)
{

}

}
