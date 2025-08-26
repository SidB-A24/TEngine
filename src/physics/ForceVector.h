#pragma once
#include "raylib.h"
#include "raymath.h"

#include "../supplementaries/RaylibVector2Operators.h"
#include "FreeBody.h"

namespace TPhysics
{
	class ForceVector
	{
	public:
		ForceVector(Vector2 origin, Vector2 direction, float magnitude);

		Vector2 get_force_vector(); //I dont think we need this.


	public:
		float magnitude;
		Vector2 direction;
		Vector2 origin;
	};

	//This will be deleted.
	class FrictionForceVector : public ForceVector
	{
	public:
		FrictionForceVector(Vector2 direction, float coefficient);

		Vector2 get_force_vector_smart(FreeBody freeBody);

	private:
		float p_coefficient; //Friction Coefficient between the Affector surface and the affected surface.
	};
}