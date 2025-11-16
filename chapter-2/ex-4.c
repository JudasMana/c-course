#include <stdio.h>

#define MAX_LENGTH 1000

void squeeze(char str1[], char str2[]);

int main(){
  char str1[MAX_LENGTH] = "esempio";
  char str2[MAX_LENGTH] = "o";

  squeeze(str1, str2);

  printf("\nString after deletion: %s\n", str1);

  return 0;
}

void squeeze(char str1[], char str2[]){
  int str1RreadingIndex, str2ReadingIndex, str1WritingIndex;

  for(str1RreadingIndex = str1WritingIndex = 0; str1[str1RreadingIndex] != '\0'; ++str1RreadingIndex){
    for(str2ReadingIndex = 0; str2[str2ReadingIndex] != '\0' && str1[str1RreadingIndex] != str2[str2ReadingIndex]; str2ReadingIndex++);
    if (str2[str2ReadingIndex] == '\0') str1[str1WritingIndex++] = str1[str1RreadingIndex];
  }
  str1[str1WritingIndex] = '\0';
}