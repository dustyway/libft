#include <catch2/catch.hpp>

extern "C" {
#include "stack.h"
}

TEST_CASE( "CHECK the basic functionality of t_stack", "[stack]" ) {
  t_stack *s;
  int a = 1;
  int b = 2;
  int c = 3;

  int *ap = (int *)malloc(sizeof(int));
  int *bp = (int *)malloc(sizeof(int));
  int *cp = (int *)malloc(sizeof(int));
  int *ip;

  stack_init(&s,free);
  CHECK( stack_peek(s) == NULL);
  CHECK( stack_size(s) == 0);
  stack_push(s,&a);
  CHECK( stack_peek(s) == &a);
  CHECK( *((int *)stack_peek(s)) == 1);
  CHECK( stack_size(s) == 1);
  stack_push(s,&b);
  stack_push(s,&c);
  CHECK( stack_size(s) == 3);
  CHECK( stack_peek(s) == &c);
  ip = (int *) stack_pop(s);
  CHECK( ip == &c);
  CHECK( stack_size(s) == 2);
  CHECK( stack_peek(s) == &b);
  CHECK( stack_is_empty(s) == 0);
  CHECK( *(int *)stack_pop(s) == 2);
  CHECK( *(int *)stack_pop(s) == 1);
  CHECK( stack_is_empty(s) == 1);
  stack_push(s,ap);
  stack_push(s,bp);
  stack_push(s,cp);
  clear_stack(&s);
  CHECK( s == NULL);
}

