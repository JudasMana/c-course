#include <ctype.h>
#include <stdio.h>

#define BUF_SIZE 100

int getch(void);
void ungetch(int c);
int getInt(int *pn);

char buf[BUF_SIZE];
int bufp = 0;

int main(){
  int i, result;
  result = getInt(&i);
  printf("Value found: %d\nValue returned: %d\n", i, result);
  return 0;
}

int getInt(int *pn){
  int c, sign;

  while(isspace(c = getch()));
  if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
    ungetch(c);
    return 0;
  }
  sign = c == '-' ? -1 : +1;
  if (c == '+' || c == '-') c = getch();
  if (!isdigit(c)) {
    ungetch(c);
    return 0;
  }
  for (*pn = 0; isdigit(c) ; c = getch()){
    *pn = *pn * 10 + (c - '0');
  }
  *pn *= sign;
  if (c != EOF) ungetch(c);
  return c;
}

int getch(void){
  return (bufp > 0) ? buf[--bufp] : getchar();
} 

void ungetch(int c){
  if (bufp >= BUF_SIZE) printf("ungetch: too many characters\n"); 
  else buf[bufp++] = c;
}

