#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	build_stack(&a, argv + 1);
	if (stack_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	if (stack_size(a) == 2)
		sa(&a, true);
	else if (stack_size(a) == 3)
		sort_three(&a);
	else
		sort_stacks(&a, &b);
	free_stack(&a);
	return (0);
}
