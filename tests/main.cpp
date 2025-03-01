//
// Created by ps on 3/1/25.
//
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <iostream>
extern "C" {
#include "mathematics.h"
}
int main() {
  unsigned int a;

  a = factorial(10);
  std::cout << "Hello World cpp " << a << std::endl;
  return 0;
}