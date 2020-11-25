#ifndef MVECTOR_H
#define MVECTOR_H

#include <vector> // bring in vector library
#include <assert.h> // bring in assert library for some minor error handling

// class that represents mathematical vector.
// trivial functions are defined here. Complex functions are defined in .cpp
class MVector 
{
public:
	// constructors
	MVector() {}
	explicit MVector(int n) : v(n) {}
	MVector(int n, double x) : v(n, x)	{}
	MVector(std::initializer_list<double> l) : v(l) {}

	// element accessors 

	// access mutable element at index "index" (read and write)
	double &operator[](int index) { return v[index]; }

	// access immutable element at index "index" (read only)
	double operator[](int index) const { return v[index];  }

	// get number of elements in vector
	int size() const { return v.size(); }

private:
	std::vector<double> v;
};

/*
Operator overloads for vectors
*/

// operator for "scalar * vector"
inline MVector operator*(const double& lhs, const MVector& rhs)
{
	MVector temp = rhs; // return vector will be same dimension as rhs, so preallocate memory

	// for each element in rhs, multiply by lhs and store value in same element in temp
	for (int i = 0; i < temp.size(); i++)
	{
		temp[i] *= lhs;
	}

	return temp;
}

// operator for "vector * scalar"
inline MVector operator*(const MVector& lhs, const double& rhs)
{
	// use scalar * operator so we only need to maintain one function (order is irrelevant)
	MVector temp = rhs * lhs;

	return temp;
}

// operator for "vector / scalar"
inline MVector operator/(const MVector& lhs, const double& rhs)
{
	MVector temp = lhs; // return vector will be same dimension as rhs, so preallocate memory

	// for each element in rhs, multiply by lhs and store value in same element in temp
	for (int i = 0; i < temp.size(); i++)
	{
		temp[i] /= rhs;
	}

	return temp;
}

// operator for "vector + vector"
inline MVector operator+(const MVector& lhs, const MVector& rhs)
{
	// check vectors are of equal size
	assert(lhs.size() == rhs.size() && "Vectors must have equal size");

	MVector temp = lhs;

	// for each element in lhs, add it to rhs element
	for (int i = 0; i < temp.size(); i++)
	{
		temp[i] += rhs[i];
	}

	return temp;
}

// operator for "vector - vector"
inline MVector operator-(const MVector& lhs, const MVector& rhs)
{
	// check vectors are of equal size
	assert(lhs.size() == rhs.size() && "Vectors must have equal size");

	MVector temp = lhs;

	// for each element in lhs, subtract it to rhs element
	for (int i = 0; i < temp.size(); i++)
	{
		temp[i] -= rhs[i];
	}

	return temp;
}

// ooperator for "<< vector" (prints vector to screen or file)
std::ostream& operator<<(std::ostream& os, const MVector& v)
{
	// get size of v and then print out all elements, surrounded by brackets
	int v_size = v.size();
	os << "(";

	for (int i = 0; i < v_size; i++)
	{
		os << v[i];

		if (i != v_size - 1)
		{
			os << ", ";
		}
	}

	os << ")";

	return os;
}

#endif
