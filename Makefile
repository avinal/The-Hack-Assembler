CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic-errors -std=c++17

OBJECTS = build/parser.o build/code.o build/symbol_table.o

TARGET = assembler

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) src/Main.cpp $(OBJECTS)


build/parser.o:src/parser.cpp include/parser.hpp
	$(CXX) $(CXXFLAGS) -c src/parser.cpp -o build/parser.o

build/code.o:src/code.cpp include/code.hpp
	$(CXX) $(CXXFLAGS) -c src/code.cpp -o build/code.o

build/symbol_table.o:src/symbol_table.cpp include/symbol_table.hpp
	$(CXX) $(CXXFLAGS) -c src/symbol_table.cpp -o build/symbol_table.o

clean:
	rm -f build/*