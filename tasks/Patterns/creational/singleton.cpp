#include <iostream>

class Baskov
{
private:
    Baskov()
    {
        std::cout << "Фантазёр..." << std::endl;
    }
    static Baskov* nikolai;
public:
    static Baskov* getNikolai()
    {
        if (!nikolai)
        {
            nikolai = new Baskov;
        }
        return nikolai;
    }

    void sing()
    {
        std::cout << "Натуральный блондин" << std::endl;
    }
};

Baskov* Baskov::nikolai= nullptr;


int main()
{
    auto baskov1 = Baskov::getNikolai();
    auto baskov2 = Baskov::getNikolai();
    baskov1->sing();
    if (baskov1 == baskov2)
    {
        std::cout << "На всю страну такой один" << std::endl;
    }
}