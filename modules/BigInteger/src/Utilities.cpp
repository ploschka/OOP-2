#include "BigInteger.h"

void BigInteger::shrink()
{
    std::string::iterator iter = number.begin();
    std::string::iterator from = iter;
    std::string::iterator eIter = (number.end() - 1);
    while((iter != eIter) && (*iter == '0'))
        iter++;
    number.erase(from, iter);
    if(number[0] == '0')
        negative = false;
    this->number.shrink_to_fit();
}

void BigInteger::mirror()
{
    std::string::iterator bIter = this->number.begin();
    std::string::iterator eIter = this->number.end() - 1;

    while (bIter < eIter)
    {
        std::swap(*bIter, *eIter);
        bIter++;
        eIter--;
    }
    this->shrink();
}

BigInteger::BigInteger(const std::string& aNumber)
{
    if(aNumber.empty())
        throw std::invalid_argument("Empty string");
    
    std::string::const_iterator iter = aNumber.cbegin();
    std::string::const_iterator eIter = aNumber.cend();

    if(aNumber[0] == '-')
    {
        negative = true;
        iter++;
    }
    for(;iter != eIter; iter++)
    {
        if((*iter < '0') || (*iter > '9'))
            throw std::invalid_argument("Argument is not a number");
        number.push_back(*iter);
    }
    shrink();
}

BigInteger::BigInteger(const int aNumber)
{
    number = std::to_string(aNumber);
    if(aNumber < 0)
    {
        negative = true;
        number.erase(0, 1);
    }
}

BigInteger::BigInteger(const BigInteger& other)
{
    this->number = other.number;
    this->negative = other.negative;
}

void BigInteger::operator=(const BigInteger& other)
{
    this->number = other.number;
    this->negative = other.negative;
}

void BigInteger::operator=(const int& other)
{
    this->number = std::to_string(other);
    this->negative = (other < 0);
}

std::ostream& operator<<(std::ostream& out, const BigInteger& bigInt)
{
    if(bigInt.negative)
        out << '-';
    out << bigInt.number;
    return out;
}