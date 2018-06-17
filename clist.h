#ifndef CLIST_H
#define CLIST_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define INIT_LIST(NAME, TYPE, CMPFN, COPYFN, PRINTFN)                         \
                                                                              \
/* -- Structs and Typedef -- */                                               \
                                                                              \
struct list_##NAME##_node {                                                   \
  TYPE value;                                                                 \
  struct list_##NAME##_node* next;                                            \
};                                                                            \
                                                                              \
typedef struct list_##NAME##_node list_##NAME##_node;                         \
typedef struct list_##NAME##_node* list_##NAME;                               \
                                                                              \
extern list_##NAME list_##NAME##_new();                                       \
extern bool list_##NAME##_isEmpty(list_##NAME l);                             \
extern TYPE list_##NAME##_head(list_##NAME l);                                \
extern list_##NAME list_##NAME##_tail(list_##NAME l);                         \
extern list_##NAME list_##NAME##_cons(TYPE d, list_##NAME l);                 \
extern void list_##NAME##_destroy(list_##NAME l);                             \
                                                                              \
/* ---------- Functions ----------*/                                          \
                                                                              \
  /* -- list list_new() -- */                                                 \
  list_##NAME list_##NAME##_new(){                                            \
    return NULL;                                                              \
  }                                                                           \
                                                                              \
  /* -- list list_isEmpty(list l) -- */                                       \
  bool list_##NAME##_isEmpty(list_##NAME l){                                  \
    return l == NULL;                                                         \
  }                                                                           \
                                                                              \
  /* -- type list_head(list l) -- */                                          \
  TYPE list_##NAME##_head(list_##NAME l){                                     \
    if(list_##NAME##_isEmpty(l)) abort();                                     \
      return l->value;                                                        \
  }                                                                           \
                                                                              \
  /* -- list list_tail(list l) -- */                                          \
  list_##NAME list_##NAME##_tail(list_##NAME l){                              \
    if(list_##NAME##_isEmpty(l)) abort();                                     \
    return l->next;                                                           \
  }                                                                           \
                                                                              \
  /* -- list list_cons(type d, list l) -- */                                  \
  list_##NAME list_##NAME##_cons(TYPE d, list_##NAME l){                      \
    list_##NAME m = malloc(sizeof(list_##NAME##_node));                       \
    m->value = (COPYFN)(d);                                                   \
    m->next = l;                                                              \
    return m;                                                                 \
  }                                                                           \
                                                                              \
  /* -- list list_destroy(list l) */                                          \
  void list_##NAME##_destroy(list_##NAME l){                                  \
    list_##NAME prev;                                                         \
    while(!list_##NAME##_isEmpty(l)){                                         \
      prev = l;                                                               \
      l = list_##NAME##_tail(l);                                              \
      free(prev);                                                             \
    }                                                                         \
  }                                                                           \
                                                                              \
  /* -- list_print() -- */                                                    \
  void list_##NAME##_print(list_##NAME l){                                    \
    if(list_##NAME##_isEmpty(l)){                                             \
      printf("[]");                                                           \
      return;                                                                 \
    }                                                                         \
    printf("[ ");                                                             \
    (PRINTFN)(l->value);                                                      \
    l = list_##NAME##_tail(l);                                                \
    while(!list_##NAME##_isEmpty(l)){                                         \
      printf(", ");                                                           \
      (PRINTFN)(l->value);                                                    \
      l = l->next;                                                            \
    }                                                                         \
    printf(" ]");                                                             \
  }                                                                           \
                                                                              \
  size_t list_##NAME##_length(list_##NAME l){                                 \
    size_t len = 0;                                                           \
    for(len = 0; !list_##NAME##_isEmpty(l); len++){                           \
      l = list_##NAME##_tail(l);                                              \
    }                                                                         \
    return len;                                                               \
  }                                                                           \
                                                                              \
  list_##NAME list_##NAME##_delete(TYPE e, list_##NAME l){                    \
    if(list_##NAME##_isEmpty(l))                                              \
      return l;                                                               \
    list_##NAME root = l;                                                     \
    list_##NAME prec;                                                         \
                                                                              \
    TYPE f = list_##NAME##_head(l);                                           \
    if((CMPFN)(&f, &e) == 0){                                                 \
      prec = l;                                                               \
      l = list_##NAME##_tail(l);                                              \
      free(prec);                                                             \
      return l;                                                               \
    }                                                                         \
                                                                              \
    while(!list_##NAME##_isEmpty(l)){                                         \
      prec = l;                                                               \
      l = list_##NAME##_tail(l);                                              \
      if(list_##NAME##_isEmpty(l))                                            \
        return root;                                                          \
      f = list_##NAME##_head(l);                                              \
      if((CMPFN)(&f, &e) == 0){                                               \
        prec->next = list_##NAME##_tail(l);                                   \
        free(l);                                                              \
        return root;                                                          \
      }                                                                       \
    }                                                                         \
    return root;                                                              \
  }                                                                           \
                                                                              \
  list_##NAME list_##NAME##_push(TYPE e, list_##NAME l){                      \
    if(list_##NAME##_isEmpty(l)){                                             \
      return list_##NAME##_cons(e, l);                                        \
    }                                                                         \
    list_##NAME root = l;                                                     \
    list_##NAME prec;                                                         \
    while(!list_##NAME##_isEmpty(l)) {                                        \
      prec = l;                                                               \
      l = list_##NAME##_tail(l);                                              \
    }                                                                         \
    l = prec;                                                                 \
    list_##NAME m = malloc(sizeof(list_##NAME##_node));                       \
    m->value = (COPYFN)(e);                                                   \
    m->next = NULL;                                                           \
    l->next = m;                                                              \
    return root;                                                              \
  }                                                                           \
                                                                              \
  list_##NAME list_##NAME##_sort(list_##NAME l){                              \
    size_t len = list_##NAME##_length(l);                                     \
    list_##NAME root = l;                                                     \
    TYPE *arr = malloc(len*sizeof(TYPE));                                     \
    for(int i = 0; i < len; i++){                                             \
      arr[i] = (COPYFN)(list_##NAME##_head(l));                               \
      l = list_##NAME##_tail(l);                                              \
    }                                                                         \
                                                                              \
    list_##NAME##_destroy(root);                                              \
    qsort(arr, len, sizeof(TYPE), CMPFN);                                     \
                                                                              \
    list_##NAME m = list_##NAME##_new();                                      \
    for(int i = 0; i < len; i++){                                             \
      m = list_##NAME##_push(arr[i], m);                                      \
    }                                                                         \
    free(arr);                                                                \
    return m;                                                                 \
  }                                                                           \
                                                                              \
  list_##NAME list_##NAME##_reverse(list_##NAME l){                           \
    list_##NAME root = l;                                                     \
    list_##NAME m = list_##NAME##_new();                                      \
    while(!list_##NAME##_isEmpty(l)) {                                        \
      TYPE e = (COPYFN)(list_##NAME##_head(l));                               \
      m = list_##NAME##_cons(e, m);                                           \
      l = list_##NAME##_tail(l);                                              \
    }                                                                         \
    list_##NAME##_destroy(root);                                              \
    return m;                                                                 \
  }
#endif /* CLIST_H */
