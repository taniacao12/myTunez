#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(){
	struct node *list;
	print_list(list);

	printf("\nadding 'a' by A to front of list...\n");
	list = insert_back(list, 'a', 'A');
	print_list(list);

	printf("\nadding 'b' by B to front of list...\n");
	list = insert_back(list, 'b', 'B');
	print_list(list);

	printf("\nadding 'c' by C to front of list...\n");
	list = insert_back(list, 'c', 'C');
	print_list(list);

	printf("\nremoving all items in linked list...\n");
	list = free_list(list);
	print_list(list);
	
	printf("\n");
	return 0;
}
