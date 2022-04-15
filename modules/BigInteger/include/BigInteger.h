#pragma once

#include <iostream>
#include <exception>

class BigInteger
{
private:
    std::string number;
    bool negative = false;

    void shrink();

    void mirror();

public:
    BigInteger() = default;
    BigInteger(const std::string& aNumber);
    BigInteger(const int number);
    ~BigInteger() = default;

    BigInteger operator+(const BigInteger& other) const;
    BigInteger operator-(const BigInteger& other) const;
    BigInteger operator*(const BigInteger& other) const;
    void operator=(const BigInteger& other);
    bool operator<(const BigInteger& other) const;
    bool operator<=(const BigInteger& other) const;
    bool operator>(const BigInteger& other) const;
    bool operator>=(const BigInteger& other) const;
    bool operator==(const BigInteger& other) const;

    BigInteger operator+(const int& other) const;
    BigInteger operator-(const int& other) const;
    BigInteger operator*(const int& other) const;
    void operator=(const int& other);
    bool operator<(const int& other) const;
    bool operator<=(const int& other) const;
    bool operator>(const int& other) const;
    bool operator>=(const int& other) const;
    bool operator==(const int& other) const;

    friend std::ostream& operator<<(std::ostream& out, const BigInteger& bigInt);
};
