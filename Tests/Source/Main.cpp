

AStaticRun(Test)
{
    static std::unique_ptr<UI::ViewWindow> instance{ Create<UI::ViewWindow>()};
    instance->show();
    instance->setGeometry(Math::IntegerRectangle{500, 500, 800, 480});
    auto ImageView = CreateShared<UI::ImageView>();
    ImageView->setImage(::ClosedFolderIcon);
    instance->setView(ImageView);
    instance->onClosed = [](){ UIApplication::getInstance().stop(); };
    Log::Print("Test");
}

int main()
{
    UIApplication application;
    return application.execute().getErrorCode();
}
