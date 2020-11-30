#include <iostream>
#include <cmath>

#include "EulerSolve.h"
#include "functionF2.h"
#include "functionF1.h"

int main()
{
	MVector y({ 0, 1 });
	FunctionF2 f;
	EulerSolver(160, 0, 1, y, f);

	return 0;
}
