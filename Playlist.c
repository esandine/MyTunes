#include <stdio.h>
#include <stdlib.h>
#include "Playlist.h"

/*char delete_playlist(){
  int i;
  for(i=0;i<26;i++){
    printf("TEST\n");
    Nums[i]=0;
  }

  return 0;
  }*/
node* add_song(char* name, char* artist){
  return insert((Playlist+*name-97), name, artist);
}
node* find_song(char* name){
  return findSong((Playlist+*name-97), name);
}
node* find_artist(char* artist){
  char i;
  node* n;
  while(i<26){
    n = findArtist((Playlist+i), artist);
    if(n){
      return n;
    }
    i++;
  }
  return 0;
}
char print_letter(char letter){
  printf("Printing: %c\n", letter);
  return print_list((Playlist+letter-97));
}
char print_artist(char* artist){
  int i;
  node* n;
  printf("Artist: %s\n\n",artist);
  for(i=0; i<26; i++){
    n = findArtist((Playlist+i), artist);
    while(n){
      print_node(n);
      n=findArtist(n->next, artist);
    }
  }
  return 1;
}
char shuffle(char songs){
  while(songs){
    int letter = rand()%26;//assumes roughly equal amount of songs each letter
    print_node(random_node(Playlist+letter));
    songs--;
  }
  return 0;
}


