#include <stdio.h>

int setbits(int x, int p, int n, int y);

int main(){
  int x = 0360740;
  int y = 000022;
  int p = 11;
  int n = 4;

  printf("\nSe ho x = %o e y = %o, e uso p = %d e n = %d\n", x, y, p, n);
  setbits(x, p, n, y);
  return 0;
}

int setbits(int x, int p, int n, int y){
  // Estrapolare i primi n bit di y
  int firstNFromY = y & ~(~0 << n);
  printf("firstNFromY: %o\n", firstNFromY);

  // Estrapolare i primi p - n + 1 bit di x
  int XTail = x & ~(~0 << (p - n + 1));
  printf("XTail: %o\n", XTail);

  // Shiftare x a destra di p - n + 1 bits
  x = x >> (p - n + 1);
  printf("X shiftato a destra di p - n + 1: %o\n", x);
  
  // Rendere 0 i primi n bits di x (dopo lo shift)
  x = x & (~0 << n);
  printf("X con maschera a 0 sui primi n bit: %o\n", x);

  // Sommare a x gli n bit estratti da y
  x = x | firstNFromY;
  printf("x sommati ai n bit presi da y: %o\n", x);
  
  // Shiftare a sinistra x di p - n + 1 bits
  x = x << (p - n + 1); 
  printf("x shiftato a sinistra di p - n + 1 bits: %o\n", x);

  // Sommare a x i p - n + 1 bits estratti allo step 2
  x = x | XTail;
  printf("x sommato agli p - n + 1 bit tolti prima: %o\n", x);

  return x;
}