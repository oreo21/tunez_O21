#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"
#include "library.h"

song_node *table[26];

void addSong(song_node *table[], char *s, char *a){
	int i = a[0] - 97;
	table[i] = insert_order(table[i], a, s);
	printf("added song %s by %s to library\n", a, s);
}

void printLibrary(song_node *table[]){
	printf("printing entire library...\n");
	int i;
	for (i = 0; i < 26; i++){
		if (table[i] != 0){
			printf("printing letter %c...\n", i + 97);
			print_list(table[i]);
		}
	}
}

void printLetter(song_node *table[], char *L){
	printf("printing letter %s...\n", L);
	int i = L[0] - 97;
	if (table[i] == 0) printf("no songs found\n");
	else print_list(table[i]);
}

void printArtist(song_node *table[], char *a){
	printf("looking for %s...\n", a);
	int i;
	for (i = 0; i < 26; i++){
		song_node *foundNode = find_artist(table[i], a);
		if (foundNode != 0){
			while (foundNode -> next && strcmp(foundNode -> artist, a) == 0){
				printf("%s - %s   ", foundNode -> artist, foundNode -> name);
				foundNode = foundNode -> next;
			}
			printf("\n");
			return;
		}
	}
	printf("artist not found.\n");
}

song_node* findArtist(song_node *table[], char *a){
	int i;
    for (i = 0; i < 26; i++){
		song_node *foundNode = find_artist(table[i], a);
		if (foundNode != 0) return foundNode;
	}
	return 0;
}

song_node* findSong(song_node *table[], char *s){
	printf("looking for %s\n", s);
	int i;
	for (i = 0; i < 26; i++){
		song_node *foundNode = find_song(table[i],s);
		if (foundNode != 0){
			printf("%s", s);
			return foundNode;
		}
	}
	printf("song not found");
	return 0;
}


void shuffle(song_node *table[]){
	printf("shuffling songs...\n");
	srand(time(NULL));
	int r1 = rand() % 26;
	while (table[r1] == 0) r1 = rand() % 26;
	int r2 = rand() % list_len(table[r1]);
	int r2temp = r2;
	int i;
	for (i = 0; i < 3; i++){
		song_node* list = table[r1];
		while (r2temp){
			list = list -> next;
			r2temp--;
		}
		printf("%s - %s\n", list -> artist, list -> name);
	}
}

void deleteAll(song_node *table[]){
	printf("deleting entire library...\n");
	int i;
	for (i = 0; i < 26; i++){
		free_list(table[i]);
	}
}
