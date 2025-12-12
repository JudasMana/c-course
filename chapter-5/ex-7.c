#include <stdio.h>
#include <string.h>

#define MAX_LINES 500
#define MAX_LINE_LENGTH 100

int pGetline(char *s, int lim);
int readlines(char memory[], char *lineptr[], int lim);
void writelines(char *lineptr[], int nlines);

char *lineptr[MAX_LINES];

int main(){
  char memory[MAX_LINE_LENGTH * MAX_LINES];
  int nlines;
  if ((nlines = readlines(memory, lineptr, MAX_LINES)) >= 0) {
    printf("\n\n");
    writelines(lineptr, nlines); 
    return 0; 
  } else { 
    printf("error: input too big to sort\n"); 
    return 1; 
  }
}

int readlines(char memory[], char *lineptr[], int lim){
  int len;
  int nlines = 0;
  int index = 0;
  char line[MAX_LINE_LENGTH];

  while((len = pGetline(line, MAX_LINE_LENGTH)) > 0){
    if (nlines >= lim) return -1;
    else {
      line[len - 1] = '\0';
      strcpy(memory + index, line);
      lineptr[nlines++] = memory + index; 
      index += len;
    }
  }
  return nlines;
}

int pGetline(char *s, int lim){
  int c;
  char *startingS = s;
  while(s - startingS < lim - 1 && (c = getchar()) != EOF && c != '\n') *s++ = c;
  if (c == '\n') *s++ = c;
  *s = '\0';
  return s - startingS;
}

void writelines(char *lineptr[], int nlines){
  while(nlines-- > 0) printf("%s\n", *lineptr++);
}