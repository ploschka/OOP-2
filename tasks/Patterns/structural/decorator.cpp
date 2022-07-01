#include <iostream>

class IKettle
{
public:
    virtual void execute() = 0;
};

class Kettle: public IKettle
{
public:
    void execute()
    {
        std::cout << "Заварил чай" << std::endl;
    }
};

class KettleBaseDecorator: public IKettle
{
protected:
    IKettle* wrapee;
public:
    KettleBaseDecorator(IKettle* kettle):wrapee(kettle){}
    virtual void execute()
    {
        wrapee->execute();
    }
};

class KettleCoffeeDecorator: public KettleBaseDecorator
{
public:
    KettleCoffeeDecorator(IKettle* kettle): KettleBaseDecorator(kettle){}
    virtual void execute()
    {
        wrapee->execute();
        std::cout << "А ещё заварил кофейка" << std::endl;
    }
};

void MakeSomeDrinks(IKettle* ket)
{
    ket->execute();
}

int main()
{
    IKettle* ket = new Kettle;
    MakeSomeDrinks(ket);

    IKettle* cofket = new KettleCoffeeDecorator(ket);
    MakeSomeDrinks(cofket);
}