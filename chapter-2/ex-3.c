#include <stdio.h>

int htoi(char s[]);

int main(){
  printf("\nTest with string 245\n");
  printf("Result: %d\n", htoi("245"));
  return 0;
}

int htoi(char s[]){
  int i, j, startIndex, result, current;
  
  startIndex = result = 0;
  if (s[0] != '\0' && s[1] != '\0' && s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) startIndex = 2;
  i = startIndex;
  while(s[i] != '\0'){
    if (s[i] >= '0' && s[i] <= '9') current = s[i] - '0';
    else if (s[i] >= 'a' && s[i] <= 'f') current = s[i] - 'a' + 10;
    else if (s[i] >= 'A' && s[i] <= 'F') current = s[i] - 'A' + 10;
    else printf("Invalid hex cahracter: %d\n", s[i]);

    result = result * 16 + current;
    ++i;
  }

  return result;
}