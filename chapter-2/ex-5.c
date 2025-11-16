#include <stdio.h>

#define MAX_LENGTH 1000

int any(char str1[], char str2[]);

int main(){
  char str1[MAX_LENGTH] = "Test";
  char str2[MAX_LENGTH] = "yuiyuiuiT";
  printf("\nShould return 0: %d\n", any(str1, str2));
  return 0;
}

int any(char str1[], char str2[]){
  for (int i = 0; str1[i] != '\0'; ++i){
    for (int j = 0; str2[j] != '\0'; ++j) if (str1[i] == str2[j]) return i;
  }
  return -1;
}