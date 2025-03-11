/* ******************************************************** */
/*                                                          */
/*                      FT_STRCPY                           */
/*                                                          */
/*   Copies the string pointed to by s2 into s1,            */
/*   including the terminating null byte.                   */
/*                                                          */
/*   Usage:                                                 */
/*     ./ft_strcpy "hello"                                  */
/*                                                          */
/*   Output:                                                */
/*     hello                                                */
/*                                                          */
/* ******************************************************** */

#include <stdio.h>
#include <stdlib.h>

// Copies string s2 into s1 and returns s1.
char    *ft_strcpy(char *s1, char *s2) {
    char *dest = s1;

    while (*s2)
        *s1++ = *s2++;
    *s1 = '\0';
    return (dest);
}

int main(int argc, char **argv) {
    if (argc == 2) {
        char *str = (char *)malloc(sizeof(char) * 100);
        if (!str)
            return (1);
        printf("%s\n", ft_strcpy(str, argv[1]));
        free(str);
    }
    return (0);
}
