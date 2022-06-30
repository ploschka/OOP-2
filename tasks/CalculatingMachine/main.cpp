#include <iostream>
#include <utility>
#include "CalcMachine.h"
#include "BigInteger.h"
#include "CSVParser.h"
#include "LoggerFactory.h"
#include "Stack.h"

int main()
{
    uint64_t startingNumber;
    std::cout << "Enter the starting number: ";
    std::cin >> startingNumber;

    CalcStrategyFactory<BigInteger> stratfactory;
    CalcMachine<BigInteger> machine(startingNumber);
    CSVParser parser;

    FileLoggerFactory logfac;
    ILogger* logger = logfac.createLogger();

    Stack<std::pair<std::string, BigInteger>> stack;

    machine.addCommand("ADD", stratfactory.createAddStrategy());
    machine.addCommand("SUB", stratfactory.createSubStrategy());
    machine.addCommand("MUL", stratfactory.createMulStrategy());
    logger->info("Successfully added strategies into calulating machine");

    parsed_strings entry;
    try
    {
        entry = parser.parse("machine_entry.csv");
    }
    catch(std::exception error)
    {
        logger->error(error.what());
        exit(1);
    }
    logger->info("Successfully parsed entry file");

    try
    {
        for(auto i: entry)
        {
            stack.push(std::make_pair(i[0], BigInteger(i[1])));
        }
    }
    catch(std::exception error)
    {
        logger->error(error.what());
        exit(1);
    }
    logger->info("Successfully filled stack");
    
    while(!stack.is_empty())
    {
        auto operation =  stack.pop();
        machine.doOperation(operation.first, operation.second);
    }
    
    std::cout << "Result: " << machine.getBuffer() << std::endl;
}

#undef mylog