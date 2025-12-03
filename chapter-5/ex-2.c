#include <stdio.h>
#include <ctype.h>

#define BUF_SIZE 100

int getFloat(double *pn);
int getch(void);
void ungetch(int c);

char buf[BUF_SIZE];
int bufp = 0;

int main(){
  double n;
  getFloat(&n);
  printf("Got number: %.12g\n", n);
}

int getFloat(double *pn){
  int c, sign;
  int power = 1;

  while(isspace(c = getch()));
  if (!isdigit(c) && c != '-' && c != '+' && c != '.' && c != EOF){
    ungetch(c);
    return 0;
  }
  sign = c == '-' ? -1 : 1;
  if (c == '-' || c == '+') c = getch();
  if (!isdigit(c) && c != '.'){
    ungetch(c);
    return 0;
  }
  for(*pn = 0; isdigit(c); c = getch()){
    *pn = *pn * 10 + (c - '0');
  }
  if (c != '.') {
    ungetch(c);
    return c;
  }
  if (!isdigit(c = getch())) {
    ungetch(c);
    return c;
  }
  
  while(isdigit(c)){
    *pn = *pn * 10 + (c - '0');
    power *= 10;
    c = getch();
  }
  *pn = sign * (*pn / power);
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