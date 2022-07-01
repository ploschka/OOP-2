#pragma once

#include <string>
#include <vector>
#include <ostream>

class ParserInterface {
public:
    virtual std::vector<std::vector<std::string>> parse(const std::string &filename) = 0;

    virtual void print(const std::vector<std::vector<std::string>> &parsed_data) = 0;

    virtual void write_to_file(const std::vector<std::vector<std::string>> &parsed_data, const std::string& filename) = 0;
};

class Parser : public ParserInterface {
private:
    std::string join_str;
    bool table_mode;
public:
    explicit Parser(const std::string &join_str, bool table_mode);

    Parser();

    std::vector<std::vector<std::string>> parse(const std::string &filename) override;

    void print(const std::vector<std::vector<std::string>> &parsed_data) override;

    void write_to_file(const std::vector<std::vector<std::string>> &parsed_data, const std::string& filename) override;
};

std::string strip(const std::string& str, char ch);