#pragma once
#include <string>
#include "KVC.h"
#include "CalcStrategies.h"
#include "CalcStrategyFactory.h"

template<typename T>
class CalcMachine
{
private:
    KVC<std::string, ICalcStrategy<T>*> strats;
    T buffer;
public:
    CalcMachine(T number): buffer(number) {}
    void addStrategy(std::string command, ICalcStrategy<T>* strategy)
    {
        strats[command] = strategy;
    }
    void doOperation(std::string operation, T number)
    {
        buffer = strats[operation]->execute(buffer, number);
    }
    T getBuffer()
    {
        return buffer;
    }
};