#include "AI/AISubsystem.hpp"
#include "AI/AIComponent.hpp"
#include "Gameplay/PawnComponent.hpp"
#include "Graphics/TransformComponent.hpp"
#include "Gameplay/Factions/FactionRelation.hpp"
#include "Gameplay/Factions/FactionDefinition.hpp"
#include "Gameplay/Factions/FactionComponent.hpp"

namespace AI
{

void AISubsystem::UpdateScene(Graphics::Scene &Scene)
{
    if (!UpdateTimer.IsElapsed())
    {
        return;
    }

    UpdateTimer.Start(std::chrono::duration_cast<DateTime::Steady::Clock::duration>(UpdateRate));
    
    ECS::Query(Scene, [&Scene](AI::AIComponent &AI, ECS::TransformComponent &Transform, Gameplay::PawnComponent &PawnComponent, Gameplay::FactionComponent &Faction)
    {
        Float2 Distance;
        ECS::Entity Enemy;
        ECS::Query(Scene, [&](const ECS::Entity &Entity, ECS::TransformComponent &EnemyTransform, Gameplay::PawnComponent &PawnComponent, Gameplay::FactionComponent &EntityFaction)
        {
            if (Enemy || Faction.Definition == EntityFaction.Definition /*|| !Faction->IsEnemy(EntityFaction->Name)*/)
            {
                return;
            }

            auto TempDistance = EnemyTransform->Position.xy - Transform->Position.xy;
            if (hlslpp::length(TempDistance).x > 1.0f)
            {
                return;
            }
            
            Enemy = Entity;
            Distance = TempDistance;
        });

        if (Enemy)
        {
            auto Direction = hlslpp::normalize(Distance);
            PawnComponent.InputVector = Direction;
        }
    });
}

}