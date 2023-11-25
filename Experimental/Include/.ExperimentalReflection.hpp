#pragma once

#include "Graphics/TransformComponent.hpp"
#include "Graphics/SpriteMaterial.hpp"
#include "Graphics/SpriteComponent.hpp"
#include "Graphics/ParticleSystemSubsystem.hpp"
#include "Graphics/RenderingSubsystem.hpp"


namespace
{

struct DungeonReflectionType
{
    DungeonReflectionType()
    {
        Reflection::Add<ECS::TransformComponent>("ECS.TransformComponent");
        Reflection::Add<ECS::SpriteComponent>("ECS.SpriteComponent");
        Reflection::Add<ECS::SpriteMaterial>("ECS.SpriteMaterial");
        //Reflection::Add<DungeonGameMode>("DungeonGameMode");
        //Reflection::Add<MainMenuView>("MainMenuView");
        //Reflection::Add<Physics2D::Subsystem>("Physics2D.Subsystem");
        //Reflection::Add<Graphics2D::ParticleSystemSubsystem>("Graphics2D.ParticleSystemSubsystem");
        //Reflection::Add<Graphics2D::RenderingSubsystem>("Graphics2D.RenderingSubsystem");
//
        //Reflection::Add<ProceduralTilemapSubsystem>("ProceduralTilemapSubsystem");
    }
} inline ExperimentalReflection;

}
