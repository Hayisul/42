#include "push_swap.h"

void	calculate_push_cost(t_stack_node *dst, t_stack_node *src)
{
	int dst_size;
    int src_size;

    dst_size = stack_size(dst);
    src_size = stack_size(src);
    while (src)
    {
        src->push_cost = src->index;
        if (!(src->above_median))
            src->push_cost = src_size - (src->index);
        if (src->target->above_median)
            src->push_cost += src->target->index;
        else
            src->push_cost += dst_size - (src->target->index);
        src = src->next;
    }
}

void    set_cheapest(t_stack_node *stack)
{
    t_stack_node    *cheapest_node;
    long            min_cost;

    min_cost = LONG_MAX;
    while (stack)
    {
        if (stack->push_cost < min_cost)
        {
            min_cost = stack->push_cost;
            cheapest_node = stack;
        }
        stack = stack->next;
    }
    cheapest_node->cheapest = true;
}

t_stack_node    *get_cheapest(t_stack_node *stack)
{
    while (stack)
    {
        if (stack->cheapest)
            return (stack);
        stack = stack->next;
    }
    return (NULL);
}