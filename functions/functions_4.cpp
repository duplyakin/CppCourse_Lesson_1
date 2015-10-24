/*
4. Implement iterative function for Fibonacci calculation.
Нужно сделать итеративный алгоритм. 
fact(){
  N*fact()
}
*/

#include "logger.h"

void print(const int string) {
  INF("Print: %d", string);
}

int fibonacci(int N) {
  if (N == 0 || N == 1) {
    return 1;
  }
  return fibonacci(N - 1) + fibonacci(N - 2);
}


int fib(int n) {
   int i, a = 0, b = 1; 
   int c;
   for (i = 0; i < n; i++) {
      c = a + b;
      a = b;
      b = c;
   }
   return b;
}



int main(int argc, char** argv) {

  DBG("[Lesson 1]: Functions 4");

  for(int i=0; i<10; i++){
  	print(fib(i));
  }
  printf("CHECK: \n");
   for(int i=0; i<10; i++){
  	print(fibonacci(i));
  }

  DBG("[Lesson 1]: Functions 4 [END]");
  return 0;
}



