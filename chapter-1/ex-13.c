#include <stdio.h>

#define START -1
#define IN_WORD 0
#define OUT_OF_WORD 1
#define NUMBER_OF_WORDS_ALLOWED 10

int main(){
  int c, i, currentWordIndex, wordsNumber, state;
  int wordCounts[NUMBER_OF_WORDS_ALLOWED];

  currentWordIndex = 0;
  state = START;

  for (i = 0; i < NUMBER_OF_WORDS_ALLOWED; ++i){
    wordCounts[i] = 0;
  }

  while ((c = getchar()) != '\n'){
    if (c != ' ' && c != '\t'){      
      if (state == OUT_OF_WORD)  ++currentWordIndex;
      state = IN_WORD;
      ++wordCounts[currentWordIndex];
    } else {
      if (state != START) state = OUT_OF_WORD;
    }
  }

  int max = 0;
  for (i = 0; i < NUMBER_OF_WORDS_ALLOWED; ++i){
    if (wordCounts[i] >= max) max = wordCounts[i];
  }

  printf("\n\nHistogram:\n");
  for (int j = max; j > 0; --j){
    for (i = 0; i < NUMBER_OF_WORDS_ALLOWED; ++i){
        if (wordCounts[i] >= j) printf("X");
        else printf(" "); 
        printf(" ");
    }
    printf("\n");
  }
}