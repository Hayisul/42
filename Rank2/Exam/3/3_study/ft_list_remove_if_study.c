// Expected files   : ft_list_remove_if.c
// Allowed functions: free
// --------------------------------------------------------------------------------
//
// Write a function called ft_list_remove_if that removes from the
// passed list any element the data of which is "equal" to the reference data.
//
// cmp takes two void* arguments and returns 0 when both are equal.

#include <stdlib.h>

typedef struct s_list
{
    struct s_list *next;
    void *data;
} t_list;

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (begin_list == NULL || *begin_list == NULL)
		return;

	t_list *cur = *begin_list;

	if (cmp(cur->data, data_ref) == 0)
	{
		*begin_list = cur->next;
		free(cur);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	cur = *begin_list;
	ft_list_remove_if(&cur->next, data_ref, cmp);
}

/*
ITERATIVE SOLUTION

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list *current = *begin_list;
    t_list *previous = NULL;
    t_list *tmp;

    while (current)
    {
        if (cmp(current->data, data_ref) == 0)
        {
            // Save the next pointer before freeing.
            tmp = current->next;
            if (previous == NULL)
                *begin_list = tmp;
            else
                previous->next = tmp;
            free(current);
            // Continue with the saved next node.
            current = tmp;
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }
}
*/

/*
#include <stdio.h>

int cmp(void *a, void *b) {
    return ((int)a == (int)b) ? 0 : 1;
}

void ft_printlist(t_list *lst) {
    while (lst) {
        printf("%d ", (int)lst->data);
        lst = lst->next;
    }
    printf("\n");
}

int main(void) {
    t_list *lst = NULL;
    
    // Directly build a short list: 5 -> 3 -> 5 -> 7
    lst = (t_list*)malloc(sizeof(t_list));
    lst->data = (void*)5;
    lst->next = (t_list*)malloc(sizeof(t_list));
    lst->next->data = (void*)3;
    lst->next->next = (t_list*)malloc(sizeof(t_list));
    lst->next->next->data = (void*)5;
    lst->next->next->next = (t_list*)malloc(sizeof(t_list));
    lst->next->next->next->data = (void*)7;
    lst->next->next->next->next = NULL;

    printf("Before removal:\n");
    ft_printlist(lst);

    ft_list_remove_if(&lst, (void*)5, cmp);

    printf("After removal:\n");
    ft_printlist(lst);

    // Free remaining nodes.
    while (lst) {
        t_list *tmp = lst;
        lst = lst->next;
        free(tmp);
    }
    return 0;
}
*/