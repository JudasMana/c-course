#include <stdio.h>

#define MAX_LENGTH 1000
#define NORMAL_MODE 1
#define CHARACTER_MODE 2
#define STRING_MODE 3
#define LINE_COMMENT_MODE 4
#define BLOCK_COMMENT_MODE 5

int addToStack(char stack[], char element, int stackLength);
int popFromStack(char stack[], int stackLength);
char getTopStackElement(char stack[], int stackLength);

int main(){
  char text[MAX_LENGTH];
  char characters[MAX_LENGTH];
  int i, c, mode, stackLength;
  char lastChar;

  i = stackLength = 0;
  mode = NORMAL_MODE;
  while((c = getchar()) != EOF){
    text[i] = c;
    ++i;
  }
  text[i] = EOF;

  i = 0;
  while(text[i] != EOF){
    c = text[i];
    
    // Parenthesis
    if (c == '(' || c == '[' || c == '{') {
      if (mode == NORMAL_MODE) stackLength = addToStack(characters, c, stackLength);
    }    
    if (c == ')' && mode == NORMAL_MODE){
      if (getTopStackElement(characters, stackLength) != '(') {
        printf("Wrong character ) detected\n");
        return 1;
      } else stackLength = popFromStack(characters,   stackLength);
    } else if (c == ']' && mode == NORMAL_MODE){
    if (getTopStackElement(characters, stackLength) != '[') {
      printf("Wrong character ] detected\n");
      return 1;
    } else stackLength = popFromStack(characters,   stackLength);
    } else if (c == '}' && mode == NORMAL_MODE){
      if (getTopStackElement(characters, stackLength) != '{') {
        printf("Wrong character } detected\n");
        return 1;
      } else stackLength = popFromStack(characters,   stackLength);
    }

    // Strings
    if (c == '"' && mode != BLOCK_COMMENT_MODE && mode != LINE_COMMENT_MODE && getTopStackElement(characters, stackLength) != '\\'){
     if (mode == NORMAL_MODE) {
        mode = STRING_MODE;
        stackLength = addToStack(characters, c, stackLength);
      } else if (mode == STRING_MODE) {
        mode = NORMAL_MODE;
        stackLength = popFromStack(characters, stackLength);
      }
    }
    if (mode == CHARACTER_MODE && c != '\'' && c != '\\' && text[i + 1] != '\'') {
      printf("Wrong character sequence");
      return 1;
    }
    if (c == '\'' && mode != BLOCK_COMMENT_MODE && mode != LINE_COMMENT_MODE && getTopStackElement(characters, stackLength) != '\\'){
     if (mode == NORMAL_MODE) {
        mode = CHARACTER_MODE;
        stackLength = addToStack(characters, c, stackLength);
      } else if (mode == CHARACTER_MODE) {
        mode = NORMAL_MODE;
        stackLength = popFromStack(characters, stackLength);
      }
    }

    // Comments
    if (c == '/' && mode == NORMAL_MODE){
      if (text[i + 1] == '/') mode = LINE_COMMENT_MODE;
      else if (text[i + 1] == '*') mode = BLOCK_COMMENT_MODE;
    } else if (c == '\n' && mode == LINE_COMMENT_MODE){
      mode = NORMAL_MODE;
    } else if (c == '*' && mode == BLOCK_COMMENT_MODE && text[i + 1] == '/'){
      mode = NORMAL_MODE;
    }

    // Escape sequences
    if (mode != LINE_COMMENT_MODE && mode != BLOCK_COMMENT_MODE && getTopStackElement(characters, stackLength) == '\\'){
      if (c == 'n' || c == 't' || c == '0' || c == 'b' || c == '"' || c == '\'' || c == '"'){
        stackLength = popFromStack(characters, stackLength);
      } else {
        printf("Wrong escape sequence: \\%c", c);
        return 1;
      }
    }
    if (mode != LINE_COMMENT_MODE && mode != BLOCK_COMMENT_MODE && c == '\\'){
      if (getTopStackElement(characters, stackLength) == '\\') stackLength = popFromStack(characters, stackLength);
      else stackLength = addToStack(characters, c, stackLength);
    }

    ++i;
  }

  i = 0;
  if (stackLength > 0){
    while(i < stackLength){
      printf("There is an error: %c\n", characters[i]);
      ++i;
    }
  }
  return 0;
}

int addToStack(char stack[], char element, int stackLength){
  stack[stackLength] = element;
  return stackLength + 1;
}

int popFromStack(char stack[], int stackLength){
  stack[stackLength - 1] = '\0';
  return stackLength - 1;
}

char getTopStackElement(char stack[], int stackLength){
  return stack[stackLength - 1];
}
