#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linkedlist.h"

// print current node
void print_node (struct node *list) {
	printf("| %s: %s ", list->artist, list->name);
	printf("\n");
}

// print the entire list
void print_list (struct node *list) {
  while (list) {
	print_node(list);
    list = list->next;
  }
}

// find and return a pointer to the first song of an artist based on artist name
struct node * find_artist(struct node *list, char *art) {
  	printf("looking for [%s]\n", art);
	while (list) {
		if (strcmp(list->artist, art) == 0) {
		  	printf("artist found\n");
			return list;
		}
    	list = list->next;
  	}
  	printf("artist not found\n");
	return NULL;
}

// find and return a pointer to a node based on artist and song name
struct node * find_song(struct node *list, char *song, char *art) {
  	printf("looking for [%s: %s]\n", art, song);
  	while (list) {
    	if (strcmp(list->artist, art) == 0 && strcmp(list->name, song) == 0) {
		  	printf("song found\n");
			return list;
		}
      	list = list->next;
  	}
	printf("song not found\n");
	return NULL;
}

// return the length of the list
int get_length (struct node *list) {
	int length = 0;
	while (list) {
		list = list->next;
		length++;
	}
	return length; 
}

// return a pointer to random element in the list
struct node * get_random (struct node *list) {
	if (list) {
		int len = get_length(list);
		int num = rand() % len;
		while (num) {
   			list = list->next;
   		 	num--;
		}
		return list;
	}
	return NULL;
}

// insert node at the front
struct node * insert_front (struct node *list, char *song, char *art) {
  struct node *new = malloc(sizeof(struct node));
  strcpy(new->name, song);
  strcpy(new->artist, art);
  new->next = list;
  return new;
}

// insert nodes in order (alphabetical by Artist then by Song)
struct node * insert_order (struct node *list, char *song, char *art) {
	if (list) {
		struct node *new = malloc(sizeof(struct node));
	 	strcpy(new->name, song);
  		strcpy(new->artist, art);
		if (list->next) {
			struct node *head = list;
			struct node *next = list->next;
			if (strcmp(head->artist, art) == 0 && strcmp(head->name, song) > 0)
				return insert_front(list, song, art);
			while (strcmp(next->artist, art) < 0) {
				head = head->next;
				next = head->next;
			}
			if (strcmp(next->artist, art) > 0) {
				next = insert_front(next, song, art);
				head->next = next;
				return list;
			}
			else if (strcmp(next->artist, art) == 0) {
				while (next && strcmp(next->artist, art) == 0 && strcmp(next->name, song) < 0) {
					head = head->next;
					next = head->next;
				}
				next = insert_front(next, song, art);
				head->next = next;
				return list;
			}
		}
		list->next = new;
		return list;
	}
	return insert_front(list, song, art);
}

// remove a single specified node from the list
struct node * remove_node (struct node *list, char *song, char *art) {
  	printf("removing [%s: %s]\n", art, song);
  	struct node *head = list;
	if (list && strcmp(list->artist, art) == 0 && strcmp(list->name, song) == 0) {
		list = list->next;
		free(head);
		return list;
	}
	struct node *prev= list;
	struct node *temp= list;
	while (temp) {
    	if (strcmp(temp->artist, art) == 0 && strcmp(temp->name, song) == 0) {
			if (temp) {
				if (!temp->next) {
					prev->next = NULL;
					free(temp);
					temp = NULL;
				}
				prev->next = temp->next;
				return list;
			}
		}
		prev = temp;
		temp = temp->next;
  	}
	printf("[%s: %s] not found\n", art, song);
	return list;
}

// free the entire list
struct node * free_list (struct node *list) {
	struct node *next;
  	while (list) {
		printf("freeing node: %s - %s \n", list->artist, list->name);	
  	  	next = list->next;
   		free(list);
    	list = next;
  	}
	printf("list after free_list:\n");
	return NULL;
}
