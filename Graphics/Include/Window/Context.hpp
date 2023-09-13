#pragma once

namespace Core
{

/*class Context
{
public:
    entt::registry Registry;

    inline static const float UnitSize = 100.0f;
    UniqueReference<sf::RenderWindow> Window;
    Array<UniqueReference<Subsystem>> Subsystems;

    Int2 MousePosition;

    Float2 GetMouseWorldPosition() const { return sfVector(Window->mapPixelToCoords({ MousePosition.x, MousePosition.y })); }
    Int2 GetMouseWorldPixelPosition() const { return Int2(GetMouseWorldPosition() * UnitSize); }

    WorldCoords GetCoords(const Float2 &WorldPosition) const
    {
        Int2 ScaledPosition = Int2(WorldPosition * UnitSize);

        WorldCoords Coords;
        Coords.Chunk = ScaledPosition / (g_ChunkSize * g_GameTileSize);    
        const Int2 tile = (ScaledPosition % (g_ChunkSize * g_GameTileSize)) / g_GameTileSize;
        Coords.TileIndex = tile[1] * g_ChunkSize[0] + tile[0];

        return Coords;
    }

    entt::entity Player;

    sf::Clock Clock;
    sf::Time DeltaTime;

    auto CreateEntity(const Float2 &Position = {}, float Rotation = 0.0f, const Float2 &Scale = { 1.0f, 1.0f })
    {
        auto Entity = Registry.create();

        auto &transform = Registry.emplace<Graphics2D::TransformComponent>(Entity);
        transform.Position = Position;
        transform.Rotation = Rotation;
        transform.Scale = Scale;

        return Entity;
    }

    auto CreateSprite(const Float2 &Position = {}, float Rotation = 0.0f, const Float2 &Scale = { 1.0f, 1.0f })
    {
        auto Entity = CreateEntity(Position, Rotation, Scale);
        Registry.emplace<Physics2D::RigidBodyComponent>(Entity);
        Registry.emplace<Graphics2D::SpriteComponent>(Entity);
        return Entity;
    }

    void UpdateScreenSurface(const sf::Vector2f &Size)
    {
        sf::View View = Window->getView();
        View.setSize({ Size.x / UnitSize, -Size.y / UnitSize});
        Window->setView(View);
    }

    void Run(const String& Title, int32_t Width, int32_t Height)
    {
        Window = std::make_unique<sf::RenderWindow>(sf::VideoMode(Width, Height), Title.data());
        UpdateScreenSurface({ float(Width), float(Height) });
        Window->setFramerateLimit(60);

        for (auto &Subsystem : Subsystems)
        {
            Subsystem->OnLoad(*this);
        }

        std::vector<sf::Event> Events;
        while (Window->isOpen())
        {
            Events.reserve(64);
            sf::Event Event;
            while (Window->pollEvent(Event))
            {
                if (Event.type == sf::Event::Closed)
                {
                    Window->close();
                }
                else if (Event.type == sf::Event::Resized)
                {
                    UpdateScreenSurface({ float(Event.size.width), float(Event.size.height) });
                }

                Events.push_back(Event);
                for (auto &Subsystem : Subsystems)
                {
                    Subsystem->OnPreprocessEvent(*this, Event);
                }
            }

            if (Registry.valid(Player))
            {
                sf::View View = Window->getView();
                auto Transform = Registry.get<Graphics2D::TransformComponent>(Player);
                View.setCenter(sfVector(Transform.Position));
                Window->setView(View);
            }
            
            Window->clear(sf::Color::Black);
            OnTick();
            Window->display();

            for (auto &Event : Events)
            {
                for (size_t i = Subsystems.size() - 1; i != size_t(-1); --i)
                {
                    auto &Subsystem = Subsystems[i];
                    if (Subsystem->OnHandleEvent(*this, Event))
                    {
                        break;
                    }
                }
            }

            Events.clear();
        }

        for (auto &Subsystem : Subsystems)
        {
            Subsystem->OnUnload(*this);
        }
    }

    void OnTick()
    {
        DeltaTime = Clock.restart();

        for (auto &Subsystem : Subsystems)
        {
            Subsystem->OnTick(*this);
        }
    }
};*/

}
