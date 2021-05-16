all: clear main.o bintree.o
	gcc -o main bintree.o main.o
clear:
	clear
main: main.o
	gcc -o main main.o
main.o: main.c bintree.h
	gcc -g -c main.c
bintree.o: bintree.c bintree.h
	gcc -g -c bintree.c
clean:
	rm main.o bintree.o
