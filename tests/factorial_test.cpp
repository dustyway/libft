//
// Created by pschneid on 3/1/25.
//
#include <catch2/catch.hpp>

extern "C" {
#include "mathematics.h"
}


TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE( factorial(1) == 1 );
    REQUIRE( factorial(2) == 2 );
    REQUIRE( factorial(3) == 6 );
    REQUIRE( factorial(10) == 3628800 );
    //REQUIRE( Factorial(0) == 1 );
}