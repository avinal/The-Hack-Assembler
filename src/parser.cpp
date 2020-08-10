#include "../include/parser.hpp"

void parser::assemble()
{
    std::ifstream asmfile(filename);
    int pos = filename.find(".");
    filename.erase(pos);
    std::string outfile = filename + ".hack";

    std::ofstream genfile(outfile);

    std::string instruction;
    if (asmfile.is_open())
    {
        while (std::getline(asmfile, instruction))
        {
            std::string converted = "";
            std::string binary;
            instruction.erase(instruction.size() - 1);
            if (instruction.empty() ||
                instruction.substr(0, 2) == "//")
            {
                continue;
            }
            else
            {
                switch (command_type(instruction))
                {
                case 'A':
                {
                    count_ins++;
                    converted += "0";
                    int address;
                    instruction = instruction.substr(1);
                    if (std::all_of(instruction.begin(),instruction.end(),::isdigit)){
                        address = std::stoi(instruction);
                    }else
                    {
                        
                    }
                    
                        binary = std::bitset<15>(std::stoi(instruction.substr(1))).to_string();
                    converted += binary;
                }
                break;
                case 'C':
                {
                    count_ins++;
                    auto token = split(instruction);
                    binary = comp(token[1]) + dest(token[0]) + jump(token[2]);
                    converted += "111" + binary;
                }
                break;
                case 'L':
                    break;
                default:
                    break;
                }
                if (genfile.is_open())
                {
                    genfile << converted << std::endl;
                }
            }
        }
        genfile.close();
        asmfile.close();
    }
}

std::array<std::string, 3> parser::split(std::string mnemonic)
{
    std::array<std::string, 3> token;
    int pos;
    if ((pos = mnemonic.find(';')) != std::string::npos)
    {
        token.at(2) = mnemonic.substr(pos + 1);
        mnemonic.erase(pos);
    }
    else
    {
        token.at(2) = "null";
    }

    if ((pos = mnemonic.find("=")) != std::string::npos)
    {
        token.at(1) = mnemonic.substr(pos + 1);
        mnemonic.erase(pos);
        token.at(0) = mnemonic;
    }
    else
    {
        token.at(1) = mnemonic;
        token.at(0) = "null";
    }
    return token;
}

std::string parser::comp(std::string com)
{
    const std::unordered_map<std::string, std::string> compare({{"0", "101010"},
                                                                {"1", "111111"},
                                                                {"-1", "111010"},
                                                                {"D", "001100"},
                                                                {"C", "110000"},
                                                                {"!D", "001101"},
                                                                {"!C", "110001"},
                                                                {"-D", "001111"},
                                                                {"-C", "110011"},
                                                                {"D+1", "011111"},
                                                                {"C+1", "110111"},
                                                                {"D-1", "001110"},
                                                                {"C-1", "110010"},
                                                                {"D+C", "000010"},
                                                                {"D-C", "010011"},
                                                                {"C-D", "000111"},
                                                                {"D&C", "000000"},
                                                                {"D|C", "010101"}});

    std::string recomp = "";
    int pos;
    char am;
    if ((pos = com.find("M")) != std::string::npos)
    {
        com.replace(pos, 1, "C");
        recomp += "1";
    }
    else if ((pos = com.find("A")) != std::string::npos)
    {
        com.replace(pos, 1, "C");
        recomp += "0";
    }
    else
    {
        recomp += "0";
    }

    if (compare.find(com) != compare.end())
    {
        recomp += compare.at(com);
    }
    return recomp;
}

std::string parser::dest(std::string des)
{
    const std::unordered_map<std::string, std::string> destination({{"null", "000"},
                                                                    {"M", "001"},
                                                                    {"D", "010"},
                                                                    {"MD", "011"},
                                                                    {"A", "100"},
                                                                    {"AM", "101"},
                                                                    {"AD", "110"},
                                                                    {"AMD", "111"}});
    return destination.at(des);
}

std::string parser::jump(std::string jum)
{
    const std::unordered_map<std::string, std::string> jumpto({{"null", "000"},
                                                               {"JGT", "001"},
                                                               {"JEQ", "010"},
                                                               {"JGE", "011"},
                                                               {"JLT", "100"},
                                                               {"JNE", "101"},
                                                               {"JLE", "110"},
                                                               {"JMP", "111"}});
    return jumpto.at(jum);
}

char parser::command_type(std::string mnemonic)
{
    if (mnemonic.front() == '@')
    {
        return 'A';
    }
    else if (mnemonic.front() == '(' && mnemonic.back() == ')')
    {
        return 'L';
    }
    else
    {
        return 'C';
    }
}