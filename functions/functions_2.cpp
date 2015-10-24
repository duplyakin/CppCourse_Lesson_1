/*
2. Implement swap() function:

This function takes two arguments (say, representing integer values) and
swap their values. Compare the result with standard std::swap() function
from <algorithms> header.

void swap(int*, int* )
swap(&a, &b)
*/

#include "logger.h"

void print(const int string) {
  INF("Print: %d", string);
}


void swap(int* a, int* b){
  int c = *a;
  *a = *b;
  *b = c;
}


int main(int argc, char** argv) {

  int a = 5;
  int b = 6;
  DBG("[Lesson 1]: Functions 2");

  
  print(a);
  print(b);
  swap(&a, &b);
  print(a);
  print(b);
  DBG("[Lesson 1]: Functions 2 [END]");
  return 0;
}

