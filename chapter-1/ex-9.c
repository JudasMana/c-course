#include <stdio.h>

#define CHARACTER_TO_FILTER ' '

int main(){
  int ch;
  int lastChar;

  lastChar = '\0';
  while((ch = getchar()) != EOF){
    if (ch == CHARACTER_TO_FILTER){
      if (lastChar != CHARACTER_TO_FILTER){
        putchar(ch);
      }
    }
    if (ch != CHARACTER_TO_FILTER){
      putchar(ch);
    }
    lastChar = ch;
  }
}