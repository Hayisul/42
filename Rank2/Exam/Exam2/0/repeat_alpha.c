/* ***************************************************** */
/*                                                       */
/*                     REPEAT_ALPHA                      */
/*                                                       */
/*   For each character in the input string,             */
/*   if the character is an alphabetical letter,         */
/*   it prints the character repeated as many times      */
/*   as its position in the alphabet (A=1, B=2, etc.).   */
/*   It prints non–alphabetical characters once.         */
/*                                                       */
/*   Usage:                                              */
/*       ./repeat_alpha "Hola"                           */
/*                                                       */
/*   Example Output:                                     */
/*       HHHHHHHHooooooooooooooolllllllllllla            */
/*                                                       */
/* ***************************************************** */

#include <unistd.h>

int main(int argc, char **argv) {
    // Proceed only if exactly one argument is provided.
    if (argc == 2) {
        int i = 0;
        char *str = argv[1];

        // Iterate over each character in the string.
        while (str[i]) {
            int c = 1;  // Default repetition count for non-alphabetical characters.
            
            // If the character is an uppercase letter, determine its position (A=1, B=2, etc.).
            if (str[i] >= 'A' && str[i] <= 'Z')
                c = str[i] - 'A' + 1;
            // Else if the character is a lowercase letter, determine its position (a=1, b=2, etc.).
            else if (str[i] >= 'a' && str[i] <= 'z')
                c = str[i] - 'a' + 1;
            
            // Print the current character 'c' times.
            while (c > 0) {
                write(1, &str[i], 1);
                c--;
            }
            i++;
        }
    }
    // Print a newline at the end.
    write(1, "\n", 1);
    return (0);
}