#ifndef __LINK_H__
#define __LINK_H__

struct link
{
  struct lelement *head;
};

struct lelement
{
  int data;
  struct lelement *next;
};

struct link lnk__empty();
struct lelement *lnk__first(const struct link *lnk);
int llm__is_end_mark(const struct lelement *llm);
void lnk__add_head(struct link *lnk, struct lelement *llm);
struct lelement *lnk__remove_head(struct link *lnk);
struct lelement *llm__next(struct lelement *llm);
int lnk__add_after(struct lelement *toadd, struct lelement *llmbefore);
int lnk__remove_after(struct lelement *llmbefore);

#endif
