#pragma once

#include "Graphics/.Graphics.hpp"
#include "Graphics/SpriteMaterial.hpp"
#include "Graphics/SpriteComponent.hpp"
//#include ".Physics.hpp"

namespace Graphics2D
{

inline static bool PhysicsDebug = false;

class RenderingSubsystem : public Graphics::RenderingSubsystem
{
public:
    sf::Font DebugFont;
    sf::Texture DebugTexture;

    void Load() override
    {
        auto Binding = std::make_shared<Input::KeyboardButtonBinding>();
        Binding->Button = Input::KeyboardButton::O;
        Input::Bind(Input::GetDebugContext(), Binding, PhysicsDebug);
        
        if (!DebugTexture.loadFromFile("Images/sample.png")) {
            // Handle error
        }

        DebugFont.loadFromFile("C:/Windows/Fonts/consola.ttf");
    }

    void RenderScene(Graphics::Window &Window, Graphics::Scene &Scene) override
    {
        auto SFMLWindow = DynamicCast<Graphics::SFMLWindow>(&Window);

        ECS::Query(Scene, [&](const ECS::TransformComponent& Transform, ECS::SpriteComponent& Sprite)
        {
            if (!Sprite.Material.TextureInstance)
            {
                if (!Sprite.Material.Path.empty())
                {
                    SharedReference<sf::Texture> Texture(Create<sf::Texture>());
                    Texture->loadFromFile(Sprite.Material.Path.generic_string());
                    Sprite.Material.TextureInstance = Texture;
                }
                else
                {
                    sf::CircleShape Circle;
                    Circle.setPosition(sfVector(Transform->Position) - sf::Vector2f{ 0.1f, 0.1f });
                    Circle.setRadius(0.1f);
                    Circle.setFillColor(sf::Color::Blue);
                    SFMLWindow->Handle.draw(Circle);
                }
            }
            else
            {
                sf::Sprite sfSprite;
                Float2 HalfSize = Float2(Sprite.Material.Size) / UnitSize;
                HalfSize.y = -HalfSize.y;
                sfSprite.setPosition(sfVector(Transform->Position));
                sfSprite.setOrigin(float(Sprite.Material.Size.x) / 2, -float(Sprite.Material.Size.y) / 2);
                sfSprite.setRotation(Transform->Rotation.z);
                sfSprite.setTexture(*Sprite.Material.TextureInstance);
                sfSprite.setTextureRect(sf::IntRect{sfVector(Sprite.Material.Offset), sfVector(Sprite.Material.Size)});
                sfSprite.setScale(2.0f / UnitSize, 2.0f / UnitSize);
                SFMLWindow->Handle.draw(sfSprite);
            }

            /*sf::RectangleShape rectangle;
            auto HalfSize = sf::Vector2f(Sprite.Size.x, Sprite.Size.y) / 2.0f;
            rectangle.setPosition((Transform.Position) * Context.UnitSize - HalfSize);
            rectangle.setSize(sf::Vector2f(Sprite.Size.x, Sprite.Size.y));
            //rectangle.setTexture(&DebugTexture);
            rectangle.setFillColor(sf::Color::Blue);
            Context.Window->draw(rectangle);*/
        });

        //if (PhysicsDebug)
        //{
        //    ECS::Query(Scene, [&](const ECS::TransformComponent& Transform, const Physics2D::PhysicsComponent& PhysicsComponent)
        //    {
        //        sf::CircleShape Circle;
        //        float Thicness = 0.01f;
        //        Circle.setPosition(sfVector(Transform->Position - Float3{ PhysicsComponent.Radius, PhysicsComponent.Radius, 0.0f }) + sf::Vector2f{Thicness, Thicness});
        //        Circle.setRadius(PhysicsComponent.Radius - Thicness);
        //        Circle.setFillColor(sf::Color::Transparent);
        //        Circle.setOutlineColor(PhysicsComponent.Body && PhysicsComponent.Body->IsAwake() ? sf::Color::Red : sf::Color::Green);
        //        Circle.setOutlineThickness(Thicness);
        //        SFMLWindow->Handle.draw(Circle);
//
        //        /*sf::Text Text;
        //        Text.setFont(DebugFont);
        //        Text.setPosition(Transform.Position * Context.UnitSize);
        //        Text.setFillColor(sf::Color::Yellow);
        //        Text.setString(fmt::format("Transform: p({:.2f}, {:.2f}) r({:.2f}) s({:.2f}, {:.2f})\nRadius: {:.2f}\nVelocity: {:.2f}, {:.2f}\n",
        //            Transform.Position.x,
        //            Transform.Position.y,
        //            Transform.Rotation,
        //            Transform.Scale.x,
        //            Transform.Scale.y,
        //            RigidBody.Radius,
        //            RigidBody.Body->GetLinearVelocity().x,
        //            RigidBody.Body->GetLinearVelocity().y
        //        ));
        //        Text.setCharacterSize(12);
        //        Context.Window->draw(Text);*/
        //    });
        //}
    }
};

}
