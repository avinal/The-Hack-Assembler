#define CATCH_CONFIG_MAIN
#include "catch.hpp"

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

TEST_CASE("Demo test")
{
    REQUIRE(1 == 1);
}