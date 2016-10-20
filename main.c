#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Song.h"
#include "Playlist.h"

int main(){
  srand(time(0));
  node* s1 = 0;
  s1=insert_front(s1, "elysong", "elyname");
  s1=insert_front(s1, "alysong2", "elyname2");
  s1=insert(s1, "blysong2", "elyname3");
  s1=insert(s1, "zlysong2", "elyname4");
  s1=insert(s1, "clysong2", "elyname5");
  print_list(s1);
  printf("findSong(s1,blysong2)->name: %s\n\n",findSong(s1,"blysong2")->name);
  printf("(s1,elyname4)->name: %s\n\n",findArtist(s1,"elyname4")->name);
  printf("len(s1): %d\n",len(s1));
  printf("random_node(s1): \n");
  print_node(random_node(s1));
  printf("random_node(s1): \n");
  print_node(random_node(s1));
  printf("random_node(s1): \n");
  print_node(random_node(s1));
  remove_node(s1, findSong(s1, "blysong2"));
  printf("remove_node(s1, findSong(s1, blysong2))\n");
  print_list(s1);
  printf("\n\n==================Playlist Testing========================\n\n");
  add_song("elysong", "elyartist");
  print_letter('e');
  return 0;
}
