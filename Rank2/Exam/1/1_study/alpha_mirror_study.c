// Expected files   : alpha_mirror.c
// Allowed functions: write
// --------------------------------------------------------------------------------
//
// Write a program called alpha_mirror that takes a string and displays this string
// after replacing each alphabetical character by the opposite alphabetical
// character, followed by a newline.
//
// 'a' becomes 'z', 'Z' becomes 'A'
// 'd' becomes 'w', 'M' becomes 'N'
//
// and so on.
//
// Case is not changed.
//
// If the number of arguments is not 1, display only a newline.

int main(int argc, char **argv)
{
    int i;
    char *str;
    char c;

    if (argc == 2)
    {
        i = 0;
        str = argv[1];
        while (str[i])
        {
            if (str[i] >= 'a' && str[i] <= 'z')
                c = 'z' - (str[i] - 'a');
            else if (str[i] >= 'A' && str[i] <= 'Z')
                c = 'Z' - (str[i] - 'A');
            else
                c = str[i];
            write(1, &c, 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}