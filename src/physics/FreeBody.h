#pragma once

#include "ForceVector.h"

#include <vector>

namespace TPhysics
{
	class FreeBody
	{
	private:
		std::vector<ForceVector> p_COMForces; //Forces that are purely translational.
		std::vector<float> p_torques;

	public:
		void add_force(Vector2 COMPos, ForceVector forceVector); //Will calculate the torque and stuff based on location of cm and auto seperate components. 

		ForceVector get_net_force();
		float get_net_torque(); //+ve torque -> clockwise.

	};
}