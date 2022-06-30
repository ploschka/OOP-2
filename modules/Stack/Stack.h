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
    bool is_empty();
    void push(const T& data);
    T pop();

    template<typename TT>
    friend std::ostream& operator<<(std::ostream& out, const Stack<TT>& stack);
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
bool Stack<T>::is_empty()
{
    return (!head);
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
    T res(head->data);
    const StackElement<T>* victim = head;
    head = head->next;
    delete victim;
    return res;
}

template<typename TT>
std::ostream& operator<<(std::ostream& out, const Stack<TT>& stack)
{
    const StackElement<TT>* current = stack.head;
    while (current)
    {
        out << current->data << ' ';
        current = current->next;
    }
    return out;
}
