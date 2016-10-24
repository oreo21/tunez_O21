#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked_list.h"
#include "library.h"

int main(){
	song_node *table[26] = {};
	addSong(table, "u2", "with or without you");
	addSong(table, "u2", "mysterious ways");
	addSong(table, "u2", "sunday bloody sunday");
	addSong(table, "crowded house", "don't dream it's over");
	addSong(table, "crowded house", "pineapple head");
	addSong(table, "cannonball adderly", "autumn leaves");
	addSong(table, "cannonball adderly", "bangoon");
	addSong(table, "cars, the", "just what I needed");
	addSong(table, "tame impala", "elephant");
	addSong(table, "talk talk", "it's my life");
	addSong(table, "two door cinema club", "what you know");
	printf("\n\n");
	printLibrary(table);
	printf("\n\n");
	printLetter(table, "u");
	printLetter(table, "c");
	printLetter(table, "t");
	print("\n\n");
	shuffle(table);
	print("\n\n");
	findSong(table, "elephant");
	findSong(table, "giraffe");
	print("\n\n");
	printArtist(table, "u2");
	printAritst(table, "talk talk");
	print("\n\n");
	deleteAll(table);
	return 0;
}