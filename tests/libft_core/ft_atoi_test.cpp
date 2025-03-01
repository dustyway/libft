#include <catch2/catch.hpp>

extern "C" {
#include "libft.h"
}

TEST_CASE( "Check the output of ft_atoi", "[ft_atoi]" ) {
    CHECK( ft_atoi("0") == 0 );
    CHECK( ft_atoi("546:5") == 546 );
    CHECK( ft_atoi("-4886") == -4886 );
    CHECK( ft_atoi("+548") == 548 );
    CHECK( ft_atoi("054854") == 54854 );
    CHECK( ft_atoi("000074") == 74 );
    CHECK( ft_atoi("+-54") == 0 );
    CHECK( ft_atoi("-+48") == 0 );
    CHECK( ft_atoi("--47") == 0 );
    CHECK( ft_atoi("++47") == 0 );
    CHECK( ft_atoi("+47+5") == 47 );
    CHECK( ft_atoi("-47-5") == -47 );
    CHECK( ft_atoi("\e475") == 0 );
    CHECK( ft_atoi("\t\n\r\v\f  469 \n") == 469 );
    CHECK( ft_atoi("-2147483648") == -2147483648 );
    CHECK( ft_atoi("2147483647") == 2147483647 );
    CHECK( ft_atoi("\t\n\r\v\fd469 \n") == 0 );
    CHECK( ft_atoi("\n\n\n  -46\b9 \n5d6") == -46 );
}
