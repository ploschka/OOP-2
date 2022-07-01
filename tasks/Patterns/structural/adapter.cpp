#include <iostream>

class ILeftHandMug
{
public:
    virtual void grabLeftMug() = 0;
};

class IRightHandMug
{
public:
    virtual void grabRightMug() = 0;
};

class LeftHandMug: public ILeftHandMug
{
public:
    void grabLeftMug()
    {
        std::cout << "You grabbed a left-handed mug" << std::endl;
    }
};

class RightHandMug: public IRightHandMug
{
public:
    void grabRightMug()
    {
        std::cout << "You grabbed a right-handed mug" << std::endl;
    }
};

class LeftToRightHandMugAdapter: public IRightHandMug
{
private:
    ILeftHandMug* left;
    void rotate()
    {
        std::cout << "You rotated the mug" << std::endl;
    }
public:
    LeftToRightHandMugAdapter(ILeftHandMug* left): left(left){}

    void grabRightMug()
    {
        rotate();
        left->grabLeftMug();
    }
};

void grabByRightHand(IRightHandMug* mug)
{
    mug->grabRightMug();
}

int main()
{
    ILeftHandMug* leftmug = new LeftHandMug();
    auto* adap = new LeftToRightHandMugAdapter(leftmug);
    grabByRightHand(adap);
}