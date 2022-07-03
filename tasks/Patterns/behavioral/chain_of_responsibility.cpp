#include <iostream>

class IHandler
{
public:
    virtual IHandler* setNext(IHandler* next) = 0;
    virtual void handle() = 0;
};

class BaseHandler: public IHandler
{
private:
    IHandler* next = nullptr;
public:
    IHandler* setNext(IHandler* next)
    {
        this->next = next;
        return next;
    }
    void handle()
    {
        if(next != nullptr)
        {
            next->handle();
        }
    }
};

class Пресс_качат: public BaseHandler
{
public:
    void handle()
    {
        std::cout << "Пресс качат" << std::endl;
        BaseHandler::handle();
    }
};

class Бегит: public BaseHandler
{
public:
    void handle()
    {
        std::cout << "Бегит" << std::endl;
        BaseHandler::handle();
    }
};

class Турник: public BaseHandler
{
public:
    void handle()
    {
        std::cout << "Турник" << std::endl;
        BaseHandler::handle();
    }
};

class Анжуманя: public BaseHandler
{
public:
    void handle()
    {
        std::cout << "Анжуманя" << std::endl;
        BaseHandler::handle();
    }
};

int main()
{
    auto* p = new Пресс_качат;
    auto* b = new Бегит;
    auto* t = new Турник;
    auto* a = new Анжуманя;
    p->setNext(b)->setNext(t)->setNext(a);
    p->handle();
}