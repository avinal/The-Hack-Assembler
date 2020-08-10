#include "../include/symbol_table.hpp"

void symbol_table::add_entry(std::string symbol, int address)
{
    symbols.insert(std::make_pair(symbol, address));
}

bool symbol_table::contains(std::string symbol)
{
    return !(symbols.find(symbol) == symbols.end());
}

int symbol_table::get_address(std::string symbol)
{
    if (contains(symbol))
    {
        return symbols[symbol];
    }else
    {
        return -1;
    }
}