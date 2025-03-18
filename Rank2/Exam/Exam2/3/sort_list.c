/* ****************************************************************** */
/*                                                                    */
/*                             SORT_LIST                              */
/*                                                                    */
/*   Sorts a linked list of integers using bubble sort.               */
/*   The list is sorted in increasing order.                          */
/*   The sorting is performed using a provided comparison function,   */
/*   and nodes with unsorted data are swapped.                        */
/*                                                                    */
/*   Usage:                                                           */
/*       ./sort_list                                                  */
/*                                                                    */
/*   Example Output:                                                  */
/*       Before sorting: 5 3 8 3 10                                   */
/*       After sorting:  3 3 5 8 10                                   */
/*                                                                    */
/* ****************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list {
    int data;
    struct s_list *next;
} t_list;

// Swaps the data values of two nodes.
void swap_values(t_list *a, t_list *b) {
    int swap = a->data;
    a->data = b->data;
    b->data = swap;
}

// Bubble-sort the list using cmp (non-zero if in order, 0 if not).
t_list *sort_list(t_list *lst, int (*cmp)(int, int)) {
    int swapped = 1;  // Flag to indicate if a swap occurred.
    t_list *cur = lst;
    
    while (swapped == 1) {
        swapped = 0;
        while (cur && cur->next) {
            if (cmp(cur->data, cur->next->data) == 0) {
                swap_values(cur, cur->next);
                swapped = 1;
            }
            cur = cur->next;
        }
        cur = lst;
    }
    return lst;
}

// Returns non-zero if a <= b, 0 otherwise.
int cmp(int a, int b) {
    return (a <= b) ? 1 : 0;
}

// Creates a new list node.
t_list *create_node(int data) {
    t_list *node = malloc(sizeof(t_list));
    if (node) {
        node->data = data;
        node->next = NULL;
    }
    return node;
}

// Prints the list.
void print_list(t_list *lst) {
    while (lst) {
        printf("%d ", lst->data);
        lst = lst->next;
    }
    printf("\n");
}

int main(void) {
    t_list *lst = NULL;
    t_list *node1 = create_node(5);
    t_list *node2 = create_node(3);
    t_list *node3 = create_node(8);
    t_list *node4 = create_node(3);
    t_list *node5 = create_node(10);
    
    // Check for allocation failures.
    if (!node1 || !node2 || !node3 || !node4 || !node5) {
        if (node1) free(node1);
        if (node2) free(node2);
        if (node3) free(node3);
        if (node4) free(node4);
        if (node5) free(node5);
        fprintf(stderr, "Allocation failure\n");
        return 1;
    }
    
    // Build the list: 5 -> 3 -> 8 -> 3 -> 10.
    lst = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    
    printf("Before sorting:\n");
    print_list(lst);
    
    lst = sort_list(lst, cmp);
    
    printf("After sorting:\n");
    print_list(lst);
    
    // Free the nodes.
    t_list *tmp;
    while (lst) {
        tmp = lst;
        lst = lst->next;
        free(tmp);
    }
    
    return 0;
}
