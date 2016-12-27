#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "link.h"

static struct lelement sentinel={-1,&sentinel};

struct link lnk__empty()
{
  struct link lnk;
  lnk.head = &sentinel;
  return lnk;
}

struct lelement *lnk__first(const struct link *lnk)
{
  return lnk->head;
}

int llm__is_end_mark(const struct lelement *llm)
{
  return (llm->next == llm);
}

void lnk__add_head(struct link *lnk, struct lelement *llm)
{
  struct lelement *tmp = lnk__first(lnk);
  lnk->head = llm;
  llm->next = tmp;
}

struct lelement *lnk__remove_head(struct link *lnk)
{
  if(llm__is_end_mark(lnk__first(lnk)))
    return NULL;
  struct lelement *tmp = lnk__first(lnk);
  lnk->head = llm__next(lnk__first(lnk));
  return tmp;
}

struct lelement *llm__next(struct lelement *llm)
{
  return llm->next;
}

int lnk__add_after(struct lelement *toadd, struct lelement *llmbefore)
{
  if(llm__is_end_mark(llmbefore))
    return 0;
  struct lelement *tmp = llmbefore->next;
  llmbefore->next = toadd;
  toadd->next = tmp;
  return 1;
}

int lnk__remove_after(struct lelement *llmbefore)
{
  if(llm__is_end_mark(llm__next(llmbefore)))
    return 0;
  llmbefore->next = llm__next(llm__next(llmbefore));
  return 1;
}

