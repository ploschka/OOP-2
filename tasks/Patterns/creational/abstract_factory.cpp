#include <iostream>
#include <tuple>

class Mouse
{
public:
    virtual void click() = 0;
};
class Keyboard
{
public:
    virtual void type() = 0;
};
class Headphones
{
public:
    virtual void sound() = 0;
};

class LogitechMouse: public Mouse
{
public:
    virtual void click()
    {
        std::cout << "The click by Logitech" << std::endl;
    }
};
class LogitechKeyboard: public Keyboard
{
public:
    virtual void type()
    {
        std::cout << "The type by Logitech" << std::endl;
    }
};
class LogitechHeadphones: public Headphones
{
public:
    virtual void sound()
    {
        std::cout << "The sound by Logitech" << std::endl;
    }
};

class BloodyMouse: public Mouse
{
public:
    virtual void click()
    {
        std::cout << "The click by Bloody" << std::endl;
    }
};
class BloodyKeyboard: public Keyboard
{
public:
    virtual void type()
    {
        std::cout << "The type by Bloody" << std::endl;
    }
};
class BloodyHeadphones: public Headphones
{
public:
    virtual void sound()
    {
        std::cout << "The sound by Bloody" << std::endl;
    }
};

class GamingFactory
{
public:
    virtual Mouse* createMouse() = 0;
    virtual Keyboard* createKeyboard() = 0;
    virtual Headphones* createHeadphones() = 0;
};

class LogitechFactory: public GamingFactory
{
public:
    virtual Mouse* createMouse()
    {
        return new LogitechMouse;
    }
    virtual Keyboard* createKeyboard()
    {
        return new LogitechKeyboard;
    }
    virtual Headphones* createHeadphones()
    {
        return new LogitechHeadphones;
    }
};

class BloodyFactory: public GamingFactory
{
public:
    virtual Mouse* createMouse()
    {
        return new BloodyMouse;
    }
    virtual Keyboard* createKeyboard()
    {
        return new BloodyKeyboard;
    }
    virtual Headphones* createHeadphones()
    {
        return new BloodyHeadphones;
    }
};

int main()
{
    GamingFactory* bloody = new BloodyFactory();
    GamingFactory* logitech = new LogitechFactory();

    std::tuple<Mouse*, Keyboard*, Headphones*> bloody_things;
    std::tuple<Mouse*, Keyboard*, Headphones*> logitech_things;

    bloody_things = std::make_tuple(bloody->createMouse(), bloody->createKeyboard(), bloody->createHeadphones());
    logitech_things = std::make_tuple(logitech->createMouse(), logitech->createKeyboard(), logitech->createHeadphones());

    std::get<0>(bloody_things)->click();
    std::get<1>(bloody_things)->type();
    std::get<2>(bloody_things)->sound();

    std::get<0>(logitech_things)->click();
    std::get<1>(logitech_things)->type();
    std::get<2>(logitech_things)->sound();
}