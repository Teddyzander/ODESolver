#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>

#include "EulerSolve.h"
#include"falknerSkanEq.h"
#include "functionF2.h"
#include "functionF1.h"
#include "NewtonShooting.h"

int main()
{
	/*
	Find errors for euler and RK4 methods for different step sizes
	*/
	FunctionF2 f;
	SolverOutput data_euler, data_rungekutta;

	std::ofstream eulerErrorFile, rungekuttaErrorFile;

	eulerErrorFile.open("eulerErrors.txt");
	rungekuttaErrorFile.open("rungekuttaErrors.txt");

	double act_y0 = 0.5;
	double act_y1 = exp(1);

	for (int i = 2; i < 1025; i = i * i)
	{
		MVector y1({ 0, 1 });
		data_euler = EulerSolve(i, 0, 1, y1, f, true);
		MVector y2({ 0, 1 });
		data_rungekutta = RungeKutta(i, 0, 1, y2, f, true);

		
		if (eulerErrorFile.is_open())
		{
			eulerErrorFile << i << "\t" << data_euler.y[0] << "\t" << data_euler.y[1] << "\t" <<
				abs(data_euler.y[0] - act_y0)  << "\t" << abs(data_euler.y[1] - act_y1) << std::endl;
		}
		
		if (rungekuttaErrorFile.is_open())
		{
			rungekuttaErrorFile << i << "\t" << data_rungekutta.y[0] << "\t" << data_rungekutta.y[1] << "\t" <<
				abs(data_rungekutta.y[0] - act_y0) << "\t" << abs(data_rungekutta.y[1] - act_y1) << std::endl;
		}
	}

	eulerErrorFile.close();
	rungekuttaErrorFile.close();

	/*
	Calculate f''(0) for some values of beta
	*/

	std::cout << std::setprecision(16);
	double guess = 0.47;
	double beta = 0.0;

	double fdash_est = FSBoundary(guess, beta);

	std::cout << fdash_est << std::endl;

	guess = 0.7;
	beta = 1.0/3.0;

	fdash_est = FSBoundary(guess, beta);

	std::cout << fdash_est << std::endl;

	guess = 1.2;
	beta = 10.0 / 11.0;

	fdash_est = FSBoundary(guess, beta);

	std::cout << fdash_est << std::endl;

	guess = 0.85;
	beta = 0.4;

	fdash_est = FSBoundary(guess, beta);

	std::cout << fdash_est << std::endl;

	/*
	Calculate f''(0) for values of beta between 0 and 1
	*/
	
	guess = 0.47;
	beta = 0.0;

	std::ofstream myFile;
	myFile.open("fdashdash0.txt");

	while (beta < 1.01)
	{
		double fdash_est = FSBoundary(guess, beta);

		myFile << beta << "\t" << fdash_est << std::endl;
		
		guess = fdash_est;
		beta += 0.01;
	}

	myFile.close();
	
	return 0;

}
