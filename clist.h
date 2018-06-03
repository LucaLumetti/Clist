#ifndef CLIST_H
#define CLIST_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
/* NON PRIMITIVE */
/*
extern list list_insert(list_element d, unsigned p, list l);
extern list list_delete(unsigned p, list l);
extern void list_print(list l);
extern unsigned list_length(list l);
extern unsigned list_find(list_element d, list l);
extern list list_sublist(unsigned start, unsigned end, list l);
extern list list_copy(list l);
*/
/* TODO */
/*
extern list list_reverse(list l);
extern list list_append(list l, list m);
extern list_element list_push(list* l);
extern list_element list_pop(list* l);
*/
/* FINE NON PRIMITIVE */

/* MACRO */
#define INIT_LIST(NAME, TYPE, COPYFN, PRINTFN) \
\
/* -- Structs and Typedef -- */\
\
struct list_##NAME##_node { \
  TYPE value; \
  struct list_##NAME##_node* next; \
}; \
\
typedef struct list_##NAME##_node list_##NAME##_node; \
typedef struct list_##NAME##_node* list_##NAME; \
\
/* function definition (useless, but helpfull for readibility)*/\
\
extern list_##NAME list_##NAME##_new(); \
extern bool list_##NAME##_isEmpty(list_##NAME l); \
extern TYPE list_##NAME##_head(list_##NAME l); \
extern list_##NAME list_##NAME##_tail(list_##NAME l); \
extern list_##NAME list_##NAME##_cons(TYPE d, list_##NAME l); \
extern void list_##NAME##_destroy(list_##NAME l); \
\
/* ---------- Functions ----------*/\
\
  /* -- list list_new() -- */ \
  list_##NAME list_##NAME##_new(){ \
    return NULL; \
  } \
\
  /* -- list list_isEmpty(list l) -- */\
  bool list_##NAME##_isEmpty(list_##NAME l){ \
    return l == NULL; \
  } \
\
  /* -- type list_head(list l) -- */\
  TYPE list_##NAME##_head(list_##NAME l){ \
    if(list_##NAME##_isEmpty(l)) abort(); \
      return l->value; \
  } \
\
  /* -- list list_tail(list l) -- */\
  list_##NAME list_##NAME##_tail(list_##NAME l){ \
    if(list_##NAME##_isEmpty(l)) abort(); \
    return l->next; \
  } \
  /* -- list list_cons(type d, list l) -- */\
  list_##NAME list_##NAME##_cons(TYPE d, list_##NAME l){ \
    list_##NAME m = malloc(sizeof(list_##NAME##_node)); \
    m->value = (COPYFN)(d); \
    m->next = l; \
    return m; \
  } \
\
  /* -- list list_destroy(list l) */\
  void list_##NAME##_destroy(list_##NAME l){ \
    list_##NAME prev; \
    while(!list_##NAME##_isEmpty(l)){ \
      prev = l; \
      l = l->next; \
      free(prev); \
    } \
    free(l); \
  } \
\
  /* -- list_print() -- */\
  void list_##NAME##_print(list_##NAME l){ \
    if(list_##NAME##_isEmpty(l)){ \
      printf("[]"); \
      return; \
    } \
    printf("[ "); \
    (PRINTFN)(l->value); \
    l = list_##NAME##_tail(l); \
    while(!list_##NAME##_isEmpty(l)){ \
      printf(", "); \
      (PRINTFN)(l->value); \
      l = l->next; \
    } \
    printf(" ]"); \
  }
#endif /* CLIST_H */
