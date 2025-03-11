// Expected files   : first_word.c
// Allowed functions: malloc, free, realloc, write
// --------------------------------------------------------------------------------
//
// Write a program that takes a string and displays its first word, followed by a newline.
//
// A word is a section of string delimited by spaces/tabs or by the start/end of the string.
//
// If the number of parameters is not 1, or if there are no words, simply display a newline.

#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    int i;
    char    *str;

    if (argc == 2)
    {
        i = 0;
        str = argv[1];
        while (str[i] == ' ' || str[i] == '\t')
            i++;
        while (str[i] && str[i] != ' ' && str[i] != '\t')
       {
            ft_putchar(str[i]);
            i++;
       }
    }
    ft_putchar('\n');
    return (0);
}