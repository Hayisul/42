#include "push_swap.h"

static void swap(t_stack_node **stack)
{
    t_stack_node    *first;
    t_stack_node    *second;

    if (!stack || !*stack || !(*stack)->next)
        return ;
    first = *stack;
    second = first->next;
    first->next = second->next;
    if (second->next)
        second->next->prev = first;
    second->next = first;
    second->prev = NULL;
    first->prev = second;
    *stack = second;
}

void    sa(t_stack_node **a, bool print)
{
    swap(a);
    if (print)
        ft_putstr_fd("sa\n", 1);
}

void    sb(t_stack_node **b, bool print)
{
    swap(b);
    if (print)
        ft_putstr_fd("sb\n", 1);
}

void    ss(t_stack_node **a, t_stack_node **b, bool print)
{
    sa(a, false);
    sb(b, false);
    if (print)
        ft_putstr_fd("ss\n", 1);
}