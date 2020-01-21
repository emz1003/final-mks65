all: main.o shell.o gameplay.o interface.o
	gcc -o program main.o shell.o gameplay.o interface.o

main.o: main.c final.h
	gcc -c main.c final.h

shell.o: shell.c final.h
	gcc -c shell.c

gameplay.o: gameplay.c final.h
	gcc -c gameplay.c

interface.o: interface.c final.h
	gcc -c interface.c

run:
	./program

clean:
	rm output *.o *.gch
