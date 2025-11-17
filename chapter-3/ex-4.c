#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAX_LENGTH 1000

void itoa(char str[], int n);
void reverse(char str[]);

int main(){
  int n = INT_MIN;
  printf("Int min: %d", INT_MIN);
  printf("Long min: %d", LONG_MIN);
  char str[MAX_LENGTH];

  itoa(str, n);
  printf("\nNumber stringified:\n%s\n", str);
  return 0;
}

void itoa(char str[], int n){
  int sign, i = 0, exception = 0;
  if (n == INT_MIN) {
    n += 1; // power of 2 will never finish with 9
    exception = 1;
  }
  if ((sign = n) < 0){
    n = -n;
  }

  do {
    str[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);

  if (sign < 0){
    str[i++] = '-';
  }
  str[i] = '\0';

  if (exception) str[0] += 1;

  reverse(str);
}

void reverse(char str[]){
  int i, j, temp;
  for(i = 0, j = strlen(str) - 1; i < j; ++i, --j){
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  }
}