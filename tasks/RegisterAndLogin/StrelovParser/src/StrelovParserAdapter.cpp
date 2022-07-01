#include "StrelovParserAdapter.h"

StrelovParserAdapter::StrelovParserAdapter(ParserInterface* strelovParser): strelovParser(strelovParser)
{

}

parsed_strings StrelovParserAdapter::parse(const std::string& filename) const
{
    return strelovParser->parse(filename);
}