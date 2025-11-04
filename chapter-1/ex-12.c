#include <stdio.h>

#define WORD_COMPLETE 0
#define WORD_INCOMPLETE 1
#define START 2

int main(){
  int c, state;

  state = START;
  while ((c = getchar()) != EOF){
    if (c == ' ' || c == '\n' || c == '\t'){
      if (state != START) state = WORD_COMPLETE;
    } else {
      if (state == WORD_COMPLETE) printf("\n");
      state = WORD_INCOMPLETE;
      putchar(c);
    }
  }
}