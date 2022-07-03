#include "Parser.h"
#include "gtest/gtest.h"

TEST(ParserTest, NoQuotesTest)
{
    parsed_strings p;
    p = {{"Lol", "Kek", "Cheburek"},
        {"Lalala", "alalaL"},
        {"GGG"}};
    
    CSVParser par;
    parsed_strings pp = par.parse("test1.csv");
    for(int i = 0; i < pp.size(); i++)
    {
        for(int j = 0; j < pp[i].size(); j++)
        {
            EXPECT_EQ(p[i][j], pp[i][j]);
        }
    }
}

TEST(ParserTest, QuotesTest)
{
    parsed_strings p;
    p = {{"Lol", "Kek", "Cheburek, ochen vkusniy cheburek"},
        {"Lalala", "alalaL"},
        {"GGG, hihi"}};
    
    CSVParser par;
    parsed_strings pp = par.parse("test2.csv");
    for(int i = 0; i < pp.size(); i++)
    {
        for(int j = 0; j < pp[i].size(); j++)
        {
            EXPECT_EQ(p[i][j], pp[i][j]);
        }
    }
}