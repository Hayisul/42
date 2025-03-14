/* ************************************************************ */
/*                                                              */
/*                          PRINT_BITS                          */
/*                                                              */
/*   Displays the binary representation of an unsigned char.    */
/*   For each bit, if set, prints '1'; otherwise, prints '0'.   */
/*                                                              */
/*   Usage:                                                     */
/*       ./print_bits                                           */
/*                                                              */
/*   Example Output (for given test values):                    */
/*       00000000                                               */
/*       00000001                                               */
/*       00000101                                               */
/*       00001010                                               */
/*       00101010                                               */
/*       01010101                                               */
/*       01111111                                               */
/*       10000000                                               */
/*       11111111                                               */
/*                                                              */
/* ************************************************************ */

#include <unistd.h>

// Prints unsigned char’s binary representation.
void print_bits(unsigned char octet) {
    // Iterate over each bit from MSB to LSB.
    for (int i = 7; i >= 0; i--) {
        // Check if the bit is set with AND operator and mask (1 << i).
        if (octet & (1 << i)) // Isolates the bit at position i in octet.
            write(1, "1", 1);
        else
            write(1, "0", 1);
    }
}

int main(void) {
    // Test values for print_bits.
    unsigned char test_values[] = {0, 1, 5, 10, 42, 85, 127, 128, 255};
    int size = sizeof(test_values) / sizeof(test_values[0]);

    // Iterate over each test value, printing its binary representation.
    for (int i = 0; i < size; i++) {
        print_bits(test_values[i]);
        write(1, "\n", 1);
    }
    return (0);
}
