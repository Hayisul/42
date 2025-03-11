/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:09:08 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:27:40 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

/* Allocates and returns a new node.
 *
 * Parameters:
 *  - content: The content to be added to the new node.
 *
 * Returns:
 *  - The new node.
 *  - NULL if the allocation fails.
 *
 * Behavior:
 *  - The function allocates memory for a new node.
 *  - The content of the new node is set to 'content'.
 *  - The 'next' pointer of the new node is set to NULL.
 *  - The function returns the new node.
 */