
#include <stdio.h>
#include <string.h>

char *ft_strpbrk(const char *s1, const char *s2);

int main(void)
{
    printf("ft_strpbrk(\"hello\", \"aeiou\") = %s\n", ft_strpbrk("hello", "aeiou"));
    printf("strpbrk(\"hello\", \"aeiou\") = %s\n", strpbrk("hello", "aeiou"));
    
    printf("ft_strpbrk(\"hello\", \"xyz\") = %s\n", ft_strpbrk("hello", "xyz"));
    printf("strpbrk(\"hello\", \"xyz\") = %s\n", strpbrk("hello", "xyz"));
    
    printf("ft_strpbrk(\"hello\", \"\") = %s\n", ft_strpbrk("hello", ""));
    printf("strpbrk(\"hello\", \"\") = %s\n", strpbrk("hello", ""));
    
    printf("ft_strpbrk(\"\", \"aeiou\") = %s\n", ft_strpbrk("", "aeiou"));
    printf("strpbrk(\"\", \"aeiou\") = %s\n", strpbrk("", "aeiou"));

    return 0;
}