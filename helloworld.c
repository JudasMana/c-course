#include <stdio.h>
#include <string.h>

int main(){
  printf("Select an instruction between add or subtract:\n");
  char instruction[100];
  scanf("%s", &instruction);

  int num1;
  printf("Type first number:\n");
  scanf("%d", &num1);
  printf("\n");

  int num2;
  printf("Type second number:\n");
  scanf("%d", &num2);
  printf("\n");

  if (strcmp(instruction, "subtract") == 0){
    printf("Result: %d\n", num1 - num2);
  } else if (strcmp(instruction, "add") == 0){
    printf("Result: %d\n", num1 + num2);
  }

  return 0;
}