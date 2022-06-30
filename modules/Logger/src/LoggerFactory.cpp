#include "Logger.h"
#define DEFAULT_LOG_NAME "Logs.txt"

class ILoggerFactory
{
public:
    virtual ILogger* createLogger() = 0;
};

class ConsoleLoggerFactory: public ILoggerFactory
{
public:
    ILogger* createLogger()
    {
        return (new ConsoleLogger());
    }
};

class FileLoggerFactory: public ILoggerFactory
{
public:
    ILogger* createLogger()
    {
        return (new FileLogger(DEFAULT_LOG_NAME));
    }
};

class CombinedLoggerDecoratorFactory: public ILoggerFactory
{
public:
    ILogger* createLogger()
    {
        return new FileLoggerDecorator(new ConsoleLogger(), DEFAULT_LOG_NAME);
    }
};
