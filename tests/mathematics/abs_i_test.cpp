#include <catch2/catch_all.hpp>

extern "C" {
#include "mathematics.h"
#include <limits.h>
}

TEST_CASE( "Compute the absolute value of an int", "[abs_i]" ) {
    CHECK( abs_i( 5 ) == 5);
    CHECK( abs_i( -5 ) == 5);
    CHECK( abs_i(INT_MAX) == INT_MAX);
    // This doesn't catch the error!
    //CHECK( abs_i(INT_MIN) == -INT_MIN);
}
