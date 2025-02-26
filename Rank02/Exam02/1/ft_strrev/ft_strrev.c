
char *ft_strrev(char *str)
{
	int i = -1;
	int length = 0;
	char temporary;

	while (str[length])
		length++;
	while (++i < length / 2)
	{
		temporary = str[i];
		str[i] = str[length - 1 - i];
		str[length - 1 - i] = temporary;
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