// Expected files   : search_and_replace.c
// Allowed functions: write, exit
// --------------------------------------------------------------------------------
//
// Write a program called search_and_replace that takes 3 arguments,
// the first argument is a string in which to replace a letter (2nd argument)
// by another one (3rd argument).
//
// If the number of arguments is not 3, just display a newline.
//
// If the second argument is not contained in the first one (the string)
// then the program simply rewrites the string followed by a newline.

#include <unistd.h>

void    search_and_replace(char *str, char s, char r)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == s)
            str[i] = r;
        write(1, &str[i++], 1);
    }
}

int main(int argc, char **argv)
{
    if (argc == 4)
        search_and_replace(argv[1], argv[2][0], argv[3][0]);
    write(1, "\n", 1);
    return (0);
}