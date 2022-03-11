#pragma once

#include "KeyValueElement.h"

template<typename keyt, typename valuet>
class KeyValueContainer
{
private:
    KeyValueElement<keyt, valuet>* list;
public:
    KeyValueContainer();
    ~KeyValueContainer();

    KeyValueElement<keyt, valuet>& operator[](const keyt&);
};