#include "System.h"

#include "../Logger.h"

#include <sstream>
#include <string>

TPhysics::System::System()
{
	lastTickTime = std::chrono::high_resolution_clock::now();
}

void TPhysics::System::tick_new()
{
	//Getting dt
	std::chrono::high_resolution_clock::time_point currentTime = std::chrono::high_resolution_clock::now();
	float deltaTime = std::chrono::duration<float>{ currentTime - lastTickTime }.count();
	lastTickTime = currentTime;


	ForceVector gravityForceVector = ForceVector({ 0, 0 }, { 0, -1 }, 9.8f);
	std::set<std::set<float>> checkedRigidBodies; //Tracking collisions to prevent applying impulses multiple times.

	for (const auto& rb1 : p_rigidBodies)
	{
		//Gravity
		gravityForceVector.origin = rb1->get_pos();
		rb1->add_force_to_freebody(gravityForceVector);

		/*
		Checking for Collisions
		*/
		for (const auto& rb2 : p_rigidBodies)
		{
			//Making sure this specific combination has never been checked against.
			if (checkedRigidBodies.find({ rb1->get_unique_random(), rb2->get_unique_random() }) == checkedRigidBodies.end())
			{
				checkedRigidBodies.insert({ rb1->get_unique_random(), rb2->get_unique_random() });
				
				CollisionResult result = do_collision(rb1->hitbox, rb2->hitbox);

				if (result.collisionOccured)
				{
					/*
					Conservation of Linear Momentum
					*/

					//Normal of collision
					Vector2 n1 = result.collisionPoint - rb1->get_pos();
					Vector2 n2 = result.collisionPoint - rb2->get_pos();
					Vector2 nRel = Vector2Normalize(n2 - n1);

					//Relative Velocity
					Vector2 vRel = rb1->get_vel() - rb2->get_vel();
					float velOfSeperation = vRel * nRel; //DotProduct

					if (velOfSeperation < 0)
					{
						//Accounting for mass and moment of inertia
						float inertial = (1.0f / rb1->get_mass() + 1.0f / rb2->get_mass()) +
							(powf((rb1->get_pos() % nRel), 2) * (1 / rb1->get_I())) +
							(powf((rb2->get_pos() % nRel), 2) * (1 / rb2->get_I()));

						//Final Impulse.
						float linearForce = (-velOfSeperation / inertial) / deltaTime;

						ForceVector linearForceVector(result.collisionPoint, Vector2Normalize(nRel), -linearForce);

						rb1->add_force_to_freebody(linearForceVector);
						linearForceVector.magnitude *= -1.0f;
						rb2->add_force_to_freebody(linearForceVector);
					}


					/*
					TODO: Friction between rigidbodies
					TODO: Coefficient of restitution
					*/

				}

			}
		}

		/*
		Checking for contact/collision with RigidStatic
		*/

		for (const auto& rb : p_rigidBodies)
		{
			for (const auto& rs : p_rigidStatics)
			{
				//Now we need to run the same impulse stuff seen above.
				CollisionResult result = do_collision(rb->hitbox, rs->hitbox);

				if (result.collisionOccured)
				{
					/*
					Conservation of Linear Momentum
					*/

					//Normal of collision
					Vector2 n1 = result.collisionPoint - rb->get_pos();
					Vector2 n2 = result.collisionPoint; //The collision point is the position as far as we're concerned of the static.
					Vector2 nRel = Vector2Normalize(n2 - n1);

					//Relative Velocity
					Vector2 vRel = rb->get_vel() - rs->get_vel();
					float velOfSeperation = vRel * nRel; //DotProduct

					if (velOfSeperation < 0)
					{
						//Accounting for mass and moment of inertia
						float inertial = (1.0f / rb->get_mass()) +
							(powf((rb->get_pos() % nRel), 2) * (1 / rb->get_I())); //No inertia of the static, so we won't need to account for it

						//Final Impulse.
						float linearForce = (-velOfSeperation / inertial) / deltaTime;

						ForceVector linearForceVector(result.collisionPoint, Vector2Normalize(nRel), -linearForce);

						rb->add_force_to_freebody(linearForceVector);
						//This ⬇️ is omitted as the static does not have any influence by the rigidbody
						//linearForceVector.magnitude *= -1.0f;
						//rs.add_force_to_freebody(linearForceVector);
					}

				}
			}

		}

		/*
		First, we apply gravity to all the RigidBodies here that have gravity;

		Second, we check for collision impulses and convert them to the necessary force needed and add them to the freeBody

		Third, we calculate the reaction forces with RigidStatics.
		 - If there's velocity along the normal
		 - If there's normal force, etc

		Finally, we compute the net impulse based on the forces present in the freeBody;


		*/
	}
}

void TPhysics::System::_log_data() const
{
	for (const auto& rb : p_rigidBodies)
	{
		std::stringstream ss;
		Vector2 pos = rb->get_pos();
		ss << rb->get_unique_random() << " :  (" << pos.x << "," << pos.y << ")\n";

		TEngine::Logger::Instance().info(ss.str().c_str());
	}

}

