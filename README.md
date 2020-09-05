# The-Hack-Assembler
Assembler developed to convert The HACK assembly language to machine code.

**Important: If you are taking this course then I suggest you to try to write the assembler yourself first, it is not very easy and not very tough too. At least not impossible, because I did it 😘**

## Get Started with the project
1. Directory Structure
    ```shell
        .
        |_include      # Contains headers
        |_src          # Contains Source Code and Main
        |_tests        # Unit tests for modules
        |     |_catch  # Catch2 Header only Unit Test Files
        |_example_file # Example HACK Assembly Files
    ```
2. Clone this repo
    ```shell
        git clone https://github.com/avinal/The-Hack-Assembler.git
    ```
3. Build and run, provide only [HACK Assembly Language](https://www.nand2tetris.org/project04) file. Don't confuse with `.asm` extesion. 
    ```shell
        cd The-Hack-Assembler
        make
        ./assembler file.asm
    ```
4. Tests are written using header only unit test framework [Catch2](https://github.com/catchorg/Catch2). Not needed if you just want to use the project.
    ```shell
        make test
        ./test
    ```
5. Start over after modification
    ```shell
        make clean
    ```


## Tips
In case you want to modify this project, you can use [Boost C++ Libraries](https://www.boost.org/), they can simplify many tasks needed by this project. 

## Some Words
This was a nice project and taugh me many things. Given below are some miraculous code snippets that proved to be really useful and are well researched. Hope you will find them useful.
1. Check if a `std::string` only contains digits or not.
    ```cpp
        #include <algorithm>
        inline bool isNumber(std::string str)
        {
            return (!str.empty() && std::all_of(str.begin(), str.end(), ::isdigit));
        }
    ```
2. Trim a string of spaces, tabs, carrige return, vertical tabs, newline chars.
    ```cpp
        inline std::string trim(std::string str)
        {
            str.erase(0, str.find_first_not_of(" \r\t\v\n"));                 //prefixing 
            str.erase(std::min(str.find_first_of(" \r\t\v\n"), str.size())); //surfixing 
            return str;
        }
    ```
3. Convert a Decimal number to Binary String of certain number of bits. (Most Interesting)
    ```cpp
        #include <bitset>
        inline std::string toBinaryString(int decimal)
        {
            return std::bitset<16>(decimal).to_string(); // 16 is the number of bits required
        }
    ```
