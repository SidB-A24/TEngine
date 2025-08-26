#include "ForceVector.h"

TPhysics::ForceVector::ForceVector(Vector2 origin, Vector2 direction, float magnitude)
	:origin(origin), direction(direction), magnitude(magnitude)
{
}

Vector2 TPhysics::ForceVector::get_force_vector()
{
	return magnitude*direction;
}
