#include "push_swap.h"

static void    rotate_to_min(t_stack_node **a)
{
    t_stack_node    *min;

    min = find_min(*a);
    if (*a == min)
        return ;
    while (*a != min)
    {
        if (min->above_median)
            ra(a, true);
        else
            rra(a, true);
    }
}

static void push_a(t_stack_node **a, t_stack_node **b)
{
    t_stack_node    *cheapest_node;

    cheapest_node = get_cheapest(*b);
    if (cheapest_node->above_median
    && cheapest_node->target->above_median)
        rotate_both(a, b, cheapest_node);
    else if (!(cheapest_node->above_median)
    && !(cheapest_node->target->above_median))
        reverse_both(a, b, cheapest_node);
    prep_push(b, cheapest_node, 'b');
    prep_push(a, cheapest_node->target, 'a');
    pa(a, b, true);
}

static void push_b(t_stack_node **a, t_stack_node **b)
{
    t_stack_node    *cheapest_node;

    cheapest_node = get_cheapest(*a);
    if (cheapest_node->above_median
    && cheapest_node->target->above_median)
        rotate_both(b, a, cheapest_node);
    else if (!(cheapest_node->above_median)
    && !(cheapest_node->target->above_median))
        reverse_both(b, a, cheapest_node);
    prep_push(a, cheapest_node, 'a');
    prep_push(b, cheapest_node->target, 'b');
    pb(a, b, true);
}

void sort_stacks(t_stack_node **a, t_stack_node **b)
{
    if (stack_size(*a) > 3 && !stack_sorted(*a))
        pb(a, b, true);
    if (stack_size(*a) > 3 && !stack_sorted(*a))
        pb(a, b, true);
    while (stack_size(*a) > 3 && !stack_sorted(*a))
	{
        prep_a(*a, *b);
        push_b(a, b);
    }
    if (!stack_sorted(*a))
        sort_three(a);
    while (*b)
    {
        prep_b(*a, *b);
        push_a(a, b);
    }
    set_index(*a);
    rotate_to_min(a);
}

void	sort_three(t_stack_node **a)
{
    t_stack_node    *max;

    max = find_max(*a);
    if (*a == max)
        ra(a, true);
    else if ((*a)->next == max)
        rra(a, true);
    if ((*a)->nbr > (*a)->next->nbr)
        sa(a, true);
}
