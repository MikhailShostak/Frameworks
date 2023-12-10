#pragma once

struct EditorWindow
    : public SceneWindowComponent
{
    using This = EditorWindow;
    using Super = SceneWindowComponent;
    SharedReference<System::ConfigFile<EditorConfig>> Config = {};

    virtual ~EditorWindow() {}
    template<typename T>
    void Serialize(T &&data)
    {
        data["Config"] & Config;
    }
    virtual void Load(Core::Application & Application);
    virtual void Unload(Core::Application & Application);
    virtual void CreateUI();
    virtual void Render();
    virtual void Draw();

    void Initialize()
    {
        Super::Initialize();
    }
};