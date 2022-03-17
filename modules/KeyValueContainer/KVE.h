#pragma once

template<typename keyt, typename valuet>
class KVC;

template<typename keyt, typename valuet>
class KVE
{
private:
    const keyt key;
    const valuet value;

    KVE(const keyt key, const valuet value);
    KVE(const KVE<keyt, valuet>& other);
    
    void operator=(const valuet newData);

    friend class KVC<keyt, valuet>;
};






template<typename keyt, typename valuet>
KVE<keyt, valuet>::KVE(const keyt key, const valuet value)
{

}

template<typename keyt, typename valuet>
KVE<keyt, valuet>::KVE(const KVE<keyt, valuet>& other)
{

}

template<typename keyt, typename valuet>
void KVE<keyt, valuet>::operator=(const valuet newData)
{

}