#!/bin/bash

g++ -std=c++11 -I../logging functions_1.cpp -o functions_1
g++ -std=c++11 -I../logging functions_2.cpp -o functions_2
g++ -std=c++11 -I../logging functions_3.cpp -o functions_3
g++ -std=c++11 -I../logging functions_4.cpp -o functions_4
g++ -std=c++11 -I../logging functions_5.cpp -o functions_5

./functions_1 1031
./functions_2
./functions_3
./functions_4
./functions_5

rm ./functions_1
rm ./functions_2
rm ./functions_3
rm ./functions_4
rm ./functions_5