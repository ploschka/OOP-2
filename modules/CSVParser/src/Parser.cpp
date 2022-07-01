#include <vector>
#include <fstream>
#include "Parser.h"

parsed_strings CSVParser::parse(const std::string& filename) const
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
            auto end = str.end();
            for(auto iter = str.begin(); iter <= end; iter++)
            {
                if(*iter == ',' || iter == end)
                {
                    ps.push_back(str.substr(0, iter - str.begin()));
                    if(iter < end)
                        iter += 2;
                    str.erase(str.begin(), iter);
                    if(iter < end)
                    {
                        iter = str.begin()-1;
                        end = str.end();                        
                    }
                }
                else if(*iter == '\"')
                {
                    do
                    {
                        iter++;
                    }
                    while(*iter != '\"' && iter != end);
                    if(iter == end)
                        throw std::runtime_error("No ending quote");
                    if(*(iter + 1) != ',' && (iter + 1) == end)
                        throw std::runtime_error("No coma after ending quote");
                    
                    ps.push_back(str.substr(1, iter - str.begin() - 1));
                    iter += 3;
                    str.erase(str.begin(), iter);
                    iter = str.begin()-1;
                    end = str.end();
                }
            }
            result.push_back(ps);
        }
    }
    return result;
}
