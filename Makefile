CXX = g++
STDVERSION = -std=c++17
WARNINGS = -pedantic -Wall -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable


TARGET = assembler
OBJ_DIR = build 
OBJECTS = build/symbol_table.o build/parser.o 
TEST_OBJS = build/parser_test.o 
all:$(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(WARNINGS) $(STDVERSION) -o $(TARGET) src/Main.cpp $(OBJECTS)


build/parser.o: src/parser.cpp include/parser.hpp 
	$(CXX) $(WARNINGS) $(STDVERSION) -c src/parser.cpp -o build/parser.o

build/symbol_table.o:src/symbol_table.cpp include/symbol_table.hpp
	$(CXX) $(STDVERSION) -c src/symbol_table.cpp -o build/symbol_table.o


test:
	$(CXX) $(STDVERSION) tests/*.cpp tests/catch/catch_main.cpp src/parser.cpp src/symbol_table.cpp -o test

clean:
	rm -rf build/*.o $(TARGET) test