#include "RigidBody.h"
#include "RigidBody.h"

TPhysics::RigidBody::RigidBody(const HitBox& hitbox, float mass, float momentOfInertia, float grip)
	:p_mass(mass), p_grip(grip), p_momentOfInertia(momentOfInertia), Affector(hitbox)
{

}

void TPhysics::RigidBody::add_force_to_freebody(ForceVector forceVector)
{
	p_freeBody.add_force(p_pos, forceVector);
}
