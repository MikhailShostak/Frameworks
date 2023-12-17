#pragma once

namespace Graphics2D
{

class ParticleSystem : public sf::Drawable, public sf::Transformable
{
public:

    ParticleSystem(unsigned int count) :
        m_particles(count),
        m_vertices(sf::Points, count),
        m_lifetime(3.f),
        m_emitter(0.f, 0.f)
    {
    }

    void setEmitter(const sf::Vector2f &position)
    {
        m_emitter = position;
    }

    void update(float elapsed)
    {
        for (std::size_t i = 0; i < m_particles.size(); ++i)
        {
            // update the particle lifetime
            Particle& p = m_particles[i];
            p.lifetime -= elapsed;

            // if the particle is dead, respawn it
            if (p.lifetime <= 0.0f)
                resetParticle(i);

            // update the position of the corresponding vertex
            m_vertices[i].position += p.velocity * elapsed;

            // update the alpha (transparency) of the particle according to its lifetime
            float ratio = p.lifetime / m_lifetime;
            m_vertices[i].color.a = static_cast<sf::Uint8>(ratio * 255);
        }
    }

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // apply the transform
        states.transform *= getTransform();

        // our particles don't use a texture
        states.texture = NULL;

        // draw the vertex array
        target.draw(m_vertices, states);
    }

private:

    struct Particle
    {
        sf::Vector2f velocity;
        float lifetime = 0.0f;
    };

    void resetParticle(std::size_t index)
    {
        // give a random velocity and lifetime to the particle
        float angle = (std::rand() % 360) * 3.14f / 180.f;
        float speed = ((std::rand() % 50) + 50) / 100.0f;
        m_particles[index].velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
        m_particles[index].lifetime = (std::rand() % 2000) + 1000;

        // reset the position of the corresponding vertex
        m_vertices[index].position = m_emitter;
    }

    std::vector<Particle> m_particles;
    sf::VertexArray m_vertices;
    float m_lifetime = 0.0f;
    sf::Vector2f m_emitter;
};

struct ParticleSystemComponent
{
    ParticleSystem particles = ParticleSystem(100);
};

}
