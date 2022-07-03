#pragma once
#include "CalcCommands.h"

template<typename T>
class CalcCommandFactory
{
public:
    ICalcCommand<T>* createAddCommand()
    {
        return (new AddCommand<T>());
    }
    ICalcCommand<T>* createSubCommand()
    {
        return (new SubCommand<T>());
    }
    ICalcCommand<T>* createMulCommand()
    {
        return (new MulCommand<T>());
    }
};