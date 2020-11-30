#include <iostream>
#include <cmath>
#include <fstream>

#include "EulerSolve.h"
#include "functionF2.h"
#include "functionF1.h"

int main()
{
	FunctionF2 f;
	SolverOutput data;

	for (int i = 10; i < 1281; i *= 2)
	{
		MVector y1({ 0, 1 });
		data = EulerSolve(i, 0, 1, y1, f, true);
		MVector y2({ 0, 1 });
		data = RungeKutta(i, 0, 1, y2, f, true);
	}

	return 0;
}
