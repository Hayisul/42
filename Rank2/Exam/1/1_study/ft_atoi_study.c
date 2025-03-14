// Expected files   : ft_atoi.c
// Allowed functions: None
// --------------------------------------------------------------------------------
//
// Write a function that converts the string argument str to an integer (type int)
// and returns it.
//
// It works much like the standard atoi(const char *str) function, see the man.

#include <limits.h>

int ft_atoi(const char *str)
{
    int i = 0;
    int sig = 1;
    int res = 0;

    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
            str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sig= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (res * sig);
}

/*
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    printf("ft_atoi(\"%s\") = %d\n", argv[1], ft_atoi(argv[1]));
    return(0);
}
*/