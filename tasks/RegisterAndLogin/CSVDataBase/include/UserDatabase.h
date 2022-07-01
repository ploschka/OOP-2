#pragma once

#include "Parser.h"

class Database
{
private:
    std::string filename;
    IParser* parser;
public:
    Database(IParser* parser, const std::string& filename);
    void write(const parsed_string& user);
    bool contains(const std::string& login) const;
    parsed_strings read() const;
};
