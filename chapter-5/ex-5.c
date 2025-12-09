#include <stdio.h>

#define MAX_LENGTH 100

void myStrncpy(char *s, char *t, int n);
void myStrncat(char *s, char *t, int n);
int myStrncmp(char *s, char *t, int n);

int main(){
  char str1[MAX_LENGTH] = "testone";
  char *str2 = "My suo";
  myStrncpy(str1, str2, 4);
  printf("Strncpy: %s\n", str1);
  myStrncat(str1, str2, 4);
  printf("Strncat: %s\n", str1);
  printf("Strncmp: %d\n", myStrncmp(str1, str2, 4));
}

void myStrncpy(char *s, char *t, int n){
  while(n-- > 0 && *s != '\0' && *t != '\0'){
    *s++ = *t++;
  }
}

void myStrncat(char *s, char *t, int n){
  while(*(s++ + 1) != '\0');
  while(n-- > 0 && (*s++ = *t++) != '\0');
}

int myStrncmp(char *s, char *t, int n){
  while(n-- > 0  && *s == *t){
    s++;
    t++;
  }
  return n == -1 ? 0 : *s - *t;
}