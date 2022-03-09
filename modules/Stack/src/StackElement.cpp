#include "StackElement.h"

template<typename T>
StackElement<T>::StackElement(const T& data, const StackElement* const ptr): data(data), next(ptr)
{

}