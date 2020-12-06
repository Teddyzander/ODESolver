#ifndef FUNCTIONF2_H
#define FUNCTIONF2_H

#include "mFunction.h"

// Specific function class is derived from generic function class
/*
Function is in the form of FunctionF1(x, y) = [x, y[1]]
*/
class FunctionF2 : public MFunction
{
public:

	// overload pure virtual function from MFunction
	virtual MVector operator()(const double& x, const MVector& y)
	{
		// create vector to return calculated values
		MVector temp(2);

		// calculate values and return them
		temp[0] = x;
		temp[1] = y[1];

		return temp;
	}

};

#endif