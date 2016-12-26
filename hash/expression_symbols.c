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

struct variable* create_variable(enum simple_type type, int level){
  struct variable *res = malloc(sizeof(struct variable));
  res->t = type;
  res->lvl = level;
  return res;
}

char* get_variable_type(struct variable *v){

  switch(v->t){
  case 0:
    return "int";
    break;
  case 1:
    return "float";
    break;
  case 2:
    return "void";
    break;
  default:
    return "inconnu";
    break;
  }

}
