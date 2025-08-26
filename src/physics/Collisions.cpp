#include "collisions.h"

namespace TPhysics
{
	CollisionResult do_collision(HitBox h1, HitBox h2)
	{
		return { false, {0, 0} };
	}

	CollisionResult do_collision(HitBox_Rectangle h1, HitBox_Rectangle h2)
	{
		for (Vector2 pt: h1.get_points_on_perimeter(4))
		{
			if (h2.is_pt_in_hitbox(pt))
			{
				return { true , pt };
			}
		}
		for (Vector2 pt : h2.get_points_on_perimeter(4))
		{
			if (h1.is_pt_in_hitbox(pt))
			{
				return { true , pt };
			}
		}

		return { false, {0, 0} };
	}

} //We can overload this function externally for custom geometries.