#include <stdio.h>

#define MAX_LENGTH 1000

int main(){
  char s[MAX_LENGTH];
  int c;
  for(int i = 0; i < MAX_LENGTH - 1; ++i){
    c = getchar();
    if (c == EOF) break;
    if (c == '\n') break;
    s[i] = c;
  }
  return 0;
}