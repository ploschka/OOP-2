#include "Logger.h"
#include "LoggerFactory.h"
#include "UserDatabase.h"
#include "StrelovParser.h"
#include "StrelovParserAdapter.h"
#include <functional>
#include <iostream>

int main()
{
    auto* sparser = new Parser;
    IParser*  parser = new StrelovParserAdapter(sparser);
    Database db(parser, "users.csv");
    auto fac = new FileLoggerFactory();
    ILogger* logger = fac->createLogger("[REGISTER]");

    std::string login;
    std::cout << "Enter your login: ";
    std::cin >> login;
    bool correct = false;
    while(!correct)
    {
        try
        {
            if(!db.contains(login))
            {
                std::string password1;
                std::string password2;
                while(!correct)
                {
                    std::cout << "Enter your password: ";
                    std::cin >> password1;

                    std::cout << "Repeat your password: ";
                    std::cin >> password2;

                    if(password1 == password2)
                    {
                        correct = true;
                    }
                    else
                    {
                        std::cout << "Passwords don\'t match" << std::endl;
                    }
                }
                parsed_string newUser;
                newUser.push_back(login);
                newUser.push_back(std::to_string(std::hash<std::string>{}(password1)));
                db.write(newUser);
                logger->info("Account " + login + " created");
                std::cout << "Account created successfully" << std::endl;
            }
            else
            {
                std::cout << "This user already exists" << std::endl;
                logger->error("User " + login + " already exists");
            }
        }
        catch(std::runtime_error error)
        {
            logger->error("File read error");
            logger->error(error.what());
        }
    }
    delete logger;
    delete fac;
    delete parser;
    delete sparser;
}