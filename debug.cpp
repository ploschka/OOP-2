#include <iostream>
#include "KVC.h"
#include "Stack.h"
#include "BigInteger.h"
#include "CSVParser.h"
#include <fstream>
#include "LoggerFactory.h"

int main()
{
    std::ofstream file("ggg.txt");
    KVC<char, int> mapa;
    mapa['a'] = 5;
    std::cout << mapa['a'] << std::endl;
    mapa['a'] = 6;
    mapa['b'] = 7;
    std::cout << mapa['b'] << std::endl;
    std::cout << mapa['a'] << std::endl;

    KVC<char, int> mapa2(mapa);

    std::cout << "===================" << std::endl;

    std::cout << mapa2['a'] << std::endl << mapa2['b'] << std::endl;
    std::cout << "===================================\n" << "===================================\n";

    Stack<int> staka;
    staka.push(5);
    staka.push(3);
    staka.push(2);
    std::cout << staka << std::endl;
    std::cout << staka.pop() << std::endl;
    std::cout << staka << std::endl;
    std::cout << "===================================\n" << "===================================\n";

    BigInteger biga("5");
    BigInteger bigb("5");
    BigInteger bigc("10");
    file << ((biga * bigc) + bigb) << "\n\n";
    CSVParser parser;
    std::string hhhhhhhhhhhhhhhhhhhh = "fff.txt";
    parsed_strings gg = parser.parse(hhhhhhhhhhhhhhhhhhhh);
    for(auto i: gg)
    {
        for(auto j: i)
        {
            file << j << "; ";
        }
        file << "\n";
    }
    file.close();

    ILoggerFactory* fac1 = new FileLoggerFactory();
    ILoggerFactory* fac2 = new ConsoleLoggerFactory();
    ILoggerFactory* fac3 = new CombinedLoggerFactory();

    ILogger* logger;

    logger = fac1->createLogger("[DEBUG1]");
    logger->error("Я пёрнул");
    logger->warning("Я пёрнул");
    logger->info("Я пёрнул");

    logger = fac2->createLogger("[DEBUG2]");
    logger->error("Я пёрнул");
    logger->warning("Я пёрнул");
    logger->info("Я пёрнул");

    logger = fac3->createLogger("[DEBUG3]");
    logger->error("Я пёрнул");
    logger->warning("Я пёрнул");
    logger->info("Я пёрнул");

    parsed_strings bb = parser.parse("hhh.csv");
    std::cout << std::endl;
}
