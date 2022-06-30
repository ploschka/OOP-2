#include "Logger.h"
#define DEFAULT_LOG_NAME "Logs.txt"
#include "LoggerFactory.h"

ILogger* ConsoleLoggerFactory::createLogger()
{
    return (new ConsoleLogger());
}

ILogger* FileLoggerFactory::createLogger()
{
    return (new FileLogger(DEFAULT_LOG_NAME));
}

ILogger* CombinedLoggerFactory::createLogger()
{
    return new FileLoggerDecorator(new ConsoleLogger(), DEFAULT_LOG_NAME);
}
