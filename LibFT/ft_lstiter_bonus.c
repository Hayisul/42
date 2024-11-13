/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:44:24 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:47:14 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/* Iterates over the list 'lst' and applies the function 'f' to the content of each node.
 *
 * Parameters:
 *  - lst: The beginning of the list.
 *  - f: The address of the function used to iterate over the list.
 *
 * Behavior:
 *  - If 'lst' or 'f' is NULL, the function does nothing.
 * 	- The function iterates over the list
 *  and applies the function 'f' to the content of each node.
 */