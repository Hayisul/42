// Expected files   : rev_wstr.c
// Allowed functions: write, malloc, free
// --------------------------------------------------------------------------------
//
// Write a program that takes a string as a parameter,
// and prints its words in reverse order.
//
// A "word" is a part of the string bounded by spaces and/or tabs,
// or the begin/end of the string.
//
// If the number of parameters is different from 1, the program will display '\n'.
//
// In the parameters that are going to be tested, there won't be any "additional" spaces
// (meaning that there won't be additionnal spaces at the beginning or 
// at the end of the string, and words will always be separated by exactly one space).

#include <unistd.h>
#include <stdlib.h>

void	rev_wstr(char *str)
{
	int i = 0;
	int j;
	int first_word = 1;

	while (str[i] != '\0')
		++i;

	while (i >= 0)
	{
		while (i >= 0 && (str[i] == '\0' || str[i] == ' ' || str[i] == '\t'))
			--i;
		j = i;
		while (j >= 0 && str[j] != ' ' && str[j] != '\t')
			--j;
		if (first_word == 0)
			write(1, " ", 1);
		write(1, str + j + 1, i - j);
		first_word = 0;
		i = j;
	}
}