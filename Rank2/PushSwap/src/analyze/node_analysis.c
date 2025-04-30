#include "push_swap.h"

void    set_index(t_stack_node *stack)
{
    int i;
    int median;

    i = 0;
    if(!stack)
        return ;
    median = stack_size(stack) / 2;
    while (stack)
    {
        stack->index = i;
        if (i <= median)
            stack->above_median = true;
        else
            stack->above_median = false;
        stack = stack->next;
        i++;
    }
}

t_stack_node *find_min(t_stack_node *stack)
{
    t_stack_node *min_node;
    long min;

    if (!stack)
        return (NULL);
    min = LONG_MAX;
    while (stack)
    {
        if (stack->nbr < min)
        {
            min = stack->nbr;
            min_node = stack;
        }
        stack = stack->next;
    }
    return (min_node); 
}

t_stack_node *find_max(t_stack_node *stack)
{
    t_stack_node *max_node;
    long max;

    if (!stack)
        return (NULL);
    max = LONG_MIN;
    while (stack)
    {
        if (stack->nbr > max)
        {
            max = stack->nbr;
            max_node = stack;
        }
        stack = stack->next;
    }
    return (max_node);
}
