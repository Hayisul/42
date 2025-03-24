/* *************************************************************** */
/*                                                                 */
/*                        RSTR_CAPITALIZER                         */
/*                                                                 */
/*   Capitalizes the last letter of each word and lowercases all   */
/*   other letters in the provided string. A word is defined as    */
/*   a sequence of non-space/tab characters.                       */
/*                                                                 */
/*   Usage:                                                        */
/*       ./rstr_capitalizer "Hello WORLD"                          */
/*                                                                 */
/*   Example Output:                                               */
/*       hellO worlD                                               */
/*                                                                 */
/* *************************************************************** */

#include <unistd.h>

void str_capitalizer(char *str) {
    while (*str) {
        // Write any leading spaces or tabs.
        while (*str && (*str == ' ' || *str == '\t')) {
            write(1, str, 1);
            str++;
        }
        // Process the word.
        while (*str && *str != ' ' && *str != '\t') {
            // If the character is lowercase and it's the last letter of the word, capitalize it.
            if (*str >= 'a' && *str <= 'z' && (*(str + 1) == '\0' 
					|| *(str + 1) == ' ' || *(str + 1) == '\t'))
                *str -= 32;
            // Else if the character is uppercase and not the last letter, convert it to lowercase.
            else if (*str >= 'A' && *str <= 'Z' && *(str + 1) 
                     && *(str + 1) != ' ' && *(str + 1) != '\t')
                *str += 32;
            write(1, str, 1);
            str++;
        }
    }
    write(1, "\n", 1);
}

int main(int argc, char **argv) {
    if (argc == 1)
        write(1, "\n", 1);
    else {
        for (int i = 1; i < argc; i++)
            str_capitalizer(argv[i]);
    }
    return (0);
}