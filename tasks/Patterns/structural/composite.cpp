#include <iostream>
#include <vector>

class Component
{
public:
    virtual void execute() = 0;
};

class Box: public Component
{
private:
    std::vector<Component*> components;
public:
    void add(Component* comp)
    {
        components.push_back(comp);
    }
    void execute()
    {
        std::cout << "I am box, i have " << components.size() << " things inside: {";
        for(Component* i: components)
        {
            i->execute();
        }
        std::cout << '}';
    }
};

class Hammer: public Component
{
public:
    void execute()
    {
        std::cout << "I am Hammer ";
    }
};

class Screwdriver: public Component
{
public:
    void execute()
    {
        std::cout << "I am Screwdriver ";
    }
};

class Saw: public Component
{
public:
    void execute()
    {
        std::cout << "I am Saw ";
    }
};

int main()
{
    Box* box = new Box;
    box->add(new Screwdriver);
    box->add(new Saw);
    Box* box2 = new Box;
    box->add(box2);
    box2->add(new Hammer);
    box2->add(new Saw);

    box->execute();
    std::cout << std::endl;
}