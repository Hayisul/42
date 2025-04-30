#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

// ────────────── Stack Building ──────────────
void			build_stack(t_stack_node **a, char **argv);

// ────────────── Cleanup ──────────────
void			free_stack(t_stack_node **stack);
void			free_errors(t_stack_node **a);

// ────────────── Analysis ──────────────

void			set_index(t_stack_node *stack);
void			set_target_a(t_stack_node *a, t_stack_node *b);
void			set_target_b(t_stack_node *a, t_stack_node *b);
void    		calculate_push_cost(t_stack_node *from, t_stack_node *to);
void			set_cheapest(t_stack_node *stack);
t_stack_node    *get_cheapest(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node    *find_max(t_stack_node *stack);

// ────────────── Stack Utils ──────────────

bool			stack_sorted(t_stack_node *stack);
int				stack_size(t_stack_node *stack);

// ────────────── Sorting ──────────────
void			sort_three(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b);
void			prep_a(t_stack_node *a, t_stack_node *b);
void			prep_b(t_stack_node *a, t_stack_node *b);
void			prep_push(t_stack_node **stack, t_stack_node *node, char c);
void			rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node);
void			reverse_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node);


// ────────────── Operations ──────────────
void            sa(t_stack_node **a, bool print);
void            sb(t_stack_node **b, bool print);
void            ss(t_stack_node **a, t_stack_node **b, bool print);
void            pa(t_stack_node **a, t_stack_node **b, bool print);
void            pb(t_stack_node **a, t_stack_node **b, bool print);
void            ra(t_stack_node **a, bool print);
void            rb(t_stack_node **b, bool print);
void            rr(t_stack_node **a, t_stack_node **b, bool print);
void            rra(t_stack_node **a, bool print);
void            rrb(t_stack_node **b, bool print);
void            rrr(t_stack_node **a, t_stack_node **b, bool print);

#endif