#!/bin/bash

#g++ -std=c++11 -I../logging insertion_sort.cpp -o insertion_sort
#g++ -std=c++11 -I../logging insertion_sort_bug_01.cpp -o insertion_sort_bug_01
#g++ -std=c++11 -I../logging insertion_sort_bug.cpp -o insertion_sort_bug
g++ -std=c++11 -I../logging sortings_3_home.cpp -o sortings_3_home
g++ -std=c++11 -I../logging sortings_4_home.cpp -o sortings_4_home

#./insertion_sort
#./insertion_sort_bug_01
#./insertion_sort_bug
./sortings_3_home
./sortings_4_home


#rm ./insertion_sort
#rm ./insertion_sort_bug_01
#rm ./insertion_sort_bug
rm ./sortings_3_home
rm ./sortings_4_home
