#include <stdio.h>

bool TestLongPrime(long int suspect) {
  if(suspect < 2)
    return false;

  for(long int i = 2; i < suspect; i++)
    if(suspect % i == 0)
      return false;

  return true;
}

long int FindNextPrime() {
  static long int curPrime = 1;
 
  curPrime++;
  while(TestLongPrime(curPrime) == false) {
    curPrime += 1;
  }

  return curPrime; 
}

#define FACTOR_NUM 600851475143

int main(int argc, char *argv[]) {
  long int largestFactor = 1;
  long int acc = 1;
  long int temp;

  while((temp = FindNextPrime()) < FACTOR_NUM) {
    if(FACTOR_NUM % temp == 0) {
      printf("New factor: %ld\n", temp);
      largestFactor = temp;
      acc *= temp;
      if(acc == FACTOR_NUM)
        break;
    }
  }
  
  printf("Largest factor of %ld is %ld\n", FACTOR_NUM, largestFactor);

  return 0;
}
