#include "stdafx.h"
#include "BasicStruct.h"
#include <cassert>
#include <iostream>

void Complex::operator+=(const Complex& complex)
{
	real_ += complex.real_;
	image_ += complex.image_;
}

void Complex::operator-=(const Complex& complex)
{
	real_ -= complex.real_;
	image_ -= complex.image_;
}

void Complex::operator*=(const Complex& complex)
{
	double a = real_, b = image_;
	real_ = a * complex.real_ - b * complex.image_;
	image_ = a * complex.image_ + b * complex.real_;
}

void Complex::operator/=(const Complex& complex)
{
	(*this)*=complex.Inverse();
}

void Complex::operator*=(const double rate)
{
	real_ *= rate;
	image_ *= rate;
}

Complex Complex::operator+(const Complex& complex) const
{
	return {real_ + complex.real_, image_ + complex.image_};
}

Complex Complex::operator*(const double rate) const
{
	return { real_ * rate, image_ * rate };
}

Complex Complex::operator*(const Complex& complex) const
{
	return { real_*complex.real_ - image_ * complex.image_, real_*complex.image_ + image_ * complex.real_ };
}

double Complex::Length() const
{
	return sqrt(real_*real_ + image_ * image_);
}

double Complex::Radiant() const
{
	return atan(image_ / real_);
}

Complex Complex::Inverse() const
{
	assert(Length() >0);
	return Complex(*this)*(1 / (Length()*Length()));
}

Complex Complex::Conjugate() const
{
	return {real_, -image_};
}

Complex Complex::Opposite() const
{
	return {-real_, -image_};
}

Complex Complex::Rotate(double angle) const
{
	return Complex(*this)*Complex(angle);
}

#ifdef DEBUG
void print_test(const Complex& complex)
{
	std::cout << "Complex:" << std::endl;
	std::cout << "Real: " << complex.real_ << "  Image: " << complex.image_ << std::endl << std::endl;
}
#endif
