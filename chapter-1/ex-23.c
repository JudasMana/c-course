#include <stdio.h>

#define MAX_LENGTH 1000
#define NO_COMMENT 0
#define LINE_COMMENT 1
#define COMMENT_BLOCK 2

void removeComments(char text[]);

int main(){
  int c, i;
  char text[MAX_LENGTH];

  i = 0;
  while(i < MAX_LENGTH - 1 && (c = getchar()) != EOF){
    text[i] = c;
    ++i;
  }
  text[i] = '\0';

  removeComments(text);
  printf("\nNO comments code:\n\n%s\n", text);
  return 0;
}

void removeComments(char text[]){
  int readingIndex, copyingIndex, commentMode;
  readingIndex = copyingIndex = 0;
  commentMode = NO_COMMENT;

  while(text[readingIndex] != '\0'){
    if (text[readingIndex] == '/' && text[readingIndex + 1] == '/'){
      commentMode = LINE_COMMENT;
    }
    if (text[readingIndex] == '/' && text[readingIndex + 1] == '*'){
      commentMode = COMMENT_BLOCK;
    }
    if (commentMode == NO_COMMENT) {
      text[copyingIndex] = text[readingIndex];
      ++copyingIndex;
    } else if (commentMode == LINE_COMMENT && text[readingIndex] == '\n'){
      commentMode = NO_COMMENT;
    } else if (commentMode == COMMENT_BLOCK && text[readingIndex] == '/' && text[readingIndex - 1] == '*'){
      commentMode = NO_COMMENT;
    }
    ++readingIndex;
  }
  text[copyingIndex] = '\0';
}