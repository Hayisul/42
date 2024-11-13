/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:54:24 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:47:07 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*node;

	if (!lst || !f)
		return (NULL);
	new = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, node);
		lst = lst->next;
	}
	return (new);
}

/* Iterates over the list 'lst' and applies the function 'f' to the content of each node.
 *
 * Parameters:
 *  - lst: The beginning of the list.
 *  - f: The address of the function used to iterate over the list.
 *  - del: The address of the function used to delete the content of a node.
 *
 * Returns:
 *  - A new list resulting from the successive applications of 'f'.
 *  - NULL if the allocation fails.
 *
 * Behavior:
 *  - If 'lst' or 'f' is NULL, the function returns NULL.
 * 	- The function iterates over the list
 *  and applies the function 'f' to the content of each node.
 *  - The function creates a new node with the content returned by 'f'.
 *  - If the allocation fails,
 *  the function deletes the new list and returns NULL.
 *  - Finally, the function returns the new list.
 */