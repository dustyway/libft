#include <catch2/catch.hpp>

extern "C" {
#include "stack.h"
}

TEST_CASE( "CHECK the basic functionality of t_stack", "[stack]" ) {
  t_stack *stack;
  int a = 1;
  int b = 2;
  int c = 3;

  int *ap = (int *)malloc(sizeof(int));
  int *bp = (int *)malloc(sizeof(int));
  int *cp = (int *)malloc(sizeof(int));
  int *ip;

  init_stack(&stack,free);
  CHECK( peek_stack(stack) == NULL);
  CHECK( stack_size(stack) == 0);
  push_stack(stack,&a);
  CHECK( peek_stack(stack) == &a);
  CHECK( *((int *)peek_stack(stack)) == 1);
  CHECK( stack_size(stack) == 1);
  push_stack(stack,&b);
  push_stack(stack,&c);
  CHECK( stack_size(stack) == 3);
  CHECK( peek_stack(stack) == &c);
  ip = (int *) pop_stack(stack);
  CHECK( ip == &c);
  CHECK( stack_size(stack) == 2);
  CHECK( peek_stack(stack) == &b);
  CHECK( stack_is_empty(stack) == 0);
  CHECK( *(int *)pop_stack(stack) == 2);
  CHECK( *(int *)pop_stack(stack) == 1);
  CHECK( stack_is_empty(stack) == 1);
  push_stack(stack,ap);
  push_stack(stack,bp);
  push_stack(stack,cp);
  clear_stack(&stack);
  CHECK( stack == NULL);
}

