#include "clist.h"

typedef struct {
  int a;
  float b;
} foo;
/*
 * Assume we want to create a list of a the above struct
 * First we have to create the 3 functions (COPY, CMP, PRINT)
 */



/*
 * CMP function return an int and take 2 args of type const void*
 * We assume that foo a is greater that foo b if foo.a is greater
 */
int cmp_foo(const void* a, const void* b){
  foo* fooa = (foo*) a;
  foo* foob = (foo*) b;
  return (*fooa).a - (*foob).a;
}

/*
 * COPY function take an arg of type TYPE and return a TYPE
 */
foo copy_foo(foo a){
  foo b = {a.a, a.b};
  return b;
}

/*
 * PRINT function tkae an arg of type TYPE
 */
void print_foo(foo a){
  printf("A: %d, B: %f", a.a, a.b);
}

/*
 * At this point we can init our list
 * Remember no ";" at the end of a macro
 */

INIT_LIST(foo, foo, cmp_foo, copy_foo, print_foo)

/*
 * Here our list is defined, test it in main
 */

int main(){
  foo one = {1, 1.0};
  foo two = {2, 2.0};
  foo test = {5, 9.2};
  foo toDelete = {2, 2.0};

  list_foo l = list_foo_new();
  l = list_foo_cons(one, l);
  l = list_foo_cons(two, l);
  l = list_foo_cons(test, l);

  printf("La lista contiene %lu elementi\n", list_foo_length(l));
  list_foo_print(l);

  printf("Cancello un elemento\n");
  l =list_foo_delete(toDelete, l);

  list_foo_print(l);
  list_foo_destroy(l);
  return 0;
}
