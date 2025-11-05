#include <stdio.h>

#define MAX_LENGTH 5

int getLine(char line[], int lim);
void copy(char from[], char to[]);

int main (){
  int  currentLen, longestLineLength, lengthMax, extraLen;
  char currentLine[MAX_LENGTH];
  char throwString[MAX_LENGTH];
  char longestLine[MAX_LENGTH];

  longestLineLength = lengthMax = 0;
  currentLen = 0;
  
  while((currentLen = getLine(currentLine, MAX_LENGTH)) != 0){
    lengthMax = currentLen;
    while (currentLen == MAX_LENGTH - 1 && throwString[currentLen - 1] != '\n'){
      currentLen = getLine(throwString, MAX_LENGTH);
      lengthMax = lengthMax + currentLen;
    }
    if (lengthMax > longestLineLength){
      longestLineLength = lengthMax;
      copy(currentLine, longestLine);
    }
  }

  if (longestLineLength > 0){
    printf("Max length: %d\n", longestLineLength);
    printf("The longest line is: \n%s", longestLine);
  }

  return 0;
}

int getLine(char line[], int lim){
  int i, c;

  i = 0;
  while (i < lim - 1){
    c = getchar();
    if (c != EOF && c != '\n') {
      line[i] = c;
      ++i;
    }
    else break;
  }
  
  if (line[i] == '\n'){
    line[i] = c;
    ++i;
  }

  line[i] ='\0';

  return i;
}

void copy(char from[], char to[]){
  int i;
  i = 0;

  while ((to[i] = from[i]) != '\0') ++i;
}