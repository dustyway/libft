//
// Created by pschneid on 3/1/25.
//
#include <libft_addendum.h>

#include "ft_printf.h"

int main() {
  int a=23;
  int b=42;
  int c=5;
  int *ip;

  t_list *l = NULL;
  ft_lstadd_front(&l,ft_lstnew(&a));
  ip =lst_nth(l,0);
  ft_printf("hello world: %d\n", *ip);
}