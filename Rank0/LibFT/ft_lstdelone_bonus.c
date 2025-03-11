/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:23:14 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:26:52 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/* Deletes and frees the memory of a single node in the list.
 *
 * Parameters:
 *  - lst: The node to be deleted.
 *  - del: The address of the function used to delete the content of the node.
 *
 * Behavior:
 *  - If 'lst' or 'del' is NULL, the function does nothing.
 *  - The function deletes the content of the node using the 'del' function.
 *  - Finally, the memory of the node is freed.
 */