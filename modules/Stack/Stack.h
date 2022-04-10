#pragma once

#include "StackElement.h"
#include <iostream>

template<typename T>
class Stack
{
private:
    const StackElement<T>* head = nullptr;

public:
    Stack() = default;
    ~Stack();
    void push(const T& data);
    T pop();

    template<typename TT>
    friend std::ostream& operator<<(std::ostream& os, const Stack<TT>& stack);
};






template<typename T>
Stack<T>::~Stack()
{
    const StackElement<T>* victim;
    while(head != nullptr)
    {
        victim = head;
        head = head->next;
        delete victim;
    }
}

template<typename T>
void Stack<T>::push(const T& data)
{
    StackElement<T>* newby = new StackElement<T>(data, head);
    head = newby;
}

template<typename T>
T Stack<T>::pop()
{
    T ret(head->data);
    const StackElement<T>* victim = head;
    head = head->next;
    delete victim;
    return ret;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& stack)
{
    const StackElement<T>* current = stack.head;
    while (current)
    {
        os << current->data << ' ';
        current = current->next;
    }
    return os;
}