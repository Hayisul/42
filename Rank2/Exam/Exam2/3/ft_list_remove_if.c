/* ********************************************************************* */
/*                                                                       */
/*                           FT_LIST_REMOVE_IF                           */
/*                                                                       */
/*   Removes all nodes from a linked list whose data matches data_ref,   */
/*   using the provided comparison function. Removed nodes are freed.    */
/*                                                                       */
/*   Usage:                                                              */
/*       ./ft_list_remove_if                                             */
/*                                                                       */
/*   Example:                                                            */
/*       Given list: 5 -> 3 -> 5 -> 7. Removing 5 yields: 3 -> 7         */
/*                                                                       */
/* ********************************************************************* */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct s_list {
    struct s_list *next;
    void *data;
} t_list;

int cmp(void *a, void *b) {
    // Return 0 if a equals b, 1 otherwise.
    return (((intptr_t)a == (intptr_t)b) ? 0 : 1);
}

// Remove all nodes from the list whose data matches data_ref.
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *a, void *b)) {
    if (begin_list == NULL || *begin_list == NULL)
        return;
    t_list *cur = *begin_list;
    // If the current node's data matches data_ref, remove it.
    if (cmp(cur->data, data_ref) == 0) {
        *begin_list = cur->next;
        free(cur);
        ft_list_remove_if(begin_list, data_ref, cmp);
    }
    cur = *begin_list;
    ft_list_remove_if(&cur->next, data_ref, cmp);
}

void ft_printlist(t_list *lst) {
    while (lst) {
        // Print the node's data as an integer.
        printf("%ld ", (intptr_t)lst->data);
        lst = lst->next;
    }
    printf("\n");
}

int main(void) {
    t_list *lst = NULL;
    
    // Directly build a short list: 5 -> 3 -> 5 -> 7.
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
    return (0);
}
