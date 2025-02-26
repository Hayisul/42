// Expected files   : rev_print.c
// Allowed functions: write
// --------------------------------------------------------------------------------
//
// Write a program that takes a string,
// and displays the string in reverse followed by a newline.
//
// If the number of parameters is not 1, the program displays a newline.

#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    char    *str;

    if (argc == 2)
    {
        i = 0;
        str = argv[1];
        while (str[i])
            i++;
        while (i > 0)
            write(1, &str[--i], 1);
    }
    write(1, "\n", 1);
    return (0);
}