#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
  char name[256];
  char artist[256];
  struct node *next;
} node;

char print_node(struct node* n){
    printf("Name: %s\nArtist: %s\n\n", n->name, n->artist);
    return 1;
}
char print_list(struct node* n){
  if(n){
    print_node(n);
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

int len(node* front){
  int i = 0;
  while(front){
    i++;
    front=front->next;
  }
  return i;
}

struct node* random_node(node* front){
  int i = rand()%len(front);
  while(i){
    front=front->next;
    i--;
  }
  return front;
}

char remove_node(node* front, node* rem){
  if(front==rem){
    front=front->next;
    free(rem);
  }else{
    while(!(front->next==rem)){
      front=front->next;
    }
    front->next=rem->next;
    free(rem);
  }
  return 1;
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
  

  
  return 0;
}
