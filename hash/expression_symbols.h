#ifndef __EXPRESSION_SYMBOLS_H_
#define __EXPRESSION_SYMBOLS_H_

#define LONGUEUR_MAX 64
#define MAX_VAR 1024
enum simple_type
{
  ENTIER = 0,
  FLOTTANT = 1,
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
    float f;
};

struct declarator
{
  enum declarator_type d;
  char nom[LONGUEUR_MAX];
};

struct variable
{
  enum simple_type t;
  int lvl;
};

struct expression_symbol 
{
  enum simple_type t;
  union value v;
};

struct expression_symbol* create_expression_symbol_int(int n); 
struct expression_symbol* create_expression_symbol_float(float f); 

struct declarator* create_declarator(enum declarator_type d, char *nom);

struct variable* create_variable(enum simple_type type, int level);
char* get_variable_type(struct variable *v);

#endif // __EXPRESSION_SYMBOLS_H_
