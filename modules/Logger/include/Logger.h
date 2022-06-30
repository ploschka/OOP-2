#pragma once
#include <string>
#include <fstream>

class ILogger
{
public:
    virtual void info(const std::string& str) = 0;
    virtual void warning(const std::string& str) = 0;
    virtual void error(const std::string& str) = 0;
};

class ConsoleLogger: public ILogger
{
private:
    void log(const std::string& str);
public:
    void info(const std::string& str);
    void warning(const std::string& str);
    void error(const std::string& str);
};

class FileLogger: public ILogger
{
private:
    std::ofstream logfile;
    void log(const std::string& str);
public:
    FileLogger(const std::string& filename);
    ~FileLogger();
    void info(const std::string& str);
    void warning(const std::string& str);
    void error(const std::string& str);
};

class BaseLoggerDecorator: public ILogger
{
protected:
    ILogger* wrappedLogger;
private:
    void log(const std::string& str);
public:
    BaseLoggerDecorator(ILogger* logger);
    void info(const std::string& str);
    void warning(const std::string& str);
    void error(const std::string& str);
};

class ConsoleLoggerDecorator: public BaseLoggerDecorator
{
private:
    void log(const std::string& str);
public:
    ConsoleLoggerDecorator(ILogger* logger);
    void info(const std::string& str);
    void warning(const std::string& str);
    void error(const std::string& str);
};

class FileLoggerDecorator: public BaseLoggerDecorator
{
private:
    std::ofstream logfile;
    void log(const std::string& str);
public:
    FileLoggerDecorator(ILogger* logger, const std::string& filename);
    ~FileLoggerDecorator();
    void info(const std::string& str);
    void warning(const std::string& str);
    void error(const std::string& str);
};
