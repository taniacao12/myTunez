#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include "library.h"

int main() {
	struct node *list;
	list = insert_order(list, "Flower Road", "Big Bang");
	list = insert_order(list, "Love Scenario", "iKON");
	list = insert_order(list, "Bang Bang Bang", "Big Bang");
	list = insert_order(list, "Forever Young", "BlackPink");
	list = insert_order(list, "Like The Seasons", "EXID");
	list = insert_order(list, "Stay", "BlackPink");
	
	printf("LINKED LIST TESTS \n");
	
	printf("====================================\n\nTesting print_list:\n");
	print_list(list);

	printf("====================================\n\nTesting print_node:\n");
	print_node(list);

	printf("====================================\n\nTesting find_song:\n");
	print_list(find_song(list, "Love Scenario", "iKON"));
	print_list(find_song(list, "My Type", "iKON"));

	printf("====================================\n\nTesting find_artist:\n");
	print_list(find_artist(list, "EXID"));
	print_list(find_artist(list, "KARD"));

	printf("====================================\n\nTesting get_random:\n");
	print_node(get_random(list));
	print_node(get_random(list));

	printf("====================================\n\nTesting remove_node:\n");
	print_list(list = remove_node(list, "Bang Bang Bang", "Big Bang"));
	print_list(list = remove_node(list, "Hola Hola", "KARD"));

	printf("====================================\n\nTesting free_list:\n");
	free_list(list);

	printf("\n====================================\n\nMUSIC LIBRARY TESTS\n\n");
	
	add("flower road", "big bang");
	add("love scenario", "ikon");
	add("bang bang bang", "big bang");
	add("forever young", "blackpink");
	add("like the seasons", "exid");
	add("stay", "blackpink");

	printf("====================================\n\nTesting print_library:\n");
	print_library();

	printf("====================================\n\nTesting print_letter:\n");
	print_letter('b');
	print_letter('e');

	printf("====================================\n\nTesting find_tune:\n");
	print_node(find_tune("love scenario", "ikon"));
	//print_node(find_tune("my type", "ikon"));

	printf("====================================\n\nTesting find_musician:\n");
	print_node(find_musician("exid"));
	//print_node(find_musician("kard"));

	printf("====================================\n\nTesting remove_song:\n");
	delete("bang bang bang", "big bang");
	delete("hola hola", "kard");

	printf("====================================\n\nTesting clear_library:\n");
	clear_library();

	printf("====================================\n\nTesting print_artist:\n");
	print_artist("exid");
	print_artist("kard");

	printf("====================================\n\nTesting shuffle:\n");
	shuffle();

	return 0;
}
