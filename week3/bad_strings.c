#include <stdio.h>

#define bad_string size_t
// size_t is eight bytes long!

/*
* str_print
* Prints our "bad" string
* :: const BAD_STRING str :: The "string" to print
* Returns nothing, but prints to standard output
*/
void str_print(const bad_string str) {
    printf("%s\n", (char*) &str);
};

/*
* byte_place
* Places a character at a given byte position in our "string"
* :: bad_string str :: Our current string
* :: const char character :; The character to place
* :: size_t position :: the position to place the character
* Returns a new "bad_string" with the character placed
* in the correct position
*/
bad_string byte_place(
    bad_string str,
    const char character,
    const size_t position) {
        *((char*) &str + position) = character;
        return str;
    };

int main() {

    bad_string str = 0;

    str_print(str);

    str = byte_place(str, 'a', 0);
    str_print(str);

    str = byte_place(str, 'b', 1);
    str_print(str);

    str = byte_place(str, 'c', 2);
    str_print(str);

    return 0;
}
