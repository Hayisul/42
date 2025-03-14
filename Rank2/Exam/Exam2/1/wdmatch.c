/* **************************************************************** */
/*                                                                  */
/*                              WDMATCH                             */
/*                                                                  */
/*   Checks if the first string is a subsequence of the second.     */
/*   A subsequence means that all characters in the first string    */
/*   appear in the second string in the same order.                 */
/*   If it is a subsequence, the program prints the first string.   */
/*                                                                  */
/*   Usage:                                                         */
/*       ./wdmatch "abc" "ahbgdc"                                   */
/*                                                                  */
/*   Example Output:                                                */
/*       abc                                                        */
/*                                                                  */
/* **************************************************************** */

#include <unistd.h>

int main(int ac, char **av) {
    if (ac == 3) {
        int i = 0;
        int j = 0;

        // Iterate through both strings.
        while (av[1][i] && av[2][j]) {
            // If the characters match, increment the first string index.
            if (av[1][i] == av[2][j])
                i++;
            // Increment the second string index.
            j++;
        }

        // If we've reached the end of av[1], it's a subsequence of av[2].
        if (av[1][i] == '\0') {
            // Print the first string.
            for (i = 0; av[1][i]; i++)
                write(1, &av[1][i], 1);
        }
    }
    write(1, "\n", 1);
    return (0);
}