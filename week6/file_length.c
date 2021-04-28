#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#define BUFFER_SIZE 128

int main(int argc, char const *argv[]) {

    const char *fname = "test.txt";

    int fd = open(fname, O_RDONLY);
    if (!fd) {
        printf("Fail to open the file.\n");
        return 1;
    }

    off_t bytes = 0;
    bytes = lseek(fd, 0, SEEK_END);

    switch (bytes) {
        case 0:
            printf("The file is empty.\n");
            break;
        case 1:
            printf("There is 1 byte in the file.\n");
            break;
        default:
            printf("There are %lld bytes in the file.\n", bytes);
    }

    return 0;
}
