#include <stdio.h>

#define NUM_NUMBERS 100

int main(int argc, char *argv[]) {
  
  unsigned long squaresAcc = 0;
  unsigned long sumAcc = 0;

  for(int i = 0; i <= NUM_NUMBERS; i++){
    sumAcc += i;
    squaresAcc += i*i;
  }

  printf("%d sum:%ld squares: %ld square of sum: %ld\n", NUM_NUMBERS, sumAcc, squaresAcc, sumAcc * sumAcc);

  unsigned long result = sumAcc * sumAcc - squaresAcc;
  printf("%d: result is %ld\n", NUM_NUMBERS, result);

  return 0;
}
