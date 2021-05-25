all: clear main.o sort.o
	gcc -o main main.o sort.o

clear:
	clear

main.o: main.c sort.h
	gcc -g -c main.c
sort.o: sort.c sort.h
	gcc -g -c sort.c

clean:
	rm *.o
