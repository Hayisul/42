#include "push_swap.h"

void prep_push(t_stack_node **stack, t_stack_node *node, char c)
{
    while (*stack != node)
    {
        if (c == 'a')
        {
            if (node->above_median)
                ra(stack, true);
            else
                rra(stack, true);
        }
        else if (c == 'b')
        {
            if (node->above_median)
                rb(stack, true);
            else
                rrb(stack, true);
        }
    }
}

void	prep_a(t_stack_node *a, t_stack_node *b)
{
	set_index(a);
	set_index(b);
	set_target_a(a, b);
	calculate_push_cost(b, a);
	set_cheapest(a);
}

void	prep_b(t_stack_node *a, t_stack_node *b)
{
	set_index(a);
	set_index(b);
	set_target_b(a, b);
	calculate_push_cost(a, b);
	set_cheapest(b);
}