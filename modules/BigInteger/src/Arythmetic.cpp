#include "BigInteger.h"
#include <algorithm>

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
    result.negative = makeNeg;
    result.shrink();
    return result;
}

BigInteger BigInteger::mul(const BigInteger& other) const
{
    BigInteger result;
    std::string upper;
    std::string lower;
    if (this->number.size() > other.number.size())
    {
        upper = this->number;
        lower = other.number;
    }
    else
    {
        upper = other.number;        
        lower = this->number;
    }

    result.number.reserve(upper.size() + lower.size());
    result.number.push_back('0');

    auto uppere = upper.crend();
    auto lowere = lower.crend();
    auto resulte = result.number.begin() - 1;

    size_t resultc = 0;

    for(auto loweri = lower.crbegin(); loweri != lowere; loweri++)
    {
        auto resulti = result.number.end() - 1 - resultc;
        uint8_t buff = 0;
        for(auto upperi = upper.crbegin(); upperi != uppere; upperi++)
        {
            buff += (*upperi - '0') * (*loweri - '0');
            *resulti += buff % 10;
            buff /= 10;
            result.number.insert(resulti, '0');
            //resulti--;
        }
        *resulti += buff;
        resultc++;
    }
    for(auto resulti = result.number.end() - 1; resulti != resulte; resulti--)
    {
        if(*resulti > '9')
        {
            if (resulti - 1 == resulte)
            {
                result.number.insert(resulti, '0');
                resulti++;
            }
            *(resulti - 1) = *resulti - ':';
            *resulti -= ':';
        }
    }
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