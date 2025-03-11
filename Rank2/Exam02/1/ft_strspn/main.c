
#include <stdio.h>

size_t ft_strspn(const char *s, const char *accept);

int main(void)
{
    printf("%zu\n", ft_strspn("hello", "he"));       // 2
    printf("%zu\n", ft_strspn("hello", "abc"));      // 0
    printf("%zu\n", ft_strspn("hello", "lohe"));     // 5
    printf("%zu\n", ft_strspn("hello", ""));         // 0
    printf("%zu\n", ft_strspn("", "abc"));           // 0
    return 0;
}