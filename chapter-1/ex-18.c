#include <stdio.h>

#define MAX_DOC_LENGTH 1000
#define MAX_LENGTH 1000

int getLine(char line[], int maxLength);
void cleanLine(char line[], int length);
void copyLine(char from[], char to[]);
void printLine(char line[]);

int main(){
  int currentLength, lineIndex, i;
  char currentLine[MAX_LENGTH];
  char docLines[MAX_DOC_LENGTH][MAX_LENGTH];

  currentLength = -1;
  lineIndex = 0;
  while(currentLength = getLine(currentLine, MAX_LENGTH) != 0){    
    if (lineIndex == MAX_DOC_LENGTH) break;
    
    cleanLine(currentLine, currentLength);
    
    if (currentLine[0] != '\0'){
      copyLine(currentLine, docLines[lineIndex]);
      ++lineIndex;
    }
  }

  for (i = 0; i <= lineIndex; ++i) printLine(docLines[i]);

  return 0;
}

int getLine(char line[], int maxLength){
  int i, c;

  for (i = 0; i < maxLength - 1; ++i){
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

void copyLine(char from[], char to[]){
  int i;
  
  i = 0;
  while(from[i] != '\0'){
    to[i] = from[i];
    ++i;
  }
  to[i] = '\0';
}

void cleanLine(char line[], int length){
  int i;
  
  for(i = length - 1; i >= 0; --i){
    if (line[i] == ' '  || line[i] == '\t' || line[i] == '\n') line[i] = '\0';
    else break;
  }
}

void printLine(char line[]){
  int i;
  
  i = 0;

  while(line[i] != '\0'){
    printf("%c", line[i]);
    ++i;
  }
}