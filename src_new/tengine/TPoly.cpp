//
// Created by Sid B on 27/08/25.
//

#include "TPoly.h"
#include "../tutilities/RaylibVector2Operators.h"

namespace TEngine {
    Vector2 TPoly::get_normal(size_t vertexIndex)
    {
        Vector2 difference = m_vertices[vertexIndex] - m_vertices[vertexIndex-1];

        return Vector2{difference.x, -difference.y};

    }
} // TEngine