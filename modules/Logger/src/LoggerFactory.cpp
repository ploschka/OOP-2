#include "Logger.h"
#define DEFAULT_LOG_NAME "Logs.txt"
#include "LoggerFactory.h"

ILogger* ConsoleLoggerFactory::createLogger(const std::string& prefix)
{
    return (new ConsoleLogger(prefix));
}

ILogger* FileLoggerFactory::createLogger(const std::string& prefix)
{
    return (new FileLogger(prefix, DEFAULT_LOG_NAME));
}

ILogger* CombinedLoggerFactory::createLogger(const std::string& prefix)
{
    return new FileLoggerDecorator(prefix, new ConsoleLogger(prefix), DEFAULT_LOG_NAME);
}
