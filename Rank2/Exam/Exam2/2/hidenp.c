/* ************************************************************ */
/*                                                              */
/*                             HIDENP                           */
/*                                                              */
/*   Checks if all characters of the first string (probe) are   */
/*   present in the second string (target) in the same order.   */
/*   Prints "1" if true, "0" otherwise.                         */
/*                                                              */
/*   Usage:                                                     */
/*       ./hidenp "abc" "2a3b4c"                                */
/*                                                              */
/*   Example Output:                                            */
/*       1                                                      */
/*                                                              */
/* ************************************************************ */

#include <unistd.h>

// Checks if the probe's characters are in the target in the same order.
void hidenp(char *probe, char *target) {
    // Iterate over each character in the probe string.
    while (*probe) {
        // Advance target until a matching character is found.
        while (*target && *target != *probe)
            target++;
        if (*target == '\0') {
            write(1, "0", 1);
            return;
        }
        // Move to the next character in both strings.
        target++;
        probe++;
    }
    write(1, "1", 1);
}

int main(int argc, char **argv) {
    if (argc == 3)
        hidenp(argv[1], argv[2]);
    write(1, "\n", 1);
    return (0);
}