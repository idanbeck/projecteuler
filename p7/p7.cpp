#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
  if(argc != 2) {
    printf("usage: %s <num prime>\n", argv[0]);
    return -1;
  }

  int numPrime = 0;
  int targetPrime = atoi(argv[1]);
  if(targetPrime < 1) {
    printf("error: number prime cannot be negative or zero\n");
    return -1;
  }
  else {
    printf("Finding %d prime...\n", targetPrime);
  }

  for(unsigned long i = 2; i < ULONG_MAX; i++) {
    bool fPrime = true;
    for(unsigned long j = 2; j < i; j++) {
      if(i % j == 0) {
        fPrime = false;
        break;
      }
    }

    if(fPrime == true) {
      numPrime++;
      printf("%3d%% complete\r", (int)(((float)numPrime/(float)(targetPrime)) * 100.0f));
    
      if(numPrime == targetPrime) {
        printf("%d prime is %ld\n", numPrime, i);
        return 0;
      }
    }
  }

  return 0;
}
