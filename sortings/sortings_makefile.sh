#!/bin/bash

g++ -std=c++11 -I../logging insertion_sort.cpp -o insertion_sort
#g++ -std=c++11 -I../logging insertion_sort_bug_01.cpp -o insertion_sort_bug_01
g++ -std=c++11 -I../logging insertion_sort_bug.cpp -o insertion_sort_bug

./insertion_sort
#./insertion_sort_bug_01
./insertion_sort_bug

rm ./insertion_sort
#rm ./insertion_sort_bug_01
rm ./insertion_sort_bug
