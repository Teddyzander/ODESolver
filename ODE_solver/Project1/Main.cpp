#include <iostream>
#include<cmath>
#include "mvector.h"

int main()
{
	MVector test_1(3, 3);
	MVector test_2({3, 6, 9});
	MVector test_3({1, 1, 1, 1});

	std::cout << test_1 << std::endl;
	std::cout << test_2 << std::endl;
	std::cout << (5 * test_2) << std::endl;
	std::cout << (test_2 * 5) << std::endl;
	std::cout << (test_2 / 3) << std::endl;
	std::cout << (test_1 + test_2) << std::endl;
	std::cout << (test_2 - test_1) << std::endl;

	std::cout << (test_1 + test_3) << std::endl;

	return 0;
}
