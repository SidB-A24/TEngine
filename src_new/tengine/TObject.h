//
// Created by Sid B on 26/08/25.
//
#pragma once

#include <raylib.h>
#include <memory>

#include "TModule.h"
#include "TPoly.h"

namespace TEngine
{
class TObject
{
private:
    std::shared_ptr<Vector2> m_pos;
    std::shared_ptr<Vector2> m_vel;

    std::shared_ptr<float> m_angularPos; //Rotation in radians
    std::shared_ptr<float> m_angularVel; //Angular vel in rad/s

    std::shared_ptr<TModule> m_tPhysicsModule = nullptr;
    std::shared_ptr<TModule> m_tPhotonModule = nullptr;

    std::shared_ptr<TPoly> m_geometry;

public:
    TObject();
    ~TObject();

    void set_physics_module(); //TODO: Setting physics module.
    void set_photon_module();



};

inline TObject::TObject()
    : m_pos(std::make_shared<Vector2>(0, 0))
    {}
} // TEngine

