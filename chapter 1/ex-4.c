#include <stdio.h>

int main(){
  printf("This is a Celsius to Fahrenheit conversion program!\n\n");

  float cels, fahr;
  int start, end, step;

  start = 0;
  end = 200;
  step = 20;

  while(cels <= end){
    fahr = (cels * (9.0/5.0)) + 32;
    printf("%3.0f\t%6.1f\n", cels, fahr);
    cels = cels + step;
  } 
}