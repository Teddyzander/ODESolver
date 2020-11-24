#ifndef MVECTOR_H
#define MVECTOR_H

#include <vector> // bring in vector library

// class that represents mathematical vector.
// trivial functions are defined here. Complex functions are defined in .cpp
class MVector 
{
public:
	// constructors
	MVector() {}
	explicit MVector(int n) : v(n) {}
	MVector(int n, double x) : v(n, x) {}
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

// operator for "scalar * vector"
inline MVector operator*(const double& lhs, const MVector rhs)
{
	MVector temp = rhs; // return vector will be same dimension as rhs, so preallocate memory

	// for each element in rhs, multiply by lhs and store value in same element in temp
	for (int i = 0; i < temp.size(); i++)
	{
		temp[i] *= lhs;
	}

	return temp;
}

inline double operator*(const MVector rhs, const MVector lhs)
{
	// check that rhs and lhs are the same size
}

#endif
