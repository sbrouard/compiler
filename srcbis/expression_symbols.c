#include "expression_symbols.h"

#include <stdlib.h>
#include <stdio.h>

struct expression_symbol* create_expression_symbol_int(int n)
{
  struct expression_symbol *s = malloc(sizeof(struct expression_symbol));
  s->t = ENTIER;
  s->v.n = n;
  s->code = "";
  s->var = var_name();
  return s;
}

struct expression_symbol* create_expression_symbol_float(double d)
{
  struct expression_symbol *s = malloc(sizeof(struct expression_symbol));
  s->t = DOUBL;
  s->v.f = d;
  s->code = "";
  s->var = var_name();
  return s;
}


int var_name(){
  static int i = 0;
  i++;
  return i;
}
