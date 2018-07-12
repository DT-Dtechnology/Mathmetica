#pragma once
#include <cmath>
#include <cassert>
#include <iostream>

struct Complex
{
	double real_;
	double image_;

	Complex(double real, double image) :real_(real), image_(image) { ; }
	Complex(double angle) :Complex(cos(angle), sin(angle)) { ; }
	Complex() = default;

	void operator+=(const Complex&);
	void operator-=(const Complex&);
	void operator*=(const Complex&);
	void operator/=(const Complex&);
	void operator*=(const double);

	Complex operator+(const Complex&) const;
	Complex operator*(const double) const;
	Complex operator*(const Complex&) const;

	double Length() const;
	double Radiant() const;
	Complex Inverse() const;
	Complex Rotate(double angle) const;
	Complex Conjugate() const;
	Complex Opposite() const;
};

template<signed n>
struct Vector
{
	double array[n]{};
	int size = n;

	Vector<n>() = default;
	Vector<n>(double*);
	~Vector<n>() = default;

	double operator[](const int position);
	Vector<n> operator+(const Vector<n>&);
	Vector<n> operator*(const double);
	void operator+=(const Vector<n>&);
	void operator*=(const double);
	double operator*(const Vector<n>&);
	
	double Length() const;
	Vector<n> Opposite();
	Vector<n> Unitized();
};

template <int n>
Vector<n>::Vector(double* data)
{
	for (auto it = 0; it < size; ++it)
		array[it] = data[it];
}

template <int n>
double Vector<n>::operator[](const int position)
{
	assert(position < size);
	return array[position];
}

template <int n>
Vector<n> Vector<n>::operator+(const Vector<n>& vector)
{
	double data[n];
	for (auto it = 0; it < size; ++it)
		data[it] = array[it] + vector.array[it];
	return Vector<n>(data);
}

template <int n>
Vector<n> Vector<n>::operator*(const double rate)
{
	double data[n];
	for (auto it = 0; it < size; ++it)
		data[it] = array[it] * rate;
	return Vector<n>(data);
}

template <int n>
void Vector<n>::operator+=(const Vector<n>& vector)
{
	assert(vector.size == size);
	for (auto it = 0; it < size; ++it)
		array[it] += vector.array[it];
}

template <int n>
void Vector<n>::operator*=(const double rate)
{
	for (auto it = 0; it < size; ++it)
		array[it] *= rate;
}

template <int n>
double Vector<n>::operator*(const Vector<n>& vector)
{
	double value = 0;
	for (auto it = 0; it < size; ++it)
		value += array[it] * vector.array[it];
	return value;
}

template <int n>
double Vector<n>::Length() const
{
	double value = 0;
	for (auto it = 0; it < size; ++it)
		value += array[it] * array[it];
	return sqrt(value);
}

template <int n>
Vector<n> Vector<n>::Opposite()
{
	double data[n];
	for (auto it = 0; it < size; ++it)
		data[it] = -array[it];
	return Vector<n>(data);
}

template <int n>
Vector<n> Vector<n>::Unitized()
{
	const double length = Length();
	assert(length != 0);
	double data[n];
	for (auto it = 0; it < size; ++it)
		data[it] = array[it]/length;
	return Vector<n>(data);
}

typedef Vector<2> Vector2;
typedef Vector<3> Vector3;


#ifdef DEBUG
void print_test(const Complex&);
template<signed n>
void print_test(const Vector<n>&);

template<signed n>
void print_test(const Vector<n>& vector)
{
	std::cout << "Vector(" << vector.size << ")" << std::endl;
	std::cout << "Array: ";
	for (auto it = 0; it < vector.size; ++it)
		std::cout << vector.array[it] << " ";
	std::cout << std::endl << std::endl;
}
#endif
