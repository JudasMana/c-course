#include <stdio.h>

int main(){
  printf("This is a Fahrenheit to Celsius conversion program!\n\n");
  float cels, fahr;
  int start, end, step;

  start = 0;
  end = 200;
  step = 20;

  while(fahr <= end){
    cels = (5.0/9.0) * (fahr - 32.0);
    printf("%3.0f\t%6.1f\n", fahr, cels);
    fahr = fahr + step;
  }
}