#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
  char name[256];
  char artist[256];
  struct Song *next;
} node;

struct node* insert_front(struct node* front, char* name, char* artist){
  struct node* n = (struct node*)malloc(sizeof(struct node));
  strcpy(n->name, name);
  (*n).artist=artist;
  return n;
}

int main(){
  node *s1 = (node*)malloc(sizeof(Song));
  s1=insert_front(s1, "elysong", "elyname");
  printf("Node s1\nName: %s\nArtist: %s\n",s1->name,s1->artist);
  return 0;
}
