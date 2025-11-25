#include <stdio.h>
#define MAXLEN 100

void reverse(char s[]);

int main(){
  char s[MAXLEN] = "asdfghjk";
  reverse(s);
  printf("Reversed: %s\n", s);
  return 0;
}

void reverse(char s[]){
  static int i = 0;
  static int j = 0;
  if (s[j] == '\0') return;
  if (s[i + j + 1] != '\0'){
    char temp = s[i + 1];
    s[i + 1] = s[i];
    s[i++] = temp;
    reverse(s);
  } else {
    ++j;
    i = 0;
    reverse(s);
  }
}