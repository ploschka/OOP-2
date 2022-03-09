#pragma once
template <typename T> class Stack;

template <typename T>
class StackElement
{
private:
    T data;
    StackElement<T>* next;
    StackElement(const T& data, const StackElement* const ptr);

    friend class Stack<T>;
};