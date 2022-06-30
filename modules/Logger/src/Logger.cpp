#include <string>
#include <iostream>
#include <fstream>
#include "Logger.h"

void ConsoleLogger::log(const std::string& str)
{
    std::cout << str << std::endl;
}
void ConsoleLogger::info(const std::string& str)
{
    log("[INFO] "+str);
}
void ConsoleLogger::warning(const std::string& str)
{
    log("[WARNING] "+str);
}
void ConsoleLogger::error(const std::string& str)
{
    log("[ERROR] "+str);
}

void FileLogger::log(const std::string& str)
{
    logfile << str << std::endl;
}
FileLogger::FileLogger(const std::string& filename): logfile(filename, std::ios_base::app)
{

}
FileLogger::~FileLogger()
{
    logfile.close();
}
void FileLogger::info(const std::string& str)
{
    log("[INFO] "+str);
}
void FileLogger::warning(const std::string& str)
{
    log("[WARNING] "+str);
}
void FileLogger::error(const std::string& str)
{
    log("[ERROR] "+str);
}

void BaseLoggerDecorator::log(const std::string& str)
{

}
BaseLoggerDecorator::BaseLoggerDecorator(ILogger* logger): wrappedLogger(logger)
{

}
void BaseLoggerDecorator::info(const std::string& str)
{
    wrappedLogger->info(str);
}
void BaseLoggerDecorator::warning(const std::string& str)
{
    wrappedLogger->warning(str);
}
void BaseLoggerDecorator::error(const std::string& str)
{
    wrappedLogger->error(str);
}

void ConsoleLoggerDecorator::log(const std::string& str)
{
    std::cout << str << std::endl;
}
ConsoleLoggerDecorator::ConsoleLoggerDecorator(ILogger* logger):BaseLoggerDecorator(logger)
{

}
void ConsoleLoggerDecorator::info(const std::string& str)
{
    wrappedLogger->info(str);
    this->log("[INFO] "+str);
}
void ConsoleLoggerDecorator::warning(const std::string& str)
{
    wrappedLogger->warning(str);
    this->log("[WARNING] "+str);
}
void ConsoleLoggerDecorator::error(const std::string& str)
{
    wrappedLogger->error(str);
    this->log("[ERROR] "+str);
}

void FileLoggerDecorator::log(const std::string& str)
{
    logfile << str << std::endl;
}
FileLoggerDecorator::FileLoggerDecorator(ILogger* logger, const std::string& filename): BaseLoggerDecorator(logger), logfile(filename, std::ios_base::app)
{

}
FileLoggerDecorator::~FileLoggerDecorator()
{
    logfile.close();
}
void FileLoggerDecorator::info(const std::string& str)
{
    wrappedLogger->info(str);
    this->log("[INFO] "+str);
}
void FileLoggerDecorator::warning(const std::string& str)
{
    wrappedLogger->warning(str);
    this->log("[WARNING] "+str);
}
void FileLoggerDecorator::error(const std::string& str)
{
    wrappedLogger->error(str);
    this->log("[ERROR] "+str);
}
