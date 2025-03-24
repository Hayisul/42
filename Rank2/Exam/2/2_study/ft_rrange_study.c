// Expected files   : ft_rrange.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------
//
// Write a function that allocates (with malloc()) an array of integers,
// fills it with consecutive values that begins at end
// and ends at start (Including start and end !),
// then return a pointer to the first value of the array.

#include <stdlib.h>

int		*ft_rrange(int start, int end)
{
	int number_of_ints;
	int *array;
	int step;
	int i;

	number_of_ints = 1 + absolute_value(end - start);
	array = malloc(sizeof(int) * number_of_ints);

	if (start > end)
		step = 1;
	else
		step = -1;

	i = 0;
	while (i < number_of_ints)
	{
		array[i] = end;
		end = end + step;
		++i;
	}
	return (array);
}

/*
#include <stdio.h>

int absolute_value(int n)
{
    return (n < 0 ? -n : n);
}

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        printf("%d\n", ft_atoi_base(argv[1], atoi(argv[2])));
    }
    return (0);
}
*/