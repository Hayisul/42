// Expected files   : ulstr.c
// Allowed functions: write
// --------------------------------------------------------------------------------
//
// Write a program that takes a string and reverses the case of all its letters.
// Other characters remain unchanged.
//
// You must display the result followed by a '\n'.
//
// If the number of arguments is not 1, the program displays '\n'.

#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    char    *str;
    char    c;

    if (argc == 2)
    {
        i = 0;
        str = argv[1];
        while (str[i])
        {
            if (str[i] >= 'a' && str[i] <= 'z')
                c = str[i] - 32;
            else if (str[i] >= 'A' && str[i] <= 'Z')
                c = str[i] + 32;
            else
                c = str[i];
            write(1, &c, 1);
            i++;
        }        
    }
    write(1, "\n", 1);
    return (0);
}