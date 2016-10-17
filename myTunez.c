#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song_node{
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

 
void print_list(struct song_node *start){
  printf("%s - %s,  ", start -> artist, start -> name);
  if (start -> next != 0) print_list(start -> next);
  else printf("(nil)\n");
}

void insert_front(song_node *list, char *n, char *a){
  song_node *newNode = (song_node *)malloc(sizeof(song_node));
  strcpy(newNode -> name, n);
  strcpy(newNode -> artist, a);
  newNode -> next = list;
}

song_node* insert_order(song_node *list, char *n, char *a){
  song_node *newNode = (song_node *)malloc(sizeof(song_node));
  int foundLoc = 0;
}

song_node* find_song(song_node *list, char *s){
}

void find_artist(song_node *list, char *a){
}

void remove_node(song_node *list){
}

int main(){
  return 0;
}





