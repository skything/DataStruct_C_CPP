rm *.out
clear
g++ -Wall -pg -O0 -g -c -o List_test.o List_test.cpp
g++ -Wall -pg -O0 -g -c -o cMemory.o cMemory.c
g++ -Wall -pg -O0 -g -c -o List.o List.cpp
g++ -Wall -pg -O0 -g -o Test List_test.o cMemory.o List.o
./Test

