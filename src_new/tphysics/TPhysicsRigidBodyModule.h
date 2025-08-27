//
// Created by Sid B on 27/08/25.
//
#pragma once
#include <memory>
#include <vector>

#include "../tengine/TPoly.h"
#include "raylib.h"
#include "../tengine/TModule.h"
#include "ForceVector.h"


namespace TPhysics
{

    class TPhysicsRigidBodyModule : public TEngine::TModule
    {
    private:
        float m_mass = 0.0f;
        float m_momentOfInertia = 0.0f;
        float m_grip = 1;

        //std::unique_ptr<HitBox> hitBox;

        std::shared_ptr<Vector2> m_vel;
        std::shared_ptr<Vector2> m_pos;

        std::shared_ptr<float> m_angularPos; //Rotation in radians
        std::shared_ptr<float> m_angularVel; //Angular vel in rad/s

        std::shared_ptr<TEngine::TPoly> m_geometry;

        std::vector<ForceVector> m_forceVectors;

    public:
        //Constructor is heavy looking cuz of shared ptr assignment.
        TPhysicsRigidBodyModule(float mass, float momentOfInertia, float grip,
            const std::shared_ptr<Vector2>& vel, const std::shared_ptr<Vector2>& pos,
            const std::shared_ptr<float>& angularVel, const std::shared_ptr<float>& angularPos)
            :m_mass(mass), m_momentOfInertia(momentOfInertia), m_grip(grip),
            m_pos(pos), m_vel(vel), m_angularPos(angularPos), m_angularVel(angularVel)
        {;}

        void add_force(ForceVector forceVector) {m_forceVectors.push_back(forceVector);}

        void apply_translational_impulse(Vector2 impulse);
        void apply_rotational_impulse(float impulse);

        //Called by the system
        void apply_forces(float deltaTime);
    };
}
