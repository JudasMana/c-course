#include <stdio.h>

#define MAXLEN 100

void itoa(char s[], int n);

int main(){
  char s[MAXLEN];
  int n = 1357;
  itoa(s, n);
  printf("String: %s\n", s);
  return 0;
}

void itoa(char s[], int n){
  static int i = 0;
  if(n < 0){
    s[i++] = '-';
    n = -n; 
  }
  if (n != 0){
    itoa(s, n / 10);
    if (i < MAXLEN - 1) s[i++] = n % 10 + '0';
  }
  s[i + 1] = '\0';
}


