#ifndef __EXPRESSION_H_
#define __EXPRESSION_H_

#include "expression_symbols.h"

struct expression
{
  char *code;
  enum simple_type type;
  int var;
};


#endif
