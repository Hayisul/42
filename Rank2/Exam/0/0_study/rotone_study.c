// Expected files   : rotone.c
// Allowed functions: write
// --------------------------------------------------------------------------------
//
// Write a program that takes a string and displays it,
// replacing each of its letters by the next one in alphabetical order.
//
// 'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.
//
// The output will be followed by a \n.
//
// If the number of arguments is not 1, the program displays \n.

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
            if ((str[i] >= 'a' && str[i] <= 'y') || (str[i] >= 'A' && str[i] <= 'Y'))
                c = str[i] + 1;
            else if (str[i] == 'z' || str[i] == 'Z')
                c = str[i] - 25;
            else
                c = str[i];
            write(1, &c, 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}