#include <iostream>
#include "MegaInt.h"

int main()
{
	MegaInt num1 = "123456789012345678901234567890";
	MegaInt num2 = "123456789012345678901234567890";

	MegaInt addition = num1 + num2;
	MegaInt subtraction = num1 - num2;
	MegaInt multiplication = num1 * num2;

	std::cout << "Addition: " << addition << std::endl;
	std::cout << "Subtraction: " << subtraction << std::endl;
	std::cout << "Multiplication " << multiplication << std::endl;

}