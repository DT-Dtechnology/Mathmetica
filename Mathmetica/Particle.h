#pragma once
#include "BasicStruct.h"

/**
 * \brief 具体对象：粒子
 * 简述：基本的粒子，利用组合的方式记录位置、速度、加速度、阻尼
 */
class Particle
{
	// 基本信息
	Vector3 position_;
	Vector3 velocity_;
	Vector3 acceleration_;

	Vector3 forceAccum_;

	// 阻尼，1表示无阻尼
	double damping_ = 1.00;

	// 质量的倒数，方便计算加速度
	double inserse_mass_;
	// 质量，方便计算引力
	double mass_;

	void UpdatePosition(const double duration);
	void UpdateVelocity(const double duration);

public:
	Particle() = default;
	~Particle() = default;

	/**
	 * \brief 核心运行函数，基于时间进行单步运算，从而推算出下一步的状态信息,默认单位为秒 
	 * 默认设定为优先更新顺序: (1)位置 (2)速度 (3)加速度
	 */
	void Step(const double duration = 0.1f);
	void addForce(const Vector3&);
};

