song_node *table[26];

void addSong(song_node *[], char *n, char *a);
void printLibrary(song_node *[]);
void printLetter(song_node *[], char *L);
void printArtist(song_node *[], char *a);
void findArtist(song_node *[], char *a);
void findSong(song_node *[], char *s);
void shuffle(song_node *[]);
void deleteSong(song_node *[], char *s);
void deleteAll(song_node *[]);
