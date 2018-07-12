#include "stdafx.h"
#include "ForceRegistry.h"

void ForceRegistry::add(Particle* particle, ForceGenerator* force_generator)
{
	registrations_.push_back({ particle, force_generator });
}

void ForceRegistry::remove(Particle* particle, ForceGenerator* force_generator)
{
	auto it = registrations_.begin();
	while(it != registrations_.end())
	{
		if(it->particle == particle && it->force_generator == force_generator)
		{
			registrations_.erase(it);
			return;
		}
	}
}


void ForceRegistry::updateForces(double duration)
{
	for(auto it = registrations_.begin() ; it != registrations_.end() ;++it)
	{
		it->force_generator->updateForce(it->particle, duration);
	}
}
