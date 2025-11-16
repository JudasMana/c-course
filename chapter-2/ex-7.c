#include <stdio.h>

int invert(int x, int p, int n);

int main(){
  int x = 0224; // 010 010 100, dovrebbe diventare: 010 001 100 -> 214
  int p = 4;
  int n = 2;

  printf("\nSe ho x = %o, p = %d e n = %d, ottengo: %o\n", x, p, n, invert(x, p, n));
  return 0;
}

int invert(int x, int p , int n){
  int tailX = x & ~(~0 << (p - n + 1));
  printf("Mi prendo gli ultimi %d bit di x: %o\n", (p - n + 1), tailX);

  x = x >> (p - n + 1);
  printf("Shifto x a destra di %d bit: %o\n", (p - n + 1), x);

  int inverted = ~x & ~(~0 << n); 
  printf("Prendo l'inverso di x e ne tengo solo gli ultimi %d bit: %o\n", n, inverted);

  x = (x & (~0 << n)) | inverted;
  printf("Metto i bit invertiti: %o\n", x);

  x = (x << (p - n + 1)) | tailX;
  printf("Rimetto la coda al suo posto: %o\n", x);

  return x;
}