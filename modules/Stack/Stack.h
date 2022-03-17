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






template<typename T>
Stack<T>::Stack()
{

}

template<typename T>
void Stack<T>::push(const T& data)
{
    StackElement<T>* newby = new StackElement<T>(data, head);
    head = newby;
}

template<typename T>
T& Stack<T>::pop()
{
    T ret(head->data);
    StackElement<T>* victim = head;
    head = head->next;
    delete victim;
}