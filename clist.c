#include "clist.h"

/* FUNZIONI PRIMITIVE */

list emptylist(){
  list l = malloc(sizeof(item));
  l->next = NULL;
  return l;
}

bool empty(list l){
  if(l == NULL) abort();
  return l->next == NULL;
}

type head(list l){
  if(empty(l)) abort();
  return l->value;
}

list tail(list l){
  if(empty(l)) abort();
  return l->next;
}

list cons(type d, list l){
  list m = emptylist();
  m->value = d;
  m->next = l;
  return m;
}

bool destroy(list l){
  list prev;
  while(!empty(l)){
    prev = l;
    l = l->next;
    free(prev);
  }
  free(l);
}

/* FINE FUNZIONI PRIMITIVE */

/* FUNZIONI NON PRIMITIVE */

list insert(type d, unsigned p, list l){
  if(empty(l)) abort();
  if(p == 0)
    return cons(d, l);

  list root = l;
  list m = emptylist();
  list prev;

  for(int i = 0; i < p; i++){
    if(empty(l)) break;
    prev = l;
    l = l->next;
  }

  m->next = l;
  m->value = d;
  prev->next = m;
  return root;
}

list delete(unsigned p, list l){
  if(empty(l)) abort();
  if(p == 0)
    return l->next;

  list root = l;
  list prev;

  for(int i = 0; i < p; i++){
    if(empty(l)) break;
    prev = l;
    l = l->next;
  }

  prev->next = l->next;
  free(l);
  return root;
}

void showlist(list l){
  if(empty(l)){
    printf("[]");
    return;
  }
  printf("[ %d", l->value);
  l = tail(l);
  while(!empty(l)){
    printf(", %d", l->value);
    l = l->next;
  }
  printf(" ]");
}

unsigned length(list l){
  unsigned len = 0;
  while(!empty(l)){
    len++;
    l = l->next;
  }
  return len;
}

unsigned find(type d, list l){
  for(int i = 0; !empty(l); i++, l = l->next)
    if(l->value == d)
      return i;
  return -1;
}

list sublist(unsigned start, unsigned end, list l){
  if(end < start) abort();
  list m = malloc(sizeof(item));
  list root = m;
  for(int i = 0; !empty(l) && i <= end; i++){
    if(i < start){
      l = l->next;
      continue;
    }
    list n = malloc(sizeof(item));
    m->value = l->value;
    m->next = n;
    l = l->next;
    m = n;
  }
  m->next = NULL;
  return root;
}

list copy(list l){
  list m = malloc(sizeof(item));
  list root = m;
  while(!empty(l)){
    list n = malloc(sizeof(item));
    m->value = l->value;
    m->next = n;
    l = l->next;
    m = n;
  }
  m->next = NULL;
  return root;
}
/* FINE FUNZIONI NON PRIMITIVE */
