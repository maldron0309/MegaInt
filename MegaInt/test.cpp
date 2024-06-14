#include <iostream>
#include "MegaInt.h"

int main()
{
	MegaInt num1("123456789012345678901234567890");
	MegaInt num2("123456789012345678901234567890");

	MegaInt sum = num1 - num2;

	std::cout << sum;

}