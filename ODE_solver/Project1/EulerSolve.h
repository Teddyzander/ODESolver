#ifndef EULERSOLVE_H
#define EULERSOLVE_H

#include "mFunction.h"
#include <string>
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
save (bool): whether or not to save outputs to file

OUTPUTS:

result (SolverOutput): A struct holding estimated values for Y at x and an error code
*/
SolverOutput EulerSolve(int steps, double a, double b, MVector& y, MFunction& f, bool save = false)
{
	std::ofstream myFile;
	// Struct to hold return values and error value
	SolverOutput result;
	// declare the initial starting point for x
	double x;
	// calculate the size of each step
	double h = abs(a - b) / steps;

	if (save == true) { myFile.open("eulerSolver" + std::to_string(steps) + ".txt"); }

	// loop over
	for (int i = 0; i < steps - 1; i++)
	{
		x = a + i * h;

		if (save == true)
		{
			myFile << "step: " << i << "\t" << x << "\t" << y << std::endl;
		}

		y = y + h * f(x, y);
	}

	x = b;

	if (save == true)
	{
		myFile << "step: " << steps << "\t" << x << "\t" << y << std::endl;
	}


	myFile.close();

	std::cout << "x: " << x << "\ny: " << y << std::endl;

	result.x = x;
	result.y = y;
	result.error = 0;

	return result;
}

/*
Function to estimate the value(s) of a function(s) at x = b

INPUTS:

steps (int): integer for number of steps wanted between a and b
a (double): value of x to start estimates at
b (double): value of x to end estimates at
y (MVector): vector to hold estimated values of y at each step
f (MFunction): function(s) to evaluate
save (bool): whether or not to save outputs to file

OUTPUTS:

result (SolverOutput): A struct holding estimated values for Y at x and an error code
*/

SolverOutput RungeKutta(int steps, double a, double b, MVector& y, MFunction& f, bool save = false)
{
	std::ofstream myFile;
	// Struct to hold return values and error value
	SolverOutput result;
	// declare the initial starting point for x
	double x;
	// calculate the size of each step
	double h = abs(a - b) / steps;

	MVector k1, k2, k3, k4;

	if (save == true) { myFile.open("rungeKutta" + std::to_string(steps) + ".txt");	}

	// loop over
	for (int i = 0; i < steps - 1; i++)
	{
		x = a + i * h;

		if (save == true)
		{
			myFile << "step: " << i << "\t" << x << "\t" << y << std::endl;
		}

		k1 = f(x, y);
		k2 = f(x + h / 2, y + (h / 2) * k1);
		k3 = f(x + h / 2, y + (h / 2) * k2);
		k4 = f(x + h, y + h * k3);

		y = y + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4);
		
	}

	x = b;

	if (save == true)
	{
		myFile << "step: " << steps << "\t" << x << "\t" << y << std::endl;
	}


	myFile.close();

	std::cout << "x: " << x << "\ny: " << y << std::endl;

	result.x = x;
	result.y = y;
	result.error = 0;

	return result;
}

#endif