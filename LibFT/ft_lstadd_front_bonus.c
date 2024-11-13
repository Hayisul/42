/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:08:02 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:37:34 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/* Adds the node 'new_node' at the beginning of the list.
 *
 * Parameters:
 *  - lst: A double pointer to the head of the list.
 *  - new_node: The node to be added at the front of the list.
 *
 * Behavior:
 *  - Sets the 'next' pointer of 'new_node' to the current head of the list.
 *  - Updates the head of the list to point to 'new_node'.
 */