#ifndef FALKNERSKANEQ_H
#define FALKNERSKANEQ_H

#include "mFunction.h"

// Specific function class is derived from generic function class
/*
Function is in the form of FunctionF1(x, y) = [y[1],
											   y[2],
											   kappa * (y[1]^2 - 1) - y[0] * y[2]]
*/
class FalknerSkanEq : public MFunction
{
public:

	FalknerSkanEq() { beta = 0; }

	// overload pure virtual function from MFunction
	virtual MVector operator()(const double& x, const MVector& y)
	{
		// create vector to return calculated values
		MVector temp(6);

		// calculate values and return them
		temp[0] = y[1];
		temp[1] = y[2];
		temp[2] = -y[0] * y[2] - beta * (1 - y[1] * y[1]);
		temp[3] = y[4];
		temp[4] = y[5];
		temp[5] = -y[0] * y[5] - y[2] * y[3] + 2 * beta * y[1] * y[4];

		return temp;
	}

	void SetBeta(double b) { beta = b; } // change kappa

private:
	double beta;
};

#endif
