#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

// Main routine
#define MAX_LINE 100
#define NUMBER -2
#define FUNCTION -3
#define VARIABLE -4

#define EMPTY -1

#define MAX_STACK_LENGTH 100
#define MAX_BUFFER_LENGTH 100
#define MAX_VARIABLE_LENGTH 100

double pop();
void push(double n);
int getop(char s[]);
double myAtof(char s[]);
void printop();
void duplicateTop();
void swapTop();
void clearStack();
int getch();
void ungetch(int c);
int getVarIndex(char s[]);
void pushToVarValues(double n, char s[]);
void ungets(char s[]);

int stackIndex = -1;
double stack[MAX_STACK_LENGTH];

int bufferIndex = -1;
char buffer[MAX_BUFFER_LENGTH];

double lastResult;
char tempVar[MAX_VARIABLE_LENGTH];

char varArray[MAX_STACK_LENGTH][MAX_VARIABLE_LENGTH] = {"\0"};
double varValues[MAX_STACK_LENGTH];

int main(){
  char s[MAX_LINE];
  double op1, op2;
  int signal, varIndex;

  while((signal = getop(s)) != EOF){
    // printf("Signal received: %d\n", signal);
    switch(signal){
      case NUMBER:
        push(myAtof(s));
        break;
      case VARIABLE:
        if (strcmp(s, "last") == 0) push(lastResult);
        else {
          varIndex = getVarIndex(s);
          if (varIndex >= 0) push(varValues[varIndex]);
          else strcpy(tempVar, s);
        }
        break;  
      case '=':
        pushToVarValues(myAtof(s), tempVar);
        break;
      case FUNCTION:
        if (strcmp(s, "sin") == 0){
          push(sin(pop()));
        } else if (strcmp(s, "cos") == 0){
          push(cos(pop()));
        } else if (strcmp(s, "pow") == 0){
          op2 = pop();
          push(pow(pop(), op2));
        } else printf("Unrecognised function\n");
        break;
      case '+':
        push(pop() + pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '*':
        push(pop() * pop());
        break;
      case '%':
        op2 = pop();
        op1 = pop();
        if (op2 == 0.0) printf("Cannot compile modulus of 0\n");
        else if (op2 != (int) op2 || op1 != (int) op1) printf("Modulus operands must be integers\n");
        else (push((int) op1 % (int) op2));
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0) push(pop() / op2);
        else printf("Division by 0 detected\n");
        break;
      case '\n':
        // printf("Now printing...");
        // printop();
        lastResult = pop();
        printf("\t%.8g\n", lastResult);
        break;
      default:
        printf("Unrecognised operation detected\n");
        break;
      }
  }
  return 0;
}


// Push and pop routines
double pop(){
  // printf("Pop called\n");
  if (stackIndex < 0){
    printf("Stack is empty\n");
    return 0.0;
  } else return stack[stackIndex--];
}

void push(double n){
  // printf("To be pushed: %g\n", n);
  if (stackIndex == MAX_STACK_LENGTH - 1){
    printf("Cannot push, stack is full'n");
  } else {
    stack[++stackIndex] = n;
  }
}

// Getop routine
int getop(char s[]){
  int i = 0, c;
  while ((c = getch()) == ' ' || c == '\t');
  if (!isdigit(c) && c != '.' && !(c >= 'a' && c <= 'z')) return c;
  s[i++] = c;
  if (c == '.' || isdigit(c)) {
    while (isdigit(c = getch())) s[i++] = c;
    if (c == '.') {
      s[i++] = c;
      while (isdigit(c = getch())) s[i++] = c;
    }
    s[i] = '\0';
    if (c != EOF) ungetch(c);
    return NUMBER;
  } else {
    while((c = getch()) >= 'a' && c <= 'z') s[i++] = c;
    s[i] = '\0';
    if (c != EOF) ungetch(c);
    return strlen(s) > 1 ? FUNCTION : VARIABLE;
  }
}

// getch routine
int getch(){
  return bufferIndex >= 0 ? buffer[bufferIndex--] : getchar();
}
void ungetch(int c){
  if (c < 0) return;
  if (bufferIndex == MAX_BUFFER_LENGTH - 1) printf("Cannot push to character buffer\n");
  else buffer[++bufferIndex] = c;
}

// Atof routine
double myAtof(char s[]){
  double val;
  int sign, i, powerSign, j, power, exponent;

  for(i = 0; isspace(s[i]); ++i);
  sign = s[i] == '-' ? -1 : 1;
  if (s[i] == '-' || s[i] == '+') ++i;
  
  power = 0;
  val = 0;
  exponent = 0;

  while(isdigit(s[i])){
    val = 10.0 * val + (s[i++] - '0');
  }

  if(s[i] == '.'){
    ++i;
    while(isdigit(s[i])){
      val = 10.0 * val + (s[i++] - '0');
      power -= 1;
    }
  }

  j = power;
  while(j != 0){
    if (power > 0){
      --j;
      val *= 10.0;
    } else {
      ++j;
      val /= 10.0;
    }
  }

  return sign * val;
}

void printop(){
  if (stackIndex < 0) printf("Cannot print top: must have at least one element in the stack\n");
  else  printf("Top of the stack: %g\n", stack[stackIndex]);
}

void duplicateTop(){
  if (stackIndex < 0) printf("Cannot duplicate top: must have at least one element in the stack\n");
  else push(stack[stackIndex]);
}

void swapTop(){
  if (stackIndex < 1){
    printf("Cannot swap top elements: must have at least two ib the stack\n");
  } else {
    double temp = stack[stackIndex - 1];
    stack[stackIndex  -1] = stack[stackIndex];
    stack[stackIndex] = temp;
  }
}

void clearStack(){
  stackIndex = -1;
}

// Variables routines
int getVarIndex(char s[]){
  int i = 0;
  while(strcmp(varArray[i], "\0") != 0) {
    if (strcmp(varArray[i], s) == 0) return i;
    ++i;
  }
  return -1;
}

void pushToVarValues(double n, char s[]){
  int i = 0;
  while(strcmp(varArray[i], "\0") != 0) ++i;
  varValues[i] = n;
  strcpy(varArray[i++], s);
  strcpy(varArray[i], "\0");
}

// unget string routine
void ungets(char s[]){
  int i = 0;
  while(s[i++] != '\0') ungetch(s[i]);
}

// single pushback getch and ungetch
char bufChar = EMPTY;
void ungetSingleCh(int c){
  if (bufChar >= 0) printf("Updating current bufChar. Could cause data loss.\n");
  bufChar = c;
}

int getSingleCh(){
  if (bufChar < 0) printf("No pushed back character to get\n");
  else {
    int temp = bufChar;
    bufChar = EMPTY;
    return temp;
  }
}