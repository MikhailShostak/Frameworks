namespace Graphics
{

void RenderingSubsystem::UpdateScene(Graphics::Scene &Scene)
{
    Scene.CommandQueue.push_back(std::bind(&This::RenderScene, this, std::placeholders::_1, std::placeholders::_2));
}

void RenderingSubsystem::RenderScene(Graphics::Window &Window, Graphics::Scene &Scene)
{

}

}
