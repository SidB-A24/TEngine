#pragma once

#include <vector>
#include <set>
#include <memory>
#include <chrono>

#include "Affector.h"
#include "RigidBody.h"
#include "RigidStatic.h"
#include "Collisions.h"

namespace TPhysics
{
	class System
	{
	public:
		System();

		//Managing Elements
		void add_rigidbody(std::shared_ptr<RigidBody> rigidBody) {p_rigidBodies.push_back(rigidBody);}

		void add_rigidstatic(std::shared_ptr<RigidStatic> rigidStatic) {p_rigidStatics.push_back(rigidStatic);}

		void add_affector(std::shared_ptr<Affector> affector) {p_affectors.push_back(affector);}

		//Ticking
		void tick();
		void tick_new();

		void _log_data() const;

	private:
		std::chrono::high_resolution_clock::time_point lastTickTime;

		std::vector<std::shared_ptr<Affector>> p_affectors;

		std::vector<std::shared_ptr<RigidBody>> p_rigidBodies;
		std::vector<std::shared_ptr<RigidStatic>> p_rigidStatics;
	};
}