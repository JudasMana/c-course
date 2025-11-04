#include <stdio.h>

#define MAX_CHARACTERS 200
#define CHARACTER_TO_BE_ADDED 0
#define CHARACTER_PRESENT 1


int main(){
  int c, i, characterCounter, characterState;
  int characterList[MAX_CHARACTERS];
  int characterCounts[MAX_CHARACTERS];

  characterCounter = 0;

  for (i = 0; i < MAX_CHARACTERS; ++i){
    characterCounts[i] = 0;
    characterList[i] = '\n';
  }

  while ((c = getchar()) != '\n'){
    characterState = CHARACTER_TO_BE_ADDED;
    for (i = 0; i < MAX_CHARACTERS; ++i){
      if (characterList[i] == c) {
        ++characterCounts[i];
        characterState = CHARACTER_PRESENT;
      }
    }
    if (characterState == CHARACTER_TO_BE_ADDED){
      ++characterCounter;
      characterList[characterCounter - 1] = c;
      characterCounts[characterCounter - 1] = 1;
    }
  }

  for (i = 0; i < MAX_CHARACTERS; ++i){
    if (characterList[i] != '\n'){
      printf("%c - ", characterList[i]);
      for (int j = 0; j < characterCounts[i]; ++j){
        printf("X");
      }
      printf("\n");
    }
  }
}