#include <stdio.h>

void lower(char text[]);

int main(){
  char str[] = "Test Di StrInGa Con MoLTE MaiuScoLe";
  lower(str);
  printf("\nStringa minuscola: \n%s\n", str);
  return 0;
}

void lower(char text[]){
  for (int i = 0; text[i] != '\0'; ++i) text[i] = (text[i] >= 'A' && text[i] <= 'Z') ? text[i] - 'A' + 'a' : text[i];
}