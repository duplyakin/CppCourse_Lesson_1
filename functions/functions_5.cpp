/*5. Implement iterative function for Factorial calculation.*/

#include "logger.h"

void print(const int string) {
  INF("Print: %d", string);
}

int factorial(int N) {
  if (N == 0) {
    return 1;
  }
  return N * factorial(N - 1);
}


int myfactorial(int n) {
   int i, a = 1; 
   int c = 1;
   for (i = 0; i < n; i++) {
      c = c*a;
      a++;
   }
   return c;
}



int main(int argc, char** argv) {

  DBG("[Lesson 1]: Functions 4");

  for(int i=0; i<10; i++){
  	print(myfactorial(i));
  }
  printf("CHECK: \n");
   for(int i=0; i<10; i++){
  	print(factorial(i));
  }

  DBG("[Lesson 1]: Functions 4 [END]");
  return 0;
}



