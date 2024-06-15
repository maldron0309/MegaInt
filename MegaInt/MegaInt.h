#ifndef MEGAINT_H
#define MEGAINT_H

#include <iostream>
#include <vector>
#include <algorithm>

class MegaInt
{
public:
	MegaInt();
	MegaInt(const std::string& value);
	MegaInt(const char* value);
	~MegaInt();

	MegaInt operator+(const MegaInt& other) const;
	MegaInt operator-(const MegaInt& other) const;
	MegaInt operator*(const MegaInt& other) const;
	MegaInt operator/(const MegaInt& other) const;

	friend std::ostream& operator<<(std::ostream& os, const MegaInt& obj);

private:
	std::string value;

	static std::string MegaAdd(const std::string& num1, const std::string& num2);
	static std::string MegaSub(const std::string& num1, const std::string& num2);
	static std::string MegaMultiply(const std::string& num1, const std::string& num2);
	static std::string MegaDivide(const std::string& num1, const std::string& num2);
};

MegaInt::MegaInt()
{
}

MegaInt::~MegaInt()
{
}

MegaInt::MegaInt(const std::string& value) : value(value)
{
}

MegaInt::MegaInt(const char* value) : value(value) {}

MegaInt MegaInt::operator+(const MegaInt& other) const
{
	std::string result = MegaAdd(this->value, other.value);
	return MegaInt(result);
}

MegaInt MegaInt::operator-(const MegaInt& other) const
{
	std::string result = MegaSub(this->value, other.value);
	return MegaInt(result);
}

MegaInt MegaInt::operator*(const MegaInt& other) const
{
	std::string result = MegaMultiply(this->value, other.value);
	return MegaInt(result);
}

MegaInt MegaInt::operator/(const MegaInt& other) const
{
	return MegaInt();
}

std::ostream& operator<<(std::ostream& os, const MegaInt& obj)
{
	os << obj.value;
	return os;
}

std::string MegaInt::MegaAdd(const std::string& num1, const std::string& num2)
{
	std::string result = "";
	int carry = 0;
	int max_length = std::max(num1.length(), num2.length());

	for (int i = 0; i < max_length; ++i)
	{
		int digit1 = (i < num1.length()) ? (num1[num1.length() - 1 - i] - '0') : 0;
		int digit2 = (i < num2.length()) ? (num2[num2.length() - 1 - i] - '0') : 0;

		int sum = digit1 + digit2 + carry;
		carry = sum / 10;
		sum %= 10;

		result.insert(result.begin(), sum + '0');
	}

	if (carry > 0)
		result.insert(result.begin(), carry + '0');

	return result;
}

std::string MegaInt::MegaSub(const std::string& num1, const std::string& num2)
{
	std::string result = "";
	int borrow = 0;
	int max_length = std::max(num1.length(), num2.length());

	for (int i = 0; i < max_length; ++i)
	{
		int digit1 = (i < num1.length()) ? (num1[num1.length() - 1 - i] - '0') : 0;
		int digit2 = (i < num2.length()) ? (num2[num2.length() - 1 - i] - '0') : 0;

		int diff = digit1 - digit2 - borrow;

		if (diff < 0)
		{
			diff += 10;
			borrow = 1;
		}
		else borrow = 0;

		result.insert(result.begin(), diff + '0');
	}

	result.erase(0, std::min(result.find_first_not_of('0'), result.size() - 1));

	return result;
}

std::string MegaInt::MegaMultiply(const std::string& num1, const std::string& num2)
{
	int digit1 = num1.size();
	int digit2 = num2.size();

	if (num1 == "0" || num2 == "0") return "0";

	std::vector<int> temp(digit1 + digit2, 0); // 임시 저장

	for (int i = digit1 - 1; i >= 0; i--)
	{
		for (int j = digit2 - 1; j >= 0; j--)
		{
			auto mul = (num1[i] - '0') * (num2[j] - '0'); // 현재 자릿수 곱셈
			auto sum = temp[i + j + 1] + mul; // 기존 값 + 곱셈 결과 

			temp[i + j + 1] = sum % 10; // 현재 자릿수 저장
			temp[i + j] += sum / 10; // 올림 값 다음 자릿수에 저장
		}
	}

	std::string result;
	for (int num : temp)
	{
		if (!(result.empty() && num == 0)) result.push_back(num + '0'); // 필요없는 0 제거
	}

	return result.empty() ? "0" : result; // 비어있으면 0 반환
}



#endif
