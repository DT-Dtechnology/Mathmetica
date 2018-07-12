#pragma once
#include "Particle.h"
class ForceGenerator
{
public:
	virtual void updateForce(Particle* particle, double duration) = 0;
};
