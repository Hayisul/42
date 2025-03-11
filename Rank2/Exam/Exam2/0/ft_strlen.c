/* *********************************************************** */
/*                                                             */
/*                        FT_STRLEN                            */
/*                                                             */
/*      Calculates and returns the length of a string.         */
/*                                                             */
/*    Usage:                                                   */
/*      ./ft_strlen "hello"                                    */
/*                                                             */
/*    Output:                                                  */
/*      5                                                      */
/*                                                             */
/* *********************************************************** */

#include <stdio.h>
#include <unistd.h>

// Calculates the length of a string.
int ft_strlen(char *str) {
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

// Main function demonstrating ft_strlen usage.
int main(int argc, char **argv) {
    if (argc == 2)
        printf("%d\n", ft_strlen(argv[1]));
    return (0);
}
