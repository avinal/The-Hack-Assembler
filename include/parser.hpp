#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <bitset>
#include "symbol_table.hpp"

class parser
{
private:
    std::string filename;
    symbol_table table;

public:
    parser() {}
    parser(std::string input_file) : filename(input_file) {}

    void assemble();
    std::vector<std::array<char, 16>> get_machine_code;
    char command_type(std::string mnemonic);
    void create_table();
    std::string dest(std::string des);
    std::string comp(std::string com);
    std::string jump(std::string jum);
    std::array<std::string, 3> split(std::string mnemonic);
};
