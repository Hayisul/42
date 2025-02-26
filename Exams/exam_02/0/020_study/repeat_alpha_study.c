// Expected files   : repeat_alpha.c
// Allowed functions: write
// --------------------------------------------------------------------------------
//
// Write a program called repeat_alpha that takes a string
// and display it repeating each alphabetical character
// as many times as its alphabetical index, followed by a newline.
//
// 'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...
//
// Case remains unchanged.
//
// If the number of arguments is not 1, just display a newline.

int main(int argc, char **argv)
{
    int i;
    int c;
    char    *str;

    if (argc == 2)
    {
        i = 0;
        str = argv[1];
        while (str[i])
        {
            c = 1;
            if (str[i] >= 'A' && str[i] <= 'Z')
                c = str[i] - 'A' + 1;
            if (str[i] >= 'a' && str[i] <= 'z')
                c = str[i] - 'a' + 1;
            while (c > 0)
            {
                write(1, &str[i], 1);
                c--;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}