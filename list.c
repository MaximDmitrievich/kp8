#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <complex.h>
#include "list.h"

typedef struct node_{
	double a;
	double b;
	size_t next;
	size_t prev;
};

typedef struct list_{
	Node *nodes;
	size_t center;
};



List *list_create()
{
	List *list = (List *) malloc(sizeof(List));
	list->nodes = NULL;
	list->center = 0;
	return list;
}

Iterator iterator_init(List *list)
{
	Iterator it;
	it.list = list;
	it.index = 0;
	it.elements = 0;
	return it;
}

void get_iterator(Iterator *iterator)
{
	printf("%d\n", iterator->index);
}

void iterator_next(Iterator *iterator)
{
	iterator->index = iterator->list->nodes[iterator->index].next;
}

void iterator_prev(Iterator *iterator)
{
	iterator->index = iterator->list->nodes[iterator->index].prev;
}

size_t iterator_next_index(Iterator *iterator)
{
	iterator_next(&iterator);
	size_t index = iterator->index;
	iterator_prev(&iterator);
	return index;
}

size_t iterator_prev_index(Iterator *iterator)
{
	iterator_prev(&iterator);
	size_t index = iterator->index;
	iterator_next(&iterator);
	return index;
}

void iterator_null(Iterator *iterator)
{
	iterator->index = iterator->list->center;
}

void iterator_last(Iterator *iterator)
{
	iterator_null(&iterator);
	iterator_prev(&iterator);
}

bool list_is_empty(Iterator *iterator)
{
	if (iterator->elements == 0) {
		return true;
	} else false;
}

void list_insert(Iterator *iterator, double a, double b)
{
	iterator->list->nodes = (Node *) realloc(iterator->list->nodes, sizeof(Node) * ++iterator->elements);
	iterator->index = iterator->elements - 1;
	iterator->list->nodes[iterator->index].next = 0;
	iterator->list->nodes[iterator->index].prev = iterator_prev_index(&iterator);
	iterator->list->nodes[iterator_prev_index(&iterator)].next = iterator->index;
	iterator->list->nodes[iterator->list->center].prev = iterator->index;
	iterator->list->nodes[iterator->index].a = a;
	iterator->list->nodes[iterator->index].b = b;
}

size_t iterator_length_of_list(Iterator *iterator)
{
	return iterator->elements;
}

void list_print(Iterator *iterator)
{
	iterator_null(&iterator);
	for (int i = 0; i < iterator->elements; ++i) {
		printf("%.2lf+(%.2lf)i\n", iterator->list->nodes[iterator->index].a, iterator->list->nodes[iterator->index].b);
		iterator_next(&iterator);
	}
}

void list_node_delete(Iterator *iterator)
{
	iterator->list->nodes[iterator_next_index(&iterator)].prev = iterator_prev_index(&iterator);
	iterator->list->nodes[iterator_prev_index(&iterator)].next = iterator_next_index(&iterator);
	iterator->elements--;
	free(iterator->list->nodes + iterator->index);
}

void list_destroy(Iterator *iterator)
{
	free(iterator->list->nodes);
	free(iterator->list);
}

void delete_last_k_elements(Iterator *iterator, size_t k)
{
	if (iterator_length_of_list(&iterator) < k) {
		printf("length of list is less, than k\n");
	} else {
		for (int i = 0; i < k; i++) {
			iterator_last(&iterator);
			list_node_delete(&iterator);
		}
	}
}