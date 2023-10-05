#pragma once

namespace
{

struct AppFlowReflectionType
{
    AppFlowReflectionType()
    {
        Reflection::Add<AppFlow::AppFlowSubsystem>("AppFlow.AppFlowSubsystem");
    }
};

inline static AppFlowReflectionType AppFlowReflection;

}
