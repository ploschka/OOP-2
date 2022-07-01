#include "StrelovParser.h"
#include <iostream>
#include <fstream>

Parser::Parser(const std::string &join_str, bool table_mode) {
    this->join_str = join_str;
    this->table_mode = table_mode;
}

Parser::Parser() {
    this->join_str = " ";
    this->table_mode = true;
}

std::vector<std::vector<std::string>> Parser::parse(const std::string &filename) {
    std::ifstream file(filename);
    if (!file)
        throw std::runtime_error("File does not exist");
    std::vector<std::vector<std::string>> result;
    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> parsed_line;
        line += ",";
        bool quotes_mode = false;
        int substr_start_index = 0;
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == '"')  // Если попали на кавычку
                quotes_mode = !quotes_mode;
            else if (line[i] == ',' && !quotes_mode) {  // Если встретили запятую вне кавычек
                parsed_line.push_back(
                        strip(line.substr(substr_start_index, i - substr_start_index), '"')
                );
                substr_start_index = i + 1;
            }
        }
        result.push_back(parsed_line);
    }
    return result;
}

void Parser::print(const std::vector<std::vector<std::string>> &parsed_data) {
    if (this->table_mode) {
        int max_line_count = 0;  // Ширина таблицы в столбцах
        for (const std::vector<std::string> &line: parsed_data)
            max_line_count = max_line_count < line.size() ? line.size() : max_line_count;

        std::vector<int> max_lengths(max_line_count);  // В каждом столбце максимальная ширина ячейки
        for (const std::vector<std::string> &line: parsed_data) {
            for (int i = 0; i < line.size(); i++)
                max_lengths[i] = max_lengths[i] < line[i].size() ? line[i].size() : max_lengths[i];
        }

        for (const std::vector<std::string> &line: parsed_data) {
            for (int i = 0; i < line.size(); i++) {
                int spaces_left = max_lengths[i] - line[i].size();
                std::string spaces = std::string(spaces_left, ' ');
                std::cout << line[i] << spaces << this->join_str;
            }
            std::cout << '\n';
        }
    } else {
        for (const std::vector<std::string> &line: parsed_data) {
            for (const std::string &word: line)
                std::cout << word << this->join_str;
            std::cout << '\n';
        }
    }
}

void Parser::write_to_file(const std::vector<std::vector<std::string>> &parsed_data, const std::string &filename) {
    std::ofstream out(filename);
    for (const std::vector<std::string> &line: parsed_data) {
        for (int i = 0; i < line.size() - 1; i++) {
            auto cell_value = line[i];
            bool has_commas = false;
            for (auto ch: cell_value)
                has_commas = (ch == ',') || has_commas;
            if (has_commas)
                out << "\"" << cell_value << "\",";
            else
                out << cell_value << ",";
        }
        out << line[line.size() - 1] << std::endl;
    }
    out.close();
}

std::string strip(const std::string& str, char ch) {
    bool remove_left = str[0] == ch;
    bool remove_right = str[str.size() - 1] == ch;
    return str.substr(remove_left, str.size() - remove_left - remove_right);
}