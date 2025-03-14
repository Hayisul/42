// Expected files   : last_word.c
// Allowed functions: write
// --------------------------------------------------------------------------------
//
// Write a program that takes a string and displays its last word followed by a \n.
//
// A word is a section of string delimited by spaces/tabs
// or by the start/end of the string.
//
// If the number of parameters is not 1, or there are no words, display a newline.

#include <unistd.h>

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int i;
        char *str;

        i = 0;
        str = av[1];
        while (str[i])
            i++;
        i--;
        while ((str[i] == ' ' || str[i] == '\t') && i != 0)
            i--;
        while (str[i] != ' ' && str[i] != '\t' && i != 0)
            i--;
        if (str[i] == ' ' || str[i] == '\t')
            i++;
        while (str[i] && str[i] != ' ' && str[i] != '\t')
        {
            write(1, &str[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}