song_node *table[26];

void addSong(song_node *[], char *a, char *s);
void printLibrary(song_node *[]);
void printLetter(song_node *[], char *L);
void printArtist(song_node *[], char *a);
song_node* findArtist(song_node *[], char *a);
song_node* findSong(song_node *[], char *s);
void shuffle(song_node *[]);
void deleteSong(song_node *[], char *s);
void deleteAll(song_node *[]);
