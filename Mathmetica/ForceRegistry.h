#pragma once
#include "ForceGenerator.h"
#include <vector>


/**
 * \brief ����ע����ƣ������κζ�����κ������˽���ͳһע�ᣬ���������ӡ�
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

