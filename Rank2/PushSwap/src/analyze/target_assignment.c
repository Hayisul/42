#include "push_swap.h"

void set_target_a(t_stack_node *a, t_stack_node *b)
{
    t_stack_node *current_b;
    t_stack_node *target_node;
    long closest;

    while (a)
    {
        closest = LONG_MIN;
        current_b = b;
        while (current_b)
        {
            if (current_b->nbr < a->nbr && current_b->nbr > closest)
            {
                closest = current_b->nbr;
                target_node = current_b;
            }
            current_b = current_b->next;
        }
        if (closest == LONG_MIN)
            a->target = find_max(b);
        else
            a->target = target_node;
        a = a->next;
    }
}

void set_target_b(t_stack_node *a, t_stack_node *b)
{
    t_stack_node *current_a;
    t_stack_node *target_node;
    long closest;

    while (b)
    {
        closest = LONG_MAX;
        current_a = a;
        while (current_a)
        {
            if (current_a->nbr > b->nbr && current_a->nbr < closest)
            {
                closest = current_a->nbr;
                target_node = current_a;
            }
            current_a = current_a->next;
        }
        if (closest == LONG_MAX)
            b->target = find_min(a);
        else
            b->target = target_node;
        b = b->next;
    }
}
