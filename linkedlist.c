#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

// print the entire list
void print_list (struct node *list) {
	printf("LINKLIST: ");
	while (list) {
		printf("|%s: %s ", list->artist, list->name);
		list = list->next;
	}
}

// find and return a pointer to a node based on artist and song name
void find_node (struct node *list, char art) {
	while (list) {
		if (*(list->artist) == art) {
			printf("node found\n");
			break;
		}
		list = list->next;
	}
	printf("node not found\n");	
}

// find and return a pointer to the first song of an artist based on artist name
void find_song (struct node *list, char song, char art) {
	while (list) {
		if (*list->artist == art)
			if (*list->name == song) {
				printf("node found\n");
				break;
			}
		list = list->next;
	}
	printf("node not found\n");
}

// return a pointer to random element in the list
struct node * get_random (struct node * list) {
	int num = rand() % sizeof(list);
	int i = 0;
	while (i < num) {
		list = list->next;
		i++;
	}
	return list;
}

// insert node at the front
struct node * insert_front (struct node *list, char song, char art) {
	struct node *new;
	new = malloc(sizeof(struct node));
	*new->name = song;
	*new->artist = art;
	new->next = list;
	list = new;
	return list;
}

// insert node at the back
struct node * insert_back (struct node *list, char song, char art) {
	struct node *temp;
	temp = malloc(sizeof(struct node));
	while (list) {
		temp = insert_front(list, *list->name, *list->artist);
		list = list->next;
	}
	struct node *new;
	new = malloc(sizeof(struct node));
	*new->name = song;
	*new->artist = art;
	new->next = NULL;
	while (temp) {
		new = insert_front(temp, *temp->name, *temp->artist);
		temp = temp->next;
	}
	list = new;
	return list;
}

// insert nodes in order (alphabetical by Artist then by Song)
struct node * insert_order (struct node *list, char song, char art){
	if (!list || (strcmp(list->artist, art) > 0 && strcmp(list->name, song) > 0))
		return insert_front(list, song, art);
	struct node *next;
	next = list->next;
	//while (list && list->next && strcmp(list->artist, art) <= 0 && strcmp(list->name, song) < 0) {
	while (list && strcmp(list->artist, art) <= 0 && strcmp(list->name, song) < 0) {		list = list->next;
		next = list->next;
	}
	list = list->next;
	*list->name = song;
	*list->artist = art;
	list->next = next;
	return list;
}

// remove a single specified node from the list
struct node * remove_node (struct node *list, char song, char art){
	struct node *next;
	while (list) {
		if (*list->artist == art)
			if (*list->name == song)
				break;
		list = list->next;
	}
	next = list->next;
	free(list);
	list = next;
	return list;
}

// free the entire list
struct node * free_list (struct node *list) {
	struct node *next;
	while (list) {
    	next = list->next;
    	free(list);
    	list = next;
	}
	return list;
}