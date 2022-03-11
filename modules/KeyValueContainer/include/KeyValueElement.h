#pragma once

template<typename keyt, typename valuet>
class KeyValueContainer;

template<typename keyt, typename valuet>
class KeyValueElement
{
private:
    const keyt key;
    const valuet value;

    KeyValueElement(const keyt key, const valuet value);
    KeyValueElement(const KeyValueElement<keyt, valuet>& other);
    
    void operator=(const valuet newData);

    friend class KeyValueContainer<keyt, valuet>;
};