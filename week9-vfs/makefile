all: terminal
test: test.o vsf.o
	gcc -o test test.o vfs.o
terminal: terminal.o vsf.o
	gcc -o terminal terminal.o vfs.o
test.o: test.c vfs.h
	gcc -c -g test.c
terminal.o: terminal.c vfs.h
	gcc -c -g terminal.c
vsf.o: vfs.c vfs.h
	gcc -c -g vfs.c
clean:
	rm terminal.o vfs.c
