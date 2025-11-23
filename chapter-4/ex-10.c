#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LINE_LENGTH 100
#define MAX_STACK_LENGTH 100
#define MAX_VARIABLE_LENGTH 100

#define ERROR -1
#define PRINT -2
#define NUMBER -3
#define FUNCTION -4
#define VARIABLE -5
#define END_OF_LINE -6
#define PLUS '+'
#define MINUS '-'
#define MULT '*'
#define DIV '/'
#define MOD '%'
#define EQ '='
#define LAST_RESULT '_'

int getLine(char s[], int maxLen);
int getop(char line[], char op[]);
double pop();
void push(double n);
double myAtof(char s[]);
int getVarIndex(char s[]);
void pushToVarValues(double n, char s[]);

double lastResult;

int stackIndex = -1;
double stack[MAX_STACK_LENGTH];

char tempVar[MAX_VARIABLE_LENGTH];
char varArray[MAX_STACK_LENGTH][MAX_VARIABLE_LENGTH] = {"\0"};
double varValues[MAX_STACK_LENGTH];

int main(){
  double op1, op2;
  char line[MAX_LINE_LENGTH];
  char op[MAX_LINE_LENGTH];
  int signal, varIndex;

  while(getLine(line, MAX_LINE_LENGTH) != -1){
    while((signal = getop(line, op)) != END_OF_LINE){
      switch(signal){
        case NUMBER:
          push(myAtof(op));
          break;
        case LAST_RESULT:
          push(lastResult);
          break;
        case VARIABLE:
          varIndex = getVarIndex(op);
          if (varIndex >= 0) push(varValues[varIndex]);
          else strcpy(tempVar, op);
          break;  
        case EQ:
          op1 = pop();
          printf("Saving variable %s with value %g\n", tempVar, op1);
          pushToVarValues(op1, tempVar);
          break;
        case FUNCTION:
          if (strcmp(op, "sin") == 0){
            push(sin(pop()));
          } else if (strcmp(op, "cos") == 0){
            push(cos(pop()));
          } else if (strcmp(op, "pow") == 0){
            op2 = pop();
            push(pow(pop(), op2));
          } else printf("Unrecognised function\n");
          break;
        case PLUS:
          push(pop() + pop());
          break;
        case MINUS:
          op2 = pop();
          push(pop() - op2);
          break;
        case MULT:
          push(pop() * pop());
          break;
        case MOD:
          op2 = pop();
          op1 = pop();
          if (op2 == 0.0) printf("Cannot compile modulus of 0\n");
          else if (op2 != (int) op2 || op1 != (int) op1) printf("Modulus operands must be integers\n");
          else (push((int) op1 % (int) op2));
          break;
        case DIV:
          op2 = pop();
          if (op2 != 0.0) push(pop() / op2);
          else printf("Division by 0 detected\n");
          break;
        case PRINT:
          lastResult = pop();
          printf("\t%.8g\n", lastResult);
          break;
        case ERROR:
          printf("Error: operation not recognized: %d\n", op[0]);
          return 1;
          break;
        default:
          printf("Unrecognised operation detected: %s\n", op);
          break;  
      }
      if (signal == EQ) break;
    }

    // read first operand
    // read eventual second operand
    // read operator
    // print and save result
  }
  return 0;
}

int getLine(char s[], int maxLen){
  int c, i = 0;
  while ((c = getchar()) != '\n' && c != EOF && i < maxLen - 1) s[i++] = c;
  if (c == EOF) return -1;
  if (c == '\n') s[i++] = '\n';
  s[i] = '\0';
  return i;
}

int getop(char line[], char op[]){
  int i = 0, j = 0, jStart, z = 0;
  int value;

  // Skip spaces
  while(line[i] == '\t' || line[i] == ' ') ++i;

  // Get starting op index
  jStart = i;

  // Get op value
  if (line[i] == '\n') value = PRINT;
  else if (line[i] == '\0') value = END_OF_LINE;
  else if (line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/' || line[i] == '%' || line[i] == '=' || line[i] == '_') value = line[i];
  else if (line[i] == '.' || isdigit(line[i])){
    while(isdigit(line[i])) ++i;
    if (line[i] == '.') ++i;
    while(isdigit(line[i])) ++i;
    --i;
    value = NUMBER;
  } else if (line[i] >= 'a' && line[i] <= 'z') {
    while (line[i] >= 'a' && line[i] <= 'z') ++i;
    value = i - jStart > 1 ? FUNCTION : VARIABLE;
    --i;
  } else value = ERROR;

  // Copy op in s
  while(jStart + j <= i) {
    op[j] = line[jStart + j];
    ++j;
  } 
  op[j] = '\0';

  // Remove op from line
  ++i;
  while(line[i + z] != '\0') {
    line[z] = line[i + z];
    z++;
  }
  line[z] = '\0';

  // Return correct value
  return value;
}

double pop(){
  if (stackIndex < 0){
    printf("Stack is empty\n");
    return 0.0;
  } else return stack[stackIndex--];
}

void push(double n){
  if (stackIndex == MAX_STACK_LENGTH - 1){
    printf("Cannot push, stack is full'n");
  } else {
    stack[++stackIndex] = n;
  }
}

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