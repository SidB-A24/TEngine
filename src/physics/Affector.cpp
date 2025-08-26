#include "Affector.h"

#include <random>

TPhysics::Affector::Affector(HitBox hitbox)
	:hitbox(hitbox)
{
	//Generating a unique seed to this specific affector on scene. This can help us differentiate it from others. 
	std::random_device randomDevice;
	std::mt19937 randomEngine(randomDevice());
	std::uniform_real_distribution<float> floatRange(0.0, 1.0);
	p_random = floatRange(randomEngine);
}
