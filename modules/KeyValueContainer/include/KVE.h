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