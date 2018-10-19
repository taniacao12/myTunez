#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linkedlist.h"
#include "library.h"

// print the entire library
void print_library() {
    int index = 0;
    while (index < 27) {
        if (table[index]) {
            printf("%d list\n", index);
            print_list(table[index]);
        }
        index++ ;
    }
}

// print all entries under a certain letter
void print_letter(char letter) {
    printf("%d list\n", letter);
    print_list(table[letter - 'a']);
}

// print all songs of a certain artist
void print_artist(char *artist) {
    struct node *temp = find_musician(artist);
    while (temp) {
        if (!strcmp(temp->artist, artist)) {
            print_node(temp);
        }
        temp = temp->next;
    }
    printf("\n");
}

// find and return a pointer to the first song of an artist based on artist name
struct node * find_musician(char *artist) {
    int num = artist[0] - 'a';
	if (num < 0 || num >= 27)
		num = 26;
	struct node *temp = table[num];
	return find_artist(temp, artist);
}

// find and return a pointer to a song based on artist and song name
struct node * find_tune(char *song, char *artist) {
    int num = artist[0] - 'a';
	if (num < 0 || num >= 27)
		num = 26;
	struct node *temp = table[num];
	return find_song(temp, song, artist);
}

// print out a series of randomly chosen songs
void shuffle() {
	struct node * songs = malloc(sizeof(struct node));
	int index = 27;
	while (index) {
		if (table[index])
			insert_order(songs, songs->name, songs->artist);
		index--;
	}
	int num = 3;
	while (num) {
		print_node(get_random(songs));
		num--;
	}
}

// add song nodes to the library
void add(char *song, char *artist) {
	int num = artist[0] - 'a';
	if (num >= 27 ||num < 0)
		num = 26;
	struct node *p = table[num];
	table[num] = insert_order(p, song, artist);
}

// delete song from the library
void delete(char *song, char *artist) {
    int num = artist[0] - 'a';
	if (num < 0 || num >= 27)
		num = 26;
	struct node *temp = table[num];
	remove_node(temp, song, artist);
}

// clear the entire library
void clear_library() {
    int index = 27;
	while (index) {
		free(table[index]);
		table[index] = NULL;
		index--;
	}
}