#pragma once
#include "ForceGenerator.h"
#include "BasicStruct.h"

class Gravity:public ForceGenerator
{
	Vector3 gravity_;
public:
	Gravity(const Vector3& gravity) :gravity_(gravity) {  }
	virtual void updateForce(Particle* particle, double duration) override;
};

inline void Gravity::updateForce(Particle* particle, double duration)
{
	// Jugde zero mass or not.

	// Add force to the Particle

}
