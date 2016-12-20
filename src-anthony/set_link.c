#include <stdio.h>
#include <stdlib.h>
#include "set_link.h"

struct lelement *find(struct link *lnk, int x)
{
  struct lelement *current = lnk__first(lnk);
  if(llm__next(current)==current || current->data >= x) // empty link or data > x
    return NULL;

  while((current->next)->data < x && !llm__is_end_mark(llm__next(current)))
    current = llm__next(current);
  return current;
}

struct set* set__empty()
{
  struct set *set = malloc(sizeof(struct set));
  struct link *lnk = malloc(sizeof(struct link));
  *lnk = lnk__empty();
  set->l=lnk;
  return set;
}

int set__is_empty(struct set const *set)
{
  return (lnk__first(set->l)==llm__next(lnk__first(set->l)));
}

int set__find(struct set *set, int x)
{
  if(set__is_empty(set))
    return 0;
  struct lelement *llm = find(set->l,x);
  struct lelement *first = lnk__first(set->l);
  if((llm==NULL && first->data==x) || (llm != NULL && llm->next->data==x))
    return 1;
  return 0;
}

int set__add(struct set *set, int x)
{
  if(x < 0)
    return 0;
  struct lelement *llm=malloc(sizeof(struct lelement));
  llm->data = x;
  struct lelement *before = find(set->l,x);
  if(before==NULL)
    lnk__add_head(set->l,llm);
  else
    lnk__add_after(llm,before);
  return 1;
}

int set__remove(struct set *set, int x)
{
  if(!set__find(set,x))
    return 0;
  struct lelement *before = find(set->l,x);
  struct lelement *tmp;
  if(before==NULL)
    {
      tmp = lnk__first(set->l);
      lnk__remove_head(set->l);
    }
  else
    {
      tmp = llm__next(before);
      lnk__remove_after(before);
    }
  free(tmp);
  return 1;
}

int set__size(struct set *set)
{
  int i;
  struct lelement *current = set->l->head;
  for(i=0; !llm__is_end_mark(current); i++)
    current = llm__next(current);
  return i;
}

void set__free(struct set *set)
{
  if(set->l != NULL)
    free(set->l);
  set->l=NULL;
  if(set != NULL)
    free(set);
}
