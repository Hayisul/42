#include "push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node    *first;
    t_stack_node    *last;

    if (!stack || !*stack || !(*stack)->next)
        return ;
    first = *stack;
    *stack = first->next;
    (*stack)->prev = NULL;
    last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void    ra(t_stack_node **a, bool print)
{
    rotate(a);
	if (print)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack_node **b, bool print)
{
	rotate(b);
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	ra(a, false);
	rb(b, false);
	if (print)
		ft_putstr_fd("rr\n", 1);
}

void rotate_both(t_stack_node **dst,
                 t_stack_node **src,
                 t_stack_node *cheapest_node)
{
	if (*dst == cheapest_node->target && *src == cheapest_node)
		return ;
    while (*dst != cheapest_node->target && *src != cheapest_node)
        rr(dst, src, true);
    set_index(*dst);
    set_index(*src);
}

/*void rotate_both(t_stack_node **a,
                 t_stack_node **b,
                 t_stack_node *cheapest_node)
{
	if (*b == cheapest_node->target && *a == cheapest_node)
		return ;
    while (*b != cheapest_node->target && *a != cheapest_node)
        rr(a, b, false);
    set_index(*a);
    set_index(*b);
}*/
