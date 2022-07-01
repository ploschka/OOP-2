#include "Parser.h"
#include "UserDatabase.h"
#include <fstream>

Database::Database(IParser* parser, const std::string& filename): parser(parser), filename(filename)
{

}
void Database::write(const parsed_string& user)
{
    std::ofstream file(filename, std::ios_base::app);
    file << user[0] << ", " << user[1] << std::endl;
    file.close();
}
bool Database::contains(const std::string& login) const
{
    auto parsed = parser->parse(filename);
    for (auto& i: parsed)
    {
        if(login == i[0])
        {
            return true;
        }
    }
    return false;
}
parsed_strings Database::read() const
{
    return parser->parse(filename);
}
