#include <stdio.h>

#define MAX_LENGTH 1000
#define MAX_DOC_LENGTH 1000
#define LEN_TRESHOLD 10

int getLine(char line[], int maxLen);
void copyLine(char from[MAX_LENGTH], char to[MAX_LENGTH]);
void printLine(char line[MAX_LENGTH]);

int main(){
  char longLines[MAX_DOC_LENGTH][MAX_LENGTH];
  char currentLine[MAX_LENGTH];
  int currentLength, lineIndex, i;

  lineIndex = 0;
  while((currentLength = getLine(currentLine, MAX_LENGTH)) != 0){
    if (currentLength >= LEN_TRESHOLD + 1){
      copyLine(currentLine, longLines[lineIndex]);
      ++lineIndex;
    }
  }

  for (i = 0; i < lineIndex; ++i) printLine(longLines[i]);

  return 0;
}


int getLine(char line[], int maxLen){
  int i, c;

  for (i = 0; i < maxLen - 1; ++i){
    c = getchar();
    if (c == '\n'){
      line[i] = c;
      ++i;
      break;
    } else if (c == EOF) break;
    else line[i] = c;
  }

  line[i] = '\0';
  return i;
}

void copyLine(char from[MAX_LENGTH], char to[MAX_LENGTH]){
  int i;

  for (i = 0; i < MAX_LENGTH; ++i){
    if (from[i] != '\0') to[i] = from[i];
    else break;
  }
}

void printLine(char line[MAX_LENGTH]){
  int i;

  for (i = 0; i < MAX_LENGTH; ++i){
    printf("%c", line[i]);
    if (line[i] == '\0') break;
  }
}