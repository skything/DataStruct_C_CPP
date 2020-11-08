rm *.out
clear
g++ -Wall -pg -O0 -g -c -o Queue_test.o Queue_test.cpp
g++ -Wall -pg -O0 -g -c -o cMemory.o ../List/cMemory.c
g++ -Wall -pg -O0 -g -c -o Queue.o Queue.cpp
g++ -Wall -pg -O0 -g -o Test Queue_test.o cMemory.o Queue.o
./Test

