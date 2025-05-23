// Expected files   : epur_str.c
// Allowed functions: write
// --------------------------------------------------------------------------------
//
// Write a program that takes a string, and displays this string
// with exactly one space between words, with no spaces or tabs
// either at the beginning or the end, followed by a \n.
//
// A "word" is defined as a part of a string delimited either by spaces/tabs,
// or by the start/end of the string.
//
// If the number of arguments is not 1, or if there are no words to display,
// the program displays \n.

#include <unistd.h>

int		skip_whitespace(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t')
		++i;
	return (i);
}

int		ft_wordlen(char *str)
{
	int i = 0;

	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
		++i;
	return (i);
}

void	epur_str(char *str)
{
	int i = 0;
	int first_word = 1;
	int word_len;

	i = skip_whitespace(str, i);
	while (str[i] != '\0')
	{
		if (first_word == 0)
			write(1, " ", 1);
		word_len = ft_wordlen(str + i);
		write(1, str + i, word_len);
		i = i + word_len;
		first_word = 0;
		i = skip_whitespace(str, i);
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		epur_str(argv[1]);
	write(1, "\n", 1);
	return (0);
}