#pragma once

#include "Affector.h"

namespace TPhysics
{
	class RigidStatic : public Affector
	{
	private:
		//p_mass = infinity
		//p_momentOfInertia = infinity
		float p_grip = 1;

		Vector2 p_vel;
		Vector2 p_pos;

	public:
		RigidStatic(HitBox hitbox, float grip);

		Vector2 get_vel() { return p_vel; }
		
	};
}