#include "push_swap.h"

static void push(t_stack_node **dst, t_stack_node **src)
{
    t_stack_node    *node;

    if (!src || !*src)
        return ;
    node = *src;
    *src = (*src)->next;
    if (*src)
        (*src)->prev = NULL;
    node->next = *dst;
    if (*dst)
        (*dst)->prev = node;
    node->prev = NULL;
    *dst = node;
}

void    pa(t_stack_node **a, t_stack_node **b, bool print)
{
    push(a, b);
    if (print)
        ft_putstr_fd("pa\n", 1);
}

void    pb(t_stack_node **a, t_stack_node **b, bool print)
{
    push(b, a);
    if (print)
        ft_putstr_fd("pb\n", 1);
}