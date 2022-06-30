#include <string>
#include <iostream>
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
    void log(const std::string& str)
    {
        std::cout << str << std::endl;
    }
public:
    void info(const std::string& str)
    {
        log("[INFO] "+str);
    }
    void warning(const std::string& str)
    {
        log("[WARNING] "+str);
    }
    void error(const std::string& str)
    {
        log("[ERROR] "+str);
    }
};

class FileLogger: public ILogger
{
private:
    std::ofstream logfile;
    void log(const std::string& str)
    {
        logfile << str << std::endl;
    }
public:
    FileLogger(const std::string& filename): logfile(filename, std::ios_base::app)
    {

    }
    ~FileLogger()
    {
        logfile.close();
    }
    void info(const std::string& str)
    {
        log("[INFO] "+str);
    }
    void warning(const std::string& str)
    {
        log("[WARNING] "+str);
    }
    void error(const std::string& str)
    {
        log("[ERROR] "+str);
    }
};

class BaseLoggerDecorator: public ILogger
{
protected:
    ILogger* wrappedLogger;
private:
    void log(const std::string& str);
public:
    BaseLoggerDecorator(ILogger* logger): wrappedLogger(logger)
    {

    }
    void info(const std::string& str)
    {
        wrappedLogger->info(str);
    }
    void warning(const std::string& str)
    {
        wrappedLogger->warning(str);
    }
    void error(const std::string& str)
    {
        wrappedLogger->error(str);
    }
};

class ConsoleLoggerDecorator: public BaseLoggerDecorator
{
private:
    void log(const std::string& str)
    {
        std::cout << str << std::endl;
    }
public:
    ConsoleLoggerDecorator(ILogger* logger):BaseLoggerDecorator(logger)
    {

    }
    void info(const std::string& str)
    {
        wrappedLogger->info(str);
        this->log("[INFO] "+str);
    }
    void warning(const std::string& str)
    {
        wrappedLogger->warning(str);
        this->log("[WARNING] "+str);
    }
    void error(const std::string& str)
    {
        wrappedLogger->error(str);
        this->log("[ERROR] "+str);
    }
};

class FileLoggerDecorator: public BaseLoggerDecorator
{
private:
    std::ofstream logfile;
    void log(const std::string& str)
    {
        logfile << str << std::endl;
    }
public:
    FileLoggerDecorator(ILogger* logger, const std::string& filename): BaseLoggerDecorator(logger), logfile(filename, std::ios_base::app)
    {

    }
    ~FileLoggerDecorator()
    {
        logfile.close();
    }
    void info(const std::string& str)
    {
        wrappedLogger->info(str);
        this->log("[INFO] "+str);
    }
    void warning(const std::string& str)
    {
        wrappedLogger->warning(str);
        this->log("[WARNING] "+str);
    }
    void error(const std::string& str)
    {
        wrappedLogger->error(str);
        this->log("[ERROR] "+str);
    }
};
