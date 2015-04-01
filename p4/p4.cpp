#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_DIGITS 3

int GetNumDigits(long int num) {
  long int acc = num;
  int numDigits = 0;

  while(acc > 0) {
    acc = acc / 10;
    numDigits++;
  }

  return numDigits;
}

long LargestNumberWithDigitProduct(int numDigits) {
  long int acc = 0;

  for(int i = 0; i < numDigits; i++)
    acc += 9 * pow(10, i);

  acc *= acc;

  return acc;
}

long GetIntegerOfDigitArray(unsigned char *digitArray, int digitArray_n) {
  long acc = 0;
  
  for(int i = 0; i < digitArray_n; i++) {
    acc += digitArray[i] * pow(10, i);
  }

  return acc;
}

unsigned char *GetDigitArrayOfInteger(long num) {
  int numDigits = GetNumDigits(num);
  unsigned char *digitArray = (unsigned char*)malloc(sizeof(unsigned char) * numDigits);
  long acc = num;
  for(int i = 0; i < GetNumDigits(num); i++){
    digitArray[i] = acc % 10;
    acc = acc / 10; 
  }

  return digitArray;
}

long GetDigitArrayIntegerMirror(unsigned char *digitArray, int digitArray_n) {
  long acc = 0;

  for(int i = 0; i < digitArray_n; i++)
    acc += digitArray[i] * pow(10, i + digitArray_n);

  for(int i = digitArray_n - 1; i >= 0; i--)
    acc += digitArray[i] * pow(10, (digitArray_n - i - 1)); 

  return acc;
}

// Note: This breaks in negative numbers
void DecrementDigitArray(unsigned char *digitArray, int digitArray_n) {
  if(digitArray[0] == 0) {
    digitArray[0] = 9;
    DecrementDigitArray((unsigned char *)(digitArray + 1), digitArray_n - 1);
  }
  else {
    digitArray[0]--;
  }
}

void DigitArraySubtract(unsigned char *digitArray, int digitArray_n, int num) {
  for(int i = 0; i < num; i++)
    DecrementDigitArray(digitArray, digitArray_n);
}

#define MAX_FACTORS 200
int FindDigitFactors(long num, int numDigits) {
  int factors[MAX_FACTORS];
  int factors_n = 0;

  memset(factors, 0, sizeof(int) * factors_n);

  printf("Factors of %d: ", num);
  for(long i = 2; i < num; i++) {
    if(num % i == 0 && GetNumDigits(i) == numDigits) {
      printf("%d, ", i);
      factors[factors_n] = i;
      factors_n++;
    }
  }

  if(factors_n > 1) {
    for(int i = 0; i < factors_n; i++) {
      for(int j = 0; j < factors_n; j++) {
        if(factors[i] * factors[j] == num) {
          printf("%d * %d = %d\n", factors[i], factors[j], num);
          return -1;
        }
      }
    }
  }

  printf("\n");

  return factors_n;
}


int main(int argc, char *argcv[]){
  
  long largestProduct = LargestNumberWithDigitProduct(NUM_DIGITS);  
  int numDigits = GetNumDigits(largestProduct);
  unsigned char *digitArray = GetDigitArrayOfInteger(largestProduct);
  unsigned char *leftDigitArray = (unsigned char*)malloc(sizeof(unsigned char) * numDigits / 2);

  int leftNumDigits = numDigits/2;
  int j = numDigits/2 - 1;
  for(int i = numDigits - 1; i >= numDigits/2; i--) {
    leftDigitArray[j] = digitArray[i];
    j--;
  }

  printf("%d\n", GetIntegerOfDigitArray(digitArray, numDigits));
  printf("%d\n", GetIntegerOfDigitArray(leftDigitArray, leftNumDigits));
  printf("%d\n", GetDigitArrayIntegerMirror(leftDigitArray, leftNumDigits));
 
  while(GetDigitArrayIntegerMirror(leftDigitArray, leftNumDigits) > largestProduct)
    DecrementDigitArray(leftDigitArray, leftNumDigits); 

  //printf("%d\n", GetDigitArrayIntegerMirror(leftDigitArray, leftNumDigits));

  while(FindDigitFactors(GetDigitArrayIntegerMirror(leftDigitArray, leftNumDigits), NUM_DIGITS) != -1) {
    DecrementDigitArray(leftDigitArray, leftNumDigits);
  }

  return 0;
}
