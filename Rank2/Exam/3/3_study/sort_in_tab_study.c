// Expected files   : sort_int_tab.c
// Allowed functions: 
// --------------------------------------------------------------------------------
//
// Write a function that sorts (in-place) the 'tab' int array,
// that contains exactly 'size' members, in ascending order.
//
// Doubles must be preserved.
//
// Input is always coherent.

void	swap_values(int *a, int *b)
{
	int swap = *a;
	*a = *b;
	*b = swap;
}

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i;
	int swapped = 1;

	while (swapped == 1)
	{
		i = 1;
		swapped = 0;
		while (i < size)
		{
			if (tab[i - 1] > tab[i])
			{
				swap_values(&tab[i - 1], &tab[i]);
				swapped = 1;
			}
			++i;
		}
	}
}