#include <vector>
#include <fstream>

typedef std::vector<std::string> parsed_string;
typedef std::vector<parsed_string> parsed_strings;

class CSVParser
{
public:
    parsed_strings parse(const std::string& filename)
    {
        std::ifstream file(filename);
        if(!file.is_open())
        {
            throw std::runtime_error("File does not exist");
        }
        parsed_strings result;
        while(!file.eof())
        {
            parsed_string ps;
            std::string str;
            std::getline(file, str, '\n');
            if (!file.eof())
            {
                auto end = str.cend();
                for(auto iter = str.cbegin(); iter < end; iter++)
                {
                    if(*iter == ',')
                    {
                        ps.push_back(str.substr(0, iter - str.begin()));
                        iter += 2;
                        str.erase(str.begin(), iter);
                    }
                    if(*iter == '\"')
                    {
                        while(*iter != '\"' && iter < end)
                        {
                            iter++;
                        }
                        if(iter == end)
                            throw std::runtime_error("No ending quote");
                        if(*(iter + 1) != ',')
                            throw std::runtime_error("No coma after ending quote");
                        
                        ps.push_back(str.substr(1, iter - str.begin()));
                        iter += 3;
                        str.erase(str.begin(), iter);
                    }
                }
                result.push_back(ps);
            }
        }
        return result;
    }
};
