#include <stdio.h>

int main(){
  int c;
  float bn, tn, nn;

  while((c = getchar()) != EOF){
    if (c == '\b') ++bn;
    if (c == '\n') ++nn;
    if (c == '\t') ++tn;
  }
  printf("Number of blanks: %.0f\n", bn);
  printf("Number of tabs: %.0f\n", tn);
  printf("Number of newlines: %.0f\n", nn);
}