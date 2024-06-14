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
	~MegaInt();

	MegaInt operator+(const MegaInt& other) const;
	MegaInt operator-(const MegaInt& other) const;
	MegaInt operator*(const MegaInt& other) const;
	MegaInt operator/(const MegaInt& other) const;

	friend std::ostream& operator<<(std::ostream& os, const MegaInt& obj);

private:
	std::string value;

	// 큰 수 더하기
	static std::string MegaAdd(const std::string& num1, const std::string& num2);
	static std::string MegaSub(const std::string& num1, const std::string& num2);
	static std::string MegaMultip(const std::string& num1, const std::string& num2);
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
	return MegaInt();
}

MegaInt MegaInt::operator/(const MegaInt& other) const
{
	return MegaInt();
}

std::ostream& operator<<(std::ostream& os, const MegaInt& obj)
{
	os << obj.value; // 올바르게 obj.value로 수정
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
		else
			borrow = 0;

		result.insert(result.begin(), diff + '0');
	}

	result.erase(0, std::min(result.find_first_not_of('0'), result.size() - 1));

	return result;
}

#endif
