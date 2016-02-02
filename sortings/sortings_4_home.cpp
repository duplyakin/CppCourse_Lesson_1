/*
4. Make pivot selection in quicksort randomized.
Compare time performance with non-randomized quicksort
and std::sort().
*/

#include <algorithm>
#include "logger.h"
#include <ctime>


int GenerateArray() {
  srand(clock());
  return rand() % 10 + 1;
}
int GenerateSize() {
  srand(clock());
  return rand() % 100 + 1;
}
//int size = GenerateSize();


void recovery(int array[], int arrayBeforeSorting[], int size) {
	for (int i=0; i<size; i++) {
		array[i] = arrayBeforeSorting[i];
	}
}


void check(int array[], int arrayAfterRightSorting[], int size) {
	for (int i=0; i<size; i++) {
		if (array[i] != arrayAfterRightSorting[i]) {
			WRN("Randomized sorting is incorrect!");
		}
	}
	WRN("OK. Randomized sorting gives the same result as nonrandomised sorting");
}

namespace sort {

//nonrandomised pivot
//------------------------------------------------------------------
size_t partition(int array[], size_t p, size_t r) {
  int pivot = array[r - 1];
  //int pivot = array[std::rand()%r];
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
    quicksort(array, q + 1, r);//сортируется всё, что справа //(quicksort, array, 4)(quicksort, array, 0, 4)(quicksort, array, 3, 4)... - LAST - 
    //хвостовая рекурсия. 
   
  }
}

void quicksort(int array[], size_t size) { //(quicksort, array, 4)
  quicksort(array, 0, size);//(quicksort, array, 4)(quicksort, array, 0, 4)
}
//---------------------------------------------------------------------

//randomised pivot
//------------------------------------------------------------------
/*
//https://en.wikipedia.org/wiki/Quicksort --- почему то не рабоает, возможно ответ здесь: http://www.cplusplus.com/forum/general/87796/
int  Rpartition(int array[], int p, int r) {
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

void Rquicksort(int array[], int p, int r) {
  if (p < r) {
    int q = Rpartition(array, p, r); 
    Rquicksort(array, p, q); 
    Rquicksort(array, q + 1, r);
   
  }
}

void Rquicksort(int array[], int size) { 
  Rquicksort(array, 2, size);
}
*/

/*
//Почему то не работает... 
int  Rpartition(int array[], int p, int r) {
  int pivot = array[(p+r)/2];
  int i = p;//если здесь сделать size_t i = p --- то будет ошибка
  int j = r;
  do 
  {
  	while (array[i] < pivot) i++;
  	while (array[j] > pivot) j--;
  	
  	if (i <= j) {
  		if (array[i] > array[j]) std::swap(array[i], array[j]);
  		i++;
  		j--;
  	}	
  } while (i <= j);

}

void Rquicksort(int array[], int p, int r) {
   int i = p;
   int j = r;
   if (i < r)
   	Rpartition(array, i, r);
   if (p < j)
   	Rpartition(array, p, j);
}
*/


//http://forkettle.ru/vidioteka/programmirovanie-i-set/108-algoritmy-i-struktury-dannykh/sortirovka-i-poisk-dlya-chajnikov/1010-metod-khoara-bystraya-sortirovka-quick-sort
void Rquicksort(int array[], size_t first, size_t last)
{
    size_t i = first, j = last; 
    int x = array[(first + last) / 2];
  
    do {
        while (array[i] < x) i++;
        while (array[j] > x) j--;
  
        if(i <= j) {
            if (array[i] > array[j]) std::swap(array[i], array[j]);
            i++;
            j--;
        }
    } while (i <= j);
  
    if (i < last)
        Rquicksort(array, i, last);
    if (first < j)
        Rquicksort(array, first, j);
}

void Rquicksort(int array[], size_t size) { 
  Rquicksort(array, 0, size-1);
}

/*
Падает на следующих массивах: 
49 51 -12 43 59 -12 -9 48 59 -18 4 0 0 10 57 16
40 24 18 35 59 48 20 17 54 -14 50 19 5 8 17 30 -8 57 28 23 11 37 55 6 59 -8 49 -4 -3 6 24 23 59 -5 -2 29 54 37 -18
-15 -11 -16 -18 -13 

*/

//---------------------------------------------------------------------


}

void print(int array[], size_t size) {
  for (size_t i = 0; i < size; ++i) {
    printf("%i ", array[i]);
  }
  printf("\n");
}

int main(int argc, char** argv) {
  DBG("[Lesson 1]: Sortings: sortings_4_home");
  /*for(int i=0; i<100; i++) {
  	printf("%d ", std::rand()%10);
  }
  printf("\n");
  */
  int size = GenerateSize();
  int array[size];
  int arrayBeforeSorting[size];
  int arrayAfterRightSorting[size];

  for (int i=0; i<size; i++) {
  	array[i] = GenerateArray()%(2*40)-20;
  	arrayBeforeSorting[i] = array[i];
  }

  INF("Before sorting");
  print(array, size);
  INF("After nonrandomized sorting");
  sort::quicksort(array, size);
  print(array, size);
  for (int i=0; i<size; i++) {//save result after right sorting
  	arrayAfterRightSorting[i] = array[i];
  }
  //check(array, arrayAfterRightSorting, size);
  recovery(array, arrayBeforeSorting, size);//восстанавливаем первоначальное значение массива

  INF("Before sorting");
  print(array, size);
  INF("After randomized sorting");
  sort::Rquicksort(array, size);
  print(array, size);
  check(array, arrayAfterRightSorting, size);
  recovery(array, arrayBeforeSorting, size);
  
 
  //-------------------------------------------
  recovery(array, arrayBeforeSorting, size);
  INF("Time for nonrandomized sorting: ");
  clock_t start = clock();
 
  sort::quicksort(array, size);
  
  clock_t end = clock();
  int timeNonRandomozed = end-start/CLOCKS_PER_SEC;
  printf("%d\n", timeNonRandomozed);
  //-------------------------------------------
  recovery(array, arrayBeforeSorting, size);
  INF("Time for randomized sorting: ");
  start = clock();
  
  sort::Rquicksort(array, size);
  
  end = clock();
  int timeRandomozed = end-start/CLOCKS_PER_SEC;
  printf("%d\n", timeRandomozed);
  //-------------------------------------------
  printf("More effective is: ");
  if (timeRandomozed > timeNonRandomozed) {
  	printf("nonrandomised sorting\n");
  } else {
  	printf("randomized sorting\n");
  }

  DBG("[Lesson 1]: Sortings: sortings_4_home [END]");
  return 0;
}

