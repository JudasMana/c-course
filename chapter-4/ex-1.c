#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int getLine(char line[], int maxLength);
int strIndex(char string[], char pattern[]);

int main(){
  char line[MAX_LENGTH];
  char pattern[] = "es";
  int found = 0;

  while(getLine(line, MAX_LENGTH) != 0){
    if (strIndex(line, pattern) > 0){
      ++found;
      printf("%s", line);
    }
  }
  return found;
}

int getLine(char line[], int maxLength){
  int c, i;
  i = 0;
  while((c = getchar()) != '\n' && c != EOF && --maxLength) line[i++] = c;
  if (c = '\n') line[i++] = '\n';
  line[i] = '\0';
  return i;
}

int strIndex(char string[], char pattern[]){
  int i, j, k;

  for(i = strlen(string) - 1; i >= 0; --i){
    for(j = i, k = 0; string[j] == pattern[k] && pattern[k] != '\0' && string[j] != '\0'; ++j, ++k);
    if (pattern[k] == '\0') return i;
  }
  return -1;
}