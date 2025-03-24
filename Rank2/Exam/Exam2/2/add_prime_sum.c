/* ***************************************************************** */
/*                                                                   */
/*                           ADD_PRIME_SUM                           */
/*                                                                   */
/*   Calculates the sum of all prime numbers up to a given number.   */
/*   If the input number is less than or equal to 0, prints 0.       */
/*                                                                   */
/*   Usage:                                                          */
/*       ./add_prime_sum <number>                                    */
/*                                                                   */
/*   Example Output:                                                 */
/*       For input 5, output: 10 (2 + 3 + 5 = 10)                    */
/*                                                                   */
/* ***************************************************************** */

#include <unistd.h>

// Converts a string to an integer.
int ft_atoi(char *str) {
    int n = 0;
    
    while (*str >= '0' && *str <= '9') {
        n *= 10;
        n += *str - '0';
        str++;
    }
    return n;
}

// Recursively prints an integer to standard output.
void ft_putnbr(int n) {
    if (n >= 10)
        ft_putnbr(n / 10);
    char c = (n % 10) + '0';
    write(1, &c, 1);
}

// Checks if n is a prime number; returns 1 if true, 0 if false.
int is_prime(int n) {
    int i = 2;
    
    if (n < 2)
        return 0;
    while (i * i <= n) {
        if (n % i == 0)
            return 0;
        i++;
    }
    return 1;
}

// Sums all prime numbers up to n.
int add_prime_sum(int n) {
    int sum = 0;
    int i = 2;
    
    while (i <= n) {
        if (is_prime(i))
            sum += i;
        i++;
    }
    return sum;
}

int main(int argc, char **argv) {
    int n;
    
    if (argc == 2 && (n = ft_atoi(argv[1])) > 0)
        ft_putnbr(add_prime_sum(n));
    else
        ft_putnbr(0);
    write(1, "\n", 1);
    return (0);
}