// Expected files   : ft_strcpy.c
// Allowed functions: 
// --------------------------------------------------------------------------------
//
// Reproduce the behavior of the function strcpy (man strcpy).

char    *ft_strcpy(char *s1, char *s2)
{
    char    *dest;

    dest = s1;
    while(*s2)
        *s1++ = *s2++;
    *s1 = '\0';
    return (dest);
}

/*
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    char *str = malloc(sizeof(char) * 100);
    printf("ft_strcpy(\"%s\", str) = %s\n", argv[1], ft_strcpy(str, argv[1]));
    free(str);
    return(0);
}
*/

/*
The strcpy() function in C copies the content of the source string (src)
into the destination string (dest), including the null terminator (\0).
It requires that dest has enough space to hold the contents of src,
or it may cause undefined behavior.
*/