#include <stdio.h>

float getCelsius(int fahr);

int main(){
  int start, end, step;

  start = 0;
  end = 300;
  step = 20;

  while(start <= end){
    printf("%3d %6.1f\n", start, getCelsius(start));
    start = start + step;
  }

  return 0;
}

float getCelsius(int fahr){
  return (5.0/9.0)*(fahr-32);
}