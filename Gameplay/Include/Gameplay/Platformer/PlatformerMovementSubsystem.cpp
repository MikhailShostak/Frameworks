#include "Gameplay/Platformer/PlatformerMovementComponent.hpp"
#include "Gameplay/Platformer/PlatformerMovementSubsystem.hpp"
#include "Gameplay/PawnComponent.hpp"

namespace Gameplay
{

void PlatformerMovementSubsystem::UpdateScene(Graphics::Scene & Scene)
{
    ECS::Query(Scene, [&](Gameplay::PawnComponent& Pawn, Gameplay::PlatformerMovementComponent& Movement, Physics2D::PhysicsComponent& PhysicsComponent)
    {
        /*if (!RigidBody.Body)
        {
            return;
        }

        Float2 InputDirection = Pawn.InputVector;
        if (InputDirection.x || InputDirection.y)
        {
            InputDirection = hlslpp::normalize(InputDirection);
        }
        
        RigidBody.Body->ApplyForceToCenter(b2Vector(InputDirection * Pawn.Speed * Scene.DeltaTime.count()), true);
        RigidBody.Body->SetLinearDamping(Pawn.Damping);
        if (Movement.Jump)
        {
            Movement.Jump = false;

            RigidBody.Body->SetLinearVelocity(b2Vec2_zero);
            RigidBody.Body->ApplyLinearImpulseToCenter(b2Vec2(0.0f, Pawn.JumpStrength), true);
        }

        
        if (Movement.Dash && (InputDirection.x + InputDirection.y))
        {
            Movement.Dash = false;

            Scene.CommandQueue.push_back([this, InputDirection, &Pawn, &RigidBody](Graphics::Scene& Scene)
            {
                RigidBody.Body->SetLinearVelocity(b2Vec2_zero);
                RigidBody.Body->ApplyLinearImpulseToCenter(b2Vector(InputDirection * Pawn.DashStrength), true);
            });
        }*/
    });
}

}
