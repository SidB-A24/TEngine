//
// Created by Sid B on 27/08/25.
//

#include "ForceVector.h"

#include "../tutilities/RaylibVector2Operators.h"

namespace TPhysics {} // TPhysics

Vector2 TPhysics::ForceVector::get_force_vector() const
{
    return magnitude*direction;
}
