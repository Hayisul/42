/* **************************************************************** */
/*                                                                  */
/*                           SWAP_BITS                              */
/*                                                                  */
/*   Swaps the upper and lower 4-bit nibbles of an unsigned char.   */
/*   For example, if octet is represented as ABCD EFGH in binary,   */
/*   the function returns EFGH ABCD.                                */
/*                                                                  */
/*   Usage:                                                         */
/*       ./swap_bits                                                */
/*                                                                  */
/*   Example Output:                                                */
/*       swap_bits(0) = 0                                           */
/*       swap_bits(1) = 16                                          */
/*       swap_bits(5) = 80                                          */
/*       swap_bits(10) = 160                                        */
/*       swap_bits(42) = 162                                        */
/*       swap_bits(85) = 85                                         */
/*       swap_bits(127) = 247                                       */
/*       swap_bits(128) = 8                                         */
/*       swap_bits(255) = 255                                       */
/*                                                                  */
/* **************************************************************** */

#include <assert.h>
#include <stdio.h>

// Swaps the upper and lower 4-bit nibbles of an unsigned char.
unsigned char swap_bits(unsigned char octet) {
    // Shift the upper 4 bits to the right and the lower 4 bits to the left.
    return ((octet >> 4) | (octet << 4));
}

int main(int argc, char **argv) {
    unsigned char test_values[] = {0, 1, 5, 10, 42, 85, 127, 128, 255};
    int size = sizeof(test_values) / sizeof(test_values[0]);

    // Iterate over each test value and print its swapped bits.
    for (int i = 0; i < size; i++) {
        // Print the swapped bits.
        printf("swap_bits(%d) = %d\n", test_values[i], swap_bits(test_values[i]));
        // Swapping the bits twice should yield the original value.
        assert(test_values[i] == swap_bits(swap_bits(test_values[i])));
    }
    return (0);
}