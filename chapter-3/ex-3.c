#include <stdio.h>

#define MAX_LENGTH 1000

void expand(char s1[], char s2[]);

int main(){
  char str1[MAX_LENGTH], str2[MAX_LENGTH];
  int c, i = 0;

  while((c = getchar()) != EOF){
    str1[i] = c;
    ++i;
  }
  str1[i] = '\0';

  expand(str1, str2);
  printf("\nExpanded string: \n%s\n", str2);
  return 0;
}

void expand(char s1[], char s2[]){
  int i, j;
  for(i = 0, j =0; s1[i] != '\0' && i < MAX_LENGTH - 1 && j < MAX_LENGTH - 1; ++i){
    if(s1[i + 1] == '-' &&
       s1[i] <= s1[i + 2] && 
       (s1[i] >= 'a' && s1[i+2] <= 'z' || s1[i] >= '0' && s1[i+2] <= '9' || s1[i] >= 'A' && s1[i+2] <= 'Z')
    ){
      for (int z = 0; z + j < MAX_LENGTH - 1 && z < s1[i + 2] - s1[i]; ++z){
        s2[j++] = s1[i] + z;
      }
      ++i;
    } else s2[j++] = s1[i];
  }
}