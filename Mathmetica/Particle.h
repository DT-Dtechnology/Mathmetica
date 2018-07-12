#pragma once
#include "BasicStruct.h"

/**
 * \brief �����������
 * ���������������ӣ�������ϵķ�ʽ��¼λ�á��ٶȡ����ٶȡ�����
 */
class Particle
{
	// ������Ϣ
	Vector3 position_;
	Vector3 velocity_;
	Vector3 acceleration_;

	Vector3 forceAccum_;

	// ���ᣬ1��ʾ������
	double damping_ = 1.00;

	// �����ĵ��������������ٶ�
	double inserse_mass_;
	// �����������������
	double mass_;

	void UpdatePosition(const double duration);
	void UpdateVelocity(const double duration);

public:
	Particle() = default;
	~Particle() = default;

	/**
	 * \brief �������к���������ʱ����е������㣬�Ӷ��������һ����״̬��Ϣ,Ĭ�ϵ�λΪ�� 
	 * Ĭ���趨Ϊ���ȸ���˳��: (1)λ�� (2)�ٶ� (3)���ٶ�
	 */
	void Step(const double duration = 0.1f);
	void addForce(const Vector3&);
};

