//
// Created by Sid B on 27/08/25.
//
#pragma once
#include <vector>

#include "raylib.h"

/*
 * TODO: add a function that converts the relative vertices to vertices adjusted to the position of the body and rotation too.
 * So essentially the vertices are initially plotted with respect to the origin. This makes it really easy to define shapes.
 * We also have a function that returns the actual vertices, so we can create a TPoly_Circle, which returns that point + radius projection.
 */

namespace TEngine
{
    class TPoly
    {
    private:
        std::vector<Vector2> m_vertices;
    public:
        const std::vector<Vector2> &get_vertices() const
        {
            return m_vertices;
        }

        Vector2 get_normal(size_t vertexIndex);
    };

} // TEngine

