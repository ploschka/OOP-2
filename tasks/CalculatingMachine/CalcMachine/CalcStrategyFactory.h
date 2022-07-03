#pragma once
#include "CalcStrategies.h"

template<typename T>
class CalcStrategyFactory
{
public:
    ICalcStrategy<T>* createAddStrategy()
    {
        return (new AddStrategy<T>());
    }
    ICalcStrategy<T>* createSubStrategy()
    {
        return (new SubStrategy<T>());
    }
    ICalcStrategy<T>* createMulStrategy()
    {
        return (new MulStrategy<T>());
    }
};