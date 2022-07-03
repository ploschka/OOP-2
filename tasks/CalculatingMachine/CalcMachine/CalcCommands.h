#pragma once
template<typename T>
class ICalcCommand
{
public:
    virtual T execute(const T& a, const T& b) = 0;
};

template<typename T>
class AddCommand: public ICalcCommand<T>
{
public:
    T execute(const T& a, const T& b)
    {
        return a + b;
    }
};

template<typename T>
class SubCommand: public ICalcCommand<T>
{
public:
    T execute(const T& a, const T& b)
    {
        return a - b;
    }
};

template<typename T>
class MulCommand: public ICalcCommand<T>
{
public:
    T execute(const T& a, const T& b)
    {
        return a * b;
    }
};
