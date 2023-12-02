#include "Gameplay/Factions/FactionRelation.hpp"
#include "Gameplay/Factions/FactionDefinition.hpp"
#include "Gameplay/Factions/FactionComponent.hpp"

namespace Gameplay
{

FactionDefinition *FactionComponent::GetIndirectValue()
{
    return Definition.get();
}

}