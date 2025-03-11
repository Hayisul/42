// Expected files   : ft_strlen.c
// Allowed functions:
// --------------------------------------------------------------------------------
//
// Write a function that returns the length of a string.

int	ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

/*
#include <stdio.h>

int main(int argc, char **argv) {
    if (argc == 2)
        printf("%d\n", ft_strlen(argv[1]));
    return (0);
}
*/