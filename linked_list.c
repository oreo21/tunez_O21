#include <stdlib.h>
#include <stdio.h>

typedef struct song_node{
  name char[256];
  artist char[256];
  struct song_node *next;
} song_node;

void print_list(struct song_node *start){
  printf("%s - %s,  ", start -> artist, start -> name);
  if (start -> next != 0) print_list(start -> next);
  else printf("(nil)\n");
}

song_node* insert_front(song_node *list, char *n, char *a){
  song_node *newNode = (song_node *)malloc(sizeof(song_node));
  strcpy(newNode -> name, n);
  strcpy(newNode -> artist, a);
  newNode -> next = list;
  return newNode;
}

song_node* insert_order(song_node *list, char *n, char *a){
  song_node *curr = list;
  int foundPos = 0; //0 = start, 1 = artist found, 2 = song found
  while (foundPos){
    if (strcmp(n, curr -> artist) < 0)
    	foundPos = 1;

  }
}

song_node* find_song(song_node *list, char *s){
	song_node *newNode = (song_node *)malloc(sizeof(song_node));
}

song_node* find_artist(song_node *list, char *a){
}

song_node* find_random(song_node* list){
}

void remove_node(song_node *list, char *a, char *s){
}

void free_list(song_node* list){}
