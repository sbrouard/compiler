#ifndef __EXPRESSION_SYMBOLS_H_
#define __EXPRESSION_SYMBOLS_H_

enum simple_type
{
  ENTIER = 0,
  DOUBL = 1,
  VIDE = 2,
};

enum declarator_type
{
  VAR = 3,
  FONCTION = 4,
};

union value
{
    int n;
    double f;
};

struct expression_symbol 
{
  enum simple_type t;
  union value v;
};

struct expression_symbol* create_expression_symbol_int(int n); 
struct expression_symbol* create_expression_symbol_float(double d); 

#endif // __EXPRESSION_SYMBOLS_H_
