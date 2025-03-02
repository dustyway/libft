#include <catch2/catch_all.hpp>
extern "C" {
#include "libft_addendum.h"
}

TEST_CASE( "return the nth element of a list starting from 0", "[lst_nth]" ) {
    int a=23;
    int b=42;
    int c=5;
    int *ip;

    t_list *l = NULL;
    ft_lstadd_front(&l,ft_lstnew(&a));
    ft_lstadd_front(&l,ft_lstnew(&b));
    ft_lstadd_front(&l,ft_lstnew(&c));
    CHECK( l->content == &c);
    CHECK( lst_nth(l,2) == &a);
    CHECK( lst_nth(l,1) == &b);
    CHECK( lst_nth(l,0) == &c);
    CHECK( lst_nth(l,4) == NULL);
    CHECK( lst_nth(l,-1) == NULL);
}

