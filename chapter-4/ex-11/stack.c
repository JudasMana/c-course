#include <stdio.h>
#include "calc.h"
#define MAX_VAL 100

int sp = 0;
double val[MAX_VAL];

void push(double n){
  if (sp < MAX_VAL) val[sp++] = n;
  else printf("Error: stack full, cannot push %g\n", n);
}

double pop(void){
  if (sp > 0) return val[--sp];
  else printf("Error: cannot pop, stack is empty\n");
  return 0.0;
}