#pragma once

#include <Box2D/Box2D.h>

inline b2Vec2 b2Vector(const Float3 &Vector) { return { Vector.x, Vector.y }; }
inline b2Vec2 b2Vector(const Float2 &Vector) { return { Vector.x, Vector.y }; }
inline Float2 b2Vector(const b2Vec2 &Vector) { return { Vector.x, Vector.y }; }

namespace Physics2D
{

class PhysicsComponent;

}

namespace Physics
{

struct CollisionReport;

using CollisionReportCallback = Meta::Function<void, const CollisionReport&>;

}

#include "Physics/CollisionReport.hpp"
#include "Physics/PhysicsComponent.hpp"
#include "Physics/TriggerVolumeComponent.hpp"
