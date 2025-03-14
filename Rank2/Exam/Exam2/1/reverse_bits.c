/* ******************************************************** */
/*                                                          */
/*                        REVERSE_BITS                      */
/*                                                          */
/*   Reverses the bits of an unsigned char.                 */
/*   For each bit, if set, clears it; otherwise, sets it.   */
/*                                                          */
/*   Usage:                                                 */
/*       ./reverse_bits                                     */
/*                                                          */
/*   Example Output:                                        */
/*       reverse_bits(0) = 0                                */
/*       reverse_bits(1) = 128                              */
/*       reverse_bits(5) = 160                              */
/*       reverse_bits(10) = 80                              */
/*       reverse_bits(42) = 84                              */
/*       reverse_bits(85) = 170                             */
/*       reverse_bits(127) = 254                            */
/*       reverse_bits(128) = 1                              */
/*       reverse_bits(255) = 255                            */
/*                                                          */
/* ******************************************************** */

#include <assert.h>
#include <stdio.h>

// Reverses the bits of the given unsigned char.
unsigned char reverse_bits(unsigned char octet) {
    unsigned char res = 0;
    
    // Iterates over each bit from LSB to MSB.
    for (int i = 0; i < 8; i++) {
        // Shifts res to the left and adds the LSB of octet.
        res = (res << 1) | (octet & 1);
        // Shifts octet to the right.
        octet >>= 1;
    }
    return (res);
}

int main(void) {
    // Test values for reverse_bits.
    unsigned char test_values[] = {0, 1, 5, 10, 42, 85, 127, 128, 255};
    int size = sizeof(test_values) / sizeof(test_values[0]);

    for (int i = 0; i < size; i++) {
        // Prints the result of reverse_bits.
        printf("reverse_bits(%d) = %d\n", test_values[i], reverse_bits(test_values[i]));
        // Reversing the bits twice should yield the original value.
        assert(test_values[i] == reverse_bits(reverse_bits(test_values[i])));
    }
    return (0);
}