#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int rank;
    char file;
} position;

int rand_range(low, high) {
    return rand() % (high - low + 1) + low;
}

position rand_pos() {
    position pos;

    pos.rank = rand_range(1, 8);
    pos.file = rand_range(65, 72);

    return pos;
}

int main(int argc, char const *argv[]) {

    srand(time(0));

    position pos;
    pos = rand_pos();

    printf("%c%d\n", pos.file, pos.rank);
    
    return 0;
}
