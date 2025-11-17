#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAX_LENGTH 1000

void reverse(char s[]);
void itoa(int n, char s[], int minLength);

int main(){
  char str[MAX_LENGTH];
  int n = -253;
  int minLength = 10;
  itoa(n, str, minLength);
  printf("\nStringified and padded: \n%s\n", str);
  return 0;
}

void itoa(int n, char s[], int minLength){
  int sign, exception = 0, i = 0;

  if(n == INT_MIN){
    exception = 1;
    n += 1;
  }

  if ((sign = n) < 0){
    n = -n;
  }

  do {
    s[i++] = (n % 10) + '0';
  } while ((n /= 10) > 0);

  if (sign < 0) s[i++] = '-';

  while (i < minLength){
    s[i++] = ' ';
  }

  s[i] = '\0';
  if (exception) s[0] += 1;
  reverse(s);
}

void reverse(char s[]){
  int i, j, temp;
  for(i = 0, j = strlen(s) - 1; i < j; ++i, --j){
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }
}