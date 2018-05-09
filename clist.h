#ifndef CLIST_H
#define CLIST_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#ifndef CLIST_TYPE
#define CLIST_TYPE int
#endif

typedef CLIST_TYPE type;

struct list_el {
  type value;
  struct list_el* next;
};

typedef struct list_el item;
typedef struct list_el* list;

/* PRIMITIVE */
extern list emptylist();
extern bool empty(list l);
extern type head(list l);
extern list tail(list l);
extern list cons(type d, list l);
extern bool destroy(list l);
/* FINE PRIMITIVE */

/* NON PRIMITIVE */
extern list insert(type d, unsigned p, list l);
extern list delete(unsigned p, list l);
extern void showlist(list l);
extern unsigned length(list l);
extern unsigned find(type d, list l);
extern list copy(list l);
/* TODO */
extern list sublist(unsigned start, unsigned end, list l);
extern list reverse(list l);
extern list append(list l, list m);
extern type push(list* l);
extern type pop(list* l);

/* FINE NON PRIMITIVE */

#endif /* CLIST_H */
