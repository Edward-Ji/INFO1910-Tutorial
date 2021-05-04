all: terminal
terminal: terminal.o vsf.o
	gcc -o terminal terminal.o vfs.o
terminal.o: terminal.c vfs.h
	gcc -c -g terminal.c
vsf.o: vfs.c vfs.h
	gcc -c -g vfs.c
clean:
	rm terminal.o vfs.c
