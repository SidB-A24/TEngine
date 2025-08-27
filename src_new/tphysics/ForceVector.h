//
// Created by Sid B on 27/08/25.
//
#pragma once
#include "raylib.h"

namespace TPhysics
{
    class ForceVector
    {
    public:
        ForceVector(Vector2 origin, Vector2 direction, float magnitude);

        Vector2 get_force_vector() const; //I dont think we need this.


    public:
        float magnitude;
        Vector2 direction;
        Vector2 origin;
    };
} // TPhysics

