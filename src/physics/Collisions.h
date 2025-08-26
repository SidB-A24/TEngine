#pragma once
#include "Hitbox.h"

namespace TPhysics
{
	struct CollisionResult
	{
		bool collisionOccured;
		Vector2 collisionPoint;
	};

	CollisionResult do_collision(HitBox h1, HitBox h2);
	CollisionResult do_collision(HitBox_Rectangle h1, HitBox_Rectangle h2);
}