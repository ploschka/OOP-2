#pragma once

#include "KVE.h"

template<typename keyt, typename valuet>
class KVC
{
private:
    KVE<keyt, valuet>* list;
public:
    KVC();
    ~KVC();

    KVE<keyt, valuet>& operator[](const keyt&);
};