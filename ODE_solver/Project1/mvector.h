#ifndef MVECTOR_H
#define MVECTOR_H

#include <vector> // bring in vector library

//Class that represents mathematical vector
class MVector 
{
public:
	// constructors
	MVector() {}
	explicit MVector(int n) : v(n) {}
	MVector(int n, double x) : v(n, x) {}
	MVector(std::initializer_list<double> l) : v(l) {}

private:
	std::vector<double> v;
};

#endif
