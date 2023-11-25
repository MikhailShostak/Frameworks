#include "Graphics/TransformComponent.hpp"

namespace ECS
{

Graphics::Transform *TransformComponent::GetIndirectValue()
{
    return &Transform;
}

}