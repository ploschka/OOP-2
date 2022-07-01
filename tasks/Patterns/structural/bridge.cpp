#include <iostream>

class IRabotyaga
{
public:
    virtual void doJob() = 0;
};

class Svarchik: public IRabotyaga
{
public:
    virtual void doJob()
    {
        std::cout << "Сварил суп" << std::endl;
    }
};

class Prorab
{
private:
    IRabotyaga* rab;
    void drinkTea()
    {
        std::cout << "You drinked tea" << std::endl;
    }
    void motivateTheRabotyaga()
    {
        std::cout << "А ну, иди работать!!!" << std::endl;
        rab->doJob();
    }
public:
    void newRabotyaga(IRabotyaga* rab)
    {
        this->rab = rab;
    }
    void doSomeThings()
    {
        drinkTea();
        motivateTheRabotyaga();
    };
};

int main()
{
    auto p = new Prorab;
    IRabotyaga* r = new Svarchik;
    p->newRabotyaga(r);
    p->doSomeThings();
}