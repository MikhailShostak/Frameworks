#pragma once

namespace Graphics
{
PUBLIC_API_EXPORT Array<Scene*> &GetScenes();
}

namespace ECS
{

template<typename FunctionType, typename Type, typename ReturnType, typename ...Types>
inline void QueryInternal(Graphics::Scene &Scene, const FunctionType &Handle, ReturnType(Type::*f)(Types &...) const)
{
    Scene.Registry.view<Types...>().each(Handle);
}

template<typename FunctionType>
inline void Query(Graphics::Scene &Scene, const FunctionType &Handle)
{
    QueryInternal(Scene, Handle, &FunctionType::operator());
}

}
