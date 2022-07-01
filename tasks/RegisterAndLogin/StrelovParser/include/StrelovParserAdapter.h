#pragma once

#include "Parser.h"
#include "StrelovParser.h"

class StrelovParserAdapter: public IParser
{
private:
    ParserInterface* strelovParser;
public:
    StrelovParserAdapter(ParserInterface* strelovParser);
    parsed_strings parse(const std::string& filename) const;
};