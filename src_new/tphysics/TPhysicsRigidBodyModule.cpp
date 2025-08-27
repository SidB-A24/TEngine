//
// Created by Sid B on 27/08/25.
//

#include "TPhysicsRigidBodyModule.h"
#include "../tutilities/RaylibVector2Operators.h"

void TPhysics::TPhysicsRigidBodyModule::apply_translational_impulse(Vector2 impulse)
{
    *m_vel = *m_vel + impulse / m_mass;
}

void TPhysics::TPhysicsRigidBodyModule::apply_rotational_impulse(float impulse)
{
    *m_angularVel = *m_angularVel + impulse / m_momentOfInertia;
}

/*
 * We need to go through each vector and apply it as translation.
 * Apply the rotational component as rotational.
 */
void TPhysics::TPhysicsRigidBodyModule::apply_forces(float deltaTime)
{
    for (ForceVector& forceVector : m_forceVectors)
    {
        //Translation
        apply_translational_impulse(forceVector.get_force_vector()*deltaTime);

        //Rotation
        float torque = (forceVector.origin - *m_pos) % forceVector.get_force_vector();
        apply_rotational_impulse(torque*deltaTime);
    }

}
