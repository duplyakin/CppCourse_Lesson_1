//3. Eliminate tail recusion in case of quicksort.
#include <algorithm>
#include "logger.h"

namespace sort {

size_t partition(int array[], size_t p, size_t r) {
  int pivot = array[r - 1];
  size_t i = p;

  for (size_t j = p + 1; j < r; ++j) {
    if (array[j - 1] <= pivot) {
      ++i;
      std::swap(array[i - 1], array[j - 1]);
    }
  }
  std::swap(array[i], array[r - 1]);
  return i;
}

void quicksort(int array[], size_t p, size_t r) {
  if (p < r) {
    size_t q = partition(array, p, r);//pivot //(quicksort, array, 4)(quicksort, array, 0, 4)(partition, array, 0, 4)... - NOT LAST
    quicksort(array, p, q);//сортируется всё, что слева //(quicksort, array, 4)(quicksort, array, 0, 4)(quicksort, array, 0, 2)... - NOT LAST
    //quicksort(array, q + 1, r);//сортируется всё, что справа //(quicksort, array, 4)(quicksort, array, 0, 4)(quicksort, array, 3, 4)... - LAST - 
    //хвостовая рекурсия. 
    //----------------------------
    if (q+1<r) {
      size_t old_q = q;
      size_t q = partition(array, old_q+1, r);
      quicksort(array, old_q+1, q);
    }
    //----------------------------
  }
}

void quicksort(int array[], size_t size) { //(quicksort, array, 4)
  quicksort(array, 0, size);//(quicksort, array, 4)(quicksort, array, 0, 4)
}

}

void print(int array[], size_t size) {
  for (size_t i = 0; i < size; ++i) {
    printf("%i ", array[i]);
  }
  printf("\n");
}

int main(int argc, char** argv) {
  DBG("[Lesson 1]: Sortings: sortings_3_home");

  int array[20] = {5, 8, 1, 12, -4, -7, 3, 5, 9, 0, 17, -4, -8, 11, 3, 7, 6, -11, -9, 2};
  print(array, 20);
  INF("After sorting");
  sort::quicksort(array, 20);//пусть размер массива 4. Стек фрейм:(адрес функции, параметры) (quicksort, array, 4)
  print(array, 20);

  DBG("[Lesson 1]: Sortings: sortings_3_home [END]");
  return 0;
}

