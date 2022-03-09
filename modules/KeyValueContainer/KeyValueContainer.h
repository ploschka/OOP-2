#pragma once

template<typename keyt, typename valuet>
class KeyValueContainer
{
private:
    void** keys;
    void** values;
public:
    KeyValueContainer();
    ~KeyValueContainer();

    T& operator[](const T&);
};