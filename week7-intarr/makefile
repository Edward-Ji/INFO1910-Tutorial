all: main
main: main.o intarr.o
	gcc -o main main.o intarr.o
main.o: main.c intarr.h
	gcc -c -g main.c
intarr.o: intarr.c intarr.h
	gcc -c -g intarr.c
clean:
	rm main.o intarr.o
