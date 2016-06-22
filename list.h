#ifndef _LIST_H
#define _LIST_H
#include <stdbool.h>


typedef struct node_ Node;
typedef struct list_ List;
typedef struct iterator_{
	List *list;
	size_t index;
	size_t elements;
} Iterator;


List *list_create();
Iterator iterator_init(List *list);
void get_iterator(Iterator *iterator);
void iterator_next(Iterator *iterator);
void iterator_prev(Iterator *iterator);
size_t iterator_next_index(Iterator *iterator);
size_t iterator_prev_index(Iterator *iterator);
void iterator_null(Iterator *iterator);
void iterator_last(Iterator *iterator);
bool list_is_empty(Iterator *iterator);
void list_insert(Iterator *iterator, double a, double b);
size_t iterator_length_of_list(Iterator *iterator);
void list_print(Iterator *iterator);
void list_node_delete(Iterator *iterator);
void list_destroy(Iterator *iterator);
void delete_last_k_elements(Iterator *iterator, size_t k);


#endif