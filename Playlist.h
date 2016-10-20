#ifndef PLAYLIST
#include "Song.h"
#define PLAYLIST
node Playlist[26]
char add_song(char* name, char* artist);
node* find_song(char* name);
node* find_song(char* artist);
char print_letter(char letter);
char print_artist(char* artist);
char shuffle();
char delete(char* name);
char delete();
#endif
