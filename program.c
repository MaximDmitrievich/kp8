#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"

/**
	value = complex
	list = circle, <->
	delete last k elements

	func_spec:
	create
	empty
	length
	first
	last
	next
	prev
	insert
	delete
	destroy
	delete last k elements
**/

int main(void)
{
	double a = 0.0;
	double b = 0.0;
	int k = 0;
	List *list = list_create();
	Iterator iterator = iterator_init(list);
	printf("===== \n\n ++func_spec:++\n\n create - default\n\n empty - e\n\n length - l\n\n first - 1\n\n last - 0\n\n next - n\n\n prev - p\n\n insert - i\n\n get iterator - g\n\n print list - w\n\n delete - d\n\n destroy - q\n\n delete last k elements - k\n\n =====\n\n");
	while(true) {
		char insert = 0;
		scanf("%c", &insert);
		switch (insert) {
			case 'e':
				printf(list_is_empty(list) ? "Yes\n" : "No\n");
				break;
			case 'l':
				printf("%d\n", iterator_length_of_list(&iterator));
				break;
			case '1':
				iterator_null(&iterator);
				get_iterator(&iterator);
				break;
			case '0':
				iterator_last(&iterator);
				get_iterator(&iterator);
				break;
			case 'n':
				iterator_next(&iterator);
				get_iterator(&iterator);
				break;
			case 'p':
				iterator_prev(&iterator);
				get_iterator(&iterator);
				break;
			case 'i':
				scanf("%lf%lf", &a, &b);
				list_insert(&iterator, a, b);
				break;
			case 'g':
				get_iterator(&iterator);
			case 'w':
				list_print(&iterator);
			case 'd':
				list_node_delete(&iterator);
				break;
			case 'q':
				list_destroy(&iterator);
				exit(0);
			case 'k':
				scanf("%d", &k);
				delete_last_k_elements(&iterator, k);
				break;
			default:
				printf("Insert command\n");
		}
	}
	return 0;
}