// Expected files   : ft_strrev.c
// Allowed functions:
// --------------------------------------------------------------------------------
//
// Write a function that reverses (in-place) a string.
//
// It must return its parameter. 

char    *ft_strrev(char *str)
{
    int i = -1;
    int len = 0;
    char temp;

    while (str[len])
        len++;
    while (++i < len / 2)
    {
        temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
    return (str);
}

/*
#include <stdio.h>

int main(void)
{
    char str1[] = "hello";
    char str2[] = "world!";
    char str3[] = "";
    char str4[] = "a";

    printf("Original: %s | Reversed: %s\n", str1, ft_strrev(str1)); // "olleh"
    printf("Original: %s | Reversed: %s\n", str2, ft_strrev(str2)); // "!dlrow"
    printf("Original: %s | Reversed: %s\n", str3, ft_strrev(str3)); // ""
    printf("Original: %s | Reversed: %s\n", str4, ft_strrev(str4)); // "a"

    return 0;
}
*/