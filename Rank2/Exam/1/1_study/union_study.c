// Expected files   : union.c
// Allowed functions: write
// --------------------------------------------------------------------------------
//
// Write a program that takes two strings and displays, without doubles,
// the characters that appear in either one of the strings.
//
// The display will be in the order characters appear in the command line,
// and will be followed by a \n.
//
// If the number of arguments is not 2, the program displays \n.

#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        int ascii[256] = {0};
        
        for (int i = 1; i < 3; i++)
        {
            int j = 0;
            while (argv[i][j])
            {
                if (ascii[(unsigned char)argv[i][j]] == 0)
                {
                    ascii[(unsigned char)argv[i][j]] = 1;
                    write(1, &argv[i][j], 1);
                }
                j++;
            }
        }
    }
    write(1, "\n", 1);
    return (0);
}