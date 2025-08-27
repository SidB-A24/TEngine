//
// Created by Sid B on 27/08/25.
//

#pragma once
#include "raylib.h"

#include "../tengine/TPoly.h"

namespace TPhysics
{
    struct CollisionResult
    {
        bool collided;
        Vector2 result;

        CollisionResult (bool collided, Vector2 result) : collided(collided), result(result) {;}
    };

    extern CollisionResult collide_geometries(TEngine::TPoly g1, TEngine::TPoly g2);
} // TPhysics


