// Expected files   : ft_strcmp.c
// Allowed functions:
// --------------------------------------------------------------------------------
//
// Reproduce the behavior of the function strcmp (man strcmp).

int ft_strcmp(char *s1, char *s2)
{
    int i = 0;

    while(s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc == 3)
        printf("ft_strcmp(\"%s\", \"%s\") = %d\n", argv[1], argv[2], ft_strcmp(argv[1], argv[2]));
    return(0);
}
*/