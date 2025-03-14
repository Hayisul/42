// Expected files	: ft_strpbrk.c
// Allowed functions: None
// ---------------------------------------------------------------
//
// Reproduce exactly the behavior of the function strpbrk
// (man strpbrk).

#include <stdio.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
    int i = 0;

    if (!s1 || !s2)
        return (NULL);
    while (*s1)
    {
        i = 0;
        while (s2[i])
        {
            if (*s1 == s2[i])
                return ((char *)s1);
            i++;
        }
    s1++;
    }
    return (NULL);
}

/*
int main()
{
    char str[] = "hello, world";
    char chars[] = "aeiou";

    char *result = strpbrk(str, chars);
    printf("First matching character: %c\n", *result); // Output: e

    return 0;
}
*/