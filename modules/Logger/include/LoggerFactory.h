#pragma once
#include "Logger.h"

class ILoggerFactory
{
public:
    virtual ILogger* createLogger() = 0;
};

class ConsoleLoggerFactory: public ILoggerFactory
{
public:
    ILogger* createLogger();
};

class FileLoggerFactory: public ILoggerFactory
{
public:
    ILogger* createLogger();
};

class CombinedLoggerDecoratorFactory: public ILoggerFactory
{
public:
    ILogger* createLogger();
};
