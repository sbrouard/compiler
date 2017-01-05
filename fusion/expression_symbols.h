#ifndef __EXPRESSION_SYMBOLS_H_
#define __EXPRESSION_SYMBOLS_H_

#define LONGUEUR_MAX 64
#define MAX_VAR 1024

enum assign{
  ASSIGN,
  ASSIGN_MUL,
  ASSIGN_DIV,
  ASSIGN_REM,
  ASSIGN_SHL,
  ASSIGN_SHR,
  ASSIGN_ADD,
  ASSIGN_SUB,
};

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
  char *code;
  int is_var;
  int var;
  int lvl;
};

struct expression_symbol* create_expression_symbol_int(int n); 
struct expression_symbol* create_expression_symbol_float(double d); 

struct declarator* create_declarator(enum declarator_type d, char *nom);

struct expression_symbol* create_expression_symbol_general(enum simple_type type, int level);
struct expression_symbol* expression_symbol_copie(struct expression_symbol *e);
char* get_expression_symbol_type(struct expression_symbol *v);

int var_name();

#endif // __EXPRESSION_SYMBOLS_H_
