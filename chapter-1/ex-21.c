#include <stdio.h>

#define MAX_INPUT_LENGTH 1000
#define TAB_STOP_LENGTH 2

void entabInput(char text[], int maxLen);

int main(){
  char input[MAX_INPUT_LENGTH];

  entabInput(input, MAX_INPUT_LENGTH);

  printf("\n\nEntabbed input: \n%s\n", input);

  return 0;
}

void entabInput(char text[], int maxLen){
  int c, spaceCounter, tabDisplacement, inputIndex;
  inputIndex = tabDisplacement = spaceCounter = 0;
  while(inputIndex < maxLen && (c = getchar()) != EOF){
    if (c == ' '){
      spaceCounter++;
      if (spaceCounter == TAB_STOP_LENGTH - (tabDisplacement % TAB_STOP_LENGTH)){
        text[inputIndex] = '\t';
        tabDisplacement = 0;
        ++inputIndex;
        spaceCounter = 0;
      }
    } else {
      if (spaceCounter != 0 ){
        for (int i = 0; i < spaceCounter && inputIndex < maxLen - 1; --spaceCounter){
          text[inputIndex] = ' ';
          ++inputIndex;
          ++tabDisplacement;
        }
      }
      text[inputIndex] = c;
      ++inputIndex;
      ++tabDisplacement;
    }

    if (c == '\n' || c == '\t') tabDisplacement = 0;
  }
}