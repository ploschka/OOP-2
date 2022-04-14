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
    if(number[0] == '-')
    {
        negative = true;
        number.erase(0, 1);
    }
}

BigInteger BigInteger::operator+(const BigInteger& other) const
{
    if(this->negative < other.negative)
    {
        return (*this - other);
    }
    else if(other.negative < this->negative)
    {
        return (other - *this);
    }
    unsigned char buffer;
    BigInteger result;
    result.negative = this->negative;
    result.number = '0';

    std::string::const_reverse_iterator rIter = number.crbegin();
    std::string::const_reverse_iterator orIter = other.number.crbegin();

    std::string::const_reverse_iterator erIter = number.crend();
    std::string::const_reverse_iterator oerIter = other.number.crend();

    while(rIter != erIter && orIter != oerIter)
    {
        buffer = (*rIter + *orIter + result.number[0]) - (2 * '0');
        if(buffer > '9')
        {
            result.number[0] = buffer - 10;
            result.number.insert(0, 1, '1');
        }
        else
        {
            result.number[0] = buffer;
            result.number.insert(0, 1, '0');
        }
        rIter++;
        orIter++;
    }
    if(rIter == erIter)
    {
        result.number.insert(0, other.number.substr(0, oerIter - orIter));
    }
    else
    {
        result.number.insert(0, this->number.substr(0, erIter - rIter));
    }

    result.shrink();
    return result;
}

BigInteger BigInteger::operator-(const BigInteger& other) const
{

}

BigInteger BigInteger::operator*(const BigInteger& other) const
{

}

void BigInteger::operator=(const BigInteger& other)
{
    this->number = other.number;
    this->negative = other.negative;
}

bool BigInteger::operator<(const BigInteger& other) const
{

}

bool BigInteger::operator<=(const BigInteger& other) const
{

}

bool BigInteger::operator>(const BigInteger& other) const
{

}

bool BigInteger::operator>=(const BigInteger& other) const
{

}

bool BigInteger::operator==(const BigInteger& other) const
{

}

BigInteger BigInteger::operator+(const int& other) const
{

}

BigInteger BigInteger::operator-(const int& other) const
{

}

BigInteger BigInteger::operator*(const int& other) const
{

}

void BigInteger::operator=(const int& other)
{
    this->number = std::to_string(other);
    this->negative = (other < 0);
}

bool BigInteger::operator<(const int& other) const
{
    
}

bool BigInteger::operator<=(const int& other) const
{

}

bool BigInteger::operator>(const int& other) const
{

}

bool BigInteger::operator>=(const int& other) const
{

}

bool BigInteger::operator==(const int& other) const
{
    
}

std::ostream& operator<<(std::ostream& out, const BigInteger& bigInt)
{
    if(bigInt.negative)
        out << '-';
    out << bigInt.number;    
}