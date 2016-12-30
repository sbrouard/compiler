#include <stdio.h>
#include <stdlib.h>
#include <search.h>

#include "expression_symbol.h"

int add_hash(char *nom, struct expression_symbol *es){

  ENTRY e, *ep;

  e.key = nom;
  e.data = (void *) es;
  
  ep = hsearch(e, ENTER);

  // There should be no error
  if (ep == NULL) {
    fprintf(stderr, "hash table : entry failed\n");
    exit(EXIT_FAILURE);
  }
  
}

struct expression_symbol* recup_hash(char *nom){
  ENTRY e, *ep;
  e.key = nom;

  ep = hsearch(e, FIND);
  return ((struct expression_symbol *)(ep->data));
}

int is_in_hash(char *nom){
  ENTRY e;
  e.key = nom;

  return (hsearch(e, FIND) != NULL)
}

