## Documentation
### Definition

clist.h contains a big macro called INIT_LIST that requires 5 params:
NAME, TYPE, CMPFN, COPYFN, PRINTFN
#### NAME
NAME Is the name that will be used to name list's functions and the struct, e.g.:
If NAME is "float"
`struct list_float`, `list_float_new()`, ...

#### TYPE
TYPE is the type of the value inside the list

#### CMPFN
CMPFN is the function used to compare 2 node of the list.
It should take 2 arguments of type const void\* and it return -1/0/+1 if the first values is smaller/equal/greater than the second
values

#### COPYFN
COPYFN is the functions used to copy a value of type TYPE
It should take 1 arguments of type TYPE and it return a copy of the
argument

#### PRINTFN
PRINTFN is the function used to print a single node of the list. It
should take 1 arguments of type TYPE and it returns void

### Primitive Functions
`list emptylist()` return an empty list (list->next = NULL)

`bool empty(list l)` return true if `l` is an empty list, return false instead

`type head(list l)` return the value of the first list item

`list tail(list l)` return the `item*` to the second element of the list `l`

`list cons(type d, list l)` add the item `d` as first `item` of the list `l`

`void destroy(list l)` free() the list

### Non-primitive Functions

`list insert(type d, unsigned p, list l)` add the element `d` in the position `p` of the list `l` and return the modified list `l`

`list delete(unsigned p, list l)` delete the element in the position `p` of the list `l` and return the modified list

`void showlist(list l)` print the list on stdout with fancy []

`unsigned length(list l)` return the length of the list

`unsigned find(type d, list l)` return the position of the first occurrence of the element with value `d` in the list `l`

`list sublist(unsigned start, unsigned end, list l)` create a new listmade with element from the position `start` to the position `end` of the list `l`

`list copy(list l)` return a copy of the list `l`

_Others TODO__

