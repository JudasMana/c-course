#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_LENGTH 1000

void itob(int n, char s[], int b);
void reverse(char str[]);

int main(){
  int b = 36;
  int n = 1364278;
  char string[MAX_LENGTH];
  itob(n, string, b);
  printf("\nString to base:\n%s\n", string);
  return 0;
}

void itob(int n, char s[], int b){
  if (b > 36) {
    printf("Base cannot exceed 36");
    return;
  }

  int c, sign, exception = 0, i = 0;

  if (n == INT_MIN){
    exception = 1;
    n += 1;
  }
  if ((sign = n) < 0){
    n = -n;
  }

  do {
    c = (n % b < 10) ? (n % b) + '0' : ((n % b) - 10) + 'A';
    s[i++] = c;
  } while((n /= b) > 0);

  if (sign < 0){
    s[i++] = '-';
  }
  s[i] = '\0';
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