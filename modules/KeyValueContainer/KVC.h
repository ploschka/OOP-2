#pragma once

#include "KVE.h"
#include <malloc.h>

template<typename keyt, typename valuet>
class KVC
{
private:
    void** list;
    unsigned short int size;
public:
    KVC();
    ~KVC();

    KVE<keyt, valuet>& operator[](const keyt&);
};






template<typename keyt, typename valuet>
KVC<keyt, valuet>::KVC()
{
    size = 16;
    list = reinterpret_cast<void**>(malloc(size << 3));
}

template<typename keyt, typename valuet>
KVC<keyt, valuet>::~KVC()
{
 
}

template<typename keyt, typename valuet>
KVE<keyt, valuet>& KVC<keyt, valuet>::operator[](const keyt& sKey)
{
    unsigned int i;
    //while(list[i] && )
}