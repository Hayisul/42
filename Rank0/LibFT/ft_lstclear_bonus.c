/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:17:02 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:47:21 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next; // -> has precedence over * but (*lst) solves that
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}

/* Deletes and frees the memory of all nodes in the list.
 *
 * Parameters:
 *  - lst: A double pointer to the head of the list.
 *  - del: The address of the function used to delete the content of a node.
 *
 * Behavior:
 *  - If 'lst' or 'del' is NULL, the function does nothing.
 * 	- The function iterates over the list
 *  and deletes each node using the 'del' function.
 *  - Finally, the head of the list is set to NULL.
 */