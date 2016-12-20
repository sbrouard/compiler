#ifndef __SET_H__
#define __SET_H__

int set__is_empty(struct set const *set);
int set__add(struct set *set, int value);
struct set *set__empty();
int set__remove(struct set *set, int value);
int set__find(struct set *set, int value);
int set__size(struct set *set);
void set__free(struct set *set);

#endif
