namespace Graphics
{
Array<Scene*> &GetScenes()
{
    static Array<Scene*> Scenes;
    return Scenes;
}
}
