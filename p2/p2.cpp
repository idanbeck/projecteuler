#include <stdio.h>

int main(int argc, char *argv[]) {
  long int acc = 0;

  long int lastFib = 1;

  for(long int i = 1; i < 4000000; ){
    if(i % 2 == 0)
      acc += i;
    
    long int temp = i;
    i += lastFib;
    lastFib = temp;
  }


  printf("acc equivalent %ld\n", acc);

  return 0;
}


