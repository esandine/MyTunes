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
  s1=remove_node(s1, findSong(s1, "alysong2"));
  printf("remove_node(s1, findSong(s1, alysong2))\n");
  print_list(s1);
  s1=remove_list(s1);
  printf("Should be nothing:");
  print_list(s1);
  printf("\n\n==================Playlist Testing========================\n\n");
  delete_playlist();
  add_song("elysong", "elyartist");
  printf("test\n");
  print_letter('e');
  add_song("elysong2","elyartist2");
  add_song("elysong3","elyartist2");
  add_song("alysong4","elyartist2");
  print_node(find_song("elysong2"));
  print_node(find_artist("elyartist2"));
  printf("Find artist:\n");
  print_artist("elyartist2");
  printf("Shufflin'/n");
  shuffle(10);
  delete("elysong2");
  print_letter('e');
  delete_playlist();
  print_letter('e');
  return 0;
}
