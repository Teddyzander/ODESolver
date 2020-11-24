#include <iostream>
#include<cmath>
#include "mvector.h"

int main()
{
	MVector test_1(3, 3);
	MVector test_2({3, 6, 9});

	std::cout << test_1 << std::endl;
	std::cout << test_2 << std::endl;
	std::cout << (5 * test_2) << std::endl;


	return 0;
}
