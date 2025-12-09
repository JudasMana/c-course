#include <stdio.h>

#define MAX_LENGTH 100

void myStrcat(char *s1, char *s2);

int main(){
  char str1[MAX_LENGTH] = "Test";
  char str2[] = "Allora";
  myStrcat(str1, str2);
  printf("Concatenated: %s\n", str1);
  return 0;
}

void myStrcat(char *s1, char *s2){
  while(*++s1 != '\0');
  while((*s1++ = *s2++) != '\0');
}

