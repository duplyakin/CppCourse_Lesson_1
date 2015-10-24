/*
3. Implement some function, which returns 3 different values from it.
*/

#include "logger.h"

void print(const int string) {
  INF("Print: %d", string);
}



int sumAndSwap(int* a, int* b){
  int c = *a;
  *a = *b;
  *b = c;
  return (*a + *b);
}

int main(int argc, char** argv) {

  int a = 5;
  int b = 6;
  int sum = 0;
  DBG("[Lesson 1]: Functions 3");

  print(sum);
  print(a);
  print(b);
  sum = sumAndSwap(&a, &b);
  print(sum);
  print(a);
  print(b);
  DBG("[Lesson 1]: Functions 3 [END]");
  return 0;
}

