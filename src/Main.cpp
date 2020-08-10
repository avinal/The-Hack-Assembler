#include "../include/parser.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    std::string asmfile(argv[1]);
    parser pars(asmfile);
    pars.assemble();
    return 0;
}
