#include <vector>
#include <string>

typedef std::vector<std::string> parsed_string;
typedef std::vector<parsed_string> parsed_strings;

class CSVParser
{
public:
    parsed_strings parse(const std::string& filename) const;
};
