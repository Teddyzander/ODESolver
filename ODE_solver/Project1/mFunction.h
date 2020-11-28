#ifndef MFUNCTION_H
#define MFUNCTION_H

#include "mVector.h"

// pure virtual class for defining functions
// functions should be written as a class inheriting from this one
// with the () operator over-ridden
class MFunction
{
public:

	/*
	function to over-ride

	INPUTS
	x (double): constant for use by the function
	y (MVector): mathematical vector containing variables for the function

	OUTPUTS
	a mathematical vector
	*/
	virtual MVector operator()(const double& x,
							   const MVector& y) = 0;
};

#endif
