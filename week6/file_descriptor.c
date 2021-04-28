#include <stdio.h>

// open requires
#include <fcntl.h>

// read/write requires
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#include <string.h>

#define BUFFER_SIZE 128

int main(int argc, char const *argv[]) {

    // open file
    int fd = open("test.txt", O_RDWR);

    // write a string to file
    char *string = "Bye!!";
    write(fd, string, strlen(string));

    // reset cursor to beginning of file
    lseek(fd, 0, SEEK_SET);

    // read content of defined buffer length
    char buffer[BUFFER_SIZE];
    read(fd, buffer, BUFFER_SIZE);
    printf("%s\n", buffer);

    // close file
    close(fd);

    return 0;
}
