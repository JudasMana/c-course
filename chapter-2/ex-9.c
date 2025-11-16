#include <stdio.h>

/*
x = 1001
x - 1 = 1000
x & (x-1) = 1000 --> correct

x = 1000
x - 1 = 0111
x & (x-1) = 0000 --> correct

x = 1010
x - 1 = 1001
x & (x-1) = 1000 --> correct

It works because:
if last bit is 1 --> it becomes 0 and with & it gets deleted
if last bit is 0 --> the last 1 in x becomes 0 and all the following bits become 1, and with & all the bits (with the last 1) become 0
*/

int bitcount(int x);

int main(){
  int x = 11;
  printf("\nCount 1 bits in %o: %d\n", x, bitcount(x));
  return 0;
}

int bitcount(int x){
  int count;
  for (count = 0; x != 0; x &= x - 1) ++count;
  return count;
}