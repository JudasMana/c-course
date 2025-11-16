#include <stdio.h>

int rightrot(int x, int n);

int main(){
  int x = 0263; // 10 110 011
  int n = 24; // -> 00 111 011 = 73

  printf("\nCon x = %o e n = %d, ottengo: \n%o\n", x, n, rightrot(x, n));
  return 0;
}

int rightrot(int x, int n){
  int temp = x;
  int bitSignificativi = 0;
  while(temp != 0){
    temp = temp >> 1;
    ++bitSignificativi;
  }
  if (bitSignificativi == 0) return x;

  int rightShift = n % bitSignificativi;
  if (rightShift == 0) return x;

  int leftShift = bitSignificativi - rightShift;
  return ((x & ~(~0 << leftShift)) << (leftShift)) | (x >> rightShift);
}