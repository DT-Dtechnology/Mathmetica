#pragma once
#include "ForceGenerator.h"
#include <vector>


/**
 * \brief 中心注册机制，对于任何对象的任何手里了进行统一注册，完成受力添加。
 */
class ForceRegistry
{
protected:
	struct ForceRegistration
	{
		Particle* particle;
		ForceGenerator* force_generator;
	};

	typedef std::vector<ForceRegistration> Registry;
	Registry registrations_;

public:
	void add(Particle* particle, ForceGenerator* force_generator);
	void remove(Particle* particle, ForceGenerator* force_generator);
	void clear();

	void updateForces(double);
};

