#include <iostream>
#include "MegaInt.h"

int main()
{
	MegaInt num1("123");
	MegaInt num2("456");

	MegaInt sum = num1 * num2;

	std::cout << sum;

}