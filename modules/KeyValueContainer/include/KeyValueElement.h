#pragma once

template<typename keyt, typename valuet>
class KeyValueContainer;

template<typename keyt, typename valuet>
class KeyValueElement
{
private:
    const keyt key;
    const valuet value;

    KeyValueElement();
    
    void operator=(const valuet newData);

    friend class KeyValueContainer<keyt, valuet>;
};