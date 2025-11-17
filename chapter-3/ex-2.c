#include <stdio.h>

#define MAX_LENGTH 1000

void escape(char s[], char t[]);
void deEscape(char s[], char t[]);

int main(){
  char str1[MAX_LENGTH], str2[MAX_LENGTH], str3[MAX_LENGTH];
  int c, i = 0;

  while((c = getchar()) != EOF && i < MAX_LENGTH - 1) str1[i++] = c;
  str1[i] = '\0';

  escape(str1, str2);
  deEscape(str1, str3);

  printf("Escaped: \n%s\n", str2);
  printf("De escaped: \n%s\n", str3);
  return 0;
}

void escape(char s[], char t[]){
  int j = 0;
  for(int i = 0; s[i] != '\0' && j < MAX_LENGTH - 1; ++i){
    switch(s[i]){
      case '\t':
        t[j++] = '\\';
        t[j++] = 't';
        break;
      case '\\':
        t[j++] = '\\';
        t[j++] = '\\';
        break;
      case '\a':
        t[j++] = '\\';
        t[j++] = 'a';
        break;
      case '\b':
        t[j++] = '\\';
        t[j++] = 'b';
        break;
      case '\n':
        t[j++] = '\\';
        t[j++] = 'n';
        break;      
      default:
        t[j++] = s[i];
    }
  }

  t[j] = '\0';
}

void deEscape(char s[], char t[]){
  int j = 0;
  for(int i = 0; s[i] != '\0'; ++i){
    switch(s[i]){
      case '\\':
        switch(s[i + 1]){
          case 't':
            t[j++] = '\t';
            ++i;
            break;
          case '\\':
            t[j++] = '\\';
            ++i;
            break;
          case 'a':
            t[j++] = '\a';
            ++i;
            break;
          case 'b':
            t[j++] = '\b';
            ++i;
            break;
          case 'n':
            t[j++] = '\n';
            ++i;
            break;
        }
        break;
      default:
        t[j++] = s[i];
        break;
    }
  }
  t[j] = '\0';
}

