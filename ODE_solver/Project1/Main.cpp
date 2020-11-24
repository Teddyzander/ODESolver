#include <iostream>
#include<cmath>
#include "mvector.h"

int main()
{
	MVector test_1(3, 6);
	MVector test_2({ 1, 2, 3, 4 });

	std::cout << test_1[0] << std::endl;
	std::cout << test_2[3] << std::endl;

	return 0;
}
