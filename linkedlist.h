struct node {char name[100]; char artist[100]; struct node *next;};
void print_list(struct node *list);
void find_node(struct node *list, char art);
void find_song(struct node *list, char song, char art);
struct node * get_random(struct node * list);
struct node * insert_front(struct node *list, char song, char art);
struct node * insert_back(struct node *list, char song, char art);
struct node * insert_order(struct node *list, char song, char art);
struct node * remove_node(struct node *list, char song, char art);
struct node * free_list(struct node *list);
