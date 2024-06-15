# MegaInt

[Korean](./README.md) | [English](./README_EN.md)

This library is created to facilitate large number operations beyond unsigned long long in C++, eliminating the need for cumbersome string operations.

## Installation
`include "MegaInt.h"`  to use the library.

### Features
- **operator+**: Addition of large numbers
- **operator-**: Subtraction of large numbers
- **operatorx**: Multiplication of large numbers
- ~~operator/~~: Division of large numbers (currently under development)
  
## Usage Examples

### Traditional String-based Approach
```cpp
#include <iostream>
#include <string>
#include <algorithm>

// String operation
std::string AddString(const std::string& num1, const std::string& num2)
{
    std::string result;
    int carry = 0;
    int len1 = num1.size();
    int len2 = num2.size();
    int maxLen = std::max(len1, len2);

    for (int i = 0; i < maxLen; ++i) {
        int digit1 = (i < len1) ? num1[len1 - 1 - i] - '0' : 0;
        int digit2 = (i < len2) ? num2[len2 - 1 - i] - '0' : 0;
        int addition = digit1 + digit2 + carry;
        carry = addition / 10;
        result.insert(result.begin(), (addition % 10) + '0');
    }

    if (carry) {
        result.insert(result.begin(), carry + '0');
    }

    return result;
}

int main() 
{
    std::string num1 = "123456789012345678901";
    std::string num2 = "123456789012345678901";

    std::string addition = AddString(num1, num2);
    std::cout << "Addition: " << addition << std::endl;

    return 0;
}
```

### Using the MegaInt Library
```cpp
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
	std::cout << "Multiplication: " << multiplication << std::endl;

}
```

## Roadmap
- Currently developing the division feature.

## Contributing
If you'd like to contribute to this project, please open an Issue or a Pull Request. All contributions are welcome!
