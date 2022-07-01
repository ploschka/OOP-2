#pragma once
#include "Logger.h"

class ILoggerFactory
{
public:
    virtual ILogger* createLogger(const std::string& prefix) = 0;
};

class ConsoleLoggerFactory: public ILoggerFactory
{
public:
    ILogger* createLogger(const std::string& prefix);
};

class FileLoggerFactory: public ILoggerFactory
{
public:
    ILogger* createLogger(const std::string& prefix);
};

class CombinedLoggerFactory: public ILoggerFactory
{
public:
    ILogger* createLogger(const std::string& prefix);
};
