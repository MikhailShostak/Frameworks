#pragma once

#include "Gameplay/Projectile/ProjectileComponent.hpp"
#include "Gameplay/Projectile/ProjectileSubsystem.hpp"
#include "Gameplay/TopDown/TopDownMovementComponent.hpp"
#include "Gameplay/TopDown/TopDownMovementSubsystem.hpp"
#include "Gameplay/AbilityComponent.hpp"
#include "Gameplay/AbilitySubsystem.hpp"
#include "Gameplay/Factions/FactionRelation.hpp"
#include "Gameplay/Factions/FactionDefinition.hpp"
#include "Gameplay/Factions/FactionComponent.hpp"
#include "Gameplay/Spawner/SpawnerComponent.hpp"
#include "Gameplay/Spawner/SpawnerSubsystem.hpp"
#include "Gameplay/GameModeSubsystem.hpp"
#include "Gameplay/PawnComponent.hpp"

#include "AI/AIComponent.hpp"
#include "AI/AISubsystem.hpp"

namespace
{

struct GameplayReflectionType
{
    GameplayReflectionType()
    {
        Reflection::Add<Gameplay::AbilityComponent>("Gameplay.AbilityComponent");
        Reflection::Add<Gameplay::AbilitySubsystem>("Gameplay.AbilitySubsystem");
        Reflection::Add<Gameplay::FactionComponent>("Gameplay.FactionComponent");
        Reflection::Add<Gameplay::FactionDefinition>("Gameplay.FactionDefinition");
        Reflection::Add<Gameplay::GameModeSubsystem>("GameModeSubsystem");
        Reflection::Add<Gameplay::PawnComponent>("Gameplay.PawnComponent");
        Reflection::Add<Gameplay::ProjectileComponent>("Gameplay.ProjectileComponent");
        Reflection::Add<Gameplay::ProjectileSubsystem>("Gameplay.ProjectileSubsystem");
        Reflection::Add<Gameplay::SpawnerComponent>("Gameplay.SpawnerComponent");
        Reflection::Add<Gameplay::SpawnerSubsystem>("Gameplay.SpawnerSubsystem");
        Reflection::Add<Gameplay::TopDownMovementComponent>("Gameplay.TopDownMovementComponent");
        Reflection::Add<Gameplay::TopDownMovementSubsystem>("Gameplay.TopDownMovementSubsystem");

        Reflection::Add<AI::AIComponent>("AI.AIComponent");
        Reflection::Add<AI::AISubsystem>("AI.AISubsystem");
    }
} inline GameplayReflection;

}
