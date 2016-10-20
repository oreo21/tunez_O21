#ifndef LINK_LIST_H
#define LINK_LIST_H

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


void print_artist(song_node *start, char *a){}

song_node* insert_front(song_node *list, char *n, char *a){
  song_node *newNode = (song_node *)malloc(sizeof(song_node));
  strcpy(newNode -> name, n);
  strcpy(newNode -> artist, a);
  newNode -> next = list;
  return newNode;
}

song_node* insert_order(song_node *list, char *n, char *a){
  song_node *newNode = (song_node *)malloc(sizeof(song_node));
  int foundLoc = 0;
}

song_node* free_list(song_node* list){}

song_node* find_song(song_node *list, char *s){
}

song_node* find_artist(song_node *list, char *a){
}

void remove_node(song_node *list, char *a, char *s){
}

int main(){
  return 0;
}

#endif



