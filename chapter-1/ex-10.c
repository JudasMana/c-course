#include <stdio.h>

#define TAB '\t'
#define BACKSPACE '\b'
#define SLASH '\\'

int main(){
  int c;

  while((c = getchar()) != EOF){
    if (c == TAB)
      printf("\\t");
    else if (c == BACKSPACE)
      printf("\\b");
    else if (c == SLASH)
      printf("\\\\");
    else
      putchar(c);
  }
}