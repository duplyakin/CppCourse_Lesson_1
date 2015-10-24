/*
1. Revert the array:

Given an array of integers of some size, implement a function
that reverts this array. For example:

Initial array is:  [-1, 5, 2, 7, 4]
Reverted array is: [4, 7, 2, 5, -1]
*/

#include <cstdlib>
#include "logger.h"

void reverse(int array[], size_t size) {
  int* tmpArray = (int*) malloc(sizeof(int) * size);
  //printf("My dubug:\n");
  for (size_t i = 0; i < size; ++i) {
    tmpArray[size-1-i] = array[i];
  }

  for (size_t i = 0; i < size; ++i) {
    array[i]=tmpArray[i];
  }

  free(tmpArray);
  
}

void print(int array[], size_t size) {
  for (size_t i = 0; i < size; ++i) {
    printf("%i ", array[i]);
  }
  printf("\n");
}

int main(int argc, char** argv) {
  DBG("[Lesson 1]: Arrays 2");

  int* array = (int*) malloc(sizeof(int) * 10);
  
  for (size_t i = 0; i < 10; ++i) {
    array[i] = std::rand() % 100 + 1;
  }
  print(array, 10);
  reverse(array, 10);
  print(array, 10);
  free(array);

  DBG("[Lesson 1]: Arrays 2 [END]");
  return 0;
}