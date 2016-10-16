#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
  char name[256];
  char artist[256];
  struct node *next;
} node;


char print_list(struct node* n){
  if(n){
    printf("Name: %s\nArtist: %s\n\n", n->name, n->artist);
    return print_list(n->next);
  }
  return 1;
}

struct node* insert_front(struct node* front, char* name, char* artist){
  struct node* n = (struct node*)malloc(sizeof(struct node));
  strcpy(n->name, name);
  strcpy(n->artist, artist);
  n->next=front;
  return n;
}

struct node* insert(struct node* front, char* name, char* artist){
  node* i = front;
  while((i -> next) && *(i->next->name)<*name){
    i=i->next;
  }
  i->next=insert_front(i->next, name, artist);
  return front;
}

struct node* findSong(struct node* front, char* name){
  while(front && strcmp(front->name, name)){
    front=front->next;
  }
  if(front){
    return front;
  }
  return 0;
}

struct node* findArtist(struct node* front, char* artist){
  while(front && strcmp(front->artist, artist)){
    front=front->next;
  }
  if(front){
    return front;
  }
  return 0;
}

int main(){
  node* s1 = 0;
  s1=insert_front(s1, "elysong", "elyname");
  s1=insert_front(s1, "alysong2", "elyname2");
  s1=insert(s1, "blysong2", "elyname3");
  s1=insert(s1, "zlysong2", "elyname4");
  s1=insert(s1, "clysong2", "elyname5");
  print_list(s1);
  printf("findSong(s1,blysong2)->name: %s\n\n",findSong(s1,"blysong2")->name);
  printf("findSong(s1,elyname4)->name: %s\n\n",findArtist(s1,"elyname4")->name);
  return 0;
}
