// Expected files   : ft_itoa.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------
//
// Write a function that takes an int and converts it to a null-terminated string.
// The function returns the result in a char array that you must allocate.

#include <stdlib.h>

int absolute_value(int nbr)
{
    if (nbr < 0)
        return (-nbr);
    return (nbr);
}

int get_len(int nbr)
{
    int len = 0;
    if (nbr <= 0)
        len++;
    while (nbr)
    {
        len++;
        nbr /= 10;
    }
    return (len);
}

char *ft_itoa(int nbr)
{
    char *result;
    int len;
    long num;

    num = nbr;
    len = get_len(nbr);
    result = malloc(sizeof(char) * (len + 1));
    if (!result)
        return (NULL);
    result[len] = '\0';

    if (nbr < 0)
    {
        result[0] = '-';
        num = -num;
    }
    else if (nbr == 0)
        result[0] = '0';

    while (num)
    {
        result[--len] = (num % 10) + '0';
        num /= 10;
    }
    return (result);
}

/*
#include <stdio.h>

int main(int argc, char **argv)
{
    printf("%s\n", ft_itoa(atoi(argv[1])));
    free(ft_itoa(atoi(argv[1])));
    return (0);
}
*/