#pragma once

#include <vector>
#include <utility>

template<typename keyt, typename valuet>
class KVC
{
private:
    std::vector<std::pair<keyt, valuet>> map;

    typename std::vector<std::pair<keyt, valuet>>::iterator findKey(const keyt& sKey);
public:
    KVC() = default;
    KVC(const KVC<keyt, valuet>& other);
    ~KVC() = default;

    valuet& operator[](const keyt& sKey);
};






template<typename keyt, typename valuet>
typename std::vector<std::pair<keyt, valuet>>::iterator KVC<keyt, valuet>::findKey(const keyt& sKey)
{
    typename std::vector<std::pair<keyt, valuet>>::iterator iter = map.begin();
    typename std::vector<std::pair<keyt, valuet>>::iterator eIter = map.end();
    while ((iter != eIter) && (iter->first != sKey))
        ++iter;
    return iter;
}

template<typename keyt, typename valuet>
KVC<keyt, valuet>::KVC(const KVC<keyt, valuet>& other): map(other.map){}

template<typename keyt, typename valuet>
valuet& KVC<keyt, valuet>::operator[](const keyt& sKey)
{
    typename std::vector<std::pair<keyt, valuet>>::iterator iter = findKey(sKey);
    if (iter == map.end())
    {
        map.insert(iter, std::pair<keyt, valuet>(sKey, valuet()));
        iter = map.end();
        --iter;
    }
    return iter->second;
}