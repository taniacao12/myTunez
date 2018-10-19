#ifndef LIBRARY_H
#define LIBRARY_H
    
struct node * table[27];

void print_library();
void print_letter(char letter);
void print_artist(char *artist);

struct node * songs();
struct node * find_musician(char *artist);
struct node * find_tune(char *song, char *artist);

void shuffle();

void add(char *song, char *artist);
void delete(char *song, char *artist);
void clear_library();

#endif
