/*
4. Make pivot selection in quicksort randomized.
Compare time performance with non-randomized quicksort
and std::sort().
*/

#include <algorithm>
#include "logger.h"
#include <ctime>


int generateElement() {
  return rand() % 100 + 1;
}
int generateSize() {
  return rand() % 50000 + 1;
}

namespace sort {



//nonrandomised pivot
//------------------------------------------------------------------
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
    size_t q = partition(array, p, r);
    quicksort(array, p, q);
    quicksort(array, q + 1, r);
  }
}

void quicksort(int array[], size_t size) { 
  quicksort(array, 0, size);
}
//---------------------------------------------------------------------

//randomised pivot
//------------------------------------------------------------------


int partition1(int array[], int p, int r) {
  
  int pivot = array[p];
  int i = p - 1;
  int j = r + 1;
  while(true) 
  {
  	do {
  		j = j - 1;
  	} while (array[j] > pivot);
  	do {
  		i = i + 1;
  	} while (array[i] < pivot);
  	if (i < j) 
  		std::swap(array[i], array[j]);
  	else 
  		return j;
  }
}

int partitionRand(int array[], int p, int r) {
  int k = rand() % (r - p) + p; // Rand(p,r)
  std::swap(array[k], array[p]);
  return partition1(array, p, r);
}

void quicksortRand(int array[], int p, int r) {
  if (p < r) {
    int q = partitionRand(array, p, r); 
    quicksortRand(array, p, q); 
    quicksortRand(array, q + 1, r);
   
  }
}

void quicksortRand(int array[], int size) { 
  quicksortRand(array, 0, size - 1);
}


}

void print(int array[], size_t size) {
  for (size_t i = 0; i < size; ++i) {
    printf("%i ", array[i]);
  }
  printf("\n");
}

void unitTest() {
  

  clock_t start = clock();
  clock_t elapsed = start;
  while ((elapsed - start) < 5 * CLOCKS_PER_SEC) { 
    int size = generateSize();
    int array1[size];
    int array2[size]; 
    

    for (int i = 0; i < size; i++) {
      array1[i] = generateElement()%(2*40)-20;
      array2[i] = array1[i];  
    }

    DBG("%i", size);

    sort::quicksort(array1, size);
    sort::quicksortRand(array2, size);

    for (int i=0; i < size; ++i) {
      if (array1[i] != array2[i]) {
        ERR("Error: randomized and nonrandomised sortings give different results");
        break;
      }
    }
    INF("OK. randomized sorting gives the same result as nonrandomised sorting: %i", size);
    elapsed = clock();
  }
}


struct Score {
  long int array1_wins;
  long int array2_wins;
};


void performanceTest() {
  struct Score score;
  score.array1_wins = 0;
  score.array2_wins = 0;
  

  clock_t start = clock();
  clock_t elapsed = start;
  while ((elapsed - start) < 5 * CLOCKS_PER_SEC) { 
    int size = generateSize();
    int array1[size];
    int array2[size];

    for (int i = 0; i < size; i++) {
      array1[i] = generateElement()%(2*40)-20;
      array2[i] = array1[i];  
    }

    DBG("%i", size);

    clock_t sort1_start = clock();
    sort::quicksort(array1, size);
    clock_t sort1_elapsed = clock();

    clock_t sort2_start = clock();
    sort::quicksortRand(array2, size);
    clock_t sort2_elapsed = clock();

    double array2_time = static_cast<double>(sort2_elapsed - sort2_start) / CLOCKS_PER_SEC;
    double array1_time = static_cast<double>(sort1_elapsed - sort1_start) / CLOCKS_PER_SEC; 
    if (array1_time < array2_time) 
      ++score.array1_wins;
    else 
      ++score.array2_wins;

    elapsed = clock();
  }
  INF("Score: non-randomized quicksort is faster in [%ld] cases, randomized quicksort is faster in [%ld] cases", score.array1_wins, 
    score.array2_wins);
}


int main(int argc, char** argv) {
  DBG("[Lesson 1]: Sortings: sortings_4_home");
 
  unitTest();
  printf("Введите любой символ:");
  getchar();
  performanceTest();
 
  DBG("[Lesson 1]: Sortings: sortings_4_home [END]");
  return 0;
}

