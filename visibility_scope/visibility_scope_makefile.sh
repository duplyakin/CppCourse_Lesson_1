#!/bin/bash



g++ -std=c++11 visibility_scope_5.cpp -o visibility_scope_5
g++ -std=c++11 visibility_scope_5_new.cpp -o visibility_scope_5_new
g++ -std=c++11 visibility_scope_6.cpp -o visibility_scope_6
g++ -std=c++11 visibility_scope_6_new.cpp -o visibility_scope_6_new
g++ -std=c++11 visibility_scope_7.cpp -o visibility_scope_7
g++ -std=c++11 visibility_scope_7_new.cpp -o visibility_scope_7_new



./visibility_scope_5
./visibility_scope_5_new
./visibility_scope_6
./visibility_scope_6_new
./visibility_scope_7
./visibility_scope_7_new


