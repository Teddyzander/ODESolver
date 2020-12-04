#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>

#include "EulerSolve.h"
#include"falknerSkanEq.h"
#include "functionF2.h"
#include "functionF1.h"

/*
Function caluclates estimate for 

*/

double FSBoundary(double beta = 0, float guess = 0, int bound = 500,
	int maxNewtonSteps = 1000, int RungeKuttaSteps = 1000)
{
	FalknerSkanEq f;
	MVector y(6);
	f.SetBeta(beta);
	double tol = 1e-16;
	double phi;
	double phidash;

	for (int i = 0; i < maxNewtonSteps; i++)
	{

		y[0] = 0; y[1] = 0; y[2] = guess;
		y[3] = 0; y[4] = 1; y[5] = 1;

		SolverOutput result = RungeKutta(RungeKuttaSteps, 0, bound, y, f);

		phi = result.y[1] - 1;
		phidash = result.y[4];

		if (abs(phi) < tol) break;

		guess -= phi / phidash;
	}

	return guess;
}

int main()
{
	/*
	FunctionF2 f;
	SolverOutput data_euler, data_rungekutta;

	std::ofstream eulerErrorFile, rungekuttaErrorFile;

	eulerErrorFile.open("eulerErrors.txt");
	rungekuttaErrorFile.open("rungekuttaErrors.txt");

	double act_y0 = 0.5;
	double act_y1 = exp(1);

	for (int i = 10; i < 20000; i *= 2)
	{
		MVector y1({ 0, 1 });
		data_euler = EulerSolve(i, 0, 1, y1, f, true);
		MVector y2({ 0, 1 });
		data_rungekutta = RungeKutta(i, 0, 1, y2, f, true);

		if (eulerErrorFile.is_open())
		{
			eulerErrorFile << "steps: " << i << "\t errors: " << abs(data_euler.y[0] - act_y0)  << "\t" << abs(data_euler.y[1] - act_y1) << std::endl;
		}

		if (rungekuttaErrorFile.is_open())
		{
			rungekuttaErrorFile << "steps: " << i << "\t errors: " << abs(data_rungekutta.y[0] - act_y0) << "\t" << abs(data_rungekutta.y[1] - act_y1) << std::endl;
		}
	}

	eulerErrorFile.close();
	rungekuttaErrorFile.close();
	*/
	
	/*
	float beta = 0.6;
	double guess = 0.47;
	double bound = 5;
	
	double fdash_est = FSBoundary(beta, guess, bound);

	std::ofstream myFile;
	myFile.open("FalknerSkanBetaF3.txt");

	while (beta <= 1.05)
	{
		double fdash_est = FSBoundary(beta, guess, bound);


		std::cout << "beta: " << beta << "\tf''(0) = " << fdash_est << std::endl;
		myFile << beta << "\t" << fdash_est << std::endl;

		beta += 0.001;
		guess = fdash_est;

		if (std::to_string(guess) == "-nan(ind)")
		{
			guess = 0.5;
		}

	}

	myFile.close();
	*/
	/*
	float beta = 0.2;
	double guess = 0.47;
	double bound = 5;

	double fdash_est = FSBoundary(beta, guess, bound);

	double c_bound = 0;

	std::ofstream myFile;
	myFile.open("fdash02.txt");

	while (c_bound < 5)
	{
		MVector y(6);
		FalknerSkanEq f;

		y[0] = 0; y[1] = 0; y[2] = fdash_est;
		y[3] = 0; y[4] = 0; y[5] = 1;

		SolverOutput result = RungeKutta(5000, 0, c_bound, y, f);

		myFile << c_bound << "\t" << result.y[1] << std::endl;

		c_bound += 0.1;
	}

	myFile.close();

	*/

	double guess = 1.23;
	FalknerSkanEq f;
	int maxNewtonSteps = 100;
	double phi, phidash;
	double tol = 1e-8;
	MVector y(6);

	f.SetBeta(1.0);

	for (int i = 0; i < maxNewtonSteps; i++)
	{

		y[0] = 0; y[1] = 0; y[2] = guess;
		y[3] = 0; y[4] = 0; y[5] = 2;

		SolverOutput result = RungeKutta(1000, 0, 5, y, f);

		phi = result.y[1] - 1;
		phidash = result.y[3];

		std::cout << "f'(5): " << result.y[1] << "\tf''(5): " << result.y[2] << "\tf''(0): " << guess << std::endl;

		if (abs(phi) < tol)
		{
			std::cout << "end: " << y << std::endl;
			break;
		}

		guess -= phi / phidash;

	}

	
	
	std::cout << "--------------------------------" << std::endl;

	f.SetBeta(1 / 3);

	for (int i = 0; i < maxNewtonSteps; i++)
	{

		y[0] = 0; y[1] = 0; y[2] = guess;
		y[3] = 0; y[4] = 0; y[5] = 1;

		SolverOutput result = RungeKutta(10000, 0, 5, y, f);

		phi = result.y[1] - 1;
		phidash = result.y[3];

		if (abs(phi) < tol) break;

		guess -= phi / phidash;

	}

	std::cout << "F'''(0) = " << guess << std::endl;

	std::cout << "--------------------------------" << std::endl;

	f.SetBeta(10/11);

	for (int i = 0; i < maxNewtonSteps; i++)
	{

		y[0] = 0; y[1] = 0; y[2] = guess;
		y[3] = 0; y[4] = 0; y[5] = 1;

		SolverOutput result = RungeKutta(10000, 0, 5, y, f);

		phi = result.y[1] - 1;
		phidash = result.y[3];

		if (abs(phi) < tol) break;

		guess -= phi / phidash;

	}

	std::cout << "F'''(0) = " << guess << std::endl;
	
	return 0;

}
