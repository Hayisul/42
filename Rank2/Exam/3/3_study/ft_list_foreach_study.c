// Expected files   : ft_list_foreach.c
// Allowed functions: 
// --------------------------------------------------------------------------------
//
// Write a function that takes a list and a function pointer,
// and applies this function to each element of the list.

#include <stdlib.h>
typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	if (begin_list == 0)
		return;
	while (begin_list != 0)
	{
		f(begin_list->data);
		begin_list = begin_list->next;
	}
}

/*
#include <stdio.h>

void print_str(void *data)
{
    printf("%s\n", (char *)data);
}

int main(void)
{
    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));

    if (!node1 || !node2 || !node3)
    {
        free(node1);
        free(node2);
        free(node3);
        return 1;
    }

    node1->data = "Hello";
    node2->data = "World";
    node3->data = "!";
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    ft_list_foreach(node1, print_str);

    free(node1);
    free(node2);
    free(node3);

    return 0;
}
*/
