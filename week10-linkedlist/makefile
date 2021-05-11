all: clear main.o linkedlist.o
	gcc -o main linkedlist.o main.o
clear:
	clear
main: main.o
	gcc -o main main.o
main.o: main.c linkedlist.h
	gcc -g -c main.c
linkedlist.o: linkedlist.c linkedlist.h
	gcc -g -c linkedlist.c
clean:
	rm main.o linkedlist.o
