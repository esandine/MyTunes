#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  srand(time(NULL));
  int i = rand();
  printf("i: %d\n", i);
}
