#include "push_swap.h"

static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	t_stack_node	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

void	rra(t_stack_node **a, bool print)
{
	reverse_rotate(a);
	if (print)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack_node **b, bool print)
{
	reverse_rotate(b);
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	rra(a, false);
	rrb(b, false);
	if (print)
		ft_putstr_fd("rrr\n", 1);
}

void reverse_both(t_stack_node **dst,
                 t_stack_node **src,
                 t_stack_node *cheapest_node)
{
	if (*dst == cheapest_node->target && *src == cheapest_node)
		return ;
    while (*dst != cheapest_node->target && *src != cheapest_node)
        rrr(dst, src, true);
    set_index(*dst);
    set_index(*src);
}

/*void reverse_both(t_stack_node **a,
                     t_stack_node **b,
                     t_stack_node *cheapest_node)
{
	if (*b == cheapest_node->target && *a == cheapest_node)
		return ;
    while (*b != cheapest_node->target && *a != cheapest_node)
        rrr(a, b, false);
    set_index(*a);
    set_index(*b);
}*/
