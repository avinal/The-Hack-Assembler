#pragma once
#ifdef PARSER_HPP
#define PARSER_HPP

#include "code.hpp"
#include <fstream>

class parser : public code
{
private:
    std::ifstream asmfile;

public:
    parser(std::string input_file);
    ~parser();

    bool has_more_commands();
    void advance();
    char command_type();
    std::string symbol();
    std::array<char, 3> dest();
    std::array<char, 7> comp();
    std::array<char, 3> jump();
};

#endif
