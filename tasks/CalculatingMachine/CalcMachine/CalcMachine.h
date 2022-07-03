#pragma once
#include <string>
#include "KVC.h"
#include "CalcCommands.h"
#include "CalcCommandFactory.h"

template<typename T>
class CalcMachine
{
private:
    KVC<std::string, ICalcCommand<T>*> strats;
    T buffer;
public:
    CalcMachine(T number): buffer(number) {}
    void addCommand(std::string command, ICalcCommand<T>* Command)
    {
        strats[command] = Command;
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