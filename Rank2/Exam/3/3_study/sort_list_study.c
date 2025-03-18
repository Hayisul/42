// Expected files   : sort_list.c
// Allowed functions: 
// --------------------------------------------------------------------------------
//
// Write a function that sorts the list given as a parameter,
// using the function pointer cmp to select the order to apply,
// and returns a pointer to the first element of the sorted list.
//
// Duplications must remain.
//
// Inputs will always be consistent.
//
// You must use the type t_list described in the file list.h 
// that is provided to you. You must include that file 
// (#include "list.h"), but you must not turn it in.
// We will use our own to compile your assignment.
//
// Functions passed as cmp will always return a value different from 0
// if a and b are in the right order, 0 otherwise.

#include "list.h"

void	swap_values(t_list *a, t_list *b)
{
	int swap = a->data;
	a->data = b->data;
	b->data = swap;
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int swapped = 1;
	t_list *cur = lst;

	while (swapped == 1)
	{
		swapped = 0;
		while (cur != 0 && cur->next != 0)
		{
			if (cmp(cur->data, cur->next->data) == 0)
			{
				swap_values(cur, cur->next);
				swapped = 1;
			}
			cur = cur->next;
		}
		cur = lst;
	}
	return (lst);
}

