#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 100

int pGetline(char *s, int lim);
int pAtoi(char *s);
void reverse(char *s);
void pItoa(char *s, int n);
int pStrindex(char *string, char *target);

int main(){
  // char str[MAX_LEN];
  // while(pGetline(str, MAX_LEN) != 0){
  //   printf("Current line: %s\n", str);
  // }

  // char number[] = "2345"; 
  // printf("Number from atoi: %d\n", pAtoi(number));

  // char string[MAX_LEN];
  // int numberInt = 26135;
  // pItoa(string, numberInt);
  // printf("String from itoa: %s\n", string);

  char myString[] = "Test";
  char myTarget[] = "Tes";
  printf("Detected index: %d\n", pStrindex(myString, myTarget));
  return 0;
}

int pGetline(char *s, int lim){
  int c;
  char *startingS = s;
  while(s - startingS < lim - 1 && (c = getchar()) != EOF && c != '\n') *s++ = c;
  if (c == '\n') *s++ = c;
  *s = '\0';
  return s - startingS;
}

int pAtoi(char *s){
  int n = 0;
  while(isspace(*s)) s++;
  while(isdigit(*s)){
    n = n * 10 + (*s - '0');
    s++;
  }
  return n;
}

void reverse(char *s){
  char *end = s;
  int temp;
  while(*(end + 1) != '\0') end++;

  while(s <= end){
    temp = *end;
    *end-- = *s;
    *s++ = temp;
  }
}

void pItoa(char *s, int number){
  char *current = s;
  while(number % 10 != 0){
    *current++ = '0' + (number % 10);
    number /= 10;
  }
  *current = '\0';
  reverse(s);
}

int pStrindex(char *s, char *t){
  int i;
  char *cursor = s;
  while(*cursor != '\0'){
    for (i = 0; *(cursor + i) == *(t + i); i++);
    if (*(t + i) == '\0') return cursor - s;
    cursor++;
  }
  return -1;
}