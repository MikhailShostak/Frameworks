#include ".Graphics.hpp"

#include <GLFW/glfw3.h>

namespace MapUtils
{

template<typename KeyType, typename ValueType>
auto &FindOrAdd(Map<KeyType, ValueType> &Map, const KeyType &Key)
{
    auto It = Map.find(Key);
    if (It == Map.end())
    {
        It = Map.insert({ Key, ValueType() }).first;
    }
    return It->second;
}

template<typename KeyType, typename ValueType>
const auto &FindOrAdd(const Map<KeyType, ValueType> &Map, const KeyType &Key)
{
    auto It = Map.find(Key);
    if (It == Map.end())
    {
        It = Map.insert({ Key, ValueType() }).first;
    }
    return It->second;
}

}

namespace Graphics
{

Map<Graphics::Window*, GLFWwindow*> Handles;
inline static const Int2 WindowSize = { 800, 480};

void GLFWSubsystem::Load()
{
    Input = Core::FindSubsystem<Input::Subsystem>();
    
    if (glfwInit() != GLFW_TRUE)
    {
        return;
    }
}

void GLFWSubsystem::Update()
{
    /*for (auto &W : Windows)
    {
        GLFWwindow *&Window = MapUtils::FindOrAdd(Handles, W.get());
        if (!Window)
        {
            Window = glfwCreateWindow(Window->Size[0], Window->Size[1], Window->Title.data(), nullptr, nullptr);
            //UpdateScreenSurface(Window, WindowSize[0], WindowSize[1]);
        }

        if (!glfwWindowShouldClose(Window))
        {
            glfwPollEvents();
            
            int width, height;
            glfwGetWindowSize(Window, &width, &height);

            glViewport(0, 0, width, height);
            glClear(GL_COLOR_BUFFER_BIT);

            // Draw shape here (e.g., OpenGL calls for drawing a rectangle)
            
            glfwSwapBuffers(Window);

            // Event handling
            // This part has to be set up using GLFW callbacks for event handling (glfwSetKeyCallback, etc.)
        }
        else
        {
            glfwDestroyWindow(Window);
            Window = nullptr;
        }
    }*/
}

void GLFWSubsystem::Unload()
{
    
}

}
