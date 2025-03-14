/* *********************************************************** */
/*                                                             */
/*                     IS_POWER_OF_2                           */
/*                                                             */
/*   Checks if a given unsigned integer is a power of 2.       */
/*   A number is a power of 2 if it is greater than 0 and      */
/*   its binary representation contains exactly one bit set.   */
/*                                                             */
/*   Usage:                                                    */
/*       ./is_power_of_2                                       */
/*                                                             */
/*   Example Output (for given test cases):                    */
/*       0                                                     */
/*       1                                                     */
/*       1                                                     */
/*       1                                                     */
/*       1                                                     */
/*       1                                                     */
/*       0                                                     */
/*       1                                                     */
/*       1                                                     */
/*       0                                                     */
/* *********************************************************** */

#include <stdio.h>

// A power of 2 has exactly one bit set, so (n & (n - 1)) should equal 0.
int is_power_of_2(unsigned int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main(void) {
    // Test cases for is_power_of_2.
    unsigned int test_cases[] = {0, 1, 2, 4, 8, 16, 31, 32, 64, 127};
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    // Iterate over each test case and print the result.
    for (int i = 0; i < num_tests; i++)
        printf("%d\n", is_power_of_2(test_cases[i]));
    return (0);
}