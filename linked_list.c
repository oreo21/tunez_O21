#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"

void print_list(song_node *list){
  while(list != 0){
  	printf("%s - %s ", list -> artist, list -> name);
  	list = list -> next;
  }
  printf("\n");
}

song_node* insert_front(song_node *list, char *a, char *s){
  song_node *newNode = (song_node *)malloc(sizeof(song_node));
  strcpy(newNode -> name, s);
  strcpy(newNode -> artist, a);
  newNode -> next = list;
  return newNode;
}

song_node* insert_order(song_node *list, char *a, char *s){
  song_node *temp = list;
  if (list == 0) return insert_front(NULL, a, s);
  if (list -> next == 0) {
    if (strcmp(a, list -> artist) < 0 || (strcmp(a, list -> artist) == 0 && strcmp(s, list->name) < 0))
      list = insert_front(list, a, s);
    else {
      list->next = insert_front(NULL, a, s);
    }
    return list;
  }
  if (strcmp(a, list->artist) < 0 || (strcmp(a, list->artist) == 0 && strcmp(s, list->name) < 0)) {
    return insert_front(list, a, s);
  }
  while (list->next) { 
    if (strcmp(a,list -> next -> artist) < 0 || (strcmp(a, list -> next -> artist) == 0 && strcmp(s, list -> next -> name) < 0)) {
      list -> next = insert_front(list -> next, a, s);
      return temp;
    }
    list = list -> next;
  }
  list -> next = insert_front(NULL, a, s);
  return temp;
}

song_node* find_song(song_node *list, char *s){
	while (list != 0){
		if (strcmp(s, list -> name) == 0) return list;
		list = list -> next;
	}
	return 0; 
}

song_node* find_artist(song_node *list, char *a){
	while (list != 0){
		if (strcmp(a, list -> artist) == 0) return list;
		list = list -> next;
	}
	return 0; 
}

int list_len(song_node *list){ //helper function
	int len = 0;
	while (list != 0){
		list = list -> next;
		len++;
	}
	return len;
}

song_node* find_random(song_node *list){
	srand(time(NULL));
	int pos = rand() % list_len(list);
	for (pos; pos > 0; list = list -> next, pos--);
	return list;
}

song_node* remove_node(song_node *list, char *a, char *s){
	song_node *lead = list;
	if (!strcmp(a, list -> artist) && !strcmp(s, list -> name)){ //remove first
		list = list -> next;
		free(lead);
		return list;
	}
	while (list != 0){ 
		if (!strcmp(a, list -> next -> artist) && !strcmp(s, list -> next -> name)){
			song_node *nextNode = list -> next -> next; //jump ahead to the node following the one to be removed
			free(list -> next);
			list -> next = nextNode;
			return lead;
		}
		list = list -> next;
	}
}
	
void free_list(song_node *list){
	song_node *temp = list;
	while (list != 0){
		temp = list -> next;
		free(list);
		list = temp;
	}
	free(list);
}

/*
void main(){
	song_node *node1 = (song_node *)malloc(sizeof(song_node));
	song_node *node2 = (song_node *)malloc(sizeof(song_node));
	song_node *node3 = (song_node *)malloc(sizeof(song_node));
	song_node *node4 = (song_node *)malloc(sizeof(song_node));
	song_node *node5 = (song_node *)malloc(sizeof(song_node));
	song_node *node6 = (song_node *)malloc(sizeof(song_node));	
	strcpy(node1 -> artist, "sachiko");
	strcpy(node1 -> name, "bach 1");
	strcpy(node2 -> artist, "sachiko");
	strcpy(node2 -> name, "bach 3");
	strcpy(node3 -> artist, "sergio");
	strcpy(node3 -> name, "hop");
	strcpy(node4 -> artist, "shins");
	strcpy(node4 -> name, "onion");
	strcpy(node5 -> artist, "shins");
	strcpy(node5-> name, "rifle");
	strcpy(node6 -> artist, "shins");
	strcpy(node6 -> name, "simple");
	node1 -> next = node2;
	node2 -> next = node3;
	node3 -> next = node4;
	node4 -> next = node5;
	node5 -> next = node6;
}
*/

song_node *table[26];

void addSong(song_node *table[], char *a, char *s){
	int i = a[0] - 97;
	table[i] = insert_order(table[i], a, s);
	printf("adding %s by %s\n", s, a);
}

void printLibrary(song_node *table[]){
	printf("printing entire library...\n");
	int i;
	for (i = 0; i < 26; i++){
		if (table[i] != 0){
			printf("%c list\n", i + 97);
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

//void deleteSong(song_node *[], char *s){}

void deleteAll(song_node *table[]){
	printf("deleting entire library...\n");
	int i;
	for (i = 0; i < 26; i++){
		free_list(table[i]);
	}
}
