all: main
main: main.o strlib.o
	gcc -o main main.o strlib.o
main.o: main.c strlib.h
	gcc -c -g main.c
strlib.o: strlib.c strlib.h
	gcc -c -g strlib.c
clean:
	rm main.o strlib.o
