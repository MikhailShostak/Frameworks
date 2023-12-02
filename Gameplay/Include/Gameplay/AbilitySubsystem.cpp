#include "Gameplay/AbilitySubsystem.hpp"
#include "Gameplay/AbilityComponent.hpp"
#include "Graphics/TransformComponent.hpp"

namespace Gameplay
{

void AbilitySubsystem::UpdateScene(Graphics::Scene &Scene)
{
    ECS::Query(Scene, [&Scene](Gameplay::AbilityComponent &Ability, ECS::TransformComponent &Transform)
    {

    });
}

}