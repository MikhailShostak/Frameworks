#pragma once

struct PUBLIC_API_EXPORT EScene
{
    using This = EScene;
    ECS::SceneRegistry Registry = {};
    DateTime::SecondRatio DeltaTime;

    template<typename T>
    void Serialize(T &&data)
    {
    }

    void Initialize()
    {
    }
};
