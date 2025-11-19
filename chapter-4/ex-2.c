#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main(){
  char string[] = "   12.323456425e+5";
  printf("\n\nDoubled number:\n%f\n", atof(string));
  return 0;
}

double atof(char s[]){
  double val;
  int sign, i, powerSign, j, power, exponent;

  for(i = 0; isspace(s[i]); ++i);
  sign = s[i] == '-' ? -1 : 1;
  if (!isdigit(s[i])) ++i;
  
  power = 0;
  val = 0;
  exponent = 0;

  while(isdigit(s[i])){
    val = 10.0 * val + (s[i++] - '0');
  }

  if(s[i] == '.'){
    ++i;
    while(isdigit(s[i])){
      val = 10.0 * val + (s[i++] - '0');
      power -= 1;
    }
  }

  if (s[i] == 'e' || s[i] == 'E'){
    ++i;
    powerSign = s[i++] == '-' ? -1 : +1;
    while(isdigit(s[i])){
      exponent += exponent * 10 + (s[i++] - '0');
    }
    power = powerSign > 0 ? power + exponent : power - exponent;
  }

  j = power;
  while(j != 0){
    if (power > 0){
      --j;
      val *= 10.0;
    } else {
      ++j;
      val /= 10.0;
    }
  }

  return sign * val;
}