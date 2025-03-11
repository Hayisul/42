// Expected files	: ft_strspn.c
// Allowed functions: None
// ---------------------------------------------------------------
//
// Reproduce exactly the behavior of the strspn function 
// (man strspn).

#include <stddef.h>

size_t	ft_strspn(const char *s, const char *accept)
{
    size_t  i = 0;
    size_t  count = 0;

    while (*s)
    {
        while (accept[i] && *s != accept[i])
            i++;
        if (accept[i] == '\0')
            return (count);
        i = 0;
        count++;
        s++;
    }
    return (count);
}

/*
#include <stdio.h>

int main(void)
{
    printf("%zu\n", ft_strspn("hello", "he"));
    printf("%zu\n", ft_strspn("hello", "abc"));
    printf("%zu\n", ft_strspn("hello", "lohe"));
    printf("%zu\n", ft_strspn("hello", ""));
    printf("%zu\n", ft_strspn("", "abc"));
    return 0;
}
*/