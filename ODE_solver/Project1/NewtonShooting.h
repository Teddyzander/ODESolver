#ifndef NEWTONSHOOTING_H
#define NEWTONSHOOTING_H

#include "falknerSkanEq.h"
#include "EulerSolve.h"
/*
INPUT:
beta (double): parameter for angle of the wedge fluid is flowing past
guess (float): initial guess for f''(0)
bound (int): upper bound for eta
maxNewtonSteps (int): Maximum number to get solution
RungeKuttaSteps (int): Number of RK$ steps for each iteration of the 
shooting method

*/

double FSBoundary(double guess = 0, double beta = 0, int bound = 5,
	int maxNewtonSteps = 100, int RungeKuttaSteps = 100)
{
	FalknerSkanEq f;
	MVector y(6);
	f.SetBeta(beta);
	double tol = 1e-8;
	double phi;
	double phidash;

	for (int i = 0; i < maxNewtonSteps; i++)
	{

		y[0] = 0; y[1] = 0; y[2] = guess;
		y[3] = 0; y[4] = 0; y[5] = 1;

		SolverOutput result = RungeKutta(RungeKuttaSteps, 
			0, bound, y, f);

		phi = result.y[1] - 1;
		phidash = result.y[4];

		if (abs(phi) < tol) break;

		guess -= phi / phidash;
	}

	return guess;
}

#endif
