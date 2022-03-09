#pragma once

#include "StackElement.h"

template<typename T>
class Stack
{
private:
    StackElement<T>* head;

public:
    Stack();
    void push(const T& data);
    T& pop();
};