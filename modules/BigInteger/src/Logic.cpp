#include "BigInteger.h"

bool BigInteger::operator<(const BigInteger& other) const
{
    if(this->negative ^ other.negative)
    {
        return this->negative;
    }
    else if(this->number.size() != other.number.size())
    {
        return this->number.size() < other.number.size();
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
