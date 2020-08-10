#include "catch/catch.hpp"
#include "../include/parser.hpp"

typedef std::array<std::string, 3> Token;
parser testpar;

TEST_CASE("C-Instruction Split")
{
    Token token1 = {"null", "M", "null"};
    Token token2 = {"null", "M+1", "JMP"};
    Token token3 = {"AMD", "!D", "null"};
    Token token4 = {"MD", "M+D", "JGT"};
    std::string cases[4] = {"M", "M+1;JMP", "AMD=!D", "MD=M+D;JGT"};
    REQUIRE(testpar.split(cases[0]) == token1);
    REQUIRE(testpar.split(cases[1]) == token2);
    REQUIRE(testpar.split(cases[2]) == token3);
    REQUIRE(testpar.split(cases[3]) == token4);
}

TEST_CASE("Command Type")
{
    std::string cases[4] = {"@123", "@sym", "M=M+1", "(LABEL)"};
    REQUIRE(testpar.command_type(cases[0]) == 'A');
    REQUIRE(testpar.command_type(cases[1]) == 'A');
    REQUIRE(testpar.command_type(cases[2]) == 'C');
    REQUIRE(testpar.command_type(cases[3]) == 'L');
}

TEST_CASE("Comparision string")
{
    std::string cases[14] = {"0", "-1", "D", "M", "A+1", "-D", "-M", "!D", "!A", "D-M", "D|A", "D&M", "A-D", "D-1"};
    std::string results[14] = {"0101010",
                               "0111010",
                               "0001100",
                               "1110000",
                               "0110111",
                               "0001111",
                               "1110011",
                               "0001101",
                               "0110001",
                               "1010011",
                               "0010101",
                               "1000000",
                               "0000111",
                               "0001110"};
    REQUIRE(testpar.comp(cases[0]) == results[0]);
    REQUIRE(testpar.comp(cases[1]) == results[1]);
    REQUIRE(testpar.comp(cases[2]) == results[2]);
    REQUIRE(testpar.comp(cases[3]) == results[3]);
    REQUIRE(testpar.comp(cases[4]) == results[4]);
    REQUIRE(testpar.comp(cases[5]) == results[5]);
    REQUIRE(testpar.comp(cases[6]) == results[6]);
    REQUIRE(testpar.comp(cases[7]) == results[7]);
    REQUIRE(testpar.comp(cases[8]) == results[8]);
    REQUIRE(testpar.comp(cases[9]) == results[9]);
    REQUIRE(testpar.comp(cases[10]) == results[10]);
    REQUIRE(testpar.comp(cases[11]) == results[11]);
    REQUIRE(testpar.comp(cases[12]) == results[12]);
    REQUIRE(testpar.comp(cases[13]) == results[13]);
}

TEST_CASE("Destination String")
{
    std::string cases[8] = {"null", "M", "D", "MD", "A", "AM", "AD", "AMD"};
    std::string results[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};
    REQUIRE(testpar.dest(cases[0]) == results[0]);
    REQUIRE(testpar.dest(cases[1]) == results[1]);
    REQUIRE(testpar.dest(cases[2]) == results[2]);
    REQUIRE(testpar.dest(cases[3]) == results[3]);
    REQUIRE(testpar.dest(cases[4]) == results[4]);
    REQUIRE(testpar.dest(cases[5]) == results[5]);
    REQUIRE(testpar.dest(cases[6]) == results[6]);
    REQUIRE(testpar.dest(cases[7]) == results[7]);
}

TEST_CASE("Jump String")
{
    std::string cases[8] = {"null", "JGT", "JEQ", "JGE", "JLT", "JNE", "JLE", "JMP"};
    std::string results[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};
    REQUIRE(testpar.jump(cases[0]) == results[0]);
    REQUIRE(testpar.jump(cases[1]) == results[1]);
    REQUIRE(testpar.jump(cases[2]) == results[2]);
    REQUIRE(testpar.jump(cases[3]) == results[3]);
    REQUIRE(testpar.jump(cases[4]) == results[4]);
    REQUIRE(testpar.jump(cases[5]) == results[5]);
    REQUIRE(testpar.jump(cases[6]) == results[6]);
    REQUIRE(testpar.jump(cases[7]) == results[7]);
}