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

    BigInteger abs() const;

    BigInteger add(const BigInteger& other);
    BigInteger sub(const BigInteger& other);
    BigInteger mul(const BigInteger& other);

public:
    BigInteger() = default;
    BigInteger(const std::string& aNumber);
    BigInteger(const int aNumber);
    BigInteger(const BigInteger& other);
    ~BigInteger() = default;


    BigInteger operator-() const;

    BigInteger operator+(const BigInteger& other) const;
    BigInteger operator-(const BigInteger& other) const;
    BigInteger operator*(const BigInteger& other) const;
    void operator=(const BigInteger& other);
    bool operator<(const BigInteger& other) const;
    bool operator<=(const BigInteger& other) const;
    bool operator>(const BigInteger& other) const;
    bool operator>=(const BigInteger& other) const;
    bool operator==(const BigInteger& other) const;

    void operator=(const int& other);

    friend std::ostream& operator<<(std::ostream& out, const BigInteger& bigInt);
};
