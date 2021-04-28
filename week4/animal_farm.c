#include <stdio.h>

typedef unsigned short count;

typedef struct
{
    size_t pork;
    size_t veal;
    size_t lamb;
    size_t milk;
    size_t eggs;
} resources;

typedef struct
{
    size_t legs;
    char* sound;
    int efficiency;
    void (*exclaim)(animal*);
    void (*work)(animal*, resources*);
} animal;

void exclaim(animal* a) {
    a->exclaim();
}

void set_exclaim(aminal* a, void (*exclaim)(aminal*)) {
    a->exclaim = exclaim;
}

void work(animal*, resources*){
    a->work();
}

void set_work(animal*, void (*work)(animal*, resources*)) {
    a->work = work;
}

void work_day(animal*, const size_t n_animals, resources*){

}

int main(int argc, char const *argv[]) {

    return 0;
}
