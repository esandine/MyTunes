#ifndef SONG_C
#define SONG_C
typedef struct node{
  char name[256];
  char artist[256];
  struct node *next;
} node;
char print_node(node* n);
char print_list(node* n);
node* insert_front(node* front, char* name, char* artist);
node* insert(node* front, char* name, char* artist);
node* findSong(node* front, char* name);
node* findArtist(node* front, char* artist);
int len(node* front);
node* random_node(node* front);
node* remove_node(node* front, node* rem);
node* remove_list(node* front);
#endif

