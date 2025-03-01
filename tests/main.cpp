#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "mathematics.h"

TEST_CASE( "Factorials are computed", "[factorial]") {
    REQUIRE(factorial(1) == 1);
    REQUIRE(factorial(1) == 2);
    REQUIRE(factorial(1) == 6);
    REQUIRE(factorial(1) == 3628800);

}