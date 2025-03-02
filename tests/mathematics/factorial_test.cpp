#include <catch2/catch_all.hpp>

extern "C" {
#include "mathematics.h"
#include "libft.h"
}


TEST_CASE( "Factorials are computed", "[factorial]" ) {
    CHECK( factorial(1) == 1 );
    CHECK( factorial(2) == 2 );
    CHECK( factorial(3) == 6 );
    CHECK( factorial(10) == 3628800 );
    CHECK( factorial(0) == 1 );
}