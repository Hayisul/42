/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 00:14:11 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 21:03:38 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast(*lst);
	tmp->next = new;
}

/* Adds the node 'new_node' at the end of the list.
 *
 * Parameters:
 *  - lst: A double pointer to the head of the list.
 *  - new_node: The node to be added at the end of the list.
 *
 * Behavior:
 *  - If 'new_node' is NULL, the function does nothing.
 *  - If the list is empty,
 *  the head of the list is updated to point to 'new_node'.
 *  - Otherwise, the function finds the last node in the list
 *  and updates its 'next' pointer to point to 'new_node'.
 */