#include <stdio.h>

#define BUF_SIZE 100

char buf[BUF_SIZE];
int bufp = 0;

int getch(void){
  return (bufp > 0) ? buf[--bufp] : getchar();
} 

void ungetch(int c){
  if (bufp >= BUF_SIZE) printf("ungetch: too many characters\n"); 
  else buf[bufp++] = c;
}