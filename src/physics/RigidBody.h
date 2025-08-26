#pragma once
#include "Affector.h"
#include "ForceVector.h"
#include "FreeBody.h"


namespace TPhysics
{
	class RigidBody : public Affector
	{
	private:
		float p_mass;
		float p_momentOfInertia;
		float p_grip = 1; //Multiplier for friction coefficient of a given surface. This multiplication is clamped between 0.0 and 1.0

		Vector2 p_vel;
		Vector2 p_pos;
		
		//FreeBody p_freeBody = FreeBody();

	public:
		RigidBody(HitBox hitbox, float mass, float momentOfInertia, float grip);

		void apply_translation_impulse();
		void apply_rotational_impulse();

		void add_force_to_freebody(ForceVector forceVector); //Gravity, etc. constant forces are applied to the freebody first.

		Vector2 get_pos() { return p_pos; }
		Vector2 get_vel() { return p_vel; }
		float get_mass() { return p_mass; }
		float get_I() { return p_momentOfInertia; }
	};
}