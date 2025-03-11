// Expected files   : ft_putstr.c
// Allowed functions: write
// --------------------------------------------------------------------------------
//
// Write a function that displays a string on the standard output.
//
// The pointer passed to the function contains the address of the string's first character.

#include <unistd.h>

void    ft_putstr(char *str)
{
    while (*str)
        write(1, str++, 1);
}

/*
int main(void)
{
    ft_putstr("Hello World!\n");
    return (0);
}
*/