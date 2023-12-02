#include "Gameplay/Factions/FactionRelation.hpp"
#include "Gameplay/Factions/FactionDefinition.hpp"

namespace Gameplay
{

bool/*Result*/ FactionDefinition::IsAlly(const StringID &Faction)
{
    return Name == Faction || ArrayUtils::Contains(Allies, Faction);
}

bool/*Result*/ FactionDefinition::IsEnemy(const StringID &Faction)
{
    return ArrayUtils::Contains(Enemies, Faction);
}

bool/*Result*/ FactionDefinition::IsNeutral(const StringID &Faction)
{
    return !IsAlly(Faction) && !IsEnemy(Faction);
}

Gameplay::FactionRelation/*Result*/ FactionDefinition::GetRelation(const StringID &Faction)
{
    if (IsAlly(Faction))
    {
        return Gameplay::FactionRelation::Ally;
    }
    else if (IsEnemy(Faction))
    {
        return Gameplay::FactionRelation::Enemy;
    }
    return Gameplay::FactionRelation::Neutral;
}

}