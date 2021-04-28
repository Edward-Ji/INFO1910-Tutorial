#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#define BUFFER_SIZE 128

int main(int argc, char const *argv[]) {

    char string[BUFFER_SIZE];

    size_t bytes = read(0, string, BUFFER_SIZE);
    // read does not add '\0'

    write(1, string, bytes);
    // only prints read content

    return 0;
}
