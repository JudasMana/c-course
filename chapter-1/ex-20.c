#include <stdio.h>

#define MAX_LENGTH 1000
#define TAB_STOP_WIDTH 8
#define TO_DO_DETAB 1
#define DETAB_DONE 0

void detabText(char text[], int maxLen);

int main(){
  char input[MAX_LENGTH];
  detabText(input, MAX_LENGTH);
  printf("\n\nDetabbed input: \n%s\n", input);
  return 0; 
}

void detabText(char text[], int maxLen){
  int spaces, c, inputIndex, rowIndex;

  inputIndex = rowIndex = 0;
  while(inputIndex < maxLen && (c=getchar()) != EOF){
    if (c == '\t'){
      spaces = TAB_STOP_WIDTH - (rowIndex % TAB_STOP_WIDTH);
      for (int i = 0; i < spaces && inputIndex < maxLen; ++i){
        text[inputIndex] = ' ';
        ++inputIndex;
        ++rowIndex;
      }
    } else {
      text[inputIndex] = c;
      ++inputIndex;
      ++rowIndex;
    }
    if (c == '\n') rowIndex = 0;
  }
}