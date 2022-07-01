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
    std::string prefix;
    void log(const std::string& str1, const std::string& str2);
public:
    ConsoleLogger(const std::string& prefix);
    void info(const std::string& str);
    void warning(const std::string& str);
    void error(const std::string& str);
};

class FileLogger: public ILogger
{
private:
    std::string prefix;
    std::ofstream logfile;
    void log(const std::string& str1, const std::string& str2);
public:
    FileLogger(const std::string& prefix, const std::string& filename);
    ~FileLogger();
    void info(const std::string& str);
    void warning(const std::string& str);
    void error(const std::string& str);
};

class BaseLoggerDecorator: public ILogger
{
protected:
    ILogger* wrappedLogger;
    std::string prefix;
private:
    void log(const std::string& str1, const std::string& str2);
public:
    BaseLoggerDecorator(const std::string& prefix, ILogger* logger);
    void info(const std::string& str);
    void warning(const std::string& str);
    void error(const std::string& str);
};

class ConsoleLoggerDecorator: public BaseLoggerDecorator
{
private:
    void log(const std::string& str1, const std::string& str2);
public:
    ConsoleLoggerDecorator(const std::string& prefix, ILogger* logger);
    void info(const std::string& str);
    void warning(const std::string& str);
    void error(const std::string& str);
};

class FileLoggerDecorator: public BaseLoggerDecorator
{
private:
    std::ofstream logfile;
    void log(const std::string& str1, const std::string& str2);
public:
    FileLoggerDecorator(const std::string& prefix, ILogger* logger, const std::string& filename);
    ~FileLoggerDecorator();
    void info(const std::string& str);
    void warning(const std::string& str);
    void error(const std::string& str);
};
