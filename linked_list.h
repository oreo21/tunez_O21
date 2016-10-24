typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

void print_list(song_node *list);
song_node* insert_front(song_node *list, char *a, char *s);
song_node* insert_order(song_node *list, char *a, char *s);
song_node* find_song(song_node *list, char *s);
song_node* find_artist(song_node *list, char *a);
song_node* find_random(song_node* list);
song_node* remove_node(song_node *list, char *a, char *s);
void free_list(song_node* list);
