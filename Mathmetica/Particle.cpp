#include "stdafx.h"
#include "Particle.h"

void Particle::UpdatePosition(const double duration)
{
	position_ += velocity_ * duration + acceleration_ * duration*duration * 0.5;
}

void Particle::UpdateVelocity(const double duration)
{
	velocity_ += acceleration_ * duration;
	velocity_ *= damping_;
}

void Particle::Step(const double duration)
{
	UpdatePosition(duration);
	UpdateVelocity(duration);
}

void Particle::addForce(const Vector3& force)
{
	forceAccum_ += force;
}
