/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:24:49 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:46:32 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/* Applies the function 'f' to each character of the string 's'.
 *
 * Parameters:
 *  - s: The string to iterate over.
 *  - f: The address of the function used to iterate over the string.
 *
 * Behavior:
 *  - If 's' or 'f' is NULL, the function does nothing.
 *  - The function applies the function 'f' to each character of the string 's'.
 * 	- The function passes the index of the character
 *  and a pointer to the character to 'f'.
 */