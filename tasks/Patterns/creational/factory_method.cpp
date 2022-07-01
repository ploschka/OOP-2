#include <iostream>

class Animal
{
public:
    virtual void say() = 0;
};

class Crab: public Animal
{
public:
    void say()
    {
        std::cout << "Click click" << std::endl;
    }
};

class Fish: public Animal
{
public:
    void say()
    {
        std::cout << "Blob blob" << std::endl;
    }
};

class Factory
{
public:
    virtual Animal* createAnimal() = 0;
};

class CrabFactory: public Factory
{
public:
    Animal* createAnimal()
    {
        return new Crab;
    }
};

class FishFactory: public Factory
{
public:
    Animal* createAnimal()
    {
        return new Fish;
    }
};

int main()
{
    Animal* some_animal;
    Factory* ff = new FishFactory;
    Factory* cf = new CrabFactory;

    some_animal = ff->createAnimal();
    some_animal->say();
    delete some_animal;

    some_animal = cf->createAnimal();
    some_animal->say();
    delete some_animal;
}