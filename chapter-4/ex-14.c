#include <stdio.h>

#define swap(t, x, y) {\
  t temp = x;\
  x = y;\
  y = temp;\
};

int main(){
  int a = 1;
  int b = 2;
  swap(int, a, b);
  printf("New a: %d\nNew b: %d", a, b);
  return 0;
}