#include <iostream>

class Prototype
{
public:
    virtual Prototype* clone() = 0;
};

class Sheep: public Prototype
{
private:
    std::string name;
public:
    void sayName()
    {
        std::cout << "My name is " << name << std::endl;
    }

    Sheep(std::string name):name(name){}
    Sheep(Sheep& sheep): name(sheep.name){}

    Sheep* clone()
    {
        return new Sheep(*this);
    }
};

int main()
{
    Sheep* sheep1 = new Sheep("Dolly");

    Sheep* sheep2 = sheep1->clone();

    sheep1->sayName();
    sheep2->sayName();
}
