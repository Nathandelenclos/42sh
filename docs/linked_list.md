# Linked list
***
## Structure
```c
struct list_s {
    void *data;
    struct list_s *next;
};
```
***
## Functions
```c
int put_in_list(node **list, void *data);
```
Add node at start of list.
```c
int free_list(node *head, void (*screen)(void *data));
```
Free all element of the list with pointer of function for free node.
```c
void show_list(node *list);
```
// _deprecated_
```c
void delete_in_list(node **list, void *data);
```
Delete specific element in the list
```c
int len_list(node *list);
```
Count number of element in the list.
```c
void insert_in_list(node *previous, void *data);
```
Insert in list before the node in params.
```c
void delete_first(node **head);
```
Delete first element in list.
```c
void reverse_list(node **head_ref);
```
Reverse order of list.
```c
int put_in_end(node **list, void *data);
```
Add element at the end of the list.
```c
void *my_malloc(void *size, int opt);
```
Malloc `size` and add at the list of pointer for simplify free.
```c
void my_free(void *ptr);
```
// _deprecated_
```c
node *search_in_list(node *list, void *ptr);
```
Search element in list with data.