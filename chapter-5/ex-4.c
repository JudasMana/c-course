#include <stdio.h>

int strend(char *s, char *t);

int main(){
  char *str1 = "TestEgft";
  char *str2 = "Egft";
  printf("Check: %d\n", strend(str1, str2));
  return 0;
}

int strend(char *s, char *t){
  char *originalT = t;
  while(*(++s + 1) != '\0');
  while(*(++t + 1) != '\0');

  while(t > originalT && *s-- == *t--);
  if (t == originalT) return 1;
  return 0;
}