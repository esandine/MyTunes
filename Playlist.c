#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Playlist.h"

char delete_playlist(){
  int i;
  for(i=0;i<26;i++){
    remove_list((Playlist+i)->next);
    strcpy(Playlist[i].name,"Skip");
    Playlist[i].next=NULL;
    Nums[i]=0;
  }
  total=0;
  return 0;
}

node* add_song(char* name, char* artist){
  Nums[*name-97]+=1;
  total+=1;
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
  int randnum;
  char letter;
  while(songs){
    randnum = rand()%total;
    letter = 0;
    while(randnum>Nums[letter]){
      randnum-=Nums[letter];
      letter++;
    }
    print_node(random_node(Playlist[letter].next));
    songs--;
  }
  return 0;
}
char delete(char* name){
  total--;
  Nums[*name-97]-=1;
  remove_node(&Playlist[*name-97],find_song(name));
  return 0;
}
