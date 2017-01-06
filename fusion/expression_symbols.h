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
  enum simple_type retour; // Utile que si fonction
  enum simple_type parametres[16]; // Utile que si fonction
  int nb_param; // Utile que si fonction
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
struct declarator* create_declarator_fonction(enum declarator_type dec, char *n, enum simple_type ret, enum simple_type *s, int nb_p);

struct expression_symbol* create_expression_symbol_general(enum simple_type type, int level);
struct expression_symbol* expression_symbol_copie(struct expression_symbol *e);
char* get_expression_symbol_type(struct expression_symbol *v);
char* simple_type_to_llvm(enum simple_type s);

int var_name();

#endif // __EXPRESSION_SYMBOLS_H_
