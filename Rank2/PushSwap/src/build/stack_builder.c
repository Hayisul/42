#include "push_swap.h"

static int  is_valid_number(char *str)
{
    int i;

    if (!str || !*str)
        return (0);
    if (*str == '-' || *str == '+')
        str++;
    i = 0;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

static int  is_duplicate(t_stack_node *a, int n)
{
    while (a)
    {
        if (a->nbr == n)
            return (1);
        a = a->next;
    }
    return (0);
}

static t_stack_node *find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

static void append_node(t_stack_node **a, int n)
{
    t_stack_node    *new;
    t_stack_node    *last;

    new = malloc(sizeof(t_stack_node));
    if (!new)
        free_errors(a);
    new->nbr = n;
    new->index = -1;
    new->push_cost = 0;
    new->above_median = false;
    new->cheapest = false;
    new->target = NULL;
    new->next = NULL;
    new->prev = NULL;
    if (!*a)
        *a = new;
    else
    {
        last = find_last(*a);
        last->next = new;
        new->prev = last;
    }
}

void    build_stack(t_stack_node **a, char **argv)
{
    char    **split_args;
    long    n;
    int i;
    int j;

    i = 0;
    while (argv[i])
    {
        split_args = ft_split(argv[i], ' ');
        if (!split_args || !*split_args)
            free_errors(a);
        j = 0;
        while (split_args[j])
        {
            if (!is_valid_number(split_args[j]))
                free_errors(a);
            n = ft_atol(split_args[j]);
            if (n < INT_MIN || n > INT_MAX || is_duplicate(*a, (int)n))
                free_errors(a);
            append_node(a, (int)n);
            free(split_args[j++]);
        }
        free(split_args);
        i++;
    }
}
