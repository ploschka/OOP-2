#include "BigInteger.h"
#include <algorithm>

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

BigInteger BigInteger::add(const BigInteger& other) const
{
    unsigned char buffer;
    BigInteger result;
    result.negative = this->negative;
    result.number = '0';

    std::string::const_reverse_iterator rIter;
    std::string::const_reverse_iterator erIter;

    if(this->number.size() > other.number.size())
    {
        result.number.append(this->number);
        rIter = other.number.crbegin();
        erIter = other.number.crend();
    }
    else
    {
        result.number.append(other.number);
        rIter = this->number.crbegin();
        erIter = this->number.crend();        
    }

    std::string::reverse_iterator rrIter = result.number.rbegin();
    std::string::reverse_iterator rerIter = result.number.rend();

    while(rIter != erIter)
    {
        buffer = (*rIter + *rrIter) - '0';
        if(buffer > '9')
        {
            std::string::reverse_iterator tmpIter = rrIter;
            bool isIncremented = true;
            *tmpIter = buffer - 10;
            tmpIter++;
            while (isIncremented)
            {
                if (*tmpIter > '8')
                {
                    *tmpIter = '0';
                }
                else
                {
                    (*tmpIter)++;
                    isIncremented = false;
                }
                tmpIter++;
            }
        }
        else
        {
            *rrIter = buffer;
        }
        rIter++;
        rrIter++;
    }
    if (result.number[0] == '0') result.number.erase(result.number.begin());
    return result;
}

BigInteger BigInteger::sub(const BigInteger& other) const
{
    BigInteger result;
    std::string::const_reverse_iterator beginer;
    std::string::const_reverse_iterator ender;
    bool makeNeg;
    if(*this > other)
    {
        result = *this;
        beginer = other.number.crbegin();
        ender = other.number.crend();
        makeNeg = false;
    }
    else
    {
        result = other;
        beginer = this->number.crbegin();
        ender = this->number.crend();
        makeNeg = true;
    }
    auto resIter = result.number.rbegin();
    auto functor = [&resIter](char i)
    {
        if(*resIter >= i)
        {
            *resIter = *resIter - i + '0';
        }
        else
        {
            auto findIter = resIter + 1;
            while(*findIter == '0')
            {
                *findIter = '9';
                findIter++;
            }
            (*findIter)--;
            *resIter = *resIter + 10 - i + '0';
        }
        resIter++;
    };
    std::for_each(beginer, ender, functor);
    result.shrink();
    result.negative = makeNeg;
    return result;
}

BigInteger BigInteger::mul(const BigInteger& other) const
{

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

BigInteger BigInteger::abs() const
{
    BigInteger result(*this);
    result.negative = false;
    return result;
}

BigInteger BigInteger::operator-() const
{
    BigInteger result(*this);
    result.negative = this->negative ? false : true;
    return result;
}

BigInteger BigInteger::operator+(const BigInteger& other) const
{
    if(this->negative < other.negative)
    {
        return this->sub(other.abs());
    }
    else if(this->negative > other.negative)
    {
        return other.sub(this->abs());
    }
    return this->add(other);    
}

BigInteger BigInteger::operator-(const BigInteger& other) const
{
    if(this->negative < other.negative)
    {
        return this->add(other.abs());
    }
    else if(this->negative > other.negative)
    {
        return -(this->abs().add(other));
    }
    else if(this->negative && other.negative)
    {
        return other.abs().sub(this->abs());
    }
    else
    {
        return this->sub(other);
    }
}

BigInteger BigInteger::operator*(const BigInteger& other) const
{
    if(this->negative ^ other.negative)
    {
        return -(this->abs().mul(other.abs()));
    }
    else
    {
        return this->abs().mul(other.abs());
    }
}

void BigInteger::operator=(const BigInteger& other)
{
    this->number = other.number;
    this->negative = other.negative;
}

bool BigInteger::operator<(const BigInteger& other) const
{
    if(this->negative ^ other.negative)
    {
        return this->negative;
    }
    else if(this->number.size() != this->number.size())
    {
        return this->number.size() < this->number.size();
    }
    else
    {
        auto thisIter = this->number.cbegin();
        for(auto i: other.number)
        {
            if(*thisIter != i)
            {
                return *thisIter < i;
            }
            thisIter++;            
        }
    }
    return false;
}

bool BigInteger::operator<=(const BigInteger& other) const
{
    return !(*this > other);
}

bool BigInteger::operator>(const BigInteger& other) const
{
    return other < *this;
}

bool BigInteger::operator>=(const BigInteger& other) const
{
    return !(*this < other);
}

bool BigInteger::operator==(const BigInteger& other) const
{
    return (*this <= other) && (*this>=other);
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
