#include <iostream>

class Cyborg
{
public:
    std::string configuration;
    void sayConfig()
    {
        std::cout << "I have:\n" << configuration << std::endl;
    }
};

class CyborgBuilder
{
private:
    Cyborg* cyborg;
public:
    CyborgBuilder(Cyborg* cyborg): cyborg(cyborg){}

    void addLaserEyes()
    {
        cyborg->configuration += "Laser Eyes\n";
    }
    void addNanoMachines()
    {
        cyborg->configuration += "Nanomachines, son\n";        
    }
    void addAdvancedAI()
    {
        cyborg->configuration += "Advanced AI\n";
    }
    void addCoolHat()
    {
        cyborg->configuration += "Cool hat\n";
    }
};

int main()
{
    Cyborg* c1 = new Cyborg;
    Cyborg* c2 = new Cyborg;
    CyborgBuilder* b1 = new CyborgBuilder(c1);
    CyborgBuilder* b2 = new CyborgBuilder(c2);

    b1->addLaserEyes();
    b1->addNanoMachines();
    b1->addCoolHat();

    b2->addAdvancedAI();
    b2->addLaserEyes();

    c1->sayConfig();
    c2->sayConfig();
}