#pragma once

#include ".Physics.hpp"

namespace Physics2D
{

class Subsystem : public Graphics::RenderingSubsystem, public b2ContactListener
{
public:
    const int32_t velocityIterations = 1;
    const int32_t positionIterations = 1;
    b2Vec2 gravity = b2Vec2(0.0f, 0.0f);
    b2World PhysicWorld = b2World(gravity);

    void Load() override
    {
        PhysicWorld.SetContactListener(this);
        //b2BodyDef groundBodyDef;
        //groundBodyDef.position.Set(0.0f, -5.0f);
        //b2Body* groundBody = PhysicWorld.CreateBody(&groundBodyDef);
        
        b2PolygonShape groundBox;
        groundBox.SetAsBox(8.0f, 0.1f);

        //groundBody->CreateFixture(&groundBox, 0.0f);
    }

    ECS::Entity GetEntity(b2Fixture* fixture)
    {
        return { CurrentScene, static_cast<ECS::EntityID>(fixture->GetBody()->GetUserData().pointer) };
    }

    void SetEntity(b2Body* body, ECS::EntityID EntityID)
    {
        body->GetUserData().pointer = static_cast<uintptr_t>(EntityID);
    }

    Physics2D::PhysicsComponent& GetPhysicsComponent(b2Fixture* fixture)
    {
        return *reinterpret_cast<Physics2D::PhysicsComponent*>(fixture->GetBody()->GetUserData().pointer);
    }

    void SetPhysicsComponent(b2Body* body, Physics2D::PhysicsComponent &PhysicsComponent)
    {
        PhysicsComponent.Body = body;
        body->GetUserData().pointer = (uintptr_t)&PhysicsComponent;
    }

    void NotifyHit(const ECS::Entity &Entity, Physics2D::PhysicsComponent &PhysicsComponent, const ECS::Entity &OtherEntity, Physics2D::PhysicsComponent &OtherPhysicsComponent)
    {
        if(ArrayUtils::Contains(PhysicsComponent.IgnoreList, &OtherPhysicsComponent))
        {
            return;
        }

        for(auto &Callback : PhysicsComponent.OnHit)
        {
            Physics::CollisionReport Report{ OtherEntity, &OtherPhysicsComponent };
            Callback(Report);
        }
    }

    Graphics::Scene *CurrentScene = nullptr;

    void BeginContact(b2Contact* contact)
    {
        ECS::Entity Entity1 = GetEntity(contact->GetFixtureA());
        if (!Entity1)
        {
            return;
        }

        ECS::Entity Entity2 = GetEntity(contact->GetFixtureB());
        if (!Entity2)
        {
            return;
        }

        auto &PhysicsComponent1 = Entity1.GetComponent<Physics2D::PhysicsComponent>();
        auto &PhysicsComponent2 = Entity2.GetComponent<Physics2D::PhysicsComponent>();
        NotifyHit(Entity1, PhysicsComponent1, Entity2, PhysicsComponent2);
        NotifyHit(Entity2, PhysicsComponent2, Entity1, PhysicsComponent1);
    }
  
    void EndContact(b2Contact* contact)
    {
        
    }

    Array<Graphics::Scene*> Scenes;
    Array<b2Body*> DestroyList;

    void OnDestroy(entt::registry& registry, entt::entity entity)
    {
        if(auto PhysicsComponent = registry.try_get<Physics2D::PhysicsComponent>(entity); PhysicsComponent)
        {
            SetEntity(PhysicsComponent->Body, ECS::EntityID{});
            ArrayUtils::Add(DestroyList, PhysicsComponent->Body);
        }
    }

    void Initialize(ECS::EntityID EntityID, PhysicsComponent& PhysicsComponent, ECS::TransformComponent& Transform)
    {
        b2BodyDef circleBodyDef;
        circleBodyDef.type = PhysicsComponent.BodyType;
        circleBodyDef.position = b2Vector(Transform->Position.xy);
        circleBodyDef.linearVelocity = b2Vector(PhysicsComponent.InitialLinearVelocity);
        circleBodyDef.angularVelocity = PhysicsComponent.InitialAngularVelocity;
        circleBodyDef.linearDamping = 1.0f;
        
        b2Body* circleBody = PhysicWorld.CreateBody(&circleBodyDef);

        b2CircleShape circleShape;
        circleShape.m_radius = PhysicsComponent.Radius;

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &circleShape;
        fixtureDef.density = 1.0f; // Density
        fixtureDef.friction = 0.0f; // Friction
        fixtureDef.restitution = 0.0f; // Restitution
        b2Fixture* fixture = circleBody->CreateFixture(&fixtureDef);
        
        circleBody->SetMassData(&PhysicsComponent.MassData);
        PhysicsComponent.Body = circleBody;
        SetEntity(circleBody, EntityID);
    }

    void SubscribeForCleanUp(Graphics::Scene &Scene)
    {
        if (!ArrayUtils::Contains(Scenes, &Scene))
        {
            Scene.Registry.on_destroy<Physics2D::PhysicsComponent>().connect<&Subsystem::OnDestroy>(this);
            ArrayUtils::Add(Scenes, &Scene);
        }
    }

    void CleanUp()
    {
        for (b2Body* Body : DestroyList)
        {
            PhysicWorld.DestroyBody(Body);
        }
        DestroyList.clear();
    }

    template<typename Type>
    Type &FindOrAddComponent(ECS::Entity &Entity)
    {
        auto *Component = Entity.Scene->Registry.try_get<Type>();
        if (!Component)
        {
            Component = Entity.Scene->Registry.emplace<Type>();
        }
        return *Component;
    }

    void PrePhysicsUpdate(Graphics::Scene &Scene)
    {
        ECS::Query(Scene, [this](ECS::EntityID EntityID, PhysicsComponent& PhysicsComponent, ECS::TransformComponent& Transform)
        {
            if (!PhysicsComponent.Body)
            {
                Initialize(EntityID, PhysicsComponent, Transform);
            }

            const auto &PhysicsPosition = PhysicsComponent.Body->GetPosition();
            if (Transform->Position.x != PhysicsPosition.x && Transform->Position.y != PhysicsPosition.y)
            {
                PhysicsComponent.Body->SetTransform(b2Vector(Transform->Position.xy), Transform->Rotation.z);
            }
        });
    }

    void PostPhysicsUpdate(Graphics::Scene &Scene)
    {
        ECS::Query(Scene, [this](PhysicsComponent& PhysicsComponent, ECS::TransformComponent& Transform)
        {
            Transform->Position.xy = b2Vector(PhysicsComponent.Body->GetPosition());
        });
    }

    void RenderScene(Graphics::Window &Window, Graphics::Scene &Scene) override
    {
        SubscribeForCleanUp(Scene);
        CleanUp();
        
        PrePhysicsUpdate(Scene);
        CurrentScene = &Scene;
        PhysicWorld.Step(Scene.DeltaTime.count(), velocityIterations, positionIterations);
        CurrentScene = nullptr;
        PostPhysicsUpdate(Scene);
    }
};

}
