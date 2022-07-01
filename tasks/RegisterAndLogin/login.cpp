#include "Logger.h"
#include "LoggerFactory.h"
#include "UserDatabase.h"
#include "StrelovParser.h"
#include "StrelovParserAdapter.h"
#include "KVC.h"
#include <functional>
#include <iostream>

int main()
{
    auto* sparser = new Parser;
    IParser*  parser = new StrelovParserAdapter(sparser);
    Database db(parser, "users.csv");
    auto fac = new FileLoggerFactory();
    ILogger* logger = fac->createLogger("[LOGIN]");
    KVC<std::string, size_t> map;

    parsed_strings database;

    try
    {
        database = db.read();
    }
    catch(std::runtime_error error)
    {
        logger->error("File read error");
        logger->error(error.what());
        delete logger;
        delete fac;
        delete parser;
        delete sparser;
        exit(1);
    }

    for(auto& i: database)
    {
        map[i[0]] = std::stoul(i[1]);
    }

    std::string login;

    std::cout << "Enter your login: ";
    std::cin >> login;
    if(db.contains(login))
    {
        std::string rawPassword;
        std::cout << "Enter your password: ";
        std::cin >> rawPassword;
        if(std::hash<std::string>{}(rawPassword) == map[login])
        {
            std::cout << "Successfully logged in" << std::endl;
            logger->info("User " + login + " successfully logged in");
        }
    }
    else
    {
        logger->info("No user with login " + login);
    }
    delete logger;
    delete fac;
    delete parser;
    delete sparser;
}