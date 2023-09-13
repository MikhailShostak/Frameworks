namespace Graphics
{

void SceneSubsystem::Update()
{
    for (auto &Scene : GetScenes())
    {
        UpdateScene(*Scene);
    }
}

void SceneSubsystem::UpdateScene(Graphics::Scene & Scene)
{
    
}

}
