// Expected files   : is_power_of_2.c
// Allowed functions: None
// --------------------------------------------------------------------------------
//
// Write a function that determines if a given number is a power of 2.
//
// This function returns 1 if the given number is a power of 2, otherwise it returns 0.

int is_power_of_2(unsigned int n)
{
    return (n > 0) && ((n & (n - 1)) == 0);
}

/*
#include <stdio.h>

int main(void)
{
    unsigned int test_cases[] = {0, 1, 2, 4, 8, 16, 31, 32, 64, 127, 128, 255, 256, 1024, 2048, 4096, 8192, 16384};
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    
    for (int i = 0; i < num_tests; i++)
    {
        printf("%d\n", is_power_of_2(test_cases[i]));
    }
    return 0;
}
*/