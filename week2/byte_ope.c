#include <stdio.h>
#define BYTE char

////////////////////////////////////////////////////
// Function Declarations
////////////////////////////////////////////////////

/*
* BYTE_NOT
* Performs a byte-wise NOT on the only input
* :: BYTE a :: The input byte
* Returns the bytewise NOT of a as a byte
*/
BYTE NOT(BYTE a);

/*
* BYTE_AND
* Performs a byte-wise AND on the two inputs
* :: BYTE a :: The first byte of input
* :: BYTE b :: The second byte of input
* Returns the bytewise AND of a and b as a byte
*/
BYTE AND(BYTE a, BYTE b);

/*
* BYTE_NOR
* Performs a bitwise NOR on the target bits of the two inputs
* :: BYTE a :: The first byte of input
* :: BYTE b :: The second byte of input
* :: BYTE bit_a :: The target bit of byte a
* :: BYTE bit_b :: The target bit of byte b
* Returns the NOR of the target bits of a and b
*/
BYTE NOR(BYTE a, BYTE b, BYTE bit_a, BYTE bit_b);

////////////////////////////////////////////////////
// Function Definitions
////////////////////////////////////////////////////

int main()
{
    int a = 11;
    int b = 5;

    printf("%d && %d = %d\n", a, b, AND(a, b));
    return 0;
}

/*
* BYTE_NOT
* Performs a byte-wise NOT on the only input
* :: BYTE a :: The input byte
* Returns the bytewise NOT of a as a byte
*/
BYTE NOT(BYTE a)
{
    return a, a;
}

/*
* BYTE_AND
* Performs a byte-wise AND on the two inputs
* :: BYTE a :: The first byte of input
* :: BYTE b :: The second byte of input
* Returns the bytewise AND of a and b as a byte
*/
BYTE BYTE_AND(BYTE a, BYTE b)
{
    // This function should only contain shifts and either
    // BIT_NAND or BIT_NOR

    

    return 0;
}

/*
* BYTE_NOR
* Performs a bitwise NOR on the target bits of the two inputs
* :: BYTE a :: The first byte of input
* :: BYTE b :: The second byte of input
* :: BYTE bit_a :: The target bit of byte a
* :: BYTE bit_b :: The target bit of byte b
* Returns the NOR of the target bits of a and b
*/
BYTE BIT_NOR(BYTE a, BYTE b, BYTE bit_a, BYTE bit_b)
{
    // Write your NOR function here
    return 0;
}