#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
#include "library.h"

void addSong(song_node *[], char *s, char *a){
	int i = artist[0] -65;
	table[i] = insert_order(i, a, s);
	printf("added song %s by %s to library\n", a, s);
}

void printLibrary(song_node *table[]){
	printf("printing entire library...\n");
	int i;
	for (i = 0; i < 26; i++){
		if (table[i] != 0){
			printf("printing letter %c...\n", i + 65);
			print_list(table[i]);
		}
	}
}

void printLetter(song_node* table[], char *L){
	printf("printing letter %c...\n", L)
	int i = 65 - L;
	if (tables[i] == 0) printf("no songs found\n");
	else print_list(tables[i]);
}

void printArtist(song_node*, char *a){
	printf("printing artist %c...\n", a);
	int i;
	for (i = 0; i < 26; i++){
		song_node *foundNode = findArtist(tables[i], artist);
		if (foundNode != 0){
			while (found -> artist && strcmp(found -> artist, artist) == 0){
				printf("%s - %s   ", found -> artist, found -> name);
				found = found -> next;
			}
			printf("\n");
		}
	}
}

void findArtist(song_node *[], char *a){
	printf("looking for artist %s...\n", a);
	int i;
	for (i = 0; i < 26; i++){
		song_node *foundNode = findArtist(table[i], artist);
		if (foundNode != 0){	
			printf("%s - %s   ", found -> artist, found -> name);
			return;
		}
	}   
    printf("artist not found.\n");
}