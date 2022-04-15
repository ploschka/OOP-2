#pragma once
template <typename T> class Stack;

template <typename T>
class StackElement
{
private:
    T data;
    const StackElement<T>* next;
    StackElement() = default;
    StackElement(const T& data, const StackElement* const ptr);
    ~StackElement() = default;

    friend class Stack<T>;

    template<typename TT>
    friend std::ostream& operator<<(std::ostream& out, const Stack<TT>& stack);
};






template<typename TT>
StackElement<TT>::StackElement(const TT& data, const StackElement* ptr): data(data), next(ptr){}
