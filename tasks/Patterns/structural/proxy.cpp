#include <iostream>

class IDataBase
{
public:
    virtual std::string read() = 0;
    virtual void write(std::string str) = 0;
};

class ActualDataBase: public IDataBase
{
public:
    std::string read()
    {
        return "Data from database";
    }
    void write(std::string str)
    {
        std::cout << "Written \"" << str << "\" to database" << std::endl;
    }
};

class DataBaseProxy: public IDataBase
{
private:
    void connect()
    {
        if(!connected)
        {
            database = new ActualDataBase;
            connected = true;
            std::cout << "Connected to database" << std::endl;
        }
    }
    bool connected = false;
    IDataBase* database;
    std::string cache;
public:
    std::string read()
    {
        if(!connected)
        {
            connect();
        }
        if(cache.empty())
        {
            std::cout << "Pulled data from database" << std::endl;
            cache = database->read();
        }
        return cache;
    }
    void write(std::string str)
    {
        if(!connected)
        {
            connect();
        }
        database->write(str);
    }    
};

int main()
{
    IDataBase* database = new DataBaseProxy;
    std::cout << database->read() << std::endl;
    database->write("Hello, World!");
    std::cout << database->read() << std::endl;
}