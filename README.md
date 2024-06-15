# MegaInt

[Korean](./README.md) | [English](./README_EN.md)

C++에서 unsigned long long을 넘어가는 큰 수 연산을 해야할 때 번거롭게 문자열 연산을 하는 것을 해소하기 위해 만든 라이브러리 입니다.

## 설치
`include "MegaInt.h"` 을 통해 라이브러리 사용이 가능합니다.

### 기능
- **operator+**: 큰 수 덧셈
- **operator-**: 큰 수 뺄셈
- **operatorx**: 큰 수 곱셈
- ~~operator/~~: 큰 수 나눗셈 (현재 개발중)
  
## 사용 예시

### 기존 입력 방식
```cpp
#include <iostream>
#include <string>
#include <algorithm>

// 문자열 연산
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

### MegaInt 라이브러리 적용 후
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

## 계획
- 현재 나눗셈 기능을 개발하고 있습니다.

## 기여하기
이 프로젝트에 기여하고 싶으시다면 Issues 또는 Pull Request를 열어주세요! 모든 기여는 환영합니다!


