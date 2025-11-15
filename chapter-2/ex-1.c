#include <stdio.h>
#include <float.h>
#include <limits.h>

int main(){
  printf("char:\n");
  printf("Bits: %d\n", CHAR_BIT);
  printf("Minimun: %d\n", CHAR_MIN);
  printf("Maximum: %d\n", CHAR_MAX);
  printf("------------\n\n");

  printf("signed char:\n");
  printf("Minimun: %d\n", SCHAR_MIN);
  printf("Maximum: %d\n", SCHAR_MAX);
  printf("------------\n\n");

  printf("unsigned char:\n");
  printf("Minimun: %d\n", 0);
  printf("Maximum: %d\n", UCHAR_MAX);
  printf("------------\n\n");

  printf("int:\n");
  printf("Minimun: %d\n", INT_MIN);
  printf("Maximum: %d\n", INT_MAX);
  printf("------------\n\n");

  printf("unsigned int:\n");
  printf("Minimun: %d\n", 0);
  printf("Maximum: %u\n", UINT_MAX);
  printf("------------\n\n");

  printf("short (int):\n");
  printf("Minimun: %d\n", SHRT_MIN);
  printf("Maximum: %d\n", SHRT_MAX);
  printf("------------\n\n");

  printf("unsigned short (int):\n");
  printf("Minimun: %d\n", 0);
  printf("Maximum: %d\n", USHRT_MAX);
  printf("------------\n\n");

  printf("long (int):\n");
  printf("Minimun: %d\n", LONG_MIN);
  printf("Maximum: %d\n", LONG_MAX);
  printf("------------\n\n");

  printf("unsigned long (int):\n");
  printf("Minimun: %d\n", 0);
  printf("Maximum: %u\n", ULONG_MAX);
  printf("------------\n\n");

  printf("float:\n");
  printf("Minimun: %.8e\n", FLT_MIN);
  printf("Maximum: %.8e\n", FLT_MAX);
  printf("------------\n\n");

  printf("double:\n");
  printf("Minimun: %.16e\n", DBL_MIN);
  printf("Maximum: %.16e\n", DBL_MAX);
  printf("------------\n\n");
}
