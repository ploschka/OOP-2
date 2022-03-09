#pragma once

#include <iostream>

class BigInteger
{
private:
    void* data;

public:
    BigInteger(const std::string number);
    BigInteger(const int number);
    ~BigInteger();

    BigInteger& operator+(const BigInteger& other) const;
    BigInteger& operator-(const BigInteger& other) const;
    BigInteger& operator*(const BigInteger& other) const;
    BigInteger& operator/(const BigInteger& other) const;

    BigInteger& operator+(const int other) const;
    BigInteger& operator-(const int other) const;
    BigInteger& operator*(const int other) const;
    BigInteger& operator/(const int other) const;

    friend std::ostream& operator<<(std::ostream& out, const BigInteger& data);
};