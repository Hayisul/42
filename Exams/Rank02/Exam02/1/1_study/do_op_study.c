// Expected files   : do_op.c
// Allowed functions: atoi, printf, write
// --------------------------------------------------------------------------------
//
// Write a program that takes three strings:
// - The first and the third one are representations
// of base-10 signed integers that fit in an int.
// - The second one is an arithmetic operator chosen from: + - * / %
//
// The program must display the result of the requested arithmetic operation,
// followed by a newline. If the number of parameters is not 3,
// the program just displays a newline.
//
// You can assume the string have no mistakes or extraneous characters.
// Negative numbers, in input or output, will have one and only one leading '-'.
// The result of the operation fits in an int.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int n1;
    int n2;
    int res;

    if (argc == 4)
    {
        n1 = atoi(argv[1]);
        n2 = atoi(argv[3]);
        if (argv[2][0] == '+')
            res = n1 + n2;
        else if (argv[2][0] == '-')
            res = n1 - n2;
        else if (argv[2][0] == '*')
            res = n1 * n2;
        else if (argv[2][0] == '/')
        {
            if (n2 == 0)
            {
                write(1, "Error\n", 6);
                return (0);
            }
            res = n1 / n2;
        }
        else if (argv[2][0] == '%')
        {
            if (n2 == 0)
            {
                write(1, "Error\n", 6);
                return (0);
            }
            res = n1 % n2;
        }
        printf("%d\n", res);
        return (0);
    }
    else
    {
        write(1, "\n", 1);
        return (0);
    }
}