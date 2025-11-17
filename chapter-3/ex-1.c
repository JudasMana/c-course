#include <stdio.h>

int binarySearch(int num, int arr[], int arrLength);

int main(){
  int sortedArray[3] = {1, 2, 3};
  int num = 2;
  int index = binarySearch(num, sortedArray, 3);
  printf("Result: %d\n", index);

  return 0;
}

int binarySearch(int num, int arr[], int arrLength){  
  int low = 0;
  int high = arrLength - 1;
  int currIndex = (low + high) / 2;
  while(low <= high){
    if (arr[currIndex] > num) high = currIndex - 1;
    else low = currIndex + 1;
    currIndex = (low + high) / 2;
  }
  return arr[currIndex] == num ? currIndex : -1;
}