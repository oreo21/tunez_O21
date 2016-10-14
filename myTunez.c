#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song_node{
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

void print_list(struct song_node *start){
  printf("%s -> ", start->val);
  if (start -> next != 0) print_list(start -> next);
  else printf("(nil)\n");
}

struct song_node* insert_front(struct song_node *list, char n[], char a[]){
  struct song_node *newNode = (struct song_node *)malloc(sizeof(struct song_node));
  newNode -> name = n;
  newNode -> artist = a;
  return newNode;
}


