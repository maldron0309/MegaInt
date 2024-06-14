#include "MegaInt.hpp"

MegaInt::MegaInt() : isNegative(false) {}

MegaInt::MegaInt(const std::string& number) {
    if (number[0] == '-') {
        isNegative = true;
        parseDigits(number.substr(1));
    }
    else {
        isNegative = false;
        parseDigits(number);
    }
}

MegaInt MegaInt::operator+(const MegaInt& other) const {
    // TODO: Implement addition logic
    return MegaInt();
}

MegaInt MegaInt::operator-(const MegaInt& other) const {
    // TODO: Implement subtraction logic
    return MegaInt();
}

MegaInt MegaInt::operator*(const MegaInt& other) const {
    // TODO: Implement multiplication logic
    return MegaInt();
}

MegaInt MegaInt::operator/(const MegaInt& other) const {
    // TODO: Implement division logic
    return MegaInt();
}

bool MegaInt::operator==(const MegaInt& other) const {
    return (isNegative == other.isNegative) && (digits == other.digits);
}

std::ostream& operator<<(std::ostream& os, const MegaInt& number) {
    if (number.isNegative) os << '-';
    for (auto it = number.digits.rbegin(); it != number.digits.rend(); ++it) {
        os << *it;
    }
    return os;
}

void MegaInt::parseDigits(const std::string& number) {

