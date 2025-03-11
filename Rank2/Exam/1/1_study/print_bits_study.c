// Expected files   : print_bits.c
// Allowed functions: write
// --------------------------------------------------------------------------------
//
// Write a function that takes a byte, and prints it in binary
// WITHOUT A NEWLINE AT THE END.

void    print_bits(unsigned char octet)
{
    for  (int i = 7; i >= 0; i--)
    {
        if (octet & (1 << i))
            write(1, "1", 1);
        else
            write(1, "0", 1);
    }
}

/*
#include <unistd.h>

void print_bits(unsigned char octet);

int main(void)
{
    unsigned char test_values[] = {0, 1, 5, 10, 42, 85, 127, 128, 255};
    int size = sizeof(test_values) / sizeof(test_values[0]);

    for (int i = 0; i < size; i++)
    {
        print_bits(test_values[i]);
        write(1, "\n", 1);  // Newline for better readability
    }

    return 0;
}
*/

/*
            ================ BREAKDOWN ================
i	1 << i (Binary)     octet & (1 << i)	                Output
7	10000000	        00000101 & 10000000 → 00000000      0
6	01000000	        00000101 & 01000000 → 00000000	    0
5	00100000	        00000101 & 00100000 → 00000000	    0
4	00010000	        00000101 & 00010000 → 00000000	    0
3	00001000	        00000101 & 00001000 → 00000000	    0
2	00000100	        00000101 & 00000100 → 00000100	    1
1	00000010	        00000101 & 00000010 → 00000000	    0
0	00000001	        00000101 & 00000001 → 00000001	    1
*/