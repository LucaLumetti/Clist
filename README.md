## Documentation
### Types
Use `#define CLIST_TYPE float` before including clist.h to change the type of clist elements

Other definitions:
`typedef CLIST_TYPE type;

struct list_el {
  type value;
  struct list_el* next;
};

typedef struct list_el item;
typedef struct list_el* list;`

### Primitive Functions
`list emptylist()` return an empty list (list->next = NULL)
`bool empty(list l)` return true if `l` is an empty list, return false instead
`type head(list l)` return the value of the first list item
`list tail(list l)` return the `item*` to the second element of the list `l`
`list cons(type d, list l)` add the item `d` as first `item` of the list `l`
`void destroy(list l)` free() the list

### Non-primitive Functions
`list insert(type d, unsigned p, list l)` add the element `d` in the position `p` of the list `l` and return the modified list `l`
`list delete(unsigned p, list l)` delete the element in the position `p` of the
list `l` and return the modified list
`void showlist(list l)` print the list on stdout with fancy []
`unsigned length(list l)` return the length of the list
`unsigned find(type d, list l)` return the position of the first occurrence of the element with value `d` in the list `l`
`list sublist(unsigned start, unsigned end, list l)` create a new listmade with element from the position `start` to the position `end` of the list `l`
`list copy(list l)` return a copy of the list `l`
_Others TODO__

