#include <stdio.h>

#define MAX_LINE_LENGTH 10
#define MAX_LENGTH 1000
#define SPACE_NOT_FOUND -1

void foldLines(char text[], int maxLineLength);

int main(){
  int c, i;
  char input[MAX_LENGTH];

  i = 0;
  while(i < MAX_LENGTH - 1 && (c = getchar()) != EOF){
    input[i] = c;
    ++i;
  }
  ++i;
  input[i] = '\0';
  foldLines(input, MAX_LINE_LENGTH);

  printf("\n\nFolded input:\n%s", input);
  return 0;
}

void foldLines(char text[], int maxLineLength){
  printf("Folding lines that exceed characters: %d\n", maxLineLength);
  int i, lineLength, lastSpaceIndex, lineStartIndex;

  i = lineLength = lineStartIndex = 0;
  lastSpaceIndex = SPACE_NOT_FOUND;

  while(text[i] != '\0'){
    if (i == MAX_LENGTH - 1) {
      text[MAX_LENGTH - 1] = '\0';
      return;
    }

    ++lineLength;
    
    if (text[i] == ' ' || text[i] == '\t'){
      lastSpaceIndex = i;
    } else if (text[i] == '\n'){
      lineLength = 0;
      lastSpaceIndex = i;
      lineStartIndex = i + 1;
    }

    if (lineLength == maxLineLength){
      if (lastSpaceIndex != SPACE_NOT_FOUND || (lastSpaceIndex - lineStartIndex) > maxLineLength){
        text[i] = '\n';
       lineStartIndex = lastSpaceIndex + 1;
        lineLength = i - lineStartIndex;
        continue;
      } else if(lastSpaceIndex == SPACE_NOT_FOUND) {
        text[i] = '\n';
        lineStartIndex = i + 1;
        lineLength = i - lineStartIndex;
        continue;
      } else {
        printf("Inserting newline on space with index: %d\n", lastSpaceIndex);
        text[lastSpaceIndex] = '\n';
        lineStartIndex = lastSpaceIndex + 1;
        lineLength = i - lineStartIndex;
        lastSpaceIndex = SPACE_NOT_FOUND;
      }
    }
    
    ++i;
  }
}