#include <fstream>
#include <vector>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <bitset>

class parser
{
private:
    std::string filename;
    int count_ins = 0;

public:
    parser() {}
    parser(std::string input_file) : filename(input_file) {}

    void assemble();
    std::vector<std::array<char, 16>> get_machine_code;
    char command_type(std::string mnemonic);
    std::string symbol();
    std::string dest(std::string des);
    std::string comp(std::string com);
    std::string jump(std::string jum);
    std::array<std::string, 3> split(std::string mnemonic);
};
