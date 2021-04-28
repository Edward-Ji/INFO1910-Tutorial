#include <fcntl.h>
#include <stdio.h>

void printb(int n) {

    int i, k;
    size_t bits = sizeof(n);

    for (i = bits; i >= 0; i--)
    {
        if (n & (1 << i))
            printf("1");
        else
            printf("0");
    }

    printf("\n");
}

int main(int argc, char const *argv[]) {

    int oflags[] = {
                    O_RDONLY,        // open for reading only
                    O_WRONLY,        // open for writing only
                    O_RDWR,          // open for reading and writing
                    O_NONBLOCK,      // do not block on open or for data to become available
                    O_APPEND,        // append on each write
                    O_CREAT,         // create file if it does not exist
                    O_TRUNC,         // truncate size to 0
                    O_EXCL,          // error if O_CREAT and the file exists
                    O_SHLOCK,        // atomically obtain a shared lock
                    O_EXLOCK,        // atomically obtain an exclusive lock
                    O_NOFOLLOW,      // do not follow symlinks
                    O_SYMLINK,       // allow open of symlinks
                    O_EVTONLY,       // descriptor requested for event notifications only
                    O_CLOEXEC,       // mark as close-on-exec
                    O_NOFOLLOW_ANY   // do not follow symlinks in the entire path.}
                   };

    for (int i = 0; i < 15; i++) {
        printb(oflags[i]);
    }

    return 0;
}
