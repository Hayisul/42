#include "push_swap.h"

void    free_stack(t_stack_node **stack)
{
    t_stack_node    *tmp;

    if (!stack || !*stack)
        return ;
    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
    *stack = NULL;
}

void    free_errors(t_stack_node **a)
{
    free_stack(a);
    ft_putstr_fd("Error\n", 2);
    exit(1);
}