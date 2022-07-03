#include <iostream>
#include <utility>
#include "CalcMachine.h"
#include "BigInteger.h"
#include "Parser.h"
#include "LoggerFactory.h"
#include "Stack.h"

int main()
{
    FileLoggerFactory logfac;
    ILogger* logger = logfac.createLogger("[CALC MACHINE]");

    uint64_t startingNumber;
    std::cout << "Enter the starting number: ";
    std::cin >> startingNumber;

    if (std::cin.fail())
    {
        logger->error("Invalid starting number");
        exit(1);        
    }
    logger->info("Successfully acquired starting number");

    CalcStrategyFactory<BigInteger> stratFactory;
    CalcMachine<BigInteger> machine(startingNumber);
    CSVParser parser;

    Stack<std::pair<std::string, BigInteger>> stack;

    machine.addStrategy("ADD", stratFactory.createAddStrategy());
    machine.addStrategy("SUB", stratFactory.createSubStrategy());
    machine.addStrategy("MUL", stratFactory.createMulStrategy());

    parsed_strings entry;
    try
    {
        entry = parser.parse("machine_entry.csv");
    }
    catch(std::runtime_error error)
    {
        logger->error("File parsing error");
        logger->error(error.what());
        exit(2);
    }
    logger->info("Successfully parsed entry file");

    try
    {
        for(auto i: entry)
        {
            stack.push(std::make_pair(i[0], BigInteger(i[1])));
        }
    }
    catch(std::logic_error error)
    {
        logger->error("Stack filling error");
        logger->error(error.what());
        exit(3);
    }
    logger->info("Successfully filled stack");
    
    while(!stack.is_empty())
    {
        auto operation =  stack.pop();
        machine.doOperation(operation.first, operation.second);
    }
    
    std::cout << "Result: " << machine.getBuffer() << std::endl;
    logger->info("Program finished successfully");
}

#undef mylog