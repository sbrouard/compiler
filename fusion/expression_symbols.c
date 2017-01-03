#include "expression_symbols.h"

#include <stdlib.h>
#include <string.h>

struct expression_symbol* create_expression_symbol_int(int n)
{
  struct expression_symbol *s = malloc(sizeof(struct expression_symbol));
  s->t = ENTIER;
  s->v.n = n;
  s->code = "";
  s->var = var_name();
  s->is_var = 0;
  return s;
}

struct expression_symbol* create_expression_symbol_float(double d)
{
  struct expression_symbol *s = malloc(sizeof(struct expression_symbol));
  s->t = DOUBL;
  s->v.f = d;
  s->code = "";
  s->var = var_name();
  s->is_var = 0;
  s->var = -1;
  return s;
}

struct declarator* create_declarator(enum declarator_type dec, char *n)
{
  struct declarator *res = malloc(sizeof(struct declarator));
  res->d = dec;
  strcpy(res->nom, n);
  return res;
}

struct expression_symbol* create_expression_symbol_general(enum simple_type type, int level){
  struct expression_symbol *res = malloc(sizeof(struct expression_symbol));
  res->t = type;
  res->lvl = level;
  res->code = "";
  res->var = var_name();
  res->is_var = 1;
  return res;
}

char* get_expression_symbol_type(struct expression_symbol *v){

  switch(v->t){
  case 0:
    return "int";
    break;
  case 1:
    return "double";
    break;
  case 2:
    return "void";
    break;
  default:
    return "inconnu";
    break;
  }

}

int var_name(){
  static int i = 0;
  i++;
  return i;
}
