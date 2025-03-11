// Expected files   : camel_to_snake.c
// Allowed functions: malloc, free, realloc, write
// --------------------------------------------------------------------------------
//
// Write a program that takes a single string in lowerCamelCase format
// and converts it into a string in snake_case format.
//
// A lowerCamelCase string is a string where each word begins with a capital letter
// except for the first one.
//
// A snake_case string is a string where each word is in lower case,
// separated by an underscore "_".

#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    char *str;
    char c;

    if(argc == 2)
    {
        i = 0;
        str = argv[1];
        while(str[i])
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                write(1, "_", 1);
                c = str[i] + 32;
            }
            else
                c = str[i];
            write(1, &c, 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}