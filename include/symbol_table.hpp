#pragma once
#ifdef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP

#include <unordered_map>

class symbol_table
{
private:
    std::unordered_map<std::string, int> symbols;

public:
    symbol_table();
    ~symbol_table();

    void add_entry(std::string symbol, int address);
    bool contains(std::string symbol);
    int get_address(std::string symbol);
};

#endif
