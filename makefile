all: main.o
	gcc -o program main.o
main.o: main.c final.h
	gcc -c main.c
