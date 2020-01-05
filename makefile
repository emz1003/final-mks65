all: main.o shell.o
	gcc -o program main.o shell.o

main.o: main.c final.h
	gcc -c main.c final.h

shell.o: shell.c final.h
	gcc -c shell.c

run:
	./program

clean:
	rm output *.o *.gch
