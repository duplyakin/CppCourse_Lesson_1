#include "logger.h"
/*
Проблема в том, что size_t в данном случае - это unsigned long int, поэтому когда мы пытаемся сравнить i с нулём, то будет непредвиденное поведение. Если i станет раным нулю и если после этого его уменьшить на единицу, то i не станет равынм -1 --- i станет положительным числом. 
*/
namespace sort {

void insertion(int array[], size_t size) {
  for (size_t j = 1; j < size; ++j) {
    int key = array[j];
    size_t i = j - 1;
    //printf("sizeof(i)=%ld, i=%ld;\n ", sizeof(i), i);
    while (i > 0 && array[i] > key) {
      array[i + 1] = array[i];
      /*printf("Key = %d, New itteration number %ld and array[%ld] = %d:\n",key, i, i, array[i] );
      if (i>0){
      	printf("\nBUG, i<0\n");
      }
      for(int k=0; k<size; k++){
        printf("%d ",array[k]);
      }
      printf("\n");
      */
      
      i--;
    }
    array[i + 1] = key;
    /*printf("ИТОГ: Key = %d, New itteration number %d and array[%d] = %d:\n",key, i, i, array[i] );
      for(int k=0; k<size; k++){
        printf("%d ",array[k]);
      }
    printf("\n");*/
  }
}

}

void print(int array[], size_t size) {
  for (size_t i = 0; i < size; ++i) {
    printf("%i ", array[i]);
  }
  printf("\n");
}

int main(int argc, char** argv) {
  DBG("[Lesson 1]: Sortings: Insertion sort bug");
  //printf("sizeof(int)=%d\n", sizeof(int) );
  //printf("sizeof(long)=%d\n", sizeof(long) );

  int array[10] = {5, 8, 1, 12, -4, -7, 3, 5, 9, 0};
  print(array, 10);
  INF("After sorting");
  sort::insertion(array, 10);
  print(array, 10);




  DBG("[Lesson 1]: Sortings: Insertion sort bug [END]");
  return 0;
}
