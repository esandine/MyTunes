#include <stdio.h>
#include <stdlib.h>
#include "Playlist.h"

char delete_playlist(){
  int i;
  for(i=0;i<26;i++){
    Playlist[i].next=0;
    printf("TEST\n");
    Nums[i]=0;
  }

  return 0;
}
node* add_song(char* name, char* artist){
  Nums[*name-97]+=1;
  total++;
  node* n =insert((Playlist+*name-97)->next, name, artist);
  return n;
}
node* find_song(char* name){
  return findSong((Playlist+*name-97)->next, name);
}
node* find_artist(char* artist){
  char i;
  node* n;
  while(i<26){
    n = findArtist((Playlist+i)->next, artist);
    if(n){
      return n;
    }
    i++;
  }
  return 0;
}
char print_letter(char letter){
  printf("Printing: %c\n", letter);
  return print_list((Playlist+letter-97)->next);
}
char print_artist(char* artist){
  int i;
  node* n;
  printf("Artist: %s\n\n",artist);
  for(i=0; i<26; i++){
    n = findArtist((Playlist+i)->next, artist);
    while(n){
      print_node(n);
      n=findArtist(n->next, artist);
    }
  }
  return 1;
}
char printNums(){
  int i;
  for(i=0;i<26;i++){
    printf("%c: %d\n",i+97,Nums[i]);
  }
  return 0;
}
char shuffle(char songs){
  while(songs){
    int letter = rand()%total;
    int i=0;
    while(letter>Nums[i]){//Gets letter after weighting each letter to songs in it
      letter-=Nums[i];
      i++;
    }
    printf("i: %d\n", i);
    print_node(random_node((Playlist+i)->next));
    songs--;
  }
  return 0;
}


