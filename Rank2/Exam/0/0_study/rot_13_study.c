// Expected files   : rot_13.c
// Allowed functions: write
// --------------------------------------------------------------------------------
//
// Write a program that takes a string and displays it, replacing each of its letters
// by the letter 13 spaces ahead in alphabetical order.
//
// 'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.
//
// The output will be followed by a newline.
//
// If the number of arguments is not 1, the program displays a newline.

#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    char    *str;
    char    c;

    if (argc ==2)
    {
        i = 0;
        str = argv[1];
        while (str[i])
        {
            if ((str[i] >= 'a' && str[i] <= 'm') || (str[i] >= 'A' && str[i] <= 'M'))
                c = str[i] + 13;
            else if ((str[i] >= 'n' && str[i] <= 'z') || (str[i] >= 'N' && str[i] <= 'Z'))
                c = str[i] - 13;
            else
                c = str[i];
            write(1, &c, 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}