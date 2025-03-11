// Expected files   : reverse_bits.c
// Allowed functions:
// --------------------------------------------------------------------------------
//
// Write a function that takes a byte, reverses it,
// bit by bit (like the example) and returns the result.

unsigned char reverse_bits(unsigned char octet)
{
    unsigned char res = 0;

    for (int i = 0; i < 8; i++)
    {
        res = (res << 1) | (octet & 1);
        octet >>= 1;
    }
    return res;
}

/*
#include <stdio.h>

void print_bits(unsigned char octet)
{
    for (int i = 7; i >= 0; i--)
        printf("%c", (octet & (1 << i)) ? '1' : '0');
}

int main(void)
{
    unsigned char test_values[] = {0, 1, 5, 10, 42, 85, 127, 128, 255};
    int size = sizeof(test_values) / sizeof(test_values[0]);

    for (int i = 0; i < size; i++)
    {
        printf("Original:  ");
        print_bits(test_values[i]);
        printf("  (%d)\n", test_values[i]);

        printf("Reversed:  ");
        print_bits(reverse_bits(test_values[i]));
        printf("  (%d)\n\n", reverse_bits(test_values[i]));
    }

    return 0;
}
*/

/*
            ================ BREAKDOWN ================
Step	octet % 2   res = res * 2 + (octet % 2)     octet = octet / 2
1	    1 (LSB)	    0 * 2 + 1 = 1 (00000001)	    00000010 (2)
2	    0	        1 * 2 + 0 = 2 (00000010)	    00000001 (1)
3	    1	        2 * 2 + 1 = 5 (00000101)	    00000000 (0)
4	    0	        5 * 2 + 0 = 10 (00001010)	    00000000 (0)
5	    0	        10 * 2 + 0 = 20 (00010100)	    00000000 (0)
6	    0	        20 * 2 + 0 = 40 (00101000)	    00000000 (0)
7	    0	        40 * 2 + 0 = 80 (01010000)	    00000000 (0)
8	    0	        80 * 2 + 0 = 160 (10100000)	    00000000 (0)
*/