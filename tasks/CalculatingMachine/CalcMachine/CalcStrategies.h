#pragma once
template<typename T>
class ICalcStrategy
{
public:
    virtual T execute(const T& a, const T& b) = 0;
};

template<typename T>
class AddStrategy: public ICalcStrategy<T>
{
public:
    T execute(const T& a, const T& b)
    {
        return a + b;
    }
};

template<typename T>
class SubStrategy: public ICalcStrategy<T>
{
public:
    T execute(const T& a, const T& b)
    {
        return a - b;
    }
};

template<typename T>
class MulStrategy: public ICalcStrategy<T>
{
public:
    T execute(const T& a, const T& b)
    {
        return a * b;
    }
};
