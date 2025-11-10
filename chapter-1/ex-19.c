#include <stdio.h>

#define MAX_LENGTH 1000
#define MAX_DOC_LENGTH 1000

int getLine(char line[], int maxLen);
void reverse(char line[]);
void copyString(char from[], char to[]);
void printLine(char line[]);

int main(){
  int curLen, stringIndex;
  char curString[MAX_LENGTH];
  char reversedStrings[MAX_DOC_LENGTH][MAX_LENGTH];
  stringIndex = 0;

  while((curLen = getLine(curString, MAX_LENGTH)) != 0){
    reverse(curString);
    copyString(curString, reversedStrings[stringIndex]);
    ++stringIndex;
  }

  for(int i = 0; i < stringIndex; ++i) printLine(reversedStrings[i]);
  return 0;
}

void reverse(char line[]){
  int length = 0;
  while (line[length] != '\0') ++length;
  
  char temp;
  for (int i = 0 ; i < (length / 2); ++i){
    temp = line[length - 1 - i];
    line[length - 1 - i] = line[i];
    line[i] = temp;
  }
}

int getLine(char line[], int maxLen){
  int len, c;

  len = 0;
  while (len < maxLen - 1 && (c = getchar()) != '\n' && c != EOF) {
    line[len] = c;
    ++len;
  }

  if (c == '\n'){
    line[len] = '\n';  
    ++len;
  }

  line[len] = '\0';
  return len;
}

void copyString(char from[], char to[]){
  for (int i = 0; (to[i] = from[i]) != '\0'; ++i);
}

void printLine(char line[]){
  for (int i = 0; line[i] != '\0'; ++i) printf("%c", line[i]);
}