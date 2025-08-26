#pragma once
#include "raylib.h"

#include "Hitbox.h"

#include <memory>
#include <vector>

namespace TPhysics
{
	class Affector
	{
	protected:
		float p_random;
	public:
		Affector(HitBox hitbox);
		float get_unique_random() const { return p_random; }

		virtual Vector2 get_normal_at_pt_on_surface(Vector2 pt);
		virtual Vector2 get_tangent_at_pt_on_surface(Vector2 pt);

		HitBox hitbox;


		
	};
}


inline bool operator==(const TPhysics::Affector& a1, const TPhysics::Affector& a2)
{
	return a1.get_unique_random() == a2.get_unique_random();
}

inline bool operator!=(const TPhysics::Affector& a1, const TPhysics::Affector& a2)
{
	return a1.get_unique_random() != a2.get_unique_random();
}