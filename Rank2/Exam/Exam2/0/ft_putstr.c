/* ******************************************* */
/*                                             */
/*                 FT_PUTSTR                   */
/*                                             */
/*   Prints a string to the standard output.   */
/*                                             */
/*   Usage:                                    */
/*       ./ft_putstr                           */
/*                                             */
/*   Output:                                   */
/*       Hello, World!                         */
/*                                             */
/* ******************************************* */

#include <unistd.h>

// Prints a string character by character.
void    ft_putstr(char *str) {
    while (*str)
        write(1, str++, 1);
}

// Main function demonstrating the ft_putstr usage.
int main(void) {
    ft_putstr("Hello, world!\n");
    return (0);
}
