#include <stdio.h>
#include <ctype.h>
#include "calc.h"

#define EMPTY -2

int getop(char s[]){
  int i;
  static int c = EMPTY;

  if (c == EMPTY || c != ' ' || c != '\t'){  
    while ((s[0] = c = getch()) == ' ' || c == '\t'); 
  } else s[0] = c;
  s[1] = '\0'; 

  if (!isdigit(c) && c != '.') return c;
  i = 0; 
  if (isdigit(c)){
    while (isdigit(s[++i] = c = getch())); 
  } 
  if (c == '.'){
    while (isdigit(s[++i] = c = getch())); 
  }  
  s[i] = '\0'; 
  return NUMBER;
}