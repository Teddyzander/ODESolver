#ifndef EULERSOLVE_H
#define EULERSOLVE_H

#include "mFunction.h"
#include<fstream>

struct SolverOutput {
	int error;
	double x;
	MVector y;
};

/*
Function to estimate the value(s) of a function(s) at x = b

INPUTS:

steps (int): integer for number of steps wanted between a and b
a (double): value of x to start estimates at
b (double): value of x to end estimates at
y (MVector): vector to hold estimated values of y at each step
f (MFunction): function(s) to evaluate

OUTPUTS:

error (int): An error code to describe problems the analysis may have encountered
*/
SolverOutput EulerSolver(int steps, double a, double b, MVector& y, MFunction& f)
{
	// Struct to hold return values and error value
	SolverOutput result;
	// declare the initial starting point for x
	double x;
	// calculate the size of each step
	double h = abs(a - b) / steps;

	// loop over
	for (int i = 0; i < steps - 1; i++)
	{
		x = a + i * h;

		y = y + h * f(x, y);
	}

	x = b;
	std::cout << "x: " << x << "\ny: " << y << std::endl;
	
	result.x = x;
	result.y = y;
	result.error = 0;

	return result;
}

#endif
