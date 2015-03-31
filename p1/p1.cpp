#include <stdio.h>
#include <list>

int main(int argv, char *argc[]) {
  long int acc = 0;

  for(int i = 0; i < 1000; i++)
    if(i % 3 == 0 || i % 5 == 0) 
      acc += i;

  printf("Acc is equivalent to %ld\n", acc); 
  

  return 0;
}
