namespace Graphics
{

Scene::Scene()
{
    ArrayUtils::Add(GetScenes(), this);
}

Scene::~Scene()
{
    ArrayUtils::Remove(GetScenes(), this);
}

void Scene::Execute(Graphics::Window & Window)
{
    DeltaTime = FrameCounter.CountAs<DateTime::SecondRatio>();
    while (!CommandQueue.empty())
    {
        const auto &command = CommandQueue.front();
        command(Window, *this);
        CommandQueue.pop_front();
    }
}

}
