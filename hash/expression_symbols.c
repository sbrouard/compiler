#include "expression_symbols.h"

#include <stdlib.h>
#include <string.h>

struct expression_symbol* create_expression_symbol_int(int n)
{
  struct expression_symbol *s = malloc(sizeof(struct expression_symbol));
  s->t = ENTIER;
  s->v.n = n;
  return s;
}

struct expression_symbol* create_expression_symbol_float(float f)
{
  struct expression_symbol *s = malloc(sizeof(struct expression_symbol));
  s->t = FLOTTANT;
  s->v.f = f;
  return s;
}

struct declarator* create_declarator(enum declarator_type dec, char *n)
{
  struct declarator *res = malloc(sizeof(struct declarator));
  res->d = dec;
  strcpy(res->nom, n);
  return res;
}
