rm *.out
clear
g++ -Wall -pg -O0 -g -c -o Stack_test.o Stack_test.cpp
g++ -Wall -pg -O0 -g -c -o cMemory.o ../List/cMemory.c
g++ -Wall -pg -O0 -g -c -o Stack.o Stack.cpp
g++ -Wall -pg -O0 -g -o Test Stack_test.o cMemory.o Stack.o
./Test

