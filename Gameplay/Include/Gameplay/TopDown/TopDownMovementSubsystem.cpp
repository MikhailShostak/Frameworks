#include "Gameplay/TopDown/TopDownMovementComponent.hpp"
#include "Gameplay/TopDown/TopDownMovementSubsystem.hpp"
#include "Gameplay/PawnComponent.hpp"

namespace Gameplay
{

void TopDownMovementSubsystem::UpdateScene(Graphics::Scene & Scene)
{
    ECS::Query(Scene, [&](Gameplay::PawnComponent& Pawn, Gameplay::TopDownMovementComponent& Movement, Physics2D::PhysicsComponent& PhysicsComponent)
    {
        if (!PhysicsComponent.Body)
        {
            return;
        }

        Float2 InputDirection = Pawn.InputVector;
        if (InputDirection.x || InputDirection.y)
        {
            InputDirection = hlslpp::normalize(InputDirection);
        }
        
        PhysicsComponent.Body->ApplyForceToCenter(b2Vector(InputDirection * Movement.Speed * Scene.DeltaTime.count()), true);
        PhysicsComponent.Body->SetLinearDamping(Movement.Damping);
        
        if (Movement.Dash && (InputDirection.x + InputDirection.y))
        {
            Movement.Dash = false;

            Scene.CommandQueue.push_back([this, InputDirection, &Pawn, &Movement, &PhysicsComponent](Graphics::Window &Window, Graphics::Scene& Scene)
            {
                PhysicsComponent.Body->SetLinearVelocity(b2Vec2_zero);
                PhysicsComponent.Body->ApplyLinearImpulseToCenter(b2Vector(InputDirection * Movement.DashStrength), true);
            });
        }
    });
}

}
