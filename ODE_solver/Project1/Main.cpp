#include <iostream>
#include <cmath>
#include "mvector.h"
#include "mFunction.h"

/*
Function to estimate the behaviour of a function(s) between x = a and x = b

INPUTS:

steps (int): integer for number of steps wanted between a and b
a (double): value of x to start estimates at
b (double): value of x to end estimates at
y (MVector): vector to hold estimated values of y at each step
f (MFunction): function(s) to evaluate

OUTPUTS:

error (int): An error code to describe problems the analysis may have encountered
*/
int EulerSolver(int steps, double a, double b, MVector& y, MFunction& f)
{
	// declare the initial starting point for x
	double x;
	// calculate the size of each step
	double h = abs(a - b) / steps;

	// loop over
	for (int i = 0; i < steps - 1; i++)
	{
		x = a + i * h;

		y[i + 1] = y[i] + h * f(x, y[i]);
	}
}

int main()
{
	return 0;
}
