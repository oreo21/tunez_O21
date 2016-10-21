#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"


void print_list(struct song_node *list){
  while(list != 0){
  	printf("%s - %s    ", list -> artist, list -> name);
  	list = list -> next;
  }
  printf("\n");
}

song_node* insert_front(song_node *list, char *s, char *a){
  song_node *newNode = (song_node *)malloc(sizeof(song_node));
  strcpy(newNode -> name, s);
  strcpy(newNode -> artist, a);
  newNode -> next = list;
  return newNode;
}

song_node* insert_order(song_node *list, char *a, char *s){
  song_node *newNode = (song_node *)malloc(sizeof(song_node));
  strcpy(newNode -> name, s);
  strcpy(newNode -> artist, a);
  if (list == 0) return newNode;
  char *newA = newNode -> artist;
  char *newN = newNode -> name;
  char *listA = list -> artist;
  char *listN = list -> name;
  if (!strcmp(newA, listA) && strcmp(newN, listN) < 0){
  	newNode -> next = list;
  	return newNode;
  }
  while (list -> next){
  	newA = newNode -> artist;
  	newN = newNode -> name;
  	listA = list -> artist;
  	listN = list -> name;
  	if (strcmp(newA, listA) == 0 && strcmp(newN, listN) < 0) break; //same artist, 
  	if (strcmp(newA, listA) < 0) break;
  	list = list -> next;
  }
  newNode -> next = list -> next;
  list -> next = newNode;
  return newNode;
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

song_node* find_random(song_node* list){
	song_node *curr = list;
	int len = 0;
	while (curr != 0){
		len++;
		curr = curr -> next;
	}
	int r = rand() % (len);
	while (r){
		list = list -> next;
		r--;
	}
	return list;
}

song_node* remove_node(song_node *list, char *s){
	song_node *curr = list;
	if (!strcmp(s, list -> name)){
		list = list -> next;
		free(curr);
		return list;
	}
	song_node *ret = list;
	while (list -> next){
		if (!strcmp(s, list -> next -> name)){
			curr = list -> next;
			list -> next = list -> next -> next;
			free(curr);
			break;
		}
		list = list -> next;
	}
	return ret;
}

song_node* free_list(song_node* list){
	song_node *curr;
	while (list){
		curr = list -> next;
		free (list);
		list = curr;
	}
	return list;
}

void main(){
	song_node *node1 = (song_node *)malloc(sizeof(song_node));
	song_node *node2 = (song_node *)malloc(sizeof(song_node));
	song_node *node3 = (song_node *)malloc(sizeof(song_node));
	strcpy(node1 -> artist, "Queen");
	strcpy(node1 -> name, "Bohemian Rhapsody");
	strcpy(node2 -> artist, "U2");
	strcpy(node2 -> name, "With or Without You");
	insert_order(node1, "U2", "With");
	print_list(node1);
}
