// Expected files   : inter.c
// Allowed functions: write
// --------------------------------------------------------------------------------
//
// Write a program that takes two strings and displays, without doubles,
// the characters that appear in both strings, in the order they appear in the first one.
//
// The display will be followed by a \n.
//
// If the number of arguments is not 2, the program displays \n.

#include <unistd.h>

int already_printed(char *str, char c, int pos)
{
    int i = 0;
    while (i < pos)
        if (str[i++] == c)
            return 1;
    return 0;
}

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        char *s1 = argv[1];
        char *s2 = argv[2];
        int i = 0;
        while(s1[i])
        {
            if (!already_printed(s1, s1[i], i))
            {
                int j = 0;
                while (s2[j])
                {
                    if (s1[i] == s2[j])
                    {
                        write(1, &s1[i], 1);
                        break;
                    }
                    j++;
                }
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}