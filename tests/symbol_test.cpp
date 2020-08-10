#include "catch/catch.hpp"
#include "../include/symbol_table.hpp"

symbol_table table;

TEST_CASE("Add a Symbol")
{
    table.add_entry("avii", 47);
    table.add_entry("krish", 7);
    table.add_entry("cosmos", 0);
    table.add_entry("noone", 90);
    REQUIRE(table.contains("avii"));
    REQUIRE(table.contains("krish"));
    REQUIRE(table.contains("cosmos"));
    REQUIRE(table.contains("noone"));
}

TEST_CASE("Get Address")
{
    REQUIRE(table.get_address("avii") == 47);
    REQUIRE(table.get_address("krish") == 7);
    REQUIRE(table.get_address("cosmos") == 0);
    REQUIRE(table.get_address("noone") == 90);
}