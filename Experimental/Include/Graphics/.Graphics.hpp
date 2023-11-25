#pragma once

#include <SFML/Graphics.hpp>

inline sf::Vector2f sfVector(const Float3 &Vector) { return { Vector.x, Vector.y }; }
inline sf::Vector2f sfVector(const Float2 &Vector) { return { Vector.x, Vector.y }; }
inline Float3 sfVector(const sf::Vector2f &Vector) { return { Vector.x, Vector.y, 0.0f }; }
inline sf::Vector2i sfVector(const Int3 &Vector) { return { Vector.x, Vector.y }; }
inline sf::Vector2i sfVector(const Int2 &Vector) { return { Vector.x, Vector.y }; }
inline Int2 sfVector(const sf::Vector2i &Vector) { return { Vector.x, Vector.y }; }

inline static const float UnitSize = 100.0f;

#include "Misc/.Misc.hpp"

#include "Graphics/PostProcessStep.hpp"
#include "Graphics/GlowPostProcessStep.hpp"
