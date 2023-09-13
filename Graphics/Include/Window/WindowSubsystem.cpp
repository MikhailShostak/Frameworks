#include "Window/Window.hpp"

namespace Graphics
{

SharedReference<Graphics::Window> WindowSubsystem::Create()
{
    auto Window = SharedReference<Graphics::Window>(WindowClass->Create());
    Window->RHIContext = UniqueReference<Graphics::RHIContext>(RHIContextClass->Create());
    ArrayUtils::Add(Windows, Window);
    return Window;
}

}
