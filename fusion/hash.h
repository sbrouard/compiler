#ifndef HASH_H
#define HASH_H

#include "expression_symbols.h"

int add_hash(char *nom, struct expression_symbol *es);
struct expression_symbol* recup_hash(char *nom);
int is_in_hash(char *nom);

#endif
