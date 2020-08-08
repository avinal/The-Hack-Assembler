#pragma once
#ifdef CODE_HPP
#define CODE_HPP

#include <array>

class code
{
private:
    const std::string mnemonic;

public:
    code(std::string mno) : mnemonic(mno) {}
    ~code();
    std::array<char, 3> dest();
    std::array<char, 7> comp();
    std::array<char, 3> jump();
};

#endif