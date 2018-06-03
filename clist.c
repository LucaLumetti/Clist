/*
 *
 * USELESS - DO NOT COMPILE
 * JUST A REFERENCE FOR ALGORITMS USED IN THE MACRO
 * CHECK clist.h
 *
 */

#include "clist.h"

list list_new(){
  return NULL;
}

bool list_isEmpty(list l){
  return l == NULL;
}

list_element list_head(list l){
  if(list_isEmpty(l)) abort();
    return l->value;
}

list list_tail(list l){
  if(list_isEmpty(l)) abort();
  return l->next;
}


bool list_destroy(list l){
  list prev;
  while(!list_isEmpty(l)){
    prev = l;
    l = l->next;
    free(prev);
  }
  free(l);
}

/* FINE FUNZIONI PRIMITIVE */

/* FUNZIONI NON PRIMITIVE */
/*
list list_insert(list_element d, unsigned p, list l){
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
  m->value = copyListElement(d);
  prev->next = m;
  return root;
}

list list_delete(unsigned p, list l){
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
*/
/*
unsigned list_length(list l){
  unsigned len = 0;
  while(!empty(l)){
    len++;
    l = l->next;
  }
  return len;
}

unsigned list_find(list_element d, list l){
  for(int i = 0; !empty(l); i++, l = l->next)
    if(l->value == d)
      return i;
  return -1;
}

list list_sublist(unsigned start, unsigned end, list l){
  if(end < start) abort();
  list m = malloc(sizeof(list_node));
  list root = m;
  for(int i = 0; !empty(l) && i <= end; i++){
    if(i < start){
      l = l->next;
      continue;
    }
    list n = malloc(sizeof(list_node));
    m->value = l->value;
    m->next = n;
    l = l->next;
    m = n;
  }
  m->next = NULL;
  return root;
}

list list_copy(list l){
  list m = malloc(sizeof(list_node));
  list root = m;
  while(!empty(l)){
    list n = malloc(sizeof(list_node));
    m->value = l->value;
    m->next = n;
    l = l->next;
    m = n;
  }
  m->next = NULL;
  return root;
}
*/
/* FINE FUNZIONI NON PRIMITIVE */
