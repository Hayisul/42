/* **************************************** */
/*                                          */
/*              FT_LIST_FOREACH             */
/*                                          */
/*   Applies a given function to the data   */
/*   of each element in a linked list.      */
/*                                          */
/*   Usage:                                 */
/*       ./ft_list_foreach                  */
/*                                          */
/*   Example Output:                        */
/*       Hello                              */
/*       World                              */
/*       !                                  */
/*                                          */
/* **************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list {
    struct s_list *next;
    void *data;
} t_list;

// Applies function f to each element's data in the list.
void ft_list_foreach(t_list *begin_list, void (*f)(void *)) {
    while (begin_list) {
        f(begin_list->data);
        begin_list = begin_list->next;
    }
}

// Prints a string (cast from void *).
void print_str(void *data) {
    printf("%s\n", (char *)data);
}

int main(void) {
    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));

    // Check allocation.
    if (!node1 || !node2 || !node3) {
        free(node1);
        free(node2);
        free(node3);
        return 1;
    }

    // Create a list: "Hello" -> "World" -> "!".
    node1->data = "Hello";
    node2->data = "World";
    node3->data = "!";
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    // Use ft_list_foreach to print each string.
    ft_list_foreach(node1, print_str);

    // Free nodes.
    free(node1);
    free(node2);
    free(node3);

    return 0;
}