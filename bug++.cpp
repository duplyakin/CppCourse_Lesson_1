#include <cstdlib>
#include "logger.h"

void print(int* array, size_t size) {
  for (size_t i = 0; i < size; ++i) {
    printf("%i ", i[array]);
  }
  printf("\n");
}

void copy(int source[], int destination[], size_t size) {
  for (size_t i = 0; i < size; ++i) {
    *(destination++) = *(source++);
//a++ - снчалала возвращает значние, потом переменная увеличивается
//Если развернуть цикл, то получится так: 
//*(destination) = *(source);  --- нулевой элмемент копируется
//*(destination+1) = *(source+1);
//*(destination+2) = *(source+2);


//++a - сначала увеличивается, потом возвращается значение
//Если развернуть цикл, то получится так: 
//*(destination+1) = *(source+1); --- нулевой элемент не копируется
//*(destination+2) = *(source+2);
//*(destination+3) = *(source+3);
  }
}

int main(int argc, char** argv) {
  //DBG("[Lesson 1]: Arrays 7");

  int* A = new int[10];
  int* B = new int[10];
  
  for (size_t i = 0; i < 10; ++i) {
    A[i] = std::rand() % 100 + 1;
  }

  copy(A, B, 10);
  print(A, 10);
  print(B, 10);

  delete [] A;
  delete [] B;

  //DBG("[Lesson 1]: Arrays 7 [END]");
  return 0;
}

