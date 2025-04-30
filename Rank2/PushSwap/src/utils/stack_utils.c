#include "push_swap.h"

bool stack_sorted(t_stack_node *stack)
{
    if (!stack)
        return (1);
    while (stack->next)
    {
        if (stack->nbr > stack->next->nbr)
            return (false);
        stack = stack->next;
    }
    return (true);
}

int stack_size(t_stack_node *stack)
{
    int count;

    count = 0;
    while (stack)
    {
       count++;
       stack = stack->next; 
    }
    return (count);
}
