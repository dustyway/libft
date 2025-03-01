#include <catch2/catch.hpp>

extern "C" {
#include "libft_addendum.h"
}

TEST_CASE( "Compute the absolute value of a float", "[absf]" ) {
    CHECK( absf( 7 ) == 7);
    CHECK( absf(5.5) == 5.5 );
    CHECK( absf(-5.5) == 5.5 );
    CHECK( absf(0) == 0 );
}

