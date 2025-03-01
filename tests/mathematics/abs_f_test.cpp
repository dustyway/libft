#include <catch2/catch.hpp>

extern "C" {
#include "mathematics.h"
}

TEST_CASE( "Compute the absolute value of a float", "[abs_f]" ) {
    CHECK( abs_f( 7 ) == 7);
    CHECK( abs_f(5.5) == 5.5 );
    CHECK( abs_f(-5.5) == 5.5 );
    CHECK( abs_f(0) == 0 );
}

