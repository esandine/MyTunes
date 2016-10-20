#include <stdio.h>
#include <stdlib.h>
#include "Playlist.h"

node* add_song(char* name, char* artist){
  return insert(Playlist+*name-97, name, artist);
}
char print_letter(char letter){
  return print_list(Playlist+letter-97);
}
