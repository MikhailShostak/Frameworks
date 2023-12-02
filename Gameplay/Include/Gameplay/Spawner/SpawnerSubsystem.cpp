#include "Gameplay/Spawner/SpawnerComponent.hpp"
#include "Gameplay/Spawner/SpawnerSubsystem.hpp"
#include "Graphics/TransformComponent.hpp"

#include <cstdlib>

namespace Gameplay
{

struct SpawnerTracker
{

};

void SpawnerSubsystem::UpdateScene(Graphics::Scene &Scene)
{
    ECS::Query(Scene, [&Scene](Gameplay::SpawnerComponent &Spawner, ECS::TransformComponent &Transform)
    {
        for (size_t i = 0; i < Spawner.Entities.size(); ++i)
        {
            if (!Spawner.Entities[i])
            {
                ArrayUtils::Remove(Spawner.Entities, i--);
            }
        }

        if (Spawner.Entities.size() >= Spawner.Amount || !Spawner.CooldownTimer.IsElapsed())
        {
            return;
        }
        
        Spawner.CooldownTimer.Start(std::chrono::duration_cast<DateTime::Steady::Clock::duration>(Spawner.CooldownDuration));        
        auto Entity = ECS::CreateEntity(Scene, Spawner.Definition.get());

        Float3 Position{
            static_cast <float> (rand()) / static_cast <float> (RAND_MAX),
            static_cast <float> (rand()) / static_cast <float> (RAND_MAX),
            0,
        };
        Position = Position * (Spawner.BoxExtent + Spawner.BoxExtent) - Spawner.BoxExtent;
        auto Offset = hlslpp::normalize(Position) * Spawner.OffsetRadius;
        Entity.GetComponent<ECS::TransformComponent>()->Position = Transform->Position + Position + Offset;
        Spawner.Entities.push_back(std::move(Entity));
    });
}

}