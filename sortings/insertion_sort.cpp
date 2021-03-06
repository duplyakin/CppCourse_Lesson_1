#include "logger.h"

namespace sort {

void insertion(int array[], size_t size) {
  for (size_t j = 1; j < size; ++j) {
    int key = array[j];
    int i = j - 1;
    while (i > 0 && array[i] > key) {
      array[i + 1] = array[i];
      /*printf("Key = %d, New itteration number %d and array[%d] = %d:\n",key, i, i, array[i] );
      for(int k=0; k<size; k++){
        printf("%d ",array[k]);
      }
      printf("\n");*/
      
      --i;
    }
    //printf("end of while\n");
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
  DBG("[Lesson 1]: Sortings: Insertion sort 1");

  int array[10] = {5, 8, 1, 12, -4, -7, 3, 5, 9, 0};
  print(array, 10);
  INF("After sorting");
  sort::insertion(array, 10);
  print(array, 10);

  DBG("[Lesson 1]: Sortings: Insertion sort 1 [END]");
  return 0;
}

