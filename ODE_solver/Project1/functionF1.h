#ifndef FUNCTIONF1_H
#define FUNCTIONF1_H

#include "mFunction.h"

// Specific function class is derived from generic function class
/*
Function is in the form of FunctionF1(x, y) = [y[0] + x * y[1],
											   x* y[0] - y[1]]
*/
class FunctionF1 : public MFunction
{
public:
	
	// overload pure virtual function from MFunction
	virtual MVector operator()(const double& x, const MVector& y)
	{
		// create vector to return calculated values
		MVector temp(2);

		// calculate values and return them
		temp[0] = y[0] + x * y[1];
		temp[1] = x * y[0] - y[1];

		return temp;
	}
};

#endif
